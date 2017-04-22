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
char st[11111];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
     sn("%d",&t);
     while(t--)
     {
         sn("%s",&st);
         l=strlen(st);
         u=0;v=0;c=0;d=0;f=0;
         for(i=0,a=0;i<=l;i++)
         {
             if(st[i]=='x')
             {
                 if(d==0)c=1;
                 if(f==a)
                 u=u-c;
                 else u=u+c;
                 c=0;d=0;
             }
             else if(st[i]=='-')
             {
                 if(f==a)
                 v=v+c;
                 else v=v-c;
                 f=1;
                 c=0;d=0;
             }
             else if(st[i]=='+')
             {
                 if(f==a)
                 v=v+c;
                 else v=v-c;
                 f=0;
                 c=0;d=0;
             }
             else if(i==l)
             {
                 if(f==a)
                 v=v+c;
                 else v=v-c;
                 f=1-f;
                 c=0;d=0;
             }
             else if(st[i]=='=')
             {
                 if(f==a)
                 v=v+c;
                 else v=v-c;
                c=d=f=0;a=1;
             }
             else if(st[i]>='0'&&st[i]<='9')
             {
                 c=c*10+st[i]-'0';d++;
             }
         }
         if((v==u&&u==0))
            pf("IDENTITY\n");
         else if(v!=u&&u==0)
            pf("IMPOSSIBLE\n");
        else
            pf("%0.lf\n",floor((double)v/(double)u));
     }
    return 0;
}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

