#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <vector>
#include "Patient.hpp"
#include "Dentiste.hpp"
#include "Assistant.hpp"
#include "Responsable.hpp"
#include "RendezVous.hpp"
#include "SalleDeTraitement.hpp"

extern std::vector<Patient> patients;
extern std::vector<Dentiste> dentistes;
extern std::vector<Assistant> assistants;
extern std::vector<Responsable> responsables;
extern std::vector<RendezVous> rendezVous;
extern std::vector<SalleDeTraitement> salles;

#endif // GLOBALS_HPP
