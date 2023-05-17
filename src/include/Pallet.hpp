#pragma once

#include <string>
#include "IContainer.hpp"

class Pallet : public IContainer{

private:
	std::string itemName;
	int itemCapacity;
	int itemCount;

public:
	int getItemCount();

	std::string getItemName();

	int getItemCapacity();

	Pallet();

	Pallet(std::string itemName, int itemCapacity, int itemCount);

	bool isEmpty() override;
	bool isFull() override;
	bool reallocateEmptyPallet(std::string itemName, int itemCapacity);
	bool takeOne();
	bool putOne();
};
