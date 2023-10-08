#ifndef USAGER_H
#define USAGER_H
#include <string>
#include <ostream>
#include <vector>
using namespace std;

class Usager {
public:
    Usager(string login, string group);

    const string & getLogin() const;
    const string & getGroup() const;

    void setLogin(string nouv_login);
    void setGroup(string nouv_group);
private:
    string m_login;
    string m_group;
};

#endif /* USAGER_H */

