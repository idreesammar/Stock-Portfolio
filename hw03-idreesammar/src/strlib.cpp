#include "strlib.h"

// taken from my HW 2 submission
std::vector<std::string> strSplit(const std::string& str, char splitChar)
{
	std::vector<std::string> outVec; // the output vector whichs holds the content of str
	std::string section = ""; // denotes each section of given string str up to the split char

	// loop through each character of str
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != splitChar) // the  current char is not the split character
		{
			section.push_back(str[i]); // add it to the current section string
		}
		else	// the current characters is the split char (delimiter)
		{
			outVec.push_back(section); // add the currently completed section into outVec
			// reset section string to a blank string to begin obtaining chars for the next section
			section = "";
		}
	}
	// to obtain the last section (since it won't end with the splitChar)
	outVec.push_back(section);
	//return std::vector<std::string>();
	return outVec;
}

