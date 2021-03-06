#include <stdio.h>
#pragma warning(disable : 4996)

#define H_MAX 23
#define M_MAX 59
int calculateTime(int a, int b, int max, int* overflow);
int main(void)
{
    int wake_h, wake_m, now_h, now_m, sleep_h, sleep_m;
    int overflow = 0;
    int invalid = 1;
    char time[10];
    int next = 0;
    while (invalid) {
        if (!next) {
            printf("Enter current time (hh:mm): ");
            fgets(time, 10, stdin);
            if (sscanf(time, "%d:%d", &now_h, &now_m) == 2 && now_h <= H_MAX && now_m <= M_MAX) {
                next = 1;
            }
            else {
                printf("Wrong format!\n");
            }
        }
        else {
            printf("How long do you want to sleep (h:mm): ");
            fgets(time, 10, stdin);
            if (sscanf(time, "%d:%d", &sleep_h, &sleep_m) == 2 && sleep_h <= H_MAX && sleep_m <= M_MAX) {
                invalid = 0;
            }
            else {
                printf("Wrong format!\n");
            }
        }
    }

    wake_m = calculateTime(now_m, sleep_m, M_MAX, &overflow);
    wake_h = calculateTime(now_h, sleep_h, H_MAX, &overflow);
    printf("If you go to bed now you must wake up at ");
    if (wake_m == 0) {
        printf("%d:%d0.", wake_h, wake_m);
    }
    else if (wake_m < 10) {
        printf("%d:0%d.", wake_h, wake_m);
    }
    else {
        printf("%d:%d.", wake_h, wake_m);
    }
    return 0;
}

int calculateTime(int a, int b, int max, int* overflow) {
    int c = a + b;
    if (c > max) {
        c = c - max - 1 + *overflow;
        if (max == 59) {
            *overflow = 1;
        }
    }
    else {
        c = c + *overflow;
        if (c == H_MAX + 1 && max == H_MAX) {
            c = 0;
        }
    }
    return c;
}
