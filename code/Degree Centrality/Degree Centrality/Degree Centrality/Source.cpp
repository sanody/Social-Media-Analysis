#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

struct node1
{
	int No_Node;
	int Size;
	//bool mark = false;
};
bool operator<(const node1& l, const node1& r)
{
	return r.Size < l.Size;
}
bool operator==(const node1& l, const node1& r)
{
	return l.No_Node == r.No_Node;
}

void main()
{
	int A, Num;
	long M, count, N;
	node1 B, A1;
	cin >> N >> M;
	vector<vector<node1>> Gragh(N, vector<node1>());


	count = M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B.No_Node >> B.Size;
		A1.No_Node = A;
		A1.Size = B.Size;
		Gragh[A].push_back(B);
		Gragh[B.No_Node].push_back(A1);
	}

	////////////--------------------------Degree Centrality---////////

	for (int i = 0; i < Gragh.size(); i++)
	{
		cout << Gragh[i].size() << "\n";

	}

}