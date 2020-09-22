#include <iostream>
#include "Pasari.h"

Pasari::Pasari()
  : Vertebrate(),
    mFamilie(new string("Pasari"))
{}

Pasari::~Pasari() {
  delete mFamilie;
}

string Pasari::getFamilie() const {
  return *mFamilie;
}

void Pasari::afisare() const {
  Vertebrate::afisare();
  cout << "Familie: " << getFamilie() << endl;
}

PasareZburatoare::PasareZburatoare()
  : Pasari(),
    mSunet(new string("")),
    mSpecie(new string("")),
    mZburatoare(true)
{}

PasareZburatoare::PasareZburatoare(string sunet, string specie)
  : Pasari(),
    mSunet(new string(sunet)),
    mSpecie(new string(specie)),
    mZburatoare(true)
{}

PasareZburatoare::PasareZburatoare(const PasareZburatoare& o)
  : Pasari(),
    mZburatoare(true)
{
  mSunet = new string(o.getSunet());
  mSpecie = new string(o.getSpecie());
}

PasareZburatoare& PasareZburatoare::operator=(const PasareZburatoare& o) {
  if(this != &o) {
    delete mSunet;
    delete mSpecie;
    mSunet = new string(o.getSunet());
    mSpecie = new string(o.getSpecie());
  }
  return *this;
}

istream& operator >> (istream &in, PasareZburatoare& o) {
  delete o.mSunet;
  delete o.mSpecie;
  o.mSunet = new string;
  o.mSpecie = new string;
  in >> *o.mSunet >> *o.mSpecie;
  return in;
}

PasareZburatoare::~PasareZburatoare() {
  delete mSunet;
  delete mSpecie;
}

string PasareZburatoare::getSunet() const{
  return *mSunet;
}

string PasareZburatoare::getSpecie() const{
  return *mSpecie;
}

bool PasareZburatoare::getZburatoare() const {
  return mZburatoare;
}

void PasareZburatoare::afisare() const {
  Pasari::afisare();
  cout << endl
       << "Sunet: "      << *mSunet     << endl
       << "Specie: "     << *mSpecie    << endl
       << "Zburatoare: " << mZburatoare << endl;
}
