#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;


int aa[10000],ar[10000],lis[10000],lds[10000];


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
              for(i=0;i<n;i++)
              {
                scanf("%d",&aa[i]);
              }
        memset(lds,0,sizeof(lds));
        memset(lis,0,sizeof(lis));
        a=0;b=0;
         for(i=0;i<n;i++)
         {
             lis[i]=aa[i];
             for(j=i-1;j>=0;j--)
             {
                 if(ar[i]>ar[j])
                 {
                     if(lis[i]<lis[j]+aa[i])
                         lis[i]=lis[j]+aa[i];
                 }
             }
             if(lis[i]>a)
                a=lis[i];
         }
         for(i=0;i<n;i++)
         {
             lds[i]=aa[i];
             for(j=i-1;j>=0;j--)
             {
                 if(ar[i]<ar[j])
                 {
                     if(lds[i]<lds[j]+aa[i])
                         lds[i]=lds[j]+aa[i];
                 }
             }
             if(b<lds[i])
                b=lds[i];
         }
       if(a>=b)
        printf("Case %d. Increasing (%d). Decreasing (%d).\n",r,a,b);
       else
        printf("Case %d. Decreasing (%d). Increasing (%d).\n",r,b,a);
     }
   return 0;
}




