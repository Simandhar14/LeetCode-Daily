class Solution {
public:
double epsilon=1e-6;
    bool solve(vector<double>& cards) {
        if (cards.size() == 1) {
            return abs(cards[0]-24.0)<=epsilon;
        }
        bool result = false;
        for (int i = 0; i < cards.size(); i++) {
            for (int j = 0; j < cards.size(); j++) {
                vector<double> temp;
                if (i == j)
                    continue;
                for (int k = 0; k < cards.size(); k++) {
                    if (k == i || k == j)
                        continue;
                    temp.push_back(cards[k]);
                }
                double add = cards[i] + cards[j];
                temp.push_back(add);
                result |= solve(temp);
                temp.pop_back();

                double sub = cards[i] - cards[j];
                temp.push_back(sub);
                result |= solve(temp);
                temp.pop_back();

                double sub2 = cards[j] - cards[i];
                temp.push_back(sub2);
                result |= solve(temp);
                temp.pop_back();

                double mul = cards[i] * cards[j];
                temp.push_back(mul);
                result |= solve(temp);
                temp.pop_back();

                if(cards[j]>0.0){
                double div = cards[i] / cards[j];
                temp.push_back(div);
                result |= solve(temp);
                temp.pop_back();
                }
                if(cards[i]>0.0){
                double div2 = cards[j] / cards[i];
                temp.push_back(div2);
                result |= solve(temp);
                temp.pop_back();
                }
            }
        }
        return result;
    }
    bool judgePoint24(vector<int>& cards) { 
        vector<double>nums;
        for(int num:cards) nums.push_back(1.0 * num);
        return solve(nums); 
    }
};
