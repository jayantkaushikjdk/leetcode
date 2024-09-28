// Space: O(K)
class MyCircularDeque {
    vector<int> q;
    int begin = 0, end = 0, k, cnt = 0;
public:
    MyCircularDeque(int k) : q(k), k(k) {}
    bool insertFront(int value) {
        if (cnt == k) return false;
        begin = (begin - 1 + k) % k;
        q[begin] = value;
        ++cnt;
        return true;
    }
    bool insertLast(int value) {
        if (cnt == k) return false;
        q[end] = value;
        end = (end + 1) % k;
        ++cnt;
        return true;
    }
    bool deleteFront() {
        if (cnt == 0) return false;
        begin = (begin + 1) % k;
        --cnt;
        return true;
    }
    bool deleteLast() {
        if (cnt == 0) return false;
        end = (end - 1 + k) % k;
        --cnt;
        return true;
    }
    int getFront() {
        if (cnt == 0) return -1;
        return q[begin];
    }
    int getRear() {
        if (cnt == 0) return -1;
        return q[(end - 1 + k) % k];
    }
    bool isEmpty() {
        return cnt == 0;
    }
    bool isFull() {
        return cnt == k;
    }
};