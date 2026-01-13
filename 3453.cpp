//binary search
class Solution {
public:
    int equalArea(double y, vector<vector<int>>& squares) {
        double aboveArea = 0.0, belowArea = 0.0;
        for (int i = 0; i < squares.size(); i++) {
            double x1 = squares[i][0];
            double y1 = squares[i][1];
            double side = squares[i][2];
            double totalArea = 1.0 * side * side;
            if (y1 >= y) {
                aboveArea += totalArea;
            } else if (y1 + side <= y) {
                belowArea += totalArea;
            } else {
                double lowerArea = (y - y1) * side;
                belowArea += lowerArea;
                aboveArea += totalArea - lowerArea;
            }
        }
        double areaDiff = aboveArea - belowArea;
        if (fabs(areaDiff) < 1e-6)
            return 0;
        return areaDiff > 0.0 ? 1 : -1;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double left = 0.0;
        double right = 1000000000.0;
        while (right - left > 1e-6) {
            double mid = left + (right - left) / 2;
            double result = equalArea(mid, squares);
            if (result==0) {
                right = mid;
            } else if (result == 1 )
                left = mid;
            else
                right = mid;
        }
        return right;
    }
};
