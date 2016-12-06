#include<stdio.h>
int main()
{
    int i,j,k,t,r,n,m;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %d",&n,&m);
        if(n==1||m==1)
            k=n*m;
        else if((n==2||m==2)&&n%4!=0&&m%4!=0)
            {
                if(n%2==0&&m%2==0)
                    k=(n*m)/2 +2;
                else
                    k=(n*m)/2 +1;
            }
        else
        {
                if((n*m)%2==1)
                    k=(n*m)/2 +1;
                else
                    k=(n*m)/2;

        }
        printf("Case %d: %d\n",r,k);
    }
    return 0;
}
