/*<aside>
💡 **Question 4**

You have a `RecentCounter` class which counts the number of recent requests within a certain time frame.

Implement the `RecentCounter` class:

- `RecentCounter()` Initializes the counter with zero recent requests.
- `int ping(int t)` Adds a new request at time `t`, where `t` represents some time in milliseconds, and returns the number of requests that has happened in the past `3000` milliseconds (including the new request). Specifically, return the number of requests that have happened in the inclusive range `[t - 3000, t]`.

It is **guaranteed** that every call to `ping` uses a strictly larger value of `t` than the previous call.

</aside>*/

// SOLUTION
class RecentCounter {
public:
    queue<int>q;
    RecentCounter() { }
    
    int ping(int t) {
        int st=t-3000,c=0;
        q.push(t);

        while(!q.empty() ){
            if(q.front() <st )
            q.pop();
            else
            break;
        }

        return q.size();

    }
};
