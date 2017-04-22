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
double X1,Y1,X2,Y2;
int main()
{
    int i,j,l,t,cs=1,r=1,s,m,n;

    //freopen(".txt","r",stdin);
    while(sn("%lf %lf %lf %lf",&X1,&Y1,&X2,&Y2)!=EOF)
    {
        double ds=dis(X1,Y1,X2,Y2);
        if(ds==0)
        {
            pf("Impossible\n");
            continue;
        }
        vec P=vec(X1,Y1);
        vec Q=vec(X2,Y2);
        vec PQ=make_vac(P,Q);
        double hf=ds/2.0;
        vec O=unit_vec(PQ);
        O.x*=hf;
        O.y*=hf;
        O.x+=P.x;
        O.y+=P.y;
        double cx=O.x,cy=O.y,X3,Y3,X4,Y4,xx,yy;
        double a,b,c,k,m1;
        a=Y2-Y1;
        b=-1*(X2-X1);
        c=Y1*(X2-X1)-(Y2-Y1)*X1;
        k=a*cy-b*cx;
        if(b!=0)
        {
            yy=cy+100;
            xx=(a*yy-k)/b;
        }
        else
        {
            xx=cx+100;
            yy=(b*xx+k)/a;
        }
        vec A=vec(cx,cy);
        vec B=vec(xx,yy);
        vec AB=make_vac(A,B);
        vec UA=unit_vec(AB);
        UA.x*=hf;
        UA.y*=hf;
        UA.x+=A.x;
        UA.y+=A.y;
        X3=UA.x;
        Y3=UA.y;
        vec C=vec(X3,Y3);
        vec CA=make_vac(C,A);
        vec UC=unit_vec(CA);
        UC.x*=ds;
        UC.y*=ds;
        UC.x+=C.x;
        UC.y+=C.y;
        X4=UC.x;
        Y4=UC.y;
        pf("%.10lf %.10lf %.10lf %.10lf\n",X3,Y3,X4,Y4);
    }

    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

