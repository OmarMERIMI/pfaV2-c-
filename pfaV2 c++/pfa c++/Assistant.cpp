#include "Assistant.hpp"
#include <iostream>

// Constructeurs et destructeur
Assistant::Assistant() : Utilisateur(), nom(""), prenom("") {
}

Assistant::Assistant(int id, const std::string& username, const std::string& password,
                     const std::string& nom, const std::string& prenom)
    : Utilisateur(id, username, password), nom(nom), prenom(prenom) {
}

Assistant::~Assistant() {
}

// Getters et setters
std::string Assistant::getNom() const {
    return nom;
}

void Assistant::setNom(const std::string& nom) {
    this->nom = nom;
}

std::string Assistant::getPrenom() const {
    return prenom;
}

void Assistant::setPrenom(const std::string& prenom) {
    this->prenom = prenom;
}

// Méthodes spécifiques
void Assistant::preparerSalle() {
    std::cout << "L'assistant " << nom << " " << prenom << " prepare la salle." << std::endl;
}

void Assistant::accueillirPatient() {
    std::cout << "L'assistant " << nom << " " << prenom << " accueille un patient." << std::endl;
}

void Assistant::envoyerRappel() {
    std::cout << "L'assistant " << nom << " " << prenom << " envoie un rappel." << std::endl;
}