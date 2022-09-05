#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n)
{
    int answer = 0;
    int i, len = 0, res;

    //3진수로 변경했을 때의
    for (i = n; i / 3 >= 1; i /= 3)
    {
        len++;
    }

    while (n >= 1)
    {
        res = 1;
        for (i = 0; i < len; i++)
        {
            res *= 3;
        }
        answer += (n % 3) * res;
        n /= 3;
        len--;
    }
    return answer;
}
