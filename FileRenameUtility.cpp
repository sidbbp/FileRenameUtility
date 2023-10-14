// C++ Program to Rename File

#include <fstream> 
#include <iostream>   
#include <stdio.h>
#include <dirent.h>
using namespace std;

void ReplaceStringInPlace(std::string& subject, const std::string& search,
                          const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
}


string current_working_directory()
{
    char* cwd = _getcwd( 0, 0 ) ; // **** microsoft specific ****
    string working_directory(cwd) ;
    free(cwd) ;
    return working_directory;
}


int main() 
{ 
	string line; 
	string a = current_working_directory();
	fstream mystream;

	char newfile[100];
	char oldfile[100];

	cout<<"Enter File name to be renamed : ";
	cin>>oldfile;
	cout<<"Enter the newname of the File : ";
	cin>>newfile;

	string filename = a + "\\" + oldfile;
    ReplaceStringInPlace(filename, "\\", "\\\\");
    cout<<endl<<filename;

	ifstream ini_file{ filename }; //original file
	ofstream out_file{ newfile }; //replaced file


	//copying file
	if (ini_file && out_file) { 
		while (getline(ini_file, line)) { 
			out_file << line << "\n"; 
		} 
		cout << "Copy Finished \n"; 
	} 
	else { 
		// Something went wrong 
		printf("Cannot read File"); 
	} 
	// Closing file 
	ini_file.close(); 
	out_file.close(); 
	remove(newfile);
    rename(oldfile, newfile);
	return 0; 
}
