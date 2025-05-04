#ifndef RENDEZVOUS_HPP
#define RENDEZVOUS_HPP

#include <string>
#include <ctime>

// Déclarations anticipées
class Patient;
class Dentiste;
class SalleDeTraitement;

class RendezVous {
private:
    std::string date; // Utilisation de string pour simplifier
    std::string heure; // Utilisation de string pour simplifier
    std::string statut; // ex: confirmé, annulé, en attente
    Patient* patient;
    Dentiste* dentiste;
    SalleDeTraitement* salle;

public:
    // Constructeurs et destructeur
    RendezVous();
    RendezVous(const std::string& date, const std::string& heure, const std::string& statut);
    ~RendezVous();

    // Getters et setters
    std::string getDate() const;
    void setDate(const std::string& date);
    std::string getHeure() const;
    void setHeure(const std::string& heure);
    std::string getStatut() const;
    void setStatut(const std::string& statut);
    Patient* getPatient() const;
    void setPatient(Patient* patient);
    Dentiste* getDentiste() const;
    void setDentiste(Dentiste* dentiste);
    SalleDeTraitement* getSalle() const;
    void setSalle(SalleDeTraitement* salle);

    // Méthodes spécifiques
    void ajouterRappel();
    void confirmer();
};

#endif // RENDEZVOUS_H