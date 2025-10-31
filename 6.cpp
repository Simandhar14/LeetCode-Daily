class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        pair<int, int> down = {1, 0};
        pair<int, int> up = {-1, 1};
        string result = "";
        bool downdir = true;
        vector<vector<char>> arr(numRows, vector<char>(s.length(), '/'));
        int i = -1, j = 0;
        for (char& ch : s) {
             if (downdir) {
                i += down.first;
                j += down.second;
            } else {
                i += up.first;
                j += up.second;
            }
            arr[i][j] = ch;   
            if(downdir && i==numRows-1|| !downdir && i==0)
            {
                downdir=!downdir;
            }
        }
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<s.length();j++)
            {
                if(arr[i][j]!='/') result.push_back(arr[i][j]);
            }
        }
        return result;
    }
};
