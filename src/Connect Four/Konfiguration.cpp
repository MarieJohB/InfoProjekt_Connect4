#include "Konfiguration.h"
#include <iostream>
#include <string>
#include "highscore.h"
#include <cstdlib>
using namespace::std;





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
        cout << "Verfuegbare Befehle: \n" << endl;
        cout << "- 'h' fuer Hilfe anzeigen" << endl;
        cout << "- 's' fuer Spiel starten" << endl;
        cout << "- 'b' um die Bestenliste zu sehen" << endl;
        cout << "- 'e' um das Programm zu beenden \n" << endl;

        // cin >> input;
        cout << "Ihre Eingabe: ";
        input = getchar();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
        // cin.get(input); // nur das erste Zeichen einlesen

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
            system("cls"); // Für Windows
            cout << "Ungueltiger Befehl. Bitte erneut versuchen.\n" << endl;
        }
    } while (input != 'h' && input != 's' && input != 'b' && input != 'e');
}


// Spiel starten:
void Konfiguration::startGame() {
    system("cls"); // Für Windows
    cout << "Das Spiel wird gestartet \n" << endl;
    play = true;
    // weiteren Code eingeben oder andere Funktion hier aufrufen
}

void Konfiguration::endProgramm() {
    system("cls"); // Für Windows
    cout << "Das Spiel wird beendet \n" << endl;
    end = false;
    // weiteren Code eingebn oder andere Funktion hier aufrufen

}

bool Konfiguration::continueGame() {
    do {

        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen

        switch (input) {
        case 'y':
            return true;
            break;
        case 'n':
            return false;
            break;
        default:
            cout << "Ungueltiger Befehl. Bitte erneut versuchen. \n" << endl;
        }
    } while (input != 'y' && input != 'n');
}

void Konfiguration::endGame() {
    system("cls"); // Für Windows
    cout << "Spiel wurde beended kehre zum Hauptbildschirm zurueck! \n" << endl;
    play = false;
}


// Hilfefunktion: Spielregeln
void Konfiguration::Help() {
    system("cls"); // Für Windows
    cout << "\n Hier ist Hilfe:\n";
    cout << "Spielregeln fuer 4 Gewinnt \n";
    cout << "1: Zwei Spieler nehmen abwechselnd an dem Spiel teil1 \n";
    cout << "2: Jeder Spieler hat verschiedene Spielsteine,  X f�r Spieler eins und O f�r Spieler zwei. \n";
    cout << "3: Die Spieler werfen abwechselnd einen ihrer Spielsteine in ein Raster, das aus sieben waagerechten und sechs senkrechten L�chern besteht. \n";
    cout << "4: Die Spielsteine fallen immer auf den tiefsten verf�gbaren Platz im ausgewaehlten Raster. \n ";
    cout << "5: Das Ziel des Spiels ist es, vier Steine der eigenen Farbe in einer Reihe zu haben.Diese Reihe kann waagerecht, senkrecht oder diagonal sein. \n";
    cout << "6: Der Spieler, der zuerst vier Steine in einer Reihe hat, gewinnt das Spiel. \n" << endl;


}

// Highscore ausgeben lassen:
void Konfiguration::getHighscore(string filename) {
    highscore LIST2;
    LIST2.loadFromFile(filename);
    system("cls"); // Für Windows

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
        system("cls"); // Für Windows
        cout << "Invalide Eingabe" << endl;
        goto ersteFrage;
        break;
    }
    system("cls"); // Für Windows
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
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
------------+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*------------
              .-*%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@##-.              
                ==+*%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%#+-+                
               .+=++#++*@#####%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%##########%%###############%%%%%%%%%%%%%%%%%%%%%%%%%%%%#####%*++#*++--               
               .=++#*++*%++++#--=======---------------===========================================------------------=----%++++#+++*#++:-               
               =-++%+++#%#####-+=-==================================================================================--+-%####%#+++%++-=               
               #-+*%+++%++++*-*+==##################################################################################==+*.#++++%+++%*+=*               
               +=+#*++*#++++#-*+-*##################################################################################*:+*:%++++#*+++#+++               
              -:++#*++##++++#=++:#############=...-%####%...:%........:###*-.........  :-    %#####    :#############:++-*++++*#+++%++:+              
              =:++%*++##++++*=++:#############- ..:@@%##% ...%:: ...:--%@#.....:--:    :-    %###@%    .%############:++==++++*%+++#++:+              
              =-+*#+++%*+++*+=+-=#############- ..:@%*+*# ...@@@:...=@@@@+ ...*@@@@@@#*@-    @#**#*    .%############+-+=-*++++%*++#*+-+              
             -=++##+++%++++#-++-=#############- ..:@-........@@@:...=@@%@+ ...@%@+-----#-    @.        +%############+:++:#++++#*++*#++-+             
            -#-++%+++*#++++%:++-*#############- ..-@*++++ ..:@@@....=@@%@+ ..:@%@:     .-    @=----    +%#############:++-#++++*#+++%++.#=            
           :#*:++#+++%+++++%:+*:##############-...-@@@%%@ ..:@@@:...=@@%@+ ..:#%@@@*   .-    @%%%@@  ..+%#############-=+-#+++++#+++%++:+#:           
          .*#*-+*#+++%++++*=+++:##############-...-@@%##% ...#--.....--#@+ ..          .-    %###@@ ...+%#############==+*-#++++#+++#*+-+#*-          
         .*###-+##++##++++#-++==##############=...-@@%### ..:#........:@@#:.           .-    %###@@ ...+%#############+-++=#++++#*++*#+=+###.         
        .*###:++#*++##++++*-*+:###############%%%%%%@%##%%%%%%@%%%%%%%%%@@%++++++++++++-+++++####@%%%%%%%##############-++-#++++##++*%++.###*.        
        =###%.++%+++#*+++++=++.################%%%%%%#####%%%%%#%%%%%%%%%%%%%%%%%%%%%%%###########%%%%%%###############-++=*++++*#+++#*+:####+        
       =#####:++%+++#++++++=+=-############################*********#####*********####**********#####%*********########==+=++++++%+++#*+:*####+       
      =#####-=+##+++#++++*=++==########*-...........*%##*=. ....... *@%+.         =%@@         ..:%@*: ........*#######=-++=#++++%+++*#++-#####=      
     -######-=+%+++#*++++#=++-=#######+ .....------:*@@=....:-------#*.    .---     +@   .--=+= ..-+ ...:++****%#######=-++-%+++++%+++#++-######-     
    :*######:++%+++#*++++#-++:########+ ....@@@@@@@@@@.....+@@@@@@@@%    .#@@@@@*    +   -@@@@@ .. * ...*%@@@@@%########.++:%+++++%+++#++:#######=    
   :*######*:+*#+++#*++++*=++-########*......-=--=--=@ ...:@@########    -@@%%%@@.   +   -#+*** ..+@*+...    :%#########.+++=*++++%*++#*+:#######*:   
  .########*:+*#+++%++++++=++-##########+++====:..:..% ....%@%#######    -@#####@.   +   ++ ....:*@@+:..:=***###########.+++-*++++#*++#*+:########*:  
  +########==+*#+++%++++++=+-=############%@@@@*.....%......+#*+++++*     -+###+-    +  .+%*##= ..@+ ...*%@@@%##########+:++-*++++#*++*#+==########+  
.+#########:++#+++#*++++#=++-=#########--------......#@+:......     *#:            .*@ ..+@@@@% ..%* ....     .#########+:+*:#++++*#+++%++.#########*.
-##########-++#+++%+++++%.++-+########%.-------------%@@%%#=--:     *@@#:        .+@@@---*##@@@---%@*----------%########*:++:*+++++#+++%++.%#########=
###########:+*#+++%*****%.+*:##########%@@@@@@@@@@@@@%%%##%%%@@@%%%%**@%@-%%%%%%+#%%%%@@@@##@%%@@@@@@@@@@@@@@@@%#########:=+:#*****%+++#*+-*##########
###########:+*#++*%%###%+=+-=############################################################################################+:++=%####%*++*#+-*##########
##########%:+*#++*%#####-++:+#####%@@%*%%#################################################################################.+*-#####%*++*#+-###########
##########+=+#*++*%#####=**-*####@%%%   %@################################################################################:*#-#####%*++*%++-##########
#########%+##%#**#+++++++++++++++@%%%%##%@*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#**#%#*:##########
########%**#%#+*#********+++++++++%@%%%@@*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++***++#*+*%#*=*########
####**+=+**#+**%#*******************@=#***************************:::::::#***#=::--::*********************************************++**%***###+=++*####
*++=+*###*+++*#%%*************=====*%.*#==========+*******+++***+#****+++#***##******#*********-::::::+**=::::::=**=-::---+**********#%#*++++*##*+==+*
+*###*++++*###*%*#++++++++**+.  --+=----=-:.      #+++++++++++++*%%%%%%%%%*++#%%%%%%%%#+++++++*-   :::===-:. :::=+=--. -:-=====*++++##%**##*++++*###*+
#**+++*###*+++++++++++++**-   =#=---------=+=    =*+++++++++++++++++++++++++++++++++++++++++++%%%%%@       #%@    ...@%@ . ....@+++++++++++*###*++++*#
++**##*+%##+++++++++++*+-    .-+*###%%%###+-    :#++++++++++++++++++++++++++++++++++++++++++++#####@*****#*%@@*######@@@#####%%%#++++++++++*#%**##**++
#**********###**+++++*+----------------------:::===================================================++++++***+********************++++*****##*++******#
%@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
)";

    cout << asciiArt << "\n";

    LIST2.displaySorted(S, R);
    char wait;
    cout << "\nIrgendein Zeichen zum Fortfahren eingeben\n";
    cin >> wait;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
    while (wait == ' ') {
        cin >> wait;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoriert alle weiteren Zeichen
        
    }
    system("cls"); // Für Windows

    // Hier weiteren Code einfuegen bzw. andere Funktionen aufrufen
    //Test

}