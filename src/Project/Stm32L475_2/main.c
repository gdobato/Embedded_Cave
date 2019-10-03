/**
 * @file 
 * @author 
 * @date
 * @brief
 **/

/************************************
* Includes
************************************/
#include <OsAPIs.h>
//#include <core_cm4.h>
#include <system/system.h>
/************************************
* Private definitions 
************************************/

/************************************
* Private type definitions 
************************************/

/************************************
* Private variables
************************************/

/************************************
* Private declarations 
************************************/

int main(void)
{
  System_Init();
  OS_StartOS(APP_MODE_DEFAULT);
  return 0;
}

