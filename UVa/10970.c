#include<stdio.h>
int main()
{
    int m,n,i,j,k;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        if(m==0||n==0)
            printf("%d\n",(m*n));
        else
           printf("%d\n",(m*n)-1);
    }
    return 0;
}
