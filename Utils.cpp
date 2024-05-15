/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version
// Date
// Author
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

#include <iostream>
#include "Utils.h"

namespace sdds {
   void strCpy(char* des, const char* src)
   {
      int i = 0;

      // Copy characters until null character is encountered
      while (src[i] != '\0') {
         des[i] = src[i];
         i++;
      }

      // Add null character at the end
      des[i] = '\0';
   }
   void strnCpy(char* des, const char* src, int len)
   {
      int i = 0;

      // Copy characters until specified length is reached or null character is encountered
      while (i < len && src[i] != '\0') {
         des[i] = src[i];
         i++;
      }

      // Add null character at the end if specified length is not reached
      if (i <= len)
         des[i] = '\0';
   }
   int strCmp(const char* s1, const char* s2)
   {
      while (*s1 && (*s1 == *s2)) {
         s1++;
         s2++;
      }

      return static_cast<int>(*s1) - static_cast<int>(*s2);
   }
   int strnCmp(const char* s1, const char* s2, int len)
   {
      int i = 0;

      while (i < len && *s1 && (*s1 == *s2)) {
         s1++;
         s2++;
         i++;
      }

      if (i == len)
         return 0;  // Both strings are equal up to the specified length
      else
         return static_cast<int>(*s1) - static_cast<int>(*s2);
   }
   int strLen(const char* s)
   {
      int length = 0;

      while (*s != '\0') {
         length++;
         s++;
      }

      return length;
   }
   const char* strStr(const char* str1, const char* str2)
   {
      if (*str2 == '\0')
         return str1;  // Edge case: str2 is an empty string

      while (*str1) {
         const char* p1 = str1;
         const char* p2 = str2;

         // Match characters of str1 and str2 until a mismatch occurs or str2 ends
         while (*p1 && *p2 && (*p1 == *p2)) {
            p1++;
            p2++;
         }

         // If str2 is fully traversed, a match is found
         if (*p2 == '\0')
            return str1;

         str1++;
      }

      return nullptr;  // No match found
   }
   void strCat(char* des, const char* src)
   {
      // Find the end of des
      while (*des)
         des++;

      // Append characters from src to des
      while (*src) {
         *des = *src;
         des++;
         src++;
      }

      // Add null character at the end
      *des = '\0';
   }
   int getPosInt(int minRange, int maxRange) {
      int input;
      bool validInt = false;
      while (validInt == false)
      {
         std::cin >> input;
         if (std::cin && input >= minRange && input <= maxRange)
         {
            validInt = true;
         }
         else
         {
            std::cout << "Invalid Selection, try again: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            validInt = false;
         }
      }
      return input;
   }
   int getUserInput(int lowerLimit, int upperLimit) {
       int input;
       bool validInput = false;
       while (!validInput) {
           if (!(std::cin >> input)) {
               std::cin.clear();
               std::cin.ignore(45678, '\n');
               std::cout << "Invalid Selection, try again: ";
           }
           else if (input < lowerLimit || input > upperLimit) {
               std::cout << "Invalid Selection, try again: ";
           }
           else {
               validInput = true;
           }
       }
       return input;
   }
}