#include "Read.h"
#include<cstdio>
int dimension;//�����������
int num;//���������
//Sudoku.exe -m 9 -n 2 -i input.txt -o output.txt
int main(int argc, char* argv[])
{
	Read rd;
	if (rd.read_judge(argc, argv))//�ж������в����Ƿ�����
	{
		return 0;
	}                                /* ���� */
	dimension = atoi(argv[2]);  //9->dimension
	num = atoi(argv[4]);        //2->num
	string file_in = argv[6];   //"input.txt"->file_in
	string file_out = argv[8];  //"ouput.txt"->file_out

	rd.input(dimension, num, file_in);
	int jj = num;
	while (jj--)
	{
		rd.equal(dimension);
		rd.DFS(0);
		rd.add();
	}
	rd.output(file_out, num);

	return 0;

}
