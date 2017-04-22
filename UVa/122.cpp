
//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;
int Br[1000000];


int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,u,v;
    char st[10000],ss[1000],stt[10000],*cp;
     while(sn("%s",&st)!=EOF)
     {
         b=0;

         memset(Br,-1,sizeof(Br));
         strcpy(stt,st);
         cp=strtok(st,",()");

         for(i=0;cp!=NULL;i++)
         {
             if(i==0)
             {
                  a=atoi(cp);

             }

             else
                strcpy(ss,cp);
             cp=strtok(NULL,",()");
         }
         for(i=0,j=1;i<strlen(ss)&&strlen(stt)>2;i++)
         {
             if(ss[i]=='L')
                j=2*j;
             else
                j=2*j+1;
         }
         if(Br[j-1]!=-1)
                b=1;
         Br[j-1]=a;

         while(scanf("%s",st)!=EOF)
         {
             if(strlen(st)==2)break;

             strcpy(stt,st);
              cp=strtok(st,",()");

             for(i=0;cp!=NULL;i++)
             {
                 if(i==0)
             {
                  a=atoi(cp);
             }
                 else
                    strcpy(ss,cp);
                 cp=strtok(NULL,",()");
             }
             for(i=0,j=1;i<strlen(ss)&&strlen(stt)>2;i++)
             {
                 if(ss[i]=='L')
                    j=2*j;
                 else
                    j=2*j+1;
             }
             if(Br[j-1]!=-1)
                b=1;
             Br[j-1]=a;ss[0]='\0';
         }
         for(i=1;i<=20000;i++)
         {
             j=i+1;
             if(Br[i]!=-1&&Br[(j/2)-1]==-1)
             {
                 b=1;break;
             }
         }
          if(b==0)
          {
              for(i=0;i<=20000;i++)
                {
                   if(Br[i]!=-1)
                   {
                       if(i!=0)
                     pf(" ");
                      pf("%d",Br[i]);
                   }
                }
          }
          else
          {
              pf("not complete");
          }
            pf("\n");

     }
    return 0;
}


