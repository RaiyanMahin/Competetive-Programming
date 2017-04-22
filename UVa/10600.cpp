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
struct T{
int a,b,c;
}ar[100000];
int P[100000];

int path(int u)
{
    if(P[u]==u)
        return u;
    return P[u]=path(P[u]);
}

bool cmp(T x,T y)
{
return x.c<y.c;

}

int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h;
     scanf("%d",&t);
     for(r=1;r<=t;r++)
     {

         scanf("%d %d",&n,&m);
         for(i=1;i<=n;i++)
         {
             P[i]=i;
         }
         for(i=0;i<m;i++)
         {
             sn("%d %d %d",&ar[i].a,&ar[i].b,&ar[i].c);
         }
         int s1=0,s2,u,v,PP[1000],Pv[1000];
         sort(ar,ar+m,cmp);
         for(i=j=0;i<m;i++)
         {
             u=path(ar[i].a);
             v=path(ar[i].b);
             if(u!=v)
             {
                 if(u<v)
                 {
                     P[v]=u;
                 }
                 else
                    P[u]=v;
                    PP[j]=i;Pv[j]=ar[i].c;j++;
                 s1+=ar[i].c;
             }
         }
         s2=g=10000000;
         h=j;
         for(i=0;i<j;i++)
         {
             for(d=1;d<=n;d++)
            {
             P[d]=d;
            }
             s=0;
             for(k=0,h=0;k<m;k++)
            {
                 u=path(ar[k].a);
                 v=path(ar[k].b);
                 if(u!=v&&PP[i]!=k)
                 {
                     if(u<v)
                     {
                         P[v]=u;
                     }
                     else
                        P[u]=v;
                     s+=ar[k].c;h++;
                 }
          }
          if(s<s2&&h==j)
            s2=s;
         }

           pf("%d %d\n",s1,s2);
     }
    return 0;
}

