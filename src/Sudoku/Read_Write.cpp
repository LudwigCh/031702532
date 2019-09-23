
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
		cout << "参数个数错误！";//Error exp:Sudoku.exe -m 9 -n 2 -i input.txt -o 
		return 1;
	}
	if ((argv[2][0]<'3' || argv[2][0]>'9') || (argv[4][0]<'0' || argv[4][0]>'9'))
	{
		cout << "输入值不合法！";//Error exp:Sudoku.exe -m cvds -n fd -i input.txt -o output.txt
		return 1;
	}
	if ((argv[1][1] != 'm') || (argv[3][1] != 'n'))
	{
		cout << "参数格式错误！";//Error exp:Sudoku.exe -df 9 -n 2 -xbcdf input.txt -o output.txt
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

				temp[k][i][j] = sudo[k][i][j] - '0';//从"input.txt"读入数独矩阵存入temp
			}

		}
	}
}
bool Read::Check(int n, int key)
{
	int col = n % dimen;//列坐标
	int	row = n / dimen;//行坐标
	for (int i = 0; i < dimen; i++)
	{
		if (temp[count][row][i] == key)//检查行正确性
			return false;
	}
	for (int i = 0; i < dimen; i++)
	{
		if (temp[count][i][col] == key)//检查列正确性
			return false;
	}
	if (dimen == 3 || dimen == 5 || dimen == 7)
	{
		//3，5，7宫格只需判断行与列的合法性
		return true;
	}
	switch (dimen)
	{                         //根据所给宫格定义取出当前所在宫格的左上坐标，并遍历宫内格子
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
	dimen = dimension;      //将数独类型值赋给类内变量dimen
	sign = false;           //计算新的一个数独矩阵时将sign判断符置为false
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
void Read::DFS(int n)                              //深搜求解，其实就是递归啦。从（0，0）位置开始逐列遍历后再逐行遍历。
{                                                  //n表示格子的位置，0 <= n <dimen*dimen 

	if (n == dimen * dimen)
	{                                              //走完所有格子后标记成功并退出
		sign = true;

		return;
	}
	if (temp[count][n / dimen][n % dimen] != 0)    //该位置已有数，跳过
	{
		DFS(n + 1);
	}
	else
	{
		for (int i = 1; i <= dimen; i++)            //对1 - dimen逐个填入验证
		{
			if (Check(n, i) == true)             
			{
				temp[count][n / dimen][n % dimen] = i; //数i在该位置合法，填入
				DFS(n + 1);                            //继续下一个位置的验证
				if (sign == true)
				{
					return;
				}
				temp[count][n / dimen][n % dimen] = 0;//后续无解并返回当前位置，将原先赋值的i清空，尝试下一个数并继续往后搜索
			}
		}
	}

}
void Read::add()
{
	count++;
}

