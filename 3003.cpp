class Solution {
public:
unordered_map<long long,int> mp;
int K;
string S;
int solve(long long uniqueChar,  bool canChange,  long long i) {
    if (i >= S.size()) return 0;   

    long long key = (i << 27) | (uniqueChar << 1) | (canChange);

    if (mp.count(key)) return mp[key];

    int charIndex = S[i] - 'a';
    int uniqueUpdated = uniqueChar | (1 << charIndex);
    int uniqueCount = __builtin_popcount(uniqueUpdated);
    int result;

    if (uniqueCount > K) {
        result = 1 + solve((1 << charIndex),  canChange,  i + 1);
    } else {
        result = solve(uniqueUpdated,  canChange,  i + 1);
    }

    if (canChange) {
        for (int newChar = 0; newChar < 26; newChar++) {
            int newUnique = uniqueChar | (1 << newChar);
            int newUniqueCount = __builtin_popcount(newUnique);
            if (newUniqueCount > K) {
                result = max(result, 1 + solve((1 << newChar),  false,  i + 1));
            } else {
                result = max(result, solve(newUnique,  false,  i + 1));
            }
        }
    }
    return mp[key] = result;
}

int maxPartitionsAfterOperations(string s, int k) {
    K=k;
    S=s;
    return solve(0, true,  0) + 1;  
}
};
