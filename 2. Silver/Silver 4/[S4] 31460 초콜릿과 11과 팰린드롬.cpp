#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Palin11(int n)
{
    if (n == 1) return "0";
    return '1' + string(n - 2, '2') + '1';
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        string result = Palin11(n);
        cout << result << '\n';
    }
}