#include<stdio.h>
int main()
{
  long long  int i,t,r,j,k,l,m,n,w,a,b,c,s;
    scanf("%lld",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%lld %lld",&n,&m);
        s=0;b=0;a=0;k=0;
         if(m%2==0)
         {
             if(n%2==0)
                w=0;
             else
                w=1;
         }
         else
         {
             if(n%2==0)
                w=1;
             else
                w=0;
         }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%lld",&c);
                if(w==1)
                {
                    if(i%2==0)
                    {
                        if(j%2==0)
                            s^=c;
                    }
                    else
                    {
                        if(j%2==1)
                            s^=c;
                    }
                }
                else
                {
                    if(i%2==0)
                    {
                        if(j%2==1)
                            s^=c;
                    }
                    else
                    {
                        if(j%2==0)
                            s^=c;
                    }

                }
            }
        }
        if(s!=0)
            printf("Case %lld: win\n",r);
        else
            printf("Case %lld: lose\n",r);
    }
    return 0;
}
