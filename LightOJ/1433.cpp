#include<stdio.h>
#include<math.h>
int main()
{
    int i,t,r,j;
    double k,l,m,n,ox,oy,ax,ay,bx,by,ang;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&ox,&oy,&ax,&ay,&bx,&by);
        m=sqrt(((ox-ax)*(ox-ax))+((oy-ay)*(oy-ay)));
        n=sqrt(((ox-bx)*(ox-bx))+((oy-by)*(oy-by)));
        k=sqrt(((ax-bx)*(ax-bx))+((ay-by)*(ay-by)));
        ang=((m*m)+(n*n))-(k*k);
        ang/=(2*m*n);
        ang=acos(ang);
        l=m*ang;
        printf("Case %d: %.7lf\n",r,l);
    }
    return 0;
}
