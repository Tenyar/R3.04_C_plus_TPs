#include "Usager.h"

// à compléter
Usager::Usager(string login, string group) :  m_login(login), m_group(group){}

const string & Usager::getLogin() const {
    return this->m_login;
}

const string & Usager::getGroup() const {
    return this->m_group;
}

void Usager::setLogin(string nouv_login) {
    this->m_login = nouv_login;
}

void Usager::setGroup(string nouv_group) {
    this->m_group = nouv_group;
}



