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

struct T{
long long a,b;

}ar[106];
long long dp[50050],s;

long long Min(long long a,long long b)
{
    return a>b?b:a;
}



int main()
{
    long long  i,j,k,l,t,r,m,n,a,b,c,d,e,f,g,h,u,v;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%lld",&ar[i].a);
        }
        for(i=0;i<=30000;i++)
            dp[i]=1000000;
            s=1000000;
         dp[0]=0;
      ll ans=s,an=1000;
        for(i=0;i<m;i++)
        {
            for(j=n;j>=0;j--)
            {
                if(dp[j]<s)
                {
                   dp[j+ar[i].a]=Min(dp[j+ar[i].a],dp[j]+1);
                   if(j+ar[i].a>=n&&(j+ar[i].a<ans))
                   {
                       ans=j+ar[i].a;
                   }

                }
            }
        }
        printf("%lld %lld\n",ans,dp[ans]);
    }
    return 0;
}


