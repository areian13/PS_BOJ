#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> memory(n);
    for (int i = 0; i < n; i++)
        cin >> memory[i];

    int disk;
    cin >> disk;

    long long result = 0;
    for (int i = 0; i < n; i++)
        result += disk * (memory[i] / disk + (memory[i] % disk != 0));
    cout << result << '\n';
}