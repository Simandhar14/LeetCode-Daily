class Solution {
public:
    int minMaxDifference(int num) {
        string number=to_string(num);
        int maxnum=INT_MIN;
        int minnum=INT_MAX;
        int n=number.length();
        for(int i=0;i<n;i++)
        {
            int digit=(int)number[i];
            string temp=number;
            temp[i]='9';
            for(int j=i+1;j<n;j++)
            {
                if(digit==(int)number[j])
                {
                    temp[j]='9';
                }
            }
            maxnum=max(maxnum,stoi(temp));
        }
         for(int i=0;i<n;i++)
        {
            int digit=(int)number[i];
            string temp=number;
            temp[i]='0';
            for(int j=i+1;j<n;j++)
            {
                if(digit==(int)number[j])
                {
                    temp[j]='0';
                }
            }
            minnum=min(minnum,stoi(temp));
        }
        return maxnum-minnum;
    }
};
