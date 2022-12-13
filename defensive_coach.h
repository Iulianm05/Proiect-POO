
#ifndef MAIN_CPP_DEFENSIVE_COACH_H
#define MAIN_CPP_DEFENSIVE_COACH_H


#include <string>
#include "coach.h"

class defensive_coach:public coach {
    int abilitate_defensiva{};

    void afisare(std::ostream &os) const override;
public:
    int getAbilitateDefensiva() const;
    defensive_coach(const std::string &nume1,int varsta1=0, int abilitate_defensiva=0);
     std::shared_ptr<coach> clone() const override;
    void boost_echipa() const override;
};


#endif //MAIN_CPP_DEFENSIVE_COACH_H
