#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,t,r,l;
    char st[200];
    scanf("%d",&t);
    getchar();
    for(r=1;r<=t;r++)
    {
        gets(st);
        l=strlen(st);
        if(l%2==0)
        for(j=0;st[j];j++)
        {
                if((st[j]=='('&&st[j+1]==')')||(st[j]=='['&&st[j+1]==']'))
            {

                while(st[j])
                {

                    st[j]=st[j+2];
                    if(st[j]=='\0')
                    {
                      j=-1;
                         break;
                    }
                        j++;
                }
            }

        }
         if(st[0]=='\0')
        printf("Yes\n");
    else
        printf("No\n");
    }

  return 0;
}
