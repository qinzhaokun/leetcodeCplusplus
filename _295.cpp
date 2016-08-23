class MedianFinder {
public:
    
    priority_queue<int,vector<int>,greater<int>> min;
    priority_queue<int> max;
    // Adds a number into the data structure.
    void addNum(int num) {
        max.push(num);
        int top = max.top(); max.pop();
        min.push(top);
        if(min.size() > max.size()){
            int top = min.top(); min.pop();
            max.push(top);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(min.size() == max.size()){
            return (min.top()+max.top())/2.0;
        }
        else{
            return max.top();
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
