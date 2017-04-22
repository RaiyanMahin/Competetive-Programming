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
int vis[100005],ar[100005];
vector<int>arr[100005];

int LIS(int n)
{
    int i,j,k,lw,hi,mid,l=0;
    for(i=0;i<n;i++)
        vis[i]=-1000000000;
    for(i=n-1;i>=0;i--)
    {
        if(i==n-1)
        {
            vis[l++]=ar[i];
            arr[l-1].pb(i);
        }
        else
        {
            lw=0,hi=l-1;
            while(lw<=hi)
            {
                mid=(lw+hi)/2;
                if(vis[mid]>ar[i])
                {
                    if(mid+1<l&&vis[mid+1]>ar[i])
                        lw=mid+1;
                    else break;
                }
                else hi=mid-1;
            }
            if(lw>hi)
            {
                vis[0]=max(vis[0],ar[i]);
                arr[0].pb(i);
            }
            else
            {
                vis[mid+1]=max(vis[mid+1],ar[i]);
                arr[mid+1].pb(i);
                if(mid+1>=l)
                    l++;
            }
        }
    }

    for(i=l-1;i>=0;i--)
    {
        for(j=0;j<arr[i].size();j++)
        {
            int u=arr[i][j];
            vis[u]=i+1;
        }
    }
    for(i=0;i<=l;i++)
        arr[i].clear();
    return l;
}
int main()
{
    int i,j,k,l,t,cs=1,q,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);sn("%d",&q);
        for(i=0;i<n;i++)
        {
            sn("%d",&ar[i]);
        }
        l=LIS(n);

        pf("Case %d:\n",cs++);
        while(q--)
        {
            sn("%d",&u);
            if(l<u)
            {
                pf("Impossible\n");
            }
            else
            {
                 v=-1000000000;
                for(i=0;i<n;i++)
                {
                      if(vis[i]>=u&&ar[i]>v&&u>0)
                      {
                          pf("%d",ar[i]);
                          v=ar[i];u--;
                          if(u>0)pf(" ");
                      }
                }
                pf("\n");
            }
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

