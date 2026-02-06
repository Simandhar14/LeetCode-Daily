//sorting+binarySearch
class Solution {
public:
int binarySearch(long long knum,vector<int>&nums)
{
    int l=0,r=nums.size()-1;
    int index=-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(1LL*nums[mid]<=knum)
        {
            index=mid;
            l=mid+1;
        } 
        else r=mid-1;
    }
    return index;
}
    int minRemoval(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int minRemove=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            long long knum=1LL*num*k;
            int kindex=binarySearch(knum,nums);
            if(kindex!=-1 && nums[kindex]<=knum)
            {
                minRemove=min(minRemove,n-1-kindex+i);
            }
        }
        return minRemove;
    }
};

//sorting+two pointer
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int i=0;
        int j=0;
        int minRemove=INT_MAX;
        while(j<n)
        {
            long long knum=1LL*nums[i]*k;
            if(1LL*nums[j]<=knum)
            {
                minRemove=min(minRemove,n-(j-i+1));
                j++;
            }else i++;
        }
        return minRemove;
    }
};
