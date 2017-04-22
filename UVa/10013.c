#include<stdio.h>
int cl[1000005],c[1000005],stor[1000005];
int main()
{
    long long r,i,j,n,k,h,t,m;
  while(scanf("%lld",&t)==1)
  {
    for(r=1;r<=t;r++)
    {
        scanf("%lld",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&cl[i],&c[i]);
        }
        h=0;
        for(i=m-1;i>=0;i--)
        {
            stor[i]=(cl[i]+c[i]+h)%10;
            h=(cl[i]+c[i]+h)/10;
        }

         for(i=0;i<m;i++)
         {
             printf("%d",stor[i]);
         }
         printf("\n");
         if(t!=r)
            printf("\n");
    }
  }
    return 0;
}
