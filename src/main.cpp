#include <iostream>
#include "shipping_item.h"
#include "load.h"

using std::cout;

int main() {
    
    Address address;
    address.name = "Test";
    address.street_address = "4032 s 1990 w";
    address.city = "Ogden";
    address.state = "UT";
    address.zip = "84404";

    Load LoadTest;
    LoadTest.FillLoad("../load_small.txt");
    LoadTest.DisplayNextDelivery(cout);

    return 0; 
}