#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) *2);
    int arr[7] = {6,6,5,4,3,2,1};
    int sum = 0;
    int corect = 0;
    
    for(int i=0; i<lottos_len; i++)
    {
        if(lottos[i] == 0)
        {
            sum++;
        }
    } // 0의 값 조사하기
    
    for(int i=0; i<lottos_len; i++)
    {
        for(int j= 0; j<win_nums_len; j++)
        {
            if(lottos[i] == win_nums[j])
            {
                corect++;
            }
        }
    } // win의 배열과 lottos의 배열 같은 개수 확인하기
    
    answer[0] = arr[sum + corect];
    answer[1] = arr[corect];
    
    return answer;
}
