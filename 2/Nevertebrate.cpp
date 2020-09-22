#include <iostream>
#include <string>
#include "Nevertebrate.h"

using namespace std;

unsigned int Nevertebrate::nrNevertebrate = 0;

Nevertebrate::Nevertebrate()
  : mGrup(new string("Nevertebrate")),
    mFamilie(new string("Generic")),
    mSpecie(new string("Generic")),
    mLocomotie(new string("Se taraie pe jos")),
    mMediu(new string("Terestru"))
{
  ++nrNevertebrate;
}

unsigned int Nevertebrate::getNrNevertebrate() {
  return nrNevertebrate;
}

Nevertebrate::Nevertebrate(const Nevertebrate& o)
  : mGrup(new string("Nevertebrate")),
    mFamilie(new string(*(o.mFamilie))),
    mSpecie(new string(*(o.mSpecie))),
    mLocomotie(new string(*(o.mLocomotie))),
    mMediu(new string(*(o.mMediu)))
{
  ++nrNevertebrate;
}

Nevertebrate::Nevertebrate(string familie, string specie, string locomotie, string mediu)
  : mGrup(new string("Nevertebrate")),
    mFamilie(new string(familie)),
    mSpecie(new string(specie)),
    mLocomotie(new string(locomotie)),
    mMediu(new string(mediu))
{
  ++nrNevertebrate;
}

Nevertebrate& Nevertebrate::operator = (const Nevertebrate& o) {
  if( this != &o ) {
    *mFamilie   = *(o.mFamilie);
    *mSpecie    = *(o.mSpecie);
    *mLocomotie = *(o.mLocomotie);
    *mMediu     = *(o.mMediu);
  }
  return *this;
}

istream& operator >> (istream& in, Nevertebrate& o) {
  cout << "Familie: ";
  in >> *(o.mFamilie);
  cout << "Specie: ";
  in >> *(o.mSpecie);
  cout << "Locomotie: ";
  in >> *(o.mLocomotie);
  cout << "Mediu: ";
  in >> *(o.mMediu);
  return in;
}

Nevertebrate::~Nevertebrate() {
  delete mGrup;
  delete mFamilie;
  delete mSpecie;
  delete mLocomotie;
  delete mMediu;
  --nrNevertebrate;
}

string Nevertebrate::getGrup() const {
  return *mGrup;
}

string Nevertebrate::getSpecie() const {
  return *mSpecie;
}

string Nevertebrate::getFamilie() const {
  return *mFamilie;
}

string Nevertebrate::getLocomotie() const {
  return *mLocomotie;
}

string Nevertebrate::getMediu() const {
  return *mMediu;
}

void Nevertebrate::afisare() const {
  cout << "Grup: "      << *mGrup      << endl
       << "Familie: "   << *mFamilie   << endl
       << "Specie: "    << *mSpecie    << endl
       << "Locomotie: " << *mLocomotie << endl
       << "Mediu"       << *mMediu;
}
