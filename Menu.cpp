/*******************************************************
 * Pouya Shakiba
 * pshakiba@myseneca.ca
 * 2024/05/15
 *******************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Menu.h"
#include "Utils.h"
using namespace std;

namespace sdds {

   //MenuItem class
   void MenuItem::setEmpty() {
      menuContent = nullptr;
   }

   MenuItem::MenuItem() {
      setEmpty();
   }

   MenuItem::MenuItem(const char* textContent) {
      if (textContent != nullptr && textContent[0] != '\0') {
         menuContent = new char[strLen(textContent) + 1];
         strCpy(menuContent, textContent);
      }
      else {
         setEmpty();
      }
   }

   MenuItem::~MenuItem() {
      delete[] menuContent;
   }



   MenuItem::operator bool() const {
      return (menuContent != nullptr && menuContent[0] != '\0');
   };

   MenuItem::operator const char* () const {
      return menuContent;
   }

   std::ostream& MenuItem::display(std::ostream& os) {
      if (*this) {
         os << menuContent ;
      }

      return os;
   }

   //Menu class
   Menu::Menu() {
      pointerCount = 0;
   };

   Menu::Menu(const char* title) : menuTitle(title) {};

   Menu::~Menu() {
      unsigned int i;
      for (i = 0; i < MAX_MENU_ITEMS; i++)
      {
         delete menuItems[i];
      }
   };

   unsigned int Menu::run() {
      displayMenu();
      int selection;
      selection = getPosInt(0, pointerCount);
      return selection;
   }

   Menu::operator int() {
      return pointerCount;
   }

   Menu::operator unsigned int() {
      return pointerCount;
   }

   Menu::operator bool() {
      return (pointerCount > 0);
   }

   int Menu::operator~() {
      return run();
   }

   const char* Menu::operator[](unsigned int index) const {
      if (index > pointerCount)
      {
         int trueIndex = index %= pointerCount;
         return menuItems[trueIndex]->menuContent;
      }
      else
      {
         return menuItems[index]->menuContent;
      }
   }

   std::ostream& operator<<(std::ostream& os, Menu& menu) {
      return (menu.displayMenuTitle(os));
   }

   std::ostream& Menu::displayMenuTitle(std::ostream& os) {
      if (menuTitle) {
         menuTitle.display();
      }
      return os;
   }

   std::ostream& Menu::displayMenu(std::ostream& os) {
      if (menuTitle)
      {
         menuTitle.display();
      }
      os << endl;
      unsigned int i;
      for (i = 0; i < pointerCount; i++)
      {
         os.setf(ios::right);
         os.width(2);
         os.fill(' ');
         os << i + 1 << "- ";
         os.unsetf(ios::right);
         menuItems[i]->display(os);
         os << endl;
      }
      os << " 0- Exit" << endl;
      os << "> ";

      return os;
   }

   Menu& Menu::operator<<(const char* menuitemContent) {
      if (pointerCount < MAX_MENU_ITEMS)
      {
         MenuItem* tempMenuItem = new MenuItem(menuitemContent);
         menuItems[pointerCount] = tempMenuItem;
         pointerCount++;
      }
      return *this;
   }

};