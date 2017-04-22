#include<stdio.h>
int main()
{
    int i,j,k,lo,h,l,m,n;
   while(scanf("%d %d",&lo,&h)!=EOF)
{
    if(lo>99999||h>99999)
        break;
    if(lo<1||h<1)
        break;
      for(i=lo;i<=h;i++)
     {

               m=i;n=1;
              if(m<10)
                {
                    m=m*m;n++;
                }
               while(m>9)
               {
                   l=0;
                while(m!=0)
                {
                    j=m%10;
                    l=l+(j*j);
                    m=m/10;
                }
                n++;
                m=l;

               }
      if(m==1)
        printf("%d %d\n",i,n);
     }
   }
   return 0;
}
