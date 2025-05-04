#include "DossierPatient.hpp"
#include "Patient.hpp"
#include <iostream>

// Constructeurs et destructeur
DossierPatient::DossierPatient() : idPatient(0), dossierMedical(""), notes(""), patient(nullptr) {
}

DossierPatient::DossierPatient(int idPatient, const std::string& dossierMedical, const std::string& notes)
    : idPatient(idPatient), dossierMedical(dossierMedical), notes(notes), patient(nullptr) {
}

DossierPatient::~DossierPatient() {
    // Ne pas supprimer le patient ici car il peut être partagé
}

// Getters et setters
int DossierPatient::getIdPatient() const {
    return idPatient;
}

void DossierPatient::setIdPatient(int idPatient) {
    this->idPatient = idPatient;
}

std::string DossierPatient::getDossierMedical() const {
    return dossierMedical;
}

void DossierPatient::setDossierMedical(const std::string& dossierMedical) {
    this->dossierMedical = dossierMedical;
}

std::string DossierPatient::getNotes() const {
    return notes;
}

void DossierPatient::setNotes(const std::string& notes) {
    this->notes = notes;
}

Patient* DossierPatient::getPatient() const {
    return patient;
}

void DossierPatient::setPatient(Patient* patient) {
    this->patient = patient;
}

// Méthodes spécifiques
void DossierPatient::ajouterNotes(const std::string& nouvelleNote) {
    if (!notes.empty()) {
        notes += "\n";
    }
    notes += nouvelleNote;
    std::cout << "Note ajoutée au dossier du patient ID: " << idPatient << std::endl;
}

void DossierPatient::consulterDossier() {
    std::cout << "Consultation du dossier du patient ID: " << idPatient << std::endl;
    std::cout << "Dossier medical: " << dossierMedical << std::endl;
    std::cout << "Notes: " << notes << std::endl;
}