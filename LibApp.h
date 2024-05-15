//name:pouya shakiba email:pshakib@myseneca.com id:117389221 Date: 21/7/2023
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "Publication.h"
#include "fstream"
namespace sdds {
    class LibApp {
        bool m_changed;
        Menu m_mainMenu{ "Seneca Library Application" };
        Menu m_exitMenu{ "Changes have been made to the data, what would you like to do?" };
        char m_fileName[256]{};
        Publication* PPA[SDDS_LIBRARY_CAPACITY]{};
        int NOLP;
        int LLRN;
        Menu m_getType{ "Choose the type of publication:" };

        //gets a confirmation from user
        bool confirm(const char* message);

        void load();

        //save fucntion for the next milestone
        void save();

        //search function for th enext milestone
        int search(int ref);

        //search and returns publication
        //sets m_changed to true
        void returnPub();
        //adds a publication(next milestones)
        void newPublication();
        //removes a publication(next milestones)
        void removePublication();
        //cheacks out a publication(next milestones)
        void checkOutPub();

    public:

        //constructor for the LibApp class
        LibApp();
        LibApp(const char filename[256]);
        ~LibApp();
        //shows the menu selection and gets input from the user
        void run();
    };
}
#endif // !SDDS_LIBAPP_H


