#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)

void findSolution (int sum , vector<int> &heso , vector<int> &tmpSol , int index , vector<vector<int>> &solutions, set<vector<int>> &uniqueSol)
{
	if (sum == 0)
	{
		vector <int> sortedSol = tmpSol;
		sort (sortedSol.begin() , sortedSol.end());
		if (uniqueSol.find(sortedSol) == uniqueSol.end())
		{
			uniqueSol.insert(sortedSol);
			solutions.push_back(tmpSol);
		}
	}
	if (sum < 0 || index == heso.size())
		return;
		
	for (int x = 0 ; x <= sum / heso[index] ; x++)
	{
		tmpSol[index] = x;
		int tmpSum  = sum - x * heso[index];
		findSolution(tmpSum , heso , tmpSol , index + 1 , solutions, uniqueSol);
	}	
}

vector <vector<int>> listOfSolutions (int sum , vector<int> &heso)
{
	vector <vector<int>> solutions;
	set<vector<int>> uniqueSol;
	vector <int> tmpSol (heso.size(),0);
	findSolution (sum , heso , tmpSol , 0 , solutions, uniqueSol);
	return solutions;
}
int main()
{
	int m , n;
	int a[10000];
	vector <int> heSo;
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 0 ; i < n ; i++)
	{
		cout << "Nhap he so a[" << i+1 <<"]: ";
		cin >> a[i];
		heSo.push_back(a[i]);
	}
	vector <vector<int>> solutions = listOfSolutions(m,heSo);
	cout << "Cac nghiem cua phuong trinh la: \n";
	for (vector<int> &x : solutions)
	{
		for(int i = 0 ; i < n ; i++)
			cout << "X" << i+1 << " = " << x[i] << ", ";
		cout<<endl;
	}
	return 0;	
}
