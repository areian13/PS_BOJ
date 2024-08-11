#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsInB(int num, vector<int>& b)
{
    for (int score : b)
    {
        if (num == score)
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m;
    cin >> m;

    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result += a[i];
        if (IsInB(result, b))
            result = 0;
    }
    cout << result << '\n';
}