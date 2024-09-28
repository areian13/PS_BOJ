#include <iostream>
#include <deque>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Balloon
{
    int k, idx;
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    deque<Balloon> DQ;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        DQ.push_back({ k,i + 1 });
    }

    vector<int> result;
    bool isRight = true;
    while (true)
    {
        Balloon cur = (isRight ? DQ.front() : DQ.back());
        isRight ? DQ.pop_front() : DQ.pop_back();

        result.push_back(cur.idx);

        if (DQ.empty())
            break;

        isRight = (cur.k > 0);
        int k = abs(cur.k) - 1;
        for (int i = 0; i < k; i++)
        {
            if (isRight)
            {
                DQ.push_back(DQ.front());
                DQ.pop_front();
            }
            else
            {
                DQ.push_front(DQ.back());
                DQ.pop_back();
            }
        }
    }

    for (int idx : result)
        cout << idx << ' ';
    cout << '\n';
}