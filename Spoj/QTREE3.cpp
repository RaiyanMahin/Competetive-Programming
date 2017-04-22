//BISMILLAHIR RAHMANIR RAHIM
//lightoj-1348
/*
0 i j ,sum of value in path u to v
1 i j ,change the value of node i to j;
*/
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
vector<int>Ed[100005];
int par[100005][25],Lv[100005],subtr[100005];
int chain,id,chainsz[100005],chainnum[100005],chainhead[100005],pos[100005],posid[100005];

void HLD(int u)
{
    if(chainhead[chain]==-1)
        chainhead[chain]=u,chainsz[chain]=0;
    chainsz[chain]++;chainnum[u]=chain;
    pos[id++]=u;posid[u]=id-1;
    int i,j=Ed[u].size(),v,ans=-1,ind=-1;
    for(i=0;i<j;i++)
    {
        v=Ed[u][i];
        if(posid[v]==-1&&subtr[v]>ans)
        {
            ans=subtr[v];ind=i;
        }
    }
    if(ind!=-1)
        HLD(Ed[u][ind]);
    for(i=0;i<j;i++)
    {
        v=Ed[u][i];
        if(i!=ind&&posid[v]==-1)
        {
            chain++;
            HLD(v);
        }
    }
}
void  dfs(int u,int pr,int lv)
{

    Lv[u]=lv;
    par[u][0]=pr;
    int i,j=Ed[u].size(),v;
    for(i=0;i<j;i++)
    {
        v=Ed[u][i];
        if(Lv[v]==-1)
        {
           dfs(v,u,lv+1);
        }
    }
    subtr[u]++;
    if(par[u][0]>=0)subtr[par[u][0]]+=subtr[u];
}
void sparse_table(int n)
{
    int i,j,k,l;
    for(j=1;j<25;j++)
    {
        for(i=0;i<n;i++)
        {
            if(par[i][j-1]!=-1)
            {
                par[i][j]=par[par[i][j-1]][j-1];
            }
        }
    }
}
int find_lca(int u,int v)
{
    int i,j,k,l,m,n;
    if(Lv[v]>Lv[u])
        swap(u,v);

    for(j=24;j>=0;j--)
    {
        if(Lv[u]-(1<<j)>=Lv[v])
        {
            u=par[u][j];
        }
    }
    if(u==v)
        return u;
    for(i=24;i>=0;i--)
    {
        if(par[u][i]!=-1&&par[u][i]!=par[v][i])
        {
            u=par[u][i];v=par[v][i];
        }
    }
    return par[u][0];
}
int tree[300005];
int treeid[100005];
void build(int p,int l,int r)
{
    if(l==r)
    {
        tree[p]=0;
        treeid[pos[l]]=p;
        return;
    }
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    tree[p]=tree[2*p]+tree[2*p+1];
}

void update(int p,int v)
{
    while(p>0)
    {
        tree[p]+=v;
        p/=2;
    }
}

int query(int p,int l,int r,int x,int y)
{
    if(l>y||r<x)
        return 0;
    if(l>=x&&r<=y)
        return tree[p];
    int mid=(l+r)/2;
    return query(2*p,l,mid,x,y)+query(2*p+1,mid+1,r,x,y);
}
int HLD_query(int u,int v,int sz)
{
    int  s=-1,lcau=0;
    while(1)
    {
        if(chainnum[u]==chainnum[lcau])
        {
            if(query(1,0,sz,posid[lcau],posid[u])>0)
                s=chainnum[u];
            break;
        }
        if(query(1,0,sz,posid[chainhead[chainnum[u]]],posid[u])>0)
            s=chainnum[u];
        u=par[chainhead[chainnum[u]]][0];
    }
    if(s==-1)
        return -1;
    int mid,ll,lw=posid[chainhead[s]],hi=lw+chainsz[s]-1;
    ll=lw;s=-1;
    while(lw<=hi)
    {
        mid=(lw+hi)/2;
        int h=query(1,0,sz,ll,mid);
        if(h>0)
        {
            if(mid-1>=ll&&query(1,0,sz,ll,mid-1)>0)
                hi=mid-1;
            else
            {
                return pos[mid]+1;
            }
        }
        else lw=mid+1;
    }
    return -1;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
     //sn("%d",&t);
    //while(t--)
    {
        sn("%d",&n);int qry;sn("%d",&qry);
        for(i=0;i<n-1;i++)
        {
            sn("%d %d",&u,&v);u--;v--;
            Ed[u].pb(v);
            Ed[v].pb(u);
        }
        memset(par,-1,sizeof(par));
        memset(Lv,-1,sizeof(Lv));
        memset(subtr,0,sizeof(subtr));
        dfs(0,-1,0);
        sparse_table(n);
        id=0;chain=0;
        memset(chainhead,-1,sizeof(chainhead));
        memset(posid,-1,sizeof(posid));
        HLD(0);
        build(1,0,id-1);

      //  pf("Case %d:\n",cs++);

        while(qry--)
        {
            sn("%d",&u);
            if(u==1)
            {
                sn("%d",&u);u--;
                pf("%d\n",HLD_query(u,1,id-1));
            }
            else
            {
                sn("%d",&u);u--;
                if(tree[treeid[u]]==0)
                update(treeid[u],1);
                else
                update(treeid[u],-1);
            }
        }
        for(i=0;i<=n;i++)
            Ed[i].clear();
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/



