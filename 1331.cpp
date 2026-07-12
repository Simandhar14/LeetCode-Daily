//cpp
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> mp;
        vector<int> sortedArr = arr;
        sort(begin(sortedArr), end(sortedArr));
        int rank = 1;
        for (int& num : sortedArr) {
            if (!mp.count(num)) {
                mp[num] = rank;
                rank++;
            }
        }
        for (int& num : arr) {
            int rank = mp[num];
            num = rank;
        }
        return arr;
    }
};
