class MedianFinder {
public:
    /** initialize your data structure here. */

    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    MedianFinder()
    {

    }

    void addNum(int num)
    {
        if(!max_heap.size())
        {
            max_heap.push(num);
            return;
        }

        if(max_heap.size()==min_heap.size())
        {
            if(min_heap.top() < num)
            {
                int here = min_heap.top();
                min_heap.pop();
                min_heap.push(num);
                max_heap.push(here);
            }
            else
            {
                max_heap.push(num);
            }
        }
        else
        {
            if(max_heap.top() <= num)
            {
                min_heap.push(num);
                return;
            }
            else
            {
                int here = max_heap.top();
                max_heap.pop();
                max_heap.push(num);
                min_heap.push(here);
            }
        }
    }

    double findMedian()
    {
        if(max_heap.size() == min_heap.size())
        {
            return ( (long) max_heap.top() + (long) min_heap.top())/2.0;
        }
        else
        {
            return max_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
