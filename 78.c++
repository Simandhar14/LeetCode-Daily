class Solution {
public:
void solve( vector<vector<int>>&result,vector<int>&nums,int i,vector<int>&temp)
{
    if(i==nums.size()) return;
    temp.push_back(nums[i]);
    result.push_back(temp);
    solve(result,nums,i+1,temp);
    temp.pop_back();
    solve(result,nums,i+1,temp);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>temp;
        solve(result,nums,0,temp);
        result.push_back({});
        return result;
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