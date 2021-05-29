#include "Equation.h"

float Equation::get_x_coeff(){
    return this->x_coeff;
}

float Equation::get_cons(){
    return this->cons;
}

bool Equation::Is_valid_ex(){
    if(this->get_x_coeff()==0){
        return false;
    }
    return true;
}
