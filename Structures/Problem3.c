#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Time getTime() {
    struct Time t;
    printf("Enter hours: ");
    scanf("%d", &t.hours);
    printf("Enter minutes: ");
    scanf("%d", &t.minutes);
    printf("Enter seconds: ");
    scanf("%d", &t.seconds);
    return t;
}

struct Time calculateDifference(struct Time t1, struct Time t2) {
    struct Time diff;
    int seconds1, seconds2, totalSeconds;

    seconds1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    seconds2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    totalSeconds = seconds1 - seconds2;

    diff.hours = totalSeconds / 3600;
    totalSeconds = totalSeconds % 3600;

    diff.minutes = totalSeconds / 60;
    diff.seconds = totalSeconds % 60;

    return diff;
}

void displayTime(struct Time t) {
    printf("%02d:%02d:%02d\n", t.hours, t.minutes, t.seconds);
}

int main() {
    struct Time time1, time2, difference;

    printf("Enter the first time:\n");
    time1 = getTime();

    printf("Enter the second time:\n");
    time2 = getTime();

    difference = calculateDifference(time1, time2);

    printf("\nDifference between the two times: ");
    displayTime(difference);

    return 0;
}
