/**
  ******************************************************************************
  * @file    BSP/Src/main.c
  * @author  Thomas VERNOUX
  * @brief   Projet de Majeur - Electronique
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stlogo.h"
#include "variables.h"
#include "fonctions_gestion_ecran.h" // functions to control the screen
#include "structures.h"
#include "gpio.h"
#include "tim.h"
#include "adc.h"
#include "dma.h"
#include "PWM.h"
#include "Lumiere.h"      // functions linked to LED controll
#include "NEC_Decode.h"
#include "stm32f7xx_hal_adc.h"
#include "my_math.h"
#include <stdio.h>
#include <stdlib.h>


/* Global extern variables ---------------------------------------------------*/
uint8_t NbLoop = 1;  // number of loops
#ifndef USE_FULL_ASSERT
uint32_t    ErrorCounter = 0;
#endif


// state of the light
int etatlumiere_R;   // Define the red light state variable
int etatlumiere_G;   // Define the green light state variable
int etatlumiere_B;   // Define the blue light state variable
int etatlumiere_W;   // Define the white light state variable

int FlagTimeNEC = -1;  // infrared flag

extern int largeur_bande;   // Declare external variable for band width
extern int hauteur_bande;   // Declare external variable for band height


extern TIM_HandleTypeDef htim1;  // Defin the timer 1
extern DMA_HandleTypeDef hdma_tim1_ch1;  // Declare external variable for DMA associated with Timer 1
NEC nec;  // Declare NEC structure (infrared communication)



/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void LCD_Init(uint8_t  lcd_status);  // LCD sreen initialisation
static void CPU_CACHE_Enable(void);

STATE_MachineTypeDef Etat_machine = Mode_Automatique;  // State of the light

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  uint8_t  lcd_status = LCD_OK;  // Status of LCD screen

  CPU_CACHE_Enable();   
  HAL_Init();                   // Initialise all HAL peripherals
  SystemClock_Config();         // Configuration of system clock

  MX_GPIO_Init();
  MX_ADC3_Init();
  MX_DMA_Init();
  MX_TIM3_Init();  // Timers initialisation
  MX_TIM2_Init();
  MX_TIM1_Init();
  MX_TIM12_Init();



  LCD_Init(lcd_status);  // Initialisation of LCD screen


  set_variables();        // Set variables


  affichage_boot();       // Display boot message on the screen
  Lancer_Mode_Manuel();   // Start manual mode



  while (1)
  {
    // Main loop

	  switch (Etat_machine){
	  	  case Mode_Automatique :              // Automatic mode
	  		  callback_mode_automatique();     // Callback for automatic mode
	  		  RGBW_Light_Callback(map(etatlumiere_R,0,largeur_bande,0,65535),map(etatlumiere_G,0,largeur_bande,0,65535),map(etatlumiere_B,0,largeur_bande,0,65535),map(50,0,512,0,65535));

	  		  remplir_toutes_les_jauges();     // Fill the stripes depending on the LED intensity
	  		  afficher_pourcent_remplissage(); // Print % filling

	  	  case Mode_Manuel :                   // Manual mode
	  		  TouchScreenCallBack();           // Callback for manual mode
	  		  RGBW_Light_Callback(map(etatlumiere_R,0,largeur_bande,0,65535),map(etatlumiere_G,0,largeur_bande,0,65535),map(etatlumiere_B,0,largeur_bande,0,65535),map(50,0,512,0,65535));

	  } // end switch

  } // end while




}






/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow :
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 200000000
  *            HCLK(Hz)                       = 200000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 25
  *            PLL_N                          = 400
  *            PLL_P                          = 2
  *            PLL_Q                          = 8
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 5
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  HAL_StatusTypeDef ret = HAL_OK;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  
  /* Enable Power Control clock */
  __HAL_RCC_PWR_CLK_ENABLE();

  /* The voltage scaling allows optimizing the power consumption when the device is
     clocked below the maximum system frequency, to update the voltage scaling value 
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 400;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 8;
  ret = HAL_RCC_OscConfig(&RCC_OscInitStruct);
  ASSERT(ret != HAL_OK);

  /* activate the OverDrive */
  ret = HAL_PWREx_ActivateOverDrive();
  ASSERT(ret != HAL_OK);

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  ret = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);
  ASSERT(ret != HAL_OK);
}

/**
  * @brief  Display main demo messages.
  * @param  None
  * @retval None
  */
static void LCD_Init(uint8_t  lcd_status)
{
  uint8_t desc[50];
  lcd_status = BSP_LCD_Init();
  ASSERT(lcd_status != LCD_OK);
  BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FRAME_BUFFER);
  /* Set LCD Foreground Layer  */
  BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
  /* Clear the LCD */
  BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
  BSP_LCD_Clear(LCD_COLOR_WHITE);

}

/**
  * @brief  Check for user input.
  * @param  None
  * @retval Input state (1 : active / 0 : Inactive)
  */
uint8_t CheckForUserInput(void)
{
  if (BSP_PB_GetState(BUTTON_KEY) != RESET)
  {
    HAL_Delay(10);
    while (BSP_PB_GetState(BUTTON_KEY) != RESET);
    return 1 ;
  }
  return 0;
}

/**
  * @brief EXTI line detection callbacks.
  * @param GPIO_Pin: Specifies the pins connected EXTI line
  * @retval None
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  static uint32_t debounce_time = 0;

  if (GPIO_Pin == KEY_BUTTON_PIN)
  {
    /* Prevent debounce effect for user key */
    if ((HAL_GetTick() - debounce_time) > 50)
    {
      debounce_time = HAL_GetTick();
    }
  }
  else if (GPIO_Pin == AUDIO_IN_INT_GPIO_PIN)
  {
    /* Audio IN interrupt */
  }
}

/**
  * @brief  CPU L1-Cache enable.
  * @param  None
  * @retval None
  */
static void CPU_CACHE_Enable(void)
{
  /* Enable I-Cache */
  SCB_EnableICache();

  /* Enable D-Cache */
  SCB_EnableDCache();
}

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif /* USE_FULL_ASSERT */


/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}


/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
