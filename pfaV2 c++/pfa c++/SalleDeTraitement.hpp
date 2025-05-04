#ifndef SALLEDETRAITEMENT_HPP
#define SALLEDETRAITEMENT_HPP

#include <string>
#include <vector>

// Déclarations anticipées
class Assistant;
class RendezVous;

class SalleDeTraitement {
private:
    int id;
    std::string nom;
    std::string equipements;
    std::string statut; // ex: disponible, occupée, en maintenance
    Assistant* assistant;
    std::vector<RendezVous*> rendezVous;

public:
    // Constructeurs et destructeur
    SalleDeTraitement();
    SalleDeTraitement(int id, const std::string& nom, const std::string& equipements, const std::string& statut);
    ~SalleDeTraitement();

    // Getters et setters
    int getId() const;
    void setId(int id);
    std::string getNom() const;
    void setNom(const std::string& nom);
    std::string getEquipements() const;
    void setEquipements(const std::string& equipements);
    std::string getStatut() const;
    void setStatut(const std::string& statut);
    Assistant* getAssistant() const;
    void setAssistant(Assistant* assistant);

    // Méthodes spécifiques
    void preparer();
    void verifierEquipement();
    void ajouterRendezVous(RendezVous* rdv);
    void retirerRendezVous(RendezVous* rdv);
};

#endif // SALLEDETRAITEMENT_H