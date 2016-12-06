#include<stdio.h>
int main()
{
    int t,r,i,j,k,m,x1,x2,y1,y2,x[200],y[200];
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&x[i],&y[i]);

        }
         printf("Case %d:\n",r);
        for(i=0;i<m;i++)
        {
            if((x[i]>x1&&x[i]<x2)||(x[i]<x1&&x[i]>x2))
                if((y[i]>y1&&y[i]<y2)||(y[i]<y1&&y[i]>y2))
                printf("Yes\n");
                else
                printf("No\n");
            else
                 printf("No\n",r);
        }

    }
    return 0;
}
