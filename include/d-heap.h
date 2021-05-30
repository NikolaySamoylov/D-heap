#pragma once

#include <vector>

template<class T>
class  D_heap {
private:
	size_t d;
	vector<T> data;
	size_t size;
public:
	// окучивание
	void make_heap() 
	{
		for (int i = data.size() - 1; i >= 0; i--)
			diving(i);
	}
	// конструктор с параметрами
	D_heap(vector<T> d, size_t nd)
	{
		data = d;
		make_heap();
		d = nd;
		size = 0;
	}
	// конструктор копирования
	D_heap(const D_heap& h) 
	{
		data = h.data;
		d = h.d;
		size = h.size;
	}
	// поиск левого ребёнка
	size_t left_child(size_t i) 
	{	
		size_t lc = d * i + 1;
		if (lc <= size - 1)
			return lc;
		else 
			return 0;
	}
	// поиск правого ребёнка
	size_t right_child(size_t i) 
	{	
		size_t rc = d * i + d;
		if (rc <= size - 1)
			return rc;
		else 
			if (left_child(i))
				return (size - 1);
			else 
				return 0;
	}
	// поиск минимального ребёнка
	size_t min_сhild(size_t i) 
	{	
		size_t l = left_сhild(i), r = right_сhild(i);
		if (l == 0)
			return 0;
		int i_min = l, min = data[l];
		for (int i = l + 1; i <= r; i++)
			if (data[i] < min)
			{
				min = data[i];
				i_min = i;
			}
		return i_min;
	}
	// поиск родителя
	size_t parent(size_t i) 
	{ 
		if (i > 0)
			return ((i - 1) / d);
		else 
			return 0;
	}
	// погружение
	void diving(int i)
	{
		int j1 = i;
		int j2 = minChild(i);
		while (j2 != -1 && data[j1] > data[j2])
		{
			std::swap(j1, j2);
			j1 = j2;
			j2 = min_child(j1);
		}
	}
	// всплытие
	void emersion(int i) 
	{
		int j1 = i;
		int j2 = parent(i);
		while (j2 != -1 && data[j1] < data[j2]) {
			swap(j1, j2);
			j1 = j2;
			j2 = parent(j1);
		}
	}
	// вставка
	void insert(int i) 
	{
		heap.push_back(i);
		emersion(data.size() - 1);
		size++;
	}
	// получить минимальный элемент
	int get_min() 
	{
		if (size != 0)
			return heap[0];
		else 
			throw "D-Heap is empty!";
	}
	// удалить минимальный элемент
	void delete_min() 
	{
		std::swap(0, data.size() - 1);
		data.pop_back();
		diving(0);
	}
	// изменение веса узла i на delta
	void decreaseWeight(size_t i, T delta) 
	{
		data[i] -= delta;
		emersion(i);
	}
	// сортировка кучей
	void heap_sort() 
	{
		make_heap();
		size = data.size();
		for (int i = 0; i < data.size() - 1; i++) 
		{
			std::swap(0, size - 1);
			size--;
			diving(0);
		}
	}
};