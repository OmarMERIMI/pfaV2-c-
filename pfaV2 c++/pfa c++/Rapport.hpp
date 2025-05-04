#ifndef RAPPORT_HPP
#define RAPPORT_HPP

#include <string>

// Déclaration anticipée
class Responsable;

class Rapport {
private:
    int id;
    std::string type; // ex: financier, activité, statistique
    std::string date; // Utilisation de string pour simplifier
    std::string contenu;
    Responsable* responsable;

public:
    // Constructeurs et destructeur
    Rapport();
    Rapport(int id, const std::string& type, const std::string& date, const std::string& contenu);
    ~Rapport();

    // Getters et setters
    int getId() const;
    void setId(int id);
    std::string getType() const;
    void setType(const std::string& type);
    std::string getDate() const;
    void setDate(const std::string& date);
    std::string getContenu() const;
    void setContenu(const std::string& contenu);
    Responsable* getResponsable() const;
    void setResponsable(Responsable* responsable);

    // Méthodes spécifiques
    void genererRapport();
};

#endif // RAPPORT_H