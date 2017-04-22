#include<stdio.h>
#include<string.h>
int ck[10];
int diff(int n)
{
    memset(ck,-1,sizeof(ck));
    int m=n,d,l=0;
    while(m!=0)
    {
        d=m%10;
        m/=10;
        if(ck[d]!=-1)
        {
            l=1;break;
        }
        ck[d]=d;
    }
    if(l==0)
        return 0;
    else
        return 1;
}
int main()
{
    int i,j,k,l,n,m,ar[6000];
    memset(ar,0,sizeof(ar));
    for(i=1;i<=5000;i++)
        ar[i]=diff(i);
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n>m)
        {
            l=m;
            m=n;n=l;
        }
        k=0;
        for(i=n;i<=m;i++)
            if(ar[i]==0)
            k++;
        printf("%d\n",k);
    }
    return 0;
}
