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
int x,y;
};
ll dp[61][61][2];
char st[62];

ll rec(ll i,ll j,ll v)
{
    if(i>j)
        return v;
    ll &ret=dp[i][j][v];
    if(ret!=-1)
        return ret;
    ret=0;
    if(st[i]==st[j])
    ret=ret+rec(i+1,j-1,1);
    ret=ret+rec(i+1,j,v);
    ret=ret+rec(i,j-1,v);
    ret=ret-rec(i+1,j-1,v);
    return ret;
}
int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%s",&st);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %lld\n",r,rec(0,strlen(st)-1,0));
    }
    return 0;
}



