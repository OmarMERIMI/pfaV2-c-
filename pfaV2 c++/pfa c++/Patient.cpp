#include "Patient.hpp"
#include "DossierPatient.hpp"
#include <iostream>

// Constructeurs et destructeur
Patient::Patient() : Utilisateur(), nom(""), prenom(""), dateNaissance(""), historiqueMedical(""), dossier(nullptr) {
}

Patient::Patient(int id, const std::string& username, const std::string& password,
                 const std::string& nom, const std::string& prenom, 
                 const std::string& dateNaissance, const std::string& historiqueMedical)
    : Utilisateur(id, username, password), nom(nom), prenom(prenom), 
      dateNaissance(dateNaissance), historiqueMedical(historiqueMedical), dossier(nullptr) {
}

Patient::~Patient() {
    // Ne pas supprimer le dossier ici car il peut être partagé
}

// Getters et setters
std::string Patient::getNom() const {
    return nom;
}

void Patient::setNom(const std::string& nom) {
    this->nom = nom;
}

std::string Patient::getPrenom() const {
    return prenom;
}

void Patient::setPrenom(const std::string& prenom) {
    this->prenom = prenom;
}

std::string Patient::getDateNaissance() const {
    return dateNaissance;
}

void Patient::setDateNaissance(const std::string& dateNaissance) {
    this->dateNaissance = dateNaissance;
}

std::string Patient::getHistoriqueMedical() const {
    return historiqueMedical;
}

void Patient::setHistoriqueMedical(const std::string& historiqueMedical) {
    this->historiqueMedical = historiqueMedical;
}

DossierPatient* Patient::getDossier() const {
    return dossier;
}

void Patient::setDossier(DossierPatient* dossier) {
    this->dossier = dossier;
}

// Méthodes spécifiques
void Patient::demanderRendezVous() {
    std::cout << "Le patient " << nom << " " << prenom << " demande un rendez-vous." << std::endl;
}

void Patient::confirmerRendezVous() {
    std::cout << "Le patient " << nom << " " << prenom << " confirme son rendez-vous." << std::endl;
}

void Patient::payerFacture() {
    std::cout << "Le patient " << nom << " " << prenom << " paie sa facture." << std::endl;
}