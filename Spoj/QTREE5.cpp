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

bool del_node[100005];
int vis[100005]={0},vis_cnt=1;
int tree_sz[100005],dist[100005];
int inf=1000000000,col[100005];
int par[100005],par_dis[100005];
int tr[400005],id[100005],pos[100005];
int X[100005],Y[100005];
vector<int>Ed[100005],new_ed[100005],qry[100005];


void subtree_sz(int u)
{
    vis[u]=vis_cnt;
    int i,j=Ed[u].size(),v;
    tree_sz[u]=1;

    for(i=0;i<j;i++)
    {
        v=Ed[u][i];
        if(vis[v]!=vis_cnt&&del_node[v]==0)
        {
            dist[v]=dist[u]+1;
            subtree_sz(v);
            tree_sz[u]+=tree_sz[v];
        }
    }
}

int find_centroid(int u,int n)
{
    vis[u]=vis_cnt;
    int i,j=Ed[u].size(),v;

    for(i=0;i<j;i++)
    {
        v=Ed[u][i];
        if(vis[v]!=vis_cnt&&del_node[v]==0&&tree_sz[v]>=n/2)
        {
            return find_centroid(v,n);
        }
    }
    return u;
}

void centroid_decom(int u,int n,int pa)
{
    dist[u]=1;
    subtree_sz(u);
    vis_cnt++;

    int cent=find_centroid(u,tree_sz[u]);//here cent is centroid of subtree u;
    vis_cnt++;
    del_node[cent]=1;

    par[cent]=pa;
    if(pa!=-1)
    {
        par_dis[cent]=dist[cent];// distance par to cent in the centroid tree
        new_ed[pa].pb(cent);
    }

    int i,j=Ed[cent].size(),v;

    for(i=0;i<j;i++)
    {
        v=Ed[cent][i];
        if(del_node[v]==0)
        {
            centroid_decom(v,n,cent);
        }
    }
}

void build_tree(int p,int l,int r)
{
	if(l==r)
	{
		tr[p]=inf;
		id[l]=p;
		return;
	}

	int m=(l+r)/2;

	build_tree(2*p,l,m);
	build_tree(2*p+1,m+1,r);

	tr[p]=min(tr[2*p],tr[2*p+1]);
}
void update(int p,int v)
{
    tr[p]=v;
    p/=2;
    while(p>0)
    {
        tr[p]=min(tr[2*p],tr[2*p+1]);
        p/=2;
    }
}
void query(int p,int l,int r,int x,int y,int U)
{
	if(l>y||r<x)
        return ;

	if(l>=x&&r<=y)
    {
        qry[U].pb(p);
        return;
    }

	int m=(l+r)/2;

	query(2*p,l,m,x,y,U);
	query(2*p+1,m+1,r,x,y,U);
}

int parr[100005][25],Lv[100005];
void  dfs(int u,int pr,int lv)
{

    Lv[u]=lv;
    parr[u][0]=pr;
    int i,j=Ed[u].size(),v;
    for(i=0;i<j;i++)
    {
        v=Ed[u][i];
        if(Lv[v]==-1)
        {
           dfs(v,u,lv+1);
        }
    }

}
void sparse_table(int n)
{
    int i,j,k,l;
    for(j=1;j<25;j++)
    {
        for(i=0;i<n;i++)
        {
            if(parr[i][j-1]!=-1)
            {
                parr[i][j]=parr[parr[i][j-1]][j-1];
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
            u=parr[u][j];
        }
    }
    if(u==v)
        return u;
    for(i=24;i>=0;i--)
    {
        if(parr[u][i]!=-1&&parr[u][i]!=parr[v][i])
        {
            u=parr[u][i];v=parr[v][i];
        }
    }
    return parr[u][0];
}

int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&n);

    for(i=1;i<n;i++)
    {
        sn("%d %d",&u,&v);
        Ed[u].pb(v);
        Ed[v].pb(u);
    }

    vis_cnt=1;
    memset(vis,0,sizeof(vis));
    memset(del_node,0,sizeof(del_node));

    centroid_decom(1,n,-1);

    sn("%d",&m);
    memset(col,0,sizeof(col));
    f=0;
    for(i=1;i<=n;i++)
    {
        X[i]=f;
        for(j=0;j<new_ed[i].size();j++)
        {
            pos[new_ed[i][j]]=f;f++;
        }
        Y[i]=f-1;
    }

    build_tree(1,0,f-1);

    for(i=1;i<=n;i++)
    {
        query(1,0,f-1,X[i],Y[i],i);
    }

    while(m--)
    {
        sn("%d %d",&a,&b);
        if(a==0)
        {
            col[b]=1-col[b];
            int p=b;

            while(p>0)
            {
                int ans=inf;
                if(col[p]==1)
                    ans=0;

                for(j=0;j<qry[p].size();j++)
                    ans=min(ans,tr[qry[p][j]]);
                if(par[p]>0)
                update(id[pos[p]],ans+par_dis[p]);
                p=par[p];
            }
        }
        else{
            int ans=inf,p=b;
            d=0;
            while(p>0)
            {
                if(col[p]==1)
                    ans=min(ans,d);

                for(j=0;j<qry[p].size();j++)
                    ans=min(ans,d+tr[qry[p][j]]);

                d=d+par_dis[p];
                p=par[p];
            }
            if(ans==inf)
                pf("-1\n");
            else
                pf("%d\n",ans);
        }
    }

    for(i=0;i<=n;i++)
    {
        Ed[i].clear();
    }

    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
