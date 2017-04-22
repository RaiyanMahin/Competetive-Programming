#include<stdio.h>
int main()
{
    long long i,j,k,n,l,y,m,f,q;
    while(scanf("%lld",&y)!=EOF)
    {
        if(y==-1)
            break;
            m=0;f=0;q=1;l=0;
          if(y==0)
          {
              m=0;f=1;
          }
          for(i=0;i<y;i++)
          {
              k=m;
              m=m+l+q;
              f=k+q;
              l=k;
          }

         printf("%lld %lld\n",m,m+f);
    }
    return 0;
}
