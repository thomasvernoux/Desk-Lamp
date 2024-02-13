
/*
 * Created on: 2 juin 2021
 * Author: thomas
 * This file contain global vaiables from the project and th variable initialisation function.
 */


#include "variables.h"
#include "stm32746g_discovery_lcd.h"
#include "main.h"

// Screen global variables
int TEX; // taille de l'ecran (en x et y)
int TEY;

int marge_haut = 20;      // Top space
int marge_droite = 200;   // right space
int marge_gauche = 20;    // left space

// Colored stripes positions
int pXbR; // position X bande rouge
int pYbR; // position Y bande rouge

int pXbV; // position X green strip
int pYbV; // position Y green strip

int pXbB; // Position X blue strip
int pYbB; // Position Y blue strip

int pXbW; // position X white strip
int pYbW; // Position Y white strip

int largeur_bande;  // Band width
int hauteur_bande = 40; // Band hight


// variables linked to the change mode button
int BCM_pX = 250; // position X
int BCM_pY = 0; // position Y
int BCM_largeur = 165; // largeur
int BCM_hauteur = 55; // hauteur

// Others buttons variables
int largeur_boutton_FMO = 100; // full mid off
int hauteur_boutton_FMO = 50; // full mid off


// touchscreen variables
int x,y; // Position of last touch on the screen - variables contenant la position du dernier touch sur l'ecran tactile

int etatlumiere_R = 100/2;  // red light state
int etatlumiere_G = 100/2;  // green light state
int etatlumiere_B = 100/2;  // blue light state
int etatlumiere_W = 100/2;  // white light state




/*
 * @brief This function setup variables at startup
 * @retval nothing
 */
void set_variables(){

	// TE : taille ecran X / Y - Screen size X / Y
	TEX = BSP_LCD_GetXSize();  // return the size of LCD Size (Width)
	TEY = BSP_LCD_GetYSize();  // return the size of LCD Size (Height)

	largeur_bande = TEX - marge_droite - marge_gauche;  // strip width (1 strip)
	
	pXbR = 20;                                             // position X - red stripe
	pYbR = TEY/5 * 1 - hauteur_bande/2 + marge_haut;       // position Y - red stripe

	pXbV = 20;                                             // position X - green stripe
	pYbV = TEY/5 * 2 - hauteur_bande/2 + marge_haut;       // position Y - green stripe

	pXbB = 20;                                             // position X - blue stripe
	pYbB = TEY/5 * 3 - hauteur_bande/2 + marge_haut;       // position X - blue stripe

	pXbW = 20;                                             // position X - white stripe
	pYbW = TEY/5 * 4 - hauteur_bande/2 + marge_haut;       // position Y - white stripe


}










