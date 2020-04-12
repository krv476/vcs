#include "calc.h"

Calc::Calc()
{
}

void Calc::add()
{
	double x,y;

	cout << "Number one: ";
	cin >> x;
	cout << "Number two: ";
	cin >> y;

	cout << "Sum is: "<< x + y << endl;
}

void Calc::subtract()
{
	double x,y;

	cout << "Minuend: ";
	cin >> x;
	cout << "Subtrahend: ";
	cin >> y;

	cout << "Remainder is: " << x - y << endl;
}

void Calc::multiply()
{
	double x,y;

	cout << "Number one: ";
	cin >> x;
	cout << "Number two: ";
	cin >> y;

	cout << "Product is: " << x * y << endl;
}

void Calc::divide()
{
	double x,y;

	cout << "Dividend: ";
	cin >> x;
	cout << "Divisor: ";
	cin >> y;

	cout << "Quotient is: " << x / y << endl;
}

void Calc::root()
{
	double root, x;
	cout << "What Nth root would you like to find: ";
	cin >> root;
	cout << "What number would you like to find that root of: ";
	cin >> x;

	cout << "Result is: " << pow(x, 1.0/root) << endl;
}

void Calc::mod()
{
	int x, y;
	cout << "Dividend: ";
	cin >> x;
	cout << "Divisor: ";
	cin >> y;

	cout << "Remainder is: " << x % y << endl;
}

void Calc::power()
{
	int xpower, x;
	cout << "Number: ";
	cin >> x;
	cout << "Power: ";
	cin >> xpower;

	cout << "The result is: " << pow(x, xpower) << endl;
}