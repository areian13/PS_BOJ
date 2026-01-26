#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long SpinSum(int n)
{
    string s = to_string(n);
    int k = s.size();
    long long result = 0;
    for (int i = 0; i < k; i++)
    {
        result += stoi(s);
        s = s.back() + s;
        s.pop_back();
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    long long result = SpinSum(n);
    cout << result << '\n';
}