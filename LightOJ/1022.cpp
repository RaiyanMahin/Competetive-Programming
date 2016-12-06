#include<stdio.h>
#include<math.h>
#define pi 2*acos(0.0)
int main()
{
    double r,s,c,an;
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf",&r);
        s=4*r*r;
        c=pi*r*r;
        an=s-c;
        an+=pow(10,-9);
        printf("Case %d: %.2lf\n",i,an);

    }


    return 0;
}
