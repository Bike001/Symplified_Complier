


#include "lexer.hpp"
#include "Parse.hpp"
#include <vector>


using namespace std;


string inputfilename;
string ouputfilename;

//string outputfilename2;

//ofstream outFile2(outputfilename2);
//bool _switch = true;
//int lineNum;


// get the line of error
/*int error_line (string outputfilename2, string newlexme ){

    
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




*/





//function for removing the comments and return the string left




int main()
{

   
   
    
    string line;
    vector <string> lines;
  
//    inputfilename = "test4.txt";
//    ouputfilename =   "1231.txt";
    cout << "Enter a inputfile name .txt : ";
    cin >> inputfilename;

    cout << "Enter a outputfile name .txt : ";
    cin >> ouputfilename;
    
//    cout << "Enter a  copy file name for search line .txt : ";
//    cin >> outputfilename2;
//
   
   
    

    outFile.open(ouputfilename.c_str());
    if (!outFile.is_open())
    {

        cout << "Failed to open the file\n";
        exit(1);
    }
    
//    outFile2.open(outputfilename2.c_str());
//    if (!outFile2.is_open())
//    {
//
//        cout << "Failed to open the file\n";
//        exit(1);
//    }
//
    file.open(inputfilename.c_str());

    if (!file.is_open())
    {

        cout << "Failed to open the file\n";
        exit(1);
    }


    else
    {
        cout << "SOURCE CODE:\n\n";
        outFile << "SOURCE CODE:\n\n";
        while (getline(file, line))
        {
            cout << line << endl;
            lines.push_back(line);
            outFile << line << endl;
           // outFile2 << line << endl;
            
        }
        
        cout << endl;
    }
   

   /*
    cout << "\n\nOUTPUT:\n";
    cout << left << setw(20) << "Token" << setw(20) << "Lexeme" << endl;
    cout << endl;


    outFile << "\n\nOUTPUT:\n";
    outFile << left << setw(20) << "Token" << setw(20) << "Lexeme" << endl;
    outFile << endl;
    */
   
    
/* * * *  impementaion of skipping the comments * * * * * * * ** * * * * * * * * * * * */
    
    file.clear();
    file.seekg(0);

    string context =  remove(file); //get the string without comments


    ifstream file1(inputfilename);
    file1.close();
    ofstream file2(inputfilename,ios::out| ios::trunc);//clear the contxt of the file

    file2.close();
    ofstream file3(inputfilename);
    file3 << context; //write the string without comments to the file
    file3.close();


    
    
    /* * * *  impementaion of checking the token * * * * * * * ** * * * * * * * * * * * */
    
    
    file.open(inputfilename.c_str());
    if (!file.is_open())
    {

        cout << "Failed to open the file\n";
        exit(1);
    }
   
    
    file.clear();
    file.seekg(0);
   
    Rat22F(file);
     print_sym();
    print_instruct( file);
    //    while (!file.eof())
//      {
//          lexer(file); //call the lexer function
//
//     }
  //  for( int i = 0; i < 6; i ++){
        
  //      lexer(file); //call the lexer function
        
  //  }
    /* * * *  impementaion of restore the string to the original file * * * * * * * * * */

      file.clear();
      file.seekg(0);

      



      ifstream file4(inputfilename);
      file4.close();
      ofstream file5(inputfilename, ios::out | ios::trunc);//clear the contxt of the file

      file5.close();
      ofstream file6(inputfilename);
    for (size_t i=0; i < lines.size(); i++)
    { file6<< lines[i];
        
        file6<< endl;
    }
       
      file6.close();

    
    
    file.close();
    cout << endl;
    outFile << endl;
   
    cout << "Press any key to continue...";
    system("pause");
    return 0;

    return 0;

}







