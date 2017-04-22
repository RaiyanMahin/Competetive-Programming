
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

char st[1002][1002];

int vis[1002][1002];
int p;


void dfs(int x,int y,int n,int m,char ch)
{

    if(y<0)y=m-1;
    if(y>=m)y=0;
    if(x<0||x>=n||vis[x][y]==1||st[x][y]!=ch)
        return;
    vis[x][y]=1;
    p++;
    int i,v,xx,yy,C[]={0,0,-1,1},R[]={1,-1,0,0};
    for(i=0;i<4;i++)
    {
        xx=x+R[i];
        yy=y+C[i];

        dfs(xx,yy,n,m,ch);
    }
}

int  main()
{
    int i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h;
    char ch;
  //  scanf("%d",&t);getchar();
    while(scanf("%d%d",&n,&m)==2)
    {


       if(n==0)
        break;
         memset(vis,0,sizeof(vis));
       for(i=0;i<n;i++)
       {
          scanf("%s",st[i]);
       }
        scanf("%d %d",&a,&b);
        p=0;
        ch=st[a][b];
        dfs(a,b,n,m,ch);c=0;

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(st[i][j]==ch)
                {
                    p=0;
                    dfs(i,j,n,m,ch);
                    if(p>c)
                        c=p;
                }
            }
        }
        printf("%d\n",c);
    }
    return 0;
}




