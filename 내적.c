#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// a_len은 배열 a의 길이입니다.
// b_len은 배열 b의 길이입니다.
int solution(int a[], size_t a_len, int b[], size_t b_len) {
    int answer = 0;
    int sum[a_len];
    int i;
    
    for(i=0; i<a_len; i++)
    {
        sum[i] = a[i] * b[i];
    }
    
    for(int i = 0; i<a_len; i++)
    {
        answer = answer + sum[i];
    }
    
    return answer;
}
