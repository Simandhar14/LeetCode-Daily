//using counting sort
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        vector<int> boxes(51, 0);
        for (int& box : capacity)
            boxes[box]++;
        int requiredBoxes = 0;
        int totalApples = accumulate(begin(apple), end(apple), 0);
        int i=50;
        while(totalApples>0 && i>=0) {
            if (boxes[i] == 0)
                continue;
            int boxesAvailable = min(boxes[i], (totalApples+i-1) / i);
            requiredBoxes += boxesAvailable;
            totalApples -= (i * boxesAvailable);
            i--;
        }
        return requiredBoxes;
    }
};
