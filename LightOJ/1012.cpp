//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;

using namespace std;
int vis[105][105],a;
int ar[100000],aa[100000];
char st[105][105];
void dfs(int x,int y,int n,int m)
{
    vis[x][y]=1;
    int xx,yy,i,R[]={0,0,1,-1},C[]={1,-1,0,0};
    for(i=0;i<4;i++)
    {
        xx=x+R[i];
        yy=y+C[i];
        if(xx>=0&&yy>=0&&xx<n&&yy<m&&st[xx][yy]=='.'&&vis[xx][yy]==0)
        {
             a++;
            dfs(xx,yy,n,m);
        }
    }
   // return p;
}
int main()
{
    int i,j,k,l,t,r,s,m,n,b,c,d,e,f,g,h;
      char ch[10];
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d %d",&m,&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",&st[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(st[i][j]=='@')
                {
                    a=1;
                    dfs(i,j,n,m);
                }
            }
        }
        printf("Case %d: %d\n",r,a);
    }
    return 0;
}



