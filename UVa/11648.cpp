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
double AB,AD,CD,BC,x,y,H,A1,A2,th1,th2,EF;
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
   sn("%d",&t);
   while(t--)
   {
       sn("%lf %lf %lf %lf",&AB,&CD,&AD,&BC);
       x=AD*AD+AB*AB+CD*CD-2*CD*AB-BC*BC;
       x=x/(2.0*(AB-CD));
       y=AB-CD-x;
       H=AD*AD-x*x;
       H=sqrt(H);
       A1=.5*(AB+CD)*H;
       th1=acos(x/AD);
       th2=acos(y/BC);
       double lw=0,hi=H,mid;
       for(i=0;i<200;i++)
       {
           mid=(hi+lw)/2;
           x=mid/tan(th1);
           y=mid/tan(th2);
           EF=AB-x-y;
           A2=.5*(AB+EF)*mid;
           if(A2<A1-A2)
           {
               lw=mid;
           }
           else
            hi=mid;
       }
       pf("Land #%d: %.9lf %.9lf\n",cs++,mid/sin(th1),mid/sin(th2));
   }
    return 0;
}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

