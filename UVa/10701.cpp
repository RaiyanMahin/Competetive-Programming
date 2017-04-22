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

int Br[100000];
map<char,int>Ci;
map<int,char>Ic;
char st[100],ch[100];

void Postorder(int n)
{
    if(Br[n-1]>0)
    {
        Postorder(2*n);
        Postorder(2*n+1);
        printf("%c",Ic[Br[n-1]]);
    }
}

void Binarytree(int n,int k,int m)
{
    if(k>=m)
     return;
    if(Br[n-1]==0)
        Br[n-1]=Ci[st[k]];
    else
    {
        if(Ci[st[k]]<Br[n-1])
        {
            Binarytree(2*n,k,m);
        }
        else
        {
            Binarytree(2*n+1,k,m);
        }
        if(n==1)
        Binarytree(1,k+1,m);
    }

}
int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h;

    sn("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %s %s",&n,&st,&ch);
        memset(Br,0,sizeof(Br));
        for(i=0;i<strlen(ch);i++)
        {
            Ci[ch[i]]=i+1;
            Ic[i+1]=ch[i];
        }
        Br[0]=Ci[st[0]];
        Binarytree(1,1,strlen(st));

        Postorder(1);
        pf("\n");

        Ic.clear();
        Ci.clear();
    }
    return 0;
}


