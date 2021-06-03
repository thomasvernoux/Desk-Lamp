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
extern uint16_t x, y;


// ecran 3 bandes

extern int pXbR; // position X bande rouge
extern int pYbR; // position Y bande rouge

extern int pXbV;
extern int pYbV;

extern int pXbB;
extern int pYbB;

extern int hauteur_bande; // hauteur de la bande
extern int largeur_bande;


/* Création des differents objets --------------------------------------------*/
// Ecran 3 bandes
FormeTypeDef jauge_rouge;
FormeTypeDef jauge_verte;
FormeTypeDef jauge_bleu;





/*
 * @brief Cette fonction permet d'afficher l'ecran de controlle manuel
 * avec les 3 bandes des couleur RGB.
 * @retval rien
 */

void afficher_bandes_couleurs(){



	BSP_LCD_Clear(LCD_COLOR_WHITE);

	// Titre
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
	BSP_LCD_DisplayStringAt(40,20, (uint8_t *) "Mode Manuel" , LEFT_MODE);

	// Configuration
	BSP_LCD_DisplayStringAt(250,20, (uint8_t *) "Changer de Mode" , LEFT_MODE);


	// Bande Rouge
	BSP_LCD_SetTextColor(LCD_COLOR_RED);
	BSP_LCD_DrawRect(pXbR, pYbR,largeur_bande, hauteur_bande);
	jauge_rouge.bordH = pYbR;
	jauge_rouge.bordB = pYbR + hauteur_bande;
	jauge_rouge.bordG = pXbR;
	jauge_rouge.bordD = pXbR + largeur_bande;

	// Bande Verte
	BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
	BSP_LCD_DrawRect(pXbV, pYbV,largeur_bande, hauteur_bande);

	// Bande Bleue
	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	BSP_LCD_DrawRect(pXbB, pYbB,largeur_bande, hauteur_bande);


}

void TouchScreenCallBack(){



	uint8_t  status = 0;

	uint8_t  state = 0;
	uint8_t  text[30];
	uint8_t  radius;
	uint8_t  radius_previous = 0;



	status = BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());


	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
	char buffer[10];
	itoa(TEY,buffer,10);
	BSP_LCD_DisplayStringAt(100,100, (uint8_t *) buffer , LEFT_MODE);

	if (status == TS_OK)
	    {
	      BSP_TS_GetState(&TS_State);
	      if(TS_State.touchDetected)
	      {

	  		BSP_LCD_Clear(LCD_COLOR_WHITE);
	  		HAL_Delay(1000);
	  		afficher_bandes_couleurs();

	        x = TS_State.touchX[0];
	        y = TS_State.touchY[0];
	      } // end if
	    } // end if

} // end void


/*
 * @brief Cette fonction permet de savoir si on a appuyé dans une zone de controlle (carrés de couleurs)
 * elle retourne un entier pour savoir a quee absysse on a touché.
 * @retval int
 */
int TouchIn(FormeTypeDef forme){
	int a = 3;
	switch(a){
				case 5:
					a = 19;
					break;



	} // end switch
	return a;

}




























