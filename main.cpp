#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include "sum_of_array_elements.h"
using namespace std;



int main()
{
	///Количество ядер процессора = 14

	setlocale(LC_ALL, "rus");

	while (true)
	{
		int N = 0, M = 0; // N - размер вектора, M - количество частей, на которые будет разбит вектор
		char oper;

		cout << "Вектор случайных чисел размером: ";
		cin >> N;
		cout << "Создается вектор размером = " << N << endl;

		cout << "------------------" << endl;

		cout << "Количество частей, на которые будет разбит вектор: ";
		cin >> M;
		cout << "Вектор разбить на " << M << " частей" << endl;

		if (N % M == 0)
		{
			cout << "------------------" << endl;

			sum_of_array_elements sum_elements = sum_of_array_elements(N, M);

			// Сумма элементов входного вектора разделенного на потоки
			vector<int> list_sum_elements_vector = sum_elements.sum_elements_vector_using_Threads();

			sum_elements.get_sum_all_elements_vector(list_sum_elements_vector);

			cout << "Продолжить выполнение программы y(да) / n(нет) ?: ";
			cin >> oper;
			cout << endl;

			if (oper == 'n') break; /// Условие завершения программы
		}
		else
		{
			cout << "------------------" << endl;

			cout << "При N = " << N << "; M = " << M << " вектор не делится на равные части, введите входные данные повторно!!!" << endl;
		}
	}

	return 0;
}