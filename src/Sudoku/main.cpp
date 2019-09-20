#include "Read.h"
#include<cstdio>
int dimension;
int num;
//Sudoku.exe -m 9 -n 2 -i input.txt -o output.txt
int main(int argc, char* argv[])
{
	dimension = atoi(argv[2]);
	num = atoi(argv[4]);
	string file_in = argv[6];
	string file_out = argv[8];
	Read rd;
	rd.read_judge(argc, argv);
	rd.input(dimension, num, file_in);
	int jj = num;
	while (jj--)
	{		
		rd.equal(dimension);
		rd.DFS(0);
		rd.add();
	}
	rd.output(file_out,num);
	
	return 0;

}
