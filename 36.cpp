class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            unordered_set<char> st;
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.')
                    continue;
                if (st.find(board[i][j]) != st.end()) {
                    
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            unordered_set<char> st;
            for (int j = 0; j < m; j++) {
                if (board[j][i] == '.')
                    continue;
                if (st.find(board[j][i]) != st.end()) {
                    
                    return false;
                }
                st.insert(board[j][i]);
            }
        }
        for (int i = 0; i < m; i += 3) {
            for (int j = 0; j < n; j += 3) {
                 unordered_set<char> st;
                for (int i_ = i; i_ < i + 3; i_++) {
                    for (int j_ = j; j_ < j + 3; j_++) {
                        if (board[i_][j_] == '.')
                            continue;
                        if (st.find(board[i_][j_]) != st.end()) {
                            
                            return false;
                        }
                        st.insert(board[i_][j_]);
                    }
                }
            }
        }
        return true;
    }
};
