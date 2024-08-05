#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string ucf;
    cin >> ucf;

    int idxU = 0;
    while (ucf[idxU] != 'U')
        idxU++;

    int idxF = ucf.size() - 1;
    while (ucf[idxF] != 'F')
        idxF--;

    for (int i = 0; i < idxU; i++)
        ucf[i] = '-';
    for (int i = idxU + 1; i < idxF; i++)
        ucf[i] = 'C';
    for (int i = idxF + 1; i < ucf.size(); i++)
        ucf[i] = '-';
    cout << ucf << '\n';
}
