#include "Read.h"
#include<string>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<fstream>
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
			cout << sudo[i][j];
		}
		cout << "\n";
	}
	/*for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			cout << sudo[i][j];
		}
	}*/

}

