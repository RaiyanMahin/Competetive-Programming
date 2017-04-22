#include<stdio.h>
int main()
{
    long long int i,t,a,b,c,ma;
      scanf("%lld",&t);
      for(i=0;i<t;i++)
      {
          scanf("%lld %lld %lld",&a,&b,&c);
         if(a>0&&b>0&&c>0)
         {
              if(a>b)
          {
              if(a>c)
                ma=a;
              else
                ma=c;
          }
          else
          {
              if(b>c)
                ma=b;
              else
                ma=c;
          }
          if((a+b+c-ma)>ma)
            printf("OK\n");
          else
            printf("Wrong!!\n");
         }
         else
            printf("Wrong!!\n");
      }
      return 0;
}
