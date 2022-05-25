#pragma once

#include <string>
#include <vector>

// Name: 
//		strSplit
// Input: 
//		1) String to split, 
//		2) character to split on
// Output: 
//		Vector containing the split -- will have only the original string if there's no split
// Side Effects:
//		None
// Summary:
//		Given a string and a character to split on, returns a vector
//		of the split strings
std::vector<std::string> strSplit(const std::string& str, char splitChar);

