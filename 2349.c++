class NumberContainers {
public:
    unordered_map<int, int> mp;
    unordered_map<int,set<int>> container;
    NumberContainers() {}

    void change(int index, int number) {
        if (mp.count(index)) {
            int prevnumber = mp[index];
            container[prevnumber].erase(index);
            if (container[prevnumber].empty()) {
                container.erase(prevnumber);
            }
        }
        mp[index] = number;
        container[number].insert(index);
    }

    int find(int number) {
        if (container.count(number)) {
            int index = *container[number].begin();
            return index;
        } else
            return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */