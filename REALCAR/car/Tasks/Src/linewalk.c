#include "linewalk.h"
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
double AngleToDuty2(double angle)
{
	return (0.5+angle/180.0*2.0)/20.0;
}

void Linewalk_task(void * arg) {
	/* You can write your own code here */
	/* USER CODE BEGIN */
	
	/* USER CODE END */
	
	PWM_SetFrequency(&pwm1[1],100);
	PWM_SetFrequency(&pwm1[2],100);
	PWM_SetFrequency(&pwm1[3],100);
	PWM_SetFrequency(&pwm1[4],100);
	PWM_SetFrequency(&pwm2[1],100);
	PWM_SetFrequency(&pwm2[2],100);
//	PWM_SetDutyRatio(&pwm2[3],AngleToDuty(angle));
//	PWM_SetDutyRatio(&pwm2[4],AngleToDuty(angle));
		/* You can write your own code here */
		/* USER CODE BEGIN */
		while(1){
			
			
			delay(5);
		}
		delay(5);
}
			