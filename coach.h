//
// Created by Marin Iulian on 10/26/2022.
//

#ifndef MAIN_CPP_COACH_H
#define MAIN_CPP_COACH_H
#include <string>
#include <iostream>
#include <memory>
/*
 class coach {
    std::string coach_name;
    std::string style;
    int age;
public:
    coach();
    explicit coach(const std::string &coachName, const std::string &style="", int age=0);
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

 */

class coach {
    std::string nume;
    int varsta{};
public:
    coach(coach &&other) = default;
    coach &operator=(coach &&other) = default;
protected:
    coach(const coach &other) = default;
    coach &operator=(const coach &other) = default;
public:
    virtual std::shared_ptr<coach> clone() const =0;
    virtual void boost_echipa(int &gol_boost, int &draw, int &gol_a, int &ocazii) const=0;
    friend std::ostream &operator<<(std::ostream &os,const coach &coach_);
    explicit coach(std::string nume_,int varsta);
    virtual ~coach();
    std::string get_name();

    int getVarsta() const;

private:
    virtual void afisare(std::ostream &) const{};
};



#endif //MAIN_CPP_COACH_H
