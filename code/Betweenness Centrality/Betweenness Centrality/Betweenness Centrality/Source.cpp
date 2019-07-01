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
	return ((l.No_Node == r.No_Node) && (l.Size == r.Size));
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
	set<node1> stack1;
	//trac[SREC].first = 0;
	check[SREC].second = 0;
	pass[node] = 0;
	vector< pair<int, int>> trac(Gragh.size(), pair<int, int>(200182, 0));
	trac[SREC].first = 0;
	trac[SREC].second = 0;

	for (node1 i : Gragh[SREC])
	{
		stack1.insert(i);
		trac[i.No_Node].first = i.Size;
		if (check[i.No_Node].first == i.Size)
		{
			check[i.No_Node].second += 1;

		}
	}
	do
	{
		L = *stack1.begin();
		stack1.erase(stack1.begin());
		for (node1 M : Gragh[L.No_Node])
		{
			if (trac[M.No_Node].first > (trac[L.No_Node].first + M.Size))
			{

				trac[M.No_Node].first = trac[L.No_Node].first + M.Size;
				temp = M;
				temp.Size = trac[L.No_Node].first + M.Size;
				//stack1.push(M);
				stack1.insert(temp);
			}
			if (check[M.No_Node].first == (trac[L.No_Node].first + M.Size))
			{
				if (L.No_Node == node) {
					pass[M.No_Node] += 1;
				}
				if (pass[L.No_Node] >= 1)
				{
					pass[M.No_Node] += pass[L.No_Node];
				}


				check[M.No_Node].second += 1;
				M.Size = trac[M.No_Node].first;
				stack1.insert(M);


			}
			//if (trac[M.No_Node].first > (trac[L.No_Node].first + M.Size))
			//{
			//	if (check[M.No_Node].first == trac[L.No_Node].first + M.Size)
			//	{
			//		/*if (L.No_Node == node)
			//			pass[M.No_Node] = 1;
			//	}
			//		else*/
			//		pass[M.No_Node] = pass[L.No_Node];
			//	}
			//	

			//	trac[M.No_Node].first = trac[L.No_Node].first + M.Size;
			//	/*temp = M;
			//	temp.Size = trac[L.No_Node].first + M.Size;*/
			//	stack1.push(M);
			//	check[M.No_Node].second = 1;
			//}
			//else if (check[M.No_Node].first == trac[L.No_Node].first + M.Size)
			//{
			//	/*if (L.No_Node == node)
			//		pass[M.No_Node]+= 1;
			//	else*/
			//	    pass[M.No_Node] += pass[L.No_Node];
			//	check[M.No_Node].second +=1;

			//	M.Size = trac[M.No_Node].first;
   //           stack1.push(M);
			//}
		}

	} while (!stack1.empty());

}
void main()
{
	int A, Num, index = 0;
	long M, N;
	node1 B, A1;
	double result = 0;
	cin >> N >> M;

	vector<vector<node1>> Gragh(N, vector<node1>());



	for (int i = 0; i < M; i++)
	{
		cin >> A >> B.No_Node >> B.Size;
		A1.No_Node = A;
		A1.Size = B.Size;
		Gragh[A].push_back(B);
		Gragh[B.No_Node].push_back(A1);

	}

	for (int i = 0; i < Gragh.size(); i++)
	{
		sort(Gragh[i].begin(), Gragh[i].end());
	}
	vector < pair <int, int>> mark(N, pair<int, int>(2500028, 0));
	vector<int> pass(N, 0);
	SHORT(Gragh, mark, 0);
	short_path2(Gragh, mark, 0, 3, pass);
	cout << "hello";
	//for (int j = 0; j < Gragh.size(); j++)
	//{
	//	result = 0;
	//	index = 0;
	//	for (int i = 0; i < Gragh.size(); i++)
	//	{
	//		if (i != j)
	//		{
	//			vector < pair <int, int>> mark(N,pair<int,int>(2500028,1));
	//			vector<int> pass(N,0);
	//			SHORT(Gragh, mark, i);
	//			short_path2(Gragh, mark, i, j, pass);
	//			for (int k = i; k < Gragh.size(); k++)
	//			{
	//				if (k != i)
	//					result += (double( pass[k]) / double( mark[k].second));
	//				// << "i  " << i << "   k" << k << "   pass " << pass[k] << "   mark ";
	//				//cout << mark[k].second << "\n";
	//			}
	//			//index++;
	//		}
	//	}
	//	cout << setprecision(12) << result << "\n";
	//}


}