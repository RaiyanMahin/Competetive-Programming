//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;

bool dis[9][8][8][8][8][8][8][8];
int vis[10],pr[16],rr[9],re[9];
queue<int>Q;
int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v,ans;
    memset(pr,0,sizeof(pr));pr[3]=pr[5]=pr[7]=pr[11]=pr[13]=1;
    //freopen("Output.txt","w",stdout);
    //freopen("Input.txt","r",stdin);
     scanf("%d",&t);
     for(r=1;r<=t;r++)
     {
         n=0;memset(vis,0,sizeof(vis));
         for(i=0;i<8;i++){
         scanf("%d",&a);
         if(a<0)
         {
             a*=-1;vis[a]=1;
         }
          n=n*10+a;
         }
         m=n;j=7;
         while(m!=0)
         {
             rr[j]=m%10;m/=10;j--;
         }
         ans=900000000;
         memset(dis,0,sizeof(dis));
         dis[rr[0]][rr[1]][rr[2]][rr[3]][rr[4]][rr[5]][rr[6]][rr[7]]=1;
         Q.push(n);Q.push(0);h=0;
         if(n==12345678&&0<ans)
                ans=0;
        else
         while(!Q.empty())
         {
             u=m=Q.front();Q.pop();
             d=Q.front();Q.pop();
             a=7;
             while(m!=0)
             {
                 rr[a]=m%10;m/=10;a--;
             }
            for(i=1;i<=8;i++)
            {
                for(j=0,k=0;j<8;j++)
                {
                    if(vis[i]+vis[rr[j]]==1&&pr[i+rr[j]]==1)
                    {
                        re[k]=i;
                        for(b=k+1,c=j;c<8;c++)
                        {
                            if(rr[c]!=i)
                            re[b++]=rr[c];
                        }
                    if(dis[re[0]][re[1]][re[2]][re[3]][re[4]][re[5]][re[6]][re[7]]==0)
                        {

                            n=0;
                            for(f=0;f<8;f++)
                                {
                                    n=n*10+re[f];
                                }
                             dis[re[0]][re[1]][re[2]][re[3]][re[4]][re[5]][re[6]][re[7]]=1;
                          Q.push(n);Q.push(d+1);
                         if(n==12345678&&d+1<ans)
                            ans=d+1;
                        }
                         re[k]=rr[j];re[k+1]=i;
                        for(b=k+2,c=j+1;c<8;c++)
                        {
                             if(rr[c]!=i)
                            re[b++]=rr[c];
                        }
                   if(dis[re[0]][re[1]][re[2]][re[3]][re[4]][re[5]][re[6]][re[7]]==0)
                        {
                            n=0;
                            for(f=0;f<8;f++)
                                {
                                    n=n*10+re[f];
                                }
                             dis[re[0]][re[1]][re[2]][re[3]][re[4]][re[5]][re[6]][re[7]]=1;
                          Q.push(n);Q.push(d+1);
                          if(n==12345678&&d+1<ans)
                            ans=d+1;
                        }
                    }
                    if(i!=rr[j])
                     re[k++]=rr[j];
                }
            }
         }
         printf("Case %d: ",r);
         if(dis[1][2][3][4][5][6][7][8]==0)
            printf("-1\n");
         else
            printf("%d\n",ans);
     }
    return 0;
}
