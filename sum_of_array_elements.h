#pragma once
#include <vector>
#include <iostream>
#include <thread>
#include <ctime>
#include <algorithm>
using namespace std;

class sum_of_array_elements
{
private:
	int _sizeElementsList; // ко-во элементов в списке
	int _numberThreads; //количество потоков

	vector<int> _listElements; // список элементов
	vector<int> _listSumElements; // Сумма элементов входного вектора разделенного на потоки

	void calc_sum_part_vector(int start_index, int stop_index); // вычисление суммы элементов вектора

public:
	sum_of_array_elements(const int& sizeElementsList, const int& numberThreads);
	~sum_of_array_elements() = default;

	vector<int> sum_elements_vector_using_Threads(); // Вычисление суммы элементов вектора в потоке

	void get_sum_all_elements_vector(vector<int> sum_elements); //Сумма элементов вектора 

};

