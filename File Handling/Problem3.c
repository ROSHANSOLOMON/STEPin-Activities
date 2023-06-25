#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[10];
} LogEntry;

void extractLogEntries(FILE* file, LogEntry logEntries[], int* numEntries) {
    char line[100];
    char *token;
    int entryCount = 0;

    // Read each line from the file
    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, ",");
        
        // Extract data from each line and store it in the array of structures
        logEntries[entryCount].entryNo = atoi(token);

        token = strtok(NULL, ",");
        strcpy(logEntries[entryCount].sensorNo, token);

        token = strtok(NULL, ",");
        logEntries[entryCount].temperature = atof(token);

        token = strtok(NULL, ",");
        logEntries[entryCount].humidity = atoi(token);

        token = strtok(NULL, ",");
        logEntries[entryCount].light = atoi(token);

        token = strtok(NULL, ",");
        strcpy(logEntries[entryCount].timestamp, token);

        entryCount++;
    }

    *numEntries = entryCount;
}

void displayLogEntries(LogEntry logEntries[], int numEntries) {
    printf("EntryNo  SensorNo  Temperature  Humidity  Light  Timestamp\n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%-8d %-9s %-12.1f %-9d %-6d %-s\n",
               logEntries[i].entryNo, logEntries[i].sensorNo, logEntries[i].temperature,
               logEntries[i].humidity, logEntries[i].light, logEntries[i].timestamp);
    }
}

int main() {
    FILE* file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;

    extractLogEntries(file, logEntries, &numEntries);
    displayLogEntries(logEntries, numEntries);

    fclose(file);

    return 0;
}
