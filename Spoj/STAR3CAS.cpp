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

typedef long long int ll;
using namespace std;
struct T{
int a;
};
ll bigmod(ll a,ll b,ll mod)
{
    if(b==0)return 1;
    if(b%2==0)
    {
        ll hh=bigmod(a,b/2,mod);
        return (hh*hh)%mod;
    }
    else
    {
       return (a*bigmod(a,b-1,mod))%mod;
    }
}
int dis[25],ar[25];

void bfs(int n)
{
    int u,v,i,j,k,l,m,a,c,b;
    queue<int>Q;
    Q.push(0);dis[0]=0;
   // Q.push(0);dis[0]=0;
    while(!Q.empty())
    {
        u=Q.front();Q.pop();
       // b=Q.front();Q.pop();
        if(u==n)
            continue;
        if(dis[u+1]>dis[u]+1)
        {
            dis[u+1]=dis[u]+1;
            Q.push(u+1);
        }
        if(u+ar[u]>=0&&u+ar[u]<=n&&dis[u+ar[u]]>dis[u]+1)
        {
            dis[u+ar[u]]=dis[u]+1;
            Q.push(u+ar[u]);
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
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                dis[i]=1000000000;
            }
        }
        bfs(n);
        pf("%d\n",dis[n]);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

