//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;

ll P[10009];
struct T{
ll a,b,c,k;

}ar[120009];

bool cmp(T x,T y)
{
    if(x.c==y.c)
        return x.k>y.k;
    return x.c<y.c;
}

ll path(ll u)
{
    if(P[u]==u)
        return u;
    return P[u]=path(P[u]);
}

int main()
{
    ll i,j,k,u,v,l,t,r,s,m,n,a,b,C,d,f,g,h;
     scanf("%lld",&t);
     for(r=1;r<=t;r++)
     {
         scanf("%lld %lld %lld",&n,&m,&C);
         for(i=1;i<=n;i++)
            P[i]=i;
         for(i=0;i<m;i++)
         {
             scanf("%lld %lld %lld",&ar[i].a,&ar[i].b,&ar[i].c);
             ar[i].k=1;
         }
         for(i=0;i<n-1;i++)
         {
             ar[i+m].a=i+1;
             ar[i+m].b=i+2;
             ar[i+m].c=C;
             ar[i+m].k=2;
         }
         sort(ar,ar+n+m-1,cmp);
         f=0;s=0;
         for(i=0;i<n+m-1;i++)
         {
             u=path(ar[i].a);
             v=path(ar[i].b);
             if(u!=v)
             {
                 if(u<v)
                    P[v]=u;
                 else
                    P[u]=v;
                 s+=ar[i].c;
                 if(ar[i].k==2)
                    f++;
             }
         }
         pf("Case #%lld: %lld %lld\n",r,s+C,f+1);

     }
    return 0;
}

