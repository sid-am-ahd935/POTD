// ***    2706. Buy Two Chocolates    *** //

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        // priority_queue<int, vector<int>, greater<int>> minHeap;

        // for(auto p:prices) {
        //     minHeap.push(p);
        // }

        // int a = minHeap.top();
        // minHeap.pop();
        // int b = minHeap.top();
        // minHeap.pop();

        int a = INT_MAX, b = a;

        for(auto p:prices) {
            if(p < a) {
                b = a;
                a = p;
            } else if(p < b) {
                b = p;
            }
        }

        if(money >= a + b) {
            return money - (a+b);
        } else {
            return money;
        }
    }
};
