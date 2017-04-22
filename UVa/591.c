#include<stdio.h>
int main()
{
    int n,ar[100],s,h,k=1,i,m;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
            h=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            h=h+ar[i];
        }
        printf("Set #%d\n",k);

            m=h/n;s=0;
            for(i=0;i<n;i++)
            {
                if(ar[i]>m)
                    s=s+(ar[i]-m);
            }
            printf("The minimum number of moves is %d.\n\n",s);


        k++;
    }
    return 0;
}
