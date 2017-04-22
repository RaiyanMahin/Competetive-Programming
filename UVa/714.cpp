#include<stdio.h>
#include<string.h>
int main()
{
   long long int i,v,c,r,k,t,ans,j,m,mm,n,s,ar[1009],sl[1009];
   scanf("%lld",&t);
    for(r=0;r<t;r++)
    {
        scanf("%lld %lld",&v,&c);
        s=0;m=0;n=10000000000;
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
                    if(j>mm)
                        mm=j;
                }
                else
                {
                    j=ar[i];
                    k++;
                }
              if(j>mm)
                 mm=j;
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
         memset(sl,0,sizeof(sl));
         j=0;k=0;m=c;
         for(i=v-1;i>=0;i--)
         {
              if(j+ar[i]<=n&&(i+1)>=(m-k))
                {
                    j+=ar[i];

                }
                else
                {
                    sl[i+1]=1;
                    j=ar[i];k++;
                }

         }
         for(i=0;i<v;i++)
         {
             if(i!=0)
                printf(" ");
             if(sl[i]!=0)
                printf("/ ");

             printf("%d",ar[i]);
         }
       printf("\n");
    }
    return 0;
}
