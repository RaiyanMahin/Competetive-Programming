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
char st[55];//main string;
char ss[55];// pattern string
int br[55];
vector<int>kmm;
void preprocess(int n)
{
    int i=0,j=-1;
    br[i]=j;
    while(i<n)
    {
        while(j>=0&&ss[i]!=ss[j])j=br[j];
        j++;i++;
        br[i]=j;
    }
}
int kmpsearch(int n,int m)
{
    int i=0,j=0,s=0;
    while(i<n)
    {
        while(j>=0&&st[i]!=ss[j])j=br[j];
        j++;i++;
        s=j;
        if(j==m)
        {
           // kmm.pb(i-j);
            j=br[j];
        }
    }
    return s;
}
char alp[55];
ll mod=1<<32;
unsigned int A[55][55],B[55][55],C[55][55];
void Matrix_Expo(int  n,int m)
{
	if(n<=1)
		return;
	ll i,j,k;
	unsigned int sum;
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
unsigned int ar[55];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d %s %s",&n,&alp,&ss);
        l=strlen(alp);
        m=strlen(ss);
        preprocess(m);
        memset(A,0,sizeof(A));
        for(i=0;i<m;i++)
        {
            strcpy(st,ss);
            st[i+1]='\0';
            for(j=0;j<l;j++)
            {
                st[i]=alp[j];
                u=kmpsearch(i+1,m);
                if(u<m)
                A[m-1-u][m-1-i]++;
            }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                B[i][j]=A[i][j];
               // pf("%u ",A[i][j]);
            }
            //pf("\n");
        }
        memset(ar,0,sizeof(ar));
        ar[m-1]=l-1;s=l-1;
        if(m-2>=0)
            ar[m-2]=1,s++;
        pf("Case %d: ",cs++);
        if(n==1)
        {
            pf("%d\n",s);
        }
        else
        {
            Matrix_Expo(n-1,m-1);
            ll res=0;
            unsigned int ans=0;
            for(i=0;i<m;i++)
            {
                for(k=0;k<m;k++)
                    ans+=(A[i][k]*ar[k]);
            }
            res=ans;
            pf("%lld\n",res);
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

