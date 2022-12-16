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

void offensive_coach::boost_echipa(int &gol_boost, int &draw, int &gol_a, int &ocazii) const {
   // std::cout<<"Boost ofensiv!\n";
    gol_boost=gol_boost+4;
    draw=draw-2;
    gol_a=gol_a-2;
    ocazii=ocazii+2;

}


