class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            char ch=s.back();
            s.pop_back();
            s=ch+s;
            if(s==goal) return true;
        }
        return false;
    }
};

//better approach
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        s += s;
        int idx = s.find(goal);
        return idx != -1;
    }
};
