//BISMILLAHIR  RAHMINIR RAHIM
#include<stdio.h>
#include<string.h>
int a[10000];
int main()
{
    int i,j,k,t,s,r=1,m,n,l,h,ar[100];
   while(scanf("%d",&n)!=EOF)
    {

       memset(a,0,sizeof(a));
       t=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);

            if(ar[i]<=0)
                t=-1;
            if(i!=0)
            {
                if(ar[i]<=ar[i-1])
                    t=-1;
            }
        }
        a[0]=1;
        for(i=0;i<n;i++)
          {
              for(j=1000;j>=0;j--)
                if(a[j]!=0&&j+ar[i]<=1000)
                a[j+ar[i]]++;
          }
          for(i=0;i<n;i++)
            if(a[ar[i]]>1)
            t=-1;
        printf("Case #%d:",r);
        for(i=0;i<n;i++)
        {
            printf(" %d",ar[i]);
        }

        if(t==0)
            printf("\nThis is an A-sequence.\n");
        else
            printf("\nThis is not an A-sequence.\n");
            r++;
    }

    return 0;
}

