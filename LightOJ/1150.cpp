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
const int maxn=55;
const int inf=1000000;
int A[maxn],B[maxn],vis[maxn],cst[55][55];
vector<int>adj[maxn];
bool kuhn(int u,int cs)
{
    int i,j=adj[u].size(),v;
    for(i=0;i<j;i++)
    {
        v=adj[u][i];
        if(vis[v]==0&&cst[u][v]<=cs)
        {
            vis[v]=1;
            if(B[v]==-1||kuhn(B[v],cs))
            {
                B[v]=u;
                A[u]=v;
                return true;
            }
        }
    }
    return false;
}
vector<int>ar;
set<int>arr;
char st[27][27];
int viss[30][30],R[]={0,0,1,-1},C[]={1,-1,0,0};
void bfs(int x,int y,int h,int n,int m)
{
    int dis[27][27],i,j,k,xx,yy;
    for(i=0;i<n;i++)
       for(j=0;j<m;j++)
        dis[i][j]=inf;
    dis[x][y]=0;
    queue<int>Q;
    Q.push(x);
    Q.push(y);
    while(!Q.empty())
    {
        x=Q.front();Q.pop();
        y=Q.front();Q.pop();
        //x=Q.front();
        if(viss[x][y]>=0)
            cst[h][viss[x][y]]=dis[x][y];
        for(i=0;i<4;i++)
        {
            xx=x+R[i];
            yy=y+C[i];
            if(xx>=0&&yy>=0&&xx<n&&yy<m&&st[xx][yy]!='#'&&dis[xx][yy]>dis[x][y]+1)
            {
                dis[xx][yy]=dis[x][y]+1;
                Q.push(xx);
                Q.push(yy);
            }
        }
    }
    for(i=0;i<=50;i++)
    {
        if(cst[h][i]<inf-1000)
        {
            if(arr.count(cst[h][i])==0)
            ar.pb(cst[h][i]),arr.insert(cst[h][i]);
            adj[h].pb(i);
        }
    }
}

int BPM(int n,int cs)
{
        memset(A,-1,sizeof(A));
        memset(B,-1,sizeof(B));
        int i,max_match=0;
        for(i=0;i<n;i++)//m=A ar total node
        {
            memset(vis,0,sizeof(vis));
            if(kuhn(i,cs)==false)
            {
                return -1;
            }
        }
     return n;
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
        d=0;
        memset(viss,-1,sizeof(viss));
        for(i=0;i<n;i++)
        {
            sn("%s",&st[i]);
            for(j=0;j<n;j++)
            {
                if(st[i][j]=='G')
                    viss[i][j]=d++;
            }
        }
        for(i=0;i<=50;i++)
        {
            for(j=0;j<=50;j++)
                cst[i][j]=inf;
        }
        h=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(st[i][j]=='H')
                {
                    bfs(i,j,h,n,n);
                    h++;
                }
            }
        }
        sort(ar.begin(),ar.end());
        int lw=0,hi=ar.size()-1,mid;
       // pf("%d\n",hi);
        while(lw<=hi)
        {
            mid=(lw+hi)/2;
            if(BPM(h,ar[mid])==h)
            {
                if(mid-1>=0&&BPM(h,ar[mid-1])==h)
                {
                    hi=mid-1;
                }
                else break;
            }
            else
                lw=mid+1;
        }
        pf("Case %d: ",cs++);
        if(lw>hi)
        {
            pf("Vuter Dol Kupokat\n");
        }
        else
        {
            pf("%d\n",2+2*ar[mid]);
        }
        for(i=0;i<=50;i++)
            adj[i].clear();
            ar.clear();
            arr.clear();
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/


