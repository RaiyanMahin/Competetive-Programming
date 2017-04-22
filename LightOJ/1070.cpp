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

typedef  long long int ll;
typedef  unsigned long long int llu;
using namespace std;
ll A[3][3],B[3][3],C[3][3];
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
					sum+=(A[i][k]*B[k][j]);
				C[i][j]=sum;
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
					sum+=(A[i][k]*A[k][j]);
				C[i][j]=sum;
			}
		}
	}
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=m;j++)
			A[i][j]=C[i][j];
	}
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m;
    ll n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%lld %lld %lld",&a,&b,&n);
        pf("Case %d: ",cs++);
        A[0][0]=a;A[0][1]=-b;
        B[0][0]=a;B[0][1]=-b;
        A[1][0]=1;A[1][1]=0;
        B[1][0]=1;B[1][1]=0;
        c=a*a-b-b;
        if(n==0)
        {
            pf("2\n");
        }
        else if(n==1)
        {
            pf("%lld\n",a);
        }
        else if(n==2)
        {
            pf("%lld\n",c);
        }
        else
        {
            Matrix_Expo(n-2,2);
            llu res=A[0][0]*c+A[0][1]*a;
            pf("%llu\n",res);
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

