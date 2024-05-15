/*******************************************************
 * Pouya Shakiba
 * pshakiba@myseneca.ca
 * 2024/05/15
 *******************************************************/


#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>

namespace sdds {
   const unsigned int  MAX_MENU_ITEMS = 20;

   class MenuItem {
   private:
      char* menuContent{};
      //sets the menu item to an empty state
      void setEmpty();

      MenuItem();
      MenuItem(const char* textContent);

      //prohibiting copy
      MenuItem(const MenuItem& menuItem) = delete;
      void operator=(const MenuItem& MI) = delete;

      virtual ~MenuItem();

      //returns true it the item is not in an empty state
      operator bool() const;
      //returns the address of menuContnet
      operator const char* () const;

      //display the content of menu item
      std::ostream& display(std::ostream& os = std::cout);

      friend class Menu;
   };
   class Menu {
   private:
      MenuItem menuTitle{};
      MenuItem* menuItems[MAX_MENU_ITEMS]{};
      unsigned int pointerCount = 0;

   public:
      Menu();
      Menu(const char* title);
      ~Menu();

      unsigned int run();

      //prohibiting copy
      Menu(const Menu& M) = delete;
      void operator=(const Menu& M) = delete;

      //retunrs number of items
      operator int();

      //returns number of items as unsigned int
      operator unsigned int();

      //returns true if number of items is more than zero
      operator bool();

      //runing the menu
      int operator~();

      //loop back the index if it's more than number of items
      const char* operator[](unsigned int index) const;

      Menu& operator<<(const char* menuitemContent);

      //displays title of the menu
      std::ostream& displayMenuTitle(std::ostream& os);
      //displays menu
      std::ostream& displayMenu(std::ostream& os = std::cout);
   };
   std::ostream& operator<<(std::ostream& os, Menu& menu);


}

#endif