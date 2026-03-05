//cpp
class Solution {
public:
    int minOperations(string s) {
      int startsWithZero=0;
      int n=s.length();
      for(int i=0;i<n;i++)
      {
        if(i%2==0) 
        {
            if(s[i]=='1') startsWithZero++;
        }
        else{
            if(s[i]=='0') startsWithZero++;
        }
      }
      return min(startsWithZero,n-startsWithZero);
    }
};
