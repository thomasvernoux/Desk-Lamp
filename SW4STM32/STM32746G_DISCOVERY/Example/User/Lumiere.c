/*
 * Lumiere.c
 *
 *  Created on: 3 juin 2021
 *      Author: florian
 *      Fonctions de callback allumage des leds
 */
#include "main.h"
#include "Lumiere.h"
#include "tim.h"
#include "PWM.h"

unsigned int R_old_value = 0;
unsigned int G_old_value = 0;
unsigned int B_old_value = 0;
unsigned int W_old_value = 0;

extern int etatlumiere_R;
extern int etatlumiere_G;
extern int etatlumiere_B;

void RGBW_Light_Callback(const unsigned int R_value,const unsigned int G_value,const unsigned int B_value,const unsigned int W_value){


	if (R_old_value != R_value)
		R_Light_Callback(0xFFFFFFFF - R_value); // Notre montage est inverseur
	if (G_old_value != G_value)
		G_Light_Callback(0xFFFFFFFF - G_value);
	if (B_old_value != B_value)
		B_Light_Callback(0xFFFFFFFF - B_value);
	if (W_old_value != W_value)
		W_Light_Callback(0xFFFFFFFF - W_value);
}



void R_Light_Callback(const unsigned int Intensite){ 
	R_old_value = Intensite;
	MP_setPWM(&htim3,TIM_CHANNEL_1,Intensite);
}

void G_Light_Callback(const unsigned int Intensite){ 
	G_old_value = Intensite;
	MP_setPWM(&htim12,TIM_CHANNEL_1,Intensite);
} 

void B_Light_Callback(const unsigned int Intensite){
	B_old_value = Intensite;
	MP_setPWM(&htim2,TIM_CHANNEL_1,Intensite);
}


void W_Light_Callback(const unsigned int Intensite){ 
	W_old_value = Intensite;
	MP_setPWM(&htim12,TIM_CHANNEL_2,Intensite);
}



/*
 * @brief Cette fonction gere la reception du signial de la photorésistance et écrit sur les sorties PWM lors du mode automatique
 *
 */
void callback_mode_automatique() {
	int valeur_lumiere = my_analogRead();
	etatlumiere_R = valeur_lumiere;
	etatlumiere_G = valeur_lumiere;
	etatlumiere_B = valeur_lumiere;
	AED("aa",valeur_lumiere,3);




}

