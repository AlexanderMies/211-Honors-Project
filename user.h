// Alexander Mies
// CSC 211 H w/ Dr. Azhar
// Honors Project
// 4/23/2021
#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class user {
	private:
		string firstName;
		string lastName;
	public:
		user(){};


		vector <string> ingredientList;


		
		// getting first name
		string getFirstName() {
			return firstName;
		};
		
		// getting last name
		string getLastName() {
			return lastName;
		};
		
		// setting first name
		void setFirstName(string name) {
			this->firstName = name;
		};

		// setting last name
		void setLastName(string name) {
			this->lastName = name;
		};

		void printIngredients() {
			cout << "Hi there " << getFirstName() << ", here are the ingredients you requested to search:\n";
			
			for (int i = 0; i < this->ingredientList.size(); i++)
			{
				cout << this->ingredientList[i] << endl;
			};
		};

};
#endif


