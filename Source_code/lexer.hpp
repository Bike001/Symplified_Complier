//
//  lexer.hpp
//  parser
//
//  Created by YuSoo on 11/8/22.
//

#ifndef lexer_hpp
#define lexer_hpp
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
 

using namespace std;
extern bool _switch;
extern ifstream file;
extern ofstream outFile;
extern string newtoken;
extern string newlexme;

/* * * function for separator  * * * * * * * * * * * * * * * * * * * * * * * * * * */
bool isSeparator(const string input);

/* * * * function for operater * * * * * * * * * * * * * * * * * * * * * * * * * */
 
bool isOperator(const string input);


/* * * * function for keyword * * * * * * * * * * * * * * * * * * * * * * * * * */

bool isKeyword(string str);


/* * * *  DFSM of identifier line 59-164 * * * * * * * ** * * * * * * * * * * * */


bool isIdentifier(string str);




/* * * *  DFSM of identifier line 172-234 * * * * * * * ** * * * * * * * * * * * */





bool isInteger(string str);


      
/* * * *  DFSM of Real line 1238-343 * * * * * * * ** * * * * * * * * * * * */


bool isReal(string str);

 


string remove(ifstream& file);


void lexer(ifstream& file);

void check (string str);

#endif /* lexer_hpp */

