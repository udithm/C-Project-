#include <bits/stdc++.h>
#include"Equation.h"
#include"Solver.h"
#include"Input_decoder.h"

int main(){
    string s;
    getline(cin,s);
    Input_decoder in(s);
    in.checkTask3();
    Solver sol(in.E1,in.E2);
    sol.solve();
    return 0;
}