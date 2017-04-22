#include<stdio.h>
int main()
{
    long long int t,r,i,j,k,l,m,n,d1,d2;
    char s1[40],s2[40];
    scanf("%lld",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%s %s",s1,s2);
        l=strlen(s1);
        m=strlen(s2);
        k=1;d1=0;d2=0;
        for(i=l-1;i>=0;i--)
        {
            if(s1[i]=='1')
               d1=d1+k;
            k=k*2;
        }
        k=1;
        for(i=m-1;i>=0;i--)
        {
            if(s2[i]=='1')
               d2=d2+k;
            k=k*2;
        }
        k=1;
       while(k!=0)
       {
           k=d1%d2;
           d1=d2;
           d2=k;
       }
        if(d1>1)
            printf("Pair #%lld: All you need is love!\n",r);
        else
           printf("Pair #%lld: Love is not all you need!\n",r);
    }
    return 0;
}

