
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
int bit[200000],arr[200000],Q[100000];
struct T{
int x,y;
}ar[100000];
int fnd(int u,int n)
{
    int lw=0,hi=n-1,mid;
    while(lw<=hi)
    {
        mid=(lw+hi)/2;
        if(arr[mid]==u)
            return mid;
        else if(arr[mid]<u)
            lw=mid+1;
        else
            hi=mid-1;
    }
}
void update(int idx,int maxx,int v)
{
    while(idx<maxx)
    {
        bit[idx]+=v;
        idx+=idx&-idx;
    }
}

int query(int idx)
{
    int s=0;
    while(idx>0)
    {
        s+=bit[idx];
        idx-=idx&-idx;
    }
    return s;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d",&n,&d);
        j=0;
        for(i=0;i<n;i++)
        {
            sn("%d %d",&ar[i].x,&ar[i].y);
            arr[j++]=ar[i].x;
            arr[j++]=ar[i].y;
        }
        for(i=0;i<d;i++)
        {
            sn("%d",&Q[i]);
            arr[j++]=Q[i];
        }
        sort(arr,arr+j);
        c=1;
        for(i=0;i<j;i++)
        {
            if(arr[c-1]!=arr[i])
                arr[c++]=arr[i];
        }
        memset(bit,0,sizeof(bit));
        for(i=0;i<n;i++)
        {
            u=fnd(ar[i].x,c);
            v=fnd(ar[i].y,c);
            update(u+1,c+1,1);
            update(v+2,c+1,-1);
        }
        pf("Case %d:\n",cs++);
        for(i=0;i<d;i++)
        {
            u=Q[i];
            pf("%d\n",query(fnd(u,c)+1));
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/


