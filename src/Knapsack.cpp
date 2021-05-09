//
// Created by Caio Reidt on 09/05/21.
//

#include "Knapsack.h"
#include "Bag.h"

using namespace std;

Knapsack::Knapsack(int size, std::vector<Item> items) {
	this->size = size;
	this->items = items;
	this->item_count = (int) items.size();

	for (int i = 0; i <= this->item_count; i++) {
		this->rows.push_back(Bag(size));
	}
}

float Knapsack::solve() {

	// for each row after the first
	for (int i_weight = 1; i_weight <= this->item_count; i_weight++) {

		// for each cell after the first
		for (int i_item = 1; i_item <= this->size; i_item++) {
			Item item = this->items[i_weight - 1];

			this->evaluateItem(item, i_weight, i_item);
		}
	}

	// return the last item of the table
	return this->getItemValue(this->item_count, this->size);
}

void Knapsack::evaluateItem(Item item, int bag_index, int item_index) {

	// if the current item weight is grater than or equal to the current item's weight
	if (item.weight <= item_index) {
		// set the cell value with the biggest total value between the

		float test_value = this->getItemValue(bag_index - 1, item_index - item.weight) + item.value;
		float bigger_value = max(test_value, this->getItemValue(bag_index - 1, item_index));

		this->setItemValue(bag_index, item_index, bigger_value);

	} else {
		// set the cell with the last item on this weight

		this->setItemValue(bag_index, item_index, this->getItemValue(bag_index - 1, item_index));
	}

}

void Knapsack::setItemValue(int bag_index, int item_index, float value) {
	this->rows[bag_index].cells[item_index] = value;
}

float Knapsack::getItemValue(int bag_index, int item_index) {
	return this->rows[bag_index].cells[item_index];
}
