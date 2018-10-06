// This program demonstrates an application 
// of pure virtual functions.
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Encryption
{
 protected:
   ifstream inFile;
   ofstream outFile;   
 public:
   Encryption(char *inFileName, char *outFileName);
   ~Encryption();
   // Pure virtual function
   virtual char transform(char ch, char key) const = 0;
   // Do the actual work.
   void encrypt();
};

//**************************************************
// Constructor opens the input and output file.    *
//**************************************************
Encryption::Encryption(char *inFileName, char *outFileName)
{
   inFile.open(inFileName);
   outFile.open(outFileName);
   if (!inFile) 
     {
       cout <<  "The file " << inFileName 
            << " cannot be opened.";
       exit(1);
     }
   if (!outFile)
    {
      cout << "The file " << outFileName
           << " cannot be opened.";
      exit(1);
    }
}

//**************************************************
//Destructor closes files.                         *
//**************************************************
Encryption::~Encryption()
{
   inFile.close();
   outFile.close(); 
}

//*****************************************************
//Encrypt function uses the virtual transform         *
//member function to transform individual characters. *
//***************************************************** 
void Encryption::encrypt()
{
  char ch;
  char transCh;
  char key;
  cout << "Enter a key to add to the encryption: ";
  cin >> key;
  inFile.get(ch);
  while (!inFile.fail())
    {
      transCh = transform(ch,key);
      outFile.put(transCh);
      inFile.get(ch);
    }
}

// The subclass simply overides the virtual
// transformation function
class SimpleEncryption : public Encryption
{
public:
   char transform(char ch, char key) const
   {
     return ch + key;
   }
   SimpleEncryption(char *inFileName, char *outFileName)
   : Encryption(inFileName, outFileName)
   {
   }
};

class ScrambleWord : public Encryption
{
public:
	char scramble(char *outFileName)
	{
		int size;
		char newName[1000];
		outFile.open(outFileName);
		size = sizeof(outFile);
		for(int k=0 ; k < size; ++k)
		{
			outFileName[k] = 'h';
		} 
			
	}
};
		
	
int main()
{
  char inFileName[80], outFileName[80];
  cout << "Enter name of file to encrypt: ";
  cin >> inFileName;
  cout << "Enter name of file to receive " 
       << "the encrypted text: ";
  cin >> outFileName;
  SimpleEncryption obfuscate(inFileName, outFileName);
  obfuscate.encrypt();
  return 0;
}
