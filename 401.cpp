//cpp
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for (int hour = 0; hour <= 11; hour++) {
            for (int minute = 0; minute <= 59; minute++) {
                int hourBits = __builtin_popcount(hour);
                int minuteBits = __builtin_popcount(minute);
                if((hourBits+minuteBits)==turnedOn)
                {
                    string str=to_string(hour)+":"+(minute<10 ? to_string(0)+to_string(minute) : to_string(minute));
                    result.push_back(str);
                }
            }
        }
        return result;
    }
};
