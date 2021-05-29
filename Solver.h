#ifndef S
#define S

#include<bits/stdc++.h>
#include"Equation.h"

using namespace std;

class Solver{
    public:
        Equation E1,E2;
        bool flag=true;

        Solver(Equation e1,Equation e2){
            this->E1=e1;
            this->E2=e2;
        }
        Solver(){}

        bool Is_valid_eq();
        string solve();
};
#endif