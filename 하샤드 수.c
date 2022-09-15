#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int harsh = x;
    
    while(harsh != 0)
    {
        sum = sum + harsh % 10;
        harsh = harsh / 10;
    }
    
    if(x % sum == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    
    return answer;
}
