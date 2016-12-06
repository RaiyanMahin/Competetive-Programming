#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,l,m,n,t,r,a,b,c,d,ar[1000];
    char st[50];
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %d",&n,&m);
        printf("Case %d:\n",r);
        for(i=0;i<100;i++)
            ar[i]=1000;
        k=0;j=0;
        for(i=0;i<m;i++)
        {
            scanf("%s",&st);
            if(strcmp(st,"pushLeft")==0)
            {
                scanf("%d",&a);
                if(j>=n)
                    printf("The queue is full\n");
                else
                {
                    printf("Pushed in left: %d\n",a);
                    for(d=0;d<n;d++)
                        if(ar[d]!=1000)
                          break;
                    if(ar[d]==1000||d==0)
                        d=1;

                    for(l=d-1;l<=n;l++)
                    {

                        c=ar[l];
                        ar[l]=a;
                        a=c;
                      if(c==1000)
                        break;
                    }
                    j++;
                }
            }
            else if(strcmp(st,"pushRight")==0)
            {
                scanf("%d",&a);
                if(j>=n)
                    printf("The queue is full\n");
                else
                {
                    printf("Pushed in right: %d\n",a);
                    ar[j]=a;
                    j++;
                }
            }
            else if(strcmp(st,"popRight")==0)
            {
               if(j<=0)
                    printf("The queue is empty\n");
               else
               {
                   for(d=n-1;d>=0;d--)
                   {
                       if(ar[d]!=1000)
                       {
                            printf("Popped from right: %d\n",ar[d]);
                            ar[d]=1000;
                            j--;break;
                       }

                   }

               }
            }
            else if(strcmp(st,"popLeft")==0)
            {
               if(j<=0)
                    printf("The queue is empty\n");
               else
               {
                   for(d=0;d<n;d++)
                   {
                       if(ar[d]!=1000)
                       {
                            printf("Popped from left: %d\n",ar[d]);
                            ar[d]=1000;
                            for(b=0;b<n;b++)
                                ar[b]=ar[d+1],d++;
                            j--;break;
                       }
                   }
               }
            }
        }
    }
    return 0;
}

