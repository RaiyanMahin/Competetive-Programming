#include<stdio.h>
int main()
{
   long long int i,n,j,k,st[200],en[200];
    st[0]=1;en[0]=9;
    for(i=1;i<15;i++)
    {
        st[i]=en[i-1]*2;
        en[i]=st[i]*9;

    }
    while(scanf("%lld",&n)!=EOF)
    {
        k=0;
        for(j=0;j<15;j++)
        {
            if(n>st[j]&&n<=en[j])
            {
                k=1;break;
            }
        }
        if(k==1)
            printf("Stan wins.\n");
        else
            printf("Ollie wins.\n");
    }
    return 0;
}

