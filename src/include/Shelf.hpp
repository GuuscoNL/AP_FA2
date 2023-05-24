#pragma once

#include <array>
#include "Pallet.hpp"
#include "IContainer.hpp"

class Shelf : public IContainer{

public:
	std::array<Pallet, 4> pallets;

	/**
	 * @brief Construct a new Shelf object.
	 */
	Shelf();

	/**
	 * @brief Is the Shelf empty?
	 * 
	 * @return `true`: The Shelf is empty.
	 * @return `false`: The Shelf is not empty
	 */
	bool isEmpty() override;

	/**
	 * @brief Is the Shelf full?
	 * 
	 * @return `true`: The Shelf is full.
	 * @return `false`: The Shelf is not full.
	 */
	bool isFull() override;

	/**
	 * @brief Swap the position of two Pallet objects in the pallets array.
	 * 
	 * @return `true`: Positions are swapped successfully.
	 * @return `false`: Positions are not swapped successfully.
	 */
	bool swapPallet(int slot, int slot2);

};

