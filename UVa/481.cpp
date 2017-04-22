#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;


int ar[1000000],P[1000000],lis[1000000];

void path(int p)
{
    if(P[p]==-1)
    {
        printf("%d\n",ar[p]);
        return;
    }
    path(P[p]);
    printf("%d\n",ar[p]);

}


int main()
{
    int a,b,i=0,j=0,n=0,m,md,h,l;
      memset(P,-1,sizeof(P));
    while(scanf("%d",&ar[i])==1)
    {
         if(i==0)
        {
            lis[j]=i;
            j++;
        }
        else
        {
            l=0;h=j-1;
            md=(l+h)/2;
            while(l<=h)
            {
                if(ar[lis[md]]<ar[i])
                {
                    if(md!=j-1&&ar[lis[md+1]]<ar[i])
                        l=md+1;
                    else
                        break;
                }
                else
                {
                    h=md-1;
                }
                md=(l+h)/2;
            }
            if(l>h)
            {
                lis[0]=i;
            }
            else
            {
                lis[md+1]=i;
                P[i]=lis[md];
                if(md+1==j)
                    j++;
            }
        }
        i++;
    }
        printf("%d\n-\n",j);
        path(lis[j-1]);

        return 0;
}

