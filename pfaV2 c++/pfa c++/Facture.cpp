#include "Facture.hpp"
#include "Patient.hpp"
#include "Dentiste.hpp"
#include <iostream>

// Constructeurs et destructeur
Facture::Facture() : id(0), dateEmission(""), montant(0.0f), statut(""), patient(nullptr), dentiste(nullptr) {
}

Facture::Facture(int id, const std::string& dateEmission, float montant, const std::string& statut)
    : id(id), dateEmission(dateEmission), montant(montant), statut(statut), patient(nullptr), dentiste(nullptr) {
}

Facture::~Facture() {
    // Ne pas supprimer les pointeurs car ils peuvent être partagés
}

// Getters et setters
int Facture::getId() const {
    return id;
}

void Facture::setId(int id) {
    this->id = id;
}

std::string Facture::getDateEmission() const {
    return dateEmission;
}

void Facture::setDateEmission(const std::string& dateEmission) {
    this->dateEmission = dateEmission;
}

float Facture::getMontant() const {
    return montant;
}

void Facture::setMontant(float montant) {
    this->montant = montant;
}

std::string Facture::getStatut() const {
    return statut;
}

void Facture::setStatut(const std::string& statut) {
    this->statut = statut;
}

Patient* Facture::getPatient() const {
    return patient;
}

void Facture::setPatient(Patient* patient) {
    this->patient = patient;
}

Dentiste* Facture::getDentiste() const {
    return dentiste;
}

void Facture::setDentiste(Dentiste* dentiste) {
    this->dentiste = dentiste;
}

// Méthodes spécifiques
float Facture::calculerMontant() {
    // Logique de calcul du montant (pourrait être plus complexe dans une application réelle)
    std::cout << "Calcul du montant de la facture ID: " << id << std::endl;
    return montant;
}

void Facture::payer() {
    statut = "payee";
    std::cout << "La facture ID: " << id << " a ete payee." << std::endl;
}