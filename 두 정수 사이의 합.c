#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long answer = 0;
    
    int i;
    
    if(a<b)
    {
        for(i =a; i<=b; i++)
        {
            answer = answer +i;
        }
    }
    else if(a > b)
    {
        for(i = b; i<=a; i++)
        {
            answer = answer + i;
         }
    }
    else
    {
        answer =a;
    }
    return answer;
}
