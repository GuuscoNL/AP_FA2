#include "include/Warehouse.hpp"
#include "include/Shelf.hpp"

Warehouse::Warehouse() {}

void Warehouse::addEmployee(Employee employee) {
	employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf) {
	shelves.push_back(shelf);
}

bool Warehouse::rearrangeShelf(Shelf& shelf) {

	// Check if the employee has a certificate and is not busy
	for (auto employee : employees) {
		if (!employee.getForkliftCertificate() || employee.getBusy()) {
			return false;
		}
	}

	// Bubble sort (The number of pallets is so short that it 
	// doesn't matter that bubble sort is slow)
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3 - i; j++) {
			if (shelf.pallets[j].getItemCount() > shelf.pallets[j + 1].getItemCount()) {
				shelf.swapPallet(j, j + 1);
			}
		}
	}
	return true;
}

bool Warehouse::pickItems(std::string itemName, int itemCount) {

	// Check of itemCount valid is.
	if (itemCount <= 0){ // 0 could be considered as valid too??? for now it is not.
		return false;
	}

	// How many items are there in this warehouse?
	int total_item_count = 0;
	for (auto shelf : shelves) {
		for (auto pallet : shelf.pallets) {
			if (pallet.getItemName() == itemName) {
				total_item_count += pallet.getItemCount();
			}
		}
	}
	// Check of er wel genoeg items zijn
	if (total_item_count < itemCount) {
		return false;
	}

	int taken = 0;
	for (auto &shelf : shelves) {
		for (auto &pallet : shelf.pallets) {
			if (pallet.getItemName() != itemName) {
				continue;
			}

			while (taken < itemCount) {
				bool success = pallet.takeOne();
				if (success) {
					taken += 1;
				}
				else {
					break;
				}
			}
		}
	}
	return true;
}
