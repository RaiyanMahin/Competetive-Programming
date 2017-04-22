
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
struct T{
int a;
};
struct vec{
double x,y;
 vec(double xx=0,double yy=0)
 {
     x=xx;y=yy;
 }
};
vec make_vac(vec p,vec q)
{
    return vec(q.x-p.x,q.y-p.y);
}
double dotproduct(vec p,vec q)
{
    return p.x*q.x+p.y*q.y;
}
double crossproduct(vec p,vec q)
{
    return p.x*q.y-q.x*p.y;
}
double vec_value(vec p)
{
    return sqrt(p.x*p.x + p.y*p.y);
}
vec unit_vec(vec p)
{
    double va=vec_value(p);
    return vec(p.x/va,p.y/va);
}
double dis(double px,double py,double qx,double qy)
{
    px=fabs(px-qx);
    py=fabs(py-qy);
    return sqrt(px*px+py*py);
}
ll bigmod(ll a,ll b,ll mod)
{
    if(b==0)return 1;
    if(b%2==0)
    {
        ll hh=bigmod(a,b/2,mod);
        return (hh*hh)%mod;
    }
    else
    {
       return (a*bigmod(a,b-1,mod))%mod;
    }
}
vector<int>ar,Ed[44];
int pos[1000]={0};
int Mat[40][40];
ll mod=1000000007;
ll A[36][36],B[36][36],C[36][36];
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
					sum=(sum+(A[i][k]*B[k][j]))%mod;
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
					sum=(sum+(A[i][k]*A[k][j]))%mod;
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
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    s=0;
    for(i=1;i<(1<<7);i++)
    {
        c=0;
        for(j=0;j<7;j++)
        {
            if((i&(1<<j)))
                c++;
        }
        if(c==4)
        {
            pos[i]=ar.size();
            ar.pb(i);
        }
    }
    int vis[10];
    memset(Mat,0,sizeof(Mat));
    for(i=0;i<ar.size();i++)
    {

        for(j=0;j<(1<<4);j++)
        {
            memset(vis,0,sizeof(vis));
            c=0;d=0;
            int ans=0;
            for(k=0;k<7;k++)
            {
               if((ar[i]&(1<<k))!=0)
               {
                   if((j&(1<<c))==0)//left
                   {
                       if(k==0)d=1;
                       else if(vis[k-1]!=0)
                       {
                           d=1;
                       }
                       else
                       {
                           vis[k-1]++;
                           ans=ans|(1<<(k-1));
                       }
                   }
                   else //right
                   {
                       if(k==6)d=1;
                       else if(vis[k+1]!=0)
                       {
                           d=1;
                       }
                       else
                       {
                           vis[k+1]++;
                           ans=ans|(1<<(k+1));
                       }
                   }
                   c++;
               }
            }
            if(d==0)
            {
                Mat[pos[ans]][i]=1;
            }
        }
    }
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);
        a=0;
        for(i=0;i<7;i++)
        {
            sn("%d",&u);
            if(u)
                a=a|(1<<i);
        }
        m=34;
        for(i=0;i<=m;i++)
        {
            for(j=0;j<=m;j++)
            {
                A[i][j]=B[i][j]=Mat[i][j];
            }
        }
        ll temM[36];
        for(i=0;i<=m;i++)
        {
            temM[i]=0;
        }
        temM[pos[a]]=1;
        pf("Case %d: ",cs++);
        if(n==1)
        {
            pf("1\n");
        }
        else
        {
            Matrix_Expo(n-1,m);
            ll ans=0;
            for(i=0;i<=m;i++)
            {
                for(j=0;j<=m;j++)
                {
                    ans=(ans+A[i][j]*temM[j])%mod;
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
