//cpp
class ProductOfNumbers {
public:
    vector<int> product;
    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0)
            product.clear();
        else if (product.empty()) {
            product.push_back(num);
        } else {
            product.push_back(num * product.back());
        }
    }

    int getProduct(int k) {
        int n = product.size();
        if (k > n)
            return 0;
        else if (k == n)
            return product.back();
        return product.back() / product[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
