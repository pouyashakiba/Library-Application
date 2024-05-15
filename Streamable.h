/*******************************************************
 * Pouya Shakiba
 * pshakiba@myseneca.ca
 * 2024/05/15
 *******************************************************/

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