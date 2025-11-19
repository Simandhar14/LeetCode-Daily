class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(begin(nums),end(nums));
        while(find(begin(nums),end(nums),original)!=end(nums)) original*=2;
        return original;
    }
};

//using bitset 
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bitset<1001> seen;
        for(int &num:nums) seen[num]=1;
        int x=original;
        while(x<=1000)
        {
            if(seen[x]) x*=2;
            else break;
        }
        return x;
    }
};
