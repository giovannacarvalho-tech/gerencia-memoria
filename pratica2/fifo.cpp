#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    vector<int> paginas = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int capacidade = 3;

    vector<int> frames(capacidade, -1);
    queue<int> fila;

    int pageFaults = 0;
    for (int p : paginas) {
        bool hit = false;

        for (int f : frames) {
            if (f == p) {
                hit = true;
                break;
            }
        }

        if (!hit) {
            pageFaults++;

            if (fila.size() < capacidade) {
                for (int i = 0; i < capacidade; i++) {
                    if (frames[i] == -1) {
                        frames[i] = p;
                        fila.push(p);
                        break;
                    }
                }
            } else {
                int antigo = fila.front();
                fila.pop();

                for (int i = 0; i < capacidade; i++) {
                    if (frames[i] == antigo) {
                        frames[i] = p;
                        break;
                    }
                }

                fila.push(p);
            }
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

    cout << "\nTotal de Page Faults (FIFO): " << pageFaults << endl;

    return 0;
}
