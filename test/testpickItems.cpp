#include "include/catch.hpp"

#include "../src/include/Warehouse.hpp"
#include <iostream>

/// \brief 
/// Creates a mock Warehouse.
/// \return Warehouse with shelf of books.
/// \details
/// Creates a Warehouse with 3 unsorted shelves with a total of 100 Books, 60 Boxes, and 60 Toy Bears.
/// \n Adds forklift certified employee Bob.
/// \n This function can be used in testcases to avoid the repeated construction of Warehouse objects.

///////////////////////////////////////////////////////////////
//           Warehouse::pickItems test cases                 //
///////////////////////////////////////////////////////////////

Warehouse createMockWarehouse2(){
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
        Pallet("Books", 100, 5), 
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

    return warehouse;
}

TEST_CASE("Pick items with succes single pallet", "Warehouse::pickItems"){
    // Maak mock warehouse
    Warehouse warehouse = createMockWarehouse2();

    bool successful = warehouse.pickItems("Books", 20);
    REQUIRE(successful == true);

    // Check alle pallets om te kijken of alleen de correcte pallets
    // verandert worden.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 10);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 20);

    REQUIRE(warehouse.shelves[1].pallets[0].getItemCount() == 15);
    REQUIRE(warehouse.shelves[1].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.shelves[1].pallets[2].getItemCount() == 5);
    REQUIRE(warehouse.shelves[1].pallets[3].getItemCount() == 30);

    REQUIRE(warehouse.shelves[2].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[2].pallets[1].getItemCount() == 10);
    REQUIRE(warehouse.shelves[2].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.shelves[2].pallets[3].getItemCount() == 30);
}

TEST_CASE("Pick items with success multiple pallet", "Warehouse::pickItems"){
    // Maak mock warehouse
    Warehouse warehouse = createMockWarehouse2();

    bool successful = warehouse.pickItems("Books", 70);
    REQUIRE(successful == true);

    // Check alle pallets om te kijken of alleen de correcte pallets
    // verandert worden.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 10);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 10);

    REQUIRE(warehouse.shelves[1].pallets[0].getItemCount() == 15);
    REQUIRE(warehouse.shelves[1].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.shelves[1].pallets[2].getItemCount() == 5);
    REQUIRE(warehouse.shelves[1].pallets[3].getItemCount() == 30);

    REQUIRE(warehouse.shelves[2].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[2].pallets[1].getItemCount() == 10);
    REQUIRE(warehouse.shelves[2].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.shelves[2].pallets[3].getItemCount() == 30);
}

TEST_CASE("Pick items with success multiple pallet and mutiple shelves", "Warehouse::pickItems"){
    // Maak mock warehouse
    Warehouse warehouse = createMockWarehouse2();

    bool successful = warehouse.pickItems("Books", 100);
    REQUIRE(successful == true);

    // Check alle pallets om te kijken of alleen de correcte pallets
    // verandert worden.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 10);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 0);

    REQUIRE(warehouse.shelves[1].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.shelves[1].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.shelves[1].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.shelves[1].pallets[3].getItemCount() == 30);

    REQUIRE(warehouse.shelves[2].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[2].pallets[1].getItemCount() == 10);
    REQUIRE(warehouse.shelves[2].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.shelves[2].pallets[3].getItemCount() == 30);
}

TEST_CASE("Pick items with fail, not enough items", "Warehouse::pickItems"){
    // Construct empty warehouse and add empty shelf and forklift certified Employee.
    Warehouse warehouse = createMockWarehouse2();

    bool successful = warehouse.pickItems("Books", 110);
    REQUIRE(successful == false);

    // Check alle pallets om te kijken of er geen pallets verandert zijn.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 10);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 20);

    REQUIRE(warehouse.shelves[1].pallets[0].getItemCount() == 15);
    REQUIRE(warehouse.shelves[1].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.shelves[1].pallets[2].getItemCount() == 5);
    REQUIRE(warehouse.shelves[1].pallets[3].getItemCount() == 30);

    REQUIRE(warehouse.shelves[2].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[2].pallets[1].getItemCount() == 10);
    REQUIRE(warehouse.shelves[2].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.shelves[2].pallets[3].getItemCount() == 30);
}

TEST_CASE("Pick items with fail, 0 items requested", "Warehouse::pickItems"){
    // Construct empty warehouse and add empty shelf and forklift certified Employee.
    Warehouse warehouse = createMockWarehouse2();

    bool successful = warehouse.pickItems("Books", 0);
    REQUIRE(successful == false);

    // Check alle pallets om te kijken of er geen pallets verandert zijn.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 10);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 20);

    REQUIRE(warehouse.shelves[1].pallets[0].getItemCount() == 15);
    REQUIRE(warehouse.shelves[1].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.shelves[1].pallets[2].getItemCount() == 5);
    REQUIRE(warehouse.shelves[1].pallets[3].getItemCount() == 30);

    REQUIRE(warehouse.shelves[2].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[2].pallets[1].getItemCount() == 10);
    REQUIRE(warehouse.shelves[2].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.shelves[2].pallets[3].getItemCount() == 30);
}

TEST_CASE("Pick items with fail, -1 items requested", "Warehouse::pickItems"){
    // Construct empty warehouse and add empty shelf and forklift certified Employee.
    Warehouse warehouse = createMockWarehouse2();

    bool successful = warehouse.pickItems("Books", -1);
    REQUIRE(successful == false);

    // Check alle pallets om te kijken of er geen pallets verandert zijn.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 10);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 20);

    REQUIRE(warehouse.shelves[1].pallets[0].getItemCount() == 15);
    REQUIRE(warehouse.shelves[1].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.shelves[1].pallets[2].getItemCount() == 5);
    REQUIRE(warehouse.shelves[1].pallets[3].getItemCount() == 30);

    REQUIRE(warehouse.shelves[2].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[2].pallets[1].getItemCount() == 10);
    REQUIRE(warehouse.shelves[2].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.shelves[2].pallets[3].getItemCount() == 30);
}

TEST_CASE("Pick items with fail, Non existent item", "Warehouse::pickItems"){
    // Construct empty warehouse and add empty shelf and forklift certified Employee.
    Warehouse warehouse = createMockWarehouse2();

    bool successful = warehouse.pickItems("Games", 20);
    REQUIRE(successful == false);

    // Check alle pallets om te kijken of er geen pallets verandert zijn.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 10);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 20);

    REQUIRE(warehouse.shelves[1].pallets[0].getItemCount() == 15);
    REQUIRE(warehouse.shelves[1].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.shelves[1].pallets[2].getItemCount() == 5);
    REQUIRE(warehouse.shelves[1].pallets[3].getItemCount() == 30);

    REQUIRE(warehouse.shelves[2].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[2].pallets[1].getItemCount() == 10);
    REQUIRE(warehouse.shelves[2].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.shelves[2].pallets[3].getItemCount() == 30);
}