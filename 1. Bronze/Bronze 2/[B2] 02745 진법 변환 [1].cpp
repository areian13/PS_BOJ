#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string n;
    int b;
    cin >> n >> b;

    int result = stoi(n, nullptr, b);
    cout << result << '\n';
}