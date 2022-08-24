#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
    
}

long long solution(int w, int h) {
    
    long long total = 0;
    long long W = w;
    long long H = h;
    total = W * H;
    
    long long tmp = (W + H) - gcd(W,H);
    return total - tmp;
}
