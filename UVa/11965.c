#include<stdio.h>
#include<string.h>
int main()
{
    char str[100][600],ch=' ';
    int i,t,r,j,p,n,k,w,l[2000];
   scanf("%d",&t);
   for(r=1;r<=t;r++)
   {

       scanf("%d",&p);
       getchar();
     for(i=0;i<p;i++)
     {
            gets(str[i]);
         l[i]=strlen(str[i]);
     }
    n=0;
    printf("Case %d:\n",r);
    for(k=0;k<p;k++)
    {

        for(i=0;i<l[k];i++)
      {
          if(str[k][i]=='\t')
            str[k][i]=' ';

        if(str[k][i]==ch&&str[k][i-1]==ch&&i!=0);
        else
        {
          printf("%c",str[k][i]);
          n=0;
        }

      }
      printf("\n");

    }
      if(r!=t)
        printf("\n");
   }
    return 0;
}
