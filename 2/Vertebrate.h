#pragma once
#include <string>
#include "Regn.h"

using namespace std;

class Vertebrate : public Regn {
public:
  Vertebrate();
  virtual ~Vertebrate();
  virtual string getGrup() const;
  virtual string getSunet() const  = 0;
  static unsigned int getNrVertebrate();
  static void incrementNrVertebrate();
  virtual void afisare() const;
private:
  const string* const mGrup;
  static unsigned int nrVertebrate;
};
