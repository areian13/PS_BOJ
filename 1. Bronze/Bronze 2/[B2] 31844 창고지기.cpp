#include <iostream>
#include <string>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    cin >> s;

    int i = s.find('@');
    int j = s.find('#');
    int k = s.find('!');

    if (i < j && j < k || i > j && j > k)
        cout << abs(i - k) - 1 << '\n';
    else
        cout << -1 << '\n';
}