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

typedef long long int ll;
using namespace std;
struct T{
int nxt[85],c;
}tree[90000];
char ss[104],st[100005],*ch;
ll vis[175];
int main()
{
    ll i,j,root,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
    sn("%lld",&t);
    while(t--)
    {
        sn("%lld",&n);
        memset(vis,0,sizeof(vis));
        f=1;
        for(i=0;i<85;i++)
        {
            tree[0].nxt[i]=-1;
            tree[0].c=0;
        }
        for(u=0;u<n;u++)
        {
            sn("%s",&ss);
            l=strlen(ss);
            for(i=1;i<l-1;i++)
            {
                vis[ss[i]]++;
            }
            root=0;
            a=ss[0]-'A';
            if(tree[root].nxt[a]==-1)
              {
                tree[root].nxt[a]=f++;
                for(j=0;j<85;j++)
                {
                    tree[f-1].nxt[j]=-1;
                    tree[f-1].c=0;
                }
                root=tree[root].nxt[a];
               // pf("%lld\n",root);
              }
            else
                root=tree[root].nxt[a];

            for(i='A';i<='z';i++)
            {
                while(vis[i]>0)
                {
                    a=i-'A';
                    if(tree[root].nxt[a]==-1)
                    {
                        tree[root].nxt[a]=f++;
                        for(j=0;j<85;j++)
                        {
                            tree[f-1].nxt[j]=-1;
                            tree[f-1].c=0;
                        }
                        root=tree[root].nxt[a];
                    }
                    else
                        root=tree[root].nxt[a];
                        vis[i]--;
                }
                 vis[i]=0;
            }
            if(l==1)
            {
                tree[tree[0].nxt[ss[0]-'A']].c++;
            }
            else
            {
                a=ss[l-1]-'A';
                if(tree[root].nxt[a]==-1)
                    {
                        tree[root].nxt[a]=f++;
                        for(j=0;j<85;j++)
                        {
                            tree[f-1].nxt[j]=-1;
                            tree[f-1].c=0;
                        }
                        root=tree[root].nxt[a];
                    }
                    else
                        root=tree[root].nxt[a];
                tree[root].c++;
            }
        }

        sn("%lld",&m);
        pf("Case %lld:\n",cs++);
         getchar();
        while(m--)
        {

            gets(st);
            ch=strtok(st," ");
            ll ans=1;
            while(ch!=NULL)
            {
                l=strlen(ch);

                 if(l>1)
                 {
                     for(i=1;i<l-1;i++)
                        vis[ch[i]]++;
                      a=ch[0]-'A';
                      root=tree[0].nxt[a];
                     for(i='A';i<='z';i++)
                     {
                          a=i-'A';
                         if(root!=-1)
                         while(vis[i]>0)
                         {
                             if(root==-1)break;
                              root=tree[root].nxt[a];
                             vis[i]--;
                         }
                         vis[i]=0;
                     }
                     if(root!=-1)
                        root=tree[root].nxt[ch[l-1]-'A'];
                     if(root!=-1)
                        ans=ans*tree[root].c;
                     else
                        ans=0;
                 }
                 else
                 {
                     root=tree[0].nxt[ch[0]-'A'];
                      if(root!=-1)
                        ans=ans*tree[root].c;
                     else
                        ans=0;
                 }
                ch=strtok(NULL," ");
            }
            pf("%lld\n",ans);
        }
    }
    return 0;
}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

