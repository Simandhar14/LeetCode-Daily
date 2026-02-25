class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int,vector<int>>mp;
        sort(begin(arr),end(arr));
        for(int &num:arr)
        {
            int setBits=__builtin_popcount(num);
            mp[setBits].push_back(num);
        }
        vector<int>result;
        for(auto &temp:mp)
        {
            for(auto &numbers:temp.second) result.push_back(numbers);
        }
        return result;
    }
};

//without space
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(begin(arr),end(arr),[&](int &a,int &b){
             int setBits1=__builtin_popcount(a);
             int setBits2=__builtin_popcount(b);
             if(setBits1==setBits2) return a<b;
             return setBits1<setBits2;
        });
        return arr;
    }
};
