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
#define Inf 200000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;

int ar[1000][1000];
vector<int>cost[1000];
queue<int>Q;
map<char,int>Si;
map<int,string>Is;
int dis[105][105],tim[105][105];


int main()
{
    int i,j,k,l,c,q,r=1,t,n,m,s,sc,d,dc,a,b,E;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                if(i==j)
                dis[i][j]=0,tim[i][j]=0;
            else
                dis[i][j]=Inf,tim[i][j]=Inf;

        }

    for(i=0;i<m;i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(dis[a][b]>d)
        dis[a][b]=dis[b][a]=d;
        if(tim[a][b]>c)
        tim[a][b]=tim[b][a]=c;
    }

    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {

                if(tim[i][j]>tim[i][k]+tim[k][j])
                    tim[i][j]=tim[i][k]+tim[k][j],dis[i][j]=dis[i][k]+dis[k][j];
                else if(tim[i][j]==(tim[i][k]+tim[k][j])&&dis[i][j]>dis[i][k]+dis[k][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
            }
        }
    }
      sn("%d",&q);
      for(i=0;i<q;i++)
      {
          scanf("%d %d",&a,&b);
          if(dis[a][b]==Inf||tim[a][b]==Inf)
            pf("No Path.\n");
          else
          pf("Distance and time to reach destination is %d & %d.\n",dis[a][b],tim[a][b]);
      }

        if(r!=t)
        pf("\n");
    }
    return 0;
}





