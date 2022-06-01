// Inversion.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int inversion = 0;
void Merge(int* A, int first, int last, int n)
{
	int middle, start, final, j;
	int* mas = new int[n];
	middle = (first + last) / 2; //вычисление среднего элемента
	start = first; //начало левой части
	final = middle + 1; //начало правой части
	for (j = first; j <= last; j++) //выполнять от начала до конца
		if ((start <= middle) && ((final > last) || (A[start] < A[final])))
		{
			mas[j] = A[start];
			start++;
		}
		else
		{
			mas[j] = A[final];
			final++;
			inversion +=middle-start+1;
		}
	//возвращение результата в список
	for (j = first; j <= last; j++) A[j] = mas[j];
	delete[]mas;
};
//рекурсивная процедура сортировки
void MergeSort(int* A, int first, int last, int n)
{
	{
		if (first < last)
		{
			MergeSort(A, first, (first + last) / 2, n); //сортировка левой части
			MergeSort(A, (first + last) / 2 + 1, last, n); //сортировка правой части
			Merge(A, first, last, n); //слияние двух частей
		}
	}
};

int getInvCount(int *A, int n)
{
	int counter = 0;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (A[i] > A[j])
			{
				counter++;
			}
		}
	}
	return counter;
}


int main()
{
	setlocale(LC_ALL, "Rus");
	int i, n;
	std::cout << "Размер массива > "; std::cin >> n;
	int* A = new int[n];
	for (i = 0; i < n; i++)
	{
		std::cout << i+1 << " элемент > "; std::cin >> A[i];
	}
	int inv = getInvCount(A, n);
	MergeSort(A, 0, n-1, n); //вызов сортирующей процедуры
	std::cout << "Упорядоченный массив: "; //вывод упорядоченного массива
	for (i = 0; i < n; i++) 
		std::cout << A[i] << " ";


	std::cout << "\nInversions:" << inversion << "\nCheck:" << inv;

	return 0;
}

//Посчитть количество инверсий в массиве (инверсия это неправленное положение элементов отноительно сортировки
//2 1 4 5 3 0                - 8 инверсий (2,1)(1,0)(4,0)(4,3)(5,3)(5,0)(2,0)(3,0) i<j A[i]>A[j] - инвер

//1 5 6 7 4 2 10 9 11 12