class Solution {
public:
    string compressedString(string word) {
        string result="";
        int n=word.size();
        int i=0;
        while(i<n)
        {
            char ch=word[i];
            int j=i+1;
            int count=1;
            while(j<n && ch==word[j] && count<9)
            {
                count++;
                j++;
            }
            i=j;
            string temp=to_string(count)+ch;
            result+=temp;
        }
        return result;
    }
};