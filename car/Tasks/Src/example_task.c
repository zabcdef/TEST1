#include "example_task.h"
#include "os.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "components.h"
/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private functions declaration ---------------------------------------------*/
/* USER CODE BEGIN PFD */

/* USER CODE END PFD */

/**
* @breif 		main task of example_task
* @param 		args: avoid some funtions put parameters to this function
* @return		none
* @note
*/

void Example_task(void * arg) {
	/* You can write your own code here */
	/* USER CODE BEGIN */
	
	/* USER CODE END */

		/* You can write your own code here */
		/* USER CODE BEGIN */
	PWM_SetFrequency(&pwm1[1],100);
	PWM_SetFrequency(&pwm1[2],100);
	PWM_SetFrequency(&pwm1[3],100);
	PWM_SetFrequency(&pwm1[4],100);
	PWM_SetFrequency(&pwm2[1],100);
	PWM_SetFrequency(&pwm2[2],100);
	PWM_SetFrequency(&pwm2[3],100);
	PWM_SetFrequency(&pwm2[4],100);
	float forward = control.channel[1];
	float direction = control.channel[0];
	
	/* USER CODE END */
	while(1) {
		/*
		!!!!!this is code for controller!!!!! Don't use trace module at the same time!!!!!!!!!!!!!!!
			if (control.channel[1] > 0.2){
				PWM_SetDutyRatio(&pwm1[4],1);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
				PWM_SetDutyRatio(&pwm2[1],1);
				PWM_SetDutyRatio(&pwm2[2],1);
			}
			if (control.channel[1] < -0.2){
				PWM_SetDutyRatio(&pwm1[4],0);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
				PWM_SetDutyRatio(&pwm2[1],1);
				PWM_SetDutyRatio(&pwm2[2],1);
				
			}
			else{
				if (control.channel[0] > 0.2){
					PWM_SetDutyRatio(&pwm1[4],1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
					PWM_SetDutyRatio(&pwm2[1],1);
					PWM_SetDutyRatio(&pwm2[2],1);
				}
				if (control.channel[0] < -0.2){
					PWM_SetDutyRatio(&pwm1[4],0);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
					PWM_SetDutyRatio(&pwm2[1],1);
					PWM_SetDutyRatio(&pwm2[2],1);
				}
				else {
					PWM_SetDutyRatio(&pwm1[4],1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
					PWM_SetDutyRatio(&pwm2[1],1);
					PWM_SetDutyRatio(&pwm2[2],1);
				}
			}
			*/
			//!!!!!This is trace module!!!!!! Don't use controller part at the same time!!!!!!!!!!!!! 
			if (adc_data[0].data > 2050 && adc_data[3].data < 2250 && adc_data[5].data > 2100){
				PWM_SetDutyRatio(&pwm1[4],1);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
				PWM_SetDutyRatio(&pwm2[1],0.25);
				PWM_SetDutyRatio(&pwm2[2],0.25);
			}//on the right way
			if (adc_data[0].data < 2050 && adc_data[3].data < 2250 && adc_data[5].data > 2100){
				PWM_SetDutyRatio(&pwm1[4],1);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
				PWM_SetDutyRatio(&pwm2[1],0.25);
				PWM_SetDutyRatio(&pwm2[2],0.25);
			}//a little 
			if (adc_data[0].data > 2050 && adc_data[3].data < 2250 && adc_data[5].data < 2100){
				PWM_SetDutyRatio(&pwm1[4],1);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
				PWM_SetDutyRatio(&pwm2[1],0.25);
				PWM_SetDutyRatio(&pwm2[2],0.25);
			}// a little
			if (adc_data[0].data < 2050 && adc_data[3].data < 2250 && adc_data[5].data < 2100){
				PWM_SetDutyRatio(&pwm1[4],1);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
				PWM_SetDutyRatio(&pwm2[1],0.25);
				PWM_SetDutyRatio(&pwm2[2],0.25);
			}//parallel black !stop
			if (adc_data[0].data < 2050 && adc_data[3].data > 2250 && adc_data[5].data > 2100){
				PWM_SetDutyRatio(&pwm1[4],1);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
				PWM_SetDutyRatio(&pwm2[1],0.25);
				PWM_SetDutyRatio(&pwm2[2],0.25);
			}// adjustion
			if (adc_data[0].data > 2050 && adc_data[3].data > 2250 && adc_data[5].data < 2100){
				PWM_SetDutyRatio(&pwm1[4],1);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
				PWM_SetDutyRatio(&pwm2[1],0.25);
				PWM_SetDutyRatio(&pwm2[2],0.25);
			}// adjustion
			if (adc_data[0].data > 2050 && adc_data[3].data > 2250 && adc_data[5].data > 2100){
				PWM_SetDutyRatio(&pwm1[4],1);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
				PWM_SetDutyRatio(&pwm2[1],0.25);
				PWM_SetDutyRatio(&pwm2[2],0.25);
			}// white space !stop
			
		}
		/* USER CODE END */
		delay(5);
}


/* Private functions ---------------------------------------------------------*/
/*	Remember to declare your functions at the beginning of this file and in the .h file */
/* USER CODE BEGIN PF */

/* USER CODE END PF */
