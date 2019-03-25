#include<string.h>
#include <stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<math.h>
int validation(int argc, string valid[]);
int stringToInt(string numberString);
int plainToCaesar(char plaintext,int key) ;
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
        for(int count = 0,n=strlen(plaintext); count < n; count++){
        if (((plaintext[count] >='a')&&(plaintext[count]<='z'))||((plaintext[count] >='A')&&(plaintext[count]<='Z'))){
        char cipherText=plainToCaesar(plaintext[count],key);
        printf("%c",cipherText);
        }
        else { 
        printf("%c",plaintext[count]); 
        }  

        } printf("\n");
    }
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
int validation(int numberOfArguments, string arguments[])
{
    if(numberOfArguments != 2) {
        return 1;
    }
    int flag = 0;
        for (int count =0 , n=strlen(arguments[1]) ; count < n ; count++) {
            if (!isdigit(arguments[1][count])) {
                flag = 1;
               break;
            }
        }
    return flag;
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
