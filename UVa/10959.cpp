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

vector<int>ar[10001];
queue<int>Q;
map<string,int>Si;
map<int,string>Is;

int dis[N];

int main()
{
    int i,j,k,r=1,s,t,sx,sy,dx,dy,m,n,a,b,xx,yy,x,y;
    scanf("%d",&t);
      for(r=1;r<=t;r++)
      {
          scanf("%d %d",&n,&m);
         for(i=0;i<m;i++)
            {
               scanf("%d %d",&a,&b);
               ar[a].push_back(b);
               ar[b].push_back(a);
            }
           for(i=0;i<=n;i++)
            dis[i]=N+N;
         Q.push(0);dis[0]=0;
          while(!Q.empty())
          {
              x=Q.front();Q.pop();
              for(k=0,j=ar[x].size();k<j;k++)
              {
                  y=ar[x][k];
                  if(dis[y]>dis[x]+1)
                  {
                      dis[y]=dis[x]+1;
                      Q.push(y);
                  }
              }
          }
          for(i=1;i<n;i++)
          printf("%d\n",dis[i]),ar[i].clear();
          if(r!=t)
            printf("\n");
          ar[0].clear();
      }
    return 0;
}




