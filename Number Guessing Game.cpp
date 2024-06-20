#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    //scaling the random number because get rand() generate a random number between 32767
    int randomNum = 1 + rand()%100;  // thus it will generate a random number between 1 - 100
    int guess;
    
    cout << "Guess the random number between 1 and 100: ";
    do {
        cin >> guess;
        if (guess > randomNum) 
            cout << "your guess is too high, try again: ";
        else if (guess < randomNum )
            cout << "your guess is too low, try again: ";

    } while (guess != randomNum);

    cout << "Your Guess is Correct!";
    return 0;
}

