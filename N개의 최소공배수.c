#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int solution(int arr[], size_t arr_len) {
    int answer , num;
    
    answer = arr[0];
    
    for(int i= 1; i<arr_len; i++)
    {
        num = answer;
        
        while(num % arr[i] != 0)
        {
            num = num + answer;
        }
        answer = num;
    }
    
    return answer;
}
