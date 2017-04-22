#include<stdio.h>
#include<stdlib.h>
int main()
{
    long long int n,ar[10000]={0};
    long long int i,j,k,l[4000],m,t;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n<0||n>3000)
            break;
        k=1;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&ar[i]);
        }

        if(n==1||n==0)
            printf("Jolly\n");
       else if(n>1)
        {
            for(i=0;i<n-1;i++)
            {
                l[i]=abs(ar[i]-ar[i+1]);
            }

         for(i=0;i<n-1;i++)
        for(j=0;j<n-i-2;j++)
    {
        if(l[j]>l[j+1])
          {
              t=l[j+1];
          l[j+1]=l[j];
          l[j]=t;

          }
    }
    for(i=0,j=1;i<n-1;i++,j++)
       {
           if(l[i]!=j)
           {
               k=0;
               break;
           }
       }
     if(k==0)
        printf("Not jolly\n");
     else
        printf("Jolly\n");
 }
    }
    return 0;
}
