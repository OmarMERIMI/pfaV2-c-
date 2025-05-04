#ifndef DOSSIERPATIENT_HPP
#define DOSSIERPATIENT_HPP

#include <string>
#include <vector>

// Déclaration anticipée
class Patient;

class DossierPatient {
private:
    int idPatient;
    std::string dossierMedical;
    std::string notes;
    Patient* patient; // Référence au patient associé

public:
    // Constructeurs et destructeur
    DossierPatient();
    DossierPatient(int idPatient, const std::string& dossierMedical, const std::string& notes);
    ~DossierPatient();

    // Getters et setters
    int getIdPatient() const;
    void setIdPatient(int idPatient);
    std::string getDossierMedical() const;
    void setDossierMedical(const std::string& dossierMedical);
    std::string getNotes() const;
    void setNotes(const std::string& notes);
    Patient* getPatient() const;
    void setPatient(Patient* patient);

    // Méthodes spécifiques
    void ajouterNotes(const std::string& nouvelleNote);
    void consulterDossier();
};

#endif // DOSSIERPATIENT_H