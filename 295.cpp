class MedianFinder {
public:
    priority_queue<int, vector<int>> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder() {}

    void addNum(int num) {
         maxheap.push(num);
        int topval = maxheap.top();
        maxheap.pop();
        minheap.push(topval);
       
        if (minheap.size() > maxheap.size()) {
            int topval = minheap.top();
            minheap.pop();
            maxheap.push(topval);
        }
    }

    double findMedian() {
        int n = maxheap.size() + minheap.size();
        if (n % 2 == 0) {
            double ans=(maxheap.top() + minheap.top()) / 2.0;
            return ans;
        } else {
            return (double) maxheap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
