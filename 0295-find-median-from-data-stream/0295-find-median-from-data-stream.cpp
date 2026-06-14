class MedianFinder {
public:
    //MaxHeap and MinHeap
    priority_queue<double> maxHeap;
    priority_queue<double, vector<double>, greater<double>> minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // 3 Case for add num
        if(minHeap.size() == maxHeap.size()){
            double median = findMedian();
            if(num>median){
                minHeap.push(num);
            }
            else{
                maxHeap.push(num);
            }
        }
        else if(maxHeap.size() == minHeap.size()+1){
            double median = findMedian();
            if(num>median){
                minHeap.push(num);
            }
            else{
                double element = maxHeap.top();
                maxHeap.pop();
                minHeap.push(element);
                maxHeap.push(num);
            }
        }
        else if(maxHeap.size()+1 == minHeap.size()){
            double median = findMedian();
            if(num>median){
                double element = minHeap.top();
                minHeap.pop();
                maxHeap.push(element);
                minHeap.push(num);
            }
            else{
                maxHeap.push(num);
            }
        }

    }
    
    double findMedian() {
        // 4 Case
        //Case 1 both are empty
        if(minHeap.size() == 0 && maxHeap.size() == 0){
            return 0;
        }
        else if(maxHeap.size() == minHeap.size()){
            double median = (maxHeap.top() + minHeap.top())/2;
            return median;
        }
        else if(maxHeap.size() > minHeap.size()){
            double median = maxHeap.top();
            return median;
        }
        else{
            return minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */