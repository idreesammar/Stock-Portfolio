#include "portfolio.h"

// constructor
StockPortfolio::StockPortfolio()
{
	// the only member variable is the map mStocks and that comes empty
}

// function to add stock to the portfolio
void StockPortfolio::addStock(Stock inStock)
{
	// add the input stock's symbol as the key and the stock itself as the value to mStocks
	mStocks.emplace(inStock.getSymbol(), inStock); 
}

// function to check if specific stock is in portfolio
bool StockPortfolio::containsStock(std::string inSymbol)
{
	// boolean that indicates if input stock is in portfolio
	bool hasStock = false; // initialized to false
	
	if (mStocks.count(inSymbol) != 0)	// means that portfolio has value associated to that key
	{ 
		hasStock = true;
	}

	return hasStock; // return the boolean
}

// operator function to get value associated to key in mStocks
Stock& StockPortfolio::operator[](std::string inSymbol)
{
	// find stock object associated with input key and return this stock value
	return mStocks.at(inSymbol); 
}

// function to calculate net worth of all stocks in portfolio
Money StockPortfolio::getTotalValue() const
{
	Money netWorth; // will hold the networth of all stocks

	// use range-based loop to iterate over all stocks in mStocks map
	for (const auto& pair : mStocks) 
	{
		// adds each stocks current price value (times the number of shares) into its own money value
		netWorth += (pair.second.getCurrPrice() * pair.second.getNumShares()); 
	}

	// return the netWorth variable
	return netWorth;
}

// function to calulate original price of all stocks in portfolio
Money StockPortfolio::getOrigValue() const
{
	Money origWorth; // will hold the original price value of all stocks

	// use range-based loop to iterate over all stocks in mStocks map
	for (const auto& pair : mStocks)
	{
		// adds each stocks original purchase price (times numShares) value into its own money value
		origWorth += (pair.second.getPurPrice() * pair.second.getNumShares()); 
	}

	// return the origWorth variable
	return origWorth;
}

// function to obtain change in stock portfolio value (between current and original prices)
Money StockPortfolio::getProfit() const
{
	Money profitValue; // denotes the sum of the change for each stock in portfolio

	// use range-based loop to iterate over all stocks in mStocks map
	for (const auto& pair : mStocks)
	{
		// adds each stocks profit value (the current price minus the purhcase price)* the numShares
		profitValue += (pair.second.getChange() * pair.second.getNumShares()); 
	}

	// return the profit
	return profitValue;
}

// function to obtain key list in alphabetical order
std::vector<std::string> StockPortfolio::getAlphaList()
{
	std::vector<std::string> alphaList;

	// fill up alphaList with the keys from mStocks map (currently unsorted)
	for (const auto& pair : mStocks) 
	{
		alphaList.push_back(pair.first);	// add each key value
	}

	// now sort alphaList's keys with selection sort  (Yes, I now know maps already do this. But hey, more practice :)
	//(NOTE: earlier letters in alphabet has smaller ascii value than later e.g. A < Z)
	for (int i = 0; i < alphaList.size(); i++)
	{
		int smallIndex = i; // holds the index of smallest value (all values before i already sorted)
		for (int j = i+1; j < alphaList.size(); j++) // check all index values beyond i (which is currently index holding smallest)
		{
			if (alphaList[j] < alphaList[smallIndex]) // check if current index holds a smaller value
			{
				smallIndex = j; // the new index of the smallest value
			}
		}

		// now swap the minimum element into correct position
		std::string temp = alphaList[smallIndex];
		alphaList[smallIndex] = alphaList[i];
		alphaList[i] = temp;
	}

	// once sorted alphabetically, return the vector
	return alphaList;
}

// function to obtain key list in descending current value order
std::vector<std::string> StockPortfolio::getValueList()
{
	std::vector<std::string> valueList;

	// fill up valueList with the keys from mStocks map (currently unsorted)
	for (const auto& pair : mStocks)
	{
		valueList.push_back(pair.first);	// add each key value
	}

	// now sort valueList's keys with selection sort (NOTE: descending order, so keys with greater current value come first)
	for (int i = 0; i < valueList.size(); i++)
	{
		int bigIndex = i; // holds the index of the position with largest current value (all values before i already sorted)
		for (int j = i + 1; j < valueList.size(); j++) // check all index values beyond i (which is currently index holding largest currValue)
		{
			// check if current index holds a bigger current value
			if (mStocks.at(valueList[j]).getCurrPrice() > mStocks.at(valueList[bigIndex]).getCurrPrice()) 
			{
				bigIndex = j; // the new index of the big value
			}
		}

		// now swap the elements into correct position
		std::string temp = valueList[bigIndex];
		valueList[bigIndex] = valueList[i];
		valueList[i] = temp;
	}

	// once valueList has been sorted in descending currPrice order, return the vector
	return valueList;
}

// function to obtain key list in descending profit difference
std::vector<std::string> StockPortfolio::getDiffList()
{
	std::vector<std::string> diffList;

	// fill up diffList with the keys from mStocks map (currently unsorted)
	for (const auto& pair : mStocks)
	{
		diffList.push_back(pair.first);	// add each key value
	}

	// now sort diffList's keys with selection sort (NOTE: descending order, so keys with greater change come first)
	for (int i = 0; i < diffList.size(); i++)
	{
		int bigIndex = i; // holds the index of the position with largest change value (all values before i already sorted)
		for (int j = i + 1; j < diffList.size(); j++) // check all index values beyond i (which is currently index holding largest change)
		{
			// check if current index has a bigger change in value (currPrice-purPrice)
			if (mStocks.at(diffList[j]).getChange() > mStocks.at(diffList[bigIndex]).getChange())
			{
				bigIndex = j; // the new index of the smallest value
			}
		}

		// now swap the elements into correct position
		std::string temp = diffList[bigIndex];
		diffList[bigIndex] = diffList[i];
		diffList[i] = temp;
	}

	// once key list has been sorted by decreasing price change, return the diffList
	return diffList;
}
