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
#include "adc.h"

unsigned int R_old_value = 0;
unsigned int G_old_value = 0;
unsigned int B_old_value = 0;
unsigned int W_old_value = 0;

extern int etatlumiere_R;
extern int etatlumiere_G;
extern int etatlumiere_B;
extern int etatlumiere_W;

// valeur moyenne
int nombre_de_valeur_Vmoyenne = 5;
int compteur = 0;
long int somme = 0;
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
	long int valeur_lumiere = my_analogRead(&hadc3);
	//AED("val inst", valeur_lumiere,0);

	int vmax = 2500;
	int vmin = 400;

	valeur_lumiere = 100* valeur_lumiere / (vmax - vmin);
	//AED("val inst", valeur_lumiere,1);



	if (compteur < nombre_de_valeur_Vmoyenne){
		compteur += 1;
		somme += valeur_lumiere;
	} // end if

	else{
		int val = somme /  nombre_de_valeur_Vmoyenne;

		if (val <= 100 && val >= 0){

			etatlumiere_R = val;
			etatlumiere_G = val;
			etatlumiere_B = val;
			etatlumiere_W = val;

		}
		else if (val > 100)
			val = 100;
		else if (val < 0)
			val = 0;
		compteur = 0;
		somme = 0;
	}

	remplir_toutes_les_jauges();










}

