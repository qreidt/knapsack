//
//  main.cpp
//  knapsack
//
//  Created by Caio Reidt on 17/04/21.
//

#include <iostream>
#include <vector>

class Item {
public:
    float value;
    int weigth;
    
    Item (float value, int weigth) {
        this->value = value;
        this->weigth = weigth;
    }
};

class Bag {
public:
    
    std::vector<float> cells;
    
    Bag (int size) {
        for (int i = 0; i <= size; i++) {
            this->cells.push_back(0.0);
        }
    }
};

class Knapsack {
public:
    int size = 0;
    int item_count;
    std::vector<Item> items;
    std::vector<Bag> rows;
    
    Knapsack (int size, std::vector<Item> items) {
        this->size = size;
        this->items = items;
        this->item_count = (int) items.size();
        
        for (int i = 0; i <= this->item_count; i++) {
            this->rows.push_back(Bag(size));
        }
    }
    
    float solve() {
        
        // for each row after the first
        for (int i_row = 1; i_row <= this->item_count; i_row++) {
            
            // for each cell after the first
            for (int i_cell = 1; i_cell <= this->size; i_cell++) {
                Item item = this->items[i_row - 1];
                if (item.weigth <= i_cell) {
                    float test_value = this->rows[i_row - 1].cells[i_cell - item.weigth] + item.value;
                    
                    this->rows[i_row].cells[i_cell] = std::max(test_value, this->rows[i_row - 1].cells[i_cell]);
                } else {
                    this->rows[i_row].cells[i_cell] = this->rows[i_row - 1].cells[i_cell];
                }
                
            }
        }
        
        return this->rows[this->item_count].cells[this->size];
    }
};

int main(int argc, const char * argv[]) {
    
    std::vector<Item> items;
    
    items.push_back(Item(10.0, 2));
    items.push_back(Item( 7.0, 1));
    items.push_back(Item(25.0, 6));
    items.push_back(Item(24.0, 5));
    
    Knapsack knapsack = Knapsack(7, items);
    
    float result = knapsack.solve();
    
    std::cout << "Knapsack value: " << result << "\n";
    
    return 0;
}
