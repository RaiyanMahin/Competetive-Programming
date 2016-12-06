#include<stdio.h>
int main()
{
    int i,j,k,l,m,n,t,r,ar[2000];
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
            m=2;j=0;
        for(i=0;i<n;i++)
            {
                if(ar[i]>m)
                {
                    l=ar[i]-m;
                    j+=(l/5);
                    if(l%5>0)
                        j++;
                    m=ar[i];
                }
            }
        printf("Case %d: %d\n",r,j);
    }
    return 0;
}
