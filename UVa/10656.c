#include<stdio.h>
int main()
{
    int i,j,k,l,n,t,ar[10001];
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
        }

      k=0;j=1;
      for(i=0;i<n;i++)
      {

        k=k+ar[i];
        if(ar[i]!=0&&j==1)
           {
                printf("%d",ar[i]);
                j=0;
           }
        else if(ar[i]!=0&&j==0)
        {
            printf(" %d",ar[i]);

        }
      }
      if(k==0)
        printf("0\n");
      else
        printf("\n");
    }
    return 0;
}
