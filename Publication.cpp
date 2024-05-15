//name:pouya shakiba email:pshakib@myseneca.com id:117389221 Date: 28/7/2023
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Publication.h"
#include "Lib.h"
#include "Utils.h"
#include <iomanip>
using namespace std;

namespace sdds {



    Publication::Publication(const Publication& publication) {
        *this = publication;
    }

    Publication& Publication::operator=(const Publication& publication) {
        set(publication.m_membership);
        setRef(publication.m_libRef);
        strCpy(m_shelfId, publication.m_shelfId);
        m_date = publication.m_date;

        if (this) {
            delete[] m_title;
            m_title = nullptr;
        }
        if (publication.m_title != nullptr) {
            m_title = new char[strLen(publication.m_title) + 1];
            strCpy(m_title, publication.m_title);
        }
        else {
            m_title = nullptr;
        }
        return *this;
    }

    Publication::~Publication() {
        delete[] m_title;
    }

    void Publication::set(int member_id) {
        if (member_id < 100000 && member_id > 9999) {
            m_membership = member_id;
        }
        else {
            m_membership = 0;
        }
    }

    void Publication::setRef(int value) {
        m_libRef = value;
    }

    void Publication::resetDate() {
        m_date = Date();
    }

    char Publication::type() const {
        return 'P';
    }

    bool Publication::onLoan() const {
        return m_membership != 0;
    }

    Date Publication::checkoutDate() const {
        return m_date;
    }

    bool Publication::operator==(const char* title) const {
        return strStr(m_title, title) != nullptr;
    }

    Publication::operator const char* () const {
        return m_title;
    }

    int Publication::getRef() const {
        return m_libRef;
    }

    std::ostream& Publication::write(std::ostream& os) const {
        char temp[SDDS_TITLE_WIDTH + 1]{};
        strnCpy(temp, m_title, SDDS_TITLE_WIDTH);
        if (conIO(os)) {
            os << "| " << m_shelfId << " | ";
            os.width(SDDS_TITLE_WIDTH);
            os.fill('.');
            os << std::left << temp << " | ";
            os.unsetf(ios::left);
            if (m_membership != 0) {
                os << m_membership;
            }
            else {
                os << " N/A ";
            }
            os << " | " << m_date << " |";
        }
        else {
            os << type() << "\t";
            os << m_libRef << "\t";
            os << m_shelfId << "\t";
            os << m_title << "\t";

            if (onLoan()) {
                os << m_membership;
            }
            else {
                os << "0";
            }
            os << "\t" << m_date;
        }
        return os;
    }

    std::istream& Publication::read(std::istream& is) {
        char tempT[256]{}, tempS[SDDS_SHELF_ID_LEN + 1]{};
        int tempL = -1, tempM = 0;
        Date tempD;
        delete[] m_title;

        //setting all the variables to their default values
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        resetDate();

        if (conIO(is)) {
            std::cout << "Shelf No: ";
            is.getline(tempS, SDDS_SHELF_ID_LEN + 1);
            //checking if the shelf id is valid
            if (strLen(tempS) != SDDS_SHELF_ID_LEN) {
                is.setstate(std::ios::failbit);
            }

            std::cout << "Title: ";
            is.getline(tempT, 256);
            std::cout << "Date: ";
            is >> tempD;
        }
        else {
            is >> tempL;
            is.ignore();
            is.getline(tempS, SDDS_SHELF_ID_LEN + 1, '\t');
            is.getline(tempT, 256, '\t');
            is >> tempM;
            is.ignore();
            is >> tempD;
        }

        if (!tempD) {
            is.setstate(std::ios::failbit);
        }

        if (is) {
            m_title = nullptr;
            m_title = new char[strLen(tempT) + 1];
            strCpy(m_title, tempT);

            strCpy(m_shelfId, tempS);
            m_membership = tempM;
            m_date = tempD;
            m_libRef = tempL;
        }

        return is;
    }

    bool Publication::conIO(std::ios& ios)const {
        return (&ios == &cin || &ios == &cout);
    }

    //returns true if streamable is valid, otherwise returns false
    Publication::operator bool()const {
        return m_title;
    }
}