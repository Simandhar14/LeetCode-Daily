class Solution {
public:
    void solve(unordered_set<string>& st, string& str, int count, int n,
               vector<bool>& used, string tiles) {
        if (count == n)
            return;
        for (int j = 0; j < n; j++) {
            if (!used[j]) {
                string temp = str + tiles[j];
                if (st.find(temp) == st.end())
                    st.insert(temp);
                used[j] = true;
                solve(st, temp, count+1, n, used, tiles);
                used[j] = false;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.length();
        unordered_set<string> st;
        vector<bool> used(n, false);
        string str = "";
        solve(st, str, 0, n, used, tiles);
        return st.size();
    }
};

//Using vector of constant size 26 

class Solution {
public:
int count=0;
void solve(vector<int>&freq,string &temp)
{
    count++;
    for(int i=0;i<26;i++)
    {
        if(freq[i]==0) continue;
        temp.push_back(i+'A');
        freq[i]--;
        solve(freq,temp);
        temp.pop_back();
        freq[i]++;
    }
}
    int numTilePossibilities(string tiles) {
        vector<int>freq(26,0);
        for(char ch:tiles)
        {
            freq[ch-'A']++;
        }
        unordered_set<string>;
        string temp="";
        solve(freq,temp);
        return count-1;
    }
};