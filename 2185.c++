class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(string wrd:words)
        {
           int n=pref.length();
           int len=wrd.length();
           if(n>len) continue;
           int i=0;
           while(i<n && wrd[i]==pref[i])
           {
            i++;
           }
           if(i==n) count++;
        }
        return count;
    }
};


//Trie approach

class Trie {
public:
 struct trienode {
        trienode* children[26];
        bool endofword;
    };
     trienode* getnode() {
        trienode* root = new trienode();
        for (int i = 0; i < 26; i++) {
            root->children[i] = nullptr;
        }
        root->endofword = false;
        return root;
    }
    void insert(string wrd) {
        trienode* crawler = root;
        for (char ch : wrd) {
            int idx = ch - 'a';
            if (crawler->children[idx] == nullptr) {
                crawler->children[idx] = getnode();
            }
            crawler = crawler->children[idx];
        }
        crawler->endofword = true;
    }
    bool check(string wrd) {
        trienode* crawler = root;
        for (char ch : wrd) {
            int idx = ch - 'a';
            if (crawler->children[idx] == nullptr) {
                return false;
            }
            crawler = crawler->children[idx];
        }
        return true;
    }
    trienode* root;
    Trie() { root = getnode(); }
   
   
};
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (string wrd : words) {
            Trie obj;
            obj.insert(wrd);
            if (obj.check(pref))
                count++;
        }
        return count;
    }
};