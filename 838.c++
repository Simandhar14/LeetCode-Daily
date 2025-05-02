class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int> left(n, -1);
        vector<int> right(n, -1);
        for (int i = 1; i < n; i++) {
            left[i] = dominoes[i - 1] != '.' ? i - 1 : left[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            right[i] = dominoes[i + 1] != '.' ? i + 1 : right[i + 1];
        }
        string str = dominoes;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] != '.')
                continue;
             int leftd = (left[i] != -1) ? i - left[i] : INT_MAX;
            int rightd = (right[i] != -1) ? right[i] - i : INT_MAX;
            char leftaction = (left[i] != -1) ? dominoes[left[i]] : '.';
            char rightaction = (right[i] != -1) ? dominoes[right[i]] : '.';
            if (leftd == rightd) {
                if ((leftaction == 'R' && rightaction == 'L') ||
                    (leftaction == 'L' && rightaction == 'R') ||
                    (leftaction == 'L' && rightaction == '.') ||
                    (rightaction == 'R' && leftaction == '.'))
                    str[i] = '.';
                else if (leftaction == 'R' && rightaction == 'R') {
                    str[i] = 'R';

                } else if (leftaction == 'L' && rightaction == 'L') {
                    str[i] = 'L';

                } 
            } else {
                if (leftaction == rightaction && leftaction != '.' &&
                    rightaction != '.') {
                    str[i] = rightaction;

                } else
                    str[i] = (leftd < rightd)
                                 ? (leftaction == 'R' ? leftaction : '.')
                                 : (rightaction == 'L' ? rightaction : '.');
            }
        }
        return str;
    }
};
