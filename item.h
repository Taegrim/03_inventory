#pragma once
#include "common.h"

class Item 
{
public:
	Item();
	Item(const std::string& name, int price);
	~Item() = default;

	bool operator<(const Item& other) const;

	void PrintInfo() const;
	void Clear();

	int GetPrice() const;
	const std::string& GetName() const;

private:
	std::string name;
	int price;
};

