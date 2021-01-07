#include "tableau.h"

//Initialise les variables
TEXTE Initialiser_Texte(void){
	TEXTE t;
	t.T = NULL;
	t.L = NULL;
	/*t.A = NULL;*/
	t.nbCaracteres = 0;
	t.nbMots = 0;
	t.nbLignes = 0;
	
	return t;
}
//Calcule le nombre de caractères et de lignes 
//d'un texte donner en argument
TEXTE Nombre_Lignes_Caracteres(char *nomFic, TEXTE t){
	FILE *F;
	char c;
	t.nbLignes = 0;
	t.nbCaracteres = 0;
	F = fopen(nomFic,"r");//ouvre fichier en mode 'read'
	
	//Erreur ouverture fichier
	if(F == NULL){
		exit(12);
		printf("Erreur: ouverture du fichier impossible \n");
	}
	
	//Cas général
	if(F){
		while((c = fgetc(F)) != EOF){
			t.nbCaracteres++;
			if(c == '\n'){
				t.nbLignes++;
			}
	fclose (F);
	t.nbCaracteres = t.nbCaracteres;
	t.nbLignes = t.nbLignes;
	
	return t;
		}
	}
}

//Fonction qui crée les tableaux nécessaire au projet
TEXTE Creer_Tableaux(char *nomFic){
	TEXTE t;
	t = Initialiser_Texte();
	t = Nombre_Lignes_Caracteres(nomFic, t);
	
	t.T = malloc(t.nbCaracteres*sizeof(char));
	if(!t.T){exit(42);
			 printf("Erreur 42\n");
			}
	
	t.L = malloc((t.nbLignes+1)*sizeof(int));
	if(!t.L){exit(42);
			 printf("Erreur 42\n");
			}
		
	t.L[0] = 0;
	
	return t;
}

//Fonction qui rempli les tableaux créer précedement
TEXTE Remplir_Tableaux(char *nomFic){
	
	char c;
	int ind_char;
	ind_char = 0;
	int ind_ligne;
	ind_ligne = 0;

	TEXTE t;
	t = Creer_Tableaux(nomFic);
	
	FILE *F;
	F = fopen(nomFic,"r");//ouvre fichier en mode 'read'
	
	//Erreur ouverture fichier
	if(F == NULL){
		exit(12);
		printf("Erreur: ouverture du fichier impossible \n");
	}
	
	//Cas général	
	while((c = fgetc(F)) != EOF){
		if(c == '\n'){
			 t.L[ind_ligne] = ind_char+1;
			 ind_ligne++;
		}
		
		t.T[ind_char] = c;
		ind_char++;
	}
	fclose(F);
	return t;
}
