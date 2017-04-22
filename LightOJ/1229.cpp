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
ll bigmod(ll a,ll b,ll mod)
{
    if(b==0)return 1;
    if(b%2==0)
    {
        ll hh=bigmod(a,b/2,mod);
        return (hh*hh)%mod;
    }
    else
    {
       return (a*bigmod(a,b-1,mod))%mod;
    }
}
vector<int>ans;
int dp[205],vis[1005],viss[205];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    s=0;
    dp[0]=0;
    memset(vis,-1,sizeof(vis));
    memset(viss,-1,sizeof(viss));
    for(i=1;i<=205;i++)
    {
        dp[i]=0;
        for(j=1;j<=i;j++)
        {
            u=max(0,j-3);
            v=max(0,i-j-2);
            vis[(dp[u]^dp[v])]=i;
            dp[i]=max(dp[i],(dp[u]^dp[v]));
        }
        for(j=0,k=dp[i];j<=k;j++)
        {
            if(vis[j]!=i)
                break;
        }
        dp[i]=j;
    }
    sn("%d",&t);
    while(t--)
    {
        char st[205];
         sn("%s",&st);
         l=strlen(st);
         memset(viss,0,sizeof(viss));
         for(i=0;i<l;i++)
         {
             a=0;b=-1;
             for(j=i;j<i+3&&j<l;j++)
             {
                 if(st[j]=='X')
                    a++;
                 else b=j;
             }
             if(a==2&&b!=-1&&viss[b]==0)
             {
                 ans.pb(b);viss[b]=1;
             }
         }
         pf("Case %d:",cs++);
         if(ans.size()>0)
         {
            for(i=0;i<ans.size();i++)
            {
                pf(" %d",ans[i]+1);
            }
            pf("\n");
         }
         else
         {
            h=0;
            memset(vis,0,sizeof(vis));

            for(i=0;i<l;i++)
            {
                for(j=max(0,i-2);j<l&&j<i+3;j++)
                {
                    if(st[j]=='X')
                        vis[i]=1;
                }
            }
            for(k=0;k<l;k++)
            {
                if(vis[k]==0)
                {
                    st[k]='X';
                    memset(viss,0,sizeof(viss));
                     for(i=0;i<l;i++)
                        {
                            for(j=max(i-2,0);j<l&&j<=i+2;j++)
                            {
                                if(st[j]=='X')
                                    viss[i]=1;
                            }
                        }
                    st[k]='.';
                    s=0;a=0;
                    for(i=0;i<l;i++)
                    {
                        if(viss[i]==0)
                            a++;
                        else
                            s=s^dp[a],a=0;
                    }
                    s=s^dp[a];
                    if(s==0)
                        ans.pb(k+1);
                }
            }
            if(ans.size()==0)
                pf(" 0\n");
            else
            {
                for(i=0;i<ans.size();i++)
                {
                    pf(" %d",ans[i]);
                }
                pf("\n");
            }
         }
         ans.clear();
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

