#include "Read.h"
#include<string>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<fstream>
#include<cmath>
bool sign;
//Sudoku.exe -m 9 -n 2 -i input.txt -o output.txt
//argv[0]=filename
void Read::read_judge(int argc, char* argv[]) 
{
	
}
void Read::input(int dimension, int num, string file_in)
{
	ifstream infile(file_in);
	char sudo[100][9][9];
	for (int k = 0;k < num; k++)
	{
		for (int i = 0; i < dimension; i++)
		{
			for (int j = 0; j < dimension; j++)
			{
				infile >> sudo[k][i][j];

				temp[k][i][j] = sudo[k][i][j] - '0';
			}

		}
	}
}
bool Read::Check(int n, int key)
{
	int col = n % dimen;
	int	row = n / dimen;
	for (int i = 0; i < dimen; i++)
	{
		if (temp[count][row][i] == key) 
			return false;
	}
	for (int i = 0; i < dimen; i++)
	{
		if (temp[count][i][col] == key)
			return false;
	}
	if (dimen != 3 || dimen != 5 || dimen != 7)
	{
		
		if (dimen == 4 || dimen == 9)
		{
			int x = n / dimen / int(sqrt(dimen)) * int(sqrt(dimen));
			int y = n % dimen / int(sqrt(dimen)) * int(sqrt(dimen));
			for (int i = x; i < x + int(sqrt(dimen)); i++)
			{
				for (int j = y; j < y + int(sqrt(dimen)); j++)
				{
					if (temp[count][i][j] == key)
						return false;
				}
			}
		}
	}
	return true;
}
void Read::equal(int dimension)
{
	dimen = dimension;
	sign = false;
}
void Read::output(string file_out,int num)
{
	for (int i = 0; i < dimen; i++)
	{
		for (int j = 0; j < dimen; j++)
		{
			cout << temp[0][i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	ofstream outfile(file_out);
	for(int k = 0; k < num; k++)
	{
		for (int i = 0; i < dimen; i++)
		{
			for (int j = 0; j < dimen; j++)
			{
				outfile << temp[k][i][j] << " ";
			}
			outfile << "\n";
		}
		outfile << "\n";
	}
}
void Read::DFS(int n)
{

	if (n == dimen*dimen)
	{
		sign = true;
	
		return ;
	}	
	if (temp[count][n / dimen][n % dimen] != 0)
	{
		DFS(n + 1);
	}
	else
	{
		for (int i = 1; i <= dimen; i++)
		{
			if (Check(n, i) == true)
			{
				temp[count][n / dimen][n % dimen] = i;
				DFS(n + 1);
				if (sign == true)
				{
					return;
				}
				temp[count][n / dimen][n % dimen] = 0;
			}
		}
	}

}
void Read::add()
{
	count++;
}

