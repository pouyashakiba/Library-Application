//name:pouya shakiba email:pshakib@myseneca.com id:117389221 Date: 28/7/2023
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Streamable.h"
namespace sdds {
	std::ostream& operator<<(std::ostream& os, const Streamable& s) {

		if (s) {
			s.write(os);
		}
		return os;
	}

	std::istream& operator>>(std::istream& is, Streamable& s) {
		return (s.read(is));
	}
}

