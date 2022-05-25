#include "stock.h"

// parameterized constructor
Stock::Stock(std::string inName, std::string inSymbol, const Money& inPurPrice, double inNumShares)
{
	// set the member variables
	mName = inName;
	mSymbol = inSymbol;
	mPurchasePrice = inPurPrice;
	mCurrentPrice = inPurPrice; // currently also the purchase price (Can change later)
	mNumShares = inNumShares;
}

// default constructor
Stock::Stock()
{
	// set member variables to 0 or equivalent
	mName = "";
	mSymbol = "";
	mNumShares = 0;
	mPurchasePrice = 0;
	mCurrentPrice = 0;
}

// Getters

Money Stock::getCurrPrice() const
{
	return mCurrentPrice; // return the current price
}

Money Stock::getPurPrice() const
{
	return mPurchasePrice; // return the purchase price
}

std::string Stock::getSymbol() const
{
	return mSymbol; // return the stock symbol
}

std::string Stock::getName() const
{
	return mName; // return the stock name
}

double Stock::getNumShares() const
{
	return mNumShares; // return the number of shares of the stock
}

// function to obtain change
Money Stock::getChange() const
{
	Money changePrice = mCurrentPrice - mPurchasePrice; // holds the value of the new price minus the original price

	return changePrice; // return this difference as a Money value
}

// Setter for Current Price
void Stock::setCurrentPrice(const Money& inCurrPrice)
{
	// set the member value with its new value (from the input)
	mCurrentPrice = inCurrPrice;

}

// Output Stream Operator
std::ostream& operator<<(std::ostream& out, const Stock& stock)
{
	// display the stock and its appropriate information (e.g symbol : #shares @ currentPrice)
	out << stock.mSymbol << " : " << stock.mNumShares << " @ " << stock.mCurrentPrice;

	// return the inputted output stream
	return out;
}


