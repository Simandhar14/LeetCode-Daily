class Solution {
public:
int getCount(string s)
{
    int count=0;
    for(char &ch:s) if(ch=='1') count++;
    return count;
}
int check(string s,int count)
{
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]=='0' && count>0) return false;
        if(s[i]=='1') count--;
    }
    return true;
}
    int maxOperations(string s) {
        int operations = 0;
        int n = s.size();
        int index = s.find('1');
        int onescount=getCount(s);
        if (index == string::npos || index == n - 1)
            return 0;
        if(check(s,onescount)) return 0;
        int numberofones = 1;
        int i = index + 1;
        while (i < n) {
            if (s[i] == '1') {
                if (index + 1 != i) {
                    operations += 1 * numberofones;
                }
                index=i;
                numberofones++;
            }
            i++;
        }
        if(s[n-1]!='1')
        {
            operations+=1*numberofones;
        }
        return operations;
    }
};
