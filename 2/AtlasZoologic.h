#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Regn.h"
#include "Nevertebrate.h"

using namespace std;

template <class T>
class AtlasZoologic {
public:
  // AtlasZoologic();
  void operator += (const T&);
  bool gol() const;
  void afisare() const;
private:
  static unsigned int nrAnimale;
  vector<Regn*> Pagini;
};

template<class T>
unsigned int AtlasZoologic<T>::nrAnimale = 0;

template<class T>
void AtlasZoologic<T>::operator += (const T& o) {
  Pagini.push_back(o);
  ++nrAnimale;
}

template<class T>
bool AtlasZoologic<T>::gol() const {
  return (nrAnimale == 0);
}

template<class T>
void AtlasZoologic<T>::afisare() const {
  for(unsigned int i = 0; i < nrAnimale; ++i) {
    cout << endl;
    Pagini[i] -> afisare();
  }
}

template<>
class AtlasZoologic<Nevertebrate> {
public:
  void operator += (const Nevertebrate& o) {
    Pagini.push_back(o);
    ++mNrNevertebrate;
  }
  bool gol() const {
    return (AtlasZoologic<Nevertebrate>::mNrNevertebrate == 0);
  }
  void afisare() const {
    for(unsigned int i = 0; i < mNrNevertebrate; ++i) {
      Pagini[i].afisare();
    }
    cout << endl << "Numarul de nevertebrate: " << mNrNevertebrate << endl;
  }
private:
  static unsigned int mNrNevertebrate;
  vector<Nevertebrate> Pagini;
};

unsigned int AtlasZoologic<Nevertebrate>::mNrNevertebrate = 0;
