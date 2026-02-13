//cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tripleChar(char a,char b,char c,string s)
    {
        unordered_map<string,int> mp;
        int count_a=0,count_b=0,count_c=0;
        int result=0;
        int n=s.length();

        mp["0_0"] = -1;

        for(int i=0;i<n;i++)
        {
            if(s[i]==a) count_a++;
            else if(s[i]==b) count_b++;
            else if(s[i]==c) count_c++;

            int diff1 = count_a - count_b;
            int diff2 = count_a - count_c;
            string diff = to_string(diff1) + "_" + to_string(diff2);

            if(mp.count(diff))
                result = max(result, i - mp[diff]);
            else
                mp[diff] = i;
        }
        return result;
    }

    int doubleChar(char a,char b,string s)
    {
        unordered_map<int,int> mp;
        int count_a=0,count_b=0;
        int result=0;
        int n=s.length();

        mp[0] = -1;

        for(int i=0;i<n;i++)
        {
            if(s[i]!=a && s[i]!=b)
            {
                count_a = count_b = 0;
                mp.clear();
                mp[0] = i;
                continue;
            }

            if(s[i]==a) count_a++;
            else count_b++;

            int diff = count_a - count_b;

            if(mp.count(diff))
                result = max(result, i - mp[diff]);
            else
                mp[diff] = i;
        }
        return result;
    }

    int singleChar(char ch,string s)
    {
        int result=0, count=0;

        for(char c : s)
        {
            if(c==ch) count++;
            else
            {
                result = max(result, count);
                count = 0;
            }
        }
        result = max(result, count);
        return result;
    }

    int longestBalanced(string s) {
        int result = 1;

        result = max({result,
                      singleChar('a',s),
                      singleChar('b',s),
                      singleChar('c',s)});

        result = max({result,
                      doubleChar('a','b',s),
                      doubleChar('a','c',s),
                      doubleChar('b','c',s)});

        result = max(result, tripleChar('a','b','c',s));

        return result;
    }
};
