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
	itemName = "";
	itemCapacity = 0;
	itemCount = 0;
}

Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount) :
	itemName(itemName), 
	itemCapacity(itemCapacity), 
	itemCount(itemCount)
{}

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


bool Pallet::isEmpty(){
	throw "Not yet implemented";
}

bool Pallet::isFull(){
	throw "Not yet implemented";
}