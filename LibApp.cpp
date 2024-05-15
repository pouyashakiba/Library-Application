//name:pouya shakiba email:pshakib@myseneca.com id:117389221 Date: 9/8/2023
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <cstring>
#include "LibApp.h"
#include "Book.h"
#include "Utils.h"
#include "PublicationSelector.h"
using namespace std;

namespace sdds {

    LibApp::LibApp() :m_mainMenu("Seneca Library Application"),
        m_exitMenu("Changes have been made to the data, what would you like to do?") {
        m_changed = false;
        m_mainMenu << "Add New Publication";
        m_mainMenu << "Remove Publication";
        m_mainMenu << "Checkout publication from library";
        m_mainMenu << "Return publication to library";
        m_exitMenu << "Save changes and exit";
        m_exitMenu << "Cancel and go back to the main menu";
        load();
    }

    bool LibApp::confirm(const char* message) {
        Menu confirmMenu(message);
        confirmMenu << "Yes";
        return confirmMenu.run() == 1;
    }

    LibApp::LibApp(const char dataTitle[256]) {
        m_mainMenu << "Add New Publication" << "Remove Publication"
            << "Checkout publication from library" << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";

        if (m_fileName) {
            strCpy(m_fileName, dataTitle);
        }

        m_changed = false;
        NOLP = 0;
        m_getType << "Book" << "Publication";
        load();
    }

    LibApp::~LibApp()
    {
        for (int i = 0; i < NOLP; i++) {
            delete PPA[i];
        }
    }

    void LibApp::load() {

        cout << "Loading Data" << endl;
        ifstream file;
        file.open(m_fileName);
        if (file) {
            char temp{};
            for (size_t i = 0; file && i < SDDS_LIBRARY_CAPACITY; i++) {
                file >> temp;
                file.ignore();
                if (file) {
                    switch (temp) {
                    case 'P':
                        PPA[i] = new Publication;
                        break;
                    case 'B':
                        PPA[i] = new Book;
                        break;
                    }
                    if (PPA[i]) {
                        file >> *PPA[i];
                        NOLP++;
                        LLRN = PPA[i]->getRef();
                    }
                }
            }
        }
    }

    void LibApp::save() {
        cout << "Saving Data\n";
        ofstream myFile(m_fileName);
        for (int i = 0; i < NOLP; i++)
        {
            if (PPA[i]->getRef() != 0) {
                myFile << *PPA[i] << endl;
            }
        }
    }

    int LibApp::search(int type) {
        char title[256]{};
        int i = 0, libRef = 0, selection = 0;
        char typeC;
        PublicationSelector publicationSel("Select one of the following found matches:", 15);
        selection = m_getType.run();
        switch (selection)
        {
        case 1:
            typeC = 'B';
            break;
        case 2:
            typeC = 'P';
            break;
        }

        cin.ignore(1456, '\n');
        cout << "Publication Title: ";
        cin.getline(title, 256);
        for (i = 0; i < NOLP; i++) {
            if (PPA[i]->operator==(title) && typeC == PPA[i]->type() && PPA[i]->getRef() != 0) {
                if ((type == 1) || (type == 2 && PPA[i]->onLoan()) || (type == 3 && !PPA[i]->onLoan())) {
                    publicationSel << PPA[i];
                }
            }
        }

        if (publicationSel) {
            publicationSel.sort();
            libRef = publicationSel.run();

            if (libRef > 0) {
                int i;
                Publication* result = nullptr;
                for (i = 0; i < NOLP; i++) {
                    if (PPA[i]->getRef() == libRef) {
                        result = PPA[i];
                    }
                }
                cout << *result << endl;
            }
            else cout << "Aborted!" << endl;
        }
        else cout << "No matches found!" << endl;
        return libRef;
    }

    void LibApp::returnPub() {

    }

    void LibApp::newPublication() {
        if (NOLP >= SDDS_LIBRARY_CAPACITY) {
            cout << "Library is at its maximum capacity!\n" << endl;
        }
        else {
            cout << "Adding new publication to the library" << endl;
            int tempType = m_getType.run();

            //clearing buffer
            while (std::cin.get() != '\n');
            Publication* tempPub{};
            switch (tempType)
            {
            case 0:
                cout << "Aborted!\n" << endl;
                break;
            case 1:
                tempPub = new Book;
                cin >> *tempPub;
                break;
            case 2:
                tempPub = new Publication;
                cin >> *tempPub;
                break;
            }
            if (confirm("Add this publication to the library?")) {
                m_changed = true;
                LLRN++;
                tempPub->setRef(LLRN);
                PPA[NOLP] = tempPub;
                NOLP++;
                cout << "Publication added\n\n";
            }
            if (!*tempPub) {
                cout << "Failed to add publication!" << endl;
                delete tempPub;
            }
        }

    }

    void LibApp::removePublication() {
        cout << "Removing publication from the library" << endl;
        int ref = search(1);
        if (ref && confirm("Remove this publication from the library?")) {
            int i;
            Publication* result = nullptr;
            for (i = 0; i < NOLP; i++) {
                if (PPA[i]->getRef() == ref) {
                    result = PPA[i];
                }
            }
            result->setRef(0);
            cout << "Publication removed" << endl;
            m_changed = true;
        }
        cout << endl;
    }

    void LibApp::checkOutPub() {

        cout << "Checkout publication from the library" << endl;
        int ref = search(3);
        if (ref > 0 && confirm("Check out publication?")) {
            cout << "Enter Membership number: ";
            int inputMembership = getUserInput(10000, 99999);
            int i;
            Publication* result = nullptr;
            for (i = 0; i < NOLP; i++) {
                if (PPA[i]->getRef() == ref) {
                    result = PPA[i];
                }
            }
            result->set(inputMembership);
            m_changed = true;
            cout << "Publication checked out" << endl;
        }
        cout << endl;
    }

    void LibApp::run() {
        int menuSelection;
        int exitSelection;

        do {
            menuSelection = m_mainMenu.run();

            switch (menuSelection) {
            case 0:
                if (m_changed == true) {
                    exitSelection = m_exitMenu.run();
                    switch (exitSelection) {
                    case 0:
                        if (confirm("This will discard all the changes are you sure?")) {
                            m_changed = false;
                        }
                        break;

                    case 1:
                        save();
                        break;

                    case 2:
                        menuSelection = 1;
                        break;
                    }
                }
                cout << endl;
                break;

            case 1:
                newPublication();
                break;

            case 2:
                removePublication();
                break;

            case 3:
                checkOutPub();
                break;

            case 4:
                returnPub();
                break;
            }
        } while (menuSelection != 0);

        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }



}