//
//  main.cpp
//  knapsack
//
//  Created by Caio Reidt on 17/04/21.
//  @link https://www.youtube.com/watch?v=SJSRKnxu9Ig&t=1298s
//

#include <iostream>

#include "src/Knapsack.h"

using namespace std;

void write_table(std::string, Knapsack knapsack);

int main(int argc, const char * argv[]) {
    
    vector<Item> items;
    
    items.push_back(Item(10.0, 2));
    items.push_back(Item( 7.0, 1));
    items.push_back(Item(25.0, 6));
    items.push_back(Item(24.0, 5));
    
    Knapsack knapsack = Knapsack(7, items);
    
    float result = knapsack.solve();
    
    cout << "Knapsack value: " << result << "\n";

    write_table("../result.csv", knapsack);
    
    return 0;
}
