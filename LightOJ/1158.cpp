//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include <iostream>
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

char st[14];
int dp[2011][1005],vis[12],viss[12],mm;
int rec(int msk,int mod,int n)
{
    if(msk==(1<<n)-1)
    {
        if(mod==0)return 1;
        else return 0;
    }
    int &ret=dp[msk][mod];
    if(ret!=-1)
    return ret;
    ret=0;

    for(int i=0;i<n;i++)
    {
        if(vis[st[i]-'0']==viss[i])
        {
            vis[st[i]-'0']++;
            ret=ret+rec(msk|(1<<i),(mod*10+st[i]-'0')%mm,n);
            vis[st[i]-'0']--;
        }
    }
    return ret;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
   // freopen(".txt","r",stdin);
  #endif
    sn("%d",&t);
    while(t--)
    {
        sn("%s %d",&st,&mm);
        memset(dp,-1,sizeof(dp));
        memset(vis,-1,sizeof(vis));
        l=strlen(st);
        for(i=0;i<l;i++)
        {
            viss[i]=++vis[st[i]-'0'];
        }
        memset(vis,0,sizeof(vis));
        pf("Case %d: %d\n",cs++,rec(0,0,l));
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

