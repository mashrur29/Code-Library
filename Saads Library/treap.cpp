#include<bits/stdc++.h>
using namespace std;
#define loop(i,L,R) for(int i=(L);i<=(R);i++)
#define rept(i,L,R) for(int i=(L);i<(R);i++)
#define isc(n) scanf("%d",&n)
#define llsc(n) scanf("%lld",&n)
#define dsc(n) scanf("%lf",&n)
#define pf(n) printf("%d\n",n)
#define pfcs(cs) printf("Case %d:\n",cs);
#define enl cout<<endl
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define xx first
#define yy second
typedef long long ll;
typedef pair<int,int>PI;
typedef pair<pair<int,int>,int>PII;

typedef struct node
{
    int val,prior,sz;
    struct node *l,*r;
} node;

typedef node* pnode;

inline int siz(pnode t){return t?t->sz:0;}

inline void upd_sz(pnode t){if(t) t->sz = siz(t->l)+1+siz(t->r);}

void split(pnode t,pnode &l,pnode &r,int key)
{
    if(!t) l=r=NULL;
    else if(t->val<=key) split(t->r,t->r,r,key),l=t; //elem=key comes in l
    else split(t->l,l,t->l,key),r=t;
    upd_sz(t);
}
void merge(pnode &t,pnode l,pnode r)
{
    if(!l || !r) t=l?l:r;
    else if(l->prior > r->prior)merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l),t=r;
    upd_sz(t);
}
void insert(pnode &t,pnode it){
    if(!t) t=it;
    else if(it->prior>t->prior) split(t,it->l,it->r,it->val),t=it;
    else insert(t->val<=it->val?t->r:t->l,it);
    upd_sz(t);
}

void erase(pnode &t,int key)
{
    if(!t)return;
    else if(t->val==key)
    {
        pnode temp=t;
        merge(t,t->l,t->r);
        free(temp);
    }
    else erase(t->val<key?t->r:t->l,key);
    upd_sz(t);
}
pnode init(int val)
{
    pnode ret = (pnode)malloc(sizeof(node));
    ret->val=val;
    ret->sz=1;
    ret->prior=rand();
    ret->l=ret->r=NULL;
    return ret;
}
int query1(pnode t,int key)
{
    if(!t)return 0;
    if(t->val==key)return siz(t->l);
    else if(t->val>key)return query1(t->l,key);
    else return siz(t->l)+1+query1(t->r,key);
}
int query2(pnode t,int key)
{
    if(siz(t->l)+1==key)return t->val;
    else if(siz(t->l)+1>key)return query2(t->l,key);
    else return query2(t->r,key-siz(t->l)-1);
}
void inorder(pnode t)
{
    if(!t)return;
    inorder(t->l);
    inorder(t->r);
}
bool src(pnode t,int key)
{
    if(!t)return false;
    if(t->val==key)return true;
    else if(t->val>key)return src(t->l,key);
    else return src(t->r,key);
}
int main()
{
    //freopen("in.txt","r",stdin);


    pnode root=NULL;
    int q;
    isc(q);
    while(q--)
    {
        char a;
        int b;
        getchar();
        scanf("%c %d",&a,&b);
        if(a=='I')
        {
            if(!src(root,b))insert(root,init(b));
        }
        else if(a=='D')
        {
            erase(root,b);
        }
        else if(a=='C')
        {
            printf("%d\n",query1(root,b));
        }
        else
        {
            if(!root || root->sz<b)printf("invalid\n");
            else printf("%d\n",query2(root,b));
        }

    }
    return 0;
}

typedef struct node{
    int prior,size;
    int val;//value stored in the array
    int sum;//whatever info you want to maintain in segtree for each node
    int lazy;//whatever lazy update you want to do
    struct node *l,*r;
}node;
typedef node* pnode;
int sz(pnode t){
    return t?t->size:0;
}
void upd_sz(pnode t){
    if(t)t->size=sz(t->l)+1+sz(t->r);
}
void lazy(pnode t){
    if(!t || !t->lazy)return;
    t->val+=t->lazy;//operation of lazy
    t->sum+=t->lazy*sz(t);
    if(t->l)t->l->lazy+=t->lazy;//propagate lazy
    if(t->r)t->r->lazy+=t->lazy;
    t->lazy=0;
}
void reset(pnode t){
    if(t)t->sum = t->val;//no need to reset lazy coz when we call this lazy would itself be propagated
}
void combine(pnode& t,pnode l,pnode r){//combining two ranges of segtree
    if(!l || !r)return void(t = l?l:r);
    t->sum = l->sum + r->sum;
}
void operation(pnode t){//operation of segtree
    if(!t)return;
    reset(t);//reset the value of current node assuming it now represents a single element of the array
    lazy(t->l);lazy(t->r);//imp:propagate lazy before combining t->l,t->r;
    combine(t,t->l,t);
    combine(t,t,t->r);
}
void split(pnode t,pnode &l,pnode &r,int pos,int add=0){
    if(!t)return void(l=r=NULL);
    lazy(t);
    int curr_pos = add + sz(t->l);
    if(curr_pos<=pos)//element at pos goes to left subtree(l)
        split(t->r,t->r,r,pos,curr_pos+1),l=t;
    else 
        split(t->l,l,t->l,pos,add),r=t;
    upd_sz(t);
    operation(t);
}
void merge(pnode &t,pnode l,pnode r){ //l->leftarray,r->rightarray,t->resulting array
    lazy(l);lazy(r);
    if(!l || !r) t = l?l:r;
    else if(l->prior>r->prior)merge(l->r,l->r,r),t=l;
    else    merge(r->l,l,r->l),t=r;
    upd_sz(t);
    operation(t);
}
pnode init(int val){
    pnode ret = (pnode)malloc(sizeof(node));
    ret->prior=rand();ret->size=1;
    ret->val=val;
    ret->sum=val;ret->lazy=0;
    return ret;
}
int range_query(pnode t,int l,int r){//[l,r]
    pnode L,mid,R;
    split(t,L,mid,l-1);
    split(mid,t,R,r-l);//note: r-l!!
    int ans = t->sum;
    merge(mid,L,t);
    merge(t,mid,R);
    return ans;
}
void range_update(pnode t,int l,int r,int val){//[l,r]
    pnode L,mid,R;
    split(t,L,mid,l-1);
    split(mid,t,R,r-l);//note: r-l!!
    t->lazy+=val; //lazy_update
    merge(mid,L,t);
    merge(t,mid,R);
}

