#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    
    for(int i=0; i<n; i++)
    {
        if(n%(i+1) == 0)
            answer=answer+(i+1);
    }
    return answer;
}

int main()
{
    int num =0;
    int answer=0;
    printf("자연수 n을 입력하세요:");
    scanf("%d", &num);
    answer = solution(num);
    
    printf("%d의 약수를 모두 더하면 %d 입니다.",num,answer);
    return 0;
}
