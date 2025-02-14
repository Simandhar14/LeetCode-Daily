class ProductOfNumbers {
public:
    vector<int> prefix;
    
    ProductOfNumbers() {}
    
    void add(int num) {
        if(num == 0) 
            prefix.clear();
        else if(prefix.empty()) 
            prefix.emplace_back(num);
        else 
            prefix.emplace_back(num * prefix.back());
    }
    
    int getProduct(int k) {
        int n = prefix.size();
        if(n < k) return 0; // If k is greater than available elements, return 0
        return (k == n) ? prefix.back() : prefix[n-1] / prefix[n-k-1]; 
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
