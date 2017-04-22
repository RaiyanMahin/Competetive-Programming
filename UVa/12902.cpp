//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include <iostream>
#include<stack>
#include<map>
#include<string>
#include<vector>

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
const int sz=300000;
char st[sz];
int ar[sz];
int arr[sz];
int vis[sz];
char ss[1000][15];

int min_cnt(int ans)
{
    int a,b,c,l,i,j,s;
         l=strlen(st);
         s=0;
         a=0;b=0;
         for(i=0;i<l;i++)
         {
             ar[i]=0;arr[i]=0;
             if(i>0&&st[i]!=st[i-1])
                s++;
             if(st[i]=='a')
                ar[s]++,arr[s]=1;
             else
                ar[s]++,arr[s]=2;
         }
         for(;i<l+6;i++)
         ar[i]=0,arr[i]=0;
         b=-1;a=0;
         for(i=0;i<=s;i++)
         {
             if(arr[i]==1)
             {
                 a=a+ar[i];
             }
             else
             {
                 if(ar[i]>=a)
                 {
                     b=i;a=0;
                 }
                 else
                 {
                     a=a-ar[i];
                 }

             }
             vis[i]=0;
         }
         vis[s+1]=0;
         for(i=b;i>=0;i--)
            vis[i]=1;
         a=0;
         for(i=0;i<=s;i++)
         {
             //pf("%d %d\n",arr[i],ar[i]);
             if(arr[i]==2)
             {
                 if(a>ar[i])
                 {
                     a=a-ar[i];
                 }
                 else
                 {
                     if(arr[i+1]==1)
                     {
                         if(vis[i+1]==0&&ar[i+1]>0)
                         {
                             ans++;
                             ar[i+1]--;
                             a++;
                             ans=ans+(ar[i]+1-a);
                             a=1;
                         }
                         else
                         {
                             ans=ans+(ar[i]+1-a);
                             a=1;
                         }
                     }
                     else
                     {
                        ans=ans+(ar[i]+1-a);
                        a=1;
                     }
                 }
             }
             else
             {
                 a=a+ar[i];
             }
         }
        return ans+a-1;
}
int main()
{
    int i,j,k,l,t,cs=1,r=0,s,m,n,a,b,c,d,e,f,g,h,u,v;
    //freopen("input.txt","r",stdin);
    //freopen("input.txt","r",stdin);
     sn("%d",&t);
     while(t--)
     {
         sn("%s",&st);
         l=strlen(st);

         int ans=min_cnt(0);

         if(l>2&&st[0]=='+'&&st[1]=='a'&&st[2]=='a')
         {
             st[0]='a',st[1]='a',st[2]='+';

             ans=min(ans,min_cnt(2));
         }
         pf("Case %d: %d\n",cs++,ans);
     }


    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
