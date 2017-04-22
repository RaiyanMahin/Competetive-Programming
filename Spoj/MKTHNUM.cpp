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

const double PI=2.0*acos(0);

typedef long long int ll;
using namespace std;
struct T{
int a,b;
}ar[100005];

struct node{

int val,cr,cl;
node *L,*R;
}*save[100005];

int arr[100005],pos[100005];

bool cmp(T x,T y)
{
    return x.a<y.a;
}

void build(node* p ,int l,int r)
{
    if(l==r)
    {
        p->L=p->R=NULL;
        p->val=0;
        return;
    }

    int mid=(l+r)/2;

    p->L=new node();
    p->R=new node();
    p->val=0;
    p->cl=1;
    p->cr=1;

    build(p->L,l,mid);
    build(p->R,mid+1,r);
}

void update(node *p,node *q,int l,int r,int x)
{
    if(x<l||x>r)
        return;
    if(l==x&&r==x)
    {
        q->L=NULL;
        q->R=NULL;
        q->val=1;
        return ;
    }

    int mid=(l+r)/2;

    if(l<=x&&x<=mid)
    {
       q->L=new node();
       q->cl=1;
       q->cr=0;
       q->R=p->R;
       update(p->L,q->L,l,mid,x);
    }
    else
    {
       q->R=new node();
       q->cl=0;
       q->cr=1;
       q->L=p->L;
       update(p->R,q->R,mid+1,r,x);
    }

    q->val=q->L->val+q->R->val;
}

int query(node *p,node *q,int l,int r,int val)
{
    if(l==r)
        return l;
    int mid=(l+r)/2;

    if(val-(q->L->val-p->L->val)<=0)
    {
        return query(p->L,q->L,l,mid,val);
    }
    else
    {
       return query(p->R,q->R,mid+1,r,val-(q->L->val-p->L->val));
    }
}

void delete_node(node *p)
{
    if(p->cl==1&&p->L!=NULL)
     delete_node(p->L);

    if(p->cr==1&&p->R!=NULL)
     delete_node(p->R);

     delete(p);

     return;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d %d",&n,&m);

    for(i=0;i<n;i++)
    {
        sn("%d",&ar[i].a);
        ar[i].b=i;
        arr[i]=ar[i].a;
    }

    sort(ar,ar+n,cmp);

    for(i=0;i<n;i++)
    {
        pos[ar[i].b]=i;
    }

    node *root=new node();
    build(root,0,n-1);
    f=0;
    save[f]=root;f++;
    for(i=0;i<n;i++)
    {

        save[f++]=new node();
        update(save[f-2],save[f-1],0,n-1,pos[i]);
    }

    for(i=0;i<m;i++)
    {
        sn("%d %d %d",&a,&b,&c);a--;b--;
        u=query(save[a],save[b+1],0,n-1,c);
        pf("%d\n",ar[u].a);
    }

    for(i=0;i<f;i++)
        delete_node(save[i]);

    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
