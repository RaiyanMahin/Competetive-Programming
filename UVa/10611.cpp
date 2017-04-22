#include<stdio.h>
#include<string.h>
int arr[50009]={0};

int main()
{
    int k,i,r,n,m,h,l,q,ar[50009],a[50009];

       while(scanf("%d",&n)!=EOF)
  {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
            scanf("%d",&r);
        for(i=0;i<r;i++)
            scanf("%d",&a[i]);
        for(i=0;i<r;i++)
        {
            l=0;h=n;m=(l+h)/2;q=a[i];
            while(l<=h)
          {
            if(ar[m]<q)
            {
                if(m!=n-1&&ar[m+1]<q)
                    l=m+1;
                else
                    break;
            }
            else
                h=m-1;
            m=(l+h)/2;
          }
          if(l>h)
          printf("X ");
          else
            printf("%d ",ar[m]);
      l=0;h=n;m=(l+h)/2;q=a[i];
        while(l<=h)
          {
                if(ar[m]>q)
                {
                    if(m!=0&&ar[m-1]>q)
                        h=m-1;
                    else
                        break;
                }
                else
                    l=m+1;
                m=(l+h)/2;
            }
          if(l>h)
          printf("X\n");
          else
            printf("%d\n",ar[m]);

        }
    }
    return 0;
}
