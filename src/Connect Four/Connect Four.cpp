#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Konfiguration.h"
#include "AbstractBoard.h"
#include "ConsoleBoard.h"
#include "FileBoard.h"
#include "Ruler.h"
#include "Player.h"
#include "highscore.h"
#include "Checker.h"
#include "Celebrater.h"
using namespace::std;


#define ROWS 6
#define COLS 7


int main(int argc, char* argv[]) {

    Konfiguration GameOn;
    Ruler Ruler;
    Player players;
    Player Spieler1;
    Player Spieler2;
    highscore list;
    Checker check;
    Celebrater celeb;

    AbstractBoard* boardDisplay;

    char board[ROWS][COLS];
    int turn = 0;
    int player1 = -1;
    int& cplayer1 = player1;
    int player2 = -1;
    int& cplayer2 = player2;

    char token1 = 'X';
    char token2 = 'O';

    string filename = "highscore.txt";

    // Hier werden die Kommandline-Parameter ueberprueft

    char TokenAusgeben; // In diese Variable wird 1 (Spieler 1 hat X) oder 2 (Spieler 2 hat X) eingelesen
    char SpielAusgeben; // In diese Variable wird T (Text-Datei) oder K (Konsole) eingelesen


    // if-Fall:  wenn der User beim Start Parameter eingegeben hat
    if (argc >= 3) { // 2 Eingaben vom User werden gefodert, also müssen mindestens 3 Argumente vorliegen

        // bevor der Pointer Dereferenziert wird, wird NULL-Pointer geprüft, aber dies prüft auch schon die if-Abfrage
        if (argv[1] != NULL) {
            // zweites Argument abgreifen, also die erste Eingabe
            // Achtung: Es handelt sich um Charakter, das muss man Bei Vergliech etc. beachten
            TokenAusgeben = *argv[1];
        }
        if (argv[2] != NULL) {
            SpielAusgeben = *argv[2]; // drittes Argument einlesen
        }

    }
    else { // Falls beim Start keine Parameter uebergeben wurde
        system("cls"); // Bereinigung des Terminals von allen Zeichen
        cout << "Falsche Eingabe: \n" << endl << "1 => Spieler 1: X | Spieler 2: O \n2 => Spieler 1: O | Spieler 2: X \n" << endl;
        cout << "Ihre Eingabe: ";
        cin >> TokenAusgeben;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
        int check1 = check.checkNumberAusgabe(TokenAusgeben); // Das Ueberprüfen der Eingabe wird aus der Main rausverlagert in die Klasse Checker

        if (check1 == '1') { // Spieler 1 hat X
            token1 = 'X';
            token2 = 'O';
            TokenAusgeben = '1';
        }
        else if (check1 == '2') { // 1: Spieler 2 hat X
            token1 = 'O';
            token2 = 'X';
            TokenAusgeben = '2';
        }

        system("cls"); // Bereinigung des Terminals von allen Zeichen
        cout << "T => TokenAusgeben des Spieles in einer .txt Datei" << endl;
        cout << "K => Ausgabe des Spieles im Terminal \n" << endl;
        cout << "Ihre Eingabe: ";
        cin >> SpielAusgeben;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
        int check2 = check.checkTextAusgabe(SpielAusgeben);

        if (check2 == 'T' || check2 == 't') {
            GameOn.displayText = true;
            SpielAusgeben = 'T';
        }
        system("cls"); // Bereinigung des Terminals von allen Zeichen

    }

    // Überprüfen, welcher Spieler X bzw O hat
    if (TokenAusgeben == '1') { // Spieler 1 hat X
        token1 = 'X';
        token2 = 'O';

        cout << "Spieler 1 => Token: " << token1 << " Spieler 2 => Token: " << token2 << endl;
    }
    else if (TokenAusgeben == '2') { // 1: Spieler 2 hat X
        token1 = 'O';
        token2 = 'X';

        cout << "Spieler 1 => Token: " << token1 << " Spieler 2 => Token: " << token2 << endl;
    }


    // Überprüfen, ob das Spiel in der Konsole oder in der Text Datei stattfindet
    if (SpielAusgeben == 'T' || SpielAusgeben == 't') {
        cout << "Spielfeldausgabe geschieht im .txt Datei \n" << endl;
        GameOn.displayText = true;
    }
    else {
        cout << "Spielfeldausgabe geschieht im Terminal \n" << endl;

    }







    if (GameOn.displayText) { // Festlegen wo das Spiel Ausgegeben wird
        boardDisplay = new FileBoard();
    }
    else {
        boardDisplay = new ConsoleBoard();
    };

    while (GameOn.end) {
        boardDisplay->initializeBoard(board); // Initialisierung des Spielfeldes
        // Eingabeaufforderung im Hauptmenue
       // Uebergabe der beiden Spieler, damit dies weiter gegeben werden kann, wenn das Spiel gestartet wird und die Namen eingegeben werden
        GameOn.askUser(filename, Spieler1, Spieler2);

        while (GameOn.play) {

            boardDisplay->displayBoard(board);


            cout << "\nSpieler " << Ruler.PlayerTurn((turn % 2 + 1), Spieler1.getName(), Spieler2.getName()) << ", waehlen Sie eine Spalte: "; // Spaltenwahl Aufforderung korrespodierend zu dem dazugehoerigen Spielern
            int col = players.getInteger(); // Lesen der Eingabe 
            col--; // Array-Indizes beginnen bei 0

            if (Ruler.isValidMove(board, col)) { // Uberpruefen ob der Zug gueltig ist

                Ruler.makeMove(board, col, (turn % 2 == 0) ? token1 : token2); // Platzierung des Tokens
                Ruler.countpasses(TokenAusgeben, (turn % 2 == 0) ? token1 : token2, cplayer1, cplayer2); // Zaehlung der Platzierung

                if (Ruler.isWinningMove(board, (turn % 2 == 0) ? token1 : token2, col)) { // Ueberpruefen der Gewinnkondition

                    boardDisplay->displayBoard(board);

                    cout << "\nSpieler " << Ruler.PlayerTurn((turn % 2 + 1), Spieler1.getName(), Spieler2.getName()) << " gewinnt" << " in ";
                    cout << Ruler.countpasses(TokenAusgeben, (turn % 2 == 0) ? token1 : token2, cplayer1, cplayer2) << " Zuege!" << endl; // Ausgabe des Gewinners

                    player1 = -1;
                    player2 = -1;

                    // hier muss eine leere eingabe vorliegen
                    string dump; // faengt leeren input ab 
                    getline(cin, dump);
                    GameOn.wait();


                    list.loadFromFile(filename); // Laden des Highscores von der Text Datei
                    list.insertNode(Ruler.countpasses(TokenAusgeben, (turn % 2 == 0) ? token1 : token2, cplayer1, cplayer2), Ruler.PlayerTurn((turn % 2 + 1), Spieler1.getName(), Spieler2.getName())); // Einfügen der Daten des Gewinners in der Liste
                    list.saveToFile(filename); // Abspeicherung der Daten des Gewinners in der Text Datei
                    GameOn.endGame(); // Beenden der Spielinstanz

                }
                else if (Ruler.isDraw(board)) { // Ueberpruefen ob ein Unentschieden vorliegt

                    boardDisplay->displayBoard(board);
                    player1 = -1;
                    player2 = -1;

                    GameOn.endGame();

                }

                turn++; // Aenderung des Spielers welcher am Zug ist

            }
            else {

                system("cls"); // Bereinigung des Terminals von allen Zeichen
                cout << "\nUngueltige Spalte waehle eine andere \n";
            }
        }

    }
    return 0;
}