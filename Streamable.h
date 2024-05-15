//name:pouya shakiba email:pshakib@myseneca.com id:117389221 Date: 28/7/2023
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#pragma once

#include <iostream>

namespace sdds {
   
   class Streamable {
   
   public:
      virtual std::ostream& write(std::ostream& os)const = 0;
      virtual std::istream& read(std::istream& is) = 0;
      virtual bool conIO(std::ios& ios)const = 0;
      //returns true if streamable is valid, otherwise returns false
      virtual operator bool()const = 0;
      virtual ~Streamable() {}
   };
   std::ostream& operator<<(std::ostream& os, const Streamable& SO);
   std::istream& operator>>(std::istream& is, Streamable& RO);

}