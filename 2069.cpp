//cpp
class Robot {
public:
    bool moved = false;
    int m, n, pos;
    vector<vector<int>> moves;
    Robot(int width, int height) {
        m = height;
        n = width;
        pos = 0;
        for (int i = 0; i < n; i++)
            moves.push_back({i, 0, 0});
        for (int j = 1; j < m; j++)
            moves.push_back({n - 1, j, 1});
        for (int i = n - 2; i >= 0; i--)
            moves.push_back({i, m - 1, 2});
        for (int j = m - 2; j >= 1; j--)
            moves.push_back({0, j, 3});
    }

    void step(int num) {
        if (num > 0)
            moved = true;
        pos = (pos + num) % (int)moves.size();
    }
    string getDir() {
        if (moved && pos == 0)
            return "South";
        int dir = moves[pos][2];
        if (dir == 0)
            return "East";
        if (dir == 1)
            return "North";
        if (dir == 2)
            return "West";
        return "South";
    }
    vector<int> getPos() { return {moves[pos][0], moves[pos][1]}; }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
