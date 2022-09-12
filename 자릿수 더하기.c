#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int count =0;
    int num = n;
    
    while(num != 0)
    {
        num = num / 10;
        count++;
    }
    
    for(int i=0; i<count; i++)
    {
        answer = answer + n % 10;
        n = n / 10;
    }
    
    return answer;
}
