#include<stdio.h>
int main()
{
     int r,t,i,k,h,l,j[100],n;
     scanf("%d",&t);
     for(r=1;r<=t;r++)
     {
         scanf("%d",&n);
         for(i=0;i<n;i++)
         {
             scanf("%d",&j[i]);
         }
         l=0;h=0;
         for(i=0;i<n-1;i++)
         {
            k=j[i+1]-j[i];
             if(k>0)
                h++;
             else if(k<0)
                l++;

         }
         printf("Case %d: %d %d\n",r,h,l);
     }
     return 0;
}
