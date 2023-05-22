#include <iostream>
#include "src/include/Warehouse.hpp"

int main(void){
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 15), 
        Pallet("Books", 100, 2), 
        Pallet("Books", 100, 2), 
        Pallet("Books", 100, 10)
    };

    warehouse.addEmployee(Employee("Bob", true));
    warehouse.addShelf(shelf1);

    std::cout << warehouse.pickItems("Books", 25);
    return 0;
}
