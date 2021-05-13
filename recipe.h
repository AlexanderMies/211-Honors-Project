// Alexander Mies
// CSC 211 H w/ Dr. Azhar
// Honors Project
// 4/23/2021
#ifndef RECIPE_H
#define RECIPE_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class recipe {

public:
	// default constructor with placeholer values
	recipe(){
		recipeTitle = "Title";
		recipeDescription = "Placeholder description";
		ingredientsList = {};
		foodCost = 0;
		calories = 0;
		prepTime = 0;
		cookTime = 0;
		totalTime = 0;
	};

	string recipeTitle;
	string recipeDescription;
	vector <string>ingredientsList;
	float foodCost;
	int calories;
	int prepTime;
	int cookTime;
	int totalTime;
	int portions;


	void setPortions() {
		int temp;
		cout << "How many portions does this recipe serve?: ";
		cin >> temp;
		this->portions = temp;
	};

	float caloriesPerPortion() {
		float temp;
		temp = this->portions / this->calories;
		return temp;
	};

	// setting title of recipe
	void setTitle() {
		string temp;
		cout << "What is the name of this recipe? (Try something brief and descriptive like 'Hummus'): ";
		cin.get();
		getline(cin, temp);
		this->recipeTitle = temp;
	};

	// setting description of recipe
	void setDescription() {
		string temp;
		cout << "Please enter a brief description followed by enter key: \n";
		cin.get();
		getline(cin, temp);
		this->recipeDescription = temp;
	};

	// populating a vector of strings to be filled with ingredients for recipe
	void setIngredients() {
		int numIngredients;
		string temp;
		cout << "How many ingredients do you have in your recipe?\n";
		cin >> numIngredients; cout << endl;
		for (int i = 0; i < numIngredients; i++) {
			cout << "Enter ingredient " << i+1 << ": \n";
			cin.get();
			getline(cin, temp);
			this->ingredientsList.push_back(temp);
		};
	};


	
	// setting food cost
	void setFoodCost() {
		float temp;
		cout << "What is the total food cost of the recipe in USD?: \n";
		cin >> temp;
		this->foodCost = temp;
	};

	// seting calories
	void setCalories() {
		int temp;
		cout << "How many kCals does your recipe have in total?: \n";
		cin >> temp;
		this->calories = temp;
	};

	// setting prep time (active)
	void setPrepTime() {
		int temp;
		cout << "In minutes, how long does this recipe take to prep?: \n";
		cin >> temp;
		this->prepTime = temp;
	};

	// setting cook time (inactive)
	void setCookTime() {
		int temp;
		cout << "In minutes, how long does this recipe take to cook?: \n";
		cin >> temp;
		this->cookTime = temp;
	};

	// total time is prep+cook
	void setTotalTime() {
		this->totalTime = this->prepTime + this->cookTime;
	};

	string getTitle() {
		return this->recipeTitle;
	};

	string getDescription() {
		return this->recipeDescription;
	};

	float getFoodCost() {
		return this->foodCost;
	};

	int getCalories() {
		return this->calories;
	};

	int getPrepTime() {
		return this->prepTime;
	};

	int getCookTime() {
		return this->cookTime;
	};

	int getTotalTime() {
		return this->totalTime;
	};

	
};
#endif
