#include "offensive_coach.h"



void offensive_coach::afisare(std::ostream &os) const {
    os<<"Stil ofensiv; abilitate ofensiva "<<abilitate_ofensiva;
}

offensive_coach::offensive_coach(const std::string &nume_, int varsta_, int abilitate_ofensiva_, std::string formatie_):coach(nume_,varsta_),
                                                                                                                        abilitate_ofensiva(abilitate_ofensiva_),
                                                                                                                        formatie(std::move(formatie_)) {}

std::shared_ptr<coach> offensive_coach::clone() const {
    return std::make_shared<offensive_coach>(*this);
}

void offensive_coach::boost_echipa() const {
    std::cout<<"Echipa in timpul meciului va avea o sansa mai mare de a marca goluri\n";
}


