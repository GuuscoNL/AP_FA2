#include "include/Shelf.hpp"

#include <iostream>

Shelf::Shelf() {}

bool Shelf::swapPallet(int slot, int slot2) {
	Pallet temp = pallets[slot];
	pallets[slot] = pallets[slot2];
	pallets[slot2] = temp;
	return true;
}

bool Shelf::isEmpty(){
	for (auto pallet : pallets){
		if(!pallet.isEmpty()){
			return false;
		}
	}
	return true;
}

bool Shelf::isFull(){
	for (auto pallet : pallets){
			if (!pallet.isFull()){
				return false;
			}
		}
	return true;
}
