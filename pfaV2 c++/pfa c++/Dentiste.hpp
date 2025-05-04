#ifndef DENTISTE_HPP
#define DENTISTE_HPP

#include "Utilisateur.hpp"
#include <string>

// Déclarations anticipées
class DossierPatient;

class Dentiste : public Utilisateur {
private:
    std::string nom;
    std::string specialite;

public:
    // Constructeurs et destructeur
    Dentiste();
    Dentiste(int id, const std::string& username, const std::string& password,
             const std::string& nom, const std::string& specialite);
    virtual ~Dentiste();

    // Getters et setters
    std::string getNom() const;
    void setNom(const std::string& nom);
    std::string getSpecialite() const;
    void setSpecialite(const std::string& specialite);

    // Méthodes spécifiques
    void consulterDossierPatient();
    void ajouterNotes(const std::string& notes);
    void gererTraitement();
};

#endif // DENTISTE_H