#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<bool> isCompleted(n + 1, false);
    for (int i = 0; i < n - 1; i++)
    {
        int num;
        cin >> num;

        isCompleted[num] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!isCompleted[i])
            cout << i << '\n';
    }
}