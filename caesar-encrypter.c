#include<string.h>
#include <stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<math.h>
int validation(int argc, string valid[]);
int stringToInt(string numberString);
bool isACharacter(char plaintext);
int plainToCaesar(char plaintext,int key) ;
void ecrypt(string plaintext,int key);
int main(int argc, string argv[]) 
{
    if(validation(argc, argv) == 1) {
        printf("Usage: ./caesar key\n");
        return 1;
      }  
    else{  
        int key = stringToInt(argv[1]);
        string plaintext = get_string("Plain Text:\t");
        printf("Encrypted Text:\t");
        ecrypt(plaintext,key);
        printf("\n");
    }
}
int validation(int numberOfArguments, string arguments[])
{
    if(numberOfArguments != 2){
        return 1;
    }
    int flag = 0;
        for (int count = 0 , n = strlen(arguments[1]) ; count < n ; count++) {
            if (!isdigit(arguments[1][count])) {
                flag = 1;
                break;
            }
        }
    return flag;
}

int stringToInt(string numberString) {
    int number = 0;
    for(int counter = 0,n=strlen(numberString); counter < n ; counter ++) {
        int currentNumber = numberString[counter] - '0';
        currentNumber *= pow(10.0, n-1-counter);
        number += currentNumber; 
    }  
    return number;
}
bool isACharacter(char plaintext){
     return (((plaintext >='a')&&(plaintext<='z'))||((plaintext >='A')&&(plaintext <='Z'))) ;
}
int plainToCaesar(char plaintext,int key){
    if (islower(plaintext)!=0){
        plaintext = (((plaintext-97) + key) % 26) + 97;
     }
    else{
        plaintext = (((plaintext-65) + key) % 26) + 65 ;
       }
    return plaintext;
}
void ecrypt(string plaintext , int key){
    for(int count = 0,n=strlen(plaintext); count < n; count++){
            char plaintextcount = plaintext[count];
            if (isACharacter(plaintextcount)){
                char cipherText = plainToCaesar(plaintextcount,key);
                printf("%c",cipherText);
            }
            else { 
                printf("%c",plaintextcount); 
            } 
        } 
}
