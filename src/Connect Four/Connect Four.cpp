#include <iostream>
#include <fstream>
#include <cstdlib>
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
    char TextAusgeben;

    if (argc >= 3) { // wenn dar User beim Start Parameter eingegeben hat

        if (argv[1] != NULL) {
            // zweites Argument abgreifen, also die erste Eingabe
            // Achtung: ausgabe ist ein Charakter, das muss man Bei Vergliech etc. beachten
            ausgabe = *argv[1];
            //cout << "Das 2. Argument ist " << ausgabe << endl;
        }
        if (argv[2] != NULL) {
            TextAusgeben = *argv[2]; // drittes Argument einlesen
        }

    }
    else { // Falls beim Start keine Parameter übergeben wurde
        system("cls"); // Für Windows
        cout << "Falsche Eingabe: \n" << endl << "1 => Spieler 1: X | Spieler 2: O \n2 => Spieler 1: O | Spieler 2: X \n" << endl;
        cout << "Ihre Eingabe: ";
        cin >> ausgabe;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
        int check1 = check.checkNumberAusgabe(ausgabe);
        if (check1 == '1') { // Spieler 1 hat X
            token1 = 'X';
            token2 = 'O';
            ausgabe = '1';
        }
        else if (check1 == '2') { // 1: Spieler 2 hat X
            token1 = 'O';
            token2 = 'X';
            ausgabe = '2';
        }
        system("cls"); // Für Windows
        cout << "T => Ausgabe des Spieles in einer .txt Datei" << endl;
        cout << "K => Ausgabe des Spieles im Terminal \n" << endl;
        cout << "Ihre Eingabe: ";
        cin >> TextAusgeben;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
        int check2 = check.checkTextAusgabe(TextAusgeben);
        if (check2 == 'T' || check2 == 't') {
            GameOn.displayText = true;
            TextAusgeben = 'T';
        }
        system("cls"); // Für Windows

    }

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
    if (TextAusgeben == 'T' || TextAusgeben == 't') {
        cout << "Spielfeld ausgabe geschieht im .txt Datei \n" << endl;
        GameOn.displayText = true;
    }
    else {
        cout << "Speilfeldausgabe geschieht im Terminal \n" << endl;

    }

    while (GameOn.end) {
        Board1.initializeBoard(board); // Initialisierung des Spielfeldes
        GameOn.askUser(filename); // Eingabeaufforderung im Hauptmenue

        while (GameOn.play) {

            if (GameOn.displayText) { // Festlegen wo das Spiel Ausgegeben wird

                Board1.displayBoard(board);
            }
            else
            {
                Board2.displayBoard(board);
            }

             
            cout << "\nSpieler " << (turn % 2 + 1) << ", waehlen Sie eine Spalte: "; // Spaltenwahl Aufforderung korrespodierend zu dem dazugehoerigen Spielern
            int col = players.getInteger(); // Lesen der Eingabe 
            col--; // Array-Indizes beginnen bei 0
            if (Ruler.isValidMove(board, col)) { // Uberpruefen ob der Zug gueltig ist

                Ruler.makeMove(board, col, (turn % 2 == 0) ? token1 : token2); // Platzierung des Tokens
                Ruler.countpasses(ausgabe, (turn % 2 == 0) ? token1 : token2, cplayer1, cplayer2); // Zaehlung der Platzierung

                if (Ruler.isWinningMove(board, (turn % 2 == 0) ? token1 : token2, col)) { // Ueberpruefen der Gewinnkondition

                    if (GameOn.displayText) { // Festlegen wo das Spiel Ausgegeben wird

                        Board1.displayBoard(board);
                    }
                    else
                    {
                        Board2.displayBoard(board);
                    }

                    cout << "\nSpieler " << (turn % 2 + 1) << " gewinnt" << " in " << Ruler.countpasses(ausgabe, (turn % 2 == 0) ? token1 : token2, cplayer1, cplayer2) << " Zuege!" << endl; // Ausgabe des Gewinners
                    NameOfWinner(); // Festlegung des Namens des Gewinners
                    cout << "gewonnen hat: " << winner.getName() << endl; // Ausgabe des Gewinnernamens
                    list.loadFromFile(filename); // Laden des Highscores von der Text Datei
                    list.insertNode(Ruler.countpasses(ausgabe, (turn % 2 == 0) ? token1 : token2, cplayer1, cplayer2), 0, winner.getName()); // Einfügen der Daten des Gewinners in der Liste
                    list.saveToFile(filename); // Abspeicherung der Daten des Gewinners in der Text Datei
                    GameOn.endGame(); // Beenden der Spielinstanz

                }
                else if (Ruler.isDraw(board)) { // Ueberpruefen ob ein Unentschieden vorliegt


                    if (GameOn.displayText) { // Festlegen wo das Spiel Ausgegeben wird

                        Board1.displayBoard(board);
                    }
                    else
                    {
                        Board2.displayBoard(board);
                    }
                    GameOn.endGame();
                }

                turn++; // Aenderung des Spielers welcher am Zug ist

            }
            else {
                system("cls"); // Für Windows
                cout << "\nUngueltige Spalte waehle eine andere \n";
            }
        }

    }
    return 0;
}


