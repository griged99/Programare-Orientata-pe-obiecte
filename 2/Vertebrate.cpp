#include <iostream>
#include "Vertebrate.h"

unsigned int Vertebrate::nrVertebrate = 0;


Vertebrate::Vertebrate()
  : mGrup(new std::string("Vertebrate"))
{
  incrementNrVertebrate();
}

void Vertebrate::incrementNrVertebrate() {
  ++nrVertebrate;
}

unsigned int Vertebrate::getNrVertebrate() {
  return nrVertebrate;
}

Vertebrate::~Vertebrate() {
  --nrVertebrate;
  delete mGrup;
}

std::string Vertebrate::getGrup() const {
  return *mGrup;
}

void Vertebrate::afisare() const {
  cout << "Grup: " << getGrup() << endl;
}
