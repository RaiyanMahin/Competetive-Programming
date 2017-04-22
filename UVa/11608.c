#include<stdio.h>
int main()
{
    int i,j,r=1,k,l,n,m,ar1[13],ar[13],y;
    while(scanf("%d",&ar[0])!=EOF)
    {
        if(ar[0]<0)
            break;

        for(i=1;i<13;i++)
        {
            scanf("%d",&ar[i]);
        }
        for(i=0;i<12;i++)
        {
            scanf("%d",&ar1[i]);
        }
        printf("Case %d:\n",r);
        for(i=0,y=0;i<12;i++)
        {
            y=y+ar[i];
            if(y>=ar1[i])
               {
                    printf("No problem! :D\n");y=y-ar1[i];
               }
            else
                printf("No problem. :(\n");
        }

        r++;
    }
    return 0;
}
