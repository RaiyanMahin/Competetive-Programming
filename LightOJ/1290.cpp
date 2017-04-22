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
#define sn scanf
#define pf printf
#define pb push_back
#define N 105 //max number of vertices in one part
#define INF 100000000 //just infinity
typedef long long int ll;
using namespace std;

int cost[N+N][N+N]; //cost matrix
int node, max_match; //n workers and n jobs
int lx[N], ly[N]; //labels of X and Y parts
int xy[N]; //xy[x] - vertex that is matched with x,
int yx[N]; //yx[y] - vertex that is matched with y
bool S[N], T[N]; //sets S and T in algorithm
int slack[N]; //as in the algorithm description
int slackx[N]; //slackx[y] such a vertex, that l(slackx[y]) + l(y) - w(slackx[y],y) = slack[y]
int prev[N]; //array for memorizing alternating paths
int ar_x[N],ar_y[N];
void init_labels()
{
   memset(lx, 0, sizeof(lx));
   memset(ly, 0, sizeof(ly));
   for (int x = 0; x < node; x++)
      for (int y = 0; y < node; y++)
         lx[x] = max(lx[x], cost[ar_x[x]][ar_y[y]]);
}

void update_labels()
{
     int x, y, delta = INF; //init delta as infinity
     for (y = 0; y < node; y++) //calculate delta using slack
         if (!T[y])
            delta = min(delta, slack[y]);
     for (x = 0; x < node; x++) //update X labels
         if (S[x]) lx[x] -= delta;
     for (y = 0; y < node; y++) //update Y labels
         if (T[y]) ly[y] += delta;
     for (y = 0; y < node; y++) //update slack array
         if (!T[y])
     slack[y] -= delta;
}

void add_to_tree(int x, int prevx)
//x - current vertex,prevx - vertex from X before x in the alternating path,
//so we add edges (prevx, xy[x]), (xy[x], x)
{
     S[x] = true; //add x to S
     prev[x] = prevx; //we need this when augmenting
     for (int y = 0; y < node; y++) //update slacks, because we add new vertex to S
         if (lx[x] + ly[y] - cost[ar_x[x]][ar_y[y]] < slack[y])
         {
             slack[y] = lx[x] + ly[y] - cost[ar_x[x]][ar_y[y]];
             slackx[y] = x;
         }
}

void augment() //main function of the algorithm
{
     if (max_match == node) return; //check wether matching is already perfect
     int x, y, root; //just counters and root vertex
     int q[N], wr = 0, rd = 0; //q - queue for bfs, wr,rd - write and read pos in queue
     memset(S, false, sizeof(S)); //init set S
     memset(T, false, sizeof(T)); //init set T
     memset(prev, -1, sizeof(prev)); //init set prev - for the alternating tree
     for (x = 0; x < node; x++) //finding root of the tree
         if (xy[x] == -1)
         {
             q[wr++] = root = x;
             prev[x] = -2;
             S[x] = true;
             break;
         }

     for (y = 0; y < node; y++) //initializing slack array
     {
         slack[y] = lx[root] + ly[y] - cost[ar_x[root]][ar_y[y]];
         slackx[y] = root;
     }
     while (true) //main cycle
     {
         while (rd < wr) //building tree with bfs cycle
         {
             x = q[rd++]; //current vertex from X part
             for (y = 0; y < node; y++) //iterate through all edges in equality graph
                 if (cost[ar_x[x]][ar_y[y]] == lx[x] + ly[y] && !T[y])
                 {
                     if (yx[y] == -1) break; //an exposed vertex in Y found, so
                     //augmenting path exists!
                     T[y] = true; //else just add y to T,
                     q[wr++] = yx[y]; //add vertex yx[y], which is matched
                     //with y, to the queue
                     add_to_tree(yx[y], x); //add edges (x,y) and (y,yx[y]) to the tree
                 }
             if (y < node) break; //augmenting path found!
         }
         if (y < node) break; //augmenting path found!

         update_labels(); //augmenting path not found, so improve labeling
         wr = rd = 0;

         //in below cycle we add edges that were added to the equality graph as a
         //result of improving the labeling, we add edge (slackx[y], y) to the tree if
         //and only if !T[y] && slack[y] == 0, also with this edge we add another one
         //(y, yx[y]) or augment the matching, if y was exposed
        for (y = 0; y < node; y++)
            if (!T[y] && slack[y] == 0)
             {
                 if (yx[y] == -1) //exposed vertex in Y found - augmenting path exists!
                 {
                     x = slackx[y];
                     break;
                 }
                 else
                 {
                     T[y] = true; //else just add y to T,
                     if (!S[yx[y]])
                     {
                         q[wr++] = yx[y]; //add vertex yx[y], which is matched with
                         //y, to the queue
                         add_to_tree(yx[y], slackx[y]); //and add edges (x,y) and (y,
                         //yx[y]) to the tree
                     }
                 }
             }
         if (y < node) break; //augmenting path found!
     }

     if (y < node) //we found augmenting path!
     {
         max_match++; //increment matching
         //in this cycle we inverse edges along augmenting path
         for (int cx = x, cy = y, ty; cx != -2; cx = prev[cx], cy = ty)
         {
             ty = xy[cx];
             yx[cy] = cx;
             xy[cx] = cy;
         }
         augment(); //recall function, go to step 1 of the algorithm
     }
}


int hungarian(int n)
{
     int ret = 0; //weight of the optimal matching
     max_match = 0; //number of vertices in current matching
     node=n;
     memset(xy, -1, sizeof(xy));
     memset(yx, -1, sizeof(yx));
     init_labels(); //step 0
     augment(); //steps 1-3
     for (int x = 0; x < node; x++) //forming answer there
        ret += cost[ar_x[x]][ar_y[xy[x]]];
     return ret;
}
int vis[105],ar[105][105],mx_l;

vector<int>Ed[3][105],lv[3][105];
void dfs(int u,int l,int f)
{
    lv[f][l].pb(u);
    mx_l=max(mx_l,l);
    vis[u]=1;
    int i,j=Ed[f][u].size(),v;
    for(i=0;i<j;i++)
    {
        v=Ed[f][u][i];
        if(vis[v]==0)
        {
            dfs(v,l+1,f);
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
        memset(cost,0,sizeof(cost));
        for(i=0;i<n;i++)
        {
            sn("%d",&a);
            Ed[0][a].pb(i+1);
        }
        sn("%d",&m);
        for(i=0;i<m;i++)
        {
            sn("%d",&a);
            Ed[1][a].pb(i+1);
        }
        mx_l=0;
        memset(vis,0,sizeof(vis));
        dfs(0,0,0);
        g=mx_l;mx_l=0;
        memset(vis,0,sizeof(vis));
        dfs(0,0,1);
        int rt=0;
        if(mx_l<g) rt=1;
        else mx_l=g;
        for(i=mx_l;i>=0;i--)
        {
            for(j=0;j<lv[rt][i].size();j++)
            {
                u=lv[rt][i][j];
                for(h=0;h<Ed[rt][u].size();h++)
                    ar_x[h]=Ed[rt][u][h];
                for(g=101;h<102;h++)
                    ar_x[h]=g++;
                for(k=0;k<lv[1-rt][i].size();k++)
                {
                    v=lv[1-rt][i][k];
                    if(Ed[rt][u].size()==0||Ed[1-rt][v].size()==0)
                    {
                        cost[u][v]=1;
                    }
                    else
                    {
                        for(h=0;h<Ed[1-rt][v].size();h++)
                            ar_y[h]=Ed[1-rt][v][h];
                        for(g=101;h<102;h++)
                            ar_y[h]=g++;
                        cost[u][v]=1+hungarian(max(Ed[1-rt][v].size(),Ed[rt][u].size()));
                    }
                }
            }
        }
        pf("Case %d: %d\n",cs++,n+m+2-(2*cost[0][0]));
        for(i=0;i<=1;i++)
        {
            for(j=0;j<103;j++)
            {
                Ed[i][j].clear();
                lv[i][j].clear();
            }
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/


