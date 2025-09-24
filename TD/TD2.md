# TD2

## 0. Contexte

### 0.1 Objectifs

L'objectif de cet exercice est d'écrire un algorithme de "menu" en console avec vérification de saisie.
Le support sera un jeu de "questions".
Le joueur a 10 tours de jeu. A chaque tour, une question est posée, et 4 réponses possibles sont données.
Si la réponse est valide, le joueur remporte le tour, et la cagnotte est augmentée.
Si la réponse n'est pas valide, le joueur perd l'ensemble de la cagnotte.
A chaque tour, le joueur peut décider de tenter la question ou d'abandonner et ainsi encaisser la cagnotte.

### 0.2 Consignes

Sont demandés, pour le programme principal et chaque fonction :
- l'algorithme, en langage "naturel"
- un algorigramme

### 0.3 Fonctions prédéfinies

Les fonctions suivantes sont fournies :
- `VERIF` qui prend deux paramètres : une valeur et un type sous la forme d'un entier
  - 0 : chaîne
  - 1 : entier
  - 2 : flottant
- `LSQUESTIONS` qui donne la liste des questions disponibles, sous forme de clefs
- `UNEQUESTION` qui, à partir d'une clef de question, renvoie une liste sous la forme : `[Contenu, Réponse A, Réponse B, Réponse C, Réponse D, Réponse valide]`
- `MAJ` qui transforme une chaîne en majuscules
- `MIN` qui transforme une chaîne en minuscules
- `MST` qui renvoie le timestamp UNIX actuel
- `LIRENB` qui effectue une lecture **non-bloquante** d'une saisie utilisateur. Cette fonction prend un paramètre : le nom d'une fonction à exécuter une fois qu'une saisie utilisateur est détectée et validée

## 1.0 Fonctions de base

### 1.1 EGAL

Créez la fonction `EGAL` qui prend deux paramètres :
- `gauche`, une chaîne
- `droite`, une chaîne

Cette fonction vérifie si les deux chaînes sont égales en ignorant la casse.

---

> ### 📝 **RÉPONSE**
> 
> ### Algorigramme `EGAL` :
> 
> ```mermaid
> flowchart TD
>     A([EGAL]) --> B["gaucheMin = MIN(gauche)"]
>     B --> C["droiteMin = MIN(droite)"]
>     C --> D{"gaucheMin = droiteMin"}
>     D -->|OUI| E[RETOUR VRAI]
>     D -->|NON| F[RETOUR FAUX]
>     E --> G([FIN])
>     F --> G
> ```
> 
> ### Algorithme `EGAL` :
> 
> ```
> DEBUT EGAL
>   PARAM CHAINE gauche
>   PARAM CHAINE droite
>   VARIABLE CHAINE gaucheMin
>   VARIABLE CHAINE droiteMin
>   
>   gaucheMin ← MIN(gauche)
>   droiteMin ← MIN(droite)
>   
>   SI gaucheMin = droiteMin ALORS
>     RETOUR VRAI
>   SINON
>     RETOUR FAUX
>   FIN SI
> FIN
> ```

---

### 1.2 DANSLISTE

Créez la fonction `DANSLISTE` qui prend trois paramètres (dont un facultatif) :
- `val`, la valeur à vérifier
- `liste`, la liste
- `ignorerCasse`, un booléen pour ignorer la casse (`VRAI`) ou non (`FAUX`) - par défaut `FAUX`

Cette fonction vérifie si la valeur `val` est dans la liste `liste` et renvoie un booléen.

---

> ### 📝 **RÉPONSE**
> 
> ### Algorigramme `DANSLISTE` :
> 
> ```mermaid
> flowchart TD
>     A([DANSLISTE]) --> B["i = 0"]
>     B --> C["n = TAILLE(liste)"]
>     C --> D{"i < n"}
>     D -->|NON| E[RETOUR FAUX]
>     D -->|OUI| F{"ignorerCasse = VRAI"}
>     F -->|OUI| G{"EGAL(val, liste[i]) = VRAI"}
>     F -->|NON| H{"val = liste[i]"}
>     G -->|OUI| I[RETOUR VRAI]
>     G -->|NON| J["i = i + 1"]
>     H -->|OUI| I
>     H -->|NON| J
>     J --> D
>     I --> K([FIN])
>     E --> K
> ```
> 
> ### Algorithme `DANSLISTE` :
> 
> ```
> DEBUT DANSLISTE
>   PARAM val
>   PARAM LISTE liste
>   PARAM BOOLEEN ignorerCasse DEFAUT FAUX
>   VARIABLE ENTIER i
>   VARIABLE ENTIER n
>   
>   i ← 0
>   n ← TAILLE(liste)
>   
>   TANT QUE i < n FAIRE
>     SI ignorerCasse = VRAI ALORS
>       SI EGAL(val, liste[i]) = VRAI ALORS
>         RETOUR VRAI
>       FIN SI
>     SINON
>       SI val = liste[i] ALORS
>         RETOUR VRAI
>       FIN SI
>     FIN SI
>     i ← i + 1
>   FIN TANT QUE
>   
>   RETOUR FAUX
> FIN
> ```

---

### 1.3 POGNON

Créez la fonction `POGNON` qui prend un paramètre entier `tour` et renvoie l'argent espéré pour le tour,
selon la formule mathématique :
```math
a(n) = a(n−1) ⋅ 2.16
```

Avec n étant le numéro du tour, sachant que $$a(1)=1000$$.

---

> ### 📝 **RÉPONSE**
> 
> ### Algorigramme `POGNON` :
> 
> ```mermaid
> flowchart TD
>     A([POGNON]) --> B{"tour = 1"}
>     B -->|OUI| C[RETOUR 1000]
>     B -->|NON| D["resultat = 1000"]
>     D --> E["i = 2"]
>     E --> F{"i <= tour"}
>     F -->|NON| G[RETOUR resultat]
>     F -->|OUI| H["resultat = resultat × 2.16"]
>     H --> I["i = i + 1"]
>     I --> F
>     C --> J([FIN])
>     G --> J
> ```
> 
> ### Algorithme `POGNON` :
> 
> ```
> DEBUT POGNON
>   PARAM ENTIER tour
>   VARIABLE REEL resultat
>   VARIABLE ENTIER i
>   
>   SI tour = 1 ALORS
>     RETOUR 1000
>   SINON
>     resultat ← 1000
>     POUR i DE 2 A tour FAIRE
>       resultat ← resultat × 2.16
>     FIN POUR
>     RETOUR resultat
>   FIN SI
> FIN
> ```

---

## 2.0 Jeu de base

### 2.1 Menu

Créez le menu initial, afin de demander à l'utilisateur s'il souhaite :
- `[J]ouer`
- `[Q]uitter`

Si l'utilisateur choisit "Q" (peu importe la casse), le programme s'arrête.
Si l'utilisateur choisit "J", le jeu se lance au premier tour.
Si la saisie ne correspond à rien, demandez à nouveau à l'utilisateur.

---

> ### 📝 **RÉPONSE**
> 
> ### Algorigramme `MENU` :
> 
> ```mermaid
> flowchart TD
>     A([MENU]) --> B[/"Afficher: Que voulez-vous faire ?"/]
>     B --> C[/"Afficher: [J]ouer"/]
>     C --> D[/"Afficher: [Q]uitter"/]
>     D --> E[/Saisie choix/]
>     E --> F["choixMaj = MAJ(choix)"]
>     F --> G{"choixMaj = 'J'"}
>     G -->|OUI| H[RETOUR VRAI]
>     G -->|NON| I{"choixMaj = 'Q'"}
>     I -->|OUI| J[RETOUR FAUX]
>     I -->|NON| K[/"Afficher: Saisie invalide"/]
>     K --> B
>     H --> L([FIN])
>     J --> L
> ```
> 
> ### Algorithme `MENU` :
> 
> ```
> DEBUT MENU
>   VARIABLE CHAINE choix
>   VARIABLE CHAINE choixMaj
>   VARIABLE BOOLEEN continuer ← VRAI
>   
>   TANT QUE continuer = VRAI FAIRE
>     ECRIRE "Que voulez-vous faire ?"
>     ECRIRE "[J]ouer"
>     ECRIRE "[Q]uitter"
>     LIRE choix
>     
>     choixMaj ← MAJ(choix)
>     
>     SI choixMaj = "J" ALORS
>       RETOUR VRAI
>     SINON SI choixMaj = "Q" ALORS
>       RETOUR FAUX
>     SINON
>       ECRIRE "Saisie invalide, veuillez recommencer."
>     FIN SI
>   FIN TANT QUE
> FIN
> ```

---

### 2.2 TOUR

Créez la fonction `TOUR`, qui prend un paramètre entier, le numéro du tour, ainsi que la liste des questions déjà posées (sous forme de clefs).
Dans cette fonction, obtenez une question qui n'a pas déjà été posée.
Puis, affichez la question, suivie des réponses, et attendez la saisie de l'utilisateur.
Une fois la saisie effectuée, si celle-ci correspond à une des réponses (A, B, C ou D), affichez le résultat.
Si le joueur a perdu, revenez au menu principal.
Si la joueur a gagné, affichez la cagnotte, puis (si le tour est inférieur à 10) demandez si le joueur souhaite `[c]ontinuer` ou `[a]rrêter`.
Si le joueur arrête, il remporte la cagnotte et le programme s'arrête.
Si le joueur continue, passez au tour suivant.
Si le joueur gagne au dernier tour, le programme s'arrête.

---

> ### 📝 **RÉPONSE**
> 
> ### Algorigramme `TOUR` :
> 
> ```mermaid
> flowchart TD
>     A([TOUR]) --> B["toutesQuestions = LSQUESTIONS()"]
>     B --> C["questionChoisie = vide"]
>     C --> D["i = 0"]
>     D --> E{"i < TAILLE(toutesQuestions)"}
>     E -->|NON| F[/"Erreur: Plus de questions"/]
>     E -->|OUI| G{"DANSLISTE(toutesQuestions[i], questionsUtilisees) = FAUX"}
>     G -->|OUI| H["questionChoisie = toutesQuestions[i]"]
>     G -->|NON| I["i = i + 1"]
>     I --> E
>     H --> J["donneesQuestion = UNEQUESTION(questionChoisie)"]
>     J --> K[/"Afficher Tour numeroTour"/]
>     K --> L[/"Afficher donneesQuestion[0]"/]
>     L --> M[/"Afficher A: donneesQuestion[1]"/]
>     M --> N[/"Afficher B: donneesQuestion[2]"/]
>     N --> O[/"Afficher C: donneesQuestion[3]"/]
>     O --> P[/"Afficher D: donneesQuestion[4]"/]
>     P --> Q[/Saisie reponseUtilisateur/]
>     Q --> R["reponseUtilisateurMaj = MAJ(reponseUtilisateur)"]
>     R --> S{"DANSLISTE(reponseUtilisateurMaj, optionsValides)"}
>     S -->|NON| U[/"Afficher: Réponse invalide"/]
>     U --> Q
>     S -->|OUI| V{"reponseUtilisateurMaj = donneesQuestion[5]"}
>     V -->|OUI| W[/"Afficher: Bonne réponse!"/]
>     V -->|NON| X[/"Afficher: Mauvaise réponse!"/]
>     X --> Y[/"Afficher bonne réponse"/]
>     Y --> Z1[RETOUR FAUX]
>     W --> Z2["cagnotte = POGNON(numeroTour)"]
>     Z2 --> Z3[/"Afficher cagnotte"/]
>     Z3 --> Z4{"numeroTour = 10"}
>     Z4 -->|OUI| Z5[/"Afficher: Victoire totale!"/]
>     Z5 --> Z6[RETOUR FAUX]
>     Z4 -->|NON| Z7[/"Demander: Continuer ou Arrêter"/]
>     Z7 --> Z8[/Saisie choixContinuer/]
>     Z8 --> Z9["choixContinuerMaj = MAJ(choixContinuer)"]
>     Z9 --> Z10{"choixContinuerMaj = C"}
>     Z10 -->|OUI| Z11[RETOUR VRAI]
>     Z10 -->|NON| Z12{"choixContinuerMaj = A"}
>     Z12 -->|OUI| Z13[/"Afficher: Félicitations!"/]
>     Z13 --> Z14[RETOUR FAUX]
>     Z12 -->|NON| Z15[/"Afficher: Choix invalide"/]
>     Z15 --> Z7
>     F --> Z16([FIN])
>     Z1 --> Z16
>     Z6 --> Z16
>     Z11 --> Z16
>     Z14 --> Z16
> ```
> 
> ### Algorithme `TOUR` :
> 
> ```
> DEBUT TOUR
>   PARAM ENTIER numeroTour
>   PARAM LISTE questionsUtilisees
>   VARIABLE LISTE toutesQuestions
>   VARIABLE CHAINE questionChoisie
>   VARIABLE ENTIER i
>   VARIABLE LISTE donneesQuestion
>   VARIABLE CHAINE reponseUtilisateur
>   VARIABLE CHAINE reponseUtilisateurMaj
>   VARIABLE LISTE optionsValides
>   VARIABLE REEL cagnotte
>   VARIABLE CHAINE choixContinuer
>   VARIABLE CHAINE choixContinuerMaj
>   VARIABLE BOOLEEN continuer
>   
>   toutesQuestions ← LSQUESTIONS()
>   questionChoisie ← ""
>   optionsValides ← ["A", "B", "C", "D"]
>   
>   POUR i DE 0 A TAILLE(toutesQuestions) - 1 FAIRE
>     SI DANSLISTE(toutesQuestions[i], questionsUtilisees) = FAUX ALORS
>       questionChoisie ← toutesQuestions[i]
>       SORTIR DE BOUCLE
>     FIN SI
>   FIN POUR
>   
>   SI questionChoisie = "" ALORS
>     ECRIRE "Erreur: Aucune question disponible"
>     RETOUR FAUX
>   FIN SI
>   
>   donneesQuestion ← UNEQUESTION(questionChoisie)
>   
>   ECRIRE "=== TOUR ", numeroTour, " ==="
>   ECRIRE donneesQuestion[0]
>   ECRIRE "A: ", donneesQuestion[1]
>   ECRIRE "B: ", donneesQuestion[2]
>   ECRIRE "C: ", donneesQuestion[3]
>   ECRIRE "D: ", donneesQuestion[4]
>   
>   continuer ← VRAI
>   TANT QUE continuer = VRAI FAIRE
>     ECRIRE "Votre réponse (A, B, C ou D): "
>     LIRE reponseUtilisateur
>     reponseUtilisateurMaj ← MAJ(reponseUtilisateur)
>     
>     SI DANSLISTE(reponseUtilisateurMaj, optionsValides) = VRAI ALORS
>       continuer ← FAUX
>     SINON
>       ECRIRE "Réponse invalide! Veuillez saisir A, B, C ou D."
>     FIN SI
>   FIN TANT QUE
>   
>   SI reponseUtilisateurMaj = donneesQuestion[5] ALORS
>     ECRIRE "Bonne réponse!"
>     cagnotte ← POGNON(numeroTour)
>     ECRIRE "Cagnotte actuelle: ", cagnotte, " €"
>     
>     SI numeroTour = 10 ALORS
>       ECRIRE "FÉLICITATIONS! Vous avez terminé le jeu!"
>       ECRIRE "Vous repartez avec ", cagnotte, " € !"
>       RETOUR FAUX
>     SINON
>       continuer ← VRAI
>       TANT QUE continuer = VRAI FAIRE
>         ECRIRE "Voulez-vous [C]ontinuer ou [A]rrêter?"
>         LIRE choixContinuer
>         choixContinuerMaj ← MAJ(choixContinuer)
>         
>         SI choixContinuerMaj = "C" ALORS
>           RETOUR VRAI
>         SINON SI choixContinuerMaj = "A" ALORS
>           ECRIRE "Félicitations! Vous repartez avec ", cagnotte, " € !"
>           RETOUR FAUX
>         SINON
>           ECRIRE "Choix invalide! Veuillez saisir C ou A."
>         FIN SI
>       FIN TANT QUE
>     FIN SI
>   SINON
>     ECRIRE "Mauvaise réponse!"
>     ECRIRE "La bonne réponse était: ", donneesQuestion[5]
>     ECRIRE "Vous perdez tout! Retour au menu principal."
>     RETOUR FAUX
>   FIN SI
> FIN
> ```

---

## 3.0 Extension

### 3.1 Timer

Implémentez le timer.
Pour cela, utilisez la fonction `LIRENB` pour effectuer une lecture non-bloquante, encapsulée dans une boucle `TANTQUE` vérifiant un écart de temps.
Si cet écart de temps est supérieur à 30, et qu'aucune saisie n'a été réalisée, la réponse est considérée comme fausse.

---

> ### 📝 **RÉPONSE**
> 
> ### Algorigramme `SAISIE_TIMER` :
> 
> ```mermaid
> flowchart TD
>     A([SAISIE_TIMER]) --> B["tempsDebut = MST()"]
>     B --> C["saisieEffectuee = FAUX"]
>     C --> D["reponse = vide"]
>     D --> E["tempsActuel = MST()"]
>     E --> F["ecart = tempsActuel - tempsDebut"]
>     F --> G{"ecart > 30"}
>     G -->|OUI| H[RETOUR FAUX]
>     G -->|NON| I["resultat = LIRENB(CALLBACK_SAISIE)"]
>     I --> J{"resultat != vide"}
>     J -->|OUI| K["reponse = resultat"]
>     K --> L["saisieEffectuee = VRAI"]
>     L --> M[RETOUR reponse]
>     J -->|NON| N{"saisieEffectuee = FAUX"}
>     N -->|OUI| E
>     N -->|NON| E
>     H --> O([FIN])
>     M --> O
> ```
> 
> ### Algorithme `SAISIE_TIMER` :
> 
> ```
> DEBUT SAISIE_TIMER
>   VARIABLE ENTIER tempsDebut
>   VARIABLE ENTIER tempsActuel
>   VARIABLE ENTIER ecart
>   VARIABLE BOOLEEN saisieEffectuee
>   VARIABLE CHAINE reponse
>   VARIABLE CHAINE resultat
>   
>   tempsDebut ← MST()
>   saisieEffectuee ← FAUX
>   reponse ← ""
>   
>   TANT QUE saisieEffectuee = FAUX FAIRE
>     tempsActuel ← MST()
>     ecart ← tempsActuel - tempsDebut
>     
>     SI ecart > 30 ALORS
>       RETOUR FAUX
>     FIN SI
>     
>     resultat ← LIRENB(CALLBACK_SAISIE)
>     SI resultat != "" ALORS
>       reponse ← resultat
>       saisieEffectuee ← VRAI
>     FIN SI
>   FIN TANT QUE
>   
>   RETOUR reponse
> FIN
> ```
> 
> ### Algorithme `CALLBACK_SAISIE` :
> 
> ```
> DEBUT CALLBACK_SAISIE
>   VARIABLE CHAINE saisie
>   LIRE saisie
>   RETOUR saisie
> FIN
> ```



## Annexes

### Format de fichier

> [!Note]
> Cet encart est donné à titre informatif

Chaque question est dans un format dédié, dans un fichier `.qpdp`.
Le nom du fichier est utilisé en tant que clef (le fichier `abc.qpdp` a donc pour clef `abc`).
```
===
Contenu de la question
=A=
Réponse A
=B=
Réponse B
=C=
Réponse C
=D=
Réponse D
=X=
```

X est remplacé par A, B, C ou D selon la bonne réponse.