#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int w, l;
    cin >> w >> l;

    int result = w * l;
    cout << result << '\n';
}