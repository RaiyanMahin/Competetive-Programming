#include<stdio.h>
#include<string.h>
int main()
{
    long long int i,t,r,j,k,l,m,n,ar[30],pr[30];
    ar[0]=1;
    for(i=1;i<=20;i++)
        ar[i]=ar[i-1]*i;
    scanf("%lld",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%lld",&n);
        m=n;k=0;
        memset(pr,0,sizeof(pr));
        for(i=20;i>=0;i--)
        {
            if(ar[i]==m)
            {
                pr[k++]=i;
                m=0;
                break;
            }
            else if(ar[i]<m)
            {
                pr[k++]=i;
                m=m-ar[i];
            }
        }
        printf("Case %lld: ",r);
        if(m==0)
        for(i=k-1;i>=0;i--)
        {
            if(i!=k-1)
                printf("+");
            printf("%lld!",pr[i]);
        }
        else
            printf("impossible");
        printf("\n");
    }
    return 0;
}

