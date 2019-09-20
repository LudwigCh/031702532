#include "Read.h"
#include<string>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<fstream>
bool sign;
//Sudoku.exe -m 9 -n 2 -i input.txt -o output.txt
//argv[0]=filename
void Read::read_judge(int argc, char* argv[]) 
{
	
}
void Read::read_init(int dimension, int num, string file_in)
{
	char sudo[9][9];
	ifstream infile(file_in);
	
		for (int i = 0; i < dimension; i++)
		{
			for (int j = 0; j < dimension; j++)
			{
				infile >> sudo[i][j];
				temp[i][j] = sudo[i][j] - '0';
			}
		}
}
bool Read::Check(int n, int key)
{
	for (int i = 0; i < 9; i++)
	{
		int j = n / 9;
		if (temp[j][i] == key) 
			return false;
	}
	for (int i = 0; i < 9; i++)
	{
		int j = n % 9;
		if (temp[i][j] == key)
			return false;
	}
	int x = n / 9 / 3 * 3;
	int y = n % 9 / 3 * 3;
	for (int i = x; i < x + 3; i++)
	{
		for (int j = y; j < y + 3; j++)
		{
			if (temp[i][j] == key) 
				return false;
		}
	}
	return true;
}
void Read::equal(int dimen)
{
	dimension = dimen;
}
void Read::output()
{
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			cout << temp[i][j];
		}
		cout << "\n";
	}
}
void Read::DFS(int n)
{
	if (n > 80)
	{
		sign = true;
	
		return ;
	}	
	if (temp[n / 9][n % 9] != 0)
	{
		DFS(n + 1);
	}
	else
	{
		for (int i = 1; i <= 9; i++)
		{
			if (Check(n, i) == true)
			{
				temp[n / 9][n % 9] = i;
				DFS(n + 1);
				if (sign == true) 
					 return;
				temp[n / 9][n % 9] = 0;
			}
		}
	}

}

