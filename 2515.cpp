//cpp
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;
        int i = startIndex;
        int steps = 0;
        while ((i + 1) % n != startIndex) {
            if (words[i] == target) {
                ans = min(ans, steps);
                break;
            }
            steps++;
            i = (i + 1 + n) % n;
        }
        i = startIndex;
        steps = 0;
        while ((i - 1 + n) % n != startIndex) {
            if (words[i] == target) {
                ans = min(ans, steps);
                break;
            }
            steps++;
            i = (i - 1 + n) % n;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
