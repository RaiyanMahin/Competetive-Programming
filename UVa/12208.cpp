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
ll ar[100];
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    ar[0]=0;
    ar[1]=1;a=1;
    for(i=2;i<=33;i++)
    {
        a=a*2;
        ar[i]=ar[i-1]+ar[i-1]+a;
    }
    while(sn("%lld %lld",&n,&m)==2)
    {
        if(n==0&&m==0)break;
        u=0;n--;
        for(i=31;i>=0;i--)
        {
            a=(1<<i)-1;
            if(a<=n)
            {
              u=u+ar[i]+(n-a);
              n=n-a-1;
            }
        }
         v=0;
        for(i=31;i>0;i--)
        {
            a=(1<<i)-1;
            if(a<=m)
            {
              v=v+ar[i]+(m-a);
              m=m-a-1;
            }
        }
        pf("Case %lld: %lld\n",cs++,v-u);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

