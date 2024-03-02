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

    // Default-Werte 
    char token1 = 'X';
    char token2 = 'O';


    /* wird in der Funktion "askUser" der Klasse Konfiguration uebergeben 
    und von der Klasse Konfiguration aus weiter an die Klasse Highscore
    fuer die Speicherung des Highscores in einer .txt Datei*/
    string filename = "highscore.txt"; 




    // Hier werden die Kommandline-Parameter ueberprueft

    // Default-Werte
    char TokenAusgeben = ' '; // In diese Variable wird 1 (Spieler 1 hat X) oder 2 (Spieler 2 hat X) eingelesen
    char SpielAusgeben = ' '; // In diese Variable wird T (Text-Datei) oder K (Konsole) eingelesen


    // if-Fall:  wenn der User beim Start Parameter eingegeben hat
    if (argc >= 3) { // 2 Eingaben vom User werden gefodert, also müssen mindestens 3 Argumente vorliegen

            TokenAusgeben = *argv[1]; // zweites Argument abgreifen, also die erste Eingabe
            SpielAusgeben = *argv[2]; // drittes Argument einlesen
    }
    else { // Falls beim Start keine Parameter uebergeben wurde

        TokenAusgeben = check.checkNumberAusgabe(); // Das Ueberprüfen der Eingabe wird aus der Main rausverlagert in die Klasse Checker
        SpielAusgeben = check.checkTextAusgabe();
        system("cls"); // Bereinigung des Terminals von allen Zeichen
    }


    // Überprüfen, welcher Spieler X bzw O hat
    // Da token1 und token2 im Main mehrfach verwendet werden, wird diese if-Pruefung nicht in eine Funktion der Klasse verlagert
    if (check.TokenZuordnen(TokenAusgeben) == 'X') { // Spieler 1 hat X
        token1 = 'X';
        token2 = 'O';

        cout << "Spieler 1 => Token: " << token1 << " Spieler 2 => Token: " << token2 << endl;
        GameOn.wait();
    }
    else if (check.TokenZuordnen(TokenAusgeben) == 'O') { // Spieler 1 hat O und somit hat Spieler 2 X
        token1 = 'O';
        token2 = 'X';

        cout << "Spieler 1 => Token: " << token1 << " Spieler 2 => Token: " << token2 << endl;
        GameOn.wait();
    }

   
   


    // Überprüfen, ob das Spiel in der Konsole oder in der Text Datei stattfindet
    GameOn.displayText = check.AusgabeZuordnen(SpielAusgeben); // Bool Funktion --> Return wird für GameOn.displayText genutzt



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

                    // Anwendung fuer den Copy-Konstruktor
                    // Der Name des Gewinners wird erstellt und eine Kopie des gewinnenden Spielers wird mithilfe des Copy-Konstruktor erstellen
                    // die Rueckgabe der Funktion getWinner ist vom Typ Player
                    //Anfertigen einer Kopie: 
                    Player Winner = players.getWinner(Ruler.PlayerTurn((turn % 2 + 1), Spieler1.getName(), Spieler2.getName()), Spieler1, Spieler2);
                    Winner.setPunktzahl(Ruler.countpasses(TokenAusgeben, (turn % 2 == 0) ? token1 : token2, cplayer1, cplayer2));
                                        

                    cout << "\nSpieler " << Winner.getName()  << " gewinnt" << " in ";
                    cout << Winner.getPunktzahl() << " Zuegen!" << endl; 
                    

                    player1 = -1;
                    player2 = -1;

                    // hier muss eine leere Eingabe vorliegen, diese wird abgefangen
                    string dump; // faengt leeren input ab 
                    getline(cin, dump);
                    GameOn.wait();

                    
                    list.loadFromFile(filename); // Laden des Highscores von der Text Datei
                    //list.insertNode(Ruler.countpasses(TokenAusgeben, (turn % 2 == 0) ? token1 : token2, cplayer1, cplayer2), Ruler.PlayerTurn((turn % 2 + 1), Spieler1.getName(), Spieler2.getName())); // Einfügen der Daten des Gewinners in der Liste
                    list.insertNode(Winner.getPunktzahl(), Winner.getName()); // Einfügen der Daten des Gewinners in der Liste
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