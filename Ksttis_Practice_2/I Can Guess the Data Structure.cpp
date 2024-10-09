#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>

using namespace std;

int main() {
    int cases;
    int ops;
    int num;
    while(cin >> cases) {
        cin.ignore();
        bool is_q = true;
        bool is_s = true;
        bool is_p = true;
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;

        for (size_t i = 0; i < cases; i++) {
            cin >> ops >> num;
            if (ops == 1) {
                if(is_q) q.push(num);
                if(is_s) s.push(num);
                if(is_p) pq.push(num);
            } else if (ops == 2) {
                if (is_q)
                {
                    if (!q.empty()&& q.front() == num)
                    {
                        q.pop();
                    }else{
                        is_q = false;
                    }
                    
                }
                if (is_s)
                {
                    if (!s.empty()&& s.top() == num)
                    {
                        s.pop();
                    }else{
                        is_s = false;
                    }
                }
                if (is_p)
                {
                    if (!pq.empty()&& pq.top() == num)
                    {
                        pq.pop();
                    }else{
                        is_p = false;
                    }
                }
                
            }
        }

        

        if (is_q == true && is_s != true && is_p != true) {
            cout << "queue" << endl;
        } else if (is_q != true && is_s == true && is_p != true) {
            cout << "stack" << endl;
        } else if (is_q != true && is_s != true && is_p == true) {
            cout << "priority queue" << endl;
        } else if (is_q != true && is_s != true && is_p != true) {
            cout << "impossible" << endl;
        } else {
            cout << "not sure" << endl;
        }
    }
    return 0;
}
