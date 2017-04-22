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
int dp[1005],dpp[1005][1005];
char st[1005];
int Ispalin(int i,int j)
{
    if(i>=j)
        return 1;
    int &r=dpp[i][j];
    if(r!=-1)
        return r;
    if(st[i]==st[j])
       return r=Ispalin(i+1,j-1);
    return r=0;
}

int rec(int p,int n)
{
    if(p>=n)
        return 0;
    int &ret=dp[p];
    if(ret!=-1)
        return ret;
    ret=N;
    for(int i=p;i<n;i++)
    {
        if(Ispalin(p,i))
        {
            ret=min(ret,rec(i+1,n)+1);
        }
    }
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
        memset(dpp,-1,sizeof(dpp));
        printf("Case %d: %d\n",r,rec(0,strlen(st)));
    }
    return 0;
}


