#include<bits/stdc++.h>
using namespace std;

bool pre;

struct TRIE {
    bool endmark;
    TRIE *next[10];

    TRIE() {
        endmark=false;
        for(int i=0; i<=9; i++) next[i]=NULL;
    }

} *root;

void insert_(string str, TRIE *curr) {
    int cnt = 0;
    int len = str.size();

    for(int i=0; i<len; i++) {
        int id = str[i] - '0';
        if(curr->next[id]==NULL) {
            curr->next[id] = new TRIE();
        } else cnt++;

        if(curr->endmark) pre = true;
        curr = curr->next[id];
    }

    if(cnt==len) pre = true;
    curr->endmark = true;
}

void delete_(TRIE *root)  {

    for(int i=0; i<=9; i++) {
        if(root->next[i]) {
            delete_(root->next[i]);
        }
    }

    delete root;
}

int main() {
    root = new TRIE();
    pre = false; // determines suffix presence
    string s;
    int queries;

    cin>>queries;

    for(int i=1; i<=queries; i++) {
        cin>>s;
        insert_(s, root);
    }

    delete_(root); // clear memory, else will result in MLE

    return 0;
}

