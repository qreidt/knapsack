//
// Created by Caio Reidt on 09/05/21.
//

#include "Bag.h"

Bag::Bag(int size) {
	for (int i = 0; i <= size; i++) {
		this->cells.push_back(0.0);
	}
}