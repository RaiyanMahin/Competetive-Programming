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

int vis[60][60],p;
char st[60][60];
vector <int>D;

void dfs1(int x,int y,int n,int m)
{
     int i,v,xx,yy,C[]={0,0,1,-1},R[]={1,-1,0,0};
     for(i=0;i<4;i++)
     {
         xx=x+R[i];
         yy=y+C[i];
         if(xx>=0&&yy>=0&&xx<n&&yy<m&&st[xx][yy]=='X')
         {
             st[xx][yy]='*';
             dfs1(xx,yy,n,m);
         }
     }
}

void dfs(int x,int y,int n,int m)
{
    vis[x][y]=1;
    int i,v,xx,yy,C[]={0,0,1,-1},R[]={1,-1,0,0};
    for(i=0;i<4;i++)
    {
        if(st[x][y]=='X')
        {
            p++;
            st[x][y]='*';
            dfs1(x,y,n,m);
        }
        xx=x+R[i];
        yy=y+C[i];
         if(xx>=0&&yy>=0&&xx<n&&yy<m&&vis[xx][yy]==0&&(st[xx][yy]=='*'||st[xx][yy]=='X'))
         {
             dfs(xx,yy,n,m);
         }
    }
}

int main()
{
    int i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h;
    while(scanf("%d %d",&m,&n)==2)
    {
        if(m==0&&n==0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%s",&st[i]);
        }
        memset(vis,0,sizeof(vis));

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(vis[i][j]==0&&(st[i][j]=='*'||st[i][j]=='X'))
                {
                    p=0;
                    dfs(i,j,n,m);
                    if(p!=0)
                        D.push_back(p);
                }
            }

          }


          sort(D.begin(),D.end());
        printf("Throw %d\n",r);
        if(D.size()==0)
            D.push_back(1);
        for(i=0;i<D.size();i++)
        {
            if(i!=0)
                pf(" ");
            printf("%d",D[i]);
        } pf("\n");
        pf("\n");

        D.clear();r++;

    }
    return 0;
}


