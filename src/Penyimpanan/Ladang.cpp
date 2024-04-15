#include "Ladang.hpp"

void Ladang::cetakLadang(string label) {
    cout << "    ";
    cout << "================[ " << label << " ]=================" << endl << endl; 

    cout << "    ";
    for (int i = 0; i < n; i++) {
        cout << "   " << (char) ('A' + i) << "  ";
    }
    cout << " " << endl;

    cout << "    ";
    for (int i = 0; i < n; i++) {
        cout << "+-----";
    }
    cout << "+" << endl;

    for (int i = 0; i < m; i++) {
        cout << " " << setw(2) << setfill('0') << i + 1 << " ";

        for (int j = 0; j < n; j++) {
            cout << "| ";
            if (data[i][j] == nullptr) {
                cout << setw(3) << "   "; 
            } else {
                cout << setw(3) << data[i][j]->getKodeHuruf();
            }
            cout << " ";
        }

        cout << "|" << endl;

        cout << "    ";
        for (int i = 0; i < n; i++) {
            cout << "+-----";
        }
        cout << "+" << endl;
    }
}
