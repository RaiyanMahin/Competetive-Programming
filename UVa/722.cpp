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

char st[1000][1000];
int vis[1000][1000],p;

void dfs(int x,int y,int n,char ch)
{
    if(x<0||y<0||x>=n||y>=strlen(st[x])||st[x][y]!=ch||vis[x][y]==1)
        return ;
    vis[x][y]=1;
    p++;
    int i,C[]={0,0,-1,1},R[]={1,-1,0,0};
    for(i=0;i<4;i++)
    {
        dfs(x+C[i],y+R[i],n,ch);
    }
}

int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h;
      scanf("%d",&t);
       scanf("\n");
       for(r=1;r<=t;r++)
       {
           scanf("%d %d",&a,&b);getchar();
           n=0;
           while(gets(st[n])&&st[n][0])
           {
               n++;
           }
           memset(vis,0,sizeof(vis));
           char ch=st[a-1][b-1];
           p=0;
           if(ch=='0')
           dfs(a-1,b-1,n,ch);

           printf("%d\n",p);
           if(r!=t)
            pf("\n");
       }
    return 0;
}

