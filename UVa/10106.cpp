
#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,a,b,k,l,n,m,hand=0,u,v,put,t,stor[100000];
    char ch[100000],c[100000],temp[100000];
   while(scanf("%s %s",&ch,&c)!=EOF)
    {
         l=strlen(ch);
    k=strlen(c);
    j=(l>k)?(l-1):(k-1);
    if(l<k)
    {
        strcpy(temp,ch);
        strcpy(ch,c);
        strcpy(c,temp);
    }
    n=l-1;k=strlen(c);
    m=k-1;hand=0;v=0;u=0;
    for(i=j;i>=0;i--)
    {
            put=0;
        for(a=i,b=m-u;a<=j&&b>=0;b--,a++)
        {
            put+=((ch[a]-'0')*(c[b]-'0'));
        }
        put+=hand;
        hand=put/10;
        if(i==0&&u==k-1)
            stor[v++]=put;
        else
         stor[v++]=put%10;
        if(i==0&&u<k-1)
        {
            u++;i=1;
        }
    }
    for(i=v-1,u=0;i>=0;i--)
        if((u==0&&stor[i]!=0)||(u>0))
        printf("%d",stor[i]),u++;
    if(u==0)
        printf("0");
    printf("\n");
    }
    return 0;
}


