#include <iostream>
#include "Mamifere.h"

Mamifere::Mamifere()
  : Vertebrate(),
    mFamilie(new string("Mamifere"))
{}

Mamifere::~Mamifere() {
  delete mFamilie;
}

string Mamifere::getFamilie() const {
  return *mFamilie;
}

void Mamifere::afisare() const {
  cout << "Familie: " << *mFamilie << endl;
}

Maimuta::Maimuta()
  : Mamifere(),
    mConstiinta(false),
    mSunet(new string("u u a a")),
    mSpecie(new string("Maimuta generica")),
    mLocomotie(new string("biped"))
{}

Maimuta::Maimuta(const Maimuta& o)
  : Mamifere()
{
  mConstiinta = o.mConstiinta;
  mSunet = new string(o.getSunet());
  mSpecie = new string(o.getSpecie());
  mLocomotie = new string(o.getLocomotie());
}

Maimuta::~Maimuta() {
  delete mSunet;
  delete mSpecie;
  delete mLocomotie;
}

Maimuta& Maimuta::operator=(const Maimuta& o) {
  if(this != &o) {
    delete mSunet;
    delete mSpecie;
    delete mLocomotie;
    mConstiinta = o.mConstiinta;
    mSunet = new string(o.getSunet());
    mSpecie = new string(o.getSpecie());
    mLocomotie = new string(o.getLocomotie());
  }
  return *this;
}

istream& operator >> (istream& in, Maimuta& o) {
  delete o.mSunet;
  delete o.mSpecie;
  delete o.mLocomotie;
  o.mSunet = new string;
  o.mSpecie = new string;
  o.mLocomotie = new string;
  in >> o.mConstiinta >> *(o.mSunet) >> *(o.mSpecie) >> *(o.mLocomotie);
  return in;
}

string Maimuta::getSunet() const {
  return *mSunet;
}

string Maimuta::getSpecie() const {
  return *mSpecie;
}

string Maimuta::getLocomotie() const {
  return *mLocomotie;
}

bool Maimuta::hasConstiinta() const {
  return mConstiinta;
}

void Maimuta::afisare() const {
  Mamifere::afisare();
  cout << "Constiinta: " << mConstiinta  << endl
       << "Sunet: "      << *mSunet      << endl
       << "Specie: "     << *mSpecie     << endl
       << "Locomotie: "  << *mLocomotie  << endl;
}

Om::Om()
  : Mamifere(),
    mConstiinta(true),
    mSunet(new string("Lorem ipsum dolor sit amet")),
    mSpecie(new string("Om Generic")),
    mLocomotie(new string("Biped"))
{}

Om::Om(string sunet, string specie, string locomotie)
  : Mamifere(),
    mConstiinta(true),
    mSunet(new string(sunet)),
    mSpecie(new string(specie)),
    mLocomotie(new string(locomotie))
{}

Om::~Om() {
  delete mSunet;
  delete mSpecie;
  delete mLocomotie;
}

string Om::getSunet() const {
  return *mSunet;
}

string Om::getSpecie() const {
  return *mSpecie;
}

string Om::getLocomotie() const {
  return *mLocomotie;
}

bool Om::hasConstiinta() const {
  return mConstiinta;
}

void Om::afisare() const {
  Mamifere::afisare();
  cout << "Constiinta: " << mConstiinta  << endl
       << "Sunet: "      << *mSunet      << endl
       << "Specie: "     << *mSpecie     << endl
       << "Locomotie: "  << *mLocomotie  << endl;
}

Barbat::Barbat()
  : Om(),
    mSex('M')
{}

Barbat::Barbat(string sunet, string specie, string locomotie)
  : Om(sunet, specie, locomotie),
    mSex('M')
{}

Barbat::Barbat(const Barbat& o)
  : Om()
{
  mConstiinta   = o.mConstiinta;
  *mSunet       = *(o.mSunet);
  *mSpecie      = *(o.mSpecie);
  *mLocomotie   = *(o.mLocomotie);
  mSex          = o.mSex;
}

Barbat& Barbat::operator = (const Barbat& o) {
  if(this != &o) {
    mConstiinta   = o.mConstiinta;
    *mSunet       = *(o.mSunet);
    *mSpecie      = *(o.mSpecie);
    *mLocomotie   = *(o.mLocomotie);
    mSex          = o.mSex;
  }
  return *this;
}

istream& operator >> (istream& in, Barbat& o) {
  in >> *(o.mSunet) >> *(o.mSpecie) >> *(o.mLocomotie);
  return in;
}

void Barbat::afisare() const {
  Om::afisare();
  cout << "Sex: " << mSex << endl;
}

char Barbat::getSex() const {
  return mSex;
}

Femeie::Femeie()
  : Om(),
    mSex('F')
{}

Femeie::Femeie(string sunet, string specie, string locomotie)
  : Om(sunet, specie, locomotie),
    mSex('F')
{}

Femeie::Femeie(const Femeie& o)
: Om()
{
  mConstiinta   = o.mConstiinta;
  *mSunet       = *(o.mSunet);
  *mSpecie      = *(o.mSpecie);
  *mLocomotie   = *(o.mLocomotie);
  mSex          = o.mSex;
}

Femeie& Femeie::operator = (const Femeie& o) {
  if(this != &o) {
    mConstiinta   = o.mConstiinta;
    *mSunet       = *(o.mSunet);
    *mSpecie      = *(o.mSpecie);
    *mLocomotie   = *(o.mLocomotie);
    mSex          = o.mSex;
  }
  return *this;
}

istream& operator >> (istream& in, Femeie& o) {
  in >> *(o.mSunet) >> *(o.mSpecie) >> *(o.mLocomotie);
  return in;
}

void Femeie::afisare() const {
  Om::afisare();
  cout << "Sex: " << mSex << endl;
}

char Femeie::getSex() const {
  return mSex;
}
