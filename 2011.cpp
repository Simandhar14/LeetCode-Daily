class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X=0;
        for(string &op:operations){
            if(op[0]=='-' || op.back()=='-') X--;
            else X++;
        }
        return X;
    }
};
