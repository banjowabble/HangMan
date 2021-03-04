#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
string chooseWord();
void renderGame(string& guessedWord, const int& badGuessCount, const int& MAX_BAD_GUESSES, char* badGuesses);
char readAGuess();
void update (string& guessedWord, const string& secretWord, char guess);
bool contains(const string& secretWord, char guess);
char readAGUess();
string toLowerCase(const string& word);

//const int MAX_BAD_GUESSES = 7;
//char badGuesses[MAX_BAD_GUESSES];

int main (int arc, char* argv[])
{
    //cout << "Hang man\n" << "You can only guess for 7 times at most.\n";
    srand(time(NULL));
    string secretWord = chooseWord();
    string guessedWord = string(secretWord.length(), '-');
    int badGuessCount = 0;
    const int MAX_BAD_GUESSES = 7;
    char badGuesses[MAX_BAD_GUESSES];

    do
    {
        renderGame(guessedWord, badGuessCount, MAX_BAD_GUESSES, badGuesses);
        if (badGuessCount == MAX_BAD_GUESSES) break;
        char guess = readAGuess();
        if (contains(secretWord, guess)) update(guessedWord, secretWord, guess);
        else {badGuesses[badGuessCount]=guess; badGuessCount++;}
    }while (badGuessCount <= MAX_BAD_GUESSES && secretWord != guessedWord);

    if (badGuessCount < MAX_BAD_GUESSES) cout << "It was " << secretWord << " .Congrats! You won the game!";
    else cout << "You lost. The correct word is " << secretWord;
}

string chooseWord()
{
    vector<string> wordList;
    ifstream myFile ("wordList.txt");
    if (myFile.is_open())
    {
        string word;
        while (myFile >> word)
        {
            wordList.push_back(word);
        }
        myFile.close();
    }
    if (wordList.size()>0)
    {
        int randomIndex = rand() % wordList.size();
        return toLowerCase(wordList.at(randomIndex));
    }
    else return "";
}

void renderGame(string& guessedWord, const int& badGuessCount, const int& MAX_BAD_GUESSES, char* badGuesses)
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

    cout <<
         "                    \n"
         "                    \n"
         "                    \n"
         "                    \n"
         "                    \n"
         "                    \n"
         "                    \n"
         "                    \n"
         "                    \n"
         "                    \n"
         "                    \n"
         "                    \n"
         "                    \n"
         "                    \n"
         "                    \n"
         "                    \n"
         "                    \n"
         "                    \n"
         "                    \n"
         "                    \n"
         "                    \n";
    cout << FIGURE [badGuessCount];
    cout << guessedWord;
    cout << "\nNumber of wrong guesses: " << badGuessCount << ' ';
    if(badGuessCount>0)
    {
        cout << ", which are: ";
        for (int i=0; i<badGuessCount; i++) cout << badGuesses[i] << ' ';
    }
}

void update (string& guessedWord, const string& secretWord, char guess)
{
    for (int i=0; i<secretWord.length(); i++)
        if (secretWord[i] == guess) guessedWord[i] =  guess;
}

bool contains(const string& secretWord, char guess)
{
    for (int i=0; i<secretWord.length(); i++)
        if (secretWord[i] == guess) return true;
    return false;
}

char readAGuess()
{
    char guess; cin >> guess;
    if (guess>65 && guess<90) guess=tolower(guess);
    return guess;
}

string toLowerCase(const string& word)
{
    string res = word;
    transform(word.begin(), word.end(), res.begin(), ::tolower);
    return res;
}
