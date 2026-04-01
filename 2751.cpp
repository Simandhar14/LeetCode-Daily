//cpp
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();

        vector<int> index(n);
        for (int i = 0; i < n; i++) index[i] = i;

        sort(index.begin(), index.end(),
             [&](int i, int j) { return positions[i] < positions[j]; });

        vector<int> st;

        for (int idx : index) {
            if (st.empty() || !(directions[idx] == 'L' && directions[st.back()] == 'R')) {
                st.push_back(idx);
            } else {
                while (!st.empty() && directions[st.back()] == 'R') {
                    int top = st.back();
                    st.pop_back();

                    if (healths[top] > healths[idx]) {
                        healths[top]--;
                        healths[idx] = 0;
                        st.push_back(top);
                        break;
                    } else if (healths[idx] > healths[top]) {
                        healths[idx]--;
                        healths[top] = 0;
                    } else {
                        healths[idx] = 0;
                        healths[top] = 0;
                        break;
                    }
                }
                if (healths[idx] > 0) st.push_back(idx);
            }
        }

        vector<int> result;
        for (int h : healths) {
            if (h > 0) result.push_back(h);
        }

        return result;
    }
};
