

#include "exceptions.h"

eroare_aplicatie::eroare_aplicatie(const std::string &msj) : runtime_error(msj) {

}

eroare_meci::eroare_meci(const std::string &msj) : eroare_aplicatie(msj) {

}

eroare_competitie::eroare_competitie(const std::string &msj): eroare_aplicatie(msj) {

}
