//
//  lexer.cpp
//  parser
//
//  Created by YuSoo on 11/8/22.
//

#include "lexer.hpp"

bool _switch = false;
ifstream file;
ofstream outFile;
string newtoken;
string newlexme;
string str_nor{};
string str_ope{};//initialize str to store lexeme
string str_sep{};

/* * * function for separator  * * * * * * * * * * * * * * * * * * * * * * * * * * */
bool isSeparator(const string input)
{
    string separator[11] = { "(", ")", "{", "}", "%", "@", ",", "[", "]", ";" ,"$"};
    for (int i = 0; i < 11; i++) {
        if (separator[i] == input) {
            return 1;
        }
    }
    return 0;
}
/* * * * function for operater * * * * * * * * * * * * * * * * * * * * * * * * * */
 
bool isOperator(const string input)
{
    string operators[12] = { "+", "-", "/", "*", "<",">",":", "=", ">=" , "=>" , "!=" , "=="};
    for (int i = 0; i < 12; i++) {
        if (operators[i] == input) {
            return 1;
        }
    }
    return 0;

}

/* * * * function for keyword * * * * * * * * * * * * * * * * * * * * * * * * * */

bool isKeyword(string str)
{
    string keywords[16] = { "while", "if", "endif", "else", "return",
        "read", "write", "integer", "true", "false", "boolean", "floating" , "function", "real", "put", "get" };
    for (int i = 0; i < 16; i++) {
        if (keywords[i] == str) {
            return 1;
        }
    }
    return 0;
}

/* * * *  DFSM of identifier line 59-164 * * * * * * * ** * * * * * * * * * * * */

int dfa = 0;


// the starting state (Q1)of DFSM
void start(char c) {

    if (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z') {
        dfa = 2;
    }
    else if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '_') {
        dfa = 5;
    }

    // -1 is used to check for any invalid symbol
    else {
        dfa = -1;
    }
}

// This function is for the first state (Q2) of DFSM
void state2(char c)
{
    if (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' ||c == 'x' ||  c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' || c == 'W' ||  c == 'X' || c == 'Y' || c == 'Z') {
        dfa = 3;
    }
    else if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '_') {
        dfa = 4;
    }

    // -1 is used to check for any invalid symbol
    else {
        dfa = -1;
    }
}

// This function is for the second state (Q3) of DFSM
void state3(char c)
{
    if (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' ||c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z') {
        dfa = 3;
    }
    else if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '_') {
        dfa = 4;
    }

    // -1 is used to check for any invalid symbol
    else {
        dfa = -1;
    }
}

// This function is for the third state (Q4)of DFSM
void state4(char c)
{
    if (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' ||c == 'x' ||  c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z') {
        dfa = 3;
    }
    else if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '_') {
        dfa = 4;
    }

    // -1 is used to check for any invalid symbol
    else {
        dfa = -1;
    }
}



void state5(char c)
{
    dfa = -1;
}

bool isIdentifier(string str)
{
    
    int i;
    size_t len = str.size();  // store length of string
    dfa = 0;
    for (i = 0; i < len; i++) {
        if (dfa == 0)
            start(str[i]);

        else if (dfa == 2)
            state2(str[i]);

        else if (dfa == 3)
            state3(str[i]);

        else if (dfa == 4)
            state4(str[i]);

        else if (dfa == 5)
            state5(str[i]);
        else
            return 0;
    }

    if (dfa == 2 || dfa == 3 || dfa == 4){
        
    
        return 1;}
       
    else
        return 0;
}




/* * * *  DFSM of identifier line 172-234 * * * * * * * ** * * * * * * * * * * * */


int sta = 0;


// the starting state (Q1)of DFSM
void integerstart(char c)
{

    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {
        sta = 2;
    }

    // -1 is used to check for any invalid symbol
    else {
        sta = -1;
    }
}

//  state (Q2) of DFSM
void integerstate2(char c)
{
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {
        sta = 2;
    }


    // -1 is used to check for any invalid symbol
    else {
        sta = -1;
    }
}




void integerstate3(char c)
{
    sta = -1;
}


bool isInteger(string str)
{
    sta = 0;
    int i;
    size_t len = str.size();  // store length of string

    for (i = 0; i < len; i++) {
        if (sta == 0)
            integerstart(str[i]);

        else if (sta == 2)
            integerstate2(str[i]);


        else
            return 0;
    }
    if (sta == 2){
       
        return 1;}
       
    else
        return 0;}

/* * * *  DFSM of Real line 1238-343 * * * * * * * ** * * * * * * * * * * * */

int sta1 = 0;


// the starting state (Q1)of DFSM
void realstart(char c)
{

    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {
        sta1 = 2;
    }
    else if (c == '.') {
        sta1 = 5;
    }
    // -1 is used to check for any invalid symbol
    else {
        sta1 = -1;
    }
}

// state (Q2) of DFSM
void realstate2(char c)
{
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {
        sta1 = 2;
    }
    else if (c == '.') {
        sta1 = 3;
    }

    // -1 is used to check for any invalid symbol
    else {
        sta1 = -1;
    }
}


void realstate3(char c)
{
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {
        sta1 = 4;
    }
    else if (c == '.') {
        sta1 = 5;
    }

    // -1 is used to check for any invalid symbol
    else {
        sta1 = -1;
    }
}


void realstate4(char c)
{
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {
        sta1 = 4;
    }
    else if (c == '.') {
        sta1 = 5;
    }

    // -1 is used to check for any invalid symbol
    else {
        sta1 = -1;
    }
}


void realstate5(char c)
{
    sta = -1;
}


bool isReal(string str)
{
    sta1 = 0;
    int i;
    size_t len = str.size(); // store length of string

    for (i = 0; i < len; i++) {
        if (sta1 == 0)
            realstart(str[i]);

        else if (sta1 == 2)
            realstate2(str[i]);

        else if (sta1 == 3)
            realstate3(str[i]);

        else if (sta1 == 4)
            realstate4(str[i]);

        else if (sta1 == 5)
            realstate5(str[i]);

        else
            return 0;
    }
    if (sta1 == 4){
        
        return 1;}
       
    else
        return 0;
}


/* * * *  lexer function * * * * * * * ** * * * * * * * * * * * */
void lexer(ifstream& file)
{
    
    if (str_sep.size() > 0){
            check(str_sep);

        return;}

    
    char ch = 'c';
    
    while (!file.eof()){
        
        
       // bool found = false;
        
        /*use loop to add char to string, if the char is separator, operator or whitespace
         pop the char and break the loop. If not, add the char to the back of the string */
        
        
       // while (!found)
        //{
            if (file.eof()) {
               
                break;}
        
            ch = file.get();
        
            string s{};
        
            s.push_back(ch);
        
          //  cout <<"this is " <<s << endl;
            
            if (!isSeparator(s) && !isOperator(s) && !isspace(ch)   )
            {
                str_nor += ch;
//                if (str_sep.size() > 0){
//                    check (str_spe);
//                    return;
                //}
                 if (str_ope.size() > 0){
                    check (str_ope);
                    return;
                }
            }
            
        if (isSeparator(s)  ){
            
            str_sep += ch;
            
            if (str_nor.size() > 0){
                check(str_nor);
                return;
            }
            if (str_sep.size() > 0){
                check(str_sep);
                return;}
            
           
        }
                
                if ( isOperator(s)   ){
                    
                    str_ope += ch;
                   
                    
                    if (str_nor.size() > 0){
                        check(str_nor);
                        return;
                    }
                
                //            if (str_notnor.size() > 2)
                //            {
                //
                //                cout << "error token" << endl;
                
            }
            if(isspace(ch))
            {
                if (str_nor.size() > 0){
                    check(str_nor);
                    return;                }
                if (str_ope.size() > 0){
                    check (str_ope);
                    return;                }
            
                if (str_sep.size() > 0){
                    check (str_sep);
                    return;                }
            }
            
        //}
    }
    newlexme = "EOF";
    
}
            /* verify if it is keyword, ientifier, integer, real, separator or operator, if verified,
             print the data to the file and the console   * * * * * * * * * * * * * * * * * * * *  */
            
   void check (string str){
                
            if (str == "")
            {
                return;
            }
       
            if (isKeyword(str)){
                newtoken = "Keyword";
                newlexme = str;
                str = "";
                str_nor = "";
                if (_switch){
                    cout << left  <<"Token: "  << setw(20)<< newtoken  <<"Lexeme: "<< newlexme << endl;
                    outFile << left  <<"Token: "  << setw(20)<< newtoken  <<"Lexeme: "<< newlexme << endl;}
                return;
            }
            
            if (isIdentifier(str)) {
                newtoken = "Identifier";
                newlexme = str;
                str_nor = "";
                str = "";
                if (_switch){
                    cout << left  <<"Token: "  << setw(20)<< newtoken  <<"Lexeme: "<< newlexme << endl;
                    outFile << left  <<"Token: "  << setw(20)<< newtoken  <<"Lexeme: "<< newlexme << endl;}
                return;
            }
            if (isInteger(str)) {
                newtoken = "Integer";
                newlexme = str;
                str = "";
                if (_switch){
                    cout << left  <<"Token: "  << setw(20)<< newtoken  <<"Lexeme: "<< newlexme << endl;
                    outFile << left  <<"Token: "  << setw(20)<< newtoken  <<"Lexeme: "<< newlexme << endl;}
                str_nor = "";
                return;
            }
            if (isReal(str)) {
                newtoken = "Real";
                newlexme = str;
                str = "";
                str_nor = "";
                if (_switch){
                    cout << left  <<"Token: "  << setw(20)<< newtoken  <<"Lexeme: "<< newlexme << endl;
                    outFile << left  <<"Token: "  << setw(20)<< newtoken  <<"Lexeme: "<< newlexme << endl;}
                return;
            }
            
            if (isSeparator(str)){
                newtoken = "Separator";
                newlexme = str;
                str = "";
                if (_switch){
                    cout << left  <<"Token: "  << setw(20)<< newtoken  <<"Lexeme: "<< newlexme << endl;
                    outFile << left  <<"Token: "  << setw(20)<< newtoken  <<"Lexeme: "<< newlexme << endl;}
                str_sep = "";
                return;
            }
            
            if (isOperator(str)){
                
                newtoken = "Operator";
                newlexme = str;
                if (_switch){
                    cout << left  <<"Token: "  << setw(20)<< newtoken  <<"Lexeme: "<< newlexme << endl;
                    outFile << left  <<"Token: "  << setw(20)<< newtoken  <<"Lexeme: "<< newlexme << endl;}
                str = "";
                
                str_ope = "";
                return;
            }
            
            else
            {

                newtoken = "errortoken";
                newlexme = str;
                if (_switch){
                    cout << left  <<"Token: "  << setw(20)<< newtoken  <<"Lexeme: "<< newlexme << endl;
                    outFile << left  <<"Token: "  << setw(20)<< newtoken  <<"Lexeme: "<< newlexme << endl;}
                str_sep = "";
                str_ope = "";
                str_nor = "";
                return;
            }

       
            //str = "";
        }
    



string remove(ifstream& file){
    string before;
    string after;
    char ch;
    
    bool s_state = false;
    bool m_state = false;
 
    while (file.get(ch)) {
        before.push_back(ch);
        }        // get all che chars from the file and put in a string
    
    size_t n = before.length();
    
    for (size_t i=0; i<n; i++) // loop the string
       {
           // check for "//"
           if (s_state == true && before[i] == '\n')
               s_state = false;
    
           // check for "*/
           else if  (m_state == true && before[i] == '*' && before[i+1] == '/'){
               m_state = false;  i++;}
    
           
           else if (s_state || m_state){
               continue;}
    
           // set flag if "//"
           else if (before[i] == '/' && before[i+1] == '/'){
               s_state = true; i++;}
           //set flag if "/*"
           else if (before[i] == '/' && before[i+1] == '*'){
               m_state = true;  i++;}
    
           // append to after if current char is not comment
           else
               after += before[i];
       }
    
    return after;
       
   }

