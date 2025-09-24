class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result = "";
        if(numerator==0) return "0";
        if (numerator < 0 && denominator>0 || denominator < 0 && numerator>0)
            result += '-';
            
        long long num=llabs(1LL*numerator);
        long long den=llabs(1LL*denominator);
        long long quotient = num / den;
        result += to_string(quotient);
        long long remainder = num % den;
        if (remainder == 0)
            return result;

        unordered_map<int, int> remainderPos;
        result += '.';
        int pos = 0;
        string fraction = "";
        while (remainder != 0) {
            if (remainderPos.count(remainder)) {
                int start = remainderPos[remainder];
                fraction.insert(start, "(");
                fraction += ")";
                break;
            }
            remainderPos[remainder] = pos;
            remainder *= 10;
            fraction += to_string(remainder / den);
            remainder %= den;
            pos++;
        }
        result += fraction;
        return result;
    }
};
