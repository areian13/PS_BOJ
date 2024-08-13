#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int w, l, h;
    cin >> w >> l >> h;

    string result = (min(w, l) / h >= 2) ? "good" : "bad";
    cout << result << '\n';
}