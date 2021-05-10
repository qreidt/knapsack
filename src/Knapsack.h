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
	std::vector<Item> items;
	Bag last_bag;
	Bag current_bag;
	std::vector<Bag> history;

	Knapsack(int size, std::vector<Item> items);

	float solve();

	void evaluateItem(Item item, int item_index);

	float getLastItemValue(int item_index);

	void setItemValue(int item_index, float value);
	float getItemValue(int item_index);

	void addBagToHistory(Bag bag);
};


#endif //KNAPSACK_KNAPSACK_H
