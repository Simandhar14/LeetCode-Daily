class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> colors(1000, 0);
        int n = answers.size();
        for (int i = 0; i < n; i++) {
            colors[answers[i]]++;
        }
        int result = 0;
        for (int i = 0; i < 1000; i++) {
            if (colors[i] > 0) {
                int count = colors[i];
                double groupsize = (i + 1)/1.0;
                result += ceil(count / groupsize) * groupsize;
            }
        }
        return result;
    }
};
