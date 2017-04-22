#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,k,l,m,n;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n<=-1&&m<=-1)
            break;
        i=abs(n-m);
        if(n<m)
        {
            j=abs((n+100)-m);
        }
        else
        {
            j=abs((m+100)-n);
        }
        if(i>j)
            printf("%d\n",j);
        else
            printf("%d\n",i);
    }
    return 0;
}
