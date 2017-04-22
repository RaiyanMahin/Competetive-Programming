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
ll ar[30],aa[30],a1[100000],a2[100000];

int binry(ll b,ll v)
{
    int l=0,md,h=b-1;

    while(l<=h)
    {
        md=(l+h)/2;
        if(a2[md]<=v)
        {
            if(md!=b-1&&a2[md+1]<=v)
                l=md+1;
            else
                break;
        }
        else
            h=md-1;
    }
    if(l>h)
        return 0;
    else
        return md+1;
}
int main()
{
   ll i,j,k,l,t,r,s,m,n,a,b,c,w,d,e,f,g,h,u,v;
     scanf("%lld",&t);
     for(r=1;r<=t;r++)
     {
         scanf("%lld %lld",&n,&w);
         l=0; e=n/2;
         for(i=0;i<e;i++)
         {
            scanf("%lld",&ar[i]);
         }
         for(i=0,j=e;j<n;i++,j++)
         {
            scanf("%lld",&aa[i]);
         }
         a=b=0;
         for(i=l=0;i<(1<<e);i++)
		{
			for(j=k=0;j<e;j++)
			{
				if(i&(1<<j))
					k+=ar[j];
			}
			if(k<=w&&i!=0)
				{
				    a1[a++]=k;
				    l++;
				}
		}
		for(i=0;i<(1<<(n-e));i++)
		{
			for(j=k=0,f=e;f<n;j++,f++)
			{
				if(i&(1<<j))
					k+=aa[j];
			}
			if(k<=w&&i!=0)
				{
				    a2[b++]=k;
				    l++;
				}
		}
         sort(a1,a1+a);
         sort(a2,a2+b);
        for(i=0;i<a;i++)
        {
            d=binry(b,w-a1[i]);
            l+=d;
        }
        printf("Case %lld: %lld\n",r,l+1);
     }
    return 0;
}
