#include <iostream>
#include<string>
#include<fstream>
struct coo
{
	int a, b;
};
char returnVal(int x)
{
	x=x+87;
    return (char)x;
}
using namespace std;
int main()
{
	ifstream input("input.txt");
	string d[25];
	int m = 0;
	while (!input.eof())
	{
		getline(input, d[m], '\n');
		m++;
	}
	int n = d[0].size();
	int **A=new int*[n];
	m--;
	for (int r = 0; r < m; r++)
	{
		cout <<d[r] << "\n";
		A[r] = new int[n];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (d[i][j] == ' ')
				A[i][j] = -2;
			else
				A[i][j] = -1;
		}
	}
