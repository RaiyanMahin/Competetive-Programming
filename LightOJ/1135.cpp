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

typedef long long int ll;
using namespace std;
struct T{
 int i,j,k,s;
}tree[300005],t1,t2;

int query(int p,int l,int r,int x,int y,int z)
{
    if(l>y||r<x)
    {
        return 0;
    }
    if(l>=x&&r<=y)
    {
        z%=3;
        if(z==0)
            return tree[p].i;
        else if(z==2)
            return tree[p].j;
        else
            return tree[p].k;
    }
    int mid=(l+r)/2;
    return query(2*p,l,mid,x,y,z+tree[p].s)+query(2*p+1,mid+1,r,x,y,z+tree[p].s);
}
void shift(int p,int s)
{
    t1=tree[2*p];t2=tree[2*p +1];
    for(int i=0;i<s;i++)
    {
        int u=t1.k;
        t1.k=t1.j;
        t1.j=t1.i;t1.i=u;
        u=t2.k;
        t2.k=t2.j;
        t2.j=t2.i;t2.i=u;
    }
    tree[p].i=t2.i+t1.i;
    tree[p].j=t2.j+t1.j;
    tree[p].k=t2.k+t1.k;
}
void update(int p,int l,int r,int x,int y,int z)
{
     if(l>y||r<x)
    {
        return;
    }
    if(l>=x&&r<=y)
    {
        int u=tree[p].k;
        tree[p].k=tree[p].j;
        tree[p].j=tree[p].i;tree[p].i=u;
        tree[p].s=(tree[p].s+z)%3;
        return;
    }
    int mid=(l+r)/2;
    update(2*p,l,mid,x,y,z);
    update(2*p+1,mid+1,r,x,y,z);
     shift(p,tree[p].s);
}
void build(int p,int l,int r)
{
    if(l==r)
    {
        tree[p].i=1;
        return;
    }
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    tree[p].i=tree[2*p].i+tree[2*p+1].i;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
     sn("%d",&t);
     while(t--)
     {
         sn("%d %d",&n,&m);
         memset(tree,0,sizeof(tree));
         build(1,0,n-1);
         printf("Case %d:\n",cs++);
         while(m--)
         {
             sn("%d",&u);
             if(u==0)
             {
                 sn("%d %d",&u,&v);
                 update(1,0,n-1,u,v,1);
             }
             else
             {
                  sn("%d %d",&u,&v);
                  pf("%d\n",query(1,0,n-1,u,v,0));
             }
         }
     }
    return 0;
}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/



