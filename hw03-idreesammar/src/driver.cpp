#include "driver.h"
#include "strlib.h"
#include <fstream>

// function to add stock to portfolio
bool buyStock(StockPortfolio& inPort, const std::string& inString)
{
	bool stockAdded = false; // boolean to represent if function succeeded or not

	// will hold the various sections of the input (in order: symbol, name, purchase price, num shares)
	std::vector<std::string> stockInfo = strSplit(inString, '|');

	// create the new stock with info from the stockInfo vector
	std::string stockName = stockInfo[1];
	std::string stockSymbol = stockInfo[0];
	Money stockPurPrice = Money(std::stod(stockInfo[2])); // NOTE: stod is like stoi, converts string to double
	double stockNumShares = std::stod(stockInfo[3]);
	Stock newStock = Stock(stockName, stockSymbol, stockPurPrice, stockNumShares);

	// add stock to inputted portfolio
	inPort.addStock(newStock);
	
	// check if stock was added
	if (inPort.containsStock(stockSymbol))
	{
		stockAdded = true;;
	}

	return stockAdded;
}

// function to update a stock's price in a portfolio
bool updateStock(StockPortfolio& inPort, const std::string& inString)
{
	bool stockUpdated; // denotes if stock was updated as desired

	// will hold the various sections of the input (in order: symbol, new current price)
	std::vector<std::string> stockInfo = strSplit(inString, '|');

	// create new variables
	std::string stockSymbol = stockInfo[0];
	Money newPrice = Money(std::stod(stockInfo[1]));

	if (!(inPort.containsStock(stockSymbol)))  // if this stock isn't in portfolio, it can't be updated
	{
		stockUpdated = false; 
	}
	else  // stock is in portfolio (can be updated)
	{
		// update the stock's current price
		inPort[stockSymbol].setCurrentPrice(newPrice);
		stockUpdated = true;
	}

	return stockUpdated; // return the boolean indicating if function succeeded
}

// function to process file string (will either add or update a stock in given portfolio)
bool processFile(StockPortfolio& inPort, const std::string& inString)
{
	bool processSuccess; // bool to indicate if function succeeded
	std::ifstream inputFile(inString); // open the input stream 

	if (inputFile.is_open())  // if the input file was successfully opened
	{ 
		while (!(inputFile.eof()))  // will continue looping till reaching end of the file
		{ 
			std::string inputLine; // holds each line of input
			std::getline(inputFile, inputLine); // get the current line in the file

			if (!(inputLine.empty()))  // for non blank lines
			{
				if (inputLine[0] == '+')  // update stock
				{
					std::string cleanInputLine = inputLine.substr(1, inputLine.size() - 1); // create new substring without the +
					processSuccess = updateStock(inPort, cleanInputLine);
				}
				else	// no + so add stock
				{
					processSuccess = buyStock(inPort, inputLine);
				}
			}
		}
		inputFile.close(); // close the file
	}
	else  // file could not be found or opened
	{  
		std::cout << "Error: file was not found" << std::endl;
		processSuccess = false; // the function failed :(
	}
	
	return processSuccess; // return the boolean
}


