#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void SumRows(int** a, const int rowCount, const int colCount, int rowNo, int& S, int& k);
void SumRow(int** a, const int rowNo, const int colCount, int colNo, int& S, int& k);

int main()
{
	srand((unsigned)time(NULL));

	int Low = -42;
	int High = 51;

	int rowCount = 7;
	int colCount = 6;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High, 0, 0);
	Print(a, rowCount, colCount, 0, 0);
	int S = 0;
	int k = 0;
	SumRows(a, rowCount, colCount, 0, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(a, rowCount, colCount, 0, 0);
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}

void SumRow(int** a, const int rowNo, const int colCount, int colNo, int& S, int& k)
{
	if (!(a[rowNo][colNo] > 0) && !(a[rowNo][colNo] % 5 == 0))
	{
		S += a[rowNo][colNo];
		a[rowNo][colNo] = 0;
		k++;
	}
	if (colNo < colCount - 1) {
		SumRow(a, rowNo, colCount, colNo + 1, S, k);
	}
}
void SumRows(int** a, const int rowCount, const int colCount, int rowNo, int& S, int& k)
{
	SumRow(a, rowNo, colCount, 0, S, k);
	if (rowNo < rowCount - 1)
	{
		SumRows(a, rowCount, colCount, rowNo + 1, S, k);
	}
}
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
}
void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}