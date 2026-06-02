//cpp
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int land = landStartTime.size();
        int water = waterStartTime.size();
        int result = INT_MAX;
        for (int i = 0; i < land; i++) {
            int start = landStartTime[i] + landDuration[i];
            for (int j = 0; j < water; j++) {
                if (waterStartTime[j] <= start) {
                    result = min(result, start + waterDuration[j]);
                } else {
                    result = min(result,
                                 waterDuration[j] + waterStartTime[j]);
                }
            }
        }
        for (int i = 0; i < water; i++) {
            int start = waterStartTime[i] + waterDuration[i];
            for (int j = 0; j < land; j++) {
                if (landStartTime[j] <= start) {
                    result = min(result, start + landDuration[j]);
                } else {
                    result =
                        min(result, landDuration[j] + landStartTime[j]);
                }
            }
        }
        return result;
    }
};
