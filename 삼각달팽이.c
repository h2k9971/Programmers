#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)calloc(n * (n+1) / 2, sizeof(int));
    
    int cnt[n][n];
    int sum = 0;
    int x = -1, y =0;
    int num=1;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cnt[i][j] = 0;
        }
    }
    
    for(int i=n; i>0; i=i-3)
    {
        for(int j=0; j<i; j++)
        {
            cnt[++x][y] = num++;
        }
        for(int j=0; j<i-1; j++)
        {
            cnt[x][++y] = num++;
        }
        for(int j=0; j<i-2; j++)
        {
            cnt[--x][--y] = num++;
        }
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            answer[sum++] = cnt[i][j];
        }
    }
    
    return answer;
}
