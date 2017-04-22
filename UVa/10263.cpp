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
double X[100005],Y[100005];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    double xm,ym;

    //freopen(".txt","r",stdin);
    while(sn("%lf %lf",&xm,&ym)!=EOF)
    {
        sn("%d",&n);
        n++;
        double ans=0,anx,any;
        for(i=0;i<n;i++)
        {
            sn("%lf %lf",&X[i],&Y[i]);
            if(i==0)
            {
                ans=dis(xm,ym,X[i],Y[i]);
                anx=X[i];
                any=Y[i];
            }
            else if(i>0&&ans>dis(xm,ym,X[i],Y[i]))
            {
                ans=dis(xm,ym,X[i],Y[i]);
                anx=X[i];
                any=Y[i];
            }
        }
        c=-11;
        vec O=vec(xm,ym);
        for(i=1;i<n;i++)
        {
            vec P=vec(X[i-1],Y[i-1]);
            vec Q=vec(X[i],Y[i]);
            vec PQ=make_vac(P,Q);
            vec QP=make_vac(Q,P);
            vec PO=make_vac(P,O);
            vec QO=make_vac(Q,O);
            if(dotproduct(PQ,PO)>0&&dotproduct(QP,QO)>0)
            {
                double aa=crossproduct(PQ,PO)/vec_value(PQ);
                aa=fabs(aa);
                if(ans>aa)
                {
                    c=i;
                    ans=aa;
                    anx=dotproduct(PQ,PO)/vec_value(PQ);
                }
            }
        }
        if(c>0)
        {
            vec P=vec(X[c-1],Y[c-1]);
            vec Q=vec(X[c],Y[c]);
            vec PQ=make_vac(P,Q);
            vec un=unit_vec(PQ);
            un.x*=anx;
            un.y*=anx;
            anx=un.x+P.x;
            any=un.y+P.y;
        }
        pf("%.4lf\n",anx);
        pf("%.4lf\n",any);
       // printf("%lf",45.5645);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

