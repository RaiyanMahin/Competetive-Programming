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
double x,y;
}ar[1000];
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
bool cmp(T x,T y)
{
    return x.x<y.x;
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
            sn("%lf %lf",&ar[i].x,&ar[i].y);
        }
        double ans=0;
        sort(ar,ar+n,cmp);
        for(i=0;i<n;i++)
        {
          //  pf("--%d %d\n",(int)ar[i].x,(int)ar[i].y);
        }
        for(i=n-2;i>=0;i--)
        {
            if(i==n-2)
            {
                ans=ans+dis(ar[i+1].x,ar[i+1].y,ar[i].x,ar[i].y);
            }
            for(j=i-1;j>=0;j--)
            {
                vec P=vec(ar[i].x,ar[i].y);
                vec Q=vec(ar[i].x,0);
                vec O=vec(ar[j].x,ar[j].y);
                vec PQ=make_vac(P,Q);
                vec PO=make_vac(P,O);
                if(dotproduct(PQ,PO)<0)
                {
                    if(j+1==i)
                    {
                        ans=ans+dis(ar[j+1].x,ar[j+1].y,ar[j].x,ar[j].y);
                    }
                    else
                    {
                        double a1,a2,b1,b2,c1,c2,m1,m2,xx,yy;
                        m1=(ar[j].y-ar[j+1].y)/(ar[j].x-ar[j+1].x);
                        m2=0;
                        a1=m1;a2=m2;
                        b1=b2=-1;
                        c1=ar[j+1].y-m1*ar[j+1].x;
                        c2=ar[i].y;
                        xx=((-c1/a1)+((b1*c2)/(a1*b2)))/(1-((a2*b1)/(a1*b2)));
                        yy=(-c2/b2)-((a2*xx)/b2);
                        ans=ans+dis(ar[j].x,ar[j].y,xx,yy);
                    }

                    break;
                }
            }
            i=j+1;
        }
        pf("%.2lf\n",ans);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
