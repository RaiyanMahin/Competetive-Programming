#include<stdio.h>
int main()
{
    long long int s1,s2,n,i,j,r,wr,b,k,l,t,m,ar[30],a[30];
    scanf("%lld",&t);

    for(i=0;i<t;i++)
    {
        printf("\n");
        scanf("%lld",&n);
        s2=0;

        for(s1=1;s2<=9876543210;s1++)
        {
            m=s1;r=0;
            for(k=0;m!=0;k++)
            {
                ar[k]=m%10;
                m=m/10;
                if(k==0)
                    r=1;
               for(b=0,l=0;b<k;b++)
               {
                   if(ar[b]!=ar[k])
                    {
                        l++;
                        if(l==k)
                            r++;
                    }
               }
            }
            if(k==r)
            {
                s2=s1*n;
                m=s2;r=0;
                for(k=0;m!=0;k++)
              {
                ar[k]=m%10;
                m=m/10;
                if(k==0)
                    r=1;
               for(b=0,l=0;b<k;b++)
                 {
                   if(ar[b]!=ar[k])
                    {
                        l++;
                        if(l==k)
                            r++;
                    }
                 }
              }
            if(s2>9876543210)
                break;
              if(k==r)
              {
                  printf("%lld / %lld = %lld\n",s2,s1,n);
              }
            }
        }

    }
    return 0;
}
