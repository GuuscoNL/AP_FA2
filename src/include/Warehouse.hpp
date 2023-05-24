#pragma once

#include <vector>
#include "Shelf.hpp"
#include "Employee.hpp"

class Warehouse {

public:

	std::vector<Employee> employees;
	std::vector<Shelf> shelves;
	
	/**
	 * @brief Construct a new Warehouse object.
	 */
	Warehouse();

	/**
	 * @brief Add an Employee to the warehouse.
	 * 
	 * @param employee The Employee to add.
	 */
	void addEmployee(Employee employee);

	/**
	 * @brief Add a Shelf to the warehouse.
	 * 
	 * @param shelf The Shelf to add.
	 */
	void addShelf(Shelf shelf);

	/**
	 * @brief Sort the Pallet objects of a specific Shelf based on Itemcount.
	 * 
	 * @param shelf The Shelf to rearrange.
	 * @return true The Shelf has been successfully rearranged.
	 * @return false The Shelf has not successfully been arranged, there are no workers that are free.
	 */
	bool rearrangeShelf(Shelf& shelf);

	/**
	 * @brief Take a specific amount of items from the warehouse
	 * 
	 * @param itemName The item to take
	 * @param itemCount The amount of items to take
	 * @return true The specific amount of items have been taken successfully.
	 * @return false The specific amount of items have not been taken successfully. There could not be enough items in the warehouse or itemCount is not valid.
	 */
	bool pickItems(std::string itemName, int itemCount);

};
