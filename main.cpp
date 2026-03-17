#include "Common.h"

#include "inventory.h"
#include "item.h"

int main()
{
	Inventory<Item>* inventory = new Inventory<Item>();

	for (int i = 0; i < 11; ++i) {
		inventory->AddItem(Item("Item" + std::to_string(i), i * 100));
	}

	std::cout << "ItemCapacity : " << inventory->GetCapacity() << std::endl << std::endl;

	inventory->Resize(25);
	for (int i = 0; i < 14; ++i)
	{
		inventory->AddItem(Item("Item" + std::to_string(i), i * 100));
	}

	inventory->PrintAllItems();
	std::cout << "ItemCapacity : " << inventory->GetCapacity() << std::endl << std::endl;

	inventory->SortItems();
	inventory->PrintAllItems();
	std::cout << std::endl;

	Inventory<Item>* inventory2 = new Inventory<Item>(*inventory);
	inventory2->PrintAllItems();

	delete inventory;
	delete inventory2;
}