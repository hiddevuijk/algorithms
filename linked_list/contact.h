#ifndef GUARD_CONTACT_H
#define GUARD_CONTACT_H

class Contact {
private:
	friend std::ostream& operator << (std::ostream& os, const Contact&c);

public:
	Contact(std::string name = "none");


};


#endif
