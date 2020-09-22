#pragma once
#include <string>
#include "Vertebrate.h"

using namespace std;

class Pasari : public Vertebrate {
public:
  Pasari();
  virtual ~Pasari();
  string getFamilie() const;
  virtual string getSunet() const = 0;
  virtual string getSpecie() const = 0;
  virtual bool getZburatoare() const = 0;
  virtual void afisare() const;
private:
  const string* const mFamilie;
};

class PasareZburatoare : public Pasari {
public:
  PasareZburatoare();
  PasareZburatoare(string, string);
  PasareZburatoare(const PasareZburatoare&);
  PasareZburatoare& operator=(const PasareZburatoare&);
  friend istream& operator >> (istream&, PasareZburatoare&);
  virtual ~PasareZburatoare();
  string getSunet() const;
  string getSpecie() const;
  bool getZburatoare() const;
  virtual void afisare() const;
protected:
  string* mSunet;
  string* mSpecie;
  const bool mZburatoare;
};
