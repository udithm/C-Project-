#include "Solver.h"
#include<bits/stdc++.h>

bool Solver::Is_valid_eq(){
    if(E1.Is_valid_ex()==true && E2.Is_valid_ex()==true){
        if(E1.get_x_coeff()==E2.get_x_coeff()){
            return false;
        }
        return true;
    }
    else{
        return false;
    }
    return false;
}

string Solver::solve(){
    if(Is_valid_eq()==false){
        cout<<"No Solution"<<endl;
        return "No Solution";
    }
    //cout<<E2.get_cons()-E1.get_cons();
    //cout<<E1.get_x_coeff()-E2.get_x_coeff();
    float y=(E2.get_cons()-E1.get_cons())/(E1.get_x_coeff()-E2.get_x_coeff());
    cout<<"x="<<setprecision(4)<<y<<endl;
    return "x="+to_string(y); 
}

