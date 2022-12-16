
#ifndef MAIN_CPP_DEFENSIVE_COACH_H
#define MAIN_CPP_DEFENSIVE_COACH_H


#include <string>
#include "coach.h"

class defensive_coach:public coach {
    int abilitate_defensiva{};

    void afisare(std::ostream &os) const override;
public:
    int getAbilitateDefensiva() const;
    explicit defensive_coach(const std::string &nume1,int varsta1=0, int abilitate_defensiva=0);
    std::shared_ptr<coach> clone() const override;
    void boost_echipa(int &gol_boost, int &draw, int &gol_a, int &ocazii) const override;
};


#endif //MAIN_CPP_DEFENSIVE_COACH_H
