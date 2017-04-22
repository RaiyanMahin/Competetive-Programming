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
int a,b,c;
}ar[1000007];
int  P[1000007];

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
   int i,j,k,l,t,r,u,v,s,m,n,a,b;
     while(sn("%d %d",&n,&m)==2)
     {
         if(n==0&&m==0)
            break;
         for(i=0;i<n;i++)
            P[i]=i;
         for(i=0;i<m;i++)
         {
             scanf("%d %d %d",&ar[i].a,&ar[i].b,&ar[i].c);
         }
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
                 if(ar[i].c>s)
                 s=ar[i].c;
                 k--;
             }
         }
         if(k)
            pf("IMPOSSIBLE\n");
         else
            pf("%d\n",s);
     }
    return 0;
}


