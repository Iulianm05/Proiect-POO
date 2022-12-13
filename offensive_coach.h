
#ifndef MAIN_CPP_OFFENSIVE_COACH_H
#define MAIN_CPP_OFFENSIVE_COACH_H
#include "coach.h"
#include "offensive_coach.h"

class offensive_coach:public coach {
    int abilitate_ofensiva{};
    std::string formatie{};
    void afisare(std::ostream &os) const override;
public:
    explicit offensive_coach(const std::string &nume,int varsta=0,int abilitate_ofensiva=0,std::string formatie_="" );
    [[nodiscard]] std::shared_ptr<coach> clone()const override;
    void boost_echipa() const override;


};


#endif //MAIN_CPP_OFFENSIVE_COACH_H
