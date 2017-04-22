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

int dis[N],P[N];

void path(int ds,int s)
{
    if(ds==-1)
        return;
    path(P[ds],s);
    if(ds!=s)
    pf(" ");
    pf("%d",ds);

}

int main()
{
    int i,j,k,r=1,s,t,sx,sy,dx,dy,m,n,a,c,b,xx,yy,x,y;
    char st[500],*CP;
      while(scanf("%d",&n)==1)
      {
          getchar();
         for(i=0;i<n;i++)
            {
               gets(st);c=0;
               CP=strtok(st,"-,");
               while(CP!=NULL)
                {
                    if(c<1)
                    a=atoi(CP);
                    else
                    {
                        b=atoi(CP);
                        ar[a].push_back(b);
                    }
                    c++;
                    CP=strtok(NULL,"-,");
                }
            }
          scanf("%d",&m);
          pf("-----\n");
          for(i=0;i<m;i++)
          {
              scanf("%d %d",&sx,&dx);
               for(int l=0;l<=n;l++)
                dis[l]=N;
         Q.push(sx);dis[sx]=0;P[sx]=-1;
          while(!Q.empty())
          {
              x=Q.front();Q.pop();
              for(k=0,j=ar[x].size();k<j;k++)
              {
                  y=ar[x][k];
                  if(dis[y]>dis[x]+1)
                  {
                      dis[y]=dis[x]+1;
                       P[y]=x;
                      Q.push(y);
                  }
              }
          }
              if(dis[dx]==N)
                pf("connection impossible\n");
              else
              path(dx,sx),pf("\n");
          }

          for(i=0;i<=n;i++)
            ar[i].clear();

      }
    return 0;
}





