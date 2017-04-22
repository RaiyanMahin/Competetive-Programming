#include<stdio.h>
#include<math.h>
int main()
{
    long long int i,j,k=2,l,m=0,s,n;
    for(i=6,j=0;;i++)
    {
       if(m==10)
        break;
       s=(i*(i+1))/2;
       n=((i+k)*(i+k+1))/2;
       n=n-s+i;
       if(s==n)
       {
           printf("%10lld%10lld\n",i,i+k);
           k=i+i+k;j=i;
           i=(k*2)+j;m++;
       }
    }
    return 0;
}
