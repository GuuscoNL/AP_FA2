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

	// check of de employee een certificaat heeft
	for (auto employee : employees){
		if (!employee.getForkliftCertificate() || employee.getBusy()){
			return false;
		}
	}

	// Bubble sort
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3 - i; j++){
            if (shelf.pallets[j].getItemCount() > shelf.pallets[j + 1].getItemCount()){
                shelf.swapPallet(j, j + 1);
			}
		}
	}

	return true;
}

bool Warehouse::pickItems(std::string itemName, int itemCount) {
	// TODO - implement Warehouse::pickItems
	throw "Not yet implemented";
}
