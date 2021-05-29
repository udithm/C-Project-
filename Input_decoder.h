#ifndef I
#define I

#include<bits/stdc++.h>
#include"Equation.h"
#include"Solver.h"

class Input_decoder{
    public:
        string str;
        Equation E1,E2;

        Input_decoder(string is){
            this->str=is;
            E1.cons=0;
            E2.cons=0;
            E1.x_coeff=0;
            E2.x_coeff=0;    
        }
        Input_decoder(){}

        bool checkTask3();  
        void splitter();
        

};
#endif