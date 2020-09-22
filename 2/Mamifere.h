#pragma once
#include <string>
#include "Vertebrate.h"

using namespace std;

class Mamifere : public Vertebrate {
public:
  Mamifere();
  virtual ~Mamifere();
  string getFamilie() const;
  virtual string getSunet() const = 0;
  virtual string getSpecie() const = 0;
  virtual string getLocomotie() const = 0;
  virtual bool hasConstiinta() const = 0;
  virtual void afisare() const;
private:
  const string* const mFamilie;
};

class Maimuta : public virtual Mamifere {
public:
  Maimuta();
  Maimuta(const Maimuta&);
  Maimuta(string, string, string);
  virtual ~Maimuta();
  Maimuta& operator=(const Maimuta&);
  friend istream& operator >> (istream&, Maimuta&);
  virtual string getSunet() const;
  virtual string getSpecie() const;
  virtual string getLocomotie() const;
  virtual bool hasConstiinta() const;
  virtual void afisare() const;
protected:
  bool mConstiinta;
  string* mSunet;
  string* mSpecie;
  string* mLocomotie;
};

class Om : public virtual Mamifere {
public:
  Om();
  Om(string, string, string);
  virtual ~Om();
  virtual string getSunet() const;
  virtual string getSpecie() const;
  virtual string getLocomotie() const;
  virtual bool hasConstiinta() const;
  virtual void afisare() const;
  virtual char getSex() const = 0;
protected:
  bool mConstiinta;
  string* mSunet;
  string* mSpecie;
  string* mLocomotie;
};

class Barbat : public Om {
public:
  Barbat();
  Barbat(const Barbat&);
  Barbat(string, string, string);
  Barbat& operator = (const Barbat&);
  friend istream& operator >> (istream&, Barbat&);
  virtual void afisare() const;
  char getSex() const;
protected:
  char mSex;
};

class Femeie : public Om {
public:
  Femeie();
  Femeie(const Femeie&);
  Femeie(string, string, string);
  Femeie& operator = (const Femeie&);
  friend istream& operator >> (istream&, Femeie&);
  virtual void afisare() const;
  char getSex() const;
protected:
  char mSex;
};
