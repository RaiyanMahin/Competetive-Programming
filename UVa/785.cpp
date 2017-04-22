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
void dfs(int x,int y,int n,char ch)
{
    st[x][y]=ch;
    vis[x][y]=1;
    int i,v,xx,yy,C[]={0,0,-1,1},R[]={1,-1,0,0};
    for(i=0;i<4;i++)
    {
        xx=x+R[i];
        yy=y+C[i];
         if(xx>=0&&yy>=0&&xx<n&&yy<strlen(st[xx])&&(st[xx][yy]==' '||st[xx][yy]==ch)&&vis[xx][yy]==0)
         {
             dfs(xx,yy,n,ch);
         }
    }
}

int main()
{
    int i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h;
    char ch;
   // scanf("%d",&t);getchar();
    while(1)
    {
        n=0;t=0;
        while(gets(st[n]))
        {
            n++;
            if(st[n-1][0]=='_')
                {
                    t=1;break;
                }
        }
        if(t==0)
            break;
       memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++)
        {
            for(j=0;j<strlen(st[i]);j++)
            {
                if((st[i][j]!=' '&&st[i][j]!='X')&&st[i][j]!='_'&&vis[i][j]==0)
                {
                    ch=st[i][j];
                    dfs(i,j,n,ch);
                }
            }

        }
        for(i=0;i<n;i++)
            puts(st[i]);

    }
    return 0;
}





