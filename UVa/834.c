#include<stdio.h>
int main()
{
   long long int i,j,k,l,a,b,c,n,m;

    while(scanf("%lld %lld",&n,&m)!=EOF)
    {
          printf("[%lld;",n/m);
          k=n%m;
          n=m;a=0;
          m=k;
          while(1)
          {
               if(a!=0)
                    printf(",");
              if(n%m==0)
              {
                 printf("%lld",n);
                 break;
              }
              else
              {
                  printf("%lld",n/m);
                  k=n%m;
                  n=m;
                  m=k;
              }
              a++;
          }
          printf("]\n");
    }
  return 0;
}
