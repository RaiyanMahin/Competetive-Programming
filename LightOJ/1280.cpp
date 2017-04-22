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
vector<int>ar[2000];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d",&n,&k);
        double tt=0,mr=0;
        for(i=0;i<n;i++)
        {
            sn("%d %d",&u,&v);
            ar[v].pb(u);
            mr=mr+u;
            tt=tt+v;
        }
        for(i=1;i<=1000;i++)
        {
            sort(ar[i].begin(),ar[i].end(),cmp);
        }
        double pr=0;
        for(i=0;i<k;i++)
        {
            pr=-1.0;
            for(j=1;j<=1000;j++)
            {
                if(ar[j].size()>0)
                {
                    double aa=ar[j].back(),bb=j;
                    aa=(mr-aa)/(tt-bb);
                    if(aa>pr)
                    {
                        pr=aa;
                        c=j;
                        d=ar[j].back();
                    }
                }
            }
            tt=tt-c;
            mr=mr-d;
           // pf("%d %d\n",c,d);
            ar[c].pop_back();
        }
        pf("Case %d: %.9lf\n",cs++,(mr/tt)*100.0);
        for(i=0;i<=1000;i++)
        {
            ar[i].clear();
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
