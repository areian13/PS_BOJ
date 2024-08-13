#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int m, k;
    cin >> m >> k;

    string result = (m % k == 0) ? "Yes" : "No";
    cout << result << '\n';
}