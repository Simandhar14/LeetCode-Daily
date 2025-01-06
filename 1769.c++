class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>oneindex;
        for(int i=0;i<n;i++)
        {
            if(boxes[i]=='1') oneindex.push_back(i);
        }
        vector<int>result(n,0);
        for(int i=0;i<n;i++)
        {
            int swaps=0;
            for(int idx:oneindex)
            {
                if(i==idx) continue;
                swaps+=abs(idx-i);
            }
            result[i]=swaps;
        }
        return result;
    }
};