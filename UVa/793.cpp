#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int P[100000];
char st[100];

int parent(int u)
{
    if(P[u]==u)
        return u;
    return P[u]=parent(P[u]);
}

int main()
{
    int r,t, a,b,x,y,u,v,c,n,m,i,j,k;
    char *cp,ch[5];
    scanf("%d\n",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d",&n);getchar();
        for(i=0;i<=n;i++)
            P[i]=i;
            x=0;y=0;
        while(gets(st)&&st[0])
        {
            j=0;
            cp=strtok(st," ");
            while(cp!=NULL)
            {
                if(j==0)
                 strcpy(ch,cp);
                if(j==1)
                    a=atoi(cp);
                if(j==2)
                    b=atoi(cp);
                cp=strtok(NULL," ");
                j++;
            }
           if(ch[0]=='c')
           {
               u=parent(a);
               v=parent(b);
               if(u!=v)
               {
                   if(u>v)
                    P[u]=v;
                   else
                    P[v]=u;
               }

           }
           else if(ch[0]=='p')
           {
               u=parent(a);
               v=parent(b);
               if(u==v)
                x++;
               else
                y++;
           }
        }
        for(i=1;i<=n;i++)
            printf(" %d",P[i]);
        printf("\n%d,%d\n",x,y);
    }
    return 0;
}
