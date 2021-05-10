//
// Created by Caio Reidt on 09/05/21.
//

#include "Knapsack.h"
#include "Bag.h"

using namespace std;

Knapsack::Knapsack(int size, std::vector<Item> items): last_bag(0), current_bag(size) {
	this->size = size;
	this->items = items;
	this->item_count = (int) items.size();
}

float Knapsack::solve() {

	// for each row after the first
	for (int i_item = 1; i_item <= this->item_count; i_item++) {

		this->last_bag = this->current_bag;
		this->current_bag = Bag(this->size);

		// for each cell after the first
		for (int i_weight = 1; i_weight <= this->size; i_weight++) {
			Item item = this->items[i_item - 1];

			this->evaluateItem(item, i_weight);
		}

		this->addBagToHistory(this->last_bag);
	}

	this->addBagToHistory(this->current_bag);

	// return the last item of the table
	return this->getItemValue(this->size);
}

void Knapsack::evaluateItem(Item item, int item_index) {

	// if the current item weight is grater than or equal to the current item's weight
	if (item.weight <= item_index) { // set the cell value with the biggest total value between the

		float test_value = this->getLastItemValue(item_index - item.weight) + item.value;
		float bigger_value = max(test_value, this->getLastItemValue(item_index));

		this->setItemValue(item_index, bigger_value);

	} else { // set the cell with the last item on this weight

		this->setItemValue(item_index, this->getLastItemValue(item_index));
	}

}

float Knapsack::getLastItemValue(int item_index) {
	return this->last_bag.cells[item_index];
}

void Knapsack::setItemValue(int item_index, float value) {
	this->current_bag.cells[item_index] = value;
}

float Knapsack::getItemValue(int item_index) {
	return this->current_bag.cells[item_index];
}

void Knapsack::addBagToHistory(Bag bag) {
	if (this->size <= 50) {
		this->history.push_back(bag);
	}
}
