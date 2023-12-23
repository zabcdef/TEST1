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
double AngleToDuty1(double angle)
{
	return (0.5+angle/180.0*2.0)/20.0;
}
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
	float angle_0=30;
	PWM_SetFrequency(&pwm1[1],100);
	PWM_SetFrequency(&pwm1[2],100);
	PWM_SetFrequency(&pwm1[3],100);
	PWM_SetFrequency(&pwm1[4],200);
	PWM_SetFrequency(&pwm2[1],100);
	PWM_SetFrequency(&pwm2[2],100);
	PWM_SetFrequency(&pwm2[3],100);
	PWM_SetFrequency(&pwm2[4],100);
	float forward = control.channel[1];
	float direction = control.channel[0];
	int i =1;
	/* USER CODE END */
	while(1) {
		//left test
		/*HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,1);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
		PWM_SetDutyRatio(&pwm2[1],1);
		PWM_SetDutyRatio(&pwm2[2],1);
		*/
		//right test
		/*
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,0);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
		PWM_SetDutyRatio(&pwm2[1],1);
		PWM_SetDutyRatio(&pwm2[2],1);
		*/
		
		
		
		if (control.triSwitch[0] == 3){
			i = 1;
		//!!!!!this is code for controller!!!!! Don't use trace module at the same time!!!!!!!!!!!!!!!
			if (-control.channel[1] > 0.2){
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,1);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
				PWM_SetDutyRatio(&pwm2[1],1);
				PWM_SetDutyRatio(&pwm2[2],1);
			}
			if (-control.channel[1] < -0.2){
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,0);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
				PWM_SetDutyRatio(&pwm2[1],1);
				PWM_SetDutyRatio(&pwm2[2],1);
				
			}
			else{
				if (control.channel[0] > 0.2){
					//HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,1);
					//HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
					//HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);
					//HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
					PWM_SetDutyRatio(&pwm2[1],1);
					PWM_SetDutyRatio(&pwm2[2],1);
				}
				if (control.channel[0] < -0.2){
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,0);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
					PWM_SetDutyRatio(&pwm2[1],1);
					PWM_SetDutyRatio(&pwm2[2],1);
				}
				else {
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
					PWM_SetDutyRatio(&pwm2[1],1);
					PWM_SetDutyRatio(&pwm2[2],1);
				}
			}
		}
			//!!!!!This is trace module!!!!!! Don't use controller part at the same time!!!!!!!!!!!!! 
		
		
		
		if (control.triSwitch[0] == 1){
			
			if (i) {
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
					PWM_SetDutyRatio(&pwm2[1],0.25);
					PWM_SetDutyRatio(&pwm2[2],0.25);
					delay(3000);
				
					float temp_delt_2 = -0.85;
					int j = 10;
					while(temp_delt_2 < 0.15){
						temp_delt_2 = temp_delt_2+0.1;
						angle_0=200*(temp_delt_2+1);
						PWM_SetDutyRatio(&pwm2[3],AngleToDuty1(angle_0));
						if(j < 100){
							j = j+5;
						}
						delay(j);
					}
					delay(2500);
					PWM_SetDutyRatio(&pwm2[3],AngleToDuty1(30));
					
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,0);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
					PWM_SetDutyRatio(&pwm2[1],1);
					PWM_SetDutyRatio(&pwm2[2],1);
					i = 0;
					delay(2000);
					
					//stop
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,0);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
					PWM_SetDutyRatio(&pwm2[1],1);
					PWM_SetDutyRatio(&pwm2[2],1);
				}
			}
			
			/*
			if (i){
				if (adc_data[0].data > 2000 && adc_data[3].data < 2100 && adc_data[5].data > 2100){
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
					PWM_SetDutyRatio(&pwm2[1],0.25);
					PWM_SetDutyRatio(&pwm2[2],0.25);
					delay(20);
				}//on the right way
				if (adc_data[0].data < 2000 && adc_data[3].data < 2100 && adc_data[5].data > 2100){
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
					PWM_SetDutyRatio(&pwm2[1],0.25);
					PWM_SetDutyRatio(&pwm2[2],0.25);
					delay(20);
				}//a little 
				if (adc_data[0].data > 2000 && adc_data[3].data < 2100 && adc_data[5].data < 2100){
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
					PWM_SetDutyRatio(&pwm2[1] ,0.25);
					PWM_SetDutyRatio(&pwm2[2],0.25);
					delay(20);
				}// a little
				if (adc_data[0].data < 2000 && adc_data[3].data < 2100 && adc_data[5].data < 2100){
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
					PWM_SetDutyRatio(&pwm2[1],0.25);
					PWM_SetDutyRatio(&pwm2[2],0.25);
					i = 0;
				}//parallel black !stop
				if (adc_data[0].data < 2000 && adc_data[3].data > 2100 && adc_data[5].data > 2100){
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,0);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
					PWM_SetDutyRatio(&pwm2[1],1);
					PWM_SetDutyRatio(&pwm2[2],1);
					delay(20);
				}// adjustion
				if (adc_data[0].data > 2000 && adc_data[3].data > 2100 && adc_data[5].data < 2100){
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
					PWM_SetDutyRatio(&pwm2[1],1);
					PWM_SetDutyRatio(&pwm2[2],1);
					delay(20);
				}// adjustion
				if (adc_data[0].data > 2000 && adc_data[3].data > 2100 && adc_data[5].data > 2100){
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
					PWM_SetDutyRatio(&pwm2[1],0.25);
					PWM_SetDutyRatio(&pwm2[2],0.25);
					delay(20);
				}// white space !stop
				if (adc_data[0].data < 2000 && adc_data[3].data > 2100 && adc_data[5].data < 2100){
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,0);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
					PWM_SetDutyRatio(&pwm2[1],0.25);
					PWM_SetDutyRatio(&pwm2[2],0.25);
					delay(20);
				}
				
				if (i == 0){
					float temp_delt_2 = -0.85;
					int j = 10;
					while(temp_delt_2 < 0.15){
						temp_delt_2 = temp_delt_2+0.1;
						angle_0=200*(temp_delt_2+1);
						PWM_SetDutyRatio(&pwm2[3],AngleToDuty1(angle_0));
						if(j < 100){
							j = j+5;
						}
						delay(j);
					}
					delay(2000);
					PWM_SetDutyRatio(&pwm2[3],AngleToDuty1(30));
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,0);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
					PWM_SetDutyRatio(&pwm2[1],1);
					PWM_SetDutyRatio(&pwm2[2],1);
					i = 1;
					delay(3000);
				}
				
				
			}
			*/
		}
		
			//HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,0);
			//HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,0);
			
			//HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,0);
			//HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,0);
			if (control.triSwitch[0] == 2){
				PWM_SetDutyRatio(&pwm1[4],1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
					PWM_SetDutyRatio(&pwm2[1],0.25);
					PWM_SetDutyRatio(&pwm2[2],0.25);
			}		
		/* USER CODE END */
		delay(5);
		}



/* Private functions ---------------------------------------------------------*/
/*	Remember to declare your functions at the beginning of this file and in the .h file */
/* USER CODE BEGIN PF */

/* USER CODE END PF */
