/*
 * fonctions_gestion_ecran.c
 * This file contain all function linked to the screen
 *
 *  Created on: 2 juin 2021
 *      Author: thomas
 */

#include "fonctions_gestion_ecran.h"
#include "main.h"

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



extern int marge_haut;    // Top space
extern int marge_droite;  // right space
extern int marge_gauche;  // Left space

extern int TEX;   // Screen size X
extern int TEY;   // SCreen size Y


// Stripes positions
extern int pXbR; // Red stripe X position
extern int pYbR; // Red stripe Y position

extern int pXbV; // green stripe X position
extern int pYbV; // green stripe Y position

extern int pXbB; // blue stripe X position
extern int pYbB; // blue stripe Y position

extern int pXbW; // White stripe X position
extern int pYbW; // White stripe Y position

extern int hauteur_bande; // hight of the stripe
extern int largeur_bande; // width pf the stripe

extern int etatlumiere_R; // state light Red
extern int etatlumiere_G; // state light green
extern int etatlumiere_B; // state light blue
extern int etatlumiere_W; // state light white

// boutton changer de mode :
extern int BCM_pX; // position X
extern int BCM_pY; // position Y
extern int BCM_largeur; // largeur
extern int BCM_hauteur; // hauteur


/* Création des differents objets --------------------------------------------*/
// Ecran 3 bandes
FormeTypeDef jauge_rouge; // red stripe object
FormeTypeDef jauge_verte; // green stripe object
FormeTypeDef jauge_bleu; // blue stripe object
FormeTypeDef jauge_blanche; // white stripe object
// bouttons
FormeTypeDef boutton_changer_de_mode;  // change mode button
FormeTypeDef boutton_OFF;              // Off button
FormeTypeDef boutton_FULL;             // Full button
FormeTypeDef boutton_MID;              // Mid button

/* Variables de la machine d'etat ---------------------------------------------*/
extern STATE_MachineTypeDef Etat_machine;  // State of the machine


// variables bouttons
extern int largeur_boutton_FMO; // full mid off
extern int hauteur_boutton_FMO; // full mid off


/*
 * @brief : this callback function fill gauges depending on the LED intensity
 * @param : FormeTypeDef forme - struct that contain the rectangular form (coordinates for each side)
 * @param intensite : intensity
 */
void Remplissage_jauge_Callback(FormeTypeDef forme, int Intensite){
	// filling the rectangle with white (earasing last value)
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_FillRect(forme.bordG+1,forme.bordH+1,(forme.bordD-forme.bordG)-1, (forme.bordB-forme.bordH)-1);

	// depending of the color we want to fill :
	if (forme.Id == 'R')
		BSP_LCD_SetTextColor(LCD_COLOR_RED);
	else if (forme.Id == 'V')
		BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
	else if (forme.Id == 'B')
		BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	else if (forme.Id == 'W')
			BSP_LCD_SetTextColor(LCD_COLOR_BLACK);

	// fill the jauge with the correct vqlue
	BSP_LCD_FillRect(forme.bordG+1,forme.bordH+1,((forme.bordD-forme.bordG)-1)*Intensite/100, (forme.bordB-forme.bordH)-1);
}

/*
 * @brief : plot manual screen (colored band)
 */

void afficher_bandes_couleurs(){

	// Red stripe
	BSP_LCD_SetTextColor(LCD_COLOR_RED);                         // Text color : Red
	BSP_LCD_DrawRect(pXbR, pYbR,largeur_bande, hauteur_bande);   // draw Border rectangle
	jauge_rouge.bordH = pYbR;                                    // save gauge parameters
	jauge_rouge.bordB = pYbR + hauteur_bande;
	jauge_rouge.bordG = pXbR;
	jauge_rouge.bordD = pXbR + largeur_bande;
	jauge_rouge.Id = 'R';

	// Green stripe
	BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
	BSP_LCD_DrawRect(pXbV, pYbV,largeur_bande, hauteur_bande);
	jauge_verte.bordH = pYbV;
	jauge_verte.bordB = pYbV + hauteur_bande;
	jauge_verte.bordG = pXbV;
	jauge_verte.bordD = pXbV + largeur_bande;
	jauge_verte.Id = 'V';

	// blue stripe
	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	BSP_LCD_DrawRect(pXbB, pYbB,largeur_bande, hauteur_bande);
	jauge_bleu.bordH = pYbB;
	jauge_bleu.bordB = pYbB + hauteur_bande;
	jauge_bleu.bordG = pXbB;
	jauge_bleu.bordD = pXbB + largeur_bande;
	jauge_bleu.Id = 'B';

	// white stripe
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_DrawRect(pXbW, pYbW,largeur_bande, hauteur_bande);
	jauge_blanche.bordH = pYbW;
	jauge_blanche.bordB = pYbW + hauteur_bande;
	jauge_blanche.bordG = pXbW;
	jauge_blanche.bordD = pXbW + largeur_bande;
	jauge_blanche.Id = 'W';


	afficher_pourcent_remplissage();   // Print filling %



}

/*
 * @brief gauge callback
 * Detect if the screen has been touched, and update gauge if necessary.
 * Detect if a button has been touched and update the machine if necessary
 */
void TouchScreenCallBack(){

	uint8_t  status = 0;                                            // Status of the LCD screen
	status = BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());

	if (status == TS_OK){
	      BSP_TS_GetState(&TS_State);  // write in the touchscreen structure events (screen touched)
	      if(TS_State.touchDetected){
	    	// The screen has been touched
	        x = TS_State.touchX[0];    // Position of the touch
	        y = TS_State.touchY[0];


	        switch (Etat_machine){
				case Mode_Manuel:  // the light is in manual mode
					// See if a color gauge has been touched, and to the action if necessary
					TouchIn(jauge_rouge);
					TouchIn(jauge_verte);
					TouchIn(jauge_bleu);
					TouchIn(jauge_blanche);
					break;

				case Mode_Automatique :

					if (TouchIn(jauge_rouge) || TouchIn(jauge_verte) || TouchIn(jauge_bleu) || TouchIn(jauge_blanche)){
						// The light switch to manual mode
						Etat_machine = Mode_Manuel;
						Lancer_Mode_Manuel();  // start manual mode
						break;

					} // end if

			} // end switch etat machine


	        // Test if the touch was on a button

	        if (TouchIn(boutton_changer_de_mode)){ // Test is changemode was touched
	        	Changer_de_Mode(); // Changemode is touched.
	        }


	        if (TouchIn(boutton_FULL)){ // FULL button
	        	Etat_machine = Mode_Manuel;  // switch to manual mode
	        	Lancer_Mode_Manuel();        // start manual mode
	        	etatlumiere_R = 100;         // set full power on LEDs
	        	etatlumiere_G = 100;
	        	etatlumiere_B = 100;
	        	etatlumiere_W = 100;
	        	remplir_toutes_les_jauges(); // fill the gauges
	        	afficher_pourcent_remplissage();  // wrtie the infill %
	        } // end if FULL

	        if (TouchIn(boutton_MID)){ // MID button
	        	Etat_machine = Mode_Manuel;  // switch to manual mode
	        	etatlumiere_R = 50;          // set mid power on LEDs
	        	etatlumiere_G = 50;
	        	etatlumiere_B = 50;
	        	etatlumiere_W = 50;
	        	Lancer_Mode_Manuel();        // start manual mode
	        	afficher_pourcent_remplissage();  // wrtie the infill %
	        } // end if MID

 	        if (TouchIn(boutton_OFF)){        // OFF button
	        	Etat_machine = Mode_Manuel;   // switch to manual mode
	        	etatlumiere_R = 0;            // set 0 power on LEDs
	        	etatlumiere_G = 0;
	        	etatlumiere_B = 0;
	        	etatlumiere_W = 0;
	        	Lancer_Mode_Manuel();         // start manual mode
	        	afficher_pourcent_remplissage();  // wrtie the infill %
	        	} // end if OFF


	      } // end if
	    } // end if

} // end void


/*
 * @brief this function test if atouch was in a form? If it was in a gauge, update the gauge.
 * @param forme : structure of the gauge, containing the color, and steh side coordinates
 * @retval int : returned 1 if the touch is in the gauge
 */
int TouchIn(FormeTypeDef forme){

	int ret = 0;  // return value (int in % of the gauge touched)

	if (x < forme.bordD && x > forme.bordG && y > forme.bordH && y < forme.bordB){// Check if the touch is in a form (jauge or button)

		ret = 1; // The touch is in the gauge
		if (forme.Id == 'R' || forme.Id == 'V' || forme.Id == 'B' || forme.Id == 'W'){
			// The touch is in a gauge
			BSP_LCD_SetTextColor(LCD_COLOR_BLACK);  // set the font color
			BSP_LCD_SetBackColor(LCD_COLOR_WHITE);  // set the background color
			BSP_LCD_FillRect(forme.bordD + 10,forme.bordB - 30,52,24);  // draw rectangle border
			BSP_LCD_SetFont(&Font24);               // set the font size

			char buffer[10];                        // Buffer for infill %
			x = (x-18) *100 / (largeur_bande);      // define the infill %
			Remplissage_jauge_Callback(forme, x);   // fill the rectangle depending on the % infill
			itoa(x,buffer,10);                      // convert the infill % to write it on the screen
			BSP_LCD_SetTextColor(LCD_COLOR_BLACK);  // set parameters to write the infill %
			BSP_LCD_SetBackColor(LCD_COLOR_WHITE);  // set parameters to write the infill %
			BSP_LCD_DisplayStringAt(forme.bordD + 10,forme.bordB - 30, (uint8_t *) buffer , LEFT_MODE);  // print the infill %

			// update the light value depending on the touch
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
 * @brief This function print a variable on the screen (debug purpose)
 */

void AED(char label[10], int var, int place){
	int absysse = 20;     // position X
	for (int i = 0; i< place; i++){
		absysse += 20;
	}

	// set display parameters
	BSP_LCD_SetTextColor(LCD_COLOR_YELLOW);
	BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
	BSP_LCD_SetFont(&Font16);

	// convert value
	char buffer[10];
	itoa(var,buffer,10);
	strcat(buffer,"/");
	BSP_LCD_DisplayStringAt(20,absysse, (uint8_t *) label , LEFT_MODE);
	BSP_LCD_DisplayStringAt(100,absysse, (uint8_t *) buffer , LEFT_MODE);
	return;
}


/*
 * @brief This function print a message during initialisation : Hello
 */
void affichage_boot(){
	BSP_LCD_Clear(LCD_COLOR_WHITE);  // clear the screen
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);   // set display parameters
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);   // set background color
	BSP_LCD_SetFont(&Font24);                // set font color

	BSP_LCD_DisplayStringAt(TEX/4,TEY/2, (uint8_t *) "Hello" , LEFT_MODE);  // display message

	HAL_Delay(1000);               // delay
	Etat_machine = Mode_Manuel;    // switch the machine state
	return;
}

/*
 * @brief This function print the changemode button
 */
void afficher_changer_de_mode(){
	BSP_LCD_SetFont(&Font16);  // set font parameters

	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);  // set text color
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);  // set back color

	BSP_LCD_DisplayStringAt(BCM_pX,20, (uint8_t *) "Changer de Mode" , LEFT_MODE);  // display changemode

	// draw a square auround the button
	boutton_changer_de_mode.Id = 'A';  // button Form ID
	// coordinates of the changemode form square
	boutton_changer_de_mode.bordH = BCM_pY;     // BCM_pY : boutton changer de mode position Y
	boutton_changer_de_mode.bordB = BCM_pY + BCM_hauteur;
	boutton_changer_de_mode.bordG = BCM_pX;
	boutton_changer_de_mode.bordD = BCM_pX + BCM_largeur;

	//BSP_LCD_DrawRect(BCM_pX, BCM_pY,BCM_largeur, BCM_hauteur);

	return;
}

/*
 * @brief This function is used to switch between automatic and manual mode.
 */
void Changer_de_Mode(){

	switch (Etat_machine){
		case Mode_Manuel:                           // Manual mode : switch to automatic
			Etat_machine = Mode_Automatique;        // Change machine state
			Lancer_Mode_Automatique();              // start automatic mode
			break;
		case Mode_Automatique:                      // Automatic mode : switch to manual
			Etat_machine = Mode_Manuel;             // Change machine state
			Lancer_Mode_Manuel();                   // start manual mode
			break;
	}
}

/*
 * @brief Print manual screen
 */

void Lancer_Mode_Manuel(){

	BSP_LCD_Clear(LCD_COLOR_WHITE);                                        // clear LCD screen
	BSP_LCD_SetFont(&Font16);                                              // set font
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);                                 // set text color
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);                                 // set back color
	BSP_LCD_DisplayStringAt(40,20, (uint8_t *) "Mode Manuel" , LEFT_MODE); // display "mode manuel"
	afficher_bandes_couleurs();                                            // display gauges
	afficher_changer_de_mode();                                            // display changemode button
	remplir_toutes_les_jauges();                                           // fill gauges



	afficher_boutton_FULL();                                               // display FULL button
	afficher_boutton_OFF();                                                // display Off button
	afficher_boutton_MID();                                                // display Mid button
}

/*
 * @brief Print the automatic screen
 */
void Lancer_Mode_Automatique(){

	BSP_LCD_Clear(LCD_COLOR_WHITE);                                             // clear LCD screen
	BSP_LCD_SetFont(&Font16);                                                   // set font
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);                                      // set text color
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);                                      // set back color
	BSP_LCD_DisplayStringAt(40,20, (uint8_t *) "Mode Automatique" , LEFT_MODE); // display "mode automatique"
	afficher_changer_de_mode();                                                 // display changemode button
	afficher_bandes_couleurs();                                                 // display gauges

	afficher_boutton_FULL();                                                    // display FULL button
	afficher_boutton_OFF();                                                     // display Off button
	afficher_boutton_MID();                                                     // display Mid button
}


/*
 * @brief : Display the "FULL" button
 */
void afficher_boutton_FULL(){

	BSP_LCD_SetFont(&Font24);                 // set font type
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);    // set font color
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);    // set font back color

	BSP_LCD_DisplayStringAt(pXbR + largeur_bande + 80,pYbR +10, (uint8_t *) "FULL" , LEFT_MODE); // display FUll on the button

	// Draw a square around the button
	boutton_FULL.Id = 'F';      // Id of the form
	boutton_FULL.bordH = pYbR;  // coordinates
	boutton_FULL.bordB = pYbR + hauteur_boutton_FMO;
	boutton_FULL.bordG = pXbR + largeur_bande + 80;
	boutton_FULL.bordD = pXbR + largeur_bande + 80 + largeur_boutton_FMO;
	BSP_LCD_SetTextColor(LCD_COLOR_RED);
	//BSP_LCD_DrawRect(boutton_FULL.bordG , boutton_FULL.bordH, largeur_boutton_FMO, hauteur_boutton_FMO);

	return;
}


/*
 * @brief : Display the "MID" button
 */
void afficher_boutton_MID(){

	BSP_LCD_SetFont(&Font24);                  // set font type
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);     // set font color
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);     // set font background color

	// display MID on the button
	BSP_LCD_DisplayStringAt(pXbV + largeur_bande + 80,pYbV +10, (uint8_t *) "MID" , LEFT_MODE);

	// Draw a square around the button
	boutton_MID.Id = 'M';      // Id of the form
	boutton_MID.bordH = pYbV;  // coordinates
	boutton_MID.bordB = pYbV + hauteur_boutton_FMO;
	boutton_MID.bordG = pXbV + largeur_bande + 80;
	boutton_MID.bordD = pXbV + largeur_bande + 80 + largeur_boutton_FMO;
	BSP_LCD_SetTextColor(LCD_COLOR_RED);
	//BSP_LCD_DrawRect(boutton_MID.bordG , boutton_MID.bordH, largeur_boutton_FMO, hauteur_boutton_FMO);


		return;
}

/*
 * @brief : Display the "OFF" button
 */
void afficher_boutton_OFF(){
	BSP_LCD_SetFont(&Font24);                  // set font type
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);     // set font color
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);     // set font background color

	// display OFF on the button
	BSP_LCD_DisplayStringAt(pXbB + largeur_bande + 80,pYbB +10, (uint8_t *) "OFF" , LEFT_MODE);

	// Draw a square around the button
	boutton_OFF.Id = 'O';     // Id of the form
	boutton_OFF.bordH = pYbB; // coordinates
	boutton_OFF.bordB = pYbB + hauteur_boutton_FMO;
	boutton_OFF.bordG = pXbB + largeur_bande + 80;
	boutton_OFF.bordD = pXbB + largeur_bande + 80 + largeur_boutton_FMO;
	BSP_LCD_SetTextColor(LCD_COLOR_RED);
	//BSP_LCD_DrawRect(boutton_OFF.bordG, boutton_OFF.bordH ,largeur_boutton_FMO, hauteur_boutton_FMO);

	return;
}

/*
 * @brief : Fill all gauges depending on the intensity required
 */
void remplir_toutes_les_jauges(){
	Remplissage_jauge_Callback(jauge_rouge, etatlumiere_R);  // gauge callback red
	Remplissage_jauge_Callback(jauge_verte, etatlumiere_G);  // gauge callback green
	Remplissage_jauge_Callback(jauge_bleu, etatlumiere_B);   // gauge callback blue
	Remplissage_jauge_Callback(jauge_blanche, etatlumiere_W);// gauge callback white

}

/*
 * @brief : print % next to gauges depending on the intensity required
 */
void afficher_pourcent_remplissage(){

	BSP_LCD_SetFont(&Font24);                  // set font type
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);     // set font color
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);     // set font background color

	char buffer[10];                  // buffer for light %
	itoa(etatlumiere_R,buffer,10);    // convert light % to string
	// print the light %
	BSP_LCD_DisplayStringAt(jauge_rouge.bordD + 10,jauge_rouge.bordB - 30, (uint8_t *) buffer , LEFT_MODE);

	itoa(etatlumiere_G,buffer,10);    // convert light % to string
	// print the light %
	BSP_LCD_DisplayStringAt(jauge_verte.bordD + 10,jauge_verte.bordB - 30, (uint8_t *) buffer , LEFT_MODE);

	itoa(etatlumiere_B,buffer,10);    // convert light % to string
	// print the light %
	BSP_LCD_DisplayStringAt(jauge_bleu.bordD + 10,jauge_bleu.bordB - 30, (uint8_t *) buffer , LEFT_MODE);

	itoa(etatlumiere_W,buffer,10);    // convert light % to string
	// print the light %
	BSP_LCD_DisplayStringAt(jauge_blanche.bordD + 10,jauge_blanche.bordB - 30, (uint8_t *) buffer , LEFT_MODE);

	return;
}




















