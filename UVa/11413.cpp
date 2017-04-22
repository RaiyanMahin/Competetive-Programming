#include<stdio.h>
int main()
{
   long long int i,v,c,k,ans,j,m,mm,n,s,ar[1009];
    while(scanf("%lld %lld",&v,&c)!=EOF)
    {
        s=0;m=0;n=1000000000;
        for(i=0;i<v;i++)
        {
            scanf("%lld",&ar[i]);
            s=s+ar[i];
            if(ar[i]>m)
                m=ar[i];
        }
        if(c>v)
            c=v;
        ans=(m+s)/2;
        while(m<=s)
        {
            j=0;mm=0;
            for(i=0,k=1;i<v;i++)
            {
                if(j+ar[i]<=ans)
                {
                    j+=ar[i];
                }
                else
                {
                    j=ar[i];
                    k++;
                }
            }

            if(k<=c)
               {
                if(n==ans&&k==c)
                    break;
                  if(ans<n)
                    n=ans;
                  s=ans-1;
               }
            else if(k>c)
                m=ans+1;

            ans=(m+s)/2;
        }

            printf("%lld\n",n);

    }
    return 0;
}
