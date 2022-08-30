#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cnt[100][100];

int minnum(int x1, int x2, int y1, int y2)
{
    int point = cnt[x1][y1];
    int min = point;
    for(int i=x1+1; i<=x2; i++)
    {
        cnt[i-1][y1] = cnt[i][y1];
        
        if(min > cnt[i][y1])
        {
            min = cnt[i][y1];
        }
    }
    
    for(int i=y1+1; i<=y2; i++)
    {
        cnt[x2][i-1] = cnt[x2][i];
        
        if(min > cnt[x2][i])
        {
            min = cnt[x2][i];
        }
    }
        
    for(int i=x2-1; i>=x1; i--)
    {
        cnt[i+1][y2] = cnt[i][y2];
        
        if(min > cnt[i][y2])
        {
            min = cnt[i][y2];
        }
    }
    for(int i=y2-1; i>=y1; i--)
    {
        cnt[x1][i+1] = cnt[x1][i];
        
        if(min > cnt[x1][i])
        {
            min = cnt[x1][i];
        }
    }
    cnt[x1][y1+1] = point;
    
    return min;
}

// queries_row_len은 2차원 배열 queries의 행(세로) 길이입니다.
// queries_col_len은 2차원 배열 queries의 열(가로) 길이입니다.
// queries[i][j]는 queries의 i번째 행의 j번째 열에 저장된 값을 의미합니다.
int* solution(int rows, int columns, int **queries, size_t queries_row_len, size_t queries_col_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(queries_row_len * sizeof(int));
    int num = 0;

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            cnt[i][j] = ++num;
        }
    }
    
    for(int i=0; i<queries_row_len; i++)
    {
        int x1 = queries[i][0] -1;
        int x2 = queries[i][2] -1;
        int y1 = queries[i][1] -1;
        int y2 = queries[i][3] -1;
        
        answer[i] = minnum(x1, x2, y1 , y2);
    }
    
    return answer;
}
