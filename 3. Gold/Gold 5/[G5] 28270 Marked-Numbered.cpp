#ifdef ONLINE_JUDGE
#define _128d  __int128
#else
#define _128d long long
#endif

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <limits.h>
#include <float.h>
#include <string.h>
#include <random>
#include <type_traits>

#define Endl << "\n"
#define endL << "\n" <<
#define Cout cout <<
#define COUT cout << "OUT: " <<
#define Cin cin >>
#define fspc << " "
#define spc << " " <<
#define Enter cout << "\n"
#define if if
#define elif else if
#define else else
#define For(n) for(int i = 0; i < n; i++)
#define Forj(n) for(int j = 0; j < n; j++)
#define Foro(n) for(int i = 1; i <= n; i++)
#define Forjo(n) for(int j = 1; j <= n; j++)
#define between(small, middle, big) (small < middle && middle < big)
#define among(small, middle, big) (small <= middle && middle <= big)
#define stoe(container) container.begin(), container.end()
#define lf(d) Cout fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI 3.14159265359

typedef long long LLONG;
typedef unsigned long long ULLONG;
typedef unsigned int UINT;

using namespace std;

template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T>>
{
};

struct Node
{
	int parentIndex;
	vector<Node*> children;
};

void DeleteTree(Node* root)
{
	for (Node* child : root->children)
		DeleteTree(child);
	delete root;
}

Node* BuildTree(vector<int>& indices)
{
	int n = indices.size() - 1;
	vector<Node*> nodes(n + 1);
	nodes[0] = new Node({ 0,{} });

	Foro(n)
	{
		nodes[i] = new Node();

		if (indices[i - 1] + 1 == indices[i])
		{
			nodes[i - 1]->children.push_back(nodes[i]);
			nodes[i]->parentIndex = i - 1;
		}
		elif(indices[i - 1] >= indices[i])
		{
			int idx = i - 1;
			while (indices[idx] != indices[i])
				idx--;

			int parentIndex = nodes[idx]->parentIndex;
			nodes[parentIndex]->children.push_back(nodes[i]);
			nodes[i]->parentIndex = parentIndex;
		}
		else
		{
			DeleteTree(nodes[0]);
			Cout -1 Endl;
			exit(0);
		}
	}
	return nodes[0];
}

void AssignNumbers(Node* node, int cnt, bool isFirst = true)
{
	if (!isFirst)
		Cout cnt fspc;

	For(node->children.size())
		AssignNumbers(node->children[i], i + 1, false);
}

int main()
{
	FastIO;

	int c;
	Cin c;

	vector<int> indices(c + 1);
	Foro(c)
		Cin indices[i];

	Node* root = BuildTree(indices);
	AssignNumbers(root, 0);

	DeleteTree(root);
}
