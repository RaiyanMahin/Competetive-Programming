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
ll dp[55][53][53][53],mod=1000000007,len;
char st[55],ss[55],tem[55],tt[55];
ll rec(int p,int a,int b,int c,int n,int pr)
{
    if(p<0)
    {
        if(a!=0&&a==b&&b==c){
            return 1;
        }
        else return 0;
    }
   ll &ret=dp[p][a][b][c];
   if(ret!=-1){
     return ret;
   }
   ret=0;
   int pp;
   for(int i=0;i<=9;i++)
   {
      // if(i<tem[len-p]-'0')
        pp=0;
      // else pp=pr;
       if(i%3!=0||i==0)
       {
           ret=(ret+rec(p-1,a,b,c,i,pp));
           if(ret>=1000000007)ret-=1000000007;
       }
      else if(i==3)
        ret=(ret+rec(p-1,a+1,b,c,3,pp));
       else if(i==6)
         ret=(ret+rec(p-1,a,b+1,c,6,pp));
      else if(i==9)
        ret=(ret+rec(p-1,a,b,c+1,9,pp));
        if(ret>=1000000007)ret-=1000000007;
   }
   ret=ret%1000000007;
   return ret;
}

int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    //freopen("E:\\uva\\1.unsubmitt\\input.txt","r",stdin);
    memset(dp,-1,sizeof(dp));
    rec(52,0,0,0,10,0);
    //pf("%d\n",rec(2,0,0,0,1,0));
    sn("%lld",&t);
    while(t--)
    {
        sn("%s %s",&st,&ss);
        l=strlen(st);
        a=b=c=d=e=0;
        len=l-1;
        for(i=l-1;i>=0;i--){

            for(j=0;j<st[l-1-i]-'0';j++)
            {
                int aa,bb,cc;aa=bb=cc=0;
                if(j==3)aa++;
                if(j==6)bb++;
                if(j==9)cc++;
                d=(d+rec(i-1,aa+a,bb+b,cc+c,j,0))%1000000007;
            }
            if(st[l-1-i]=='3')a++;
            if(st[l-1-i]=='6')b++;
            if(st[l-1-i]=='9')c++;
        }
        a=b=c=e=0;
        l=strlen(ss);
        for(i=l-1;i>=0;i--){

            for(j=0;j<ss[l-1-i]-'0';j++)
            {
                int aa,bb,cc;aa=bb=cc=0;
                if(j==3)aa++;
                if(j==6)bb++;
                if(j==9)cc++;
                e=(e+rec(i-1,aa+a,bb+b,cc+c,j,0))%1000000007;
            }
            if(ss[l-1-i]=='3')a++;
            if(ss[l-1-i]=='6')b++;
            if(ss[l-1-i]=='9')c++;
        }
        if(a!=0&&a==b&&b==c)
            e++;
        pf("%lld\n",(e-d+1000000007)%1000000007);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

