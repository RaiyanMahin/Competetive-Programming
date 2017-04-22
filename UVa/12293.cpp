#include<stdio.h>
int main()
{
    int i,j,k,tw=2,n,ar[100];
    for(i=0;i<=30;i++)
    {
        ar[i]=tw-1;
        tw=tw*2;
    }
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
            j=0;
        for(i=0;i<=30;i++)
            if(ar[i]==n)
        {
            j=1;printf("Bob\n");break;
        }
        if(j==0)
            printf("Alice\n");

    }
    return 0;
}
