#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string a, b, c;
    cin >> a >> b >> c;

    string result = (a.find(c) != -1 && b.find(c) != -1 ? "YES" : "NO");
    cout << result << '\n';
}