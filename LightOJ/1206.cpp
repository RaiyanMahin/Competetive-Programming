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
const int maxn=505;

struct T{
int u,v,a,b,c,d;
}ar[505];


int A[maxn],B[maxn],vis[maxn];
vector<int>adj[maxn];

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
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);
        for(i=0;i<n;i++)
        {
            sn("%d:%d %d %d %d %d",&ar[i].u,&ar[i].v,&ar[i].a,&ar[i].b,&ar[i].c,&ar[i].d);
        }
        for(i=0;i<n;i++)
        {
            u=abs(ar[i].a-ar[i].c)+abs(ar[i].b-ar[i].d);
            for(j=i+1;j<n;j++)
            {
               v=abs(ar[j].a-ar[i].c)+abs(ar[j].b-ar[i].d);
               h=(ar[j].u-ar[i].u)*60-ar[i].v+ar[j].v;
               if(u+v<h)
               {
                   adj[i+1].pb(j+1);
               }
            }
        }
        memset(A,-1,sizeof(A));
        memset(B,-1,sizeof(B));
        int max_match=0;
        for(i=1;i<=n;i++)//m=A ar total node
        {
            memset(vis,0,sizeof(vis));
            kuhn(i);
        }
        for(i=1;i<=n;i++)
        {
            if(B[i]==-1)
            {
                max_match++;
            }
        }
        pf("Case %d: %d\n",cs++,max_match);
        for(i=0;i<=n;i++)
            adj[i].clear();
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
