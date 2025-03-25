class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>allranges;
        int size=rectangles.size();
        vector<vector<int>>ranges;
        for(int i=0;i<size;i++)
        {
            ranges.push_back({rectangles[i][0],rectangles[i][2]});
        }
        sort(begin(ranges),end(ranges));
        int i=0;
        int len=ranges.size();
        while(i<len)
        {
            int start=ranges[i][0];
            int end=ranges[i][1];
            while(i+1<len && end>ranges[i+1][0])
            {
                end=max(end,ranges[i+1][1]);
                i++;
            }
            allranges.push_back({start,end});
            i++;
        }
        if(allranges.size()>2) return true;
        allranges.clear();
        ranges.clear();
        for(int i=0;i<size;i++)
        {
            ranges.push_back({rectangles[i][1],rectangles[i][3]});
        }
        sort(begin(ranges),end(ranges));
        i=0;
        len=ranges.size();
        while(i<len)
        {
            int start=ranges[i][0];
            int end=ranges[i][1];
            while(i+1<len && end>ranges[i+1][0])
            {
                end=max(end,ranges[i+1][1]);
                i++;
            }
            allranges.push_back({start,end});
            i++;
        }
        if(allranges.size()>2) return true;
        return false;
    }
};
