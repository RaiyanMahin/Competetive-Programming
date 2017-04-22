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
ll gcd(ll a,ll b)
{
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll ar[300005],vis[300005],arr[300005];
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f=200002,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
     for(i=1;i<=f;i++)
        ar[i]=i,vis[i]=0,arr[i]=0;
     ar[1]=0;
     for(i=2;i<=f;i++)
     {
         if(ar[i]==i)
         {
             ar[i]=arr[i]=i-1;
             for(j=i+i;j<=f;j+=i)
             {
                 vis[j]+=-i;
                 a=(j/i)-1;
                arr[j]+=vis[i]*a;
                arr[j]+=i*a;
                ar[j]=(ar[j]*(i-1))/i;
             }
         }
         else
         {
             arr[i]=ar[i]+arr[i];
            for(j=i+i;j<=f;j+=i)
             {
                 vis[j]+=-(i+vis[i]);
                 a=(j/i)-1;
                arr[j]+=vis[i]*a;
                arr[j]+=i*a;
             }
         }
     }
    for(i=2;i<=f-1;i++)
        arr[i]=arr[i]+arr[i-1];
    while(sn("%lld",&n)==1)
    {
        if(n==0)break;
        pf("%lld\n",arr[n]);
//        for(i=10;i<=n;i++)
//        {
//            a=0;
//            for(j=1;j<i;j++)
//            {
//                a=a+gcd(j,i);
//            }
//            if(arr[i]!=a)
//                pf("%lld %lld %lld\n",i,arr[i],a);
//        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

