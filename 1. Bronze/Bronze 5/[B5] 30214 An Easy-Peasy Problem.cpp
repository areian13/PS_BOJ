#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int s1, s2;
    cin >> s1 >> s2;

    char result = (s1 * 2 >= s2) ? 'E' : 'H';
    cout << result << '\n';
}