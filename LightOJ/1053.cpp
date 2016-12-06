#include<stdio.h>
int main()
{
   long long int t,r,a,b,c;
   scanf("%lld",&t);
   for(r=1;r<=t;r++)
   {
       scanf("%lld %lld %lld",&a,&b,&c);
       if(((a*a)+(b*b))==c*c||((a*a)+(c*c))==b*b||((c*c)+(b*b))==a*a)
        printf("Case %lld: yes\n",r);
       else
        printf("Case %lld: no\n",r);
   }
   return 0;
}
