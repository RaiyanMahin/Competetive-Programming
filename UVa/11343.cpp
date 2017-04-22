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
double a,b,c,d;
}ar[105];
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
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);
        for(i=0;i<n;i++)
        {
            sn("%lf %lf %lf %lf",&ar[i].a,&ar[i].b,&ar[i].c,&ar[i].d);
        }
        int ans=0;
        for(i=0;i<n;i++)
        {
            s=0;
            vec P=vec(ar[i].a,ar[i].b);
            vec Q=vec(ar[i].c,ar[i].d);
            vec PQ=make_vac(P,Q);
            for(j=0;j<n;j++)
            {
                if(i==j)continue;
                vec A=vec(ar[j].a,ar[j].b);
                vec B=vec(ar[j].c,ar[j].d);
                vec AB=make_vac(A,B);
                vec PA=make_vac(P,A);
                vec PB=make_vac(P,B);
                vec AP=make_vac(A,P);
                vec AQ=make_vac(A,Q);
                if(crossproduct(PQ,PA)==0)
                {
                    vec QP=make_vac(Q,P);
                    vec QA=make_vac(Q,A);
                    if(dotproduct(PQ,PA)>=0&&dotproduct(QP,QA)>=0)
                    {
                        s=1;
                    }
                }
                if(crossproduct(PQ,PB)==0)
                {
                    vec QP=make_vac(Q,P);
                    vec QB=make_vac(Q,B);
                    if(dotproduct(PQ,PB)>=0&&dotproduct(QP,QB)>=0)
                    {
                        s=1;
                    }
                }
                if(crossproduct(AB,AP)==0)
                {
                    vec BA=make_vac(B,A);
                    vec BP=make_vac(B,P);
                    if(dotproduct(AB,AP)>=0&&dotproduct(BA,BP)>=0)
                    {
                        s=1;
                    }
                }
                if(crossproduct(AB,AQ)==0)
                {
                    vec BA=make_vac(B,A);
                    vec BQ=make_vac(B,Q);
                    if(dotproduct(AB,AQ)>=0&&dotproduct(BA,BQ)>=0)
                    {
                        s=1;
                    }
                }
                if(crossproduct(PQ,PA)*crossproduct(PQ,PB)<0&&crossproduct(AB,AP)*crossproduct(AB,AQ)<0)
                {
                    s=1;
                }
            }
            if(!s)
                ans++;
        }
        pf("%d\n",ans);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

