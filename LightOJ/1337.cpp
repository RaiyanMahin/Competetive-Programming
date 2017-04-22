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
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;
char st[505][505];
int vis[505][505],p,n,m;
vector<int>ar;

void dfs(int x,int y,int v)
{
    if(st[x][y]=='C')p++;
    vis[x][y]=v;
    int i,xx,yy,R[]={0,0,-1,1},C[]={1,-1,0,0};
    for(i=0;i<4;i++)
    {
        xx=x+R[i];yy=y+C[i];
        if(xx>=0&&yy>=0&&xx<n&&yy<m&&st[xx][yy]!='#'&&vis[xx][yy]==-1)
            dfs(xx,yy,v);
    }
}

int main()
{
    int i,j,k,l,t,r,s,a,b,c,d,e,q,f,g,h,u,v;
      scanf("%d",&t);
      for(r=1;r<=t;r++)
      {
          scanf("%d %d %d",&n,&m,&q);
          for(i=0;i<n;i++)
          {
              scanf("%s",&st[i]);
          }
          memset(vis,-1,sizeof(vis));
          for(i=0,c=0;i<n;i++)
          {
              for(j=0;j<m;j++)
              {
                  if(vis[i][j]==-1&&st[i][j]!='#')
                  {
                      p=0;
                      dfs(i,j,c);c++;
                      ar.push_back(p);
                  }
              }
          }
          printf("Case %d:\n",r);
          while(q--)
          {
              scanf("%d %d",&a,&b);
              printf("%d\n",ar[vis[a-1][b-1]]);
          }
          ar.clear();
      }
    return 0;
}

