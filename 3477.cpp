class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count=0;
        int n=fruits.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(baskets[j]>=fruits[i]) {
                    fruits[i]=-1;
                    baskets[j]=-1;
                    break;
                }
            }
            if(fruits[i]!=-1) count++; 
        }
        return count;
    }
};
