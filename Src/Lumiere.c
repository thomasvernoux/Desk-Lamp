/*
 * Lumiere.c
 *
 *  Created on: 3 juin 2021
 *      Author: Thomas Vernoux
 *      Fonctions de callback allumage des leds
 *      Callbacks functions for LED
 */
#include "main.h"
#include "Lumiere.h"
#include "tim.h"
#include "PWM.h"
#include "adc.h"

unsigned int R_old_value = 0;  // Old value for red light
unsigned int G_old_value = 0;  // Old value for green light
unsigned int B_old_value = 0;  // Old value for blue light
unsigned int W_old_value = 0;  // Old value for white light

extern int etatlumiere_R;  // Red light state
extern int etatlumiere_G;  // green light state
extern int etatlumiere_B;  // blue light state
extern int etatlumiere_W;  // white light state

// Photodiode varaibles
int nombre_de_valeur_Vmoyenne = 5; // number of value for mean calculation (photodiod low pass filter)
int compteur = 0;                  // Variable for low pass filter
long int somme = 0;                // Sum for lowpass filter

/**
  * @brief  Callback for RGBW LEDs.
  *
  * @param  R_value : value for red light
  * @param  G_value : value for green light
  * @param  B_value : value for blue light
  * @param  W_value : value for white light
  * @retval None
  */
void RGBW_Light_Callback(const unsigned int R_value,const unsigned int G_value,const unsigned int B_value,const unsigned int W_value){


	if (R_old_value != R_value) // Check if the new value if=s defferent from the old one.
		R_Light_Callback(0xFFFFFFFF - R_value); // the hardware is inverting type
	if (G_old_value != G_value)
		G_Light_Callback(0xFFFFFFFF - G_value);
	if (B_old_value != B_value)
		B_Light_Callback(0xFFFFFFFF - B_value);
	if (W_old_value != W_value)
		W_Light_Callback(0xFFFFFFFF - W_value);
}


/**
  * @brief  Callback for Red led.
  * @param  intensite : intensity
  */
void R_Light_Callback(const unsigned int Intensite){ 
	R_old_value = Intensite;
	MP_setPWM(&htim3,TIM_CHANNEL_1,Intensite);
}

/**
  * @brief  Callback for green led.
  * @param  intensite : intensity
  */
void G_Light_Callback(const unsigned int Intensite){ 
	G_old_value = Intensite;
	MP_setPWM(&htim12,TIM_CHANNEL_1,Intensite);
} 

/**
  * @brief  Callback for Blue led.
  * @param  intensite : intensity
  */
void B_Light_Callback(const unsigned int Intensite){
	B_old_value = Intensite;
	MP_setPWM(&htim2,TIM_CHANNEL_1,Intensite);
}


/**
  * @brief  Callback for White led.
  * @param  intensite : intensity
  */
void W_Light_Callback(const unsigned int Intensite){ 
	W_old_value = Intensite;
	MP_setPWM(&htim12,TIM_CHANNEL_2,Intensite);
}



/*
 * @brief Automatic callback : write light value depending on the photoresistor
 *
 */
void callback_mode_automatique() {
	long int valeur_lumiere = my_analogRead(&hadc3); // Photoresistor value read

	// Photodiod calibration value
	int vmax = 2500; // Max value measured for the photoresistor
	int vmin = 400;  // Min value measured for the photoresistor

	valeur_lumiere = 100* valeur_lumiere / (vmax - vmin);  // Light value %



	// Lowpass filter for might value
	if (compteur < nombre_de_valeur_Vmoyenne){
		compteur += 1;
		somme += valeur_lumiere;
	} // end if

	else{
		int val = somme /  nombre_de_valeur_Vmoyenne; // mean calculation

		if (val <= 100 && val >= 0){  // Normal state

			etatlumiere_R = val;
			etatlumiere_G = val;
			etatlumiere_B = val;
			etatlumiere_W = val;

		}
		else if (val > 100)
			// Light is more intensife than the maximum
			val = 100;
		else if (val < 0)
			// Light is less intensive than the minimum
			val = 0;
		compteur = 0;  // reset the counter (lowpass filter)
		somme = 0;     // reset the sum (lowpass filter)
	}

	remplir_toutes_les_jauges();  // Update all stripes










}

