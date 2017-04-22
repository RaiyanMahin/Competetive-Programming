#include<stdio.h>
#include<string.h>
int ar[500009];
int main()
{
    int i,j,k,l,n,m;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        m=1;
        for(i=1;i<31;i++)
        {
           m*=2;
           if(n<=m)
                break;
        }
        if(n==m)
            printf("%d\n",n);
        else if(n==1)
            printf("1\n");
        else
            printf("%d\n",m-((m-n)*2));
    }
return 0;
}

