#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int maxValue = 0;
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        if (value > maxValue)
        {
            maxValue = value;
            idx = i;
        }
    }

    char result = (idx == 0 ? 'S' : 'N');
    cout << result << '\n';
}