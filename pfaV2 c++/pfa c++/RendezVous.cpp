#include "RendezVous.hpp"
#include "Patient.hpp"
#include "Dentiste.hpp"
#include "SalleDeTraitement.hpp"
#include <iostream>

// Constructeurs et destructeur
RendezVous::RendezVous() : date(""), heure(""), statut(""), patient(nullptr), dentiste(nullptr), salle(nullptr) {
}

RendezVous::RendezVous(const std::string& date, const std::string& heure, const std::string& statut)
    : date(date), heure(heure), statut(statut), patient(nullptr), dentiste(nullptr), salle(nullptr) {
}

RendezVous::~RendezVous() {
    // Ne pas supprimer les pointeurs car ils peuvent être partagés
}

// Getters et setters
std::string RendezVous::getDate() const {
    return date;
}

void RendezVous::setDate(const std::string& date) {
    this->date = date;
}

std::string RendezVous::getHeure() const {
    return heure;
}

void RendezVous::setHeure(const std::string& heure) {
    this->heure = heure;
}

std::string RendezVous::getStatut() const {
    return statut;
}

void RendezVous::setStatut(const std::string& statut) {
    this->statut = statut;
}

Patient* RendezVous::getPatient() const {
    return patient;
}

void RendezVous::setPatient(Patient* patient) {
    this->patient = patient;
}

Dentiste* RendezVous::getDentiste() const {
    return dentiste;
}

void RendezVous::setDentiste(Dentiste* dentiste) {
    this->dentiste = dentiste;
}

SalleDeTraitement* RendezVous::getSalle() const {
    return salle;
}

void RendezVous::setSalle(SalleDeTraitement* salle) {
    this->salle = salle;
}

// Méthodes spécifiques
void RendezVous::ajouterRappel() {
    std::cout << "Rappel ajoute pour le rendez-vous du " << date << " à " << heure << std::endl;
}

void RendezVous::confirmer() {
    statut = "confirmé";
    std::cout << "Le rendez-vous du " << date << " à " << heure << " a ete confirme." << std::endl;
}