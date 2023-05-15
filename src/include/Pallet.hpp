#pragma once

#include <string>

class Pallet {

private:
	int itemCount;
	std::string itemName;
	int itemCapacity;

public:
	int getItemCount();

	std::string getItemName();

	int getItemCapacity();

	Pallet();

	Pallet(std::string itemName, int itemCapacity, int itemCount);

	bool reallocateEmptyPallet(std::string itemName, int itemCapacity);

	bool takeOne();

	bool putOne();
};
