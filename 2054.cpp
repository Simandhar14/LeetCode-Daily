//brute force 
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(begin(events),end(events));
        int result=0;
        for(int i=0;i<n;i++)
        {
            result=max(result,events[i][2]);
            for(int j=i+1;j<n;j++)
            {
                if(events[i][1]<events[j][0])
                {
                    result=max(result,events[i][2]+events[j][2]);
                }
            }
        }
        return result;
    }
};

//using suffix and binary search
class Solution {
public:
    int binarySearch(int i, vector<vector<int>>& events) {
        int l = i + 1, r = events.size() - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (events[mid][0] > events[i][1]) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(begin(events), end(events));
        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; i--)
            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);

        int result = 0;
        for (int i = 0; i < n; i++) {
            int index = binarySearch(i, events);
            result = max(result, events[i][2] + (index!=-1 ? suffixMax[index] : 0));
        }
        return result;
    }
};
