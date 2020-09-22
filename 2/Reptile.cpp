#include <iostream>
#include "Reptile.h"

using namespace std;

Reptile::Reptile()
  : Vertebrate(),
    mFamilie(new string("Reptile")),
    mSunet(new string("Squuish")),
    mSpecie(new string("Reptila Generica"))
{}

Reptile::Reptile(string sunet, string specie)
  : Vertebrate(),
    mFamilie(new string("Reptile")),
    mSunet(new string(sunet)),
    mSpecie(new string(specie))
{}

Reptile::Reptile(const Reptile& o)
  : Vertebrate(),
    mFamilie(new string("Reptile")),
    mSunet(new string(*(o.mSunet))),
    mSpecie(new string(*(o.mSpecie)))
{}

Reptile& Reptile::operator = (const Reptile& o) {
  if(this != &o) {
    *mSunet  = *(o.mSunet);
    *mSpecie = *(o.mSpecie);
  }
  return *this;
}

istream& operator >> (istream& in, Reptile& o) {
  in >> *(o.mSunet) >> *(o.mSpecie);
  return in;
}

Reptile::~Reptile() {
  delete mFamilie;
  delete mSunet;
  delete mSpecie;
}

string Reptile::getFamilie() const {
  return *mFamilie;
}

string Reptile::getSunet() const {
  return *mSunet;
}

string Reptile::getSpecie() const {
  return *mSpecie;
}

void Reptile::afisare() const {
  Vertebrate::afisare();
  cout << "Familie: " << *mFamilie << endl
       << "Sunet: "   << *mSunet   << endl
       << "Specie: "  << *mSpecie  << endl;
}
