Hi Maximilliano, 

You need to change a few things: 

---------------carton.cpp--------------------
Change your constructor to create the ShippingItems object: 
Carton::Carton(Address address, double weight, double side1, double side2,
               double side3)
    : ShippingItem(address, weight, side1) {
    set_measurements(side1, side2, side3);
}

---------------flat.cpp--------------------
Change your constructor to create the ShippingItems object: 
Flat::Flat(Address address, double weight, double length, double height,
           double thickness)
    : ShippingItem(address, weight, length) {
  set_length(length);
  set_height(height);
  set_thickness(thickness);
}
---------------FillLoad.cpp--------------------
FilleLoad() function needs some work: 

Change     std::string item_type; to     char  item_type;
then when you are testing test against a character instead of a string: 
    if (item_type ==  'F')
Then, change this part: 
std::getline(input, item_type);
       try{
           Flat temp_flat = {temp_address, weight, length, height,
           thickness };

            ship_vector_.push_back( &temp_flat );
            total_weight_ += temp_flat.weight();
            total_volume_ += temp_flat.Volume();
       }catch(std::out_of_range e){
           e.what();
       }
to:
 ship_vector_.push_back(new Flat(address, weight, length, height, thickness));

Now, repeat something very similar to this for the other two cases. 

Fix these things, and let me know if you are still stuck. 

