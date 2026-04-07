#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    while (to_string(n << result).size() == to_string(n << (result + 1)).size())
        result++;
    cout << result << '\n';
}