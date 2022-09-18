#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    int* answer;
    
    int sum = 0;
    long long temp = n;
    
    while(temp != 0)
    {
        temp = temp /10;
        sum++;
    }
    
    answer = (int*)malloc(sizeof(int)*sum);
    temp = n;
    
    for(int i=0; i<sum; i++)
    {
        answer[i] = temp % 10;
        temp = temp /10;
    }
  
    return answer;
}
