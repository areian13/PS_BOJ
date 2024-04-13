#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 10'000
#define MIN -10'000

vector<int> QuadraticRoots(int a, int b)
{
    vector<int> result;
    for (int x = MIN; x <= MAX; x++)
    {
        if (x * x + 2 * a * x + b == 0)
            result.push_back(x);
    }
    return result;
}

int main()
{
    FastIO;

    int a, b;
    cin >> a >> b;

    vector<int> result = QuadraticRoots(a, b);
    for (int x : result)
        cout << x << ' ';
    cout << '\n';
}