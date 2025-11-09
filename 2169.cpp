//brute force

class Solution {
public:
    int countOperations(int num1, int num2) {
        int operations=0;
        while(num1>0 && num2>0){
            if(num1>=num2) num1-=num2;
            else num2-=num1;
            operations++;
        }
        return operations;
    }
};

//better approach
class Solution {
public:
    int countOperations(int num1, int num2) {
        int operations=0;
        while (num1 > 0 && num2 > 0) {
            int maxval = max(num1, num2);
            int minval = min(num1, num2);
            int quotient = maxval / minval;
            int rem = maxval % minval;
            operations+=quotient;
            num1=rem;
            num2=minval;
        }
        return operations;
    }
};
