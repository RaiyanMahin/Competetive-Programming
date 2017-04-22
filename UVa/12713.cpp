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

typedef long long int ll;
using namespace std;
struct T{
int a;
};
ll modd=1000003,fac[2000000],ifac[2000000],pw1[2000000],pw2[2000000],pw3[2000000];
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


int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v,x,y,z;
    fac[0]=1;ifac[0]=bigmod(fac[0],modd-2,modd);
    for(i=1;i<=modd;i++)
    {
        fac[i]=(fac[i-1]*i)%modd;
        ifac[i]=bigmod(fac[i],modd-2,modd);
    }
    sn("%lld",&t);
    while(t--)
    {
        sn("%lld %lld %lld %lld %lld",&a,&b,&x,&y,&z);
        pw1[0]=pw2[0]=pw3[0]=1;
        x=x%modd;y=y%modd;z=z%modd;
        for(i=1;i<=modd;i++)
        {
            pw1[i]=(pw1[i-1]*x)%modd;
            pw2[i]=(pw2[i-1]*y)%modd;
            pw3[i]=(pw3[i-1]*z)%modd;
        }
        ll ans=1;
        while(a>0&&b>0)
        {
            u=a%modd;v=b%modd;
            c=min(u,v);
            s=0;
            for(i=0;i<=c;i++)
            {
                f=pw1[u-i]*pw2[v-i]*pw3[i]%modd;
                f=(f*fac[u+v-i])%modd;
                f=(f*ifac[u-i])%modd;
                f=(f*ifac[i])%modd;
                f=(f*ifac[v-i])%modd;
                s=(s+f)%modd;
            }
            ans=ans*s%modd;
            a/=modd;b/=modd;
        }
        pf("%lld\n",ans);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

