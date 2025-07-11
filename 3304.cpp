class Solution {
public:
    char kthCharacter(int k) {
     string word="a";
     while(word.length()<k)
     {
        string temp=word;
        for(int i=0;i<temp.length();i++)
        {
            if(temp[i]=='z') temp[i]='a';
            else temp[i]=temp[i]+1;
        }
        word+=temp;
     }   
     return word[k-1];
    }
};
