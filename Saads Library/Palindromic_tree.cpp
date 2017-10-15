#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 105000;
 
struct node {
    int next[26];
    int len;//length
    int sufflink;//proper palindromic suffix
    int num;//number
};
 
int len;
string s;
node tree[MAXN]; 
int num;            // node 1 - root with len -1, node 2 - root with len 0
int suff;           // max suffix palindrome
long long ans;
 
bool addLetter(int pos) {
    int cur = suff, curlen = 0;
    int let = s[pos] - 'a';
 //searching where to add this letter 
    while (true) {
        curlen = tree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])     
            break;  
        cur = tree[cur].sufflink;
    }
    //if already exist       
    if (tree[cur].next[let]) {  
        suff = tree[cur].next[let];
        tree[suff].num++;
        return false;
    }
 
    num++;
    suff = num;
    tree[num].len = tree[cur].len + 2;
    tree[cur].next[let] = num;
//if new letter 
    if (tree[num].len == 1) {
        tree[num].sufflink = 2;
        tree[num].num = 1;
        return true;
    }
 //finding suffix link
    while (true) {
        cur = tree[cur].sufflink;
        curlen = tree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]) {
            tree[num].sufflink = tree[cur].next[let];
            break;
        }       
    }           
 //num = number of time this pelindrom appeared 
    tree[num].num = 1;
 
    return true;
}
 
void initTree() {
    num = 2; suff = 2;
    tree[1].len = -1; tree[1].sufflink = 1;
    tree[2].len = 0; tree[2].sufflink = 1;
}
 
int main() 
{
	int t;
	cin>>t;
	cin>>s;
	len = s.size();
	initTree();
	int ans=0;
	for (int i = 0; i < len; i++)
	{
		addLetter(i);
		if(tree[suff].len>ans)ans=tree[suff].len;
	}
	cout<<ans<<endl;
    return 0;
}
