class Spreadsheet {
public:
    vector<vector<int>> sheet;
    Spreadsheet(int rows) { sheet.resize(rows+1, vector<int>(26, 0)); }

    void setCell(string cell, int value) {
        char ch = cell[0];
        int col = ch - 'A';
        string ss = cell.substr(1);
        int row = stoi(ss);
        sheet[row][col] = value;
    }

    void resetCell(string cell) {
        char ch = cell[0];
        int col = ch - 'A';
        string ss = cell.substr(1);
        int row = stoi(ss);
        sheet[row][col] = 0;
    }

    int getValue(string formula) {
        string s=formula.substr(1);
        stringstream ss(s);
        string word;
        int val = 0;
        while (getline(ss, word, '+')) {
            if (word.empty()) continue; 
            char ch = word[0];
            if(isalpha(ch)){
            int col = ch - 'A';
            string ss2 = word.substr(1);
            int row = stoi(ss2);
            val+=sheet[row][col];
            }
            else{
                val+=stoi(word);
            }
        }
        return val;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
