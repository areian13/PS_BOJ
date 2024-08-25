#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    if (n < s.size())
        cout << "Impossible" << '\n';
    else
    {
        int result = 0;
        for (char c : s)
            result += (c - 'a') + 1;
        cout << result << '\n';
    }
}