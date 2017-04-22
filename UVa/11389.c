#include<stdio.h>
int main()
{
   long long int  n,d,r,t,i,j,k,l,mrn[1000],evn[1000];
   while(scanf("%lld %lld %lld",&n,&d,&r)!=EOF)
   {
       if(n==0&&d==0&&r==0)
         break;
       for(i=0,k=0;i<n;i++)
        {
            scanf("%lld",&mrn[i]);
        }
       for(i=0;i<n;i++)
        {
            scanf("%lld",&evn[i]);

        }
        for(i=0;i<n;i++)
        {
           for(j=0;j<n-1-i;j++)
           {
               if(mrn[j+1]>mrn[j])
               {
                   t=mrn[j+1];
                   mrn[j+1]=mrn[j];
                   mrn[j]=t;
               }

           }
           for(j=0;j<n-1-i;j++)
           {
               if(evn[j+1]<evn[j])
               {
                   t=evn[j+1];
                   evn[j+1]=evn[j];
                   evn[j]=t;
               }

           }
        }
        for(i=0;i<n;i++)
        {
            if(mrn[i]+evn[i]>d)
                k=k+mrn[i]+evn[i]-d;
        }
        printf("%lld\n",k*r);
   }
   return 0;
}
