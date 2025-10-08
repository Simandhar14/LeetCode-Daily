class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        vector<int>pairs(n);
        sort(begin(potions),end(potions));
        for(int i=0;i<n;i++)
        {
            long long required=ceil(success/(1.0 * spells[i]));
            auto it=lower_bound(begin(potions),end(potions),required);
            if(it!=potions.end())
            {
                int pair=end(potions)-it;
                pairs[i]=pair;
            }
        }
        return pairs;
    }
};
