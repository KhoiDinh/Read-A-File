// Inputs: balances.txt
//Outputs:balance, all(total of all balances)
// Reads in a data file and all of the balances and the total of all the balances combined

#include "stdafx.h"
#include<cstdlib>
#include<iostream>
#include<fstream>
#include <iomanip>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//variables mae and set to equal to values
	char filename[] = "Balances.txt";
	int account_number;
	char account_holder[100] = "";
	double balance;
	double all = 0;
	// file to be read
	ifstream infile("Balances.txt");

	// conditions placed if file fails to open
	if (infile.fail())
	{
		cout << "Unable to open" << filename << endl << endl;
		return 1;
	}
	// sets it so easy to get each elements
	infile >> account_number >> account_holder >> balance;
	
	// reads file and gets balances from each line
	while (!infile.eof() || account_holder[0])
	{
		cout << account_number << '\t' << account_holder << '\t' << balance << endl;
		infile >> account_number >> account_holder >> balance;
		all = all + balance;
	}
	//outputs the total of all the balances
	cout << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
	cout << "The total of all the balances listed is: " << setprecision(2)<< all << endl;

	// closes file 
	infile.close();
	return 0;
}



