class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<long> pq_s;
    priority_queue<long>pq_l;
    
    
    MedianFinder() {

    }

    void addNum(int num) {
        // do this to sort the element !   
        pq_s.push(num);
        pq_l.push(-pq_s.top());
        pq_s.pop();
        // balance the trees
        if(pq_l.size() > pq_s.size()) {
            pq_s.push(-pq_l.top());
            pq_l.pop();
        }
    }
            
        
        
        
    

    double findMedian() {
        // idea is to keep two heaps, one max for half of the solutions, one min for other half of the solutions.
        return (pq_s.size() > pq_l.size())? pq_s.top(): (pq_s.top() - pq_l.top())/2.0;
    }
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */