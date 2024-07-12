#include <iostream>
#include <queue>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

template <typename T>
struct AbsComparator
{
    bool operator()(const T& a, const T& b)
    {
        if (abs(a) != abs(b))
            return abs(a) > abs(b);
        return a > b;
    }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    priority_queue<int, vector<int>, AbsComparator<int>> absHeap;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x != 0)
            absHeap.push(x);
        else
        {
            if (absHeap.empty())
                absHeap.push(0);

            int result = absHeap.top();
            cout << result << '\n';

            absHeap.pop();
        }
    }
}