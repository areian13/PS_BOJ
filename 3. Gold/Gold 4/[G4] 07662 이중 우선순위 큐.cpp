#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

template <typename T>
struct DoublePriorityQueue
{
private:
    priority_queue<T> maxHeap;
    priority_queue<T, vector<T>, greater<T>> minHeap;
    unordered_map<T, int> cnt;

public:
    void push(T data)
    {
        maxHeap.push(data);
        minHeap.push(data);
        cnt[data]++;
    }
    void popMax()
    {
        if (maxHeap.empty())
            return;

        cnt[maxHeap.top()]--;
        maxHeap.pop();
        Clean();
    }
    T topMax()
    {
        if (maxHeap.empty())
            return (T)0;

        return maxHeap.top();
    }
    void popMin()
    {
        if (minHeap.empty())
            return;

        cnt[minHeap.top()]--;
        minHeap.pop();
        Clean();
    }
    T topMin()
    {
        if (minHeap.empty())
            return (T)0;

        return minHeap.top();
    }
    bool empty()
    {
        return minHeap.empty();
    }
    void Clean()
    {
        while (!maxHeap.empty() && cnt[maxHeap.top()] == 0)
            maxHeap.pop();
        while (!minHeap.empty() && cnt[minHeap.top()] == 0)
            minHeap.pop();
    }
};

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int k;
        cin >> k;

        DoublePriorityQueue<int> DPQ;

        for (int i = 0; i < k; i++)
        {
            char op;
            int value;
            cin >> op >> value;

            if (op == 'I')
                DPQ.push(value);
            else
            {
                if (value == 1)
                    DPQ.popMax();
                else
                    DPQ.popMin();
            }
        }

        if (!DPQ.empty())
            cout << DPQ.topMax() << ' ' << DPQ.topMin() << '\n';
        else
            cout << "EMPTY" << '\n';
    }
}