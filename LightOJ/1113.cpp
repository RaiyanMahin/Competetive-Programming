
#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,l,m,t,r;
    char st[105][100],s[100];
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        printf("Case %d:\n",r);
       for(k=0;k<=100;k++)
        strcpy(st[k],"0");
        strcpy(st[0],"http://www.lightoj.com/");i=j=1;
        while(scanf("%s",s))
        {
            if(strcmp(s,"VISIT")==0)
            {
                scanf("%s",st[i]);
                puts(st[i]);
                j++;
                for(k=i+1;k<j;k++)
                    strcpy(st[k],"0");
                i++;
            }
            else if(strcmp(s,"BACK")==0)
            {
                if(i-2<0)
                   printf("Ignored\n");
                else
                {
                    puts(st[i-2]);i--;
                }
            }
            else if(strcmp(s,"FORWARD")==0)
            {
                if(strlen(st[i])==1)
                    printf("Ignored\n");
                else
                {
                    puts(st[i]);
                    i++;

                }
            }
            else if(strcmp(s,"QUIT")==0)
              break;

        }
    }
    return 0;
}
