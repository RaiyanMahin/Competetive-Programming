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
#define mp make_pair

const double PI=2.0*acos(0);

typedef long long int ll;
using namespace std;
int ar[1005],mx,vis[1005],lv[1004],Tc=1;
vector<int>Ed[1005];
void dfs(int u,int l)
{
    vis[u]=1;
    lv[l]=(lv[l]+ar[u])&1;
    mx=max(mx,l);
    int i,j=Ed[u].size(),v;
    for(i=0;i<j;i++)
    {
        v=Ed[u][i];
        if(vis[v]==0)
        {
            dfs(v,l+1);
        }
    }
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);
        for(i=0;i<n;i++)
        {
            sn("%d",&ar[i]);
        }
        for(i=0;i<n-1;i++)
        {
            sn("%d %d",&u,&v);
            u--;v--;
            Ed[u].pb(v);
            Ed[v].pb(u);
        }
        int ans=0;
        for(i=0;i<n;i++)
        {
            memset(vis,0,sizeof(vis));
            memset(lv,0,sizeof(lv));
            mx=0;
            dfs(i,0);
            u=0;
            for(j=1;j<=mx;j++)
            {
                if(lv[j]==1)
                {
                    u^=j;
                }
            }
            if(u==0)
                ans++;
        }
        pf("Case %d: %d\n",cs++,ans);
        for(i=0;i<=n;i++)
            Ed[i].clear();
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

