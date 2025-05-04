#include "Rapport.hpp"
#include "Responsable.hpp"
#include <iostream>

// Constructeurs et destructeur
Rapport::Rapport() : id(0), type(""), date(""), contenu(""), responsable(nullptr) {
}

Rapport::Rapport(int id, const std::string& type, const std::string& date, const std::string& contenu)
    : id(id), type(type), date(date), contenu(contenu), responsable(nullptr) {
}

Rapport::~Rapport() {
    // Ne pas supprimer le responsable ici car il peut être partagé
}

// Getters et setters
int Rapport::getId() const {
    return id;
}

void Rapport::setId(int id) {
    this->id = id;
}

std::string Rapport::getType() const {
    return type;
}

void Rapport::setType(const std::string& type) {
    this->type = type;
}

std::string Rapport::getDate() const {
    return date;
}

void Rapport::setDate(const std::string& date) {
    this->date = date;
}

std::string Rapport::getContenu() const {
    return contenu;
}

void Rapport::setContenu(const std::string& contenu) {
    this->contenu = contenu;
}

Responsable* Rapport::getResponsable() const {
    return responsable;
}

void Rapport::setResponsable(Responsable* responsable) {
    this->responsable = responsable;
}

// Méthodes spécifiques
void Rapport::genererRapport() {
    std::cout << "Generation du rapport ID: " << id << " de type: " << type << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Contenu: " << contenu << std::endl;
}