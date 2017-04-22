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
int tree[300005];

int query(int p,int l,int r,int x,int y)
{
    if(l>y||r<x)
    {
        return 0;
    }
    if(l>=x&&r<=y)
    {
        return tree[p];
    }
    int mid=(l+r)/2;
    return query(2*p,l,mid,x,y)+query(2*p+1,mid+1,r,x,y);
}

int id[300005];
int update(int u,int x)
{
    while(u>0)
    {
        tree[u]+=x;
        u=u/2;
    }
}
void build(int p,int l,int r)
{
    if(l==r)
    {
        id[l]=p;
        tree[p]=0;
        return;
    }
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    tree[p]=tree[2*p]+tree[2*p+1];
}
int vis[100005],arr[100005];
vector<int>ar[100005];

struct T{
 int i,j,ans;
}Q[100005];

int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
     sn("%d",&t);
     while(t--)
     {
         sn("%d %d",&n,&m);
         memset(tree,0,sizeof(tree));
         memset(vis,-1,sizeof(vis));
         build(1,0,n-1);
         for(i=0;i<n;i++)
         {
             sn("%d",&arr[i]);
         }
          for(i=0;i<m;i++)
          {
            sn("%d %d",&Q[i].i,&Q[i].j);
            Q[i].i--,Q[i].j--;
            ar[Q[i].j].pb(i);
          }
          for(i=0;i<n;i++)
          {
              u=arr[i];
               if(vis[u]!=-1)
                update(id[vis[u]],-1);
                vis[u]=i;
               update(id[i],1);
               for(j=0;j<ar[i].size();j++)
               {
                   v=ar[i][j];
                   Q[v].ans=query(1,0,n-1,Q[v].i,Q[v].j);
               }
          }
          pf("Case %d:\n",cs++);
          for(i=0;i<m;i++)
            pf("%d\n",Q[i].ans);
          for(i=0;i<=100000;i++)
            ar[i].clear();
     }
    return 0;
}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/


