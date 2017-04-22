#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;


int main()
{
    long long int r=1,i,j,k,l,m,n,s,d,a,b,c,u,w,v,ar[30],arr[200];
    char ch;
    while(scanf("%lld",&n)==1)
    {

           for(i=0;i<n;i++)
             scanf("%lld",&ar[i]);
           for(i=0,k=0;i<n;i++)
           {
               a=1;
               for(j=i;j<n;j++)
               {
                   a=a*ar[j];
                   arr[k++]=a;
               }
           }
           m=0;
           for(i=0;i<k;i++)
            if(arr[i]>m)
               m=arr[i];
            printf("Case #%lld: The maximum product is %lld.\n\n",r,m);
            r++;
    }
   return 0;
}



