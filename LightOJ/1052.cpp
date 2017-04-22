//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include <iostream>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf
#define pb push_back
#define mp make_pair

const double PI=2.0*acos(0);

typedef long long int ll;
using namespace std;
ll A[3][3],B[3][3],C[3][3],mod=1000000007;
void Matrix_Expo(ll n,ll m)
{
	if(n<=1)
		return;
	ll i,j,k,sum;
	if(n%2)
		Matrix_Expo(n-1,m);
	else
		Matrix_Expo(n/2,m);
	if(n%2)
	{
		for(i=0;i<=m;i++)
		{
			for(j=0;j<=m;j++)
			{
				sum=0;
				for(k=0;k<=m;k++)
					sum+=(A[i][k]*B[k][j]%mod);
				C[i][j]=sum%mod;
			}
		}
	}
	else
	{
		for(i=0;i<=m;i++)
		{
			for(j=0;j<=m;j++)
			{
				sum=0;
				for(k=0;k<=m;k++)
					sum+=(A[i][k]*A[k][j]%mod);
				C[i][j]=sum%mod;
			}
		}
	}
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=m;j++)
			A[i][j]=C[i][j];
	}
}
void init()
{
    A[0][0]=0;A[0][1]=1;
    B[0][0]=0;B[0][1]=1;
    A[1][0]=1;A[1][1]=1;
    B[1][0]=1;B[1][1]=1;
}
ll fib[1000];
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v,c1,c2;

    //freopen(".txt","r",stdin);
    sn("%lld",&t);
    fib[0]=0;fib[1]=fib[2]=1;
    for(i=3;i<=51;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
//        if(i>40)
// pf("%lld\n",fib[46]);
    }

    while(t--)
    {
        sn("%lld %lld",&u,&v);
        h=0;
        if(u<=45)
        {
            a=fib[u];
            b=fib[u+1];
            c1=v;
        }
        else
            h=1;
        sn("%lld %lld",&u,&v);
       if(u<=45)
        {
            c=fib[u];
            d=fib[u+1];
            c2=v;
        }
        else
            h=1;
        ll x,y;
        if(h==0)
        {
            if(b==0||(b*c-a*d)==0)
                h=1;
            if(h==0)
            x=(b*c2-d*c1)/(b*c-a*d);
            if(x<0||(b*c2-d*c1)%(b*c-a*d)) h=1;
            if(h==0)
             y=(c1-a*x)/b;
            if(y<0||(c1-a*x)%b) h=1;
        }
        sn("%lld",&n);
        pf("Case %lld: ",cs++);
        if(h==1)
        {
            pf("Impossible\n");
        }
        else
        {
            init();
            Matrix_Expo(n-1,1);
            ll ans=0;
            x=x%mod;
            y=y%mod;
            if(n==1)
            {
                memset(A,0,sizeof(A));
                A[0][0]=A[1][1]=1;
            }
            for(i=0;i<=1;i++)
            {
                for(j=0;j<=1;j++)
                {
                    if(i==0)
                    ans=(ans+(A[i][j]*x%mod))%mod;
                    else
                    ans=(ans+(A[i][j]*y%mod))%mod;
                }
            }
            pf("%lld\n",ans);
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

