#include <bits/stdc++.h>
using namespace std;
int main()
{
	char message[100] = "This is the plain text"; 
	char crypt[100] = "pm ol ohk hufaopun jvumpkluaphs";
	char ch;
	int key, y;
	cout<<"Choose a process to perform for Ceaser Cipher:"<<endl<<"1. Encryption"<<endl<<"2. Decryption"<<endl;
	cin>>y;
	switch(y)
	{
		case 1:
		/*cout << "Enter a message to encrypt: ";
		cin.getline(message, 100);
		for (int i = 0; i < 100; ++i)
		{
			cin>>message[i];
		}*/
		cout << endl<< "Enter key: ";
		cin >> key;
		for(int i = 0; message[i] != '\0'; ++i)
		{
			ch = message[i];
			if(ch >= 'a' && ch <= 'z')
			{
				ch = ch + key;
				if(ch > 'z')
				{
					ch = ch - 'z' + 'a' - 1;
				}
				message[i] = ch;
			}
			else if(ch >= 'A' && ch <= 'Z')
			{
				ch = ch + key;
				if(ch > 'Z')
				{
					ch = ch - 'Z' + 'A' - 1;
				}
				message[i] = ch;
			}
		}
		cout<<"Plain text: This is the plain text"<<endl;
		cout << "Encrypted message: " << message;
		break;
		case 2:
		/*cout << "Enter a message to decrypt: ";
		cin.getline(message, 100);
		cout << "Enter key: ";
		cin >> key;*/
		cout<<"Cryptic Text: pm ol ohk hufaopun jvumpkluaphs"<<endl;
		key = 7;
		for(int i = 0; crypt[i] != '\0'; ++i)
		{
			ch = crypt[i];
			if(ch >= 'a' && ch <= 'z')
			{
				ch = ch - key;
				if(ch < 'a')
				{
					ch = ch + 'z' - 'a' + 1;
				}
				crypt[i] = ch;
			}
			else if(ch >= 'A' && ch <= 'Z')
			{
				ch = ch - key;
				if(ch > 'a')
				{
					ch = ch + 'Z' - 'A' + 1;
				}
				crypt[i] = ch;
			}
		}
		cout << "Decrypted message: " << crypt;
		break;
		default:
		cout<<"Wrong Option"<<endl;
		break;
	}
	return 0;
}