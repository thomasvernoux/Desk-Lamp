#include "variables.h"
#include "stm32746g_discovery_lcd.h"
#include "main.h"

// variables globales ecran
int TEX; // taille de l'ecran (en x et y)
int TEY;




// variables ecran 3 bandes

int marge_haut = 20;
int marge_droite = 200;
int marge_gauche = 20;


int pXbR; // position X bande rouge
int pYbR; // position Y bande rouge

int pXbV;
int pYbV;

int pXbB;
int pYbB;

int pXbW; // bande blanche
int pYbW;

int largeur_bande;
int hauteur_bande = 40; // hauteur de la bande


// variables boutton changer de mode

int BCM_pX = 250; // position X
int BCM_pY = 0; // position Y
int BCM_largeur = 165; // largeur
int BCM_hauteur = 55; // hauteur

// variables autres bouttons
int largeur_boutton_FMO = 100; // full mid off
int hauteur_boutton_FMO = 50; // full mid off


// variables ecran tactile
int x,y; // variables contenant la position du dernier touch sur l'ecran tactile

int etatlumiere_R = 100/2;
int etatlumiere_G = 100/2;
int etatlumiere_B = 100/2;
int etatlumiere_W = 100/2;




/*
 * @brief Cette fonction met a jour les variables au demarrage
 * @retval rien
 */
void set_variables(){

	TEX = BSP_LCD_GetXSize();
	TEY = BSP_LCD_GetYSize();

	largeur_bande = TEX - marge_droite - marge_gauche;
	
	pXbR = 20; // position X bande rouge
	pYbR = TEY/5 * 1 - hauteur_bande/2 + marge_haut; // position Y bande rouge

	pXbV = 20;
	pYbV = TEY/5 * 2 - hauteur_bande/2 + marge_haut;

	pXbB = 20;
	pYbB = TEY/5 * 3 - hauteur_bande/2 + marge_haut;

	pXbW = 20;
	pYbW = TEY/5 * 4 - hauteur_bande/2 + marge_haut;


}










