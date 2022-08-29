#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int stack[100000];
// prices_len은 배열 prices의 길이입니다.
int* solution(int prices[], size_t prices_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    
    int* answer = (int*)malloc(prices_len * sizeof(int));
    int top, len = 0;
    
    for(int i=0; i <prices_len; i++)
    {
        top = stack[len - 1];
        while (prices[top] > prices[i] && len > 0)
        {
            answer[top] = i - top;
            len--;
            top = stack[len - 1];
        }
        stack[len++] = i;
    }
    
    for(int i=0; i<len; i++)
    {
        answer[stack[i]] = prices_len - 1 - stack[i];
    }
    return answer;
}
