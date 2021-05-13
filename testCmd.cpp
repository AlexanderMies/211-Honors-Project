// Alexander Mies
// CSC 211 H w/ Dr. Azhar
// Honors Project
// 4/23/2021
#include <iostream>
#include <fstream>
#include <string>
#include "user.h"
#include "recipe.h"
#include "pastryRecipe.h"

using namespace std;

int main()
{

	// declaring vars for building search command string and instiantiating user object
	// searchCommand is doing a few things: using curl to send a request to a search engine, spoofing a user agent to send request to said search engine,
	// and outputting the contents to a text file called htmlFile.txt
	string searchCommand = "curl -L  https://duckduckgo.com/?q=+recipe -A \" Mozilla / 5.0 (compatible; MSIE 7.01; Windows NT 5.0)\">C:\\Users\\Alexander\\source\\repos\\testCmd\\testCmd\\htmlFile.txt";
	user p1;
	int numIngredients;
	string tempIngredient;
	string ingredientSearch;
	string result;

	// setting user credentials
	string firstName;
	cout << "Enter your first name: ";
	cin >> firstName;
	p1.setFirstName(firstName);
	string lastName;
	cout << "Enter your last name: ";
	cin >> lastName;
	p1.setLastName(lastName);
	

	// getting the number of ingredients to be searched
	cout << "How many ingredients (1-5) do you have?" << endl;
	cin >> numIngredients;

	// populating the list of ingredients with user input (spelling is not a huge deal, as the search engine will correct it somewhat)
	for (int i = 0; i < numIngredients; ++i)
	{
		cout << "Enter the ingredient: ";
		cin >> tempIngredient;
		cout << endl;
		p1.ingredientList.push_back(tempIngredient);
	};
	
	// building the string to be inserted into curl search command
	switch (numIngredients) {
	case(1):
		ingredientSearch = p1.ingredientList[0];
		break;
	case(2):
		ingredientSearch = p1.ingredientList[0] + '+' + p1.ingredientList[1];
		break;
	case(3):
		ingredientSearch = p1.ingredientList[0] + '+' + p1.ingredientList[1] + '+' + p1.ingredientList[2];
		break;
	case(4):
		ingredientSearch = p1.ingredientList[0] + '+' + p1.ingredientList[1] + '+' + p1.ingredientList[2] + '+' + p1.ingredientList[3];
		break;
	case(5):
		ingredientSearch = p1.ingredientList[0] + '+' + p1.ingredientList[1] + '+' + p1.ingredientList[2] + '+' + p1.ingredientList[3] + '+' + p1.ingredientList[4];
		break;
	};
	
	// Insert the search parameters into the searchCommand string and execute to populate htmlFile.txt with custom search engine html
	searchCommand.insert(35, ingredientSearch);
	system(searchCommand.c_str());

	// selecting type of recipe to determine which class to use
	int recipeSelect;
	cout << "Now that you've reviewed the recipes given the ingredients you have, it's time to build your own!\n";
	cout << "Is your recipe for savory or pastry?\n";
	cout << "Select 1 for savory and 2 for pastry\n";
	cin >> recipeSelect;
	recipe r1;
	pastryRecipe pr1;

	fstream recipeFile;
	recipeFile.open("recipe.txt");

	switch (recipeSelect) {
	case 1:
		//setting savory recipe
		r1.setTitle();
		r1.setDescription();
		r1.setIngredients();
		r1.setFoodCost();
		r1.setCalories();
		r1.setPortions();
		r1.setPrepTime();
		r1.setCookTime();
		r1.setTotalTime();
		// populating recipe file based on user input
		recipeFile << "Title: " << r1.getTitle() << endl;
		recipeFile << "Description: " << r1.getDescription() << endl;
		recipeFile << "Ingredients: \n";
		for (int i = 0; i < r1.ingredientsList.size(); i++) {
			recipeFile << r1.ingredientsList[i] + ",";
		};
		recipeFile << endl;
		recipeFile << "Food cost: $" << r1.getFoodCost() << endl;
		recipeFile << "Calories: " << r1.getCalories() << endl;
		recipeFile << "Prep Time: " << r1.getPrepTime() << endl;
		recipeFile << "Cook Time: " << r1.getCookTime() << endl;
		recipeFile << "Total Time: " << r1.getTotalTime() << endl;
		break;

	case 2:
		// setting pastry recipe
		pr1.setTitle();
		pr1.setDescription();
		pr1.setIngredients();
		pr1.setFoodCost();
		pr1.setCalories();
		r1.setPortions();
		pr1.setPrepTime();
		pr1.setCookTime();
		pr1.setTotalTime();
		pr1.setOvenTemp();
		pr1.setSugar();
		// populating pastry recipe based on user input
		recipeFile << "Title: " << pr1.getTitle() << endl;
		recipeFile << "Description: " << pr1.getDescription() << endl;
		recipeFile << "Ingredients: \n";
		for (int i = 0; i < pr1.ingredientsList.size(); i++) {
			recipeFile << pr1.ingredientsList[i] + ",";
		};
		recipeFile << endl;
		recipeFile << "Food cost: $" << pr1.getFoodCost() << endl;
		recipeFile << "Calories per portion: " << pr1.caloriesPerPortion() << endl;
		recipeFile << "Calories: " << pr1.getCalories() << endl;
		recipeFile << "Prep Time: " << pr1.getPrepTime() << endl;
		recipeFile << "Cook Time: " << pr1.getCookTime() << endl;
		recipeFile << "Total Time: " << pr1.getTotalTime() << endl;
		recipeFile << "Oven Temperature(f): " << pr1.getOvenTemp() << endl;
		recipeFile << "Type of Sugar Used: " << pr1.getSugar() << endl;
		break;
	};

	recipeFile.close();

	
	return 0;
}


