#include <iostream>
#include "src/include/Warehouse.hpp"

#define PRINT(x) std::cout << x << std::endl 

void printWarehouse(Warehouse warehouse) {
    PRINT("");
    PRINT("Warehouse:");
    PRINT("   Employees:");

    int employee_index = 0;
    for (auto employee : warehouse.employees) {
        std::cout << "      Employee " << employee_index << ": " << employee.getName() << std::endl;
    }

    int shelf_index = 0;
    for (auto shelf : warehouse.shelves) {
        std::cout << "   Shelf " << shelf_index << ":" << std::endl;
        int pallet_index = 0;
        for (auto pallet : shelf.pallets) {

            std::cout << "      Pallet " << pallet_index;
            std::cout << ": (" << pallet.getItemName() << ", " << pallet.getItemCapacity() << ", " << pallet.getItemCount() << ")" << std::endl;
            pallet_index++;
        }
        shelf_index++;
    }
    PRINT("");
}

int main(void) {
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 40),
        Pallet("Boxes", 100, 10),
        Pallet("Books", 100, 20),
        Pallet("Books", 100, 20)
    };

    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Books", 100, 15),
        Pallet("Boxes", 100, 20),
        Pallet("Books", 100, 10),
        Pallet("Boxes", 100, 30)
    };

    Shelf shelf3 = Shelf();
    shelf3.pallets = {
        Pallet("Toy Bears", 100, 20),
        Pallet("Toy Bears", 100, 10),
        Pallet(),
        Pallet("Toy Bears", 100, 30)
    };

    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);
    warehouse.addShelf(shelf3);

    warehouse.addEmployee(Employee("Bob", true));

    printWarehouse(warehouse);

    PRINT("Rearranging all shelves...");
    for (auto &shelf : warehouse.shelves) {
        if (!warehouse.rearrangeShelf(shelf)) {
            PRINT("Something went wrong!");
            return 1;
        }
    }

    printWarehouse(warehouse);

    PRINT("Removing 100 books from the warehouse...");
    if (!warehouse.pickItems("Books", 100)){
        PRINT("Something went wrong!");
        return 1;
    }

    printWarehouse(warehouse);

    return 0;
}
