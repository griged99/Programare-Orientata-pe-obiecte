#pragma once
#include <string>
#include "Vertebrate.h"

using namespace std;

class Reptile : public Vertebrate {
public:
  Reptile();
  Reptile(string, string);
  Reptile(const Reptile&);
  Reptile& operator = (const Reptile&);
  friend istream& operator >> (istream&, Reptile&);
  virtual ~Reptile();
  string getFamilie() const;
  virtual string getSunet() const;
  virtual string getSpecie() const;
  virtual void afisare() const;
private:
  const string* const mFamilie;
  string* mSunet;
  string* mSpecie;
};
