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
#define pb push_back

typedef long long int ll;
using namespace std;
struct T{
int a;
};
char st[16][16];
int n,ar[16],dp[1<<16];

int rec(int msk)
{
    if(msk==(1<<n)-1)
       return 0;
    int &ret=dp[msk];
    if(dp[msk]!=-1)
        return dp[msk];
     ret=1<<28;
    for(int i=0;i<n;i++)
    {

        if((msk&(1<<i))==0)
        {
            ret=min(ret,ar[i]+rec(msk|(1<<i)));

            for(int j=0;j<n;j++)
            {
                if(i!=j&&(msk&(1<<j))!=0&&(st[j][i]-'0')>1)
                {
                    ret=min(ret,(ar[i]+(st[j][i]-'0')-1)/(st[j][i]-'0')+rec(msk|(1<<i)));
                }
            }
        }
    }
    return ret;
}
int main()
{
    int i,j,k,l,t,r,s,m,a,b,c,d,e,f,g,h,u,v;
     scanf("%d",&t);
     for(r=1;r<=t;r++)
     {
         scanf("%d",&n);
         for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
         for(i=0;i<n;i++)
         {
             scanf("%s",st[i]);
         }
         memset(dp,-1,sizeof(dp));

         printf("Case %d: %d\n",r,rec(0));
     }
    return 0;
}


