class Solution {
public:
    int findLucky(vector<int>& arr) {
        int maxnum=*max_element(begin(arr),end(arr));
        vector<int>freq(maxnum+1,0);
        for(int i=0;i<arr.size();i++)
        {
            freq[arr[i]]++;
        }
        int ans=-1;
        for(int i=1;i<maxnum+1;i++)
        {
            if(freq[i]==i) ans=i;
        }
        return ans;
    }
};
