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

 ll mode(ll a)
 {
     return a%10007;
 }
 ll A[5][5],B[5][5],aa[5][5];
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
    ll i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v,bb[5];
    scanf("%lld",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%lld %lld %lld %lld",&n,&a,&b,&c);
        memset(A,0,sizeof(A));
        A[0][0]=a,A[0][2]=b,A[0][3]=1;
        A[1][0]=A[2][1]=A[3][3]=1;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                B[i][j]=A[i][j];
            }
        }
        bb[0]=c,bb[1]=0,bb[2]=0,bb[3]=c;
        if(n>3)
            Matrix_expo(n-3,4);
            s=0;
        for(k=0;k<4;k++)
        {
            s=mode(s+mode((A[0][k]*bb[k])));
        }
        if(n==3)
            s=c;
        else if(n<3)
            s=0;
        printf("Case %lld: %lld\n",r,s);
    }
    return 0;
}

