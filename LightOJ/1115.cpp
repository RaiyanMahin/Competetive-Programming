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

int vis[55][55],p,R[]={1,-1,0,0,-1,-1,1,1},C[]={0,0,-1,1,-1,1,1,-1},n,m;
char st[55][55];
void dfs(int u,int v,char ch,int c)
{
    vis[u][v]=c;
    int i,j,x,y;
    for(i=0;i<4;i++)
    {
        x=u+R[i];y=v+C[i];
        if((x<=0||y<=0||x>=n-1||y>=m-1)&&st[x][y]!=ch)
            p=1;
        if(x>=0&&y>=0&&x<n&&y<m&&st[x][y]!=ch&&vis[x][y]!=c)
        {
            if(x==0||y==0||x==n-1||y==m-1)
            p=1;
            dfs(x,y,ch,c);
        }
    }
}
void color(char ch,int c)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            if(vis[i][j]==c)
            st[i][j]=ch;
    }
}
int main()
{
    int i,j,k,l,t,r,s,a,b,c,d,e,f,g,h,u,v,x1,x2,x3,y1,y2,y3;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%s",&st[i]);
        }
            memset(vis,0,sizeof(vis)); c=1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                x1=i;y1=j-1;x2=i-1;y2=j;
                if(x1>=0&&y1>=0&&x2>=0&&y2>=0&&st[x1][y1]==st[x2][y2]&&st[x1][y1]!=st[i][j]&&st[x2][y2]!='.')
                {

                        p=0;dfs(i,j,st[x1][y1],c);
                    if(p==0)
                        color(st[x1][y1],c);

                }
                c++;
            }
        }
        printf("Case %d:\n",r);
        for(i=0;i<n;i++)
            puts(st[i]);
    }
    return 0;
}

