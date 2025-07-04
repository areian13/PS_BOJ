#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        string a, b;
        cin >> a >> b;

        int n = a.size();
        int result = 0;
        for (int i = 0; i < n; i++)
            result += a[i] - b[i];

        cout << "Swapping letters to make ";
        cout << a << ' ';
        cout << "look like ";
        cout << b << ' ';

        if (result > 0)
            cout << "earned " << result << " coins.\n";
        else if (result < 0)
            cout << "cost " << -result << " coins.\n";
        else
            cout << "was FREE.\n";
    }
}