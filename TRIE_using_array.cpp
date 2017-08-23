#include<bits/stdc++.h>
using namespace std;

const int maxi = 133798;

struct TRIE {
    int next[52], endmark;
} root[maxi];

int curr;

int toINT(char ch) {
    if(ch>='a' && ch<='z') return ch - 'a';
    else return ch - 'A' + 26;
}

void insert_(char str[]) {
    int len = strlen(str);
    int pos = 0;

    for(int i=0; i<len; i++) {
        int id = toINT(str[i]);
        if(root[pos].next[id]==-1) {
            root[pos].next[id] = ++curr;
            memset(root[curr].next, -1, sizeof(root[curr].next));
            root[curr].endmark = 0;
        }

        pos = root[pos].next[id];
    }

    root[pos].endmark++;
}

int main() {
    curr = 0;
    memset(root[curr].next, -1, sizeof(root[curr].next));
    root[curr].endmark = 0;
}

