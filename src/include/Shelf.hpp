#pragma once

#include <array>
#include "Pallet.hpp"
#include "IContainer.hpp"

class Shelf : public IContainer{

public:
	std::array<Pallet, 4> pallets;

	Shelf();

	bool isEmpty() override;
	bool isFull() override;
	bool swapPallet(int slot, int slot2);

};

