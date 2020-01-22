
#include "shipping_item.h"
#include "load.h"
#include "flat.h"
#include "tube.h"
#include "carton.h"
#include <fstream>
#include <iostream>
#include <algorithm>


Load::Load(){
    current_delivery_index_ = 0;
    count_ = 0;
    total_weight_ = 0;
    total_volume_ = 0;
}

// /**
//  * @brief splits string into a vector of substrings. for use with fillload()
//  * 
//  * @return std::vector<std::string> 
//  */
// std::vector<std::string> SplitString(std::string split_this){
//     std::string delimiter = " ";
//     int pos;
//     std::string token = "";
//     pos = split_this.find(delimiter);

//     std::vector<std::string> return_this;
//     while (pos != -1)
//     {
//         token = split_this.substr(0,pos);
//         return_this.push_back(token);
//         split_this.erase(0, pos + delimiter.length());
//         pos = split_this.find(delimiter);
//     }
//     token = split_this;
//     return return_this;
    
// }

/**
 * @brief Fills a Load object 
 * 
 * @param filename 
 */
void Load::FillLoad(std::string filename){
    std::ifstream input(filename);
    if(input.fail()){
        std::cout << "Unable to open file.";
    }
    //setup temp variables 
    char item_type;
    std::string customer_name;
    std::string street_address;
    std::string city;
    std::string state;
    std::string zip;

    // F                      type of shipping item
    // Bill Collins           address.name
    // 32 South Main          address.street_address
    // Ogden                  address.city
    // UT                     address.state
    // 84408                  address.zip
    // 3.2 12.2 8.3 .32       weight and dimensions (unique to subclass)

   //while(!input.eof()){
    input >> item_type;
    input.ignore(); //this deals with '\n' at the end of the item_type row
    std::getline(input, customer_name);
    std::getline(input, street_address);  
    std::getline(input, city);
    std::getline(input, state);
    std::getline(input, zip);

    // std::cout<<item_type<<std::endl;           //test input values 
    // std::cout<<customer_name<<std::endl;
    // std::cout<<street_address<<std::endl;
    // std::cout<<city<<std::endl;
    // std::cout<<state<<std::endl;
    // std::cout<<zip<<std::endl;}

    Address temp_address = {customer_name, street_address, city, state, zip};
    if (item_type == 'F')
    {
       /*std::string weight;
       input >> weight;

       std::string length;
       input >> length;

       std::string height;
       input >> height;

       std::string thickness;
       input >> thickness;*/
       double weight;
       input >> weight;

       double length;
       input >> length;

       double height;
       input >> height;

       double thickness;
       input >> thickness;

       ship_vector_.push_back(new Flat(temp_address, weight, length, height, thickness));
        total_weight_ += weight;
        total_volume_ += length*height*thickness;
    }
    else if (item_type == 'C')
    {
        double weight;
        input >> weight;

        double side1;
        input >> side1;

        double side2;
        input >> side2;

        double side3;
        input >> side3;

        ship_vector_.push_back(new Carton(temp_address, weight, side1, side2, side3));
        total_weight_ += weight;
        total_volume_ += side1*side2*side3;    
    }
    else
    {
        double weight;
        input >> weight;

        double length;
        input >> length;
        
        double circumference;
        input >> circumference;

        double radius = circumference/(2*Tube::kPi);

        ship_vector_.push_back(new Tube(temp_address, weight, length, circumference));
        total_weight_ += weight;
        total_volume_ += length*Tube::kPi*radius;
    }//end of if statements 
    count_++;

}

/**
 * @brief displays information about the next delivery
 * 
 * @param out 
 */
void Load::DisplayNextDelivery(std::ostream &out) const{
     
    auto const& delivery = *ship_vector_[current_delivery_index_];
   // std::cout<<"Hello"<<" "<<"Hello"<<" "<<"Hello"<<" "<<"Hello"<<" ";
   // std::string value = delivery.address().zip;
    //out<<delivery.address().name<<" "<<delivery.address().city<<" " << delivery.address().street_address;
    //out << ship_vector_[current_delivery_index_]->address().city << " " << ship_vector_[current_delivery_index_]->address().city << " " << ship_vector_[current_delivery_index_]->address().city << " ";
    out << delivery.address().name << "\n"
        << delivery.address().street_address << '\n'
        << delivery.address().city << ", "
        << delivery.address().state << ' '
        << delivery.address().zip << "\n";
    delivery.Display(out);
}

/**
 * @brief sets the current delivery item to delivered and changes the current
 * to the next in the vector 
 * 
 */
void Load::ItemDelivered(){
    ship_vector_[current_delivery_index_]->MarkDelivered();
    current_delivery_index_++;
}

/**
 * @brief leaves the current delivery item set to undelivered and 
 * changes the current to the next in vector 
 * 
 */
void Load::NotDeliverable(){
    current_delivery_index_++;
}

/**
 * @brief returns the amount of delivered items in the vector 
 * 
 * @return int 
 */
int Load::HowManyDelivered() const{
    // std::copy_if(cars.begin(), cars.end(), std::back_inserter(cars_from),
    //             //on the lambda, make sure there is an && separating the statements
    //             [start, end](Car &c1){return start < c1.year && c1.year < end;}); 
    int delivered_count = std::count_if(ship_vector_.begin(), ship_vector_.end(),
             [](auto* current_shipment){return current_shipment->delivered;} );
    return delivered_count;
}

/**
 * @brief returns the amound of UNdelivered items in the vector
 * 
 * @return int 
 */
int Load::HowManyNotDelivered() const{
    int undelivered_count = std::count_if(ship_vector_.begin(), ship_vector_.end(), 
            [](auto* current_shipment){ return (current_shipment->delivered);} );
    return undelivered_count;
}