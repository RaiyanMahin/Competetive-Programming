#include<stdio.h>
int main()
{
   unsigned long long int i,j,d,m,n;
    while(scanf("%llu",&d)!=EOF)
    {
        if(d==0)
            break;
        if(d>=9)
        {
             i=(d*10)/9-9;
            for(j=0;;i++)
            {
                if(d==(i-(i/10))&&j==0)
                {
                    printf("%llu",i);
                    j=1;
                }
                else if(d==(i-(i/10))&&j==1)
                {
                    printf(" %llu",i);
                    j=1;
                }
                if((i-(i/10))>d)
                    break;

            }
            printf("\n");
        }
    }
  return 0;
}
