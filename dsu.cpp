#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N];
int size[N];

//make -> create an independent node.
void make(int v) {

	parent[v] = v;
	size[v] = 1;
}

//find -> returns parent of the group in which they are, if they are independent they return themself.
int find(int v) {

	if (v == parent[v])
		return v;

	return parent[v] = find(parent[v]);
}

//union -> add two element in a single group.
void Union(int a, int b) {

	a = find(a);
	b = find(b);

	if (a != b) {
		//UNION BY SIZE
		if (size[a] < size[b])
			swap(a, b);
		parent[b] = a;
		size[a] += size[b];
	}
}

int main() {

	int n, k;
	cin >> n >> k;

	for (int i = 1 ; i <= n ; i++)
		make(i);

	while (k--) {
		int u, v;
		cin >> u >> v;
		Union(u, v);
	}

	int connected_cmp = 0;
	for (int i = 1 ; i <= n ; i++) {

		if (parent[i] == i)
			connected_cmp++;
	}
	cout << connected_cmp << endl;
}
