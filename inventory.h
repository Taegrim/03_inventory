#pragma once
#include "common.h"

template<typename T>
class Inventory 
{
public:
	Inventory(int capacity = 10) : size{ 0 } {
		if (capacity <= 0) {
			capacity = 1;
		}

		this->capacity = capacity;
		items = new T[this->capacity];
	}
	Inventory(const Inventory<T>& other) {
		capacity = other.capacity;
		size = other.size;
		items = new T[capacity];
		for (int i = 0; i < size; ++i) {
			items[i] = other.items[i];
		}
		std::cout << "인벤토리 복사 완료" << std::endl;
	}
	~Inventory() {
		if (items) {
			delete[] items;
		}
		items = nullptr;
	}

	void AddItem(const T& item) {
		if (size < capacity) {
			items[size] = item;
			++size;
		}
		else {
			Resize(capacity * 2);
			AddItem(item);
		}
	}
	void RemoveLastItem() {
		if (size > 0) {
			--size;
		}
		else {
			std::cout << "인벤토리가 비어있습니다!" << std::endl;
		}
	}
	void PrintAllItems() const {
		for (int i = 0; i < size; ++i) {
			items[i].PrintInfo();
		}
	}
	void Assign(const Inventory<T>& other) {
		if (this == &other) {	// 자기 자신 대입하면 처리 안하고 종료
			return;
		}

		if (items) {
			delete[] items;
		}
		items = nullptr;

		capacity = other.capacity;
		size = other.size;
		items = new T[capacity];
		for (int i = 0; i < size; ++i) {
			items[i] = other.items[i];
		}
		std::cout << "인벤토리 대입 완료" << std::endl;
	}
	void Resize(int capacity) {
		if (capacity <= 0) {
			capacity = 1;
		}

		// 기존 size보다 작은 값으로 resize 할 수 있음
		size = std::min(size, capacity);

		T* new_items = new T[capacity];

		for (int i = 0; i < size; ++i) {
			new_items[i] = items[i];
		}

		delete[] items;
		items = new_items;
		this->capacity = capacity;
	}
	void SortItems() {
		std::sort(items, items + size);
	}	


	int GetSize() const { return size; }
	int GetCapacity() const { return capacity; }

private:
	T* items;
	int capacity;
	int size;
};

