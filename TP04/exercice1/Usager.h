#ifndef USAGER_H
#define USAGER_H
#include "Element.h"
#include <string>
#include <ostream>
#include <vector>
using namespace std;

class Usager {
public:
    Usager(string login, string group);

    void ajoutElement(Element & e);

    const string & getLogin() const;
    const string & getGroup() const;

    void setLogin(string nouv_login);
    void setGroup(string nouv_group);
private:
    string m_login;
    string m_group;
};

#endif /* USAGER_H */

