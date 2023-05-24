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
	 * @brief Get ItemCount of the Pallet.
	 * 
	 * @return ItemCount of the Pallet.
	 */
	int getItemCount();

	/**
	 * @brief Get ItemName of the Pallet.
	 * 
	 * @return ItemName of the Pallet.
	 */
	std::string getItemName();

	/**
	 * @brief Get ItemCapacity of the Pallet.
	 * 
	 * @return ItemCapacity of the Pallet .
	 */
	int getItemCapacity();

	/**
	 * @brief Construct a new Pallet.
	 */
	Pallet();

	/**
	 * @brief Construct a new Pallet.
	 * @param itemName The name of the item the Pallet is storing.
	 * @param itemCapacity The max capacity the Pallet can hold of 1 specific item.
	 * @param itemCount The amount of items the Pallet has stored.
	 */
	Pallet(std::string itemName, int itemCapacity, int itemCount);

	/**
	 * @brief Is the Pallet empty?
	 * 
	 * @return `true`: The Pallet is empty.
	 * @return `false`: The Pallet is not empty,
	 */
	bool isEmpty() override;

	/**
	 * @brief Is the Pallet full?
	 * 
	 * @return `true`: The Pallet is full.
	 * @return `false`: The Pallet is not full.
	 */
	bool isFull() override;

	/**
	 * @brief Reallocate Pallet for a different item.
	 * 
	 * @param itemName The new item to store.
	 * @param itemCapacity The new max capacity of the Pallet.
	 * @return true Pallet has been successfully reallocated.
	 * @return false Pallet has not been successfully reallocated, because the Pallet is not empty.
	 */
	bool reallocateEmptyPallet(std::string itemName, int itemCapacity);

	/**
	 * @brief Take one item from the Pallet.
	 * 
	 * @return `true`: Item was taken successfully.
	 * @return `false`: Item was not taken successfully, because the Pallet is empty.
	 */
	bool takeOne();

	/**
	 * @brief Put one item on the Pallet.
	 * 
	 * @return `true`: Item was added successfully.
	 * @return `false`: Item was not added successfully, because the Pallet is full.
	 */
	bool putOne();
};
