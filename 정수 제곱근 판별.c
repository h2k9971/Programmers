#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

long long solution(long long n) {
    long long answer = 0;
    
    double sum =0;
    sum = sqrt(n);
    
    if((int)sum == sum)
    {
        return  (sum + 1) * (sum + 1);
    }
    else
    {
        return  -1;
    }
    
}
