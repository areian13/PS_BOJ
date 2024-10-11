#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    string s = "";
    for (int i = 1; i <= n; i++)
        s += to_string(i);

    int result = s.find(to_string(n));
    cout << result + 1 << '\n';
}