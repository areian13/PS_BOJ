#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;

        sum += s;
    }

    string result = (sum == 0 ? "Stay" : (sum > 0 ? "Right" : "Left"));
    cout << result << '\n';
}