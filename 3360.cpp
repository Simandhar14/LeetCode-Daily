//cpp
class Solution {
public:
    bool canAliceWin(int n) {
        bool alice = true;
        for (int i = 10; i >= 0; i--) {
            if (n < i)
                return !alice;
            n -= i;
            alice = !alice;
        }
        return !alice;  
    }
};
