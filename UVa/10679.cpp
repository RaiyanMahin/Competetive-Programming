//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include <iostream>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf
#define pb push_back
#define mp make_pair


typedef long long int ll;
using namespace std;
const int t_char=60;
struct Node{
int cnt,nxt[t_char],back_pt;
bool vis;
vector<int>out;
}trie[1000005];
int Pt,root=0;
char tem[10000];
void clr(int u)
{
    memset(trie[u].nxt,-1,sizeof(trie[u].nxt));
    trie[u].cnt=0;
    trie[u].back_pt=0;
    trie[u].vis=0;
    trie[u].out.clear();
}
void add_str()
{
    int l=strlen(tem),i,j,k,cur=root;
    for(i=0;i<l;i++)
    {
         j=tem[i]-'A';
        if(trie[cur].nxt[j]==-1)
        {
            trie[cur].nxt[j]=Pt;
            cur=Pt;
            clr(Pt);
            Pt++;
        }
        else cur=trie[cur].nxt[j];
    }
}
void build_Aho()
{
   int i,j,k,l,u,v,n,m;
   queue<int>Q;
   for(i=0;i<t_char;i++)
   {
       if(trie[root].nxt[i]!=-1)
       {
           u=trie[root].nxt[i];
           Q.push(u);
           trie[u].back_pt=root;
       }
       else
        trie[root].nxt[i]=root;
   }
   while(!Q.empty())
   {
       u=Q.front();Q.pop();
       for(i=0;i<t_char;i++)
       {
           if(trie[u].nxt[i]!=-1)
           {
               v=trie[u].nxt[i];
               m=trie[u].back_pt;
               while(trie[m].nxt[i]==-1)
               {
                   m=trie[m].back_pt;
               }
               trie[v].back_pt=m=trie[m].nxt[i];
               trie[m].out.pb(v);
               Q.push(v);
           }
       }
   }
}
char text[100005];
void aho_corasick()
{
    int l=strlen(text),i,j,k,cur=root;
    for(i=0;i<l;i++)
    {
        j=text[i]-'A';
        while(trie[cur].nxt[j]==-1)
            cur=trie[cur].back_pt;
        cur=trie[cur].nxt[j];
        trie[cur].cnt++;
    }
}
int dfs(int u)
{
    if(trie[u].vis) return trie[u].cnt;
    for(int i=0;i<trie[u].out.size();i++)
    {
        trie[u].cnt+=dfs(trie[u].out[i]);
    }
    trie[u].vis=true;
    return trie[u].cnt;
}
char query[1005][1005];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%s",&text);
        l=strlen(text);
        sn("%d",&n);
        clr(root);Pt=1;
        for(i=0;i<n;i++)
        {
            sn("%s",&query[i]);
            strcpy(tem,query[i]);
            add_str();
        }
        build_Aho();
        aho_corasick();
        for(i=0;i<n;i++)
        {
            int cur=root;
            m=strlen(query[i]);
            for(j=0;j<m;j++)
            {
                cur=trie[cur].nxt[query[i][j]-'A'];
            }
            //pf("found: %d times\n",dfs(cur));
            if(dfs(cur)>0)
                pf("y\n");
            else
                pf("n\n");
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

/*#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,l,m,n,q,t,r;
    char st[100009],*p,ch[1009];
    scanf("%d",&t);
    getchar();
    for(r=1;r<=t;r++)
    {
        gets(st);
        scanf("%d",&q);
        getchar();
        for(i=0;i<q;i++)
        {
            gets(ch);k=0;
            p=strstr(st,ch);
            if(p==NULL)
                printf("n\n");
            else
                printf("y\n");
        }
    }
    return 0;
}*/
