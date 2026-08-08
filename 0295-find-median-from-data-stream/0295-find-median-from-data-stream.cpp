class MedianFinder {
private:
    priority_queue<int> maxi;
    priority_queue<int,vector<int>,greater<int>> mini;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxi.push(num);

        if (!mini.empty() && maxi.top() > mini.top()) {
            mini.push(maxi.top());
            maxi.pop();
        }

        if (maxi.size() > mini.size() + 1) {
            mini.push(maxi.top());
            maxi.pop();
        }

        if (mini.size() > maxi.size() + 1) {
            maxi.push(mini.top());
            mini.pop();
        }

        return;
    }
    
    double findMedian() {
        double med;

        if (maxi.size() == mini.size()) {
            med = (maxi.top() + mini.top()) / 2.0;
        } else if (maxi.size() > mini.size()) {
            med = maxi.top();
        } else {
            med = mini.top();
        }
        
        return med;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */