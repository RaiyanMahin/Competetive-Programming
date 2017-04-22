//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<algorithm>
#define N 1000000
#define Inf 2147483645
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;
int dis[105][105];

int main()
{
    int i,j,k,l,u,v,t,r=1,s,m,n,a,b,c,q,d,e,f,g,h;
    while(sn("%d %d %d",&n,&m,&q)==3)
    {
        if(n==0&&m==0&&q==0)
            break;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            dis[i][j]=Inf;
        }
    }
        for(i=0;i<m;i++)
        {
           sn("%d %d %d",&a,&b,&c);
           dis[a][b]=dis[b][a]=c;
        }

      for(k=1;k<=n;k++)
      {
          for(i=1;i<=n;i++)
          {
              for(j=1;j<=n;j++)
              {
                  c=((dis[i][k]>dis[k][j])?dis[i][k]:dis[k][j]);
                  dis[i][j]=dis[j][i]=(dis[i][j]<c)?dis[i][j]:c;
              }
          }
      }
         if(r!=1)
          pf("\n");
        pf("Case #%d\n",r);r++;
        for(i=0;i<q;i++)
        {
            sn("%d %d",&a,&b);

             if(dis[a][b]==Inf)
                pf("no path\n");
            else
            pf("%d\n",dis[a][b]);
        }

    }
    return 0;
}

