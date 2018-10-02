//Hien thi dong ho bam gio

#include <stdio.h>

typedef struct time_struct {
    int hr;
    int min;
    int sec;
} time_strct;

int main () {
    time_strct start, input;
    printf("Input the time: "); scanf("%d : %d : %d", &input.hr, &input.min, &input.sec);
    
    start.hr = 0;
    start.min = 0;
    start.sec = 0;
    printf("%d : %d : %d\n", start.hr, start.min, start.sec);
    
    int inputSec = input.hr * 3600 + input.min * 60 + input.sec;
    int totalSec = 0;
    int i = 0;
    
    while (i < 10) {
        if (i == 9) {
            start.sec ++;
            if (start.sec == 60) {
                start.min ++;
                if (start.min == 60) {
                    start.hr ++;
                    start.min = 0;
                }
                start.sec = 0;
            }
            totalSec = start.hr * 3600 + start.min * 60 + start.sec;
            printf("%d : %d : %d\n", start.hr, start.min, start.sec);
        } else{
            i++;
        }
        if (totalSec == inputSec) {
            break;
        }
    }
    
    return 0;
}

