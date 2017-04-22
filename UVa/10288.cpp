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
ll gcd(ll a,ll b)
{
    if(a%b==0)
        return b;
    else return gcd(b,a%b);
}
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    while(sn("%lld",&n)!=EOF)
    {
        a=n;
        for(i=n-1;i>=1;i--)
        {
            a=(a/gcd(a,i))*i;
        }
        b=0;
        for(i=n;i>=1;i--)
            b=b+a/i;
        a=a/n;
        u=gcd(a,b);
        a/=u;
        b/=u;
        if(a==1)
            pf("%lld\n",b);
        else
        {
            u=b/a;
            v=b%a;
            char sp[100],A[100],B[100],C[100];
            sprintf(A,"%lld",u);
            sprintf(B,"%lld",v);
            sprintf(C,"%lld",a);
            l=strlen(A);
            A[l]=' ';l++;A[l]='\0';
            d=l;
            c=strlen(C);
            for(i=0;i<c;i++)
                A[l++]='-';
            A[l]=0;
            for(i=0;i<d;i++)
                pf(" ");
                pf("%s\n%s\n",B,A);
            for(i=0;i<d;i++)
                pf(" ");
                pf("%s\n",C);
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

