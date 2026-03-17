#include "item.h"

Item::Item() : name{ "" }, price{ 0 }
{
}

Item::Item(const std::string& name, int price) : name{ name }, price{ price }
{
}

bool Item::operator<(const Item& other) const
{
	return this->price < other.price;
}

void Item::PrintInfo() const
{
	std::cout << "이름: " << name << ", 가격: " << price << "G" << std::endl;
}

void Item::Clear()
{
	name = "";
	price = 0;
}

int Item::GetPrice() const
{
	return price;
}

const std::string& Item::GetName() const
{
	return name;
}
