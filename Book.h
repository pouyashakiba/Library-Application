/*******************************************************
 * Pouya Shakiba
 * pshakiba@myseneca.ca
 * 2024/05/15
 *******************************************************/

#pragma once

#include <iostream>
#include "Publication.h"
namespace sdds {

   class Book : public Publication{
      char* m_authorName{};

   public:
      Book() = default;
      Book(const Book& book);
      Book& operator=(const Book& publication);
      virtual ~Book();

      char type()const;
      void set(int member_id);
      std::ostream& write(std::ostream& os)const;
      std::istream& read(std::istream& is);
      operator bool()const;
   };

}