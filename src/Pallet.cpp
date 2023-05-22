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
	if(!isEmpty()){
		return false;
	}
	this->itemName = itemName;
	this->itemCapacity = itemCapacity;
	return true;
}

bool Pallet::takeOne() {
	if(isEmpty()){
		return false;
	}
	itemCount -= 1;
	return true;
}

bool Pallet::putOne() {
	if(isFull()){
		return false;
	}
	itemCount += 1;
	return true;
}


bool Pallet::isEmpty(){
	return !(itemCount > 0);
}

bool Pallet::isFull(){
	return itemCount == itemCapacity;
}