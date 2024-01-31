/*
ROSELLO, MA. JAZMINE P.
STUDENT NUMBER : 2021-09665
CMSC 21 - T3L
Exercise #4

*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>



//this function input asks the user for input and at the same time, it turns the word being entered in its capital base form or capital letters
void input(char word[100]){

    printf("\nEnter a word: "); //asks users for input
    scanf("%s", word);

    //this for loop is to access every letter of the word being entered, by accessing them, we will convert them into the uppercase because the program is a case sensitive
    for (int i=0; i<strlen(word); i++){
        word[i] = toupper(word[i]); //by converting every letters into uppercase, we used toupper character function and stored it into word[i]
    }
}

//this function isPalindrome is the checker if the word being input by the user is a palindrome or not
int isPalindrome(char word[100]){ 

    int a=0, count=0;
    int length;

    length = (int)strlen(word); //this is to get the length of the word being entered, it is by the use of strlen
    
    //this for loop is to get the letters in the word being entered
    for (a; a<length/2; a++){//we have divided the length of the word by 2 because the logic behind this codes is that all palindromes, for example
    //"TAPAT" notice that the 1st letter and the last letter is the same letter T and the 2nd letter and the last 2nd letter is A, so by this we can conclude that
    //getting the first letter and also getting a letter from the last letter and comparing them, if they are equal we count them and therefore, we divided the length
    //by 2 because the only thing we need to get is the 1st letter & 1st last letter and so on until the loog arrive at the middle of the word
        if(word[a]==word[length-a-1]){ //getting the 1st letter and last letter and determining if their equal
        //notice that in getting the last letter we have used word[length-a-1], the minus 1 there is to dictate that we are starting fromt he last letter, the minus
        //a is to dictate what we are getting starting from the last letter. For example, if a is 2, it means word[length-2-1], it symbolizes that we are getting the last 2nd
        //letter of the word
            count++; //if they are equal we count those letters that are equal
        }
        else{ //if the word[a] is not equal to the word[length-a-1], we will now break the loop, meaning we have detected letters 
        //that are not actually the same which dictates the the word is not a palindrome so there is no need to continue accessing other letter
            break;//therefore we break the loop
        }
    }
        
    //so if the count is equal to the length divided by 2, it means that it is palindrome since they are equal
    if(count==length/2){
        return 0; //so we return 0
    }else{ //if the count is equal to 0, it means the word is not a palindrome so 
        return 1; //we return 1
    }
}


void printing(char arr[50][100], int count){
//this function printing is in void data type because we have nothing to return
//also, this function serves as the printing of all palindromes that have been stored in the array
//also, this printing function will only utilized if the users input is "exit" meaning the program will be terminated

        printf("\nDetected terminate keyword. Goodbye!\n"); 
        if(count>0){ 
            printf("Here are all your palindromes: ");
            printf("\n\n");
            for (int i=0; i<count; i++){ 
                printf("\t%s ", arr[i]); 
                printf("\n");
            }
            printf("\n");
        }else{ 
            printf("NOTE : Among the inputs you have entered, there is no palindrome detected!\n\n"); 
        }
}


int main(){
    char word[100]; //a string consisting of 100 characters
    char arr[50][100]; //declaring a pointers to pointer array where we will store palindromes
    char exit[] = "EXIT"; //declaration of array of characters coontaining the word "EXIT"
    int index=0; //initialization of variable index as 0 which will serve as the index for arr
    
    
    do{ // we have used do while sinc eit is more appropriate because we need first to ask for the input of users before we 
    //compare it into the exit array or string
        input(word); //call the function of input with array named word as its parameters

        if(isPalindrome(word)==0){ //if the isPalindrome function returns 0, it means the word user have input is a palindrom
            strcpy(arr[index],word); //so we copy the values of the array of word and store it into the arr array[index]
            printf("%s is a palindrome!\n", word);  
            index++; //after storing, we increment variable index 1 so whenever the next word user have input is a palindrome too, it will
            //store in the arr array with and index of next one
            
        }else if(isPalindrome(word)==1 && strcmp(word,exit)!=0){ //however, if isPalindrome returns 1 and the word being entered
        //is not "EXIT", we notify users the the words they have entered is not a palindrome
                printf("%s is not a palindrome!\n", word);
        }
    }while(strcmp(word,exit)!=0); //those block of codes under the do- will be executed continuously if word array values
    // is not equal to exit array values

    //if the do-while loop stops, we will now print all the values or elements stored in arr array
    printing(arr, index); //call the function of printing by passing the string word, pointers to pointer arr(2D array), exit string and integer count
    //this printing function will be called out once that the users input is exit, this printing function will print all the palindromes detected

}

