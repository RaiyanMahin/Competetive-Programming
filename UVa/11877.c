
#include<stdio.h>
int main()
{
    int i,n,j,k,l,m;
    while(scanf("%d",&m)!=EOF)
    {
        if(m==0)
            break;
        n=m;
            i=0;
        while(n>=3)
        {

            n=n-3;
            i++;
            n=n+1;
        }
          if(n+1==3)
                i++;
        printf("%d\n",i);
    }
    return 0;
}
