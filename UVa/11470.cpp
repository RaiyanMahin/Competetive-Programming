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

ll ar[1002][1002];

ll vis[1002][1002];
ll p;


void dfs(ll x,ll y,ll n,ll m)
{
    vis[x][y]=1;
    ar[x][y]=0;
    ll i,v,xx,yy,C[]={0,0,-1,1},R[]={1,-1,0,0};
    for(i=0;i<4;i++)
    {
        xx=x+R[i];
        yy=y+C[i];
         if(xx>=n&&yy>=n&&xx<m&&yy<m&&vis[xx][yy]==0)
         {
             p=p+ar[xx][yy];
             dfs(xx,yy,n,m);
         }
    }
}

int  main()
{
    ll i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h,aa[10];
    char ch;
  //  scanf("%d",&t);getchar();
    while(1)
    {
       scanf("%lld",&n);
       memset(ar,0,sizeof(ar));
       memset(aa,0,sizeof(aa));
       if(n==0)
        break;
         memset(vis,0,sizeof(vis));
       for(i=0;i<n;i++)
       {
           for(j=0;j<n;j++)
           {
               scanf("%lld",&ar[i][j]);
           }
       }
       a=0;
        for(i=(n-1)/2;i>=0;i--)
        {
                    p=ar[i][i];
                    dfs(i,i,i,n-i);
                      aa[a]=p;
                        a++;
        }
        printf("Case %lld:",r);
    for(i=a-1;i>=0;i--)
    {
        printf(" %lld",aa[i]);
    }
    pf("\n");r++;


    }
    return 0;
}



