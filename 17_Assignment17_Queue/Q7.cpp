/*<aside>
💡 **Question 7**
Design a queue that supports `push` and `pop` operations in the front, middle, and back.
Implement the `FrontMiddleBack` class:
- `FrontMiddleBack()` Initializes the queue.
- `void pushFront(int val)` Adds `val` to the **front** of the queue.
- `void pushMiddle(int val)` Adds `val` to the **middle** of the queue.
- `void pushBack(int val)` Adds `val` to the **back** of the queue.
- `int popFront()` Removes the **front** element of the queue and returns it. If the queue is empty, return `1`.
- `int popMiddle()` Removes the **middle** element of the queue and returns it. If the queue is empty, return `1`.
- `int popBack()` Removes the **back** element of the queue and returns it. If the queue is empty, return `1`.
**Notice** that when there are **two** middle position choices, the operation is performed on the **frontmost** middle position choice. For example:
- Pushing `6` into the middle of `[1, 2, 3, 4, 5]` results in `[1, 2, 6, 3, 4, 5]`.
- Popping the middle from `[1, 2, 3, 4, 5, 6]` returns `3` and results in `[1, 2, 4, 5, 6]`.
</aside>*/

// SOLUTION
class FrontMiddleBackQueue {
public:
    vector<int> v;
    int cnt = 0;
    FrontMiddleBackQueue() {
        v.clear();

    }
    
    void pushFront(int val) {
        if(v.empty()) v.push_back(val);
        else
        v.insert(v.begin(),val);
        cnt++;
    }
    
    void pushMiddle(int val) {
        v.insert(v.begin()+cnt/2,val);
        cnt++;
    }
    
    void pushBack(int val) {
        v.push_back(val);
        cnt++;
    }
    
    int popFront() {
        if(v.empty()) return -1;
        int t = v[0];
        v.erase(v.begin());
        cnt--;
        return t;
    }
    
    int popMiddle() {
        if(v.empty()) return -1;
        int mid = cnt/2;
        if(cnt % 2 == 0){
         mid = v[cnt/2-1];
        v.erase(v.begin()+cnt/2-1);
        }
        else{
             mid = v[cnt/2];
        v.erase(v.begin()+cnt/2);
        }
        cnt--;
        return mid;
    }
    
    int popBack() {
        if(v.empty()) return -1;
        int b = v[cnt-1];
        v.pop_back();
        cnt--;
        return b;
    }
};