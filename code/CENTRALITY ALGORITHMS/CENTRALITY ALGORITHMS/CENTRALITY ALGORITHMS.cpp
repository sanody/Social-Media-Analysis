#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <iomanip>
#include <algorithm>
#include <fstream>
using namespace std;

struct node1
{
	int No_Node;
	int Size;

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


	stack<node1> S;
	market[SRC] = 1;
	for (int i = 0; i < G[SRC].size(); i++)
	{

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

				S.push(M);


			}
		}


	} while (!S.empty());

	return small;
}

void SHORT(vector<vector<node1>>& Gragh, vector<pair<int, int>>& trac, int SREC)
{

	node1 L;
	stack<node1> stack1;
	trac[SREC].first = 0;



	for (node1 i : Gragh[SREC])
	{
		stack1.push(i);
		trac[i.No_Node].first = i.Size;
	}
	do
	{
		L = stack1.top();
		stack1.pop();
		for (node1 M : Gragh[L.No_Node])
		{
			if (trac[M.No_Node].first > (trac[L.No_Node].first + M.Size))
			{

				trac[M.No_Node].first = trac[L.No_Node].first + M.Size;
				stack1.push(M);
			}

		}

	} while (!stack1.empty());

}

void short_path2(vector<vector<node1>>& Gragh, vector< pair <int, int>>& check, int SREC, int node, vector<int>& pass)
{
	int sum = 0;
	int count = 0;
	node1 L;
	node1 temp;
	stack<node1> stack1;

	check[SREC].second = 0;
	pass[node] = 0;
	vector< pair<int, int>> trac(Gragh.size(), pair<int, int>(200182, 0));
	trac[SREC].first = 0;
	trac[SREC].second = 0;

	for (node1 i : Gragh[SREC])
	{
		stack1.push(i);
		trac[i.No_Node].first = i.Size;
	}
	do
	{
		L = stack1.top();
		stack1.pop();
		for (node1 M : Gragh[L.No_Node])
		{
			if (trac[M.No_Node].first > (trac[L.No_Node].first + M.Size))
			{
				if (check[M.No_Node].first == trac[L.No_Node].first + M.Size)

					if (L.No_Node == node || trac[L.No_Node].second == 1)
					{
						trac[M.No_Node].second = 1;
						pass[M.No_Node] += 1;
					}
					else
						trac[M.No_Node].second = 0;

				trac[M.No_Node].first = trac[L.No_Node].first + M.Size;
				temp = M;
				temp.Size = trac[L.No_Node].first + M.Size;
				stack1.push(temp);
				check[M.No_Node].second = 1;
			}
			else if (check[M.No_Node].first == trac[L.No_Node].first + M.Size)
			{
				if (L.No_Node == node || trac[L.No_Node].second == 1)
				{
					trac[M.No_Node].second = 1;
					pass[M.No_Node] += 1;
				}
				else
					trac[M.No_Node].second = 0;


				check[M.No_Node].second += 1;
				M.Size = trac[M.No_Node].first;

				stack1.push(M);
			}
		}
		//	trac[L.No_Node].second == 0;
	} while (!stack1.empty());

}



/////////////////////////////////
void main()
{
	int A, Num, index = 0;
	long M, N;
	node1 B, A1;
	int Sum = 0;
	int Number = 0;
	double result = 0;

	cin >> N >> M;
	vector<vector<node1>> Gragh(N, vector<node1>());
	vector < pair <int, int>> mark(N, pair<int, int>(2500028, 1));
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B.No_Node >> B.Size;

		A1.No_Node = A;
		A1.Size = B.Size;
		Gragh[A].push_back(B);
		Gragh[B.No_Node].push_back(A1);

	}
	cin >> Num;
	cout << endl << "Result" << endl;

	for (int i = 0; i < Gragh.size(); i++)
	{
		sort(Gragh[i].begin(), Gragh[i].end());
	}

	if (Num == 1)
	{
		fstream file;
		file.open("example.txt");
		for (int i = 0; i < Gragh.size(); i++)
		{
			cout << Gragh[i].size() << "\n";
		}

	}
	else if (Num == 2)
	{

		for (int i = 0; i < Gragh.size(); i++)
		{
			Sum = 0;
			SHORT(Gragh, mark, i);
			for (int j = 0; j < mark.size(); j++)
			{
				Sum += mark[j].first;
				mark[j].first = 2515222;
			}
			result = (double)(N - 1) / (double)(Sum);
			cout << setprecision(12) << result << "\n";

		}

	}
	else if (Num == 3)
	{

		for (int j = 0; j < Gragh.size(); j++)
		{
			result = 0;
			index = 0;
			for (int i = 0; i < Gragh.size(); i++)
			{
				if (i != j)
				{
					vector < pair <int, int>> mark(N, pair<int, int>(2500028, 1));
					vector<int> pass(N, 0);
					SHORT(Gragh, mark, i);
					short_path2(Gragh, mark, i, j, pass);
					for (int k = i; k < Gragh.size(); k++)
					{
						if (k != i)
							result += (double(pass[k]) / double(mark[k].second));

					}

				}
			}
			cout << setprecision(12) << result << "\n";

		}

	}

}