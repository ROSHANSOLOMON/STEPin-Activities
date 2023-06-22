#include <stdio.h>
#include <string.h>

#define MAX_SENSOR_INFO 100

struct SensorData {
    char sensorID[10];
    float temperature;
    int humidity;
    int lightIntensity;
};

void parseData(const char* data, struct SensorData* sensorData) {
    // Copy the sensor ID
    int index = 0;
    while (data[index] != '-') {
        sensorData->sensorID[index] = data[index];
        index++;
    }
    sensorData->sensorID[index] = '\0';
    index += 3;

    // Extract temperature
    sscanf(data + index, "%f", &(sensorData->temperature));
    index = strstr(data + index, "-H:") - data + 3;

    // Extract humidity
    sscanf(data + index, "%d", &(sensorData->humidity));
    index = strstr(data + index, "-L:") - data + 3;

    // Extract light intensity
    sscanf(data + index, "%d", &(sensorData->lightIntensity));
}

void printSensorInfo(const struct SensorData* sensorData) {
    printf("Sensor Info:\n");
    printf("---------------------\n");
    printf("Sensor ID: %s\n", sensorData->sensorID);
    printf("Temperature: %.1f C\n", sensorData->temperature);
    printf("Humidity: %d\n", sensorData->humidity);
    printf("Light Intensity: %d%%\n", sensorData->lightIntensity);
    printf("---------------------\n");
}

int main() {
    const char* data = "S1-T:36.5-H:100-L:50";

    struct SensorData sensorData;
    parseData(data, &sensorData);
    printSensorInfo(&sensorData);

    return 0;
}
