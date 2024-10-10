class TrieNode:
    def __init__(self):
        self.endmark = False
        self.children = [None]*26

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word):
        curnode = self.root

        for ch in word:
            index = ord(ch) - ord("a")
            if not curnode.children[index]:
                curnode.children[index] = TrieNode()
            curnode = curnode.children[index]
        curnode.endmark = True
