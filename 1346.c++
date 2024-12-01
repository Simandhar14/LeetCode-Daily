class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> st;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (st.find(2 * arr[i]) != st.end()){
                return true;
            }else{
                if(arr[i]%2==0)
                {
                    if(st.find(floor(arr[i]/2)) != st.end()) return true;
                }
            }
            st.insert(arr[i]);
        }
        return false;
    }
};