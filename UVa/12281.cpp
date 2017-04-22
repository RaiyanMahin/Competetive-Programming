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
ll ar[50];
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    ar[0]=1;ar[1]=2;
    for(i=2;i<=47;i++)
    {
        ar[i]=ar[i-1]+ar[i-2];
    }
    sn("%lld",&t);
    while(t--)
    {
        sn("%lld",&n);
        ll ans=1;
        for(j=0;j<n;j++)
        {
            sn("%lld",&a);c=0;
            for(i=47;i>=0;i--)
            {
                if(ar[i]<=a)
                {
                    a=a-ar[i];c++;
                }
            }
            ans=ans*c;
        }
        pf("Case %lld: %lld\n",cs++,ans);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

