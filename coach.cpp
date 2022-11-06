//
// Created by Marin Iulian on 10/26/2022.
//

#include "coach.h"

coach::coach(){}
coach::coach(const std::string &coachName_, const std::string &style_, int age_): coach_name{coachName_}, style{style_}, age{age_} {

}
std::ostream& operator<<(std::ostream& os, const coach& coach1){
    os<<"Numele antrenorului "<<coach1.coach_name<<", varsta :"<<coach1.age<<", stil de joc: "<<coach1.style<<std::endl;
    return os;
}