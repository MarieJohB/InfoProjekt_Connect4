#include <iostream>
#include <fstream>
#include "Konfiguration.h"
#include "AbstractBoard.h"
#include "Ruler.h"
#include "Player.h"
#include "highscore.h"
#include "Checker.h"
#include "Celebrater.h"
using namespace::std;


#define ROWS 6
#define COLS 7


// Global, damit er in der Funktion verwendet werden kann und diese ausherlb der Main festgelegt wird
Player winner;

void NameOfWinner() {
    string dump; // fängt leeren input ab 
    getline(cin, dump);

    cout << "Und den Vornamen des Gewinners eingeben:" << endl;
    string inputVorname;
    // cin.clear();
    // fflush(stdin);

    getline(cin, inputVorname);
    winner.setVorname(inputVorname);

    cout << "Gewinner, bitte geben Sie Ihren Nachnamen ein:" << endl;
    string inputNachname;
    getline(cin, inputNachname);
    winner.setNachname(inputNachname);
    // cout << "Vorname " << inputVorname << endl;
    //  cout << "nachname " << inputNachname << endl;
}



int main(int argc, char* argv[]) {

    Konfiguration GameOn;
    Ruler Ruler;
    FileBoard Board1;
    ConsoleBoard Board2;
    Player players;
    highscore list;
    Checker check;
    Celebrater celeb;

    char board[ROWS][COLS];
    int turn = 0;
    int player1 = -1;
    int& cplayer1 = player1;
    int player2 = -1;
    int& cplayer2 = player2;

    char token1 = 'X';
    char token2 = 'O';

    string filename = "highscore.txt";

    // Hiermit könnte man die eingegebenen Parameter überprüfen:

    /*cout << "Anzahl der Argumente: " << argc << endl;
    for (int i = 0; i < argc; ++i) {
        cout << "Argument " << i << ": " << argv[i] << endl;
    }
    */

    char ausgabe;
    char* eingabe1 = argv[1]; // zweites Argument abgreifen, also die erste Eingabe

    char TextAusgeben;
    char* eingabe2 = argv[2]; // drittes Argument einlesen

    if (argc >= 3) { // wenn dar User beim Start Parameter eingegeben hat

        if (eingabe1 != NULL) {
            ausgabe = *eingabe1; // Achtung: ausgabe ist ein Charakter, das muss man Bei Vergliech etc. beachten
            //cout << "Das 2. Argument ist " << ausgabe << endl;
        }
        if (eingabe2 != NULL) {
            TextAusgeben = *eingabe2;
        }

    }
    else { // Falls beim Start keine Parameter übergeben wurde
        cout << "\033[2J\033[1;1H"; // Clear the terminal screen
        cout << "Falsche Eingabe: " << endl << "1 => Spieler 1: X | Spieler 2: O \n2 => Spieler 1: X | Spieler 2: O \n" << endl;
        cin >> ausgabe;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
        cout << "\033[2J\033[1;1H";
        cout << "T => Ausgabe des Spieles in einer .txt Datei" << endl;
        cout << "K => Ausgabe des Spieles im Terminal" << endl;
        cin >> TextAusgeben;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
        cout << "\033[2J\033[1;1H";

    }

    check.checkTextAusgabe(TextAusgeben);
    check.checkNumberAusgabe(ausgabe);

    // Überprüfen, welcher Spieler X bzw O hat
    if (ausgabe == '1') { // Spieler 1 hat X
        token1 = 'X';
        token2 = 'O';

        cout << "Spieler 1 => Token: " << token1 << " Spieler 2 => Token: " << token2 << endl;
    }
    else if (ausgabe == '2') { // 1: Spieler 2 hat X
        token1 = 'O';
        token2 = 'X';

        cout << "Spieler 1 => Token: " << token1 << " Spieler 2 => Token: " << token2 << endl;
    }


    // Überprüfen, ob das Spiel in der Konsole oder in der Text Datei stattfindet
    if (TextAusgeben == 'T') {
        cout << "Spielfeld ausgabe geschieht im .txt Datei" << endl;
        GameOn.displayText = true;
    }
    else{
        cout << "Speilfeldausgabe geschieht im Terminal" << endl;

    }

    while (GameOn.end){
        Board1.initializeBoard(board);
        GameOn.askUser(filename);

        while (GameOn.play) {
            
            if (GameOn.displayText) {

                Board1.displayBoard(board);
            }
            else
            {
                Board2.displayBoard(board);
            }


            cout << "\nSpieler " << (turn % 2 + 1) << ", waehlen Sie eine Spalte: ";
            int col = players.getInteger();
            col--; // Array-Indizes beginnen bei 0

            if (Ruler.isValidMove(board, col)) {

                Ruler.makeMove(board, col, (turn % 2 == 0) ? token1 : token2);
                Ruler.countpasses(ausgabe, (turn % 2 == 0) ? token1 : token2, cplayer1, cplayer2);

                if (Ruler.isWinningMove(board, (turn % 2 == 0) ? token1 : token2, col)) {

                    if (GameOn.displayText) {

                        Board1.displayBoard(board);
                    }
                    else
                    {
                        Board2.displayBoard(board);
                    }

                    //int zuege = Ruler.countpasses(ausgabe, (turn % 2 == 0) ? token1 : token2, cplayer1, cplayer2);
                    cout << "\nSpieler " << (turn % 2 + 1) << " gewinnt" << " in " << Ruler.countpasses(ausgabe, (turn % 2 == 0) ? token1 : token2, cplayer1, cplayer2) << " Zuege!" << endl;
                    NameOfWinner();
                    for (int i = 0; i < 10 ; i++) {
                        celeb.victoryDance();
                    }
                    cout << "gewonnen hat: " << winner.getName() << endl;
                    list.loadFromFile(filename);
                    list.insertNode(Ruler.countpasses(ausgabe, (turn % 2 == 0) ? token1 : token2, cplayer1, cplayer2) , 0, winner.getName());
                    list.saveToFile(filename);
                    GameOn.endGame();

                }
                else if (Ruler.isDraw(board)) {


                    if (GameOn.displayText) {

                        Board1.displayBoard(board);
                    }
                    else
                    {
                        Board2.displayBoard(board);
                    }
                    GameOn.endGame();
                }

                turn++;

            }
            else {
                cout << "\033[2J\033[1;1H"; // Clear the terminal screen
                cout << "Ungueltige Spalte waehle eine andere \n";
            }
        }
        
    }
    return 0;
    }

    
