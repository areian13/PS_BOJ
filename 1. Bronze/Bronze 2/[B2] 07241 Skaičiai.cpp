#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s(3, '\0');
    for (int i = 0; i < 3; i++)
        cin >> s[i];
    sort(s.begin(), s.end());

    string x;
    cin >> x;

    int result = 0;
    do
    {
        result++;
        if (s == x)
            break;
    } while (next_permutation(s.begin(), s.end()));
    cout << result << '\n';
}