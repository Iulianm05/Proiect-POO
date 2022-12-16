

#ifndef MAIN_CPP_EXCEPTIONS_H
#define MAIN_CPP_EXCEPTIONS_H

#include <stdexcept>

class eroare_aplicatie:public std::runtime_error {
public:
    explicit eroare_aplicatie(const std::string &msj);

};

class eroare_meci: public eroare_aplicatie {
public:
    explicit eroare_meci(const std::string &msj);
};

class eroare_competitie: public eroare_aplicatie{
public:
    explicit eroare_competitie(const std::string &msg);
};

#endif //MAIN_CPP_EXCEPTIONS_H
