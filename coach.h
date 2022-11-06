//
// Created by Marin Iulian on 10/26/2022.
//

#ifndef MAIN_CPP_COACH_H
#define MAIN_CPP_COACH_H
#include <string>
#include <iostream>

class coach {
    std::string coach_name;
    std::string style;
    int age;
public:
    coach();
    coach(const std::string &coachName, const std::string &style, int age);
    //getters pentru ostream team
    std::string get_name()const{
        return coach_name;
    }
    std::string get_style(){
        return style;
    }
    int get_age(){
        return age;
    }
    friend std::ostream& operator<<(std::ostream& os, const coach& coach1);
};


#endif //MAIN_CPP_COACH_H
