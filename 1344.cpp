//cpp
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle1 = abs(30 * hour - 5.5 * minutes);
        return min(angle1, 360 - angle1);
    }
};
