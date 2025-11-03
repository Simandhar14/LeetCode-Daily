class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();
        priority_queue<int, vector<int>, greater<int>> minTime;
        int minCost = 0;
        char sameColor = '#'; //to keep track of consecutive colors
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                if (colors[i] == colors[i - 1]) {
                    sameColor = colors[i - 1];
                    minTime.push(neededTime[i - 1]); //push the time of the same color

                } else {
                    if (sameColor != '#') {
                        minTime.push(neededTime[i - 1]); //push the last consecutive color
                        sameColor = '#';
                        while (!minTime.empty()) {
                            int time = minTime.top();
                            minTime.pop();
                            if (minTime.size() == 0)
                                continue;
                            minCost += time;
                        }
                    }
                }
            }
        }
        if (sameColor != '#' && colors[n - 1] == sameColor) { //check if the last index was the same color or not
            minTime.push(neededTime[n - 1]);
            sameColor = '#';
            while (!minTime.empty()) {
                int time = minTime.top();
                minTime.pop();
                if (minTime.size() == 0)
                    continue;
                minCost += time;
            }
        }
        return minCost;
    }
};
