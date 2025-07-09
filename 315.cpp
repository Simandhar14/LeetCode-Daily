#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    pbds;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        pbds st;
        vector<int> ans;
        int n = nums.size();

        for (int i = n - 1; i >= 0; i--) {
            int count = st.order_of_key({nums[i], i});
            ans.push_back(count);
            st.insert({nums[i], i}); 
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
