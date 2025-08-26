class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxarea=INT_MIN;
        double longest=LLONG_MIN;
        for(auto &temp:dimensions){
            int l=temp[0];
            int w=temp[1];
            double diagonal=sqrt(l*l+w*w);
            int area=l*w;
            if(diagonal>longest)
            {
                maxarea=area;
                longest=diagonal;
            }else if(diagonal==longest)
            {
                maxarea=max(area,maxarea);
            }
        }
        return maxarea;
    }
};
