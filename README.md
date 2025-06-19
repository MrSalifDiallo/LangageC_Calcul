# 🧮 LangageC_Calcul

Un projet en **C** pour réaliser des opérations de calcul sur des valeurs (nombres entiers ou flottants). Le code est structuré pour la compilation et l'exécution simple en ligne de commande sous Windows.

---

## 📁 Structure du dépôt
```
LangageC_Calcul/
│
├── src/
│ ├── calcul.c # Fonctions de calcul (addition, soustraction, ...)
│ └── main.c # Point d’entrée : interface utilisateur, lecture des arguments, appels à calcul.c
│
├── include/
│ └── calcul.h # Déclarations publiques des fonctions de calcul
│
├── build/ # (Optionnel) dossier de génération (ex : fichiers .o, exécutable)
│
├── .gitignore # Fichiers et dossiers à ignorer par Git
└── README.md # Ce fichier explique la solution
```

---

## 💡 Fonctionnalités principales

- Calculs de base : addition, soustraction, multiplication, division
- Support des entiers et nombres à virgule flottante
- Interface via arguments CLI (ex. `calc.exe add 5 3.2`)
- Possibilité d’étendre le code pour de nouvelles opérations

---

## ⚙️ Compilation et exécution

1. **Cloner** le dépôt  
   ```bash
   git clone https://github.com/MrSalifDiallo/LangageC_Calcul.git
   cd LangageC_Calcul
   ```
2. **Compiler sous Windows (avec GCC ou MinGW)**
   ```bash
    gcc -Iinclude -o calc.exe src/main.c src/calcul.c
   ```
3. **Exécuter l’application**
      ```bash
    calc.exe <operation> <nombre1> <nombre2>
      ```
4. **Exemples** :
   ```bash
    calc.exe add 4 5
    calc.exe mul 3.5 2
   ```
   
---

## 💡 Contribution

1. Fork le projet 
2. Créer une branche pour votre fonctionnalité (`git checkout -b feature/AmazingFeature`)
3. Commit vos changements (`git commit -m 'Add some AmazingFeature'`)
4. Push vers la branche (`git push origin feature/AmazingFeature`)
5. Ouvrir une Pull Request

---

## 👤 Auteur

**Salif Diallo**  
💼 Développeur && passionné par les solutions de gestion  
📧 [salifdiallo@esp.sn](mailto:salifdiallo@esp.sn)  
🔗 [GitHub - MrSalifDiallo](https://github.com/MrSalifDiallo)  
🌍 Basé à Dakar, Sénégal

