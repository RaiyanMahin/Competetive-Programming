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
int a;
};
int dp[500006][2],ar[55];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);
        s=0;
        for(i=0;i<n;i++)
        {
            sn("%d",&ar[i]);
            s+=ar[i];
        }
        memset(dp,-1,sizeof(dp));
        s=s/2;
        int ans=0;
        dp[s][0]=0;
        a=0;
//        if(s+s>500000)
//            while(1)
//        {
//            ;
//        }
       // pf("%d\n",s);
        for(i=0;i<n;i++)
        {
            ans=max(ans,dp[s][a]);
            u=ar[i];
            for(j=s+s;j>=0;j--)
            {
                dp[j][1-a]=max(dp[j][1-a],dp[j][a]);
                if(dp[j][a]!=-1&&j+u<=s+s)
                {
                    dp[j+u][1-a]=max(dp[j+u][1-a],ar[i]+dp[j][a]);
                }
                if(j+u<=s+s&&dp[j+u][a]!=-1)
                {
                    dp[j][1-a]=max(dp[j][1-a],dp[j+u][a]);
                }
            }
            ans=max(ans,dp[s][1-a]);
            a=1-a;
        }
        if(ans==0)
            pf("Case %d: impossible\n",cs++);
        else
            pf("Case %d: %d\n",cs++,ans);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

