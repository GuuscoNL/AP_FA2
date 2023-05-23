#pragma once

#include <string>
#include "IContainer.hpp"

class Pallet : public IContainer{

private:
	std::string itemName;
	int itemCapacity;
	int itemCount;

public:
	/**
	 * @brief Get ItemCount of the Pallet
	 * 
	 * @return ItemCount of the Pallet
	 */
	int getItemCount();

	/**
	 * @brief Get ItemName of the Pallet
	 * 
	 * @return ItemName of the Pallet
	 */
	std::string getItemName();

	/**
	 * @brief Get ItemCapacity of the Pallet
	 * 
	 * @return ItemCapacity of the Pallet 
	 */
	int getItemCapacity();

	/**
	 * @brief Pallet class
	 * 
	 */
	Pallet();

	/**
	 * @brief Pallet class
	 * @param itemName The name od the item the Pallet is storing.
	 * @param itemCapacity The max capacity the Pallet can hold of 1 specific item.
	 * @param itemCount The amount of items the Pallet has stored.
	 */
	Pallet(std::string itemName, int itemCapacity, int itemCount);

	bool isEmpty() override;
	bool isFull() override;
	bool reallocateEmptyPallet(std::string itemName, int itemCapacity);
	bool takeOne();
	bool putOne();
};
