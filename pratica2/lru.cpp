#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> paginas = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int capacidade = 3;

    vector<int> frames(capacidade, -1);
    vector<int> recente;

    int pageFaults = 0;

    for (int p : paginas) {
        bool hit = false;

        for (int f : frames) {
            if (f == p) {
                hit = true;
                break;
            }
        }

        if (hit) {
            recente.erase(remove(recente.begin(), recente.end(), p), recente.end());
            recente.push_back(p);
        } else {
            pageFaults++;

            bool inserido = false;

            for (int i = 0; i < capacidade; i++) {
                if (frames[i] == -1) {
                    frames[i] = p;
                    inserido = true;
                    break;
                }
            }

            if (!inserido) {
                int lru = recente.front();
                recente.erase(recente.begin());

                for (int i = 0; i < capacidade; i++) {
                    if (frames[i] == lru) {
                        frames[i] = p;
                        break;
                    }
                }
            }

            recente.push_back(p);
        }

        cout << "Pagina " << p << ": ";
        for (int f : frames) {
            if (f == -1) cout << "- ";
            else cout << f << " ";
        }

        if (hit) cout << "(HIT)";
        else cout << "(FAULT)";

        cout << endl;
    }

    cout << "\nTotal de Page Faults (LRU): " << pageFaults << endl;

    return 0;
}
