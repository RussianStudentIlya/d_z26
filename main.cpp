#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include "sum_of_array_elements.h"
using namespace std;



int main()
{
	///���������� ���� ���������� = 14

	setlocale(LC_ALL, "rus");

	while (true)
	{
		int N = 0, M = 0; // N - ������ �������, M - ���������� ������, �� ������� ����� ������ ������
		char oper;

		cout << "������ ��������� ����� ��������: ";
		cin >> N;
		cout << "��������� ������ �������� = " << N << endl;

		cout << "------------------" << endl;

		cout << "���������� ������, �� ������� ����� ������ ������: ";
		cin >> M;
		cout << "������ ������� �� " << M << " ������" << endl;

		if (N % M == 0)
		{
			cout << "------------------" << endl;

			sum_of_array_elements sum_elements = sum_of_array_elements(N, M);

			// ����� ��������� �������� ������� ������������ �� ������
			vector<int> list_sum_elements_vector = sum_elements.sum_elements_vector_using_Threads();

			sum_elements.get_sum_all_elements_vector(list_sum_elements_vector);

			cout << "���������� ���������� ��������� y(��) / n(���) ?: ";
			cin >> oper;
			cout << endl;

			if (oper == 'n') break; /// ������� ���������� ���������
		}
		else
		{
			cout << "------------------" << endl;

			cout << "��� N = " << N << "; M = " << M << " ������ �� ������� �� ������ �����, ������� ������� ������ ��������!!!" << endl;
		}
	}

	return 0;
}