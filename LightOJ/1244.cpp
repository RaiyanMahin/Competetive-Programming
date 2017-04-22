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
ll A[63][63],B[63][63],C[63][63];
void Matrix_Expo(int  n,int m)
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
				C[i][j]=sum%10007;
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
				C[i][j]=sum%10007;
			}
		}
	}
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=m;j++)
			A[i][j]=C[i][j];
	}
}
int ar[10]={2,1,1,1},arr[11][11]={{1,1,1,1},{0,0,1,1},{0,1,0,1},{1,0,0,0}};
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);

        pf("Case %d: ",cs++);
        if(n==1)
        {
           pf("1\n");
        }
        else if(n==2)
        {
            pf("2\n");
        }
        else
        {
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    A[i][j]=B[i][j]=arr[i][j];
                }
            }
            ll res=0;
            Matrix_Expo(n-2,3);
            for(i=0;i<4;i++)
            {
                res=(res+A[0][i]*ar[i])%10007;
            }
            pf("%lld\n",res);
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/


