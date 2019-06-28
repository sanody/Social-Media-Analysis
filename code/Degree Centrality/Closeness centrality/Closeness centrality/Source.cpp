#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <iomanip>
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

int Short_Path(vector<vector<node1>>& G, vector<int> market, int SRC, int DES)
{
	int small = 0;
	int sum = 0;
	node1 L;
	node1 temp;

	/*for (int i = 0; i < G.size(); i++)
	{
		sort(G[i].begin(), G[i].end());
	}*/

	stack<node1> S;
	market[SRC] = 1;
	for (int i = 0; i < G[SRC].size(); i++)
	{
		//market[G[SRC][i].No_Node] = 1;

		S.push(G[SRC][i]);

	}


	do
	{
		L = S.top();
		S.pop();
		market[L.No_Node] = 1;
		sum += L.Size;
		if (L.No_Node == DES)
		{
			if (sum < small || small == 0)
			{
				small = sum;
				sum = 0;
			}

		}
		for (node1 M : G[L.No_Node])
		{
			if (market[M.No_Node] == 0)
			{
				//market[L.No_Node] = 1;
				/*G[i][L.No_Node].mark = true;*/
				S.push(M);


			}
		}


	} while (!S.empty());

	return small;
}


void short_path2(vector<vector<node1>>& Gragh, vector<int>& trac, int SREC)
{
	int sum = 0;
	node1 L;
	node1 temp;
	stack<node1> stack1;
	trac[SREC] = 0;

	for (node1 i : Gragh[SREC])
	{
		stack1.push(i);
		trac[i.No_Node] = i.Size;
	}
	do
	{
		L = stack1.top();
		stack1.pop();
		for (node1 M : Gragh[L.No_Node])
		{
			if (trac[M.No_Node] > (trac[L.No_Node] + M.Size))
			{
				trac[M.No_Node] = trac[L.No_Node] + M.Size;
				temp = M;
				temp.Size = L.No_Node + M.Size;
				stack1.push(M);
			}
		}

	} while (!stack1.empty());

}
void main()
{
	int A, Num, pos = 0;
	long M, count, N;
	node1 B, A1;
	int Sum = 0;
	double result = 0;
	cin >> N >> M;
	vector<vector<node1>> Gragh(N, vector<node1>());
	vector<int> mark(N);

	count = M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B.No_Node >> B.Size;
		A1.No_Node = A;
		A1.Size = B.Size;
		Gragh[A].push_back(B);
		Gragh[B.No_Node].push_back(A1);
		mark[A] = 2500028;

	}

	for (int i = 0; i < Gragh.size(); i++)
	{
		sort(Gragh[i].begin(), Gragh[i].end());

	}

	for (int i = 0; i < Gragh.size(); i++)
	{
		Sum = 0;
		short_path2(Gragh, mark, i);
		for (int j = 0; j < mark.size(); j++)
		{
			Sum += mark[j];
			mark[j] = 2515222;
		}
		result = (double)(N - 1) / (double)(Sum);
		cout << setprecision(17) << result << "\n";
	}

	
	
}







