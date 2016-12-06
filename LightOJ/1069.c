#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t,r,i,a,b;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %d",&a,&b);
        i=abs(b-a)+a;
        i=i*4;
        printf("Case %d: %d\n",r,i+19);
    }
    return 0;
}
