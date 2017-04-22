//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
//bool re[1000009];
int main()
{
   long long int i,j=0,k,l,h,md,c,a,b,m,n,ar[50009];
    while(scanf("%lld",&n)!=EOF)
    {

        for(i=0;i<n;i++)
        {
            scanf("%lld",&ar[i]);
           // re[ar[i]]=1;
        }
        scanf("%lld",&m);
        sort(ar,ar+n);
        k=m;
        for(i=0;i<n;i++)
        {
            if(ar[i]>m/2)
                break;
            l=i;h=n-1;
            md=(l+h)/2;
            c=m-ar[i];
            while(l<=h)
            {
                if(ar[md]==c)
                    break;
                else if(ar[md]<c)
                    l=md+1;
                else
                    h=md-1;
                md=(l+h)/2;
            }
            if(l>h);
            else
            {
                 if((m-ar[i]-ar[i])<k)
                {
                    a=ar[i];b=m-ar[i];
                    k=m-ar[i]-ar[i];
                }
            }

        }
        printf("Peter should buy books whose prices are %lld and %lld.\n\n",a,b);j++;
    }
    return 0;
}
