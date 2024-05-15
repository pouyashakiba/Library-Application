/*******************************************************
 * Pouya Shakiba
 * pshakiba@myseneca.ca
 * 2024/05/15
 *******************************************************/

#pragma once

#include <iostream>
#include "Date.h"
#include "Streamable.h"
#include "Lib.h"

namespace sdds {

   class Publication :public Streamable {

      char* m_title{};
      char m_shelfId[SDDS_SHELF_ID_LEN + 1]{};
      int m_membership{ };
      int m_libRef{};
      Date m_date;

   public:

      Publication() = default;

      //copy assigment and construcotr 
      Publication(const Publication& publication);
      virtual ~Publication();

      virtual Publication& operator=(const Publication& publication);

      virtual void set(int member_id);
      // Sets the membership attribute to either zero or a five-digit integer.
      void setRef(int value);
      // Sets the **libRef** attribute value
      void resetDate();
      // Sets the date to the current date of the system.

      virtual char type()const;
      //Returns the character 'P' to identify this object as a "Publication object"
      bool onLoan()const;
      //Returns true is the publication is checkout (membership is non-zero)
      Date checkoutDate()const;
      //Returns the date attribute
      bool operator==(const char* m_title)const;
      //Returns true if the argument title appears anywhere in the title of the 
      //publication. Otherwise, it returns false; (use strstr() function in <cstring>)
      operator const char* ()const;
      //Returns the title attribute
      int getRef()const;
      //Returns the libRef attirbute. 

      virtual std::ostream& write(std::ostream& os)const;
      virtual std::istream& read(std::istream& is);
      virtual bool conIO(std::ios& ios)const;
      //returns true if streamable is valid, otherwise returns false
      virtual operator bool()const;
   };

}