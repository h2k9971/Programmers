#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// A_len은 배열 A의 길이입니다.
// B_len은 배열 B의 길이입니다.
int solution(int A[], size_t A_len, int B[], size_t B_len) {
    
    int answer = 0;
    int temp = 0;
    int max = 0;
    int min = 0;
    
    for(int i = 0; i< A_len - 1; i++)
    {
        min = i;
        
        for(int j = i+1; j < A_len; j++)
        {
            if(A[min] > A[j])
            {
                min = j;
            }
        }
        if(min != i)
        {
            temp = A[min];
            A[min] = A[i];
            A[i] = temp;
        }
    }
    
    for(int i = 0; i < B_len -1; i++)
    {
        max = i;
        
        for(int j = i+1; j < B_len; j++)
        {
            if(B[max] < B[j])
            {
                max = j;
            }
        }
        if(max != i)
        {
            temp = B[max];
            B[max] = B[i];
            B[i] = temp;
        }
    }
    
    for(int i=0; i<A_len; i++)
    {
        answer = answer + A[i] * B[i];
    }
    
    return answer;
}
