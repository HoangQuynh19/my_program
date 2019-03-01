#include<iostream>
#include<ctime>
#include <cstdlib>

using namespace std;

const int GuessCountFail=5;

int generateRandomNumber()
{
    return rand() % 100 + 1;
}
int getPlayerGuess(){
    int num;
    cout << endl << "Enter your number between 1 and 100: ";
    cin>>num;
    return num;
}
void printAnswer(int number,int randomNumber){
    if (number>randomNumber) cout<<endl<<"Your number is higher"<<endl;
    else if (number<randomNumber) cout<<endl<<"Your number is lower"<<endl;
         else cout<<endl<< "Congratulation! You win."<<endl;
}
int playAgain(){
    cout<<endl<<"Do you want to play again ?"<<endl
        <<"Yes(1) or No(0) ?"<<endl;
    int Answer;
    cin>>Answer;
    return Answer;
}

int main(){
    srand(time(NULL));
    int number;
    int randomNumber;
    do {
        int badGuessCount=1;
        randomNumber=generateRandomNumber();
        do{
            number=getPlayerGuess();
            printAnswer(number,randomNumber);
            badGuessCount++;
            if (badGuessCount>GuessCountFail && number!=randomNumber){
                cout <<endl<<"You lost"<<endl;
                break;
            }
        } while (number!=randomNumber);

        int Answer=playAgain();
        if(Answer!= 1) break;
    } while(true);
    return 0;
}
