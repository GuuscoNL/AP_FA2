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

	// check of de employee een certificaat heeft en niet bezig is
	for (auto employee : employees) {
		if (!employee.getForkliftCertificate() || employee.getBusy()) {
			return false;
		}
	}

	// Bubble sort (Het aantal pallets is zo kort dat het 
	// niet uitmaakt dat bubble sort langzaam is)
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

	if (itemCount <= 0){
		return false;
	}

	// hoeveel items zijn er in deze warehouse?
	int total_count = 0;
	for (auto shelf : shelves) {
		for (auto pallet : shelf.pallets) {
			if (pallet.getItemName() == itemName) {
				total_count += pallet.getItemCount();
			}
		}
	}
	// Check of er wel genoeg items zijn
	if (total_count < itemCount) {
		return false;
	}

	int taken = 0;
	for (auto &shelf : shelves) {
		for (auto &pallet : shelf.pallets) {
			if (pallet.getItemName() == itemName) {
				while (taken < itemCount) {
					bool took = pallet.takeOne();
					if (took) {
						taken += 1;
					}
					else {
						break;
					}
				}
			}
		}
	}
	return true;
}
