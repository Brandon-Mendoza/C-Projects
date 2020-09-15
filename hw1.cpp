//Brandon Mendoza 
//3/21/20
//HW1

#include <iostream>
#include <fstream>

using namespace std;

string readFile(string original);
void writeFunction(string fileName, string content);
string Encryption(string encrypt, int key);
string Decryption(string decrypt, int key);

int main()
{
  string encrypt, decrypt, fileInput, original;
  int uKey = 0, input;

  cout << "Enter 1 for encryption or 2 for decryption: ";

  do
    {
      cin >> input;
  if(input == 1)
    {
      cout << "Choose a file to encrypt: ";
      cin >> original;
      encrypt = readFile(original);
      cout << "Input a key for the encryption: ";
      cin >> uKey;
      while(uKey > 25 || uKey < 1)
	{
	  cout << "Invalid input for key" << endl;
	  cin >> uKey;
	}
      encrypt = Encryption(encrypt, uKey);
      cout << "Choose a file name to store the information: ";
      cin >> fileInput;
      writeFunction(fileInput, encrypt);
      cout << "Process was successful, open file to see encryption" << endl;
      return 0;
    }
  else if(input == 2)
    {
      cout << "Choose a file to decrypt: ";
      cin >> original;
      decrypt = readFile(original);
      cout << "Input a key for the decryption: ";
      cin >> uKey;
      while(uKey > 25 || uKey < 1)
        {
          cout << "Invalid input for key" << endl;
          cin >> uKey;
        }
      decrypt = Decryption(decrypt, uKey);
      cout << "Choose a file name to store the information: ";
      cin >> fileInput;
      writeFunction(fileInput, decrypt);
      cout << "Process was successful, open file to see decryption" << endl;
      return 0;
    }
  else
    {
      cout << "Must enter 1 for encryption or 2 for decryption: " << endl;
      return 0;
    }
    }
  while(input != 1 || input != 2);

  return 0;
}

string readFile(string original)
{
  ifstream fin;
  fin.open(original);
  string temp = "";

  while(fin)
    {
      getline(fin, original);
      temp = temp + original;
    }
  original = temp;
  return original;
}

void writeFunction(string fileName, string content)
{
  ofstream fout(fileName);
  fout << content << endl;
}

string Encryption(string encrypt, int key)
{
  int length = 0;
  length = encrypt.length();
  for(int i = 0; i < length; i++)
    {
      if(encrypt[i] > 64 && encrypt[i] < 91)
	{
	  encrypt[i] = encrypt[i] + key; 
	  if(encrypt[i] > 90)
	    {
	      encrypt[i] = encrypt[i] - 26;
	    }
	}
      if(encrypt[i] > 96 && encrypt[i] < 123)
	{
	  encrypt[i] = encrypt[i] + key;
	}
      if(encrypt[i] > 122)
	{
	  encrypt[i] = encrypt[i] - 26;
	}
      else
	{
	  encrypt[i] = encrypt[i];
	}
    }
  return encrypt;
}

string Decryption(string decrypt, int key)
{
  int length = 0;
  length = decrypt.length();
  for(int i = 0; i < length ; i++)
    {
      if(decrypt[i] > 64 && decrypt[i] < 91)
	{
	  decrypt[i] = decrypt[i] - key;
	  if(decrypt[i] < 65)
	    {
	      decrypt[i] = decrypt[i] + 26;
	    }
	}
      if(decrypt[i] > 96 && decrypt[i] < 123)
	{
	  decrypt[i] = decrypt[i] - key;
	  if(decrypt[i] < 97)
	    {
	      decrypt[i] = decrypt[i] + 26;
	    }
	}
      else
	{
	  decrypt[i] = decrypt[i];
	}
    }
  return decrypt;
}
