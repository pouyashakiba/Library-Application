/*******************************************************
 * Pouya Shakiba
 * pshakiba@myseneca.ca
 * 2024/05/15
 *******************************************************/

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

