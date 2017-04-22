//BISMILLAHHIR RAHMANIR RAHIM
#include<stdio.h>
#include<math.h>
int main()
{
    long long int i,j,t,r,k,l,m,n,a,h,b,c,f,d,ar[100];
    scanf("%lld",&t);
    for(r=1; r<=t; r++)
    {
        scanf("%lld",&n);
        l=1;h=45000;
        m=(l+h)/2;
        while(l<=h)
        {
            a=m;j=0;b=0;
            while(a>0)
            {
                if((a-j)>0)
                b+=((a-j)*(a-j+1))/2;
                else
                    break;
                j=j*10+9;

            }

            if(n<=b)
            {
                  a=m-1;j=0;d=0;
                while(a>0)
                {
                    if((a-j)>0)
                    d+=((a-j)*(a-j+1))/2;
                    else
                        break;
                    j=j*10+9;

                }

                if(n<=d)
                    h=m-1;
                else
                    break;

            }
            else if(b<n)
                l=m+1;
            else if(b>n)
                h=m-1;
            m=(l+h)/2;

        }
        f=-1;
       for(i=m;i>=m-1;i--)
       {
           a=i;
           while(a>=1)
           {
               d=a;
               while(d!=0)
              {
                   if(b==n)
                  {
                   f=d%10;break;
                  }
                  d/=10;
                  b--;
              }
              a--;
              if(f!=-1)
                break;
           }
            if(f!=-1)
                break;
       }
       printf("%lld\n",f);

    }
    return 0;
}
