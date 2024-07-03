#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int w, n;
    cin >> w >> n;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int wi, li;
        cin >> wi >> li;

        result += wi * li;
    }
    result /= w;
    cout << result << '\n';
}