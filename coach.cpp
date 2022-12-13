//
// Created by Marin Iulian on 10/26/2022.
//

#include "coach.h"

/*
 coach::coach(){}
coach::coach(const std::string &coachName_, const std::string &style_, int age_): coach_name{coachName_}, style{style_}, age{age_} {

}
std::ostream& operator<<(std::ostream& os, const coach& coach1){
    os<<"Numele antrenorului "<<coach1.coach_name<<", varsta :"<<coach1.age<<", stil de joc: "<<coach1.style<<std::endl;
    return os;
}
  */
coach::coach(std::string nume_,int varsta_):nume(std::move(nume_)), varsta(varsta_) {}

std::ostream &operator<<(std::ostream &os, const coach &coach_) {
    os<<"Antrenor:"<<coach_.nume;
    coach_.afisare(os);
    os<<"\n";
    return os;
}

std::string coach::get_name() {
    return this->nume;
}

int coach::getVarsta() const {
    return varsta;
}

coach::~coach()=default;

