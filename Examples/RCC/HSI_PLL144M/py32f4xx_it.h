#ifndef __PY32F4XX_IT_H
#define __PY32F4XX_IT_H

#ifdef __cplusplus
 extern "C" {
#endif 


void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* __PY32F4XX_IT_H */
