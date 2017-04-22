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
const int maxn=105;
int A[maxn],B[maxn],vis[maxn];
vector<int>adj[205];
bool kuhn(int u)
{
    int i,j=adj[u].size(),v;
    for(i=0;i<j;i++)
    {
        v=adj[u][i];
        if(vis[v]==0)
        {
            vis[v]=1;
            if(B[v]==-1||kuhn(B[v]))
            {
                B[v]=u;
                A[u]=v;
                return true;
            }
        }
    }
    return false;
}
int ar[maxn],arr[maxn];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
    sn("%d",&t);
    while(t--)
    {
        memset(A,-1,sizeof(A));
        memset(B,-1,sizeof(B));
        sn("%d",&n);
        for(i=0;i<n;i++)
            sn("%d",&ar[i]);
        sn("%d",&m);
        for(i=0;i<m;i++)
            sn("%d",&arr[i]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(arr[j]%ar[i]==0)
                    adj[i].pb(j);
            }
        }
        int max_match=0;
        for(i=0;i<n;i++)//m=A ar total node
        {
            memset(vis,0,sizeof(vis));
            if(kuhn(i))
            {
                max_match++;
            }
        }
        pf("Case %d: %d\n",cs++,max_match);
        for(i=0;i<n;i++)
            adj[i].clear();
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

