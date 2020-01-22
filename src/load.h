#ifndef LOAD_H
#define LOAD_H

#include <vector>
#include <string>
#include "shipping_item.h"

class Load{
    private:
        std::vector<ShippingItem*> ship_vector_;
        int current_delivery_index_;
        int count_ ;
        double total_weight_;
        double total_volume_;
    public:
        Load();
        ~Load() { 
            for(ShippingItem* &one_ptr : ship_vector_){
                delete one_ptr;
                one_ptr = NULL;
            }
         }
        //getters
        int count() const {return count_;}
        double total_volume() const {return total_volume_;}
        double total_weight() const {return total_weight_;}
        //other methods
        void FillLoad(std::string filename);
        void DisplayNextDelivery(std::ostream &out) const;
        void ItemDelivered();
        void NotDeliverable();
        int HowManyDelivered() const;
        int HowManyNotDelivered() const;
        std::vector<std::string> SplitString();
};

#endif