//
//  Parse.cpp
//  parser
//
//  Created by YuSoo on 11/9/22.
//

#include "Parse.hpp"

#include <iostream>
#include <stack>
using namespace std;
bool isFromDeclaration = false;
bool isAssign = false;
string prenewlexme;


string outputfilename2;

ofstream outFile2;


int lineNum;

struct symbol {
    int memory_location;
    string type;
    string identifier;
};

struct symbol s;


vector <symbol> sym;

stack <int> jumpstack;

struct instruct {
    int address;
    string op;
    int operand;
    
};

instruct instuct_arr[1000];

int idx  = 1;

// get the line of error
int error_line (string outputfilename2, string newlexme ){

    
    ifstream file8;
   
    file8.open(outputfilename2.c_str());

    if (!file8.is_open())
    {

        cout << "Failed to open the file\n";
        exit(1);
    }

  int line_counter = 0;
  string line;
    while (getline (file8,line)) {
        line_counter++;
       
        if (line.find(newlexme) != string::npos) {
           
            
            break;
        }
        
        else {
                    }
    }
    file8.close();
    return line_counter;
    
}


void print_sym(){
    
    cout << "\nSymbol TABLE\n";
    outFile<<"\nSymbol TABLE\n";
    for( int i =0; i < sym.size(); i++){
        
        cout << sym[i].type << " " << sym[i].identifier << " " << sym[i].memory_location << endl;
        
        outFile << sym[i].type << " " << sym[i].identifier << " " << sym[i].memory_location << endl;
    
        
    }
    
}


int get_address(string save)
    {
        int address = 0;
        for (int i = 0; i < sym.size(); i++) {
            if (sym[i].identifier == save) {
                address = sym[i].memory_location;
            }
        }
        return address;
    }
    
void gen_instruct (string op, int operand)
{
    instuct_arr[idx].address = idx;
    instuct_arr[idx].op = op;
    instuct_arr[idx].operand = operand;
    idx++;
}

void print_instruct(ifstream& file){
    
    string a;
    cout << "\nINSTRUCTION TABLE\n";
    outFile<<"\nINSTRUCTION TABLE\n";
    for (int i = 1; i < idx; i++)
    {
        if (instuct_arr[i].operand == -99999) {
            a = "";
            cout << instuct_arr[i].address << " " << instuct_arr[i].op << " "
                << a;           cout << endl;
            outFile  << instuct_arr[i].address << " " << instuct_arr[i].op << " "
                << a;
            outFile << endl;
        }
        else {
            cout << instuct_arr[i].address << " " << instuct_arr[i].op << " "
                << instuct_arr[i].operand;
            cout << endl;
            outFile << instuct_arr[i].address << " " << instuct_arr[i].op << " "
        << instuct_arr[i].operand;
            outFile << endl;
        }

    }
    
    
}

void backPatch(int jump_addr)
{
    int addr = jumpstack.top();
    jumpstack.pop();
    instuct_arr[addr].operand = jump_addr;
}


// parse functions
void Rat22F(ifstream& file)
{
    s.memory_location = 4999;
    
    lexer(file);

    //cout << "this is " << newlexme << endl;
    if (_switch){
        
        {
            cout << "<Rat22F>  ::=   <Opt Function Definitions>   $  <Opt Declaration List>  <Statement List>  $"<< endl;
            
            outFile << "<Rat22F>  ::=   <Opt Function Definitions>   $  <Opt Declaration List>  <Statement List>  $"<< endl;
        }
        
    }
    
    if (newlexme== "$")
    {
        lexer(file);
    
        OptDeclarationList(file);
        StatementList(file);
        if (newlexme== "$")
                {
                    lexer(file);
                   
                }
                else
                {
                    lineNum = error_line(outputfilename2,newlexme);
                    outFile << "Error at line " << lineNum << endl;
                    cerr << "Error at line " << lineNum << endl;
                    outFile << "Function Body syntax error\n";
                    outFile << "Invalid separator, '$' is expected"
                        << " after statements. Specifically, after ';'.\n";
                  
                    cerr << "Function Body syntax error\n";
                    cerr << "Invalid separator, '$' is expected"
                        << " after statements. Specifically, after ';'.\n";
              
                    exit(1);
                }
        
                
        if (!(newlexme == "EOF"))
         {
            outFile << "This is not EOF marker.\n"
            << "Only <Opt Declaration List>  <Statement List>  $"<< endl;
            cerr << "This is not EOF marker.\n"
                << "Only <Opt Declaration List>  <Statement List>  $"<< endl;
         
            exit(1);
        }
 
      
    }
    else
    {
        lineNum = error_line(outputfilename2,newlexme);
          outFile << "Error at line " << lineNum << endl;
          cerr << "Error at line " << lineNum << endl;
        outFile << "Invalid separator, '$' is expected "
            << " after function definitions and before declaration list.\n";
        cerr << "Invalid separator, '$' is expected "
            <<" after function definitions and before declaration list.\n";
    
        exit(1);
    }
}
 

 
 
 

    
    
    void Qualifier(ifstream& file)
    {
        if (newtoken == "Keyword" && newlexme == "integer")
        {
            if (_switch)
            {
                cout << "\t<Qualifier> -> integer\n";
                outFile << "\t<Qualifier> -> integer\n";
               
               
                
                
            }
            
            s.type = newlexme;
            lexer(file);
         
        }
        else   if (newtoken == "Keyword" && newlexme == "boolean")
        {
            if (_switch)
            {
                cout << "\t<Qualifier> -> boolean\n";
                outFile << "\t<Qualifier> -> boolean\n";
               
                
            }
            
            s.type = newlexme;
            lexer(file);
          
        }
      
        else
        {
            lineNum = error_line(outputfilename2,newlexme);
              outFile << "Error at line " << lineNum << endl;
              cerr << "Error at line " << lineNum << endl;
            outFile << "Qualifier syntax error\n"
                << "Invalid keyword\n";
            outFile << "'integer', 'boolean' or 'real' keyword is expected"
                << " after ':'.\n";
            cerr << "Qualifier syntax error\n"
                << "Invalid keyword\n";
            cerr << "'integer', 'boolean' or 'real' keyword is expected"
                << " after ':'.\n";
       
        }
    }
    
    
   
    void OptDeclarationList(ifstream& file)
    {
       
            if (_switch)
            {
                cout << "\t<Opt Declaration List> -> <Declaration List>\n";
                outFile << "\t<Opt Declaration List> -> <Declaration List>\n";
            }
            DeclarationList(file);
       
    }
    
    
    void DeclarationList(ifstream& file)
    {
        isFromDeclaration = true;
        
        if (_switch)
        {
            cout << "\t<Declaration List> -> "
                << "<Declaration> ; <Declaration List Prime>\n";
            outFile << "\t<Declaration List> -> "
                << "<Declaration> ; <Declaration List Prime>\n";
        }
        Declaration(file);
        if (newlexme == ";")
        {
            lexer(file);
        
            DeclarationListPrime(file);
        }
//       else
//        {
//            cout << "error" << endl;
//        }
        
        
        isFromDeclaration = false;    }
    
    void DeclarationListPrime(ifstream& file)
    {
      
            if (_switch)
            {
                cout << "\t<Declaration List Prime> -> "
                    << "<Declaration List>\n";
                outFile << "\t<Declaration List Prime> -> "
                    << "<Declaration List>\n";
            }
        if (newlexme == "integer" || newlexme == "boolean"){
            DeclarationList(file);}
        
      
    }
    
    
    void Declaration(ifstream& file)
    {
        if (_switch)
        {
            cout << "\t<Declaration> -> "
                << "<Qualifier> <IDs>\n";
            outFile << "\t<Declaration> -> "
                << "<Qualifier> <IDs>\n";
        }
        Qualifier(file);
        IDs(file);
    }
    
    
    void IDs(ifstream& file)
    {
        if (newtoken == "Identifier")
        {
            if (_switch)
            {
                cout << "\t<IDs> -> "
                    << "<identifier> <IDs Prime>\n";
                outFile << "\t<IDs> -> "
                    << "<identifier> <IDs Prime>\n";
              
               
            }
            
            int count = 0;
           
                for( int i =0; i < sym.size(); i++){
                    
                    if (sym[i].identifier == newlexme  )
                        
                    {
                        count ++;
                    }
                    
                }
                if (count == 0 && isFromDeclaration == true){
                    s.identifier = newlexme;
                    s.memory_location += 1;
                    sym.push_back(s);
                }
               
               if (count > 0 && isFromDeclaration == true)
               {
                   cout <<"Error, decalred  " << newlexme << " more than one time;" << endl;
                   cout <<"Please ignore the result below: " << endl;
                   cout << endl;
                   outFile <<"Error, decalred  " << newlexme << " more than one time;" << endl;
                   outFile <<"Please ignore the result below: " << endl;
                outFile << endl;
                
                   //exit(1);
               }
               if (count == 0 && isFromDeclaration == false){
                cout <<"Error, undecalred " << newlexme << ";" << endl;
                   cout <<"Please ignore the result below: " << endl;
                  
                   cout << endl;
                   
                   outFile <<"Error, undecalred " << newlexme << ";" << endl;
                      outFile <<"Please ignore the result below: " << endl;
                   outFile << endl;
                   
                  // exit(1);
              }
           
            
            lexer(file);
          
            IDsPrime(file);
        }
        else
        {
            lineNum = error_line(outputfilename2,newlexme);
              outFile << "Error at line " << lineNum << endl;
              cerr << "Error at line " << lineNum << endl;
            outFile << "IDs syntax error\n";
            outFile << "Invalid token, <identifier> is expected"
                " after '(' or ','.\n";
            cerr << "IDs syntax error\n";
            cerr << "Invalid token, <identifier> is expected"
                " after '(' or ','.\n";
          
            exit(1);
        }
    }
 
    void IDsPrime(ifstream& file)
    {
        if (newlexme== ",")
        {
            if (_switch)
            {
                cout << "\t<IDsPrime> -> "
                    << ", <IDs>\n";
                outFile << "\t<IDsPrime> -> "
                    << ", <IDs>\n";
            }
            lexer(file);
       
            IDs(file);
        }
//        else
//            lineNum = error_line(outputfilename2,newlexme);
//              outFile << "Error at line " << lineNum << endl;
//              cerr << "Error at line " << lineNum << endl;
//            cout << "IDsPrime error" << endl;
       
    }
    
    
    void StatementList(ifstream& file)
    {
        if (_switch)
        {
            cout << "\t<Statement List> -> "
                << "<Statement> <Statement List Prime>\n";
            outFile << "\t<Statement List> -> "
                << "<Statement> <Statement List Prime>\n";
        }
        Statement(file);
        StatementListPrime(file);
    }
 
    void StatementListPrime(ifstream& file)
    {
         
        
            if (_switch)
            {
                cout << "\t<Statement List Prime> -> "
                    << "<Statement List>\n";
                outFile << "\t<Statement List Prime> -> "
                    << "<Statement List>\n";
            }
        if (newlexme == "{" ||  newtoken == "Identifier" ||newlexme == "if"|| newlexme == "return" || newlexme == "put" || newlexme == "get"||newlexme == "while"){
            
            StatementList(file);
        }
        
    }
    
    
    void Statement(ifstream& file)
    {
        if (newlexme == "{")
        {
            if (_switch)
            {
                cout << "\t<Statement> -> "
                    << "<Compound>\n";
                outFile << "\t<Statement> -> "
                    << "<Compound>\n";
            }
            Compound(file);
        }
        else if (newtoken == "Identifier")
        {
            if (_switch)
            {
                cout << "\t<Statement> -> "
                    << "<Assign>\n";
                outFile << "\t<Statement> -> "
                    << "<Assign>\n";
            }
            Assign(file);
        }
        else if (newlexme == "if")
        {
            if (_switch)
            {
                cout << "\t<Statement> -> "
                    << "<If>\n";
                outFile << "\t<Statement> -> "
                    << "<If>\n";
            }
            If(file);
        }
        else if (newlexme == "return")
        {
            if (_switch)
            {
                cout << "\t<Statement> -> "
                    << "<Return>\n";
                outFile << "\t<Statement> -> "
                    << "<Return>\n";
            }
            Return(file);
        }
        else if (newlexme == "get")
        {
            if (_switch)
            {
                cout << "\t<Statement> -> "
                    << "<Write>\n";
                outFile << "\t<Statement> -> "
                    << "<Write>\n";
            }
            Scan(file);
        }
        else if (newlexme == "put")
        {
            if (_switch)
            {
                cout << "\t<Statement> -> "
                    << "<Read>\n";
                outFile << "\t<Statement> -> "
                    << "<Read>\n";
            }
           Print(file);
        }
        else if (newlexme == "while")
        {
            if (_switch)
            {
                cout << "\t<Statement> -> "
                    << "<While>\n";
                outFile << "\t<Statement> -> "
                    << "<While>\n";
            }
            While(file);
        }
        else
        {
            //printError(outfile);
            outFile << "Statement syntax error\n";
            outFile << "Invalid token or keyword or separator\n";
            outFile << "<identifier>, 'if', 'return', 'write', 'read','while' "
                << "keyword or '{'is expected at the beginning of a statement.\n";
            cerr << "Statement syntax error\n";
            cerr << "Invalid token or keyword or separator\n";
            cerr << "<identifier>, 'if', 'return', 'write', 'read','while' "
                << "keyword or '{'is expected at the beginning of a statement.\n";
            system("Pause");
            exit(1);
        }
          
        
   
    }
    void Compound(ifstream& file)
    {
        
        if (_switch)
        {
            cout << "\t<Compound> -> "
                << "{ <StatementList> }\n";
            outFile << "\t<Compound> -> "
                << "{ <StatementList> }\n";
        }
 
 
        if (newlexme == "{")
        {
            
            lexer(file);
          
            StatementList(file);
            
            if (newlexme == "}")
            {
                lexer(file);
              
            }
            else
            {
                lineNum = error_line(outputfilename2,newlexme);
                  outFile << "Error at line " << lineNum << endl;
                  cerr << "Error at line " << lineNum << endl;
                outFile << "Compound syntax error\n";
                outFile << "Invalid separator, '}' is expected"
                    << " at the end of statement list(code block).\n";
                cerr << "Compound syntax error\n";
                cerr << "Invalid separator, '}' is expected"
                    << " at the end of statement list(code block).\n";
            
                exit(1);
            }
        }
//        else
//        {
////            lineNum = error_line(outputfilename2,newlexme);
////              outFile << "Error at line " << lineNum << endl;
////              cerr << "Error at line " << lineNum << endl;
////            outFile << "Compound syntax error\n";
////            outFile << "Invalid separator, '{' is expected"
////                << " at the beginning of statement list(code block).\n";
////            cerr << "Compound syntax error\n";
////            cerr << "Invalid separator, '{' is expected"
////                << " at the beginning of statement list(code block).\n";
////
////            exit(1);
//        }
    }
 
    
   
    void Assign(ifstream& file)
    {
        isAssign = true;
        if (_switch)
        {
            cout << "\t<Assign> -> "
                << "<Identifier> := <Expression>;\n";
            outFile << "\t<Assign> -> "
                << "<Identifier> := <Expression>;\n";
        }
       
        if (newtoken == "Identifier")
        {
            int count = 0;
           
                for( int i =0; i < sym.size(); i++){
                    
                    if (sym[i].identifier == newlexme  )
                        
                    {
                        count ++;
                    }
                    
                }
                
               
           
               
               if (count == 0 ){
                cout <<"Error, undecalred " << newlexme << ";" << endl;
                   cout <<"Please ignore the result below: " << endl;
                   cout << endl;
                   outFile <<"Error, undecalred " << newlexme << ";" << endl;
                   outFile <<"Please ignore the result below: " << endl;
                   outFile << endl;
                
              }
           
            string save = newlexme;
            string typematch = newlexme;
            lexer(file);
  
            if (newlexme == "=")
            {
                lexer(file);
           
                Expression(file);
                
                if (prenewlexme == "false" || prenewlexme == "true"){
                    
                    for( int i =0; i < sym.size(); i++){
                        
                        if (sym[i].identifier == typematch )
                            
                        {
                            if(sym[i].type != "boolean")
                                
                                cout << "error, type not matched when using boolean, please check your code" << endl;
                            cout <<"Please ignore the result below: " << endl;
                            cout << endl;
                            
                           // outFile << "error, type not matched when using boolean, please check your code" << endl;
                           // outFile <<"Please ignore the result below: " << endl;
                           // outFile << endl;
                        }
                        
                    }
                    
                }
                
                if ( prenewlexme != "false" || prenewlexme != "true" ){
                    
                    for( int i =0; i < sym.size(); i++){
                        
                        if (sym[i].identifier == typematch )
                            
                        {
                            if(sym[i].type == "boolean")
                                
                            cout << "Error, type not matched when using boolean, please check your code" << endl;
                            
                           // cout <<"Please ignore the result below: " << endl;
                            cout << endl;
                            
                           // outFile << "Error, type not matched when using boolean, please check your code" << endl;
                           // outFile <<"Please ignore the result below: " << endl;
                           // outFile << endl;
                            // exit(1);
                        }
                        
                    }
                    
                    
                }
                
                prenewlexme = " ";
                int number = get_address(save);
                gen_instruct("POPM", number);
                
                isAssign = false;
                
                if (newlexme == ";")
                {
                    lexer(file);
                  
                }
                else
                {
                    lineNum = error_line(outputfilename2,newlexme);
                      outFile << "Error at line " << lineNum << endl;
                      cerr << "Error at line " << lineNum << endl;
                    outFile << "Assign syntax error\n";
                    outFile << "Invalid separator, ';' is expected"
                        " at the end of assign statement.\n";
                    cerr << "Assign syntax error\n";
                    cerr << "Invalid separator, ';' is expected"
                        " at the end of assign statement.\n";
        
                    exit(1);
                }
            }
            else
            {
                lineNum = error_line(outputfilename2,newlexme);
                  outFile << "Error at line " << lineNum << endl;
                  cerr << "Error at line " << lineNum << endl;
                outFile << "Assign syntax error\n";
                outFile << "Invalid operator, '=' is expected"
                    << " after <identifier> and before <expression>.\n";
                cerr << "Assign syntax error\n";
                cerr << "Invalid operator, '=' is expected"
                    << " after <identifier> and before <expression>.\n";
           
                exit(1);
            }
        }
//        else
//        {
//            lineNum = error_line(outputfilename2,newlexme);
//              outFile << "Error at line " << lineNum << endl;
//              cerr << "Error at line " << lineNum << endl;
//            outFile << "Assign syntax error\n";
//            outFile << "Invalid token, <identifier> is expected"
//                " at the beginning of assign statement.\n";
//            cerr << "Assign syntax error\n";
//            cerr << "Invalid token, <identifier> is expected"
//                " at the beginning of assign statement.\n";
//
//            exit(1);
//        }
    }
    
    
    void If(ifstream& file)
    {
        if (_switch)
        {
            cout << "\t<If> -> "
                << "if (<Condition>) <Statement> <If Prime>\n";
            outFile << "\t<If> -> "
                << "if (<Condition>) <Statement> <If Prime>\n";
        }
        
        if (newlexme == "if")
        {
            
            lexer(file);
           
            if (newlexme == "(")
            {
                lexer(file);
               
                Condition(file);
                
                if (newlexme == ")")
                {
                    lexer(file);
               
                    Statement(file);
                    
                    if (newlexme == "else")
                    {
                        int addr = jumpstack.top();
                        jumpstack.pop();
                        jumpstack.push(idx);
                        gen_instruct("JUMP", -99999);

                        jumpstack.push(addr);
                        //dummyLabel = true;
                    }
                    backPatch(idx);
                    
                    IfPrime(file);
                    if (newlexme == "$")
                        gen_instruct("LABEL", -99999);
                }
                else
                {
                    lineNum = error_line(outputfilename2,newlexme);
                      outFile << "Error at line " << lineNum << endl;
                      cerr << "Error at line " << lineNum << endl;
                    outFile << "If statement syntax error\n";
                    outFile << "Invalid separator, ')' is expected"
                        << " after condition.\n";
                    cerr << "If statement syntax error\n";
                    cerr << "Invalid separator, ')' is expected"
                        << " after condition.\n";
               
                    exit(1);
                }
            }
            else
            {
                lineNum = error_line(outputfilename2,newlexme);
                  outFile << "Error at line " << lineNum << endl;
                  cerr << "Error at line " << lineNum << endl;
                outFile << "If statement syntax error\n";
                outFile << "Invalid separator, '(' is expected"
                    << " before condition.\n";
                cerr << "If statement syntax error\n";
                cerr << "Invalid separator, '(' is expected"
                    << " before condition.\n";
                
             
                exit(1);
            }
        }
//        else
//        {
//            lineNum = error_line(outputfilename2,newlexme);
//              outFile << "Error at line " << lineNum << endl;
//              cerr << "Error at line " << lineNum << endl;
//            outFile << "If statement syntax error\n";
//            outFile << "Invalid keyword, 'if' keyword is expected"
//                << " at the beginning of If statement.\n";
//            cerr << "If statement syntax error\n";
//            cerr << "Invalid keyword, 'if' keyword is expected"
//                << " at the beginning of If statement.\n";
//
//            exit(1);
//        }
    }
 
    
    
    
    
    void IfPrime(ifstream& file)
    {
        if (_switch)
        {
            cout << "\t<If Prime> -> "
            << "endif" << " | else <Statement> endif" << endl;
            outFile  << "\t<If Prime> -> "
            << "endif" << " | else <Statement> endif" << endl;
        }
        
        if (newlexme == "endif")
        {
           
            
            
            
            
            lexer(file);
         
        }
        else if (newlexme == "else")
        {
            
            lexer(file);
   
            Statement(file);
            if (newlexme == "endif")
            {
                lexer(file);
               
            }
            else
            {
                lineNum = error_line(outputfilename2,newlexme);
                  outFile << "Error at line " << lineNum << endl;
                  cerr << "Error at line " << lineNum << endl;
                outFile << "If statement syntax error\n";
                outFile << "Invalid keyword, 'endif' is expected"
                    << " at the end of If statement.\n";
                cerr << "If statement syntax error\n";
                cerr << "Invalid keyword, 'endif' is expected"
                    << " at the end of If statement.\n";
            
                exit(1);
            }
        }
//        else
//        {
//            lineNum = error_line(outputfilename2,newlexme);
//              outFile << "Error at line " << lineNum << endl;
//              cerr << "Error at line " << lineNum << endl;
//            outFile << "If statement syntax error\n";
//            outFile << "Invalid keyword, 'endif' is expected at the end of If Statement\n"
//                << "Or 'else' is expected if there is an If-else statement.\n";
//            cerr << "If statement syntax error\n";
//            cerr << "Invalid keyword, 'endif' is expected at the end of If Statement\n"
//                << "Or 'else' is expected if there is an If-else statement.\n";
//
//            exit(1);
//        }
    }
    
void Return(ifstream& file)
{
    if (_switch)
    {
        cout << "\t<Return> -> "
            << "return <Return Prime>\n";
        outFile << "\t<Return> -> "
            << "return <Return Prime>\n";
    }
    
    if (newlexme == "return")
    {
       
        lexer(file);
    
        ReturnPrime(file);
    }
//    else
//    {
//        lineNum = error_line(outputfilename2,newlexme);
//          outFile << "Error at line " << lineNum << endl;
//          cerr << "Error at line " << lineNum << endl;
//        outFile << "Return statement syntax error\n";
//        outFile << "Invalid keyword, 'return' is expected"
//            << " at the beginning of Return statement.\n";
//        cerr << "Return statement syntax error\n";
//        cerr << "Invalid keyword, 'return' is expected"
//            << " at the beginning of Return statement.\n";
//
//        exit(1);
//    }
}
 
void ReturnPrime(ifstream& file)
{
    if (newlexme == ";")
    {
        
        if (_switch)
        {
            cout << "\t<Return Prime> -> "
                << ";\n";
            outFile << "\t<Return Prime> -> "
                << ";\n";
        }
        lexer(file);
  
    }
    else
    {
        if (_switch)
        {
            cout << "\t<Return Prime> -> "
                << "<Expression>;\n";
            outFile << "\t<Return Prime> -> "
                << "<Expression>;\n";
        }
        Expression(file);
        if (newlexme == ";")
        {
            lexer(file);
            
        }
        else
        {
            lineNum = error_line(outputfilename2,newlexme);
              outFile << "Error at line " << lineNum << endl;
              cerr << "Error at line " << lineNum << endl;
            outFile << "Return statement syntax error\n";
            outFile << "Invalid separator, ';' is expected"
                << " at the end of Return statement.\n";
            cerr << "Return statement syntax error\n";
            cerr << "Invalid separator, ';' is expected"
                << " at the end of Return statement.\n";
         
            exit(1);
        }
    }
}
 
void Print(ifstream& file)
{
    if (_switch)
    {
        cout << "\t<Print> ->  "
            << "put(<Expression>)\n";
        outFile  << "\t<Print> ->  "
        << "put(<Expression>)\n";
    }
    
    
    
  
    if (newlexme == "put")
    {
        
        lexer(file);
      
        if (newlexme == "(")
        {
            lexer(file);
           
            Expression(file);
            if (newlexme == ")")
            {
                
                gen_instruct("STDOUT", -99999);
                lexer(file);
              
                if (newlexme == ";")
                {
                    lexer(file);
                    
                }
                else
                {
                    lineNum = error_line(outputfilename2,newlexme);
                      outFile << "Error at line " << lineNum << endl;
                      cerr << "Error at line " << lineNum << endl;
                    outFile << "Write statement syntax error\n";
                    outFile << "Invalid separator, ';' is expected"
                        << " at the end of Write statement.\n";
                    cerr << "Write statement syntax error\n";
                    cerr << "Invalid separator, ';' is expected"
                        << " at the end of Write statement.\n";
                 
                    exit(1);
                }
            }
            else
            {
                lineNum = error_line(outputfilename2,newlexme);
                  outFile << "Error at line " << lineNum << endl;
                  cerr << "Error at line " << lineNum << endl;
                outFile << "Write statement syntax error\n";
                outFile << "Invalid separator, ')' is expected"
                    << " before ';' and after <Expression>.\n";
                cerr << "Write statement syntax error\n";
                cerr << "Invalid separator, ')' is expected"
                    << " before ';' and after <Expression>.\n";
              
                exit(1);
            }
        }
        else
        {
            lineNum = error_line(outputfilename2,newlexme);
              outFile << "Error at line " << lineNum << endl;
              cerr << "Error at line " << lineNum << endl;
            outFile << "Write statement syntax error\n";
            outFile << "Invalid separator, '(' is expected"
                << " after 'write' keyword and before <Expression>.\n";
            cerr << "Write statement syntax error\n";
            cerr << "Invalid separator, '(' is expected"
                << " after 'write' keyword and before <Expression>.\n";
        
            exit(1);
        }
    }
//    else
//    {
//        lineNum = error_line(outputfilename2,newlexme);
//          outFile << "Error at line " << lineNum << endl;
//          cerr << "Error at line " << lineNum << endl;
//        outFile << "Print statement syntax error\n";
//        outFile << "Invalid keyword, 'put' is expected"
//            << " at the beginning of Print statement.\n";
//        cerr << "Print statement syntax error\n";
//        cerr << "Invalid keyword, 'put' is expected"
//            << " at the beginning of Print statement.\n";
//
//        exit(1);
//    }
}
 
 
void Scan(ifstream& file)
{
    if (_switch)
    {
        cout << "\t<Sacn> ->  "
            << "get(<IDs>)\n";
        outFile  << "\t<Sacn> ->  "
        << "get(<IDs>)\n";
    }
    
    
    
  
    if (newlexme == "get")
    {
        
        lexer(file);
      
        if (newlexme == "(")
        {
            lexer(file);
            string save = newlexme;
           
            IDs(file);
            
            if (newlexme == ")")
            {
                int addr = get_address(save);
                gen_instruct("STDIN", -99999);
                gen_instruct("POPM", addr);
                
                
                
                
                lexer(file);
              
                if (newlexme == ";")
                {
                    lexer(file);
                    
                }
                else
                {
                    lineNum = error_line(outputfilename2,newlexme);
                      outFile << "Error at line " << lineNum << endl;
                      cerr << "Error at line " << lineNum << endl;
                    outFile << "Write statement syntax error\n";
                    outFile << "Invalid separator, ';' is expected"
                        << " at the end of Write statement.\n";
                    cerr << "Write statement syntax error\n";
                    cerr << "Invalid separator, ';' is expected"
                        << " at the end of Write statement.\n";
                 
                    exit(1);
                }
            }
            else
            {
                lineNum = error_line(outputfilename2,newlexme);
                  outFile << "Error at line " << lineNum << endl;
                  cerr << "Error at line " << lineNum << endl;
                outFile << "Write statement syntax error\n";
                outFile << "Invalid separator, ')' is expected"
                    << " before ';' and after <Expression>.\n";
                cerr << "Write statement syntax error\n";
                cerr << "Invalid separator, ')' is expected"
                    << " before ';' and after <Expression>.\n";
              
                exit(1);
            }
        }
        else
        {
            lineNum = error_line(outputfilename2,newlexme);
              outFile << "Error at line " << lineNum << endl;
              cerr << "Error at line " << lineNum << endl;
            outFile << "Write statement syntax error\n";
            outFile << "Invalid separator, '(' is expected"
                << " after 'write' keyword and before <Expression>.\n";
            cerr << "Write statement syntax error\n";
            cerr << "Invalid separator, '(' is expected"
                << " after 'write' keyword and before <Expression>.\n";
        
            exit(1);
        }
    }
//    else
//    {
//        lineNum = error_line(outputfilename2,newlexme);
//          outFile << "Error at line " << lineNum << endl;
//          cerr << "Error at line " << lineNum << endl;
//        outFile << "Scan statement syntax error\n";
//        outFile << "Invalid keyword, 'get' is expected"
//            << " at the beginning of Scan statement.\n";
//        cerr << "Scan statement syntax error\n";
//        cerr << "Invalid keyword, 'get' is expected"
//            << " at the beginning of Scan statement.\n";
//
//        exit(1);
//    }
}
 
 
void While(ifstream& file)
{
    
    if (_switch)
    {
        cout << "\t<While> -> "
            << "<while (<Condition>) <Statement>\n";
        outFile << "\t<While> -> "
            << "<while (<Condition>) <Statement>\n";
    }
    
    
    if (newlexme == "while")
    {
        int addr = idx;
        gen_instruct("LABEL", -99999);
        
        lexer(file);
     
        if (newlexme == "(")
        {
            lexer(file);
         
            Condition(file);
            if (newlexme == ")")
            {
                lexer(file);
                
                Statement(file);
                
                gen_instruct("JUMP", addr);
                backPatch(idx);
            }
            else
            {
                lineNum = error_line(outputfilename2,newlexme);
                  outFile << "Error at line " << lineNum << endl;
                  cerr << "Error at line " << lineNum << endl;
                outFile << "While statement syntax error\n";
                outFile << "Invalid separator, ')' is expected"
                    << " after condition and before any statements.\n";
                cerr << "While statement syntax error\n";
                cerr << "Invalid separator, ')' is expected"
                    << " after condition and before any statements.\n";
             
                exit(1);
            }
        }
        else
        {
            lineNum = error_line(outputfilename2,newlexme);
              outFile << "Error at line " << lineNum << endl;
              cerr << "Error at line " << lineNum << endl;
            outFile << "While statement syntax error\n";
            outFile << "Invalid separator, '(' is expected"
                << " before condition and after 'while' keyword.\n";
            cerr << "While statement syntax error\n";
            cerr << "Invalid separator, '(' is expected"
                << " before condition and after 'while' keyword.\n";
            system("Pause");
            exit(1);
        }
    }
//    else
//    {
//        lineNum = error_line(outputfilename2,newlexme);
//          outFile << "Error at line " << lineNum << endl;
//          cerr << "Error at line " << lineNum << endl;
//        outFile << "While syntax error\n";
//        outFile << "Invalid keyword, 'while' is expected"
//            << " at the beginning of While-loop.\n";
//        cerr << "While syntax error\n";
//        cerr << "Invalid keyword, 'while' is expected"
//            << " at the beginning of While-loop.\n";
//        system("Pause");
//        exit(1);
//    }
}
 
 
 
void Condition(ifstream& file)
{
    if (_switch)
    {
        cout << "\t<Condition> -> "
            << "<Expression> <Relop> <Expression>\n";
        outFile << "\t<Condition> -> "
            << "<Expression> <Relop> <Expression>\n";
    }
    Expression(file);
    string op = newlexme;
    
    Relop(file);
    Expression(file);
    if (op == "==")
    {
        gen_instruct("EQ", -99999);
        jumpstack.push(idx);
        gen_instruct("JUMPZ", -99999);
    }
    else if (op == "!=")
    {
        gen_instruct("NEQ", -99999);
        jumpstack.push(idx);
        gen_instruct("JUMPZ", -99999);
    }
    else if (op == ">")
    {
        
        gen_instruct("GRT", -99999);
        jumpstack.push(idx);
        gen_instruct("JUMPZ", -99999);
       
    }
    else if (op == "<")
    {
        
        gen_instruct("LES", -99999);
        jumpstack.push(idx);
        gen_instruct("JUMPZ", -99999);
    }
    else if (op == "=>")
    {
        gen_instruct("GEQ", -99999);
        jumpstack.push(idx);
        gen_instruct("JUMPZ", -99999);
      
    }
    else if (op == "<=")
    {
        gen_instruct("LEQ", -99999);
        jumpstack.push(idx);
        gen_instruct("JUMPZ", -99999);
       
    }
    else
    {
       // printError(outFile);
        outFile << "Relop syntax error\n";
        outFile << "Invalid operator\n"
            << "'=', '/=', '>', '<', '=>' or '<=' is expected"
            << " between 2 <Expression>.\n";
        cerr << "Relop syntax error\n";
        cerr << "Invalid operator\n"
            << "'=', '/=', '>', '<', '=>' or '<=' is expected"
            << " between 2 <Expression>.\n";
        system("Pause");
        exit(1);
    }}
 
void Relop(ifstream& file)
{
    if (newlexme == "==")
    {
        
        
        
        
        if (_switch)
        {
            cout << "\t<Relop> -> ==\n";
            outFile << "\t<Relop> -> ==\n";
        }
        lexer(file);
       
    }
    else if (newlexme == "!=")
    {
        
        
        
        if (_switch)
        {
            cout << "\t<Relop> -> !=\n";
            outFile << "\t<Relop> -> !=\n";
        }
        lexer(file);
       
    }
    else if (newlexme == ">")
    {
        if (_switch)
        {
            cout << "\t<Relop> -> >\n";
            outFile << "\t<Relop> -> >\n";
        }
        lexer(file);
       
    }
    else if (newlexme == "<")
    {
        if (_switch)
        {
            cout << "\t<Relop> -> <\n";
            outFile << "\t<Relop> -> <\n";
        }
        lexer(file);
       
    }
    else if (newlexme == "=>")
    {
        if (_switch)
        {
            cout << "\t<Relop> -> =>\n";
            outFile << "\t<Relop> -> =>\n";
        }
        lexer(file);
        
    }
    else if (newlexme == "<=")
    {
        if (_switch)
        {
            cout << "\t<Relop> -> <=\n";
            outFile << "\t<Relop> -> <=\n";
        }
        lexer(file);
       
    }
    else
    {
        lineNum = error_line(outputfilename2,newlexme);
          outFile << "Error at line " << lineNum << endl;
          cerr << "Error at line " << lineNum << endl;
        outFile << "Relop syntax error\n";
        outFile << "Invalid operator\n"
            << "'==', '!=', '>', '<', '=>' or '<=' is expected"
            << " between 2 <Expression>.\n";
        cerr << "Relop syntax error\n";
        cerr << "Invalid operator\n"
            << "'==', '!=', '>', '<', '=>' or '<=' is expected"
            << " between 2 <Expression>.\n";
        system("Pause");
        exit(1);
    }
}
 
 
void Expression(ifstream& file)
{
    if (_switch)
    {
        cout << "\t<Expression> -> <Term> <Expression Prime>\n";
        outFile << "\t<Expression> -> <Term> <Expression Prime>\n";
    }
    Term(file);
    ExpressionPrime(file);
}
 
 
void ExpressionPrime(ifstream& file)
{
    if (newlexme == "+")
    {
        if (_switch)
        {
            cout << "\t<Expression Prime> -> "
                << "+ <Term> <Expression Prime>\n";
            outFile << "\t<Expression Prime> -> "
                << "+ <Term> <Expression Prime>\n";
        }
        lexer(file);
    
        Term(file);
        
        gen_instruct("ADD", -99999);
        
        ExpressionPrime(file);
    }
    else if (newlexme == "-")
    {
        if (_switch)
        {
            cout << "\t<Expression Prime> -> "
                << "- <Term> <Expression Prime>\n";
            outFile << "\t<Expression Prime> -> "
                << "- <Term> <Expression Prime>\n";
        }
        lexer(file);
     
        Term(file);
        ExpressionPrime(file);
    }
    
}
 
void Term(ifstream& file)
{
    if (_switch)
    {
        cout << "\t<Term> -> <Factor> <Term Prime>\n";
        outFile << "\t<Term> -> <Factor> <Term Prime>\n";
    }
    Factor(file);
    TermPrime(file);
}
 
void TermPrime(ifstream& file)
{
    if (newlexme == "*")
    {
        if (_switch)
        {
            cout << "\t<Term Prime> -> * <Factor> <Term Prime>\n";
            outFile << "\t<Term Prime> -> * <Factor> <Term Prime>\n";
        }
        lexer(file);
      
        Factor(file);
        
        gen_instruct("MUL", -99999);
        TermPrime(file);
    }
    
    
    else if(newlexme == "/")
    {
        if (_switch)
        {
            cout << "\t<Term Prime> -> / <Factor> <Term Prime>\n";
            outFile << "\t<Term Prime> -> / <Factor> <Term Prime>\n";
        }
        lexer(file);
      
        Factor(file);
        gen_instruct("DIV", -99999);
        TermPrime(file);
    }
   
}
 
void Factor(ifstream& file)
{
    if (newlexme == "-")
    {
        if (_switch)
        {
            cout << "\t<Factor> -> - <Primary>\n";
            outFile << "\t<Factor> -> - <Primary>\n";
        }
        lexer(file);
     
        Primary(file);
    }
    else
    {
        if (_switch)
        {
            cout << "\t<Factor> -> <Primary>\n";
            outFile << "\t<Factor> -> <Primary>\n";
        }
        Primary(file);
    }
}
 
 
void Primary(ifstream& file)
{
    if (newtoken == "Identifier")
    {
        
       
        
        
        if (_switch)
        {
            cout << "\t<Primary> -> <identifier> <Primary Prime>\n";
            outFile << "\t<Primary> -> <identifier> <Primary Prime>\n";
        }
        
        
        
        
        int count = 0;
       
            for( int i =0; i < sym.size(); i++){
                
                if (sym[i].identifier == newlexme  )
                    
                {
                    count ++;
                }
                
            }
            
           
       
           
           if (count == 0 ){
            cout <<"Error, undecalred " << newlexme << ";" << endl;
               cout <<"Please ignore the result below: " << endl;
               cout << endl;
          }
        
        gen_instruct("PUSHM", get_address(newlexme));
        lexer(file);
        
       
     
        PrimaryPrime(file);
    }
    else if (newtoken == "Integer")
    {
        if (_switch)
        {
            cout << "\t<Primary> -> <integer>\n";
            outFile << "\t<Primary> -> <integer>\n";
        }
        
        gen_instruct("PUSHI", stoi(newlexme));
        
        lexer(file);
   
    }
   
    else if (newlexme == "(")
    {
        if (_switch)
        {
            cout << "\t<Primary> -> (<Expression>)\n";
            outFile << "\t<Primary> -> (<Expression>)\n";
        }
        lexer(file);
   
        Expression(file);
        if (newlexme == ")")
        {
            lexer(file);
      
        }
        else
        {
            lineNum = error_line(outputfilename2,newlexme);
              outFile << "Error at line " << lineNum << endl;
              cerr << "Error at line " << lineNum << endl;
            outFile << "Invalid separator, ')' is expected.\n";
            cerr << "Invalid separator, ')' is expected.\n";
            
            exit(1);
        }
    }
    else if (newlexme == "true")
    {
        if (_switch)
        {
            cout << "\t<Prime> -> true\n";
            outFile << "\t<Prime> -> true\n";
        }
        prenewlexme = "true";
        gen_instruct("PUSHI", 1);
        lexer(file);
        
    }
    else if (newlexme == "false")
    {
        if (_switch)
        {
            cout << "\t<Prime> -> false\n";
            outFile << "\t<Prime> -> false\n";
        }
        prenewlexme = "false";
        gen_instruct("PUSHI", 0);
        lexer(file);
      
    }
    else
    {
        lineNum = error_line(outputfilename2,newlexme);
          outFile << "Error at line " << lineNum << endl;
          cerr << "Error at line " << lineNum << endl;
        outFile << "Primary syntax error\n";
        outFile << "Invalid token, separator, or boolean value\n";
        outFile << "<identifier>, <integer>, <floating>, "
            << "'(', 'true' or 'false' is expected"
            << " after '-', '*' or '/'.\n";
        cerr << "Primary syntax error\n";
        cerr << "Invalid token, separator, or boolean value\n";
        cerr << "<identifier>, <integer>, <floating>, "
            << "'(', 'true' or 'false' is expected"
            << " after '-', '*' or '/'.\n";
     
        exit(1);
    }
}
 
void PrimaryPrime(ifstream& file)
{
    if (newlexme == "(")
    {
        if (_switch)
        {
            cout << "\t<Primary Prime> -> [<IDs>]\n";
            outFile << "\t<Primary Prime> -> [<IDs>]\n";
        }
        lexer(file);
       
        IDs(file);
        if (newlexme == ")")
        {
            lexer(file);
            
        }
//        else
//        {
////            lineNum = error_line(outputfilename2,newlexme);
////              outFile << "Error at line " << lineNum << endl;
////              cerr << "Error at line " << lineNum << endl;
////            outFile << "Primary syntax error\n";
////            outFile << "Invalid separator, ']' is expected"
////                << " after <IDs>.\n";
////            cerr << "Primary syntax error\n";
////            cerr << "Invalid separator, ']' is expected"
////                << " after <IDs>.\n";
////
////            exit(1);
//        }
    }
    
}
 



