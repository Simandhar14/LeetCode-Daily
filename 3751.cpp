//cpp
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total=0;
        for(int num=num1;num<=num2;num++)
        {
            int waviness=0;
            string ss=to_string(num);
            int i=1;
            while(i<ss.length()-1)
            {
                if(ss[i]>ss[i-1] && ss[i]>ss[i+1] || ss[i]<ss[i-1] && ss[i]<ss[i+1]) waviness++;
                i++;
            }
            total+=waviness;
        }
        return total;
    }
};
