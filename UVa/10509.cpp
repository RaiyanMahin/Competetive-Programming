//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<math.h>

int main()
{
    double j,k,l,m,n,b,c,a;
    int i;
    while(scanf("%lf",&n)==1)
    {
        if(n==0)
            break;
        for(i=1;i<n;i++)
        {
            if((i*i*i)<=n&&((i+1)*(i+1)*(i+1))>n)
                break;
        }

        a=(double)i;
       // c=4*3*a*((a*a*a)-n);
        j=9*a*a*a*a;
       // k=sqrt(j-c);
        j=3*a*a;
        b=((a*a*a)-n)/j;
       // l=(k+0.0000001)-j;
       // l/=(6*a);

        printf("%.4lf\n",a-b);

    }
    return 0;
}
