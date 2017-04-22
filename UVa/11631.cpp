//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
#define N 100000000
#define Inf 200000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;


vector<int>cost[1000];
queue<int>Q;
map<char,int>Si;
map<int,string>Is;
int P[1000000];
struct T{
int a,b,c;

}ar[1000000];

bool cmp(T x,T y)
{
    return x.c<y.c;
}
int findp(int u)
{
    if(P[u]==u)
        return u;
    return P[u]=findp(P[u]);
}
int main()
{
    int i,j,k,u,v,l,q,r=1,t,n,m,s,sc,d,dc,E;
     while(scanf("%d %d",&n,&m)==2)
     {
         if(n==0&&m==0)
            break;
         for(i=0;i<n;i++)
            P[i]=i;
            s=0;sc=0;
         for(i=0;i<m;i++)
         {
             scanf("%d %d %d",&ar[i].a,&ar[i].b,&ar[i].c);
             sc+=ar[i].c;
         }
         sort(ar,ar+m,cmp);
         s=0;
         for(i=0;i<m;i++)
         {
             u=findp(ar[i].a);
             v=findp(ar[i].b);
             if(u!=v)
             {
                 if(u<v)
                    P[v]=u;
                 else
                    P[u]=v;
                 s+=ar[i].c;
             }

         }

         printf("%d\n",sc-s);
     }
    return 0;
}






