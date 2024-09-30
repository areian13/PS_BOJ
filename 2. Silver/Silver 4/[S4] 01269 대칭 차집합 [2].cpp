#include <iostream>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    unordered_map<int, bool> isIn;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        isIn[a] = true;
    }

    int result = n;
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;

        result += (isIn[b] ? -1 : +1);
    }
    cout << result << '\n';
}