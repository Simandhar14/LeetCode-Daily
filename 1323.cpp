class Solution {
public:
    int maximum69Number (int num) {
        string ss=to_string(num);
        int idx=ss.find('6');
        if(idx!=string::npos)
        {
            ss[idx]='9';
        }
        return stoi(ss);
    }
};
