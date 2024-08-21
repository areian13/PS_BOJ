#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, c;
    cin >> a >> b >> c;

    vector<int> cocktails;
    cocktails.push_back(a);
    cocktails.push_back(b);
    cocktails.push_back(c);
    cocktails.push_back(a * b);
    cocktails.push_back(b * c);
    cocktails.push_back(c * a);
    cocktails.push_back(a * b * c);

    sort(cocktails.begin(), cocktails.end(),
        [](const int a, const int b)
        {
            if ((a % 2) != (b % 2))
                return (a % 2) < (b % 2);
            return a < b;
        }
    );

    int result = cocktails.back();
    cout << result << '\n';
}