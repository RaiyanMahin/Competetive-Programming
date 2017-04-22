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
int dp[105][105];
char st[105];

int rec(int i,int j)
{
    if(i>j)
        return 0;
    int &ret=dp[i][j];
    if(ret!=-1)
        return ret;
    ret=1000;
    if(st[i]==st[j])
        ret=min(ret,rec(i+1,j-1));
    else
    {
        ret=min(ret,rec(i+1,j)+1);
        ret=min(ret,rec(i,j-1)+1);
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
        printf("Case %d: %d\n",r,rec(0,strlen(st)-1));
    }
    return 0;
}


