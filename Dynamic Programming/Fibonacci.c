//
//  main.c
//  Fibonacci
//
//  Created by Trang Nguyen on 6/11/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include "fibonacci.h"

int main(int argc, const char * argv[]) {
    clock_t start, end;
    double cpu_time_used;
    
    
    start = clock();
    fibonacci_array(50);
    end = clock();
    cpu_time_used = ((double) (end - start));
    printf("Fibonacci array time: %lf\n", cpu_time_used);
    
    start = clock();
    fibonacci_top_down(50);
    end = clock();
    cpu_time_used = ((double) (end - start));
    printf("Fibonacci top down time: %lf\n", cpu_time_used);
    
    start = clock();
    fibonacci_recursive(50);
    end = clock();
    cpu_time_used = ((double) (end - start));
    printf("Fibonacci recursive time: %lf\n", cpu_time_used);
    
    start = clock();
    fibonacci_sum(50);
    end = clock();
    cpu_time_used = ((double) (end - start));
    printf("Fibonacci sum time: %lf\n", cpu_time_used);

    return 0;
}




