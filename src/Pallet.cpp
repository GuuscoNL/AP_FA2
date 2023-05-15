#include "include/Pallet.hpp"

int Pallet::getItemCount() {
	return this->itemCount;
}

std::string Pallet::getItemName() {
	return this->itemName;
}

int Pallet::getItemCapacity() {
	return this->itemCapacity;
}

Pallet::Pallet() {
	// TODO - implement Pallet::Pallet
	throw "Not yet implemented";
}

Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount) {
	// TODO - implement Pallet::Pallet
	throw "Not yet implemented";
}

bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity) {
	// TODO - implement Pallet::reallocateEmptyPallet
	throw "Not yet implemented";
}

bool Pallet::takeOne() {
	// TODO - implement Pallet::takeOne
	throw "Not yet implemented";
}

bool Pallet::putOne() {
	// TODO - implement Pallet::putOne
	throw "Not yet implemented";
}
