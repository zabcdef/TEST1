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
		if (control.channel[1] > 0.6 && control.channel[0] >= (-0.2) && control.channel[0] <= 0.2){
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,1);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);
			PWM_SetDutyRatio(&pwm2[3], control.channel[1]);
			PWM_SetDutyRatio(&pwm2[4], control.channel[1]);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
			PWM_SetDutyRatio(&pwm2[1], control.channel[1]);
			PWM_SetDutyRatio(&pwm2[2], control.channel[1]);
		}
		else if (control.channel[1] < (-0.6) && control.channel[0] >= (-0.2) && control.channel[0] <= 0.2){
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);  //IN1
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);  //IN2
			float newforward = -1*forward;
			PWM_SetDutyRatio(&pwm2[1], -1*control.channel[1]);  //LEFT BACK
			PWM_SetDutyRatio(&pwm2[2], -1*control.channel[1]);  //RIGHT BACK
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,0);  //IN3
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);	//IN4
			PWM_SetDutyRatio(&pwm2[3], -1*control.channel[1]);  //LEFT FRONT
			PWM_SetDutyRatio(&pwm2[4], -1*control.channel[1]);  //RIGHT FRONT
		}
		else if (control.channel[1] > (-0.2) && control.channel[1] < 0.2){
			if (control.channel[0] > 0.6){
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);  //IN1
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);  //IN2
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,0);  //IN3
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);	//IN4
				PWM_SetDutyRatio(&pwm2[1],control.channel[0]);
				PWM_SetDutyRatio(&pwm2[2],control.channel[0]);
				PWM_SetDutyRatio(&pwm2[3],control.channel[0]);
				PWM_SetDutyRatio(&pwm2[4],control.channel[0]);
				delay(5);
			}
			else if (control.channel[0] < (-0.6)){
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);  //IN1
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);  //IN2
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,1);  //IN3
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);	//IN4
				float newdirection = direction;
				PWM_SetDutyRatio(&pwm2[1],-1*control.channel[0]);
				PWM_SetDutyRatio(&pwm2[2],-1*control.channel[0]);
				PWM_SetDutyRatio(&pwm2[3],-1*control.channel[0]);
				PWM_SetDutyRatio(&pwm2[4],-1*control.channel[0]);
			}
			else if (control.channel[0] >=(-0.2) && control.channel[0]<=0.2){
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);  //IN1
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);  //IN2
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,0);  //IN3
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);	//IN4
				PWM_SetDutyRatio(&pwm2[1],control.channel[0]);
				PWM_SetDutyRatio(&pwm2[2],control.channel[0]);
				PWM_SetDutyRatio(&pwm2[3],control.channel[0]);
				PWM_SetDutyRatio(&pwm2[4],control.channel[0]);
			}
			*/
			
			
			
			
			if (control.channel[1] > 0.2){
				//front
				PWM_SetDutyRatio(&pwm2[1],1);
				PWM_SetDutyRatio(&pwm2[2],0);
				PWM_SetDutyRatio(&pwm2[3],1);
				PWM_SetDutyRatio(&pwm2[4],0);
				//back
				PWM_SetDutyRatio(&pwm1[4],1);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
			}
			if (control.channel[1] < -0.2){
				//
				PWM_SetDutyRatio(&pwm2[1],0);
				PWM_SetDutyRatio(&pwm2[2],1);
				PWM_SetDutyRatio(&pwm2[3],0);
				PWM_SetDutyRatio(&pwm2[4],1);
				//back
				PWM_SetDutyRatio(&pwm1[4],0);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
			}
			else{
				if (control.channel[0] > 0.2){
					PWM_SetDutyRatio(&pwm2[1],1);
					PWM_SetDutyRatio(&pwm2[2],0);				
					PWM_SetDutyRatio(&pwm2[3],0);
					PWM_SetDutyRatio(&pwm2[4],1);
					//back
					PWM_SetDutyRatio(&pwm1[4],1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
				}
				if (control.channel[0] < -0.2){
					
					//front
					PWM_SetDutyRatio(&pwm2[1],0);
					PWM_SetDutyRatio(&pwm2[2],1);
					PWM_SetDutyRatio(&pwm2[3],1);
					PWM_SetDutyRatio(&pwm2[4],0);
					//back
					PWM_SetDutyRatio(&pwm1[4],0);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
				}
				else {
					PWM_SetDutyRatio(&pwm2[1],1);
					PWM_SetDutyRatio(&pwm2[2],1);
					PWM_SetDutyRatio(&pwm2[3],1);
					PWM_SetDutyRatio(&pwm2[4],1);
					//back
					PWM_SetDutyRatio(&pwm1[4],1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
				}
			}
		}
		//PWM_SetDutyRatio(&pwm2[1],1);
		//PWM_SetDutyRatio(&pwm2[2],1);
		//PWM_SetDutyRatio(&pwm2[3],1);
		//PWM_SetDutyRatio(&pwm2[4],1);
		/* USER CODE END */
		delay(5);
}


/* Private functions ---------------------------------------------------------*/
/*	Remember to declare your functions at the beginning of this file and in the .h file */
/* USER CODE BEGIN PF */

/* USER CODE END PF */
