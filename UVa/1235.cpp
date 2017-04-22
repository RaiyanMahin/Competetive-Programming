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
}ar[1000000];
int  P[1000];

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
   int i,j,k,l,t,r,u,v,s,m,n,a,b,c,d,f,g,h,aa[5000];
   map<int,int>II;
   scanf("%d",&t);
     while(t--)
     {
         sn("%d",&n);
         for(i=0;i<=n;i++)
            P[i]=i;
            aa[0]=0;
         for(i=0;i<n;i++)
         {
             scanf("%d",&a);
             II[a]=i+1;
             aa[II[a]]=a;

         }
         for(i=1,m=0;i<=n;i++)
         {

             for(j=i+1;j<=n;j++)
             {
                 f=aa[j];s=0; d=aa[i];
                 for(k=0;k<4;k++)
                 {
                     a=f%10;b=d%10;g=abs(a-b);
                     c=(g<(10-g))?g:10-g;
                     s+=c;
                     f/=10;d/=10;
                 }

                   //  pf("%04d  %04d %d\n",aa[i],aa[j],s);
                     ar[m].a=i;ar[m].b=j;
                     ar[m].c=s;m++;

             }
         }
         ar[m].c=100000000;
          for(j=1;j<=n;j++)
             {
                 f=aa[j];s=0; d=0;
                 for(k=0;k<4;k++)
                 {
                     a=f%10;b=d%10;g=abs(a-b);
                     c=(g<(10-g))?g:10-g;
                     s+=c;
                     f/=10;d/=10;
                 }

                if(ar[m].c>s)
                {
                     ar[m].a=0;ar[m].b=j;
                     ar[m].c=s;
                }


             }
             m++;
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
                    //pf("%04d  %04d %d\n",aa[ar[i].a],aa[ar[i].b],ar[i].c);
                 s+=ar[i].c;

             }
         }
            pf("%d\n",s);
            II.clear();
     }
    return 0;
}



