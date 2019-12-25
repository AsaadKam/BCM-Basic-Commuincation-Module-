#include"BCM_PostBConfig.h"

const BCM_Config_t BCM_UART_TX_Trans_Config={BCM_ID_0
                                            ,100
									        ,UART
									        ,BCM_Transimition_Enable
									        ,BCM_Reception_Disable    };
											
const BCM_Config_t BCM_UART_RX_Trans_Config={BCM_ID_0
                                            ,100
									        ,UART
									        ,BCM_Transimition_Disable
									        ,BCM_Reception_Enable    };