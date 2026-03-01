//cpp

class Solution {
public:
    int minPartitions(string n) {
        int result=0;
        for(int i=0;i<=n.length();i++){
            result=max(result,n[i]-'0');
        }
        return result;
    }
};
