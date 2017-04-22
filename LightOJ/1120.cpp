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
ll x1,x2,y,flag;
 T(){};
 T(int _x1,int _x2,int _y,int _flag){
     x1=_x1;x2=_x2;y=_y;flag=_flag;
 }
}ar[100000];
ll tr[400000],vis[400000],X[100000];
void update(int p,int l,int r,int x,int y,int v)
{
    if(l>y||r<x)
        return;
    if(l>=x&&r<=y)
    {
        vis[p]+=v;
        if(vis[p]>0)
            tr[p]=X[r]-X[l-1];
        else
            tr[p]=tr[2*p]+tr[2*p+1];
        return ;
    }
    int mid=(l+r)/2;
    update(2*p,l,mid,x,y,v);
    update(2*p+1,1+mid, r,x,y,v);
    if(vis[p]>0)
        tr[p]=X[r]-X[l-1];
    else
        tr[p]=tr[2*p]+tr[2*p+1];
}
bool cmp(T A,T B)
{
    return A.y<B.y;
}
int fnd_pos(int p,int n)
{
    int lw=0,hi=n-1,mid;
    while(lw<=hi)
    {
        mid=(lw+hi)/2;
        if(X[mid]==p)
            return mid;
        else if(X[mid]>p)
        {
            hi=mid-1;
        }
        else
        {
            lw=mid+1;
        }
    }
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    int x1,x2,y1,y2;
    while(t--)
    {
        sn("%d",&n);
        a=c=0;
        for(i=0;i<n;i++)
        {
            sn("%d %d %d %d",&x1,&y1,&x2,&y2);
            X[c++]=x1;
            X[c++]=x2;
            ar[a++]=T(x1,x2,y1,1);
            ar[a++]=T(x1,x2,y2,-1);
        }
        sort(X,X+c);
        b=1;
        for(i=1;i<c;i++)
        {
            if(X[b-1]!=X[i])
                X[b++]=X[i];
        }
        sort(ar,ar+a,cmp);
        memset(tr,0,sizeof(tr));
        memset(vis,0,sizeof(vis));
        ll ans=0;
        for(i=0;i<a-1;i++)
        {
            u=1+fnd_pos(ar[i].x1,b);
            v=fnd_pos(ar[i].x2,b);
            if(u<=v)
            {
                update(1,0,b-1,u,v,ar[i].flag);
            }
            ans=ans+(abs(ar[i+1].y-ar[i].y))*tr[1];
        }
        pf("Case %d: %lld\n",cs++,ans);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

