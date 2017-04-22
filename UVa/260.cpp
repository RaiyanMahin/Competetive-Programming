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

void dfs(int x,int y,int n)
{
    st[x][y]='1';
    int i,v,xx,yy,C[]={-1,-1,0,0,1,1},R[]={-1,0,-1,1,0,1};
    for(i=0;i<6;i++)
    {
        xx=x+R[i];
        yy=y+C[i];
         if(xx>=0&&yy>=0&&xx<n&&yy<n&&st[xx][yy]=='b')
         {
             dfs(xx,yy,n);
         }
    }
}

int main()
{
    int i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%s",&st[i]);
        }

        for(i=0;i<1;i++)
        {
            for(j=0;j<n;j++)
            {
                if(st[i][j]=='b')
                {
                    dfs(i,j,n);
                }
            }

          }
          a=0;
          for(i=0;i<n;i++)
          {
              if(st[n-1][i]=='1')
              {
                  a=1;break;
              }
          }
       if(a==1)
        printf("%d B\n",r);
       else
        printf("%d W\n",r);
     r++;

    }
    return 0;
}



