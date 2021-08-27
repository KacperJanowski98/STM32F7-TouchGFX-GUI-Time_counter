#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "cmsis_os.h"
#include "cmsis_os2.h"
#include "main.h"
#include "stdlib.h"

extern osSemaphoreId_t binarySemLPS25Handle;

extern int16_t result1T;
extern int16_t result2T;
extern int16_t result1P;
extern int16_t result2P;

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	if (binarySemLPS25Handle != NULL)
	{
		if (osSemaphoreAcquire(binarySemLPS25Handle, ( uint32_t ) 10) == osOK)
		{
			lps25hbMsgRdy();
		}
	}
}

void Model::lps25hbMsgRdy()
{
	modelListener->lps25hbMsgRdy(result1T, result2T, result1P, result2P);
}
