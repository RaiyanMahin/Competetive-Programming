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
int a,b,c,d;
}arr[100005],ans[100005];
const double eps=1e-12;
struct vec{
double x,y;
int pos;
 vec(double xx=0,double yy=0,int poss=0)
 {
     x=xx;y=yy;pos=poss;
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
    return vec(p.x/va,p.y/va,p.pos);
}
double dis(double px,double py,double qx,double qy)
{
    px=fabs(px-qx);
    py=fabs(py-qy);
    return sqrt(px*px+py*py);
}
vec ar[100005];
bool cmp(vec x,vec y)
{
     if(fabs(x.x-y.x)<eps)
        return x.y<y.y;
      return x.x<y.x;
}
bool cmpp(T x,T y)
{
   return x.d<y.d;
}
bool cmp2(T x,T y)
{
    if(x.a==y.a)
        return x.b<y.b;
        return x.a<y.a;
}
int X[100005],Z[100007],Y[100005];
vector<int >group[100005];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    //freopen("out.txt","w",stdout);
     while(sn("%d",&n)!=EOF&&n)
     {
         for(i=0;i<n;i++)
         {
             sn("%d %d %d",&X[i],&Y[i],&Z[i]);
             vec P=vec(X[i],Y[i],i);
             P=unit_vec(P);
             ar[i]=P;
         }
         sort(ar,ar+n,cmp);
         for(i=0,j=0;i<n;i++)
         {
             if(i==0)
             {
                 group[j].pb(ar[i].pos);
             }
             else if(i>0&&fabs(ar[i-1].x-ar[i].x)<eps&&fabs(ar[i-1].y-ar[i].y)<eps)
             {
                 group[j].pb(ar[i].pos);
             }
             else
             {
                  j++;
                  group[j].pb(ar[i].pos);
             }
         }
         u=0;
         for(i=0;i<=j;i++)
         {
             h=-1000;
             for(k=0;k<group[i].size();k++)
             {
                arr[k].a=X[group[i][k]];
                arr[k].b=Y[group[i][k]];
                arr[k].c=group[i][k];
                arr[k].d=abs(arr[k].a)+abs(arr[k].b);
             }
             sort(arr,arr+k,cmpp);
             for(a=0;a<k;a++)
             {
                 if(Z[arr[a].c]<=h)
                 {
                     ans[u++]=arr[a];
                 }
                 h=max(h,Z[arr[a].c]);
             }
         }
         pf("Data set %d:\n",cs++);
         if(u==0)
         {
             pf("All the lights are visible.\n");
         }
         else
         {
             pf("Some lights are not visible:\n");
             sort(ans,ans+u,cmp2);
             for(i=0;i<u;i++)
             {
                 if(i!=0)pf(";\n");
                 pf("x = %d, y = %d",ans[i].a,ans[i].b);
             }
             pf(".\n");
         }
         for(i=0;i<=n;i++)
         {
             group[i].clear();
         }
     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

