#include "Konfiguration.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
using namespace::std;


// Konstruktor 
Konfiguration::Konfiguration(char input_, bool displayText_, bool play_, bool end_) {
    input = input_;
    displayText = displayText_;
    play = play_;
    end = end_;
}
// Default Konstruktur:
Konfiguration::Konfiguration() {
    this->input = 's';
    this->displayText = false;
    this->play = false;
    this->end = true;
}


// Warte-Funktion
// Anwendung/Funktion: nach dem Beenden einer Funktion wird mit dem Start der naechsten Funktion gewartet, 
// bis der User Enter drueckt
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

// Die Funktion des "askUser" stellt das Hauptmenue da
// Von dort aus kann der User bestimmen, was gemacht werden soll
// Connect Four spielt als ansprechendes Layout fuer das Hauptmenue
void Konfiguration::askUser(string filename, Player& Spieler1, Player& Spieler2) {
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
        cout << "\t\t\t\t      Ihre Eingabe: "; // Dér text wird mittig unter der Abbildung platziert 
        input = getchar(); // Eingabe des Users einlesen 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen

        switch (input) { // Case-Switch zur Pruefung der Eingabe des Users
        case 'h': // Eingabe "h": Aufruf der Hilfe/Spielregeln
            Help();
            break;
        case 's': // Eingabe "s": Spiel wird gestartet, zunaechst werden die Spieler nach ihrem NAmen gefragt
            startGame(Spieler1, Spieler2); // Spieler werden weiter an die Startfunktion gegeben, dort werden die Namen eingelesen
            break;
        case 'b': // Eingabe "b": Aufruf der Bestenliste
            getHighscore(filename);
            break;
        case 'e': // Eingabe "e": Beenden des Connect Four Spiels
            endProgramm();
            break;
        default: // Default: Abfangen einer falschen Eingabe
            system("cls"); // Bereinigung des Terminals von allen Zeichen
            cout << "Ungueltiger Befehl. Bitte erneut versuchen.\n" << endl; // hier wird eine falsche Eingabe des Users abgefangen
        }
    } while (input != 'h' && input != 's' && input != 'b' && input != 'e'); // wenn eine falsche Eingabe erfolgt, bleibt man im Hauptmenue
}


// Spiel starten:
void Konfiguration::startGame(Player& Spieler1, Player& Spieler2) { // Uebergabe der Klasse mit CallByRefernece
    system("cls"); // Bereinigung des Terminals von allen Zeichen

    // zunaechst die Namen der beiden Spieler einlesen
    cout << "Player 1:\n" << endl;
    Spieler1.setName();
    system("cls"); // Bereinigung des Terminals von allen Zeichen
    cout << "Player 2:\n" << endl;
    do {
        Spieler2.setName();
    } while(Spieler2.CompareNames(Spieler2.getName(), Spieler1.getName()));

    system("cls"); // Bereinigung des Terminals von allen Zeichen
    cout << "\nSpieler 1 ist nun: " << Spieler1.getName() << "\n\nSpieler 2 ist nun: " << Spieler2.getName() << endl;
    wait(); // Warten, bis der User das Spiel fortsetzt
    system("cls"); // Bereinigung des Terminals von allen Zeichen

    play = true; // Spiel wird gestartet
}

void Konfiguration::endProgramm() { // Das Connect Four Spiel wird beendet
    system("cls"); // Bereinigung des Terminals von allen Zeichen
    cout << "Das Spiel wird beendet \n" << endl;
    end = false;
}

void Konfiguration::endGame() { // Ein Spiel wurde beendet, aber das Programm nicht 
    system("cls"); // Bereinigung des Terminals von allen Zeichen
    cout << "Spiel wurde beendet, kehre zum Hauptbildschirm zurueck! \n" << endl;
    play = false; 

}


// Hilfefunktion: Spielregeln
void Konfiguration::Help() {
    system("cls"); // Bereinigung des Terminals von allen Zeichen

    string asciiArt = R"(
      
                                                                                                                                                                                                                                                                                                                                
__/\\\________/\\\__________/\\\\\\____________/\\\\\_________________        
 _\/\\\_______\/\\\_________\////\\\__________/\\\///__________________       
  _\/\\\_______\/\\\___/\\\_____\/\\\_________/\\\______________________      
   _\/\\\\\\\\\\\\\\\__\///______\/\\\______/\\\\\\\\\________/\\\\\\\\__     
    _\/\\\/////////\\\___/\\\_____\/\\\_____\////\\\//_______/\\\/////\\\_    
     _\/\\\_______\/\\\__\/\\\_____\/\\\________\/\\\________/\\\\\\\\\\\__   
      _\/\\\_______\/\\\__\/\\\_____\/\\\________\/\\\_______\//\\///////___  
       _\/\\\_______\/\\\__\/\\\___/\\\\\\\\\_____\/\\\________\//\\\\\\\\\\_ 
        _\///________\///___\///___\/////////______\///__________\//////////__                                                                                           
)";

    // Beim Aufruf der Hilfe werden die Spielregeln angezeigt
    cout << asciiArt << "\n";
    cout << "Spielregeln fuer 4 Gewinnt: \n";
    cout << "1: Zwei Spieler nehmen abwechselnd an dem Spiel teil. \n";
    cout << "2: Die Spieler haben unterschiedliche Spielsteine.\n";
    cout << "3: Die Spieler werfen abwechselnd einen ihrer Spielsteine in ein Raster.\n";
    cout << "4: Die Spielsteine fallen immer auf den tiefsten verfuegbaren Platz in der ausgewaehlten Spalte.\n";
    cout << "5: Das Ziel des Spiels ist es, vier Steine der eigenen Farbe in einer Reihe zu haben.Diese Reihe kann waagerecht, senkrecht oder diagonal sein.\n";
    cout << "6: Der Spieler, der zuerst vier Steine in einer Reihe hat, gewinnt das Spiel.\n" << endl;
    wait(); // Warten, bis der User fortfahren moechte

}

// Highscore ausgeben lassen:
void Konfiguration::getHighscore(string filename) {
    // hier werden Funktionen der Klasse "highscore" verwendet
    highscore LIST2; // dafuer wird zunaechst ein Objekt der Klasse "highscore" erstellt
    LIST2.loadFromFile(filename); // Laden einer .txt Datei
    system("cls"); // Bereinigung des Terminals von allen Zeichen

ersteFrage: // Sprungstelle fuer goto
    cout << "Wonach soll sortiert werden?\n" << endl;
    cout << "-N fuer Name" << endl;
    cout << "-D fuer Datum" << endl;
    cout << "-Z fuer Zuege" << endl;

    char Sortiert; // verwendet fier die User-Eingabe
    char S; // S wird an die Funktion der Klasse Highscore uebergeben
    cout << "\nIhre Eingabe: ";
    cin >> Sortiert;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen

    switch (Sortiert) {
    case 'N': // sowohl Klein- als auch Großbuchstaben werden akzeptiert
    case 'n':
        S = 's';
        break;
    case 'D':
    case 'd':
        S = '2';
        break;
    case 'Z':
    case 'z':
        S = '1';
        break;
    default:
        system("cls"); // Bereinigung des Terminals von allen Zeichen
        cout << "Invalide Eingabe" << endl; // Abfangen einer falschen Eingabe
        goto ersteFrage; // Man springt zurueck zur Frage, da die Eingabe falsch war 
        break;
    }
    system("cls"); // Bereinigung des Terminals von allen Zeichen
zweiteFrage:
    cout << "Wie soll sortiert werden?\n" << endl;
    cout << "-u fuer Aufsteigend?" << endl;
    cout << "-b fuer Absteigend?" << endl;
    cout << "\nIhre Eingabe: ";
    cin >> Sortiert;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
    bool R; // R wird an die Funktion der Klasse Highscore uebergeben
    switch (Sortiert) {
    case 'u':
    case 'U':
        R = true;
        break;
    case 'b':
    case 'B':
        R = false;
        break;
    default:
        system("cls"); 
        cout << "Invalide Eingabe" << endl;
        goto zweiteFrage;
        break;
    }
    system("cls"); 
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
    // Hier werden S und R uebergeben an die Klasse Highscore 
    // von der Klasse Highscore aus erfolgt die Ausgabe auf der Konsole
    LIST2.displaySorted(S, R); // Uebergabeparameter: char sortBy, bool ascending
    wait(); // es wird gewartet, bis der User fortfahren möchte
    LIST2.saveToFile(filename); // Speichern in einer .txt Datei

}