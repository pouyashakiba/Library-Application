/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
// Version
// Date	7/15/2023
// Author	Pouya Shakiba
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

//name:pouya shakiba email:pshakib@myseneca.com id:117389221 Date: 15/7/2023
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__

namespace sdds {
	// Copies the srouce character string into the destination
	void strCpy(char* des, const char* src);
	// Copies the source character string into the destination upto "len"
	// characters. The destination will be null terminated only if the number
	// of the characters copied is less than "len"
	void strnCpy(char* des, const char* src, int len);
	// Compares two C-strings 
	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strCmp(const char* s1, const char* s2);
	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strnCmp(const char* s1, const char* s2, int len);
	// returns the lenght of the C-string in characters
	int strLen(const char* s);
	// returns the address of first occurance of "str2" in "str1"
	// returns nullptr if no match is found
	const char* strStr(const char* str1, const char* str2);
	// Concantinates "src" C-string to the end of "des"
	void strCat(char* des, const char* src);

	int getPosInt(int minRange, int maxRange);
	int getUserInput(int lowerLimit, int upperLimit);
}
#endif // SDDS_UTILS_H__
