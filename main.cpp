#include <iostream>
#include "src/include/Warehouse.hpp"

int main(void){
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };

    warehouse.addEmployee(Employee("Bob", true));
    warehouse.addShelf(shelf1);

    std::cout << (warehouse.shelves[0].pallets[0].getItemCount() == 20);
    std::cout << (warehouse.shelves[0].pallets[1].getItemCount() == 40);
    std::cout << (warehouse.shelves[0].pallets[2].getItemCount() == 30);
    std::cout << (warehouse.shelves[0].pallets[3].getItemCount() == 10);

    bool successful = warehouse.rearrangeShelf(warehouse.shelves[0]);

    std::cout << (successful == true);

    std::cout << (warehouse.shelves[0].pallets[0].getItemCount() == 10);
    std::cout << (warehouse.shelves[0].pallets[1].getItemCount() == 20);
    std::cout << (warehouse.shelves[0].pallets[2].getItemCount() == 30);
    std::cout << (warehouse.shelves[0].pallets[3].getItemCount() == 40);
    std::cout << std::endl;
    return 0;
}
