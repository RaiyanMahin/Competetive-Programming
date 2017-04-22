
#include<stdio.h>
#include<math.h>
int main()
{
    long long int i,n,j,k;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)
            break;
        if (floor(sqrt(n))==ceil(sqrt(n)))
          printf("yes\n");
        else
        printf("no\n");
    }
    return 0;
}

//sum = 0; u = floor(sqrt(N)); foreach k <= u, sum += Floor(N / K); sum = 2*sum-u*u
