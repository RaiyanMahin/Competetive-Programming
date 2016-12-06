#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,t,r,m,n;
    char st[1000];
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%s %d",&st,&n);
        if(n<0)
            n=n*-1;
        k=strlen(st);
        if(st[0]=='-')
            i=1;
        else
            i=0;
        for(;i<k;i++)
        {
            m=m*10+(st[i]-'0');
            m=m%n;
        }
        if(m==0)
            printf("Case %d: divisible\n",r);
        else
            printf("Case %d: not divisible\n",r);
    }
    return 0;
}
