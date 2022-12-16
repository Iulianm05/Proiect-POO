
#ifndef MAIN_CPP_OFFENSIVE_COACH_H
#define MAIN_CPP_OFFENSIVE_COACH_H
#include "coach.h"

class offensive_coach:public coach {
    int abilitate_ofensiva{};
    std::string formatie{};
    void afisare(std::ostream &os) const override;
public:
    explicit offensive_coach(const std::string &nume,int varsta=0,int abilitate_ofensiva=0,std::string formatie_="" );
    std::shared_ptr<coach> clone()const override;
    void boost_echipa(int &gol_boost, int &draw, int &gol_a, int &ocazii) const override;


};




#endif //MAIN_CPP_OFFENSIVE_COACH_H
