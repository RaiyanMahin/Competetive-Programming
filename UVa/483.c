#include<stdio.h>
#include<string.h>
int main()
{
    char str[8000],st[8000],s;
    int i,j=0,k,l,n=0,p=0;
    while(gets(str)){
            n=0;p=0;j=0;
    l=strlen(str);
    for(i=0;i<=l;i++)
    {
        if(str[i]==' '||str[i]=='\0')

       {  n=p;

            for(k=i-1;k>=n;k--)
          {
           st[j]=str[k];
            j++;
            p++;
          }
          p++;
          if(str[i]!='\0')
          {
              st[j]=str[i];
            j++;
          }
        }
    }
    for(i=0;i<l;i++)
    printf("%c",st[i]);
    printf("\n");

}
return 0;
}
