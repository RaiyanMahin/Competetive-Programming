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
ll a,b;
}ar[705];

int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    freopen("Output.txt","r",stdin);
  #endif
    sn("%lld",&t);
    while(t--)
    {
        sn("%lld",&n);
        for(i=0;i<n;i++)
        {
            sn("%lld %lld",&ar[i].a,&ar[i].b);
        }
        vector<ll>dis;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                a=ar[i].a-ar[j].a;
                b=ar[i].b-ar[j].b;
                c=(a*a)+(b*b);
                dis.pb(c);
            }
        }

        sort(dis.begin(),dis.end());
        a=0;b=-1;
        for(i=0;i<dis.size();i++)
        {
            if(b!=dis[i])a++;
            b=dis[i];
        }
        pf("Case %lld: %lld\n",cs++,a+1);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

