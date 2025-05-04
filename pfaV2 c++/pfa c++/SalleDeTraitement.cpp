#include "SalleDeTraitement.hpp"
#include "Assistant.hpp"
#include "RendezVous.hpp"
#include <iostream>
#include <algorithm>

// Constructeurs et destructeur
SalleDeTraitement::SalleDeTraitement() : id(0), nom(""), equipements(""), statut(""), assistant(nullptr) {
}

SalleDeTraitement::SalleDeTraitement(int id, const std::string& nom, const std::string& equipements, const std::string& statut)
    : id(id), nom(nom), equipements(equipements), statut(statut), assistant(nullptr) {
}

SalleDeTraitement::~SalleDeTraitement() {
    // Ne pas supprimer les pointeurs car ils peuvent être partagés
}

// Getters et setters
int SalleDeTraitement::getId() const {
    return id;
}

void SalleDeTraitement::setId(int id) {
    this->id = id;
}

std::string SalleDeTraitement::getNom() const {
    return nom;
}

void SalleDeTraitement::setNom(const std::string& nom) {
    this->nom = nom;
}

std::string SalleDeTraitement::getEquipements() const {
    return equipements;
}

void SalleDeTraitement::setEquipements(const std::string& equipements) {
    this->equipements = equipements;
}

std::string SalleDeTraitement::getStatut() const {
    return statut;
}

void SalleDeTraitement::setStatut(const std::string& statut) {
    this->statut = statut;
}

Assistant* SalleDeTraitement::getAssistant() const {
    return assistant;
}

void SalleDeTraitement::setAssistant(Assistant* assistant) {
    this->assistant = assistant;
}

// Méthodes spécifiques
void SalleDeTraitement::preparer() {
    statut = "preparee";
    std::cout << "La salle " << nom << " a ete preparee." << std::endl;
}

void SalleDeTraitement::verifierEquipement() {
    std::cout << "Verification de l'equipement de la salle " << nom << std::endl;
    std::cout << "Equipements: " << equipements << std::endl;
}

void SalleDeTraitement::ajouterRendezVous(RendezVous* rdv) {
    rendezVous.push_back(rdv);
    std::cout << "Rendez-vous ajoute à la salle " << nom << std::endl;
}

void SalleDeTraitement::retirerRendezVous(RendezVous* rdv) {
    auto it = std::find(rendezVous.begin(), rendezVous.end(), rdv);
    if (it != rendezVous.end()) {
        rendezVous.erase(it);
        std::cout << "Rendez-vous retire de la salle " << nom << std::endl;
    }
}