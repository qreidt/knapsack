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

void createItems(vector<Item> *items, int count) {

	for (int i = 0; i < count; i++) {
		items->push_back(Item(
				random() % 50 + 10,
				random() % 50 + 10
		));
	}

//	 items->push_back(Item(10.0, 2));
//	 items->push_back(Item( 7.0, 1));
//	 items->push_back(Item(25.0, 6));
//	 items->push_back(Item(24.0, 5));

}

int main(int argc, const char * argv[]) {

	vector<Item> items;

	createItems(&items, 5000);

	cout << "Items created" << std::endl;

	Knapsack knapsack = Knapsack(10000, items);

	cout << "Knapsack created" << std::endl;

	int start_time = clock();

	float result = knapsack.solve();

	int end_time = clock();

	cout << "Knapsack value: " << result << std::endl;

	cout << "Execution Time: " << (end_time - start_time)/double(CLOCKS_PER_SEC) << "s" << std::endl;

	 // write_table("../result.csv", knapsack);

	return 0;
}
