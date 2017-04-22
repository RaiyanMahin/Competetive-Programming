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
const int inf=1000000000;
int dp[102][102],M,ar[105][3],dpp[105][105];
int rec(int p,int rem,int n)
{

    if(p>=n)
    {
        if(rem==0)
            return 0;
            return -10000000;
       }
    int &ret=dp[p][rem];
    if(dpp[p][rem]!=-1)
        return ret;
    dpp[p][rem]=1;
    ret=-100000000;
    for(int i=0;i<=rem;i++)
    {
        if(i*ar[p][0]>M)
            break;
        int u=105;
        if(ar[p][1]>0)
            u=(M-i*ar[p][0])/ar[p][1];
        ret=max(ret,u+rec(p+1,rem-i,n));
    }
    return ret;
}
void mem()
{
   memset(dpp,-1,sizeof(dpp));
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d",&n,&m);
        for(i=0;i<n;i++)
            sn("%d %d",&ar[i][0],&ar[i][1]);
        int lw=0,hi=50000,mid;
        while(lw<=hi)
        {
            mid=(lw+hi)/2;
            mem();M=mid;
            u=rec(0,m,n);
            if(u>=m)
            {
                if(mid>0)
                {
                    mem();M=mid-1;
                    u=rec(0,m,n);
                    if(u>=m)
                        hi=mid-1;
                    else break;
                }
                else break;
            }
            else lw=mid+1;
        }
        pf("Case %d: %d\n",cs++,mid);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

