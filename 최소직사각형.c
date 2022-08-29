#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sizes_rows는 2차원 배열 sizes의 행 길이, sizes_cols는 2차원 배열 sizes의 열 길이입니다.
int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int answer = 0;
    int x = 0;
    int y = 0 ;
    int cnt = 0;
    
    for(int i=0; i<sizes_rows; i++)
    {
        if(sizes[i][0] < sizes[i][1])
        {
            cnt = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = cnt;
        }
        
        if(sizes[i][0] > x )
        {
            x = sizes[i][0];
        }
        if(sizes[i][1] > y)
        {
            y = sizes[i][1];
        }
    }
    
    answer = x * y;
    return answer;
}
