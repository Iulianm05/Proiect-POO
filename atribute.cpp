

#include "atribute.h"
//template <typename T>
//atribute<T>::atribute() =default;
template <typename T>
atribute<T>::atribute(T a, T d, T p,T s, T drib): attacking(a),defending(d),passing(p),Strength(s),dribling(drib){

    //std::cout<<"c attributes\n";
}
template <typename T>
atribute<T>::~atribute()=default;

//std::ostream& operator<< (std::ostream& os, const atribute<int>& atribute1){
//    os<<"Atac: "<<atribute1.attacking<<", dribling: "<<atribute1.dribling<<", Strength: "<<atribute1.Strength<<", defending: "<<atribute1.defending<<", pase: "<<atribute1.passing<<std::endl;
//    return os;
//}
template <typename T>
T atribute<T>::getAttacking() const {
    return attacking;
}
template <typename T>
T atribute<T>::getDefending() const {
    return defending;
}
template <typename T>
T atribute<T>::getPassing() const {
    return passing;
}
template <typename T>
T atribute<T>::getStrength() const {
    return Strength;
}
template <typename T>
T atribute<T>::getDribling() const {
    return dribling;
}
