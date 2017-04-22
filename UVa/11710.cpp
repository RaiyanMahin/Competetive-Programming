//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;

map<string,ll>Si;

struct T{
ll a,b,c;
}ar[79900];
ll  P[79900];

bool cmp(T x,T y)
{
    return x.c<y.c;
}

int path(int u)
{
    if(P[u]==u)
        return u;
    return P[u]=path(P[u]);
}

int main()
{
    ll i,j,k,l,t,r,u,v,s,m,n,a,b;
    char st[500],ch[50];
     while(sn("%lld %lld",&n,&m)==2)
     {
         if(n==0&&m==0)
            break;
         for(i=0;i<n;i++)
         {
             sn("%s",&st);
             Si[st]=i;
             P[i]=i;
         }
         for(i=0;i<m;i++)
         {
             sn("%s %s %lld",&st,&ch,&r);
             ar[i].a=Si[st];
             ar[i].b=Si[ch];
             ar[i].c=r;
         }
         scanf("%s",&st);
         sort(ar,ar+m,cmp);
         s=0;k=n-1;
         for(i=0;i<m&&k;i++)
         {
             u=path(ar[i].a);
             v=path(ar[i].b);
             if(u!=v)
             {
                 if(u<v)
                    P[v]=u;
                 else
                    P[u]=v;
                 s+=ar[i].c;k--;
             }
         }
         if(k)
            pf("Impossible\n");
         else
            pf("%lld\n",s);
     }
    return 0;
}

