#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
bool validation(int argumentCounter,string argumentVector[]);
string encryptMessage(string userInput,string keyString);
char encryption(char userCounter, int key);
int getDelta(char c);
bool isACharacter(char character);

int main(int argc, string argv[]) 
{
    if (!validation(argc, argv))
    {
        printf("Usage: ./vigenere keyword");
        return 1;
    }
    printf("Success\n");
    string keyString = argv[1];
    string plaintext = get_string("Plain text:");
    string cipherText = encryptMessage(plaintext, keyString);
    printf("ciphar text : %s\n", cipherText);
    return 0;
}

string encryptMessage(string userInput, string keyString) 
{
    int plaintextLength = strlen(userInput);
    int keyLength = strlen(keyString);
    if (plaintextLength == 0)
    {
        return "";
    }
    char *encryptedMessage = malloc(plaintextLength + 1);
    int keyCount = 0 ;
     for (int counter = 0; counter < plaintextLength; counter++)
     {
       
        if (isACharacter(userInput[counter])) 
        {   
            int key =  getDelta(keyString[keyCount % keyLength]);
            keyCount++ ; 
            char encryptedChar = encryption(userInput[counter], key);
            encryptedMessage[counter] = encryptedChar; 
         }   
        else
        {
           encryptedMessage[counter] =  userInput[counter];
        }
     }
    return encryptedMessage;
 }

bool isACharacter(char character) 
{
    return ((character >= 'a')&&(character <= 'z')) || ((character >= 'A')&&(character <= 'Z'));
}

bool validation(int argumentCounter, string argumentVector[])
{
    if (argumentCounter == 2)
    {
        bool flag = true;
        for (int count = 0, n = strlen(argumentVector[1]) ; count < n ; count++)
         {
           if (isalpha(argumentVector[1][count]) == 0)
           {
                flag = false;   
           }
         }
        return flag;
    }
    else 
    {
        return false;
    }
}
            
int getDelta(char c)
{
    int delta = c - 65;
    if(delta > 26)
    {
       delta -= 32 ;
    }
    return delta;
}
char encryption(char userCounter, int key)
{
    if (islower(userCounter)!=0)
    {
       userCounter = (((userCounter-97) + key) % 26) + 97;
    }
    else
    {
        userCounter = (((userCounter-65) + key) % 26) + 65 ;
    }
    return userCounter;
}
