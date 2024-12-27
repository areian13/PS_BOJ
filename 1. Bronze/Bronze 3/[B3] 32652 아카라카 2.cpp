#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    string result = "AKA";
    for (int i = 0; i < n; i++)
        result += "RAKA";
    cout << result << '\n';
}