#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>							//for user defined functions
#include <cmath>							//for pre defined mathfunctions
#include <string>							//for string variables
using namespace std;

	//Author: James Saylor
	//Description : This program will ask the user to choose from a list of treats
	//				and then calculate a total based on volume and toppings


//constants
const double Y_PRICE = 0.44;
const double S_PRICE = 0.49;
const double P_PRICE = 1.62;
const double B_PRICE = 3.49;
const double MED_DISC = 0.04;
const double LARGE_DISC = 0.08;
const double TOP_PRICE = 0.63;
const int SMALL_AMT = 16;
const int MED_AMT = 32;
const int LARGE_AMT = 64;
const string POSITIVE_NUM = "Please enter any positive number including 0: ";
const string MAX_NUM = "Please enter any number equal to or greater than 1: ";
const double YOG_SS_AMT = 64;
const double PREM_IC = 5;
const double BARS = 20;


//function prototypes
double ValidPosInt (string display);
double ValidMaxInt (string display, double num);
double TreatCharge (char choice, double amount);
double ToppingsCharge (char choice, double amount);
double TotalCost (char choice);
char TreatChoice ();

int main ()
{
	//local variables
	int treatCounter = 1;
	double treatNum;
	double costPerTreat;
	double cost;
	char customerTreat;
	
	//execution
	cout << "This program will calculate customer bills for frozen treats" << endl;
	cout << endl << "NEW CUSTOMER" << endl;
	do
	{
		treatNum = ValidPosInt (POSITIVE_NUM);
		while (treatCounter <= treatNum)
		{
			customerTreat = TreatChoice ();
			costPerTreat = TotalCost(customerTreat);
			if (treatCounter >= 4 && treatNum == treatCounter)
			{
				costPerTreat = costPerTreat * 0.5;
			}
			cout << setprecision(2) << showpoint << fixed;
			cout << "Charge for treat #" << treatCounter << " is $ " << costPerTreat;
			cout << endl << endl;
			cost = cost + costPerTreat;
			treatCounter++;
			system("pause");
		}
		
		if (treatCounter == treatNum + 1)
		{
			cout << setprecision(0) << noshowpoint;
			cout << "Bill total for " << treatNum;
			cout << setprecision(2) << showpoint << fixed; 
			cout << " treats is $ " << cost << endl << endl;
		}
		
	} while (treatNum == 0);
	
	system("pause");

 	cout << endl << endl;
 	return 0;
}

double ValidPosInt (string display)
{
	double validNum;
	
	do
	{
		cout << display;
		cin >> validNum;
		cout << endl;
		
		if (validNum < 0)
		{
			cout <<"Alert --- The number you have entered is not valid. Try again." << endl;
		}	
	}
	while (validNum < 0);
	
	return validNum;
}

double ValidMaxInt (string display, double num)
{
	double validNum;
	
	do
	{
		cout << display;
		cin >> validNum;
		cout << endl;
		
		if (validNum < 1 || validNum > num)
		{
			cout << "Alert --- The number you have entered is not valid. Try again." << endl;
		} 
	}
	while (validNum < 1 || validNum > num);
	
	return validNum;
}

char TreatChoice ()
{
	char choice;
	bool result = true;
	
	cout << "Treat Choices:" << endl;
	cout << "   Y - Frozen Yogurt" << setw(11) << "$ " << Y_PRICE << " per ounce" << endl;
	cout << "   S - Soft Serve Ice Cream" << setw(4) << "$ " << S_PRICE << " per ounce" << endl;
	cout << "   P - Premium Ice Cream" << setw(7) << "$ " << P_PRICE << " per scoop" << endl;
	cout << "   B - Ice Cream Bar" << setw(11) << "$ " << B_PRICE << " per bar" << endl;
 	
	do
	{
		cout << endl << "Please enter the treat type you would like to purchase: ";
		cin >> choice;
		choice = toupper(choice);
		cout << endl;
		
		switch (choice)
		{
			case 'Y':
				break;
			case 'S':
				break;
			case 'P':
				break;
			case 'B':
				break;
			default:
				cout << "Alert --- Your choice is not valid. Try again." << endl;
				result = false;		
		}
	}
	while (result == false);
	
	return choice;
}

double TreatCharge (char choice, double amount)
{
	double charge;
	
	switch (choice)
		{
			case 'Y':
				if (amount <= SMALL_AMT)
					charge = amount * Y_PRICE;
				else if (amount <= MED_AMT)
					charge = (amount * (Y_PRICE - MED_DISC));
				else if (amount <= LARGE_AMT)
					charge = (amount * (Y_PRICE - LARGE_DISC));
				break;
			case 'S':
				if (amount <= SMALL_AMT)
					charge = amount * S_PRICE;
				else if (amount <= MED_AMT)
					charge = (amount * (S_PRICE - MED_DISC));
				else if (amount <= LARGE_AMT)
					charge = (amount * (S_PRICE - LARGE_DISC));
				break;
			case 'P':
				charge = amount * P_PRICE;
				break;
			case 'B':
				charge = amount * B_PRICE;
				break;	
		}
		
		return charge;
}

double ToppingsCharge (char choice, double amount)
{
	int topAmount;
	double toppingsCharge;
	
	switch (choice)
		{
			case 'Y':
			case 'S':
				if (amount <= SMALL_AMT)
				{
					cout << "For toppings:" << endl;
					topAmount = ValidPosInt (POSITIVE_NUM);
					if (topAmount > 1)
					{
						toppingsCharge = ((topAmount - 1) * TOP_PRICE);
					}
					else
						toppingsCharge = 0;
				}
				else
					toppingsCharge = 0;
				break;
			case 'P':
				cout << "For toppings:" << endl;
				topAmount = ValidPosInt (POSITIVE_NUM);
				if (topAmount > 1)
				{
					toppingsCharge = ((topAmount - 1) * TOP_PRICE);
				}
				else
					toppingsCharge = 0;
				break;
			default:
				toppingsCharge = 0;	
		}
		
	return toppingsCharge;
}

double TotalCost (char choice)
{
	double userAmount;
	double baseCharge;
	double topCharge;
	double totalCharge;
	
	cout << "Supply your desired amount of treat." << endl;
	
	switch (choice)
		{
			case 'Y':
			case 'S':
				userAmount = ValidMaxInt (MAX_NUM, YOG_SS_AMT);
				break;
			case 'P':
				userAmount = ValidMaxInt (MAX_NUM, PREM_IC);
				break;
			case 'B':
				userAmount = ValidMaxInt (MAX_NUM, BARS);
				break;		
		}
		baseCharge = TreatCharge (choice, userAmount);
		topCharge = ToppingsCharge (choice, userAmount);
		totalCharge = baseCharge + topCharge;
		
		return totalCharge;
}
