class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int groups = 0;
        vector<int> array(colors.begin(), colors.end());
        array.insert(array.end(), colors.begin(), colors.begin()+k-1);
        int n = array.size();
        int j = 0;

        for (int i = 1; i < n; i++) {
            if (array[i] == array[i - 1]) {
                j = i;  
            }
            if (i - j + 1 == k) { 
                groups++;
                j++;  
            }
        } 
        return groups;
    }
};
