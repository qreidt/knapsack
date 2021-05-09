//
// Created by Caio Reidt on 09/05/21.
//

#ifndef KNAPSACK_KNAPSACK_H
#define KNAPSACK_KNAPSACK_H

#include "vector"

#include "Item.h"
#include "Bag.h"

class Knapsack {
public:
	int size = 0;
	int item_count;
	std::vector<Bag> rows;
	std::vector<Item> items;

	Knapsack(int size, std::vector<Item> items);

	float solve();

	void evaluateItem(Item item, int bag_index, int item_index);

	void setItemValue(int bag_index, int item_index, float value);
	float getItemValue(int bag_index, int item_index);
};


#endif //KNAPSACK_KNAPSACK_H
