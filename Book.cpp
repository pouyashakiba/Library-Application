//name:pouya shakiba email:pshakib@myseneca.com id:117389221 Date: 2/8/2023
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Book.h"
#include "Utils.h"
using namespace std;
namespace sdds {


    Book::Book(const Book& book) {
        *this = book;
    }

    Book& Book::operator=(const Book& book) {
        if (this != &book) {
            Publication::operator=(book);
            delete[] m_authorName;
            if (book.m_authorName) {
                m_authorName = new char[strLen(book.m_authorName) + 1];
                strCpy(m_authorName, book.m_authorName);
            }
            else {
                m_authorName = nullptr;
            }
        }
        return *this;
    }

    Book::~Book() {
        delete[] m_authorName;
    }

    char Book::type() const {
        return 'B';
    }

    std::ostream& Book::write(std::ostream& os) const {

        char temp[SDDS_AUTHOR_WIDTH + 1]{};
        Publication::write(os);
        if (conIO(os)) {
            strnCpy(temp, m_authorName, SDDS_AUTHOR_WIDTH);
            os << ' ';
            os.width(SDDS_AUTHOR_WIDTH);
            os.fill(' ');

            os << std::left << temp << " |";
            os.unsetf(ios::left);
        }
        else {
            os << "\t" << m_authorName;
        }
        return os;
    }

    std::istream& Book::read(std::istream& is) {
        char temp[256]{ 0 };
        Publication::read(is);
        delete[] m_authorName;
        if (conIO(is)) {
            is.ignore();
            cout << "Author: ";
        }
        else {
            is.ignore(1000, '\t');
        }
        is.get(temp, 256);
        if (is) {
            m_authorName = new char[strLen(temp) + 1];
            strCpy(m_authorName, temp);
        }
        return is;
    }


    void Book::set(int member_id) {
        Publication::set(member_id);
        Publication::resetDate();
    }

    Book::operator bool() const {
        return m_authorName && Publication::operator bool();
    }
}
