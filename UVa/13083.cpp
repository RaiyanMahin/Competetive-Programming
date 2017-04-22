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
#define sn scanf
#define pf printf
#define pb push_back
#define mp make_pair

const double PI=2.0*acos(0);

typedef long long int ll;
using namespace std;
const int N=10000005;
ll ar[100000],sz=0;
int vis[N]={0};
ll pr[1000000];
void prim()
{
    int i,j,k,l;
    for(i=3;i<=sqrt(N)+1;i+=2)
    {
        if(vis[i]==0)
        {
            for(j=i*i;j<=N;j+=i*2)
                if(j%i==0)
                vis[j]=1;
        }
    }k=1;
    pr[0]=2;
    for(i=3;i<=N;i+=2)
       if(vis[i]==0)
    {
        //printf("%d\n",i);
        pr[k++]=i;
    }
   // printf("%d\n",k);
   sz=k;
}
ll gcd(ll a,ll b)
{
    if(a%b==0)
        return b;
    else return gcd(b,a%b);
}
ll fre[10000],divs[10000],fac[9000][15],sum=0;
void fnd_sum(ll p,ll n,ll cur,ll tot,ll d)
{
    if(p>=n)
    {
        sum+=(cur)*tot;
        return;
    }
    ll cc=cur;
    for(int i=0;i<=fre[p];i++)
    {
        cur=cc;
        if(i==0)
        {
            cur=cur*1;
        }
        else
        {
            cur=cur*(i*2+1);
            tot/=ar[p];
        }
        fnd_sum(p+1,n,cur,tot,d);
    }
}
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen("in.txt","r",stdin);
    prim();
    //return 0;
    sn("%lld",&t);
    while(t--)
    {
        sn("%lld",&n);
        u=n;c=0;
        memset(fre,0,sizeof(fre));
        for(i=0;i<sz;i++)
        {
            if(pr[i]>sqrt(u))
                break;
            if(u%pr[i]==0)
                ar[c++]=pr[i];
            while(u%pr[i]==0)
            {
                fre[c-1]++;
                u/=pr[i];
            }
        }
        if(u>1)
        {
                ar[c++]=u;
                fre[c-1]++;
        }
         ll ans;

        sum=0;
       // pf("%lld\n",n);
        fnd_sum(0,c,1,n,0);
        ans=sum;
        pf("Case %lld: %lld\n",cs++,ans);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

