#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string message;
    cin >> message;

    string result = "";
    int n = message.size();
    for (int i = 0; i < n; i += (message[i] - 'A' + 1))
        result += message[i];
    cout << result << '\n';
}