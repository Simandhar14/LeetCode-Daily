class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string num=to_string(n);
        unordered_map<char,int>mp;
      
        for(char ch:num)
        {
            mp[ch]++;
        }
        sort(begin(num),end(num),greater<int>());
        int largestnum=stoi(num);
        for(int i=1;i<=largestnum;i<<=1)
        {
            string ss=to_string(i);
            if(ss.size()!=num.size()) continue;
            bool invalid=false;
            unordered_map<char,int>temp=mp;
            for(char ch:ss)
            {
                if(temp.find(ch)==temp.end()) {
                    invalid=true;
                    break;
                }
                temp[ch]--;
                if(temp[ch]==0) temp.erase(ch);
            }
            if(invalid || temp.size()>0) continue;
           if ((i & (i - 1)) == 0) return true;
        }
        return false;
    }
};
