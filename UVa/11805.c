#include<stdio.h>
int main()
{
    int i,t,N,k,p,j,m,n;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d%d",&N,&k,&p);
        for(j=1,n=k;j<=p;j++,n++)
        {
            if(n==N)
                n=0;
        }
        printf("%d\n",n);
    }
    return 0;
}
