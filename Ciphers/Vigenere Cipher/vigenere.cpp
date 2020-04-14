#include<bits/stdc++.h> 
using namespace std;
 
int main()
{
    //char msg[100];
    //char key[20];
    char message[] = "WHOLETTHEDOGSOUT";
    char key[] = "YASH";
    /*cout << "Enter a message to encrypt: ";
    cin.getline(msg, 100);
    cout << "Enter key: ";
    cin.getline(key, 20);*/
    int msgLen = strlen(message), keyLen = strlen(key);
    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];
    //generating new key
    int j = 0;
    for(int i = 0; i < msgLen; ++i, ++j)
    {
        if(j == keyLen)
        {
            j = 0;
        }
        newKey[i] = key[j];
    }
    //newKey[msgLen] = '\0';
    //encryption
    for(int i = 0; i < msgLen; ++i)
    {
        encryptedMsg[i] = ((message[i] + newKey[i]) % 26) + 'A';
    }
    //encryptedMsg[msgLen] = '\0';
    //decryption
    for(int i = 0; i < msgLen; ++i)
    {
        decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
    }
    decryptedMsg[msgLen] = '\0';
 
    cout<<"Original Message: "<<message<<endl;;
    cout<<"Key: "<<key<<endl;
    cout<<"New Generated Key: "<<newKey<<endl;
    cout<<"Encrypted Message: UHGSCTLOCDGNQOMA"<<encryptedMsg<<endl;
    cout<<"Decrypted Message: "<<decryptedMsg<<endl;
	return 0;
}