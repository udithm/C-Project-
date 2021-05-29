#ifndef E
#define E

#include<bits/stdc++.h>

class Equation{
    public:
        float x_coeff;
        float cons;

        Equation(int ix,int icons){
            this->x_coeff=ix;
            this->cons=icons;
        }
        Equation(){}

        float get_x_coeff();
        float get_cons();
        bool Is_valid_ex();

};
#endif