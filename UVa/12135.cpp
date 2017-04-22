

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
int a;
};

int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    sn("%d",&t);
    while(t--)
    {
        int ar[45],dp[33000];
        sn("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            sn("%d",&u);v=0;
            for(j=0;j<u;j++)
            {
                sn("%d",&a);
                v=v|(1<<a);
            }
            ar[i]=v;
        }
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        for(i=0;i<m;i++)
        {
           for(j=(1<<n)-1;j>=0;j--)
           {
               if(dp[j]!=-1&&(dp[j^ar[i]]>dp[j]+1||dp[j^ar[i]]==-1))
               {
                   dp[j^ar[i]]=dp[j]+1;
               }
           }
        }
        int q;char st[100];
        pf("Case %d:\n",cs++);
        sn("%d",&q);
        while(q--)
        {
            sn("%s",&st);v=0;
            for(i=0,j=n-1;i<n;i++,j--)
            {
                if(st[i]=='1')
                    v|=(1<<j);
            }
            pf("%d\n",dp[v]);
        }
        pf("\n");
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
