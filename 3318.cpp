class Solution {
public:
int getFrequentSum(vector<int>&freq,int k,int x)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>>pq; //max heap
    for(int i=0;i<51;i++)
    {
        if(freq[i]==0) continue;
        pq.push({freq[i],i});
    }
    int sum=0;
    while(!pq.empty() && x--)
    {
        sum+= (pq.top().first * pq.top().second);
        pq.pop();
    }
    return sum;
}
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int>freq(51,0);
        vector<int>ans;
        for(int i=0;i<k-1;i++)
        {
            freq[nums[i]]++;
        }
        int last=0;
        for(int i=k-1;i<n;i++)
        {
            freq[nums[i]]++;
            int sum=getFrequentSum(freq,k,x);
            ans.emplace_back(sum);
            freq[nums[last]]--;
            last++;
        }
        return ans;
    }
};
