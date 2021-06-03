/*
 * my_math.c
 *
 *  Created on: 3 juin 2021
 *      Author: mario
 */


/**
 * @brief like arduino float map()
 * @param val input value
 * @param I_Min min input val
 * @param I_Max max output val
 * @param O_Min min output val
 * @param O_Max max output val
 * @retval (float) output val
 */
float mapf(float val, float I_Min, float I_Max, float O_Min, float O_Max) {
		return(((val-I_Min)*((O_Max-O_Min)/(I_Max-I_Min)))+O_Min);
}

/**
 * @brief like arduino int map()
 * @param val input value
 * @param I_Min min input val
 * @param I_Max max output val
 * @param O_Min min output val
 * @param O_Max max output val
 * @retval (float) output val
 */
int map(int val, int I_Min, int I_Max, int O_Min, int O_Max) {
		return((int)((val-I_Min)*((O_Max-O_Min)/(I_Max-I_Min)))+O_Min);
}
