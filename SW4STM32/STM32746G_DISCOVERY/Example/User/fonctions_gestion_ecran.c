/*
 * fonctions_gestion_ecran.c
 *
 *  Created on: 2 juin 2021
 *      Author: thoma
 */

#include "fonctions_gestion_ecran.h"
#include "main.h"
#include "stm32746g_discovery_ts.h"
#include "variables.h"
#include <stdio.h>
#include <stdlib.h>




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

extern int hauteur_bande; // hauteur de la bande
extern int largeur_bande;

int curseur_jauge_rouge;
int surseur_jauge_verte;
int curseur_jauge_bleue;

extern int etatlumiere_R;
extern int etatlumiere_G;
extern int etatlumiere_B;

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
// boutton changer de mode
FormeTypeDef boutton_changer_de_mode;

/* Variables de la machine d'etat ---------------------------------------------*/
extern STATE_MachineTypeDef Etat_machine;



void Remplissage_jauge_Callback(FormeTypeDef forme, int Intensite){
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_FillRect(forme.bordG+1,forme.bordH+1,(forme.bordD-forme.bordG)-1, (forme.bordB-forme.bordH)-1);
	if (forme.Id == 'R')
		BSP_LCD_SetTextColor(LCD_COLOR_RED);
	else if (forme.Id == 'V')
		BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
	else if (forme.Id == 'B')
		BSP_LCD_SetTextColor(LCD_COLOR_BLUE);

	BSP_LCD_FillRect(forme.bordG+1,forme.bordH+1,((forme.bordD-forme.bordG)-1)*Intensite/largeur_bande, (forme.bordB-forme.bordH)-1);
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


	// afficher les chiffres qui indiquent le remplissage des jauges


	char buffer[10];
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
	BSP_LCD_SetFont(&Font24);

	itoa(etatlumiere_R,buffer,10);
	BSP_LCD_DisplayStringAt(jauge_rouge.bordD + 10,jauge_rouge.bordB - 30, (uint8_t *) buffer , LEFT_MODE);

	itoa(etatlumiere_G,buffer,10);
	BSP_LCD_DisplayStringAt(jauge_verte.bordD + 10,jauge_verte.bordB - 30, (uint8_t *) buffer , LEFT_MODE);

	itoa(etatlumiere_B,buffer,10);
	BSP_LCD_DisplayStringAt(jauge_bleu.bordD + 10,jauge_bleu.bordB - 30, (uint8_t *) buffer , LEFT_MODE);




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

	        if (TouchIn(boutton_changer_de_mode)){ //on cherche a detecter si on change de mode
	        	Changer_de_Mode();


	        }

	        switch (Etat_machine){
	        	case Mode_Manuel:
	        		TouchIn(jauge_rouge);
	        		TouchIn(jauge_verte);
	        		TouchIn(jauge_bleu);


	        }



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

	int curseur = -1;
	if (x < forme.bordD && x > forme.bordG && y > forme.bordH && y < forme.bordB){
		ret = 1;
		if (forme.Id == 'R' || forme.Id == 'V' || forme.Id == 'B'){
			// alors on manipule une jauge
			BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
			BSP_LCD_FillRect(forme.bordD + 10,forme.bordB - 30,52,24);
			BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
			BSP_LCD_SetFont(&Font24);
			char buffer[10];
			x = x - 18;
			itoa(x,buffer,10);
			BSP_LCD_DisplayStringAt(forme.bordD + 10,forme.bordB - 30, (uint8_t *) buffer , LEFT_MODE);
			Remplissage_jauge_Callback(forme, x);
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

	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
	BSP_LCD_SetFont(&Font16);
	char buffer[10];
	itoa(var,buffer,10);
	BSP_LCD_DisplayStringAt(20,absysse, (uint8_t *) label , LEFT_MODE);
	BSP_LCD_DisplayStringAt(100,absysse, (uint8_t *) buffer , LEFT_MODE);


	return;




}

void affichage_boot(){
	BSP_LCD_Clear(LCD_COLOR_WHITE);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
	BSP_LCD_SetFont(&Font24);

	BSP_LCD_DisplayStringAt(TEX/2,TEY/2, (uint8_t *) "Wesh" , LEFT_MODE);

	HAL_Delay(1000);
	Etat_machine = Mode_Manuel;


	return;
}

void afficher_changer_de_mode(){
	BSP_LCD_SetFont(&Font16);

	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetBackColor(LCD_COLOR_BLUE);

	BSP_LCD_DisplayStringAt(250,20, (uint8_t *) "Changer de Mode" , LEFT_MODE);

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
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
	BSP_LCD_DisplayStringAt(40,20, (uint8_t *) "Mode Manuel" , LEFT_MODE);


	afficher_bandes_couleurs();
	afficher_changer_de_mode();
}

/*
 * @brief affiche a l'ecran mode manuel
 */
void Lancer_Mode_Automatique(){

	BSP_LCD_Clear(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font16);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
	BSP_LCD_DisplayStringAt(40,20, (uint8_t *) "Mode Automatique" , LEFT_MODE);
	afficher_changer_de_mode();
	afficher_bandes_couleurs();
}


























