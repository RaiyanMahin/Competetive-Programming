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
const int maxn=205;
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
vector<int>lv[3][105],ch[3][105],ar[3][105];
int par[3][105],chh[3][105],m_lv=0;
int con[3][105][105];

bool ck_kuhn(int u,int p)
{
    int i,j=adj[u].size(),v;
    for(i=0;i<j;i++)
    {
        v=adj[u][i];
        if(vis[v]==0&&par[0][v]==p)
        {
            vis[v]=1;
            if(B[v]==-1||ck_kuhn(B[v],p))
            {
                B[v]=u;
                return true;
            }
        }
    }
    return false;
}

void dfs(int u,int l,int w)
{
    vis[u]=1;
    m_lv=max(m_lv,l);
    lv[w][l].pb(u);
    int i,j=ar[w][u].size(),v;
    for(i=0;i<j;i++)
    {
        v=ar[w][u][i];
        if(vis[v]==0)
        {
            par[w][v]=u;
            chh[w][u]++;
            ch[w][u].pb(v);
            dfs(v,l+1,w);
            //con[w][u][chh[w][v]]++;
        }
    }
//    for(i=100;i>=0;i--)
//    {
//        con[w][u][i]+=con[w][u][i+1];
//    }
}
set<int>cunt[3][105];
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
        for(i=0;i<n-1;i++)
        {
            sn("%d %d",&u,&v);
            ar[0][u].pb(v);
            ar[0][v].pb(u);
        }
        sn("%d",&m);
        for(i=0;i<m-1;i++)
        {
            sn("%d %d",&u,&v);
            ar[1][u].pb(v);
            ar[1][v].pb(u);
        }

        memset(vis,0,sizeof(vis));
        memset(par,0,sizeof(par));
        memset(chh,0,sizeof(chh));
         dfs(1,0,0);
         m_lv=0;
        memset(vis,0,sizeof(vis));
         dfs(1,0,1);
        for(i=m_lv;i>=0;i--)
        {
            for(j=0;j<lv[1][i].size();j++)
            {
                v=lv[1][i][j];
                for(k=0;k<lv[0][i].size();k++)
                {
                    u=lv[0][i][k];
                    if(chh[1][v]==0)
                    {
                        adj[v].pb(u);
                    }
                    else
                    {
                        memset(B,-1,sizeof(B));
                       for(h=0;h<ch[1][v].size();h++)
                       {
                           memset(vis,0,sizeof(vis));
                           e=ch[1][v][h];
                           if(ck_kuhn(e,u)==false)
                            break;
                       }
                       if(h==ch[1][v].size())
                       {
                            adj[v].pb(u);
                       }
                    }
                }
            }
        }
       // memset(A,-1,sizeof(A));
        memset(B,-1,sizeof(B));
        int max_match=0;
        pf("Case %d: ",cs++);
        for(i=1;i<=m;i++)//m=A ar total node
        {
            memset(vis,0,sizeof(vis));
            if(kuhn(i))
            {
                max_match++;
            }
            else
            {
                pf("No\n");break;
            }
        }
        if(max_match==m)
            pf("Yes\n");
        for(i=0;i<=102;i++)
            adj[i].clear();
        for(i=0;i<2;i++)
        {
            for(j=0;j<=101;j++)
            {
                ch[i][j].clear();
                ar[i][j].clear();
                lv[i][j].clear();
            }
        }
    }
    return 0;

}

/*
1
16
1 2
1 3
2 4
3 5
3 6
3 7
3 8
4 9
9 10
5 11
11 12
6 13
13 14
13 15
7 16
11
1 2
2 3
2 4
2 5
3 6
6 7
4 8
8 9
5 10
10 11
ans:No
*/
