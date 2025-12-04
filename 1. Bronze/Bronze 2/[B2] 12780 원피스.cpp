#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string h, n;
    cin >> h >> n;

    int result = 0;
    int l = h.size() - n.size() + 1;
    for (int i = 0; i < l; i++)
        result += (h.substr(i, n.size()) == n);
    cout << result << '\n';
}