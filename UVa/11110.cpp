
//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
#define N 100000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;

int ar[1000][1000];
queue<int>Q;
map<string,int>Si;
map<int,string>Is;

int vis[1000][1000],p;

void dfs(int x,int y,int s,int n)
{
    vis[x][y]=1;
    int j,xx,yy,C[]={0,0,1,-1},R[]={1,-1,0,0};
    for(j=0;j<4;j++)
    {
        xx=x+C[j];
        yy=y+R[j];
        if(xx>=0&&yy>=0&&xx<n&&yy<n&&vis[xx][yy]==0&&ar[xx][yy]==s)
        {
            p++;  dfs(xx,yy,s,n);
        }
    }
}

int main()
{
    int i,j,k,r=1,s,t,sx,sy,dx,dy,m,n,a,c,b,xx,yy,x,y;
    char st[10000],*CP;
    while(sn("%d",&n)==1)
    {
        if(n==0)
            break;
        memset(ar,0,sizeof(ar));getchar();
        for(i=1;i<n;i++)
        {
            gets(st);
            CP=strtok(st," ");c=0;
               while(CP!=NULL)
                {
                    if(c<1)
                    x=atoi(CP);
                    else
                    {
                        y=atoi(CP);ar[x-1][y-1]=i;
                       c=-1;
                    }
                    c++;
                    CP=strtok(NULL," ");
                }


        }
//        for(i=0;i<n;i++)
//        {
//            for(j=0;j<n;j++)
//                pf(" %d",ar[i][j]);
//            pf("\n");
//        }
       memset(vis,0,sizeof(vis));
       for(i=0;i<n;i++)
       {

        for(j=0;j<n;j++)
        {
            if(vis[i][j]==0)
            {
                p=1;
                dfs(i,j,ar[i][j],n);
               // pf("%d %d\n",ar[i][j],p);
                if(p!=n)
                {
                    j=n;i=n;
                }
            }
        }

       }
       if(p==n)
        pf("good\n");
       else
        pf("wrong\n");

    }
    return 0;
}





