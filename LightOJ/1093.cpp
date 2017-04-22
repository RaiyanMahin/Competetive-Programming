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
int a,b;
}tr[500000];
int ar[100005];
void build(int p,int l,int r)
{
    if(l==r)
    {
        tr[p].a=tr[p].b=ar[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    tr[p].a=min(tr[2*p].a,tr[2*p+1].a);
    tr[p].b=max(tr[2*p].b,tr[2*p+1].b);
}
int query(int p,int l,int r,int x,int y,int ty)
{
    if(l>y||r<x)
    {
        if(ty==1)
            return 1000000000;
            return 0;
    }
    if(l>=x&&r<=y)
    {
        if(ty==1)
        return tr[p].a;
        return tr[p].b;
    }
    int mid=(l+r)/2;
    if(ty==1)
        return min(query(2*p,l,mid,x,y,ty),query(2*p+1,mid+1,r,x,y,ty));
        return max(query(2*p,l,mid,x,y,ty),query(2*p+1,mid+1,r,x,y,ty));
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d",&n,&d);
        for(i=0;i<n;i++)
        {
            sn("%d",&ar[i]);
        }
        build(1,0,n-1);
        int ans=0;
        for(i=0;i+d-1<n;i++)
        {
            ans=max(ans,query(1,0,n-1,i,i+d-1,2)-query(1,0,n-1,i,i+d-1,1));
        }
        pf("Case %d: %d\n",cs++,ans);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

