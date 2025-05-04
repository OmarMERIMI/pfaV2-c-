#include "Dentiste.hpp"
#include <iostream>

// Constructeurs et destructeur
Dentiste::Dentiste() : Utilisateur(), nom(""), specialite("") {
}

Dentiste::Dentiste(int id, const std::string& username, const std::string& password,
                   const std::string& nom, const std::string& specialite)
    : Utilisateur(id, username, password), nom(nom), specialite(specialite) {
}

Dentiste::~Dentiste() {
}

// Getters et setters
std::string Dentiste::getNom() const {
    return nom;
}

void Dentiste::setNom(const std::string& nom) {
    this->nom = nom;
}

std::string Dentiste::getSpecialite() const {
    return specialite;
}

void Dentiste::setSpecialite(const std::string& specialite) {
    this->specialite = specialite;
}

// Méthodes spécifiques
void Dentiste::consulterDossierPatient() {
    std::cout << "Le dentiste " << nom << " consulte le dossier d'un patient." << std::endl;
}

void Dentiste::ajouterNotes(const std::string& notes) {
    std::cout << "Le dentiste " << nom << " ajoute des notes: " << notes << std::endl;
}

void Dentiste::gererTraitement() {
    std::cout << "Le dentiste " << nom << " gère un traitement." << std::endl;
}