//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;
struct T{
int a,b,w;
}ar[10003];
int P[10000],Kp[10000];


bool cmp (T x,T y)
{
    return x.w<y.w;
}

int path(int u)
{
    if(P[u]==u)
        return u;
   return P[u]=path(P[u]);
}

int main()
{
    int i,j,k,l,t,r,s,m,n,u,v;
     while(scanf("%d %d",&n,&m)==2)
     {
         if(n==0&&m==0)
            break;
        for(i=0;i<n;i++)
        {
            P[i]=i;
        }
         for(i=0;i<m;i++)
         {
             scanf("%d %d %d",&ar[i].a,&ar[i].b,&ar[i].w);
         }
         sort(ar,ar+m,cmp);
         for(i=0,j=0;i<m;i++)
         {
             u=path(ar[i].a);
             v=path(ar[i].b);
             if(u!=v)
             {
                 if(u<v)
                    P[v]=u;
                 else
                    P[u]=v;
             }
            else
            {
                Kp[j]=ar[i].w;j++;
            }
         }
         sort(Kp,Kp+j);
         if(j==0)
            printf("forest\n");
         else
         {
             for(i=0;i<j;i++)
             {
                 if(i!=0)
                    pf(" ");
                  pf("%d",Kp[i]);
             }
             pf("\n");
         }
     }
    return 0;
}

