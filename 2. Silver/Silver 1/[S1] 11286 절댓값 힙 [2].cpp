#include <iostream>
#include <queue>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

template <typename T>
struct Abs
{
    T data;

    friend bool operator<(const Abs& a, const Abs& b)
    {
        if (abs(a.data) != abs(b.data))
            return abs(a.data) > abs(b.data);
        return a.data > b.data;
    }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    priority_queue<Abs<int>> absHeap;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x != 0)
            absHeap.push({ x });
        else
        {
            if (absHeap.empty())
                absHeap.push({ 0 });

            int result = absHeap.top().data;
            cout << result << '\n';

            absHeap.pop();
        }
    }
}