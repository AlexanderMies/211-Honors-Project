// Alexander Mies
// CSC 211 H w/ Dr. Azhar
// Honors Project
// 4/23/2021
#ifndef PASTRYRECIPE_H
#define PASTRYRECIPE_H
#include "recipe.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class pastryRecipe : public recipe {
public:
	pastryRecipe() {
		recipeTitle = "Title";
		recipeDescription = "Placeholder description";
		ingredientsList = {};
		foodCost = 0;
		calories = 0;
		prepTime = 0;
		cookTime = 0;
		totalTime = 0;
		ovenTemp = 350;
		sugarType = "Granulated Sugar";
	};

	int ovenTemp;
	string sugarType;

	void setOvenTemp() {
		int temp;
		cout << "What temperature should the oven be set at?: \n";
		cin >> temp;
		this->ovenTemp = temp;
	};

	int getOvenTemp() {
		return this->ovenTemp;
	};


	void setSugar() {
		int temp;
		cout << "Enter 1 for Granulated Sugar, 2 for Powdered Sugar, or 3 for Brown Sugar: \n";
		cin >> temp;
		if (temp == 1)
			this->sugarType = "Granulated Sugar";
		else if (temp == 2)
			this->sugarType = "Powdered Sugar";
		else if (temp == 3)
			this->sugarType = "Brown Sugar";
	};

	string getSugar() {
		return this->sugarType;
	};
	

};




#endif