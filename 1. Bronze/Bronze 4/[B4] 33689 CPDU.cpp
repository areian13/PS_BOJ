#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        result += (s[0] == 'C');
    }
    cout << result << '\n';
}