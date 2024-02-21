#include "Konfiguration.h"
#include <iostream>
#include <string>
#include "highscore.h"
#include <cstdlib>
#include <limits>
using namespace::std;


void Konfiguration::wait() {
    char wait;
    cout << "\nEnter zum Fortfahren druecken\n";
    cin.get(wait);
    while (wait != '\n' && wait != ' ') {
        cin.get(wait);
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
    }
    system("cls"); // Bereinigung des Terminals von allen Zeichen

}


Konfiguration::Konfiguration(char input_, int ROW_, int COL_, bool displayText_, bool play_, bool end_) {
    input = input_;
    ROW = ROW_;
    COL = COL_;
    displayText = displayText_;
    play = play_;
    end = end_;
}
// Default Konstruktur:
Konfiguration::Konfiguration() {
    this->input = 's';
    this->ROW = 6;
    this->COL = 7;
    this->displayText = false;
    this->play = false;
    this->end = true;
}


void Konfiguration::askUser(string filename) {
    do {
        string hauptmenu = R"(
%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%
%@@@*-.  .-*@@@@%=.   :=%@@@@+:   .-#@@@@*-.  .-*@@@@%=.   :+%@@@@+:   .-#@@@@*-.  .-*@@@%
%@@-        :@@*         #@%.        +@@:        :@@*         #@%.        +@@:        :@@%
%@%          *@.         -@=          @#          #@.         -@=          @#          #@%
%@@.         %@=         *@#         -@@.        .@@=         *@#         -@%.        .@@%
%@@%=      -%@@@+.     :#@@@#:     .+@@@%=      -%@@@+.     :#@@@#:     .+@@@%-      -%@@%
%@@@@@%###@@@@@@@@%#*#%@@@@@@@@#*#%@@@@@@@@%###@@@@@@@@%#*#@@@@@@@@@#*#%@@@@@@@@####@@@@@%
%@@@%=:..:=#@@@@@+-..:-*@@@@@*-:..-+%@@@@%=:..:=#@@@@@+-..:-*@@@@@*-:..-+%@@@@%=:..:=#@@@%
%@@+        -@@#        .%@%:        *@@=   s    =@@#        .%@%:        *@@=        =@@%
%@%          *@.         -@=          @#   ===    #@.         -@=          @#          #@%
%@@          %@-         +@*         :@% Spielen %@-.         +@*         :@%          %@%
%@@#:      :#@@@=       +@@@*.      -%@@#:      :#@@@=      .+@@@+.      -%@@#:      :#@@%
%@@@@%*++*%@@@@@@@#+++#@@@@@@@#*++*@@@@@@@%*++*%@@@@@@@#++*#@@@@@@@#*++*@@@@@@@%*++*%@@@@%
%@@@@*=--=*%@@@@@#=---+%@@@@@%+---=#@@@@@@%%%%%%@@@@@@#=---+%@@@@@%+---=#@@@@@@*=--=*@@@@%
%@@*   e   +@@%.        -@@@-   h   .#@@%########%@@%.       -@@@-       .#@@+        +@@%
%@%   ===   #@:          =@+   ===   .@@##########@@:         =@+         .@#          %@%
%@  Beenden #@:          =@+  Hilfe  .@@##########@@:         =@+         .@%          %@%
%@@*       +@@%:        -@@@=       .%@@%########%@@%:       -@@@=       :%@@*        *@@%
%@@@@*=--=*@@@@@@#+=-=+%@@@@@%+=-=+#@@@@@@@%%%%%@@@@@@#+=-=+%@@@@@%+=-=+#@@@@@@*=--=*@@@@%
%@@@@@%%%%@@@@@@@%*++*#@@@@@@@@%%%%@@@@@@@@%%%%@@@@@@@%*+=+*@@@@@@@#*++*%@@@@@@#+==+#@@@@%
%@@@########%@@%=......:*@@@%#######%@@@@########@@@@-       =@@@*:......-%@@#.      .#@@%
%@@##########@@-.........*@%##########@@##########@@:         =@#.........:@%          %@%
%@@##########@@:.........+@%##########@@##########@@.         -@*.........:@#          #@%
%@@%########%@@#:.......=@@@%########@@@%########%@@#.       :%@@=.......:#@@=        =@@%
%@@@@%%%%%%@@@@@@*=--=+#@@@@@@%%%%%%@@@@@@%%%%%%@@@@@@*=:::=#@@@@@%+=--=*@@@@@%+-::-+%@@@%
%@@@@@####@@@@@@@@@%%@@@@@@@@@%#*#%@@@@@@@@####@@@@@@@@%***%@@@@@@@%#*#%@@@@@@@@#**#@@@@@%
%@@%=:....:=%@@@%#######%@@@#-.....:+@@@%=:....:=%@@@=   b  .*@@@#-.....:+@@@%-      -%@@%
%@@:........:%@%#########%@#.........=@@:........:%@-   ===   +@#.........-@%          %@%
%@%..........#@##########%@+.........:@#..........#@.Highscore-@*..........@#          #@%
%@@+........=@@%#########@@%-.......:*@@=........=@@*        .%@@-........*@@-        -@@%
%@@@#=-::-=#@@@@@%####%%@@@@@*=:::-+%@@@@#=-::-=#@@@@%=:  .:+@@@@@*=:::-+%@@@@#-.  .-#@@@%
%@@@@@@%%%@@@@@@@@@@@@@@@@@@@@@%%%@@@@@@@@@@%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%@@@@@%
%@@@+-....:+@@@@%######%@@@@%=:....-*@@@@*-....:+%@@@%%#####%@@@@@%######%@@@@+:....:+@@@%
%@@-........:%@%#########@@#:........+@@-........:%@%#########@@@#########%@@-........-@@%
%@%..........#@##########%@+.........:@%..........*@##########%@%##########@#..........#@%
%@@-........-@@%#########@@%:........+@@=........:@@%#########@@@#########%@@-........-@@%
%@@@*-:..:-*@@@@%%#####%@@@@%+:...:=#@@@@*-:...-+@@@@@%#####%@@@@@%#####%%@@@@*-:..:-*@@@%
%@@@@@@%%@@@@@@@@@@@@@@@@@@@@@@@%@@@@@@@@@@@@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%@@@@@@%
-------------------------------------                -------------------------------------
)";

        cout << hauptmenu << "\n";
        cout << "                                      Ihre Eingabe: ";
        input = getchar();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen

        switch (input) {
        case 'h':
            Help();
            break;
        case 's':
            startGame();
            break;
        case 'b':
            getHighscore(filename);
            break;
        case 'e':
            endProgramm();
            break;
        default:
            system("cls"); // Bereinigung des Terminals von allen Zeichen
            cout << "Ungueltiger Befehl. Bitte erneut versuchen.\n" << endl;
        }
    } while (input != 'h' && input != 's' && input != 'b' && input != 'e');
}


// Spiel starten:
void Konfiguration::startGame() {
    system("cls"); // Bereinigung des Terminals von allen Zeichen
    cout << "Das Spiel wird gestartet \n" << endl;
    play = true;
    // weiteren Code eingeben oder andere Funktion hier aufrufen
}

void Konfiguration::endProgramm() {
    system("cls"); // Bereinigung des Terminals von allen Zeichen
    cout << "Das Spiel wird beendet \n" << endl;
    end = false;
    // weiteren Code eingebn oder andere Funktion hier aufrufen

}

void Konfiguration::endGame() {
    system("cls"); // Bereinigung des Terminals von allen Zeichen
    cout << "Spiel wurde beended kehre zum Hauptbildschirm zurueck! \n" << endl;
    play = false;
}


// Hilfefunktion: Spielregeln
void Konfiguration::Help() {
    system("cls"); // Bereinigung des Terminals von allen Zeichen
    cout << "\n Hier ist Hilfe:\n";
    cout << "Spielregeln fuer 4 Gewinnt \n";
    cout << "1: Zwei Spieler nehmen abwechselnd an dem Spiel teil \n";
    cout << "2: Jeder Spieler hat verschiedene Spielsteine\n";
    cout << "3: Die Spieler werfen abwechselnd einen ihrer Spielsteine in ein Raster\n";
    cout << "4: Die Spielsteine fallen immer auf den tiefsten verfuegbaren Platz im ausgewaehlten Raster.\n";
    cout << "5: Das Ziel des Spiels ist es, vier Steine der eigenen Farbe in einer Reihe zu haben.Diese Reihe kann waagerecht, senkrecht oder diagonal sein.\n";
    cout << "6: Der Spieler, der zuerst vier Steine in einer Reihe hat, gewinnt das Spiel.\n" << endl;
    wait();

}

// Highscore ausgeben lassen:
void Konfiguration::getHighscore(string filename) {
    highscore LIST2;
    LIST2.loadFromFile(filename);
    system("cls"); // Bereinigung des Terminals von allen Zeichen

ersteFrage:
    cout << "Wonach soll sortiert werden?\n" << endl;
    cout << "-N fuer Name" << endl;
    cout << "-D fuer Datum" << endl;
    cout << "-Z fuer Zuege" << endl;

    char Sortiert;
    char S;
    cout << "\nIhre Eingabe: ";
    cin >> Sortiert;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen

    switch (Sortiert) {
    case 'N':
        S = 's';
        break;
    case 'n':
        S = 's';
        break;
    case 'D':
        S = '2';
        break;
    case 'd':
        S = '2';
        break;
    case 'Z':
        S = '1';
        break;
    case 'z':
        S = '1';
        break;
    default:
        system("cls"); // Bereinigung des Terminals von allen Zeichen
        cout << "Invalide Eingabe" << endl;
        goto ersteFrage;
        break;
    }
    system("cls"); // Bereinigung des Terminals von allen Zeichen
zweiteFrage:
    cout << "Wie nach soll sortiert werden?\n" << endl;
    cout << "-u fuer Aufsteigend?" << endl;
    cout << "-b fuer Absteigend?" << endl;
    cout << "\nIhre Eingabe: ";
    cin >> Sortiert;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
    bool R;
    switch (Sortiert) {
    case 'u':
        R = true;
        break;
    case 'b':
        R = false;
        break;
    default:
        system("cls"); // Für Windows
        cout << "Invalide Eingabe" << endl;
        goto zweiteFrage;
        break;
    }
    system("cls"); // Für Windows
    string asciiArt = R"(
                                                                                                                                                                    
                                                                                                                                                                    
__/\\\________/\\\________________________/\\\____________________________________________________________________________________        
 _\/\\\_______\/\\\_______________________\/\\\____________________________________________________________________________________       
  _\/\\\_______\/\\\___/\\\____/\\\\\\\\___\/\\\____________________________________________________________________________________      
   _\/\\\\\\\\\\\\\\\__\///____/\\\////\\\__\/\\\___________/\\\\\\\\\\______/\\\\\\\\______/\\\\\______/\\/\\\\\\\_______/\\\\\\\\__     
    _\/\\\/////////\\\___/\\\__\//\\\\\\\\\__\/\\\\\\\\\\___\/\\\//////_____/\\\//////_____/\\\///\\\___\/\\\/////\\\____/\\\/////\\\_    
     _\/\\\_______\/\\\__\/\\\___\///////\\\__\/\\\/////\\\__\/\\\\\\\\\\___/\\\___________/\\\__\//\\\__\/\\\___\///____/\\\\\\\\\\\__   
      _\/\\\_______\/\\\__\/\\\___/\\_____\\\__\/\\\___\/\\\__\////////\\\__\//\\\_________\//\\\__/\\\___\/\\\__________\//\\///////___  
       _\/\\\_______\/\\\__\/\\\__\//\\\\\\\\___\/\\\___\/\\\___/\\\\\\\\\\___\///\\\\\\\\___\///\\\\\/____\/\\\___________\//\\\\\\\\\\_ 
        _\///________\///___\///____\////////____\///____\///___\//////////______\////////______\/////______\///_____________\//////////__                                                                                              
)";


    cout << asciiArt << "\n";

    LIST2.displaySorted(S, R);
    wait();
    LIST2.saveToFile(filename);

}