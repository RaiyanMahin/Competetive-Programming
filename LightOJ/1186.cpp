#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t,r,i,j,m,n,k,ar[500],a[500];
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
            m=0;
        for(i=0;i<n;i++)
            {
                m^=(abs(ar[i]-a[i])-1);
            }
      if(m==0)
        printf("Case %d: black wins\n",r);
      else
        printf("Case %d: white wins\n",r);
    }
    return 0;
}
