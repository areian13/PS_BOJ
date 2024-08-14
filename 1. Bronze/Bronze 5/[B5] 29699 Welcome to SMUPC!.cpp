#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string label = "WelcomeToSMUPC";

    int n;
    cin >> n;

    char result = label[(n - 1) % label.size()];
    cout << result << '\n';
}