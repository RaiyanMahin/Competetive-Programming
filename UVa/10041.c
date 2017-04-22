#include<stdio.h>
#include<stdlib.h>
int main()
{
int t,N,m,a[10000]={0},cnt=0,i,y,j,test,x,minn;
        scanf("%d",&test);
            for(y=1;y<=test;y++)
            {
                    scanf("%d",&N);
                    cnt=0;
                    for(i=1;i<=N;i++)
                    {
                    scanf("%d",&a[i]);
                    }
                    for(i=1;i<=N;i++)
                    for(j=1;j<=N-i;j++)
                    {
                    if(a[j]>a[j+1])
                    {
                    t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                    }
                    }

                if(N%2==0)
                     x=N/2;
                    else
                        x=(N/2)+1;

                    for(i=1;i<=N;i++)
                    {
                    cnt+=abs(a[x]-a[i]);
                    }
                    printf("%d\n",cnt);
            }


return 0;
}
