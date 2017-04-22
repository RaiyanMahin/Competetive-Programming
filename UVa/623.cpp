#include<stdio.h>
#include<string.h>
void fact(int n)
{
    int i,j,a,b,k,l,m,hand=0,u,v,put,t,stor[100000];
   stor[0]=1;v=1;
    for(i=1;i<=n;i++)
    {
            put=0;hand=0;
        for(a=0;a<v;a++)
        {
            put+=(stor[a]*i);
             put+=hand;
             hand=put/10;
             stor[a]=put%10;
             put=0;
        }
        while(hand>0)
        {
            stor[v++]=hand%10;
            hand/=10;
        }
    }
    for(i=v-1;i>=0;i--)
        printf("%d",stor[i]);
    printf("\n");
}

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%d!\n",n);
        if(n==0)
        printf("1\n");
        else
            fact(n);

    }
    return 0;
}

