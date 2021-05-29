#include"Input_decoder.h"
#include"Equation.h"
#include"Solver.h"
#include<bits/stdc++.h>

using namespace std;

string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

bool Input_decoder::checkTask3()
{
    char arr[str.length()+1];
    strcpy(arr,str.c_str());
    
    char* token=strtok(arr,"=");
    char* lhs=token;
    token=strtok(NULL,"=");
    char* rhs=token;
    
    int flag_lhs=1;int flag_rhs=1;
    int flag_x1=0;int flag_x2=0;
    
    for(int i=0;i<strlen(lhs);i++)
    {
      if(lhs[i]=='x'){
        flag_x1=1;
      }
      if(lhs[i]=='^' || lhs[i]>=97 && lhs[i]<=122 && lhs[i]!='x')
      {
        flag_lhs=0;
        break;
      }
    }
    
    for(int i=0;i<strlen(rhs);i++)
    {
      if(rhs[i]=='x'){
        flag_x2=1;
      }
      if(rhs[i]=='^' || rhs[i]>=97 && rhs[i]<=122 && rhs[i]!='x')
      {
        flag_rhs=0;
        break;
      }
    }
    if(flag_lhs && flag_rhs)
    {
      Input_decoder::splitter();
      return true;
    }
    return false;
}

void Input_decoder::splitter(){
    vector<float> x1_l;
    vector<float> c1_l;
    vector<float> x2_l;
    vector<float> c2_l;
    vector<string> parts1;
    vector<string> parts2;
    float x1_sum=0;
    float x2_sum=0;
    float c1_sum=0;
    float c2_sum=0;

    char arr[str.length()+1];
    strcpy(arr,str.c_str());
    //cout<<str<<endl;
    //cout<<arr<<endl;
    // cout<<"dsfafdsghf";
    char* token=strtok(arr,"=");
    char* lhs=token;
    token=strtok(NULL,"=");
    char* rhs=token;
    //cout<<rhs<<endl;
    
    char* lhs_dup=strdup(lhs);
    //cout<<lhs_dup<<endl;
    char* rhs_dup=strdup(rhs);
    
    char* tokenlhs=strtok(lhs,"+-");
    if(lhs[0]=='-' && tokenlhs!=NULL)
      parts1.push_back("-"+convertToString(tokenlhs,strlen(tokenlhs)));
    else
      parts1.push_back(convertToString(tokenlhs,strlen(tokenlhs)));
    
    while(tokenlhs!=NULL)
    {
      char delim=lhs_dup[tokenlhs-lhs+strlen(tokenlhs)];
      tokenlhs=strtok(NULL,"+-");
      if(tokenlhs!=NULL)
      {
        string tokenlhs_str=convertToString(tokenlhs,strlen(tokenlhs));
        if(delim=='+')
        {
          parts1.push_back(tokenlhs_str);
        }
        else if(delim=='-')
        {
          parts1.push_back("-"+tokenlhs_str);
        }
      }
    }

    char* tokenrhs=strtok(rhs,"+-");
    if(rhs[0]=='-' && tokenrhs!=NULL)
      parts2.push_back("-"+convertToString(tokenrhs,strlen(tokenrhs)));
    else
      parts2.push_back(convertToString(tokenrhs,strlen(tokenrhs)));

    while(tokenrhs!=NULL)
    {
      char delim1=rhs_dup[tokenrhs-rhs+strlen(tokenrhs)];
      tokenrhs=strtok(NULL,"+-");
      if(tokenrhs!=NULL)
      {
        string tokenrhs_str=convertToString(tokenrhs,strlen(tokenrhs));
        if(delim1=='+')
        {
          parts2.push_back(tokenrhs_str);
        }
        else if(delim1=='-')
        {
          parts2.push_back("-"+tokenrhs_str);
        }
      }
    }

    //LHS decoding
    for(vector<string>::iterator i=parts1.begin();i<parts1.end();i++)
    {
        string s=*i;
        if(s[0]=='x'){
            s="1"+s;
        }
        if(s[s.length()-1]=='x'){
            if(s[0]=='-'){
                if(s[1]=='x'){
                    s="-1"+s.substr(1,s.length()-1);
                }
                s=s.substr(1,s.length()-2);
                int term=-stof(s);
                x1_l.push_back(term);
            }
            else{
                s=s.substr(0,s.length()-1);
                x1_l.push_back(stof(s));
            }
        }
        else{
            if(s[0]=='-'){
                s=s.substr(1,s.length()-1);
                int term=-stof(s);
                c1_l.push_back(term);
            }
            else{
                s=s.substr(0,s.length());
                c1_l.push_back(stof(s));
            }
        }
    }
    for(vector<float>::iterator i=x1_l.begin();i<x1_l.end();i++){
      //cout<<*i<<endl;
      x1_sum+=*i;
    }
    for(vector<float>::iterator i=c1_l.begin();i<c1_l.end();i++){
      //cout<<*i<<endl;
      c1_sum+=*i;
    }
    
    //RHS decoding
    for(vector<string>::iterator i=parts2.begin();i<parts2.end();i++)
    {
        string s=*i;
        if(s[0]=='x'){
            s="1"+s;
        }
        if(s[s.length()-1]=='x'){
            if(s[0]=='-'){
                if(s[1]=='x'){
                    s="-1"+s.substr(1,s.length()-1);
                }
                s=s.substr(1,s.length()-2);
                int term=-stof(s);
                x2_l.push_back(term);
            }
            else{
                s=s.substr(0,s.length()-1);
                x2_l.push_back(stof(s));
            }
        }
        else{
            if(s[0]=='-'){
                s=s.substr(1,s.length()-1);
                int term=-stof(s);
                c2_l.push_back(term);
            }
            else{
                s=s.substr(0,s.length());
                c2_l.push_back(stof(s));
            }
        }
    }
    for(vector<float>::iterator i=x2_l.begin();i<x2_l.end();i++){
      //cout<<*i<<endl;
      x2_sum+=*i;
    }
    for(vector<float>::iterator i=c2_l.begin();i<c2_l.end();i++){
      //cout<<*i<<endl;
      c2_sum+=*i;
    }
    //cout<<x1_sum;
    //cout<<c1_sum;
    //cout<<x2_sum;
    //cout<<c2_sum;
    //cout<<E1.x_coeff;
    E1.x_coeff=x1_sum;
    E1.cons=c1_sum;
    E2.x_coeff=x2_sum;
    E2.cons=c2_sum; 
}




       
