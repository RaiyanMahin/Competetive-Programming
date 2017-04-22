//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;
ll aa[30],ar[30],a1[300000],a2[300000],a,b,w;

int binry(ll b,ll v)
{
    int l=0,md,h=b-1;
    if(v==0)
        return 1;
    while(l<=h)
    {
        md=(l+h)/2;
        if(a1[md]==v)
        {
            break;
        }
        else if(a1[md]<v)
            l=md+1;
        else
            h=md-1;
    }
    if(l>h)
        return 0;
    else
        return 1;
}
void subsum1(ll p,ll s,ll l)
{
    int i;
    if(s>w)
        return;
    if(p==l)
    {
        a1[a++]=s;
        return;
    }
    for(i=0;i<3;i++)
    {
        subsum1(p+1,s+ar[p]*i,l);
    }
}
void subsum2(ll p,ll s,ll l)
{
    int i;
    if(s>w)
        return;
    if(p==l)
    {
        a2[b++]=s;
        return;
    }
    for(i=0;i<3;i++)
    {
        subsum2(p+1,s+aa[p]*i,l);
    }
}
int main()
{
   ll i,j,k,l,t,r,s,m,n,c,d,e,f,g,h,u,v;
   // freopen("OOO.txt","r",stdin);
  // freopen("Output.txt","w",stdout);
     scanf("%lld",&t);
     for(r=1;r<=t;r++)
     {
         scanf("%lld %lld",&n,&w);
         l=n/2;
         for(i=0;i<l;i++)
         {
            scanf("%lld",&ar[i]);
         }
         for(i=l,j=0;i<n;i++,j++)
         {
            scanf("%lld",&aa[j]);
         }
         a=b=0;
         subsum1(0,0,l);
         subsum2(0,0,n-l);
         sort(a1,a1+a);
        for(i=0;i<b;i++)
        {
            d=binry(a,w-a2[i]);
            if(d==1)
                break;
        }
        if(d==1)
            printf("Case %lld: Yes\n",r);
        else
            printf("Case %lld: No\n",r);
     }
    return 0;
}

