#include<stdio.h>
#define sz 100005
int ar[sz],Id[4*sz],tree[4*sz];

void build_tree(int p,int l,int r)
{
    if(l==r)
    {
        tree[p]=ar[l];
        Id[l]=p;
        return;
    }
    int m=(l+r)/2;
    build_tree(2*p,l,m);
    build_tree(2*p+1,m+1,r);
    tree[p]=tree[2*p]+tree[2*p+1];
}

void update(int p,int v)
{
    if(p>0)
    {
        tree[p]+=v;
        update(p/2,v);
    }
}

int query(int p,int l,int r,int x,int y)
{
    if(l>y||r<x)
        return 0;
    if(l>=x&&r<=y)
        return tree[p];
    int m=(l+r)/2;
    return query(2*p,l,m,x,y)+query(2*p+1,m+1,r,x,y);
}
int main()
{
    int a,b,n,m,r,t,q,i;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %d",&n,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ar[i]);

        }
         build_tree(1,1,n);
        printf("Case %d:\n",r);
        while(q--)
        {
            scanf("%d",&m);
            if(m==1)
            {
                scanf("%d",&a);
                printf("%d\n",tree[Id[a+1]]);
                update(Id[a+1],-tree[Id[a+1]]);
            }
            else if(m==2)
            {
                scanf("%d %d",&a,&b);
                update(Id[a+1],b);
            }
            else if(m==3)
            {
                scanf("%d %d",&a,&b);
                printf("%d\n",query(1,1,n,a+1,b+1));
            }
        }
    }
    return 0;
}
/*
#include<stdio.h>
#include<string.h>
#define sz 100005
struct T{
int sum,lazy;
}tree[3*sz];
int ar[sz],Id[3*sz];

void build_tree(int p,int l,int r)
{
    if(l==r)
    {
        tree[p].sum=ar[l];
        Id[l]=p;
        return ;
    }

    int m;
    m=(l+r)/2;
    build_tree(2*p,l,m);
    build_tree(2*p+1,m+1,r);
    tree[p].sum=tree[2*p].sum+tree[2*p+1].sum;
}

void  update(int p,int l,int r,int x,int y,int v)
{
    if(l>y||r<x)
        return ;
    if(l>=x&&r<=y)
    {
        tree[p].sum+=(r-l+1)*v;
        tree[p].lazy+=v;
        return;
    }
    int m=(l+r)/2;
    update(2*p,l,m,x,y,v);
    update(2*p+1,m+1,r,x,y,v);
    tree[p].sum=tree[2*p].sum+tree[2*p+1].sum+(r-l+1)*tree[p].lazy;
}

int query(int p,int l,int r,int x,int y,int cry=0)
{
    if(l>y||r<x)
        return 0;
    if(l>=x&&r<=y)
        return tree[p].sum+cry*(r-l+1);
     int m=(l+r)/2;
    return query(2*p,l,m,x,y,cry+tree[p].lazy)+query(2*p+1,m+1,r,x,y,cry+tree[p].lazy);
}
int main()
{
    int a,b,n,m,r,t,q,i;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        memset(tree,0,sizeof(tree));
        scanf("%d %d",&n,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ar[i]);

        }
        build_tree(1,1,n);
        printf("Case %d:\n",r);
        while(q--)
        {
            scanf("%d",&m);
            if(m==1)
            {
                scanf("%d",&a);
                b=tree[Id[a+1]].sum;
                printf("%d\n",b);

                update(1,1,n,a+1,a+1,-b);
            }
            else if(m==2)
            {
                scanf("%d %d",&a,&b);
                update(1,1,n,a+1,a+1,b);
            }
            else if(m==3)
            {
                scanf("%d %d",&a,&b);
                printf("%d\n",query(1,1,n,a+1,b+1));
            }
        }
    }
    return 0;
}

*/
