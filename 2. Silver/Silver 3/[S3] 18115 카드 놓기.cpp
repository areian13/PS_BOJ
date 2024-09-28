#include <iostream>
#include <vector>
#include <deque>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    deque<int> DQ;
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        cnt++;

        if (a[i] == 1)
            DQ.push_front(cnt);
        else if (a[i] == 2)
        {
            int temp = DQ.front();
            DQ.pop_front();
            DQ.push_front(cnt);
            DQ.push_front(temp);
        }
        else if (a[i] == 3)
            DQ.push_back(cnt);
    }

    while (!DQ.empty())
    {
        cout << DQ.front() << ' ';
        DQ.pop_front();
    }
}