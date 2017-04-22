#include<stdio.h>
int main()
{
    int i,j,l,a,b,c;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF)
    {
        if(a==b&&b==c&&c==a)
            printf("*\n");
        else if(a==b)
            printf("C\n");
        else if(a==c)
            printf("B\n");
        else if(c==b)
            printf("A\n");
    }
    return 0;
}

