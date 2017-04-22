#include<stdio.h>
#include<string.h>
int main()
{
    long long int i,j,k,m,n,l,ar[1000];
    char st[100];
    while(scanf("%s",st)!=EOF)
    {
        l=strlen(st);
        if(l==1&&st[0]=='0')
            break;
            k=0;m=2;
        for(i=l-1;i>=0;i--)
        {
            k=k+((st[i]-48)*(m-1));
            m=m*2;
        }
        printf("%lld\n",k);
    }
    return 0;
}
