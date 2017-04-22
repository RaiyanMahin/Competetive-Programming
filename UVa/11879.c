
#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,l,m=0,n,d=17;
    char ch[100000];
    while(scanf("%s",ch)!=EOF)
{
    if(ch[0]=='0')
        break;
    m=0;
    for(i=0;ch[i];i++)
    {
        n=m*10+(ch[i]-48);
        m=n%d;
    }
   if(m==0)
     printf("%d\n",1);
   else
     printf("%d\n",0);
}

return 0;
}
