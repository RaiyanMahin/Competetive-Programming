//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;
ll md=10000000,B[5][5],A[5][5],aa[5][5];

ll mode(ll a)
{
    if(a%md==0&&a!=0)
        return md;
    else
        return a%md;
}

void Matrix_expo(ll n,ll m)
{
    ll i,j,k,s;
    if(n<=1) return;
    if(n%2)
    {
        Matrix_expo(n-1,m);
    }
    else
    {
        Matrix_expo(n/2,m);
    }
    if(n%2)
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                s=0;
                for(k=0;k<m;k++)
                {

                    s=mode(s+mode(mode(A[i][k])*mode(B[k][j])));
                }
                aa[i][j]=s;
            }
        }
    }
    else
    {
         for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                s=0;
                for(k=0;k<m;k++)
                {
                    s=mode(s+mode(mode(A[i][k])*mode(A[k][j])));
                }
                aa[i][j]=s;
            }
        }
    }
     for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                A[i][j]=aa[i][j];
            }
        }
}

int main()
{
    ll i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v,bb[3];
      //freopen("Output.txt","r",stdin);
      scanf("%lld",&t);
      for(r=1;r<=t;r++)
      {

          scanf("%lld %lld %lld %lld",&a,&b,&n,&m);
          for(i=0;i<2;i++)
          {
              for(j=0;j<2;j++)
              {
                  A[i][j]=B[i][j]=(i==0&&j==0)?0:1;
              }
          }
          if(n>1)
          Matrix_expo(n-1,2);

          bb[0]=a;bb[1]=b;

                s=0;
                for(k=0;k<2;k++)
                {

                    s=mode(s+mode((A[1][k]*bb[k])));
                }
          d=1;
          while(m--)
          {
              d*=10;
          }
          if(n<=1)
             s=bb[n];
          printf("Case %lld: %lld\n",r,s%d);
      }
    return 0;
}

