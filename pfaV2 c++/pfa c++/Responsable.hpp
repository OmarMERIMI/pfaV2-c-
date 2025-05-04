#ifndef RESPONSABLE_H
#define RESPONSABLE_H

#include "Utilisateur.hpp"
#include <string>
#include <vector>

// Inclure les définitions nécessaires :
#include "Patient.hpp"
#include "Dentiste.hpp"
#include "Assistant.hpp"

// Déclaration anticipée
class Rapport;

class Responsable : public Utilisateur {
private:
    std::string nom;
    std::string prenom;

public:
    // Constructeurs et destructeur
    Responsable();
    Responsable(int id, const std::string& username, const std::string& password,
                const std::string& nom, const std::string& prenom);
    virtual ~Responsable();

    // Getters et setters
    std::string getNom() const;
    void setNom(const std::string& nom);
    std::string getPrenom() const;
    void setPrenom(const std::string& prenom);

    // Méthodes spécifiques
    void gererUtilisateurs();
    void genererRapports();
};

#endif // RESPONSABLE_H


// #ifndef RESPONSABLE_HPP
// #define RESPONSABLE_HPP

// #include "Utilisateur.hpp"
// #include <string>
// #include <vector>
// extern std::vector<Dentiste> dentistes;
// // Déclaration anticipée
// class Rapport;

// class Responsable : public Utilisateur {
// private:
//     std::string nom;
//     std::string prenom;

// public:
//     // Constructeurs et destructeur
//     Responsable();
//     Responsable(int id, const std::string& username, const std::string& password,
//                 const std::string& nom, const std::string& prenom);
//     virtual ~Responsable();

//     // Getters et setters
//     std::string getNom() const;
//     void setNom(const std::string& nom);
//     std::string getPrenom() const;
//     void setPrenom(const std::string& prenom);

//     // Méthodes spécifiques
//     void gererUtilisateurs();
//     void genererRapports();
// };
// // Responsable.hpp
// extern std::vector<Dentiste> dentistes;
// extern std::vector<Assistant> assistants;
// extern std::vector<Responsable> responsables;
// extern std::vector<Patient> patients; // Si nécessaire

// #endif // RESPONSABLE_H