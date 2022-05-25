#include <iostream>
#include <string>
#include "money.h"
#include "stock.h"
#include "portfolio.h"

int main()
{
	/*
	std::string s = "yes";
	double x = 3.87;
	long long y;
	y = x*100;
	std::cout << x << std::endl << y;
	return 0;
	*/

	Stock Google = Stock("Google", "GOO", Money(30000), 56);
	Stock Tesla = Stock("Tesla", "TSL", Money(45000), 17);
	Stock Apple = Stock("Apple", "APP", Money(2010), 83);

	StockPortfolio port = StockPortfolio();
	port.addStock(Google); 
	port.addStock(Tesla);
	port.addStock(Apple);


	std::cout << port.getTotalValue() << std::endl;

	Google.setCurrentPrice(Money(56000));
	std::cout << Google.getCurrPrice() << std::endl;
	//std::cout << port[""GOO""].getCurrPrice() << std::endl;

	//port.addStock(Google);

	std::cout << port.getTotalValue() << std::endl;
	
	
	//Apple.setCurrentPrice(Money(2011));
	std::vector<std::string> diffList = port.getDiffList();
	
	/*
	for (std::string symbol : diffList) {
		std::cout << port[symbol].getCurrPrice() << "  " << std::endl ;
	}
	*/
	//std::cout << port.getOrigValue();
	
	
	
}