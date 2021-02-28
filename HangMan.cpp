#include <bits/stdc++.h>
using namespace std;
string chooseWord();
void renderGame(string guessedWord, int badGuessCount);
char readAGuess();
string update (string guessedWord, string secretWord, char guess);
bool contains(string secretWord, char guess);
char readAGUess();
int main (int arc, char* argv[])
{
    cout << "Hang man\n" << "You can only guess for 7 times at most.\n";
    srand(time(NULL));
    string secretWord = chooseWord();
    string guessedWord = string(secretWord.length(), '-');
    int badGuessCount = 0;
    const int MAX_BAD_GUESSES = 7;
    do
    {
        renderGame(guessedWord, badGuessCount);
        if (badGuessCount == MAX_BAD_GUESSES) break;
        char guess = readAGuess();
        if (contains(secretWord, guess))
            guessedWord = update(guessedWord, secretWord, guess);
        else badGuessCount++;
    }while (badGuessCount <= MAX_BAD_GUESSES && secretWord != guessedWord);

    if (badGuessCount < MAX_BAD_GUESSES) cout << "It was " << secretWord << " .Congrats! You won the game!";
    else cout << "You lost. The correct word is " << secretWord;
}

string chooseWord()
{
    const string WORD_LIST [] = {"dog", "cat", "human"};
    const int wordCount = sizeof(WORD_LIST) / sizeof(string);
    int randomIndex = rand() % wordCount;
    return WORD_LIST[randomIndex];
}

void renderGame(string guessedWord, int badGuessCount)
{
    const string FIGURE[] = {
         "   -------------    \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",
         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |           |    \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|    \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",
         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |          /     \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |          / \\  \n"
         "   |     \n"
         " -----   \n",
};

    cout << FIGURE [badGuessCount];
    cout << guessedWord;
    cout << "\nNumber of wrong guesses: " << badGuessCount << '\n';
}

string update (string guessedWord, string secretWord, char guess)
{
    for (int i=0; i<secretWord.length(); i++)
        if (secretWord[i] == guess) guessedWord[i] =  guess;
    return guessedWord;
}

bool contains(string secretWord, char guess)
{
    for (int i=0; i<secretWord.length(); i++)
        if (secretWord[i] == guess) return true;
    return false;
}

char readAGuess()
{
    char guess; cin >> guess;
    return guess;
}
