#include "money.h"

// default constructor
Money::Money() 
{
	// set member varibles to 0
	mCents = 0;
}

// paramterized constructor (1)
Money::Money(long long inDollars, long long inCents)
{
	// sets mCents using two input values for dollars and cents (1 dollar = 100cents)
	mCents = (inDollars * 100) + inCents;
}

// paramterized constructor (2)
Money::Money(double inDollars)
{
	// convert double inDollars to cents (e.g. 1.75*100 = 175 cents)
	mCents = inDollars * 100;
}

// parameterized constructor (3)
Money::Money(long long inCents)
{
	mCents = inCents; // set member variable
}

// parameterized constructor (4)
Money::Money(int inCents)
{
	mCents = inCents; // set member variable
}

// Arithmetic Assignment Operators

Money& Money::operator+=(const Money& right)	// ADDITION
{
	// adds the cents value of the right Money variable into this variable's cent value
	mCents += right.mCents;

	return *this; // return this very object's reference
}

Money& Money::operator-=(const Money& right)	// SUBTRACTION
{
	// subtract the cents value of the right Money variable into this variable's cent value
	mCents -= right.mCents;

	return *this; // return this very object's reference
}

Money& Money::operator*=(double right)	// MULTIPLICATION
{
	// multiply this variable's cent value by the scalar right
	mCents *= right;

	return *this; // return this very object's reference
}

Money& Money::operator/=(double right)	// DIVISION
{
	// divide this variable's cent value by the scalar right
	mCents /= right;

	return *this; // return this very object's reference
}

// Comparison Operators

bool operator<(const Money& left, const Money& right)	// LESS THAN
{
	// compare the member variable values of the two objects
	if (left.mCents < right.mCents) 
	{
		return true;
	}
	else	// left is greater than right
	{  
		return false;
	}
}

bool operator>(const Money& left, const Money& right)	// GREATER THAN
{
	// compare the member variable values of the two objects
	if (left.mCents > right.mCents)
	{
		return true;
	}
	else	// left is less than right
	{
		return false;
	}
}

bool operator<=(const Money& left, const Money& right)	// LESS THAN OR EQUAL
{
	// compare the member variable values of the two objects
	if (left.mCents <= right.mCents)
	{
		return true;
	}
	else	// left is greater than right
	{
		return false;
	}
}

bool operator>=(const Money& left, const Money& right)	// GREATER THAN OR EQUAL
{
	// compare the member variable values of the two objects
	if (left.mCents >= right.mCents)
	{
		return true;
	}
	else	// left is less than right
	{
		return false;
	}
}

bool operator==(const Money& left, const Money& right)	// EQUAL
{
	// compare the member variable values of the two objects
	if (left.mCents == right.mCents)
	{
		return true;
	}
	else	// left is not equal to right
	{
		return false;
	}
}

bool operator!=(const Money& left, const Money& right)	// NOT EQUAL
{
	// compare the member variable values of the two objects
	if (left.mCents != right.mCents)
	{
		return true;
	}
	else	// left IS equal to right
	{
		return false;
	}
}

// Binary Arithmetic Operators

Money operator+(const Money& left, const Money& right)		// ADDITION
{
	// create new money object that will be returned
	Money retMoney = left; // set it to the same value as the left object

	// perform arithmetic operation on member variable using input objects' member variables
	retMoney.mCents = left.mCents + right.mCents;

	return retMoney; // return the new Money object
}

Money operator-(const Money& left, const Money& right)		// SUBTRACTION
{
	// create new money object that will be returned
	Money retMoney = left; // set it to the same value as the left object

	// perform arithmetic operation on member variable using input objects' member variables
	retMoney.mCents = left.mCents - right.mCents;

	return retMoney; // return the new Money object
}

Money operator*(const Money& left, double right)		// MULTIPLICATION
{
	// create new money object that will be returned
	Money retMoney = left; // set it to the same value as the left object

	// perform arithmetic operation on member variable using input objects' values
	retMoney.mCents = left.mCents * right;

	return retMoney; // return the new Money object
}

Money operator/(const Money& left, double right)		// DIVISION
{
	// create new money object that will be returned
	Money retMoney = left; // set it to the same value as the left object

	// perform arithmetic operation on member variable using input objects' values
	retMoney.mCents = left.mCents / right;

	return retMoney; // return the new Money object
}

// Output Stream Operator
std::ostream& operator<<(std::ostream& out, const Money& money)
{
	// display the dollar sign
	out << "$";

	// output a negative sign if needed
	if (money.mCents < 0)	// the cent value is negative
	{
		out << "-";
	}

	// calculate the dollar and cent amount from mCents (useds absolute value to prevent repetition of negative sign in output)
	int dollars = std::abs(money.mCents / 100);
	int cents = std::abs(money.mCents % 100); // gives the remainder that will be cents
	
	// output the dollars value
	out << dollars << ".";
	// appropriately output the cent values (adding leading 0 if needed)
	if (cents < 10)		// needs leading 0
	{
		out << 0 << cents;
	}
	else {	 // does not need leading 0
		out << cents;
	}
	
	// return the output stream
	return out;
}

// Input Stream Operator
std::istream& operator>>(std::istream& in, Money& money)
{
	// obtain double (decimal) value from the input stream
	double decimalNum; // to hold the inputted money value
	in >> decimalNum;
	
	// store the decimal value into money's member value
	money.mCents = decimalNum * 100; // appropriately convert the decimal number into a integer 

	// return the input stream
	return in;
}