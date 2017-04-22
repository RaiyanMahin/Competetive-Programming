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
int ar[30][500],dis[30];
int dp[30][500];
int rec(int p,int k,int n)
{
    if(p>=n)
    {
        dp[p][k]=0;
        return 0;
    }
    if(k<=0)
        return 0;
    int &ret=dp[p][k];
    ret=0;
    for(int i=0;i<=k;i++)
    {
        ret=max(ret,ar[p][i]+rec(p+1,k-dis[p]-i,n));
    }
    return ret;
}
vector<int>ans;
void rec1(int p,int k,int rem,int n)
{
    if(k<=0)
        return ;
    if(p>=n)
    {
        //dp[p][k]=0;
        return ;
    }

   for(int i=k;i>=0;i--)
   {
       if((rem-ar[p][i]==0)||(rem-ar[p][i]==dp[p+1][k-dis[p]-i]))
          {
              ans.pb(i);
              rec1(p+1,k-dis[p]-i,rem-ar[p][i],n);
              break;
          }
   }
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d",&n,&k);
        k=k*12;
        memset(ar,0,sizeof(ar));
        for(i=0;i<n;i++)
        {
            sn("%d",&ar[i][1]);ar[i][0]=0;
        }
        for(i=0;i<n;i++)
        {
            sn("%d",&d);
            u=ar[i][1];
            for(j=2;j<=k;j++)
            {
                u=max(0,u-d);
                ar[i][j]=ar[i][j-1]+u;
            }
        }
        memset(dis,0,sizeof(dis));
        for(i=0;i<n-1;i++)
        {
           sn("%d",&dis[i]);
        }
        memset(dp,-1,sizeof(dp));
        u=rec(0,k,n);
        pf("Case %d:\n",cs++);
        ans.clear();
        rec1(0,k,u,n);
        for(i=0;i<n;i++)
        {
            if(i!=0)pf(", ");
            if(i<ans.size())
                pf("%d",ans[i]*5);
            else pf("0");
        }
        pf("\n");
        pf("Number of fish expected: %d\n",u);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

