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
int A[63][63],B[63][63],C[63][63];
void Matrix_Expo(int  n,int m)
{
	if(n<=1)
		return;
	int i,j,k,sum;
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
				C[i][j]=sum%10;
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
				C[i][j]=sum%10;
			}
		}
	}
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=m;j++)
			A[i][j]=C[i][j];
	}
}
int ar[63][63];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                sn("%d",&u);
               // if(i==j)u++;
                u=u%10;
                A[i][j]=B[i][j]=u;
                ar[i][j]=u;
            }
        }
        pf("Case %d:\n",cs++);
        if(m==1)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    pf("%d",A[i][j]);
                }
                pf("\n");
            }
        }
        else
        {
            memset(A,0,sizeof(A));
            memset(B,0,sizeof(B));
               for(i=0;i<n+n;i++)
                {
                    for(j=0;j<n+n;j++)
                    {
                        if(i==j&&j<n)
                            A[i][j]=B[i][j]=1;
                        if(j>=n)
                        {
                            A[i][j]=B[i][j]=ar[i%n][j%n];
                        }
                    }
                }
                Matrix_Expo(m-1,n+n-1);
                for(i=0;i<n;i++)
                {
                    for(j=0;j<n;j++)
                    {
                       int sum=0;
                        for(k=0;k<n+n;k++)
                            sum+=(A[i][k]*ar[k%n][j]);
                        C[i][j]=sum%10;
                    }
                }
                for(i=0;i<n;i++)
                {
                    for(j=0;j<n;j++)
                    {
                        pf("%d",C[i][j]);
                    }
                    pf("\n");
                }
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

