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
#define N 55 //max number of vertices in one part
typedef long long int ll;
using namespace std;
ll divv=120,mdiv=208374326825464800LL;
const ll INF=42LL*208374326825464800LL;
ll cost[N][N]; //cost matrix
ll node, max_match; //n workers and n jobs
ll lx[N], ly[N]; //labels of X and Y parts
ll xy[N]; //xy[x] - vertex that is matched with x,
ll yx[N]; //yx[y] - vertex that is matched with y
bool S[N], T[N]; //sets S and T in algorithm
ll slack[N]; //as in the algorithm description
ll slackx[N]; //slackx[y] such a vertex, that l(slackx[y]) + l(y) - w(slackx[y],y) = slack[y]
ll prev[N]; //array for memorizing alternating paths

void init_labels()
{
   memset(lx, 0, sizeof(lx));
   memset(ly, 0, sizeof(ly));
   for (ll x = 0; x < node; x++)
      for (ll y = 0; y < node; y++)
         lx[x] = max(lx[x], cost[x][y]);
}

void update_labels()
{
     ll x, y, delta = INF; //init delta as infinity
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

void add_to_tree(ll x, ll prevx)
//x - current vertex,prevx - vertex from X before x in the alternating path,
//so we add edges (prevx, xy[x]), (xy[x], x)
{
     S[x] = true; //add x to S
     prev[x] = prevx; //we need this when augmenting
     for (ll y = 0; y < node; y++) //update slacks, because we add new vertex to S
         if (lx[x] + ly[y] - cost[x][y] < slack[y])
         {
             slack[y] = lx[x] + ly[y] - cost[x][y];
             slackx[y] = x;
         }
}

void augment() //main function of the algorithm
{
     if (max_match == node) return; //check wether matching is already perfect
     ll x, y, root; //just counters and root vertex
     ll q[N], wr = 0, rd = 0; //q - queue for bfs, wr,rd - write and read pos in queue
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
         slack[y] = lx[root] + ly[y] - cost[root][y];
         slackx[y] = root;
     }
     while (true) //main cycle
     {
         while (rd < wr) //building tree with bfs cycle
         {
             x = q[rd++]; //current vertex from X part
             for (y = 0; y < node; y++) //iterate through all edges in equality graph
                 if (cost[x][y] == lx[x] + ly[y] && !T[y])
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
         for (ll cx = x, cy = y, ty; cx != -2; cx = prev[cx], cy = ty)
         {
             ty = xy[cx];
             yx[cy] = cx;
             xy[cx] = cy;
         }
         augment(); //recall function, go to step 1 of the algorithm
     }
}
vector<int>tak;
ll hungarian(ll n)
{
     ll ret = 0; //weight of the optimal matching
     max_match = 0; //number of vertices in current matching
     node=n;
     memset(xy, -1, sizeof(xy));
     memset(yx, -1, sizeof(yx));
     init_labels(); //step 0
     augment(); //steps 1-3
     for (ll x = 0; x < node; x++) //forming answer there
        tak.pb(xy[x]);
     return ret;
}

struct TT{
ll a,b,c,d;
}ar[55][55];
ll gcd(ll a,ll b)
{
    if(a%b==0)
        return b;
        return gcd(b,a%b);
}
ll pr[]={2,3,5,7,11,13,17,19,23,29,31,37},vis[3][55];
int main()
{
	 ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v,totalnd;
	scanf("%lld",&t);
	while( t--)
	{
        sn("%lld",&n);
        divv=mdiv;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                sn("%lld/%lld",&ar[i][j].a,&ar[i][j].b);
                if(ar[i][j].a==0)
                    ar[i][j].b=1;
                ar[i][j].c=ar[i][j].b-ar[i][j].a;
                ar[i][j].d=ar[i][j].b;
                cost[i][j]=divv-((divv/ar[i][j].b)*ar[i][j].a);
            }
        }
        tak.clear();
        f=0;
        h=hungarian(n);
        memset(vis,0,sizeof(vis));
        for(i=0;i<tak.size();i++)
        {
            if(ar[i][tak[i]].a==1&&ar[i][tak[i]].b==1)
            {
                f=1;
            }
            else
            {
                a=ar[i][tak[i]].c;
                for(j=0;j<12;j++)
                {
                    while(a%pr[j]==0)
                    {
                        vis[0][pr[j]]++;
                        a/=pr[j];
                    }
                }
                a=ar[i][tak[i]].b;
                for(j=0;j<12;j++)
                {
                    while(a%pr[j]==0)
                    {
                        vis[1][pr[j]]++;
                        a/=pr[j];
                    }
                }
            }
        }
        ll ansx=1,ansy=1;
        if(f==0)
        {

            for(i=1;i<=40;i++)
            {
                u=min(vis[0][i],vis[1][i]);
                vis[0][i]-=u;
                vis[1][i]-=u;
                for(j=0;j<vis[0][i];j++)
                    ansx=(ansx*i);
                for(j=0;j<vis[1][i];j++)
                    ansy=(ansy*i);
            }
            ansx=ansy-ansx;
        }
        else
        {
            ansx=1;ansy=1;
        }
        if(n==1)
        {
            ansx=ar[0][0].a;
            ansy=ar[0][0].b;
        }
        pf("%lld/%lld\n",ansx,ansy);
	}
	return 0;
}
/*
1
2
4/9 1/9
7/9 5/9
*/
