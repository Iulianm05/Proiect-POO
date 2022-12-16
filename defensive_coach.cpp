

#include "defensive_coach.h"


defensive_coach::defensive_coach(const std::string &nume1, int varsta1, int abilitate_defensiva_):coach(nume1,varsta1),
                                                                                                    abilitate_defensiva(abilitate_defensiva_) {}

int defensive_coach::getAbilitateDefensiva() const {
    return this->abilitate_defensiva;
}

void defensive_coach::afisare(std::ostream &os) const {
    os<<" Stil defensiv, abilitate defensiva:"<<abilitate_defensiva<<std::endl;
}

std::shared_ptr<coach> defensive_coach::clone() const {
    return std::make_shared<defensive_coach> (*this);
}

void defensive_coach::boost_echipa(int &gol_boost, int &draw, int &gol_a, int &ocazii) const {
   //std::cout<<"boost defensiv!\n";
   gol_boost+=1;
   draw+=4;
   gol_a-=5;
   ocazii-=2;
}

