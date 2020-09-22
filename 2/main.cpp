#include <iostream>
#include "Regn.h"
#include "Pesti.h"
#include "Pasari.h"
#include "Mamifere.h"
#include "Reptile.h"
#include "AtlasZoologic.h"
#include "Nevertebrate.h"

int main() {
  int n;
  cout << "Introdu un numar n de pagini: ";
  cin >> n;
  // Regn*[n] _pagini;
  AtlasZoologic<Regn*> atlas;
  while(n--) {
    int alegere;
    cout << "Au ramas " << n+1 << " pagini. Ce vrei sa adaugi?\n";
    cout << "1. Un barbat.\n";
    cout << "2. O femeie.\n";
    cout << "3. O maimuta.\n";
    cout << "4. O femeie care devine barbat.\n";
    cout << "5. O stiuca.\n";
    cout << "6. O nevertebrata.\n";
    cin >> alegere;

    try {
      switch (alegere) {
        case 1:
          atlas += (new Barbat);
          break;
        case 2:
          atlas += (new Femeie);
          break;
        case 3:
          atlas += (new Maimuta);
          break;
        case 4:
          atlas += ( dynamic_cast<Barbat*>(new Femeie) );
          break;
        case 5:
          atlas += (new PesteGeneric("Stiuca"));
          break;
        case 6:
          Nevertebrate *aux = new Nevertebrate;
          cin >> *aux;
          atlas += aux;
          break;
      }
    } catch (exception &e) {
      cerr << "Catched: " << e.what() << endl;
    }
  }
  atlas.afisare();

  AtlasZoologic<Nevertebrate> atlasNevertebrate;
  cout << "\n********Atlas Nevertebrate********\nCate pagini doresti?";
  cin >> n;
  cout << "Introdu datele: \n";
  while(n--) {
    cout << endl;
    Nevertebrate* aux = new Nevertebrate;
    cin >> *aux;
    atlasNevertebrate += *aux;
  }
  atlasNevertebrate.afisare();
}
