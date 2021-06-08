/*
 * fonctions_gestion_ecran.c
 *
 *  Created on: 2 juin 2021
 *      Author: thoma
 */

#include "fonctions_gestion_ecran.h"
#include "main.h".0

#include "stm32746g_discovery_ts.h"
#include "variables.h"
#include <stdio.h>
#include <stdlib.h>
#include "Lumiere.h"




/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define  CIRCLE_RADIUS        30
/* Private macro -------------------------------------------------------------*/
#define  CIRCLE_XPOS(i)       ((i * BSP_LCD_GetXSize()) / 5)
#define  CIRCLE_YPOS(i)       (BSP_LCD_GetYSize() - CIRCLE_RADIUS - 60)
/* Private variables ---------------------------------------------------------*/
static TS_StateTypeDef  TS_State;



extern int marge_haut;
extern int marge_droite;
extern int marge_gauche;

extern int TEX;
extern int TEY;



extern int taille_ecran_X;
extern int taille_ecran_Y;
extern int x, y;


// ecran 3 bandes

extern int pXbR; // position X bande rouge
extern int pYbR; // position Y bande rouge

extern int pXbV;
extern int pYbV;

extern int pXbB;
extern int pYbB;

extern int pXbW;
extern int pYbW;

extern int hauteur_bande; // hauteur de la bande
extern int largeur_bande;

int curseur_jauge_rouge;
int surseur_jauge_verte;
int curseur_jauge_bleue;

extern int etatlumiere_R;
extern int etatlumiere_G;
extern int etatlumiere_B;
extern int etatlumiere_W;

// noutton changer de mode :
extern int BCM_pX; // position X
extern int BCM_pY; // position Y
extern int BCM_largeur; // largeur
extern int BCM_hauteur; // hauteur


/* Création des differents objets --------------------------------------------*/
// Ecran 3 bandes
FormeTypeDef jauge_rouge;
FormeTypeDef jauge_verte;
FormeTypeDef jauge_bleu;
FormeTypeDef jauge_blanche;
// bouttons
FormeTypeDef boutton_changer_de_mode;
FormeTypeDef boutton_OFF;
FormeTypeDef boutton_FULL;
FormeTypeDef boutton_MID;

/* Variables de la machine d'etat ---------------------------------------------*/
extern STATE_MachineTypeDef Etat_machine;


// variables bouttons
extern int largeur_boutton_FMO; // full mid off
extern int hauteur_boutton_FMO; // full mid off


void Remplissage_jauge_Callback(FormeTypeDef forme, int Intensite){
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_FillRect(forme.bordG+1,forme.bordH+1,(forme.bordD-forme.bordG)-1, (forme.bordB-forme.bordH)-1);
	if (forme.Id == 'R')
		BSP_LCD_SetTextColor(LCD_COLOR_RED);
	else if (forme.Id == 'V')
		BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
	else if (forme.Id == 'B')
		BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	else if (forme.Id == 'W')
			BSP_LCD_SetTextColor(LCD_COLOR_BLACK);

	BSP_LCD_FillRect(forme.bordG+1,forme.bordH+1,((forme.bordD-forme.bordG)-1)*Intensite/100, (forme.bordB-forme.bordH)-1);
}

/*
 * @brief Cette fonction permet d'afficher l'ecran de controlle manuel
 * avec les 3 bandes des couleur RGB.
 * @retval rien
 */

void afficher_bandes_couleurs(){

	// Bande Rouge
	BSP_LCD_SetTextColor(LCD_COLOR_RED);
	BSP_LCD_DrawRect(pXbR, pYbR,largeur_bande, hauteur_bande);
	jauge_rouge.bordH = pYbR;
	jauge_rouge.bordB = pYbR + hauteur_bande;
	jauge_rouge.bordG = pXbR;
	jauge_rouge.bordD = pXbR + largeur_bande;
	jauge_rouge.Id = 'R';

	// Bande Verte
	BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
	BSP_LCD_DrawRect(pXbV, pYbV,largeur_bande, hauteur_bande);
	jauge_verte.bordH = pYbV;
	jauge_verte.bordB = pYbV + hauteur_bande;
	jauge_verte.bordG = pXbV;
	jauge_verte.bordD = pXbV + largeur_bande;
	jauge_verte.Id = 'V';

	// Bande Bleue
	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	BSP_LCD_DrawRect(pXbB, pYbB,largeur_bande, hauteur_bande);
	jauge_bleu.bordH = pYbB;
	jauge_bleu.bordB = pYbB + hauteur_bande;
	jauge_bleu.bordG = pXbB;
	jauge_bleu.bordD = pXbB + largeur_bande;
	jauge_bleu.Id = 'B';

	// Bande blanche
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_DrawRect(pXbW, pYbW,largeur_bande, hauteur_bande);
	jauge_blanche.bordH = pYbW;
	jauge_blanche.bordB = pYbW + hauteur_bande;
	jauge_blanche.bordG = pXbW;
	jauge_blanche.bordD = pXbW + largeur_bande;
	jauge_blanche.Id = 'W';


	afficher_pourcent_remplissage();// afficher les chiffres qui indiquent le remplissage des jauges



}

/*
 * @brief c'est le callback pour les jauges uniquement
 */
void TouchScreenCallBack(){

	uint8_t  status = 0;
	status = BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());

	if (status == TS_OK)
	    {
	      BSP_TS_GetState(&TS_State);
	      if(TS_State.touchDetected){
	        x = TS_State.touchX[0];
	        y = TS_State.touchY[0];

	        // On s'occupe des jauges :
	        switch (Etat_machine){
				case Mode_Manuel:
					TouchIn(jauge_rouge);
					TouchIn(jauge_verte);
					TouchIn(jauge_bleu);
					TouchIn(jauge_blanche);
					break;

				case Mode_Automatique :

					if (TouchIn(jauge_rouge) || TouchIn(jauge_verte) || TouchIn(jauge_bleu)){
						Etat_machine = Mode_Manuel;
						Lancer_Mode_Manuel();
						break;

					} // end if

			} // end switch etat machine
	        // On s'occupe des bouttons

	        if (TouchIn(boutton_changer_de_mode)){ //on cherche a detecter si on change de mode
	        	Changer_de_Mode();
	        }


	        if (TouchIn(boutton_FULL)){
	        	Etat_machine = Mode_Manuel;
	        	Lancer_Mode_Manuel();
	        	etatlumiere_R = 100;
	        	etatlumiere_G = 100;
	        	etatlumiere_B = 100;
	        	etatlumiere_W = 100;
	        	remplir_toutes_les_jauges();
	        	afficher_pourcent_remplissage();
	        } // end if FULL

	        if (TouchIn(boutton_MID)){
	        	Etat_machine = Mode_Manuel;
	        	etatlumiere_R = 50;
	        	etatlumiere_G = 50;
	        	etatlumiere_B = 50;
	        	etatlumiere_W = 50;
	        	Lancer_Mode_Manuel();
	        	afficher_pourcent_remplissage();
	        } // end if MID

 	        if (TouchIn(boutton_OFF)){
	        	Etat_machine = Mode_Manuel;
	        	etatlumiere_R = 0;
	        	etatlumiere_G = 0;
	        	etatlumiere_B = 0;
	        	etatlumiere_W = 0;
	        	Lancer_Mode_Manuel();
	        	afficher_pourcent_remplissage();
	        	} // end if OFF


	      } // end if
	    } // end if

} // end void


/*
 * @brief Cette fonction permet de savoir si on a appuyé dans une zone de controlle (carrés de couleurs)
 * elle retourne un entier pour savoir a quee absysse on a touché.
 * @retval int
 */
int TouchIn(FormeTypeDef forme){

	int ret = 0;

	if (x < forme.bordD && x > forme.bordG && y > forme.bordH && y < forme.bordB){
		ret = 1;
		if (forme.Id == 'R' || forme.Id == 'V' || forme.Id == 'B' || forme.Id == 'W'){
			// alors on manipule une jauge

			BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
			BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
			BSP_LCD_FillRect(forme.bordD + 10,forme.bordB - 30,52,24);
			BSP_LCD_SetFont(&Font24);

			char buffer[10];
			x = (x-18) *100 / (largeur_bande);
			Remplissage_jauge_Callback(forme, x);
			itoa(x,buffer,10);
			BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
			BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
			BSP_LCD_DisplayStringAt(forme.bordD + 10,forme.bordB - 30, (uint8_t *) buffer , LEFT_MODE);

			switch(forme.Id){
					case 'R':
						etatlumiere_R = x;
						break;
					case 'V':
						etatlumiere_G = x;
						break;
					case 'B':
						etatlumiere_B = x;
						break;
					case 'W':
						etatlumiere_W = x;
						break;
			} // end switch

		} // end if


	}// end if

	return ret;

}

/*
 * @brief Fonction qui permet d'afficher unr avriable a l'ecran pour le debug
 */

void AED(char label[10], int var, int place){
	int absysse = 20;
	for (int i = 0; i< place; i++){
		absysse += 20;
	}

	BSP_LCD_SetTextColor(LCD_COLOR_YELLOW);
	BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
	BSP_LCD_SetFont(&Font16);
	char buffer[10];
	itoa(var,buffer,10);
	strcat(buffer,"/");
	BSP_LCD_DisplayStringAt(20,absysse, (uint8_t *) label , LEFT_MODE);
	BSP_LCD_DisplayStringAt(100,absysse, (uint8_t *) buffer , LEFT_MODE);


	return;




}

void affichage_boot(){
	BSP_LCD_Clear(LCD_COLOR_WHITE);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font24);

	BSP_LCD_DisplayStringAt(TEX/4,TEY/2, (uint8_t *) "<3 We love CPE <3" , LEFT_MODE);

	HAL_Delay(1000);
	Etat_machine = Mode_Manuel;


	return;
}

void afficher_changer_de_mode(){
	BSP_LCD_SetFont(&Font16);

	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);

	BSP_LCD_DisplayStringAt(BCM_pX,20, (uint8_t *) "Changer de Mode" , LEFT_MODE);

	// on dessine un carré autour
	boutton_changer_de_mode.Id = 'A';
	boutton_changer_de_mode.bordH = BCM_pY;
	boutton_changer_de_mode.bordB = BCM_pY + BCM_hauteur;
	boutton_changer_de_mode.bordG = BCM_pX;
	boutton_changer_de_mode.bordD = BCM_pX + BCM_largeur;


	BSP_LCD_SetTextColor(LCD_COLOR_RED);
	BSP_LCD_DrawRect(BCM_pX, BCM_pY,BCM_largeur, BCM_hauteur);


	return;
}

/*
 * @brief
 */
void Changer_de_Mode(){

	switch (Etat_machine){
		case Mode_Manuel:
			Etat_machine = Mode_Automatique;
			Lancer_Mode_Automatique();
			break;
		case Mode_Automatique:
			Etat_machine = Mode_Manuel;
			Lancer_Mode_Manuel();
			break;

	}




}

/*
 * @brief affiche a l'ecran mode manuel
 */
void Lancer_Mode_Manuel(){

	BSP_LCD_Clear(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font16);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
	BSP_LCD_DisplayStringAt(40,20, (uint8_t *) "Mode Manuel" , LEFT_MODE);


	afficher_bandes_couleurs();
	afficher_changer_de_mode();

	remplir_toutes_les_jauges();


	// affichage des bouttons
	afficher_boutton_FULL();
	afficher_boutton_OFF();
	afficher_boutton_MID();
}

/*
 * @brief affiche a l'ecran mode automatique
 */
void Lancer_Mode_Automatique(){

	BSP_LCD_Clear(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font16);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
	BSP_LCD_DisplayStringAt(40,20, (uint8_t *) "Mode Automatique" , LEFT_MODE);
	afficher_changer_de_mode();
	afficher_bandes_couleurs();

	// affichage des bouttons
	afficher_boutton_FULL();
	afficher_boutton_OFF();
	afficher_boutton_MID();
}



void afficher_boutton_FULL(){

	BSP_LCD_SetFont(&Font24);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);

	BSP_LCD_DisplayStringAt(pXbR + largeur_bande + 80,pYbR +10, (uint8_t *) "FULL" , LEFT_MODE);

	// on dessine un carré autour
	boutton_FULL.Id = 'F';
	boutton_FULL.bordH = pYbR;
	boutton_FULL.bordB = pYbR + hauteur_boutton_FMO;
	boutton_FULL.bordG = pXbR + largeur_bande + 80;
	boutton_FULL.bordD = pXbR + largeur_bande + 80 + largeur_boutton_FMO;
	BSP_LCD_SetTextColor(LCD_COLOR_RED);
	BSP_LCD_DrawRect(boutton_FULL.bordG , boutton_FULL.bordH, largeur_boutton_FMO, hauteur_boutton_FMO);


	return;
}

void afficher_boutton_MID(){

	BSP_LCD_SetFont(&Font24);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);

	BSP_LCD_DisplayStringAt(pXbV + largeur_bande + 80,pYbV +10, (uint8_t *) "MID" , LEFT_MODE);

	// on dessine un carré autour
	boutton_MID.Id = 'M';
	boutton_MID.bordH = pYbV;
	boutton_MID.bordB = pYbV + hauteur_boutton_FMO;
	boutton_MID.bordG = pXbV + largeur_bande + 80;
	boutton_MID.bordD = pXbV + largeur_bande + 80 + largeur_boutton_FMO;
	BSP_LCD_SetTextColor(LCD_COLOR_RED);
	BSP_LCD_DrawRect(boutton_MID.bordG , boutton_MID.bordH, largeur_boutton_FMO, hauteur_boutton_FMO);


		return;
}


void afficher_boutton_OFF(){
	BSP_LCD_SetFont(&Font24);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);

	BSP_LCD_DisplayStringAt(pXbB + largeur_bande + 80,pYbB +10, (uint8_t *) "OFF" , LEFT_MODE);

	// on dessine un carré autour
	boutton_OFF.Id = 'O';
	boutton_OFF.bordH = pYbB;
	boutton_OFF.bordB = pYbB + hauteur_boutton_FMO;
	boutton_OFF.bordG = pXbB + largeur_bande + 80;
	boutton_OFF.bordD = pXbB + largeur_bande + 80 + largeur_boutton_FMO;
	BSP_LCD_SetTextColor(LCD_COLOR_RED);
	BSP_LCD_DrawRect(boutton_OFF.bordG, boutton_OFF.bordH ,largeur_boutton_FMO, hauteur_boutton_FMO);


	return;
}


void remplir_toutes_les_jauges(){
	Remplissage_jauge_Callback(jauge_rouge, etatlumiere_R);
	Remplissage_jauge_Callback(jauge_verte, etatlumiere_G);
	Remplissage_jauge_Callback(jauge_bleu, etatlumiere_B);
	Remplissage_jauge_Callback(jauge_blanche, etatlumiere_W);

}


void afficher_pourcent_remplissage(){

	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font24);

	char buffer[10];
	itoa(etatlumiere_R,buffer,10);
	BSP_LCD_DisplayStringAt(jauge_rouge.bordD + 10,jauge_rouge.bordB - 30, (uint8_t *) buffer , LEFT_MODE);

	itoa(etatlumiere_G,buffer,10);
	BSP_LCD_DisplayStringAt(jauge_verte.bordD + 10,jauge_verte.bordB - 30, (uint8_t *) buffer , LEFT_MODE);

	itoa(etatlumiere_B,buffer,10);
	BSP_LCD_DisplayStringAt(jauge_bleu.bordD + 10,jauge_bleu.bordB - 30, (uint8_t *) buffer , LEFT_MODE);

	itoa(etatlumiere_W,buffer,10);
	BSP_LCD_DisplayStringAt(jauge_blanche.bordD + 10,jauge_blanche.bordB - 30, (uint8_t *) buffer , LEFT_MODE);

	return;
}




















