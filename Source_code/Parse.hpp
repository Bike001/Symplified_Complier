//
//  Parse.hpp
//  parser
//
//  Created by YuSoo on 11/9/22.
//

#ifndef Parse_hpp
#define Parse_hpp

#include <stdio.h>
#include "lexer.hpp"
#include <vector>
#include <fstream>
 



using namespace std;
 
extern string outputfilename2;
extern ofstream outFile2;
 

void print_sym();

int get_address(string save);

void backPatch(int jump_addr);
void print_instruct(ifstream& file);
void Rat22F(ifstream& file);
 
      
 

    
 void Qualifier(ifstream& file);
              
    

                  
   void OptDeclarationList(ifstream& file);
       
    
    void DeclarationList(ifstream& file);
                     
              
    void DeclarationListPrime(ifstream& file);
      
    void Declaration(ifstream& file);
            
    void IDs(ifstream& file);
                 
 
    void IDsPrime(ifstream& file);
             
    void StatementList(ifstream& file);
   
    void StatementListPrime(ifstream& file);
     
    void Statement(ifstream& file);
    void Compound(ifstream& file);
      
   
 void Assign(ifstream& file);
       
 void If(ifstream& file);
        
 void IfPrime(ifstream& file);
       
void Return(ifstream& file);
void ReturnPrime(ifstream& file);
void Print(ifstream& file);
 
void Scan(ifstream& file);
 
void While(ifstream& file);
 
 
void Condition(ifstream& file);
 
void Relop(ifstream& file);
 
void Expression(ifstream& file);
 
 
void ExpressionPrime(ifstream& file);
 
void Term(ifstream& file);
 
void TermPrime(ifstream& file);
void Factor(ifstream& file);
 
void Primary(ifstream& file);
void PrimaryPrime(ifstream& file);







#endif /* Parse_hpp */

