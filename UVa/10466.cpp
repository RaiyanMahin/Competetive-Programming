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
int R[100],T[100];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    while(sn("%d %d",&n,&k)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            sn("%d %d",&R[i],&T[i]);
        }
        double x=0,y=0,xx,yy;

        for(i=0;i<n;i++)
        {
            vec P=vec(x,y);
            if(i==0)
            {
                double theta=2.0*PI*(k%T[i]);
                theta/=(double)T[i];
                double H=(double)R[i]*sin(theta);
                double V=(double)R[i]*cos(theta);
                xx=V,yy=H;
                pf("%.4lf",dis(0,0,xx,yy));
                x=xx;y=yy;
            }
            else
            {
                vec Q=vec(xx+100,yy);
                vec PQ=make_vac(P,Q);
                vec U=unit_vec(PQ);
                double theta=2.0*PI*(k%T[i]);
                theta/=(double)T[i];
               // pf("\n%lf %lf\n",sin(theta),cos(theta));
                double H=(double)R[i]*sin(theta);
                double V=(double)R[i]*cos(theta);
                U.x*=V;
                U.y*=V;
                U.x+=P.x;
                U.y+=P.y;
                double cx=U.x,cy=U.y,X3,Y3,X1=xx,Y1=yy,X2=xx+100,Y2=yy;
                double a,b,c,k1,m1;
                a=Y2-Y1;
                b=-1*(X2-X1);
                c=Y1*(X2-X1)-(Y2-Y1)*X1;
                k1=a*cy-b*cx;
                if(b!=0)
                {
                    Y3=cy+1000;
                    X3=(a*yy-k1)/b;
                }
                else
                {
                    X3=cx+1000;
                    Y3=(b*xx+k1)/a;
                }
                vec A=vec(X3,Y3);
                vec UA=make_vac(U,A);
                vec UU=unit_vec(UA);
                UU.x*=H;
                UU.y*=H;
                UU.x+=U.x;
                UU.y+=U.y;

                xx=UU.x;yy=UU.y;
                pf(" %.4lf",dis(0,0,xx,yy));
                x=xx;y=yy;
            }
        }
        pf("\n");
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

