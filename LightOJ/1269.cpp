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
int a[3];
}tr[1600005];
void mem(int u)
{
    tr[u].a[0]=-1;
    tr[u].a[1]=-1;
    return ;
}
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
     sn("%lld",&t);

     while(t--)
     {
         sn("%lld",&n);
         ll minx=1000000000000000,maxx=0;
         s=0;
         mem(0);f=1;
         for(j=0;j<n;j++)
         {
             sn("%lld",&a);
             if(a>maxx)
                maxx=a;
             if(a<minx)
                minx=a;
             r=0;s=s^a;h=g=0;
             a=s;
              if(a>maxx)
                maxx=a;
             if(a<minx)
                minx=a;
             if(j!=0)
             for(i=32;i>=0;i--)
             {
                 if(a&(1LL<<i))
                 {
                     if(tr[r].a[1]!=-1)
                        r=tr[r].a[1];
                     else
                       {
                            r=tr[r].a[0];
                            h=h|(1LL<<i);
                       }
                 }
                 else
                 {
                     if(tr[r].a[0]!=-1)
                        r=tr[r].a[0];
                     else
                        r=tr[r].a[1],h=h|(1LL<<i);;
                 }
             }
             if(j>0&&h<minx)
                minx=h;
              g=0;r=0;
              if(j!=0)
              for(i=32;i>=0;i--)
             {
                 if(!(a&(1LL<<i)))
                 {
                     if(tr[r].a[1]!=-1)
                        r=tr[r].a[1], g=g|(1LL<<i);
                     else
                        r=tr[r].a[0];
                 }
                 else
                 {
                     if(tr[r].a[0]!=-1)
                        r=tr[r].a[0],g=g|(1LL<<i);
                     else
                        r=tr[r].a[1];
                 }
             }
             if(g>maxx&&j>0)
                maxx=g;
             r=0;
            for(i=32;i>=0;i--)
             {
                 if((a&(1LL<<i)))
                 {
                     if(tr[r].a[1]==-1)
                        tr[r].a[1]=f,mem(f),r=f,f++;
                     else
                        r=tr[r].a[1];
                 }
                 else
                 {
                     if(tr[r].a[0]==-1)
                        tr[r].a[0]=f,mem(f),r=f,f++;
                     else
                        r=tr[r].a[0];
                 }
             }
         }
         pf("Case %lld: %lld %lld\n",cs++,maxx,minx);
     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

