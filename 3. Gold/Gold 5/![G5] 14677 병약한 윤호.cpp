#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;
    n *= 3;

    string bld = "BLD";
    vector<vector<int>> dist(2, vector<int>(n, -1));
    
}