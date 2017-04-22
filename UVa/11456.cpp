#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;


int ar[10000],lis[10000],lds[10000];


int main()
{
    int t,r,a,b,i=0,j=0,n=0,m,md,h,l,k;
      scanf("%d",&t);
     for(r=1;r<=t;r++)
     {
             scanf("%d",&n);
             j=3000;k=3000;
             for(i=0;i<n;i++)
              {
                scanf("%d",&ar[i]);
              }
        memset(lds,0,sizeof(lds));
        memset(lis,0,sizeof(lis));
         for(i=n-1;i>=0;i--)
         {
             for(j=i+1;j<n;j++)
             {
                 if(ar[i]>ar[j])
                 {
                     if(lis[i]<lis[j]+1)
                         lis[i]=lis[j]+1;
                 }
             }
         }
         for(i=n-1;i>=0;i--)
         {
             for(j=i+1;j<n;j++)
             {
                 if(ar[i]<ar[j])
                 {
                     if(lds[i]<lds[j]+1)
                         lds[i]=lds[j]+1;
                 }
             }
         }
         m=0;
         for(i=0;i<n;i++)
         {
             if(lis[i]+lds[i]+1>m)
                m=lis[i]+lds[i]+1;
         }
         printf("%d\n",m);
     }
   return 0;
}


