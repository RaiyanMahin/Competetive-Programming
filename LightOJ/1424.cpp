
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
char st[2005];
int hi[2005],lf[2005],rg[2005];
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
        int ans=0;
        memset(hi,0,sizeof(hi));
        for(i=0;i<n;i++)
        {
            sn("%s",&st);
            hi[0]=hi[m+1]=-1;
            for(j=1;j<=m;j++)
            {
                if(st[j-1]=='0')
                    hi[j]++;
                else
                    hi[j]=0;
                lf[j]=j-1;
                while(hi[lf[j]]>=hi[j])lf[j]=lf[lf[j]];
            }
            for(j=m;j>0;j--)
            {
                rg[j]=j+1;
                while(hi[rg[j]]>=hi[j])rg[j]=rg[rg[j]];

                ans=max(ans,hi[j]*(rg[j]-lf[j]-1));

            }

        }
        pf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
