#include <iostream>
#include <string>
using namespace std;

int main()
{
	double price(0);
	string model, kind, color, leather, autopilot;
	int wheels;											// define all variables at the beginning with appropriate types

	cout << "Which vehicle would you like to order?";
	getline(cin, model);

	if (model != "3" && model != "S" && model != "X") {			// decide if an appropriate model is given
		cout << "Error - Incorrect model choice.";
		return(0);
	}


	cout << "Which kind would you like?";
	getline(cin, kind);


	if (model == "3" && kind == "Long Range") {						// listed all possible model + kind combinations and assign 
		price = 47990;												// a change of price to each condition, otherwise output an error
	}
	else if (model == "3" && kind == "Performance") {
		price = 55990;
	}
	else if (model == "S" && kind == "Long Range") {
		price = 79990;
	}
	else if (model == "S" && kind == "Performance") {
		price = 99990;
	}
	else if (model == "X" && kind == "Long Range") {
		price = 84990;
	}
	else if (model == "X" && kind == "Performance") {
		price = 104990;
	}
	else {
		cout << "Error - Incorrect kind choice.";
		return(0);
	}

	cout << "What exterior color would you like?";
	getline(cin, color);

	if (color != "White" && color != "Black" && color != "Blue" && color != "Grey" && color != "Red") {			// first a judgement of if a valid input is given
		cout << "Error - Incorrect color choice.";
		return(0);
	}
	else if (color == "White") {											// listed all possible conditons of colors and conditons of models w.r.t price changes
		price = price + 0;
	}
	else if (color == "Black") {
		if (model == "3") price += 500;
		if (model == "S") price += 1000;
		if (model == "X") price += 1500;
	}
	else if (color == "blue" || color == "grey") {
		if (model == "3") price += 1000;
		if (model == "S" || model == "X") price += 1500;
	}
	else if (color == "Red") {
		if (model == "3") price += 1500;
		if (model == "S" || model == "X") price += 2500;
	}

	cout << "Which wheels would you like?";
	cin >> wheels;
	cin.ignore(1000, '\n');

	if (wheels != 18 && wheels != 19 && wheels != 20 && wheels != 21 && wheels != 22) {			// first a check if valid wheel size is given
		cout << "Error - Incorrect wheel value.";
		return(0);
	}
	else if (model == "3") {									// conditions are combined w.r.t different model types as for diff model, wheel options are different
		if (wheels == 18) price += 0;
		else if (wheels == 19) price += 1500;
		else {
			cout << "Error - Incorrect wheel value.";
			return(0);
		}
	}
	else if (model == "S") {
		if (wheels == 19) price += 0;
		else if (wheels == 21) price += 4500;
		else {
			cout << "Error - Incorrect wheel value.";
			return(0);
		}
	}
	else if (model == "X") {
		if (wheels == 20) price += 0;
		else if (wheels == 22) price += 5500;
		else {
			cout << "Error - Incorrect wheel value.";
			return(0);
		}
	}

	cout << "Want leather interior?";
	getline(cin, leather);

	if (leather != "Yes" && leather != "No") {							// leather and autopilot are similar, as first to judge if a valid input is given
		cout << "Error - Incorrect leather choice.";					// then to check if Yes is given to change the price
		return(0);
	}
	if (leather == "Yes") {
		price += 1000;
	}

	cout << "Want Auto-Pilot?";
	getline(cin, autopilot);
	if (autopilot != "Yes" && autopilot != "No") {
		cout << "Error - Incorrect autopilot choice.";
		return(0);
	}
	if (autopilot == "Yes") {
		price += 6000;
	}

	cout.setf(ios::fixed);							// regulate the ouput of the 'price' in a format of 00.00 
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "Enjoy your new $" << price << " " << color << " Model" << " " << model << "!" << endl;		// if no error is generated, the main function will proceed to the end with output of a 'price'

	return(0);
}