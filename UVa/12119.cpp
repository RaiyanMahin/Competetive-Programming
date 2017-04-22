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
ll a,b,c;
}ans[1000000];

ll gcd(ll a,ll b)
{
    return  (a%b==0) ? b : gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
    ll d=gcd(a,b);
    return (a*b)/d;
}

bool cmp( T x,T y)
{
    if(x.a==y.a)
    {
        if(x.b==y.b)
            return x.c<y.c;
        return x.b<y.b;
    }
    return x.a<y.a;
}

int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    while(sn("%lld",&n)&&n)
    {
        vector<int>ar;
        d=min(n,(ll)1000000);
        for(i=1;i<=d;i++)
        {
            if(n%i==0)
            {
                ar.pb(i);
            }
        }
        l=ar.size();b=0;
        for(i=0;i<l;i++)
        {
            for(j=i+1;ar[j]<ar[i]+25&&j<l;j++)
            {
                for(k=j+1;ar[k]<=ar[i]+25&&k<l;k++)
                {
                    a=lcm(ar[i],ar[j]);
                    a=lcm(a,ar[k]);
                    if(a==n)
                    {
                        ans[b].a=ar[i];
                        ans[b].b=ar[j];
                        ans[b++].c=ar[k];
                    }
                }
            }
        }
        pf("Scenario %lld:\n",cs++);
        if(b==0)
            pf("Such bells don't exist\n");
        else
        {
            sort(ans,ans+b,cmp);
            for(i=0;i<b;i++)
                pf("%lld %lld %lld\n",ans[i].a,ans[i].b,ans[i].c);
        }
        pf("\n");
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

