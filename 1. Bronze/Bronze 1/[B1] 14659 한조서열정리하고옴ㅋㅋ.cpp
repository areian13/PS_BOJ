#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    int n;
    cin >> n;

    int preMaxH = 0;
    int kill = 0;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;

        if (h <= preMaxH)
            kill++;
        else
        {
            kill = 0;
            preMaxH = h;
        }
        result = max(result, kill);
    }
    cout << result << '\n';
}