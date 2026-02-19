#include <iostream>
#include <string>

using namespace std;

int main() {
    // Zmienne stanu gry [1, 2]
    int lokacja = 0; // 0: Start, 1: Zbrojownia, 2: Korytarz, 3: Wyjście
    bool maMiecz = false;
    bool graUruchomiona = true;
    int wybor;

    // Moduł I: Menu startowe (Pętla do-while) [3, 1]
    do {
        cout << "--- LOCHY C++: UCZNIOWSKA PRZYGODA ---" << endl;
        cout << "1. Rozpocznij gre" << endl;
        cout << "2. Wyjdz" << endl;
        cout << "Twoj wybor: ";
        cin >> wybor;

        if (wybor == 2) {
            cout << "Do zobaczenia!" << endl;
            return 0;
        }
    } while (wybor!= 1);

    cout << "\nBudzisz sie w ciemnej celi..." << endl;

    // Moduł V: Serce gry (Pętla while - Game Loop) 
    while (graUruchomiona) {
        cout << "\n-------------------------------------" << endl;
        
        // Moduł II: Zarządzanie lokalizacjami (switch) [5, 6]
        switch (lokacja) {
            case 0: // Cela startowa
                cout << "Jestes w celi. Widzisz otwarte drzwi na polnoc." << endl;
                cout << "1. Idz na polnoc (do Zbrojowni)" << endl;
                cout << "2. Przeszukaj cele" << endl;
                cout << "0. Wyjdz z gry" << endl;
                
                cin >> wybor;
                if (wybor == 1) {
                    lokacja = 1;
                } else if (wybor == 2) {
                    // Moduł III: Przeszukiwanie (pętla for) [7, 8]
                    cout << "Przeszukujesz cele";
                    for (int i = 0; i < 3; i++) {
                        cout << "."; 
                    }
                    cout << "\nNic nie znalazles oprócz kurzu." << endl;
                } else if (wybor == 0) {
                    graUruchomiona = false; // break pętli while [2]
                }
                break;

            case 1: // Zbrojownia
                cout << "Wchodzisz do Zbrojowni. Na scianie wisi stary miecz." << endl;
                cout << "1. Wez miecz" << endl;
                cout << "2. Idz dalej na wschod (Korytarz)" << endl;
                cout << "3. Wroc do celi (Poludnie)" << endl;
                
                cin >> wybor;
                // Logika warunkowa (if-else) [5, 9]
                if (wybor == 1) {
                    if (!maMiecz) {
                        maMiecz = true;
                        cout << "Podniosles miecz! Czujesz sie pewniej." << endl;
                    } else {
                        cout << "Juz masz miecz." << endl;
                    }
                    continue; // Pominiecie reszty i powrot na poczatek petli [10]
                } else if (wybor == 2) {
                    lokacja = 2;
                } else if (wybor == 3) {
                    lokacja = 0;
                }
                break;

            case 2: // Korytarz z przeciwnikiem
                cout << "W ciemnym korytarzu drogę zastępuje Ci Goblin!" << endl;
                cout << "1. Walcz" << endl;
                cout << "2. Uciekaj do Zbrojowni" << endl;
                
                cin >> wybor;
                if (wybor == 1) {
                    // Zlozony warunek logiczny [11]
                    if (maMiecz) {
                        cout << "Dzieki mieczowi pokonujesz Goblina i biegniesz do wyjscia!" << endl;
                        lokacja = 3;
                    } else {
                        cout << "Bez broni nie masz szans. Goblin Cie pokonal. KONIEC GRY." << endl;
                        graUruchomiona = false;
                    }
                } else {
                    lokacja = 1;
                }
                break;

            case 3: // Wyjscie
                cout << "Gratulacje! Wydostales sie na wolnosc!" << endl;
                graUruchomiona = false;
                break;

            default: // Obsluga nieoczekiwanych stanów [12]
                cout << "Cos poszlo nie tak... wracasz do celi." << endl;
                lokacja = 0;
                break;
        }
    }

    cout << "Dziekujemy za gre!" << endl;
    return 0;
}