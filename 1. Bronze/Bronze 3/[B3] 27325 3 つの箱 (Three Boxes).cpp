#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    string x;
    cin >> n >> x;

    int result = 0;
    int box = 1;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == 'L')
            box = max(box - 1, 1);
        else if (x[i] == 'R')
            box = min(box + 1, 3);
        result += (box == 3);
    }
    cout << result << '\n';
}