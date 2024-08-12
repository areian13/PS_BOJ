#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<int, 2> result = { n,1 };
    cout << result[0] << '\n' << result[1] << '\n';
}