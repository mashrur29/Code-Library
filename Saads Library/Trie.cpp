////////////////////////////////////////////////////////////////////////
struct node
{
    int endmark;
    node *next[52];
    node()
    {
        endmark=0;
        for(int i=0; i<52; i++) next[i]=NULL;
    }
}*root;

void insert(char *str,int len)
{
    node *curr=root;
    for(int i=0; i<len; i++)
    {
        int id=gid(str[i]);
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
    }
    curr->endmark++;
}
int src(char *str,int len )
{
    node *curr=root;
    for(int i=0; i<len; i++)
    {
        int id=gid(str[i]);
        if(curr->next[id]==NULL) return 0;
        curr=curr->next[id];
    }
    return curr->endmark;
}
void del(node *cur)
{
    for(int i=0; i<52; i++)
        if(cur->next[i])
            del(cur->next[i]) ;

    delete(cur) ;
}
char temp[10011];
char *pch;
int main()
{
    root=new node();
    getchar();
    while(q--)
    {
        gets(temp);
        pch = strtok (temp," ");
        while (pch != NULL)
        {
            pch = strtok(NULL," ");
        }
    }
    del(root);
}
////////////////////////////////////////////////////////////////////////
struct trie{
  struct node{
    int c;
    int a[MN];
  };

  node tree[MS];
  void clear(){
    tree[nodes].c = 0;
    memset(tree[nodes].a, -1, sizeof tree[nodes].a);
    nodes++;
  }

  int nodes;

  void init(){
    nodes = 0;
    clear();
  }

  int add(const string &s, bool query = 0){
    int cur_node = 0;
    for(int i = 0; i < s.size(); ++i){
      int id = gid(s[i]);
      if(tree[cur_node].a[id] == -1){
        if(query) return 0;
        tree[cur_node].a[id] = nodes;
        clear();
      }
      cur_node = tree[cur_node].a[id];
    }
    if(!query) tree[cur_node].c++;
    return tree[cur_node].c;
  }

};
////////////////////////////////////////////////////////////////////////
