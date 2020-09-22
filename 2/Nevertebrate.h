#pragma once
#include <string>
#include "Regn.h"

using namespace std;

class Nevertebrate : public Regn {
public:
  Nevertebrate();
  Nevertebrate(const Nevertebrate&);
  Nevertebrate(string, string, string, string);
  Nevertebrate& operator = (const Nevertebrate&);
  friend istream& operator >> (istream&, Nevertebrate&);
  virtual ~Nevertebrate();
  virtual string getFamilie() const;
  virtual string getGrup() const;
  virtual string getSpecie() const;
  virtual string getLocomotie() const;
  virtual string getMediu() const;
  static unsigned int getNrNevertebrate(); 
  virtual void afisare() const;
protected:
  const string* const mGrup;
  string* mFamilie;
  string* mSpecie;
  string* mLocomotie;
  string* mMediu;
  static unsigned int nrNevertebrate;
};
