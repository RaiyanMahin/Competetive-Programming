//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 100000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;
char st[205][205];
int vis[205][205],n,tt=0,m,dis[205][205],R[]={0,0,1,-1},C[]={1,-1,0,0};
queue<int>Q;
vector<int>b1,b2;
void dfs1(int x,int y)
{
    int u,v,i,xx,yy;
    Q.push(x);
    Q.push(y);vis[x][y]=0;
    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        v=Q.front();Q.pop();
        for(i=0;i<4;i++)
        {
            xx=u+R[i];yy=v+C[i];
            if(xx>=0&&yy>=0&&xx<n&&yy<m&&st[xx][yy]!='#'&&(vis[xx][yy]==-1||vis[xx][yy]>vis[u][v]+1))
            {
                vis[xx][yy]=vis[u][v]+1;
                Q.push(xx);
                Q.push(yy);
            }
        }
    }
}
int main()
{
    int i,j,k,l,x,y,t,r,s,a,b,c,d,e,f,g,h,u,v;
   // freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%s",&st[i]);
        }
        memset(vis,-1,sizeof(vis));
        int y=0;tt=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(st[i][j]=='F')
                {
                    //  printf(" %d",++y);
                    dfs1(i,j);
                }
                if(st[i][j]=='J')
                    u=i,v=j;
                dis[i][j]=N;


            }

        }
        int mn=N;
        dis[u][v]=0;
        Q.push(u);Q.push(v);
        while(!Q.empty())
        {
            u=Q.front();Q.pop();
            v=Q.front();Q.pop();
            for(i=0;i<4;i++)
            {
                x=u+R[i];y=v+C[i];
                if(x>=0&&y>=0&&x<n&&y<m&&st[x][y]!='#');
                else continue;
                if((vis[x][y]>dis[u][v]+1||vis[x][y]==-1)&&dis[x][y]>dis[u][v]+1)
                {
                    dis[x][y]=dis[u][v]+1;
                     Q.push(x);  Q.push(y);
                }
                  if((x==0||y==0||y==m-1||x==n-1)&&st[i][j]!='#'&&st[i][j]!='F')
                {
                    if(dis[x][y]<mn)
                        mn=dis[x][y];
                }
            }
        }
        if(mn==N)
            printf("Case %d: IMPOSSIBLE\n",r);
        else
            printf("Case %d: %d\n",r,mn+1);
    }
    return 0;
}

