class Solution {
public:
    string sortVowels(string s) {
        string t=s;
        vector<char>vowels;
        for(char ch:s)
        {
            if(ch=='A' || ch=='a' || ch=='I' || ch=='i' || ch=='O' || ch=='o' || ch=='E' || ch=='e' || ch=='U' || ch=='u') vowels.emplace_back(ch);
        }
        sort(rbegin(vowels),rend(vowels));
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
             if(ch=='A' || ch=='a' || ch=='I' || ch=='i' || ch=='O' || ch=='o' || ch=='E' || ch=='e' || ch=='U' || ch=='u'){
                t[i]=vowels.back();
                vowels.pop_back();
             }else t[i]=s[i];
        }
        return t;
    }
};
