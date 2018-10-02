//nhap vao lan luot ngay-thang-nam. vd: 28-2-96. Viet cac ham va in ra man hinh hien thi ra ngay mai cua ngay vua nhap. Dung struct

#include <stdio.h>

typedef struct date_struct {
    int date;
    int month;
    int year;
} date;

int main() {
    date now, tmr;
    do {
        printf("Input the date: "); scanf("%d-%d-%d", &now.date, &now.month, &now.year);
    } while (now.month < 1 || now.month > 12 || now.date < 1 || now.date > 31);
    
    int day_in_month;
    if (now.month == 1 || now.month == 3 || now.month == 5 || now.month == 7 || now.month == 8 || now.month == 10 || now.month == 12) {
        day_in_month = 31;
    } else if (now.month == 4 || now.month == 6 || now.month == 9 || now.month == 11) {
        day_in_month = 30;
    } else if (now.month == 2) {
        day_in_month = 28;
        if (now.year % 400 == 0 || (now.year % 4 == 0 && now.year % 100 != 0)) {
            day_in_month ++;
        }
    }
            
    
    tmr.date = now.date + 1;
    tmr.month = now.month;
    tmr.year = now.year;
    if (now.date == day_in_month) {
        tmr.date = 1;
        tmr.month = now.month + 1;
        if (tmr.month == 13) {
            tmr.month = 1;
            tmr.year = now.year + 1;
        }
    }
    
    
    printf("The date of tomorrow is: %d-%d-%d\n", tmr.date, tmr.month, tmr.year);
    return 0;
}