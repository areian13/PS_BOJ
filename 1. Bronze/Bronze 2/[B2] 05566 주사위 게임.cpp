#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> board(n);
    for (int i = 0; i < n; i++)
        cin >> board[i];

    int k = 0;
    int result = 0;
    for (int i = 0; i < m; i++)
    {
        result++;

        int x;
        cin >> x;

        k += x;
        if (k >= n - 1)
            break;

        k += board[k];
        if (k >= n - 1)
            break;
    }
    cout << result << '\n';
}