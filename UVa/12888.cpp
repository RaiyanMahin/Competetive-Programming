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
 vector<int>arr,prr;
int pr[1000005]={0};
int ar[1000006];
void seive()
{
    ll a,b,i,j,k,n=1000000,m=sqrt(n);
    for(i=1;i<=n;i++)
        ar[i]=i;
    for(i=2;i<=n;i++)
    {
        if(ar[i]==i)
        {
            for(j=i;j<=n;j+=i)
            {
                if(j%i==0)ar[j]=ar[j]/i,pr[j]++;
            }
        }
    }
    for(i=2,j=0;i<=n;i++)
    {
        if(ar[i]==1)
            arr.pb(i),pr[j++]=pr[i];
    }
}
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif

     seive();
     l=arr.size();
     //pf("%lld\n",l);
     sn("%lld",&t);
     while(t--)
     {
         sn("%lld %lld",&n,&m);
         if(n>m)swap(n,m);
         ll ans=0;
         for(j=0;j<l;j++)
         {
             if(arr[j]>n)break;
             u=n/arr[j];
             if(pr[j]%2==1)
              ans=ans+(m/arr[j])*u;
              else
                 ans=ans-(m/arr[j])*u;
         }
         pf("%lld\n",(n*m)-ans);
     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

