//
// Created by Caio Reidt on 09/05/21.
//

#include <iostream>
#include <fstream>
#include <string>

#include "Knapsack.h"

using namespace std;

void write_table (std::string path, Knapsack knapsack) {

	fstream fs;

	// create and open the .csv file
	fs.open(path, ios::out | ios::trunc);

	for (int i = 1; i <= knapsack.item_count; ++i) {

		for (int j = 1; j <= knapsack.size; ++j) {

			fs << knapsack.getItemValue(i, j);

			if (j + 1 <= knapsack.size) {
				fs << ",";
			} else {
				fs << std::endl;
			}

		}
	}

	// close the output file
	fs.close();
}