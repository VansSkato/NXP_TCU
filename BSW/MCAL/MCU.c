
#include "MCU.h"

void Init_Clock_Ports(void)
{
    /* Enables the clock for PORT0: Enables clock */
    CLOCK_EnableClock(kCLOCK_Port0);

	/* Enables the clock for PORT1: Enables clock */
    CLOCK_EnableClock(kCLOCK_Port1);

    /* Enables the clock for PORT2: Enables clock */
    CLOCK_EnableClock(kCLOCK_Port2);

    /* Enables the clock for PORT3: Enables clock */
    CLOCK_EnableClock(kCLOCK_Port3);

    /* Enables the clock for PORT4: Enables clock */
    CLOCK_EnableClock(kCLOCK_Port4);
}
