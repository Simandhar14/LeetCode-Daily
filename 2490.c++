class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string>arr;
        stringstream ss(sentence);
        string word;
        while(getline(ss,word,' '))
        {
            arr.push_back(word);
        }
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            string ss1=arr[i%n];
            string ss2=arr[(i+1)%n];
            int n1=ss1.length();
            if(ss1[n1-1]!=ss2[0]) return false;
        }
        return true;
    }
};