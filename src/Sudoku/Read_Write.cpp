
#include "Read.h"
#include<string>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
bool sign;
//Sudoku.exe -m 9 -n 2 -i input.txt -o output.txt
//argv[0]=filename
int Read::read_judge(int argc, char* argv[])
{
	if (argc != 9)
	{
		cout << "������������";//Error exp:Sudoku.exe -m 9 -n 2 -i input.txt -o 
		return 1;
	}
	if ((argv[2][0]<'3' || argv[2][0]>'9') || (argv[4][0]<'0' || argv[4][0]>'9'))
	{
		cout << "����ֵ���Ϸ���";//Error exp:Sudoku.exe -m cvds -n fd -i input.txt -o output.txt
		return 1;
	}
	if ((argv[1][1] != 'm') || (argv[3][1] != 'n'))
	{
		cout << "������ʽ����";//Error exp:Sudoku.exe -df 9 -n 2 -xbcdf input.txt -o output.txt
		return 1;
	}
	return 0;
}
void Read::input(int dimension, int num, string file_in)
{
	ifstream infile(file_in);
	char sudo[100][9][9];
	for (int k = 0; k < num; k++)
	{
		for (int i = 0; i < dimension; i++)
		{
			for (int j = 0; j < dimension; j++)
			{
				infile >> sudo[k][i][j];

				temp[k][i][j] = sudo[k][i][j] - '0';//��"input.txt"���������������temp
			}

		}
	}
}
bool Read::Check(int n, int key)
{
	int col = n % dimen;//������
	int	row = n / dimen;//������
	for (int i = 0; i < dimen; i++)
	{
		if (temp[count][row][i] == key)//�������ȷ��
			return false;
	}
	for (int i = 0; i < dimen; i++)
	{
		if (temp[count][i][col] == key)//�������ȷ��
			return false;
	}
	if (dimen == 3 || dimen == 5 || dimen == 7)
	{
		//3��5��7����ֻ���ж������еĺϷ���
		return true;
	}
	switch (dimen)
	{                         //��������������ȡ����ǰ���ڹ�����������꣬���������ڸ���
	case 4: {
		int x = n / 4 / 2 * 2;
		int y = n % 4 / 2 * 2;
		for (int i = x; i < x + 2; i++)
		{
			for (int j = y; j < y + 2; j++)
			{
				if (temp[count][i][j] == key)
					return false;
			}
		}break;
	}
	case 6: {
		int x = n / 6 / 2 * 2;
		int y = n % 6 / 3 * 3;
		for (int i = x; i < x + 2; i++)
		{
			for (int j = y; j < y + 3; j++)
			{
				if (temp[count][i][j] == key)
					return false;
			}
		}break;
	}
	case 8: {
		int x = n / 8 / 4 * 4;
		int y = n % 8 / 2 * 2;
		for (int i = x; i < x + 4; i++)
		{
			for (int j = y; j < y + 2; j++)
			{
				if (temp[count][i][j] == key)
					return false;
			}
		}break;

	}
	case 9: {
		int x = n / 9 / 3 * 3;
		int y = n % 9 / 3 * 3;
		for (int i = x; i < x + 3; i++)
		{
			for (int j = y; j < y + 3; j++)
			{
				if (temp[count][i][j] == key)
					return false;
			}
		}break;
	}
	}

	return true;
}
void Read::equal(int dimension)
{
	dimen = dimension;      //����������ֵ�������ڱ���dimen
	sign = false;           //�����µ�һ����������ʱ��sign�жϷ���Ϊfalse
}
void Read::output(string file_out, int num)
{
	ofstream outfile(file_out);
	for (int k = 0; k < num; k++)
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
void Read::DFS(int n)                              //������⣬��ʵ���ǵݹ������ӣ�0��0��λ�ÿ�ʼ���б����������б�����
{                                                  //n��ʾ���ӵ�λ�ã�0 <= n <dimen*dimen 

	if (n == dimen * dimen)
	{                                              //�������и��Ӻ��ǳɹ����˳�
		sign = true;

		return;
	}
	if (temp[count][n / dimen][n % dimen] != 0)    //��λ��������������
	{
		DFS(n + 1);
	}
	else
	{
		for (int i = 1; i <= dimen; i++)            //��1 - dimen���������֤
		{
			if (Check(n, i) == true)             
			{
				temp[count][n / dimen][n % dimen] = i; //��i�ڸ�λ�úϷ�������
				DFS(n + 1);                            //������һ��λ�õ���֤
				if (sign == true)
				{
					return;
				}
				temp[count][n / dimen][n % dimen] = 0;//�����޽Ⲣ���ص�ǰλ�ã���ԭ�ȸ�ֵ��i��գ�������һ������������������
			}
		}
	}

}
void Read::add()
{
	count++;
}

