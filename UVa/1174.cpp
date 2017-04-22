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
    ll i,j,k,l,t,r,u,v,s,m,n,a,b,x;
    char st[500],ch[50];
    scanf("%lld",&t);
    for(x=1;x<=t;x++)
     {
         sn("%lld %lld",&n,&m);
         for(i=1;i<=n;i++)
            P[i]=i;
         map<string,ll>Si;
         for(i=0,j=1;i<m;i++)
         {
             sn("%s %s %lld",&st,&ch,&r);
             if(Si[st]==0)
             {
                 Si[st]=j;j++;
             }
             if(Si[ch]==0)
             {
                 Si[ch]=j;j++;
             }
             ar[i].a=Si[st];
             ar[i].b=Si[ch];
             ar[i].c=r;
         }
         sort(ar,ar+m,cmp);
         s=0;
         for(i=0;i<m;i++)
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
             }
         }
            pf("%lld\n",s);
            if(x!=t)
                pf("\n");
                Si.clear();
     }
    return 0;
}


