#include<stdio.h>
#include<string.h>
#include<math.h>
long long int p;
 long long int Bigmod(long long int a,long long int b)
 {
     long long int half,k,m;
     if(b==0)
        return 1;
     if(b%2==0)
     {
         half=Bigmod(a,b/2);
           return ((half%p)*(half%p))%p;

     }
     else
        {
            return ((a%p)*Bigmod(a,b-1)%p)%p;
        }
 }
 int main()
 {
     long long int a,b,t,r;

     while(scanf("%lld %lld %lld",&a,&b,&p)==3)
     {

         printf("%lld\n",Bigmod(a,b));
     }
     return 0;
 }

