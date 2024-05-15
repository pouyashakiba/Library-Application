//name:pouya shakiba email:pshakib@myseneca.com id:117389221 Date: 2/8/2023
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
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