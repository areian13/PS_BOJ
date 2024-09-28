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
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;

        if (a[i] == 0)
            DQ.push_back(b);
    }

    int m;
    cin >> m;

    vector<int> result(m);
    for (int i = 0; i < m; i++)
    {
        int c;
        cin >> c;

        DQ.push_front(c);
        result[i] = DQ.back();
        DQ.pop_back();
    }

    for (int i = 0; i < m; i++)
        cout << result[i] << ' ';
    cout << '\n';
}