/**
  ******************************************************************************
  * @file    py32f4xx_hal_dma.h
  * @author  MCU Application Team
  * @brief   Header file of DMA HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) Puya Semiconductor Co.
  * All rights reserved.</center></h2>
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PY32F4XX_HAL_DMA_H
#define __PY32F4XX_HAL_DMA_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32f4xx_hal_def.h"

/** @addtogroup PY32F4xx_HAL_Driver
  * @{
  */

/** @addtogroup DMA
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/** @defgroup DMA_Exported_Types DMA Exported Types
  * @{
  */

/**
  * @brief  DMA Configuration Structure definition
  */
typedef struct
{
  uint32_t Direction;                 /*!< Specifies if the data will be transferred from memory to peripheral, 
                                           from memory to memory or from peripheral to memory.
                                           This parameter can be a value of @ref DMA_Data_transfer_direction */

  uint32_t PeriphInc;                 /*!< Specifies whether the Peripheral address register should be incremented or not.
                                           This parameter can be a value of @ref DMA_Peripheral_incremented_mode */

  uint32_t MemInc;                    /*!< Specifies whether the memory address register should be incremented or not.
                                           This parameter can be a value of @ref DMA_Memory_incremented_mode */

  uint32_t PeriphDataAlignment;       /*!< Specifies the Peripheral data width.
                                           This parameter can be a value of @ref DMA_Peripheral_data_size */

  uint32_t MemDataAlignment;          /*!< Specifies the Memory data width.
                                           This parameter can be a value of @ref DMA_Memory_data_size */

  uint32_t Mode;                      /*!< Specifies the operation mode of the DMAy Channelx.
                                           This parameter can be a value of @ref DMA_mode
                                           @note The circular buffer mode cannot be used if the memory-to-memory
                                                 data transfer is configured on the selected Channel */

  uint32_t Priority;                  /*!< Specifies the software priority for the DMAy Channelx.
                                           This parameter can be a value of @ref DMA_Priority_level */
} DMA_InitTypeDef;

/**
  * @brief  HAL DMA State structures definition
  */
typedef enum
{
  HAL_DMA_STATE_RESET             = 0x00U,  /*!< DMA not yet initialized or disabled    */
  HAL_DMA_STATE_READY             = 0x01U,  /*!< DMA initialized and ready for use      */
  HAL_DMA_STATE_BUSY              = 0x02U,  /*!< DMA process is ongoing                 */
  HAL_DMA_STATE_TIMEOUT           = 0x03U   /*!< DMA timeout state                      */
}HAL_DMA_StateTypeDef;

/**
  * @brief  HAL DMA Error Code structure definition
  */
typedef enum
{
  HAL_DMA_FULL_TRANSFER           = 0x00U,    /*!< Full transfer     */
  HAL_DMA_HALF_TRANSFER           = 0x01U     /*!< Half Transfer     */
}HAL_DMA_LevelCompleteTypeDef;

/** 
  * @brief  HAL DMA Callback ID structure definition
  */
typedef enum
{
  HAL_DMA_XFER_CPLT_CB_ID          = 0x00U,    /*!< Full transfer     */
  HAL_DMA_XFER_HALFCPLT_CB_ID      = 0x01U,    /*!< Half transfer     */
  HAL_DMA_XFER_ERROR_CB_ID         = 0x02U,    /*!< Error             */ 
  HAL_DMA_XFER_ABORT_CB_ID         = 0x03U,    /*!< Abort             */ 
  HAL_DMA_XFER_ALL_CB_ID           = 0x04U     /*!< All               */ 
    
}HAL_DMA_CallbackIDTypeDef;

/** 
  * @brief  DMA handle Structure definition
  */
typedef struct __DMA_HandleTypeDef
{
  DMA_Channel_TypeDef   *Instance;                       /*!< Register base address                  */
  
  DMA_InitTypeDef       Init;                            /*!< DMA communication parameters           */ 
  
  HAL_LockTypeDef       Lock;                            /*!< DMA locking object                     */  
  
  HAL_DMA_StateTypeDef  State;                           /*!< DMA transfer state                     */
  
  void                  *Parent;                                                      /*!< Parent object state                    */  
  
  void                  (* XferCpltCallback)( struct __DMA_HandleTypeDef * hdma);     /*!< DMA transfer complete callback         */
  
  void                  (* XferHalfCpltCallback)( struct __DMA_HandleTypeDef * hdma); /*!< DMA Half transfer complete callback    */
  
  void                  (* XferErrorCallback)( struct __DMA_HandleTypeDef * hdma);    /*!< DMA transfer error callback            */

  void                  (* XferAbortCallback)( struct __DMA_HandleTypeDef * hdma);    /*!< DMA transfer abort callback            */  
  
  __IO uint32_t         ErrorCode;                                                    /*!< DMA Error code                         */

  DMA_TypeDef            *DmaBaseAddress;                                             /*!< DMA Channel Base Address               */
  
  uint32_t               ChannelIndex;                                                /*!< DMA Channel Index                      */  

} DMA_HandleTypeDef;    
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup DMA_Exported_Constants DMA Exported Constants
  * @{
  */

/** @defgroup DMA_Error_Code DMA Error Code
  * @{
  */
#define HAL_DMA_ERROR_NONE                     0x00000000U    /*!< No error             */
#define HAL_DMA_ERROR_TE                       0x00000001U    /*!< Transfer error       */
#define HAL_DMA_ERROR_NO_XFER                  0x00000004U    /*!< no ongoing transfer  */
#define HAL_DMA_ERROR_TIMEOUT                  0x00000020U    /*!< Timeout error        */
#define HAL_DMA_ERROR_NOT_SUPPORTED            0x00000100U    /*!< Not supported mode   */ 
/**
  * @}
  */

/** @defgroup DMA_Data_transfer_direction DMA Data transfer direction
  * @{
  */
#define DMA_PERIPH_TO_MEMORY         0x00000000U                 /*!< Peripheral to memory direction */
#define DMA_MEMORY_TO_PERIPH         ((uint32_t)DMA_CCR_DIR)     /*!< Memory to peripheral direction */
#define DMA_MEMORY_TO_MEMORY         ((uint32_t)DMA_CCR_MEM2MEM) /*!< Memory to memory direction     */

/**
  * @}
  */

/** @defgroup DMA_Peripheral_incremented_mode DMA Peripheral incremented mode
  * @{
  */
#define DMA_PINC_ENABLE        ((uint32_t)DMA_CCR_PINC)  /*!< Peripheral increment mode Enable */
#define DMA_PINC_DISABLE       0x00000000U               /*!< Peripheral increment mode Disable */
/**
  * @}
  */

/** @defgroup DMA_Memory_incremented_mode DMA Memory incremented mode
  * @{
  */
#define DMA_MINC_ENABLE         ((uint32_t)DMA_CCR_MINC)  /*!< Memory increment mode Enable  */
#define DMA_MINC_DISABLE        0x00000000U               /*!< Memory increment mode Disable */
/**
  * @}
  */

/** @defgroup DMA_Peripheral_data_size DMA Peripheral data size
  * @{
  */
#define DMA_PDATAALIGN_BYTE          0x00000000U                  /*!< Peripheral data alignment: Byte     */
#define DMA_PDATAALIGN_HALFWORD      ((uint32_t)DMA_CCR_PSIZE_0)  /*!< Peripheral data alignment: HalfWord */
#define DMA_PDATAALIGN_WORD          ((uint32_t)DMA_CCR_PSIZE_1)  /*!< Peripheral data alignment: Word     */
/**
  * @}
  */

/** @defgroup DMA_Memory_data_size DMA Memory data size
  * @{
  */
#define DMA_MDATAALIGN_BYTE          0x00000000U                  /*!< Memory data alignment: Byte     */
#define DMA_MDATAALIGN_HALFWORD      ((uint32_t)DMA_CCR_MSIZE_0)  /*!< Memory data alignment: HalfWord */
#define DMA_MDATAALIGN_WORD          ((uint32_t)DMA_CCR_MSIZE_1)  /*!< Memory data alignment: Word     */
/**
  * @}
  */

/** @defgroup DMA_mode DMA mode
  * @{
  */
#define DMA_NORMAL         0x00000000U                  /*!< Normal mode   */
#define DMA_CIRCULAR       ((uint32_t)DMA_CCR_CIRC)     /*!< Circular mode */
/**
  * @}
  */

/** @defgroup DMA_Priority_level DMA Priority level
  * @{
  */
#define DMA_PRIORITY_LOW             0x00000000U               /*!< Priority level : Low       */
#define DMA_PRIORITY_MEDIUM          ((uint32_t)DMA_CCR_PL_0)  /*!< Priority level : Medium    */
#define DMA_PRIORITY_HIGH            ((uint32_t)DMA_CCR_PL_1)  /*!< Priority level : High      */
#define DMA_PRIORITY_VERY_HIGH       ((uint32_t)DMA_CCR_PL)    /*!< Priority level : Very_High */
/**
  * @}
  */


/** @defgroup DMA_interrupt_enable_definitions DMA interrupt enable definitions
  * @{
  */
#define DMA_IT_TC                         ((uint32_t)DMA_CCR_TCIE)
#define DMA_IT_HT                         ((uint32_t)DMA_CCR_HTIE)
#define DMA_IT_TE                         ((uint32_t)DMA_CCR_TEIE)
/**
  * @}
  */

/** @defgroup DMA_flag_definitions DMA flag definitions
  * @{
  */
#define DMA_FLAG_GL1                      0x00000001U
#define DMA_FLAG_TC1                      0x00000002U
#define DMA_FLAG_HT1                      0x00000004U
#define DMA_FLAG_TE1                      0x00000008U
#define DMA_FLAG_GL2                      0x00000010U
#define DMA_FLAG_TC2                      0x00000020U
#define DMA_FLAG_HT2                      0x00000040U
#define DMA_FLAG_TE2                      0x00000080U
#define DMA_FLAG_GL3                      0x00000100U
#define DMA_FLAG_TC3                      0x00000200U
#define DMA_FLAG_HT3                      0x00000400U
#define DMA_FLAG_TE3                      0x00000800U
#define DMA_FLAG_GL4                      0x00001000U
#define DMA_FLAG_TC4                      0x00002000U
#define DMA_FLAG_HT4                      0x00004000U
#define DMA_FLAG_TE4                      0x00008000U
#define DMA_FLAG_GL5                      0x00010000U
#define DMA_FLAG_TC5                      0x00020000U
#define DMA_FLAG_HT5                      0x00040000U
#define DMA_FLAG_TE5                      0x00080000U
#define DMA_FLAG_GL6                      0x00100000U
#define DMA_FLAG_TC6                      0x00200000U
#define DMA_FLAG_HT6                      0x00400000U
#define DMA_FLAG_TE6                      0x00800000U
#define DMA_FLAG_GL7                      0x01000000U
#define DMA_FLAG_TC7                      0x02000000U
#define DMA_FLAG_HT7                      0x04000000U
#define DMA_FLAG_TE7                      0x08000000U
/**
  * @}
  */

/** @defgroup DMA_Channel_map DMA Channel map
  * @{
  */
#define DMA_CHANNEL_MAP_ADC1              0x00000000U
#define DMA_CHANNEL_MAP_ADC2              0x00000001U
#define DMA_CHANNEL_MAP_ADC3              0x00000002U
#if defined(DAC1)
#define DMA_CHANNEL_MAP_DAC1              0x00000003U
#define DMA_CHANNEL_MAP_DAC2              0x00000004U
#endif /* DAC1 */
#define DMA_CHANNEL_MAP_SPI1_RD           0x00000005U
#define DMA_CHANNEL_MAP_SPI1_WR           0x00000006U
#define DMA_CHANNEL_MAP_SPI2_RD           0x00000007U
#define DMA_CHANNEL_MAP_SPI2_WR           0x00000008U
#define DMA_CHANNEL_MAP_SPI3_RD           0x00000009U
#define DMA_CHANNEL_MAP_SPI3_WR           0x0000000AU
#define DMA_CHANNEL_MAP_USART1_RD         0x0000000BU
#define DMA_CHANNEL_MAP_USART1_WR         0x0000000CU
#define DMA_CHANNEL_MAP_USART2_RD         0x0000000DU
#define DMA_CHANNEL_MAP_USART2_WR         0x0000000EU
#define DMA_CHANNEL_MAP_USART3_RD         0x0000000FU
#define DMA_CHANNEL_MAP_USART3_WR         0x00000010U
#define DMA_CHANNEL_MAP_USART4_RD         0x00000011U
#define DMA_CHANNEL_MAP_USART4_WR         0x00000012U
#define DMA_CHANNEL_MAP_USART5_RD         0x00000013U
#define DMA_CHANNEL_MAP_USART5_WR         0x00000014U
#define DMA_CHANNEL_MAP_I2C1_RD           0x00000015U
#define DMA_CHANNEL_MAP_I2C1_WR           0x00000016U
#define DMA_CHANNEL_MAP_I2C2_RD           0x00000017U
#define DMA_CHANNEL_MAP_I2C2_WR           0x00000018U
#define DMA_CHANNEL_MAP_TIM1_CH1          0x00000019U
#define DMA_CHANNEL_MAP_TIM1_CH2          0x0000001AU
#define DMA_CHANNEL_MAP_TIM1_CH3          0x0000001BU
#define DMA_CHANNEL_MAP_TIM1_CH4          0x0000001CU
#define DMA_CHANNEL_MAP_TIM1_COM          0x0000001DU
#define DMA_CHANNEL_MAP_TIM1_TRIG         0x0000001EU
#define DMA_CHANNEL_MAP_TIM1_UP           0x0000001FU
#define DMA_CHANNEL_MAP_TIM2_CH1          0x00000020U
#define DMA_CHANNEL_MAP_TIM2_CH2          0x00000021U
#define DMA_CHANNEL_MAP_TIM2_CH3          0x00000022U
#define DMA_CHANNEL_MAP_TIM2_CH4          0x00000023U
#define DMA_CHANNEL_MAP_TIM2_UP           0x00000024U
#define DMA_CHANNEL_MAP_TIM3_CH1          0x00000025U
#define DMA_CHANNEL_MAP_TIM3_CH3          0x00000026U
#define DMA_CHANNEL_MAP_TIM3_CH4          0x00000027U
#define DMA_CHANNEL_MAP_TIM3_UP           0x00000028U
#define DMA_CHANNEL_MAP_TIM3_TRIG         0x00000029U
#define DMA_CHANNEL_MAP_TIM4_CH1          0x0000002AU
#define DMA_CHANNEL_MAP_TIM4_CH2          0x0000002BU
#define DMA_CHANNEL_MAP_TIM4_CH3          0x0000002CU
#define DMA_CHANNEL_MAP_TIM4_UP           0x0000002DU
#define DMA_CHANNEL_MAP_TIM5_CH1          0x0000002EU
#define DMA_CHANNEL_MAP_TIM5_CH2          0x0000002FU
#define DMA_CHANNEL_MAP_TIM5_CH3          0x00000030U
#define DMA_CHANNEL_MAP_TIM5_CH4          0x00000031U
#define DMA_CHANNEL_MAP_TIM5_UP           0x00000032U
#define DMA_CHANNEL_MAP_TIM5_TRIG         0x00000033U
#define DMA_CHANNEL_MAP_TIM6              0x00000034U
#define DMA_CHANNEL_MAP_TIM7              0x00000035U
#define DMA_CHANNEL_MAP_TIM8_CH1          0x00000036U
#define DMA_CHANNEL_MAP_TIM8_CH2          0x00000037U
#define DMA_CHANNEL_MAP_TIM8_CH3          0x00000038U
#define DMA_CHANNEL_MAP_TIM8_CH4          0x00000039U
#define DMA_CHANNEL_MAP_TIM8_COM          0x0000003AU
#define DMA_CHANNEL_MAP_TIM8_TRIG         0x0000003BU
#define DMA_CHANNEL_MAP_TIM8_UP           0x0000003CU
#define DMA_CHANNEL_MAP_TIM2_TRIG         0x0000003DU
#define DMA_CHANNEL_MAP_TIM3_CH2          0x0000003EU
#define DMA_CHANNEL_MAP_TIM4_CH4          0x0000003FU
#define DMA_CHANNEL_MAP_TIM4_TRIG         0x00000040U
#define DMA_CHANNEL_MAP_ESMC_TX           0x00000041U
#define DMA_CHANNEL_MAP_ESMC_RX           0x00000042U
#define DMA_CHANNEL_MAP_SDIO              0x00000043U     
#define DMA_CHANNEL_MAP_USB               0x00000044U    


#define DMA_CHANNEL_MAP_END               0x00000045U   
/**
  * @}
  */

/**
  * @}
  */


/* Exported macros -----------------------------------------------------------*/
/** @defgroup DMA_Exported_Macros DMA Exported Macros
  * @{
  */

/** @brief  Reset DMA handle state.
  * @param  __HANDLE__: DMA handle
  * @retval None
  */
#define __HAL_DMA_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_DMA_STATE_RESET)

/**
  * @brief  Enable the specified DMA Channel.
  * @param  __HANDLE__: DMA handle
  * @retval None
  */
#define __HAL_DMA_ENABLE(__HANDLE__)        (SET_BIT((__HANDLE__)->Instance->CCR, DMA_CCR_EN))

/**
  * @brief  Disable the specified DMA Channel.
  * @param  __HANDLE__: DMA handle
  * @retval None
  */
#define __HAL_DMA_DISABLE(__HANDLE__)       (CLEAR_BIT((__HANDLE__)->Instance->CCR, DMA_CCR_EN))


/* Interrupt & Flag management */

/**
  * @brief  Enables the specified DMA Channel interrupts.
  * @param  __HANDLE__: DMA handle
  * @param __INTERRUPT__: specifies the DMA interrupt sources to be enabled or disabled.
  *          This parameter can be any combination of the following values:
  *            @arg DMA_IT_TC:  Transfer complete interrupt mask
  *            @arg DMA_IT_HT:  Half transfer complete interrupt mask
  *            @arg DMA_IT_TE:  Transfer error interrupt mask
  * @retval None
  */
#define __HAL_DMA_ENABLE_IT(__HANDLE__, __INTERRUPT__)   (SET_BIT((__HANDLE__)->Instance->CCR, (__INTERRUPT__)))

/**
  * @brief  Disable the specified DMA Channel interrupts.
  * @param  __HANDLE__: DMA handle
  * @param  __INTERRUPT__: specifies the DMA interrupt sources to be enabled or disabled.
  *          This parameter can be any combination of the following values:
  *            @arg DMA_IT_TC:  Transfer complete interrupt mask
  *            @arg DMA_IT_HT:  Half transfer complete interrupt mask
  *            @arg DMA_IT_TE:  Transfer error interrupt mask
  * @retval None
  */
#define __HAL_DMA_DISABLE_IT(__HANDLE__, __INTERRUPT__)  (CLEAR_BIT((__HANDLE__)->Instance->CCR , (__INTERRUPT__)))

/**
  * @brief  Check whether the specified DMA Channel interrupt is enabled or not.
  * @param  __HANDLE__: DMA handle
  * @param  __INTERRUPT__: specifies the DMA interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg DMA_IT_TC:  Transfer complete interrupt mask
  *            @arg DMA_IT_HT:  Half transfer complete interrupt mask
  *            @arg DMA_IT_TE:  Transfer error interrupt mask
  * @retval The state of DMA_IT (SET or RESET).
  */
#define __HAL_DMA_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)  ((((__HANDLE__)->Instance->CCR & (__INTERRUPT__)) == (__INTERRUPT__)) ? SET : RESET)

/**
  * @brief  Return the number of remaining data units in the current DMA Channel transfer.
  * @param  __HANDLE__: DMA handle
  * @retval The number of remaining data units in the current DMA Channel transfer.
  */
#define __HAL_DMA_GET_COUNTER(__HANDLE__) ((__HANDLE__)->Instance->CNDTR)

/**
  * @}
  */

/* Include DMA HAL Extension module */
#include "py32f4xx_hal_dma_ex.h"   

/* Exported functions --------------------------------------------------------*/
/** @addtogroup DMA_Exported_Functions
  * @{
  */

/** @addtogroup DMA_Exported_Functions_Group1
  * @{
  */
/* Initialization and de-initialization functions *****************************/
HAL_StatusTypeDef HAL_DMA_Init(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_DeInit (DMA_HandleTypeDef *hdma);
/**
  * @}
  */

/** @addtogroup DMA_Exported_Functions_Group2
  * @{
  */
/* IO operation functions *****************************************************/
HAL_StatusTypeDef HAL_DMA_Start (DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMA_Start_IT(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMA_Abort(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_Abort_IT(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_PollForTransfer(DMA_HandleTypeDef *hdma, uint32_t CompleteLevel, uint32_t Timeout);
void HAL_DMA_IRQHandler(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_RegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID, void (* pCallback)( DMA_HandleTypeDef * _hdma));
HAL_StatusTypeDef HAL_DMA_UnRegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID);
void HAL_DMA_ChannelMap(DMA_HandleTypeDef *hdma, uint32_t MapReqNum);

/**
  * @}
  */

/** @addtogroup DMA_Exported_Functions_Group3
  * @{
  */
/* Peripheral State and Error functions ***************************************/
HAL_DMA_StateTypeDef HAL_DMA_GetState(DMA_HandleTypeDef *hdma);
uint32_t HAL_DMA_GetError(DMA_HandleTypeDef *hdma);
/**
  * @}
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup DMA_Private_Macros DMA Private Macros
  * @{
  */

#define IS_DMA_DIRECTION(DIRECTION) (((DIRECTION) == DMA_PERIPH_TO_MEMORY ) || \
                                     ((DIRECTION) == DMA_MEMORY_TO_PERIPH)  || \
                                     ((DIRECTION) == DMA_MEMORY_TO_MEMORY))

#define IS_DMA_BUFFER_SIZE(SIZE) (((SIZE) >= 0x1U) && ((SIZE) < 0x10000U))

#define IS_DMA_PERIPHERAL_INC_STATE(STATE) (((STATE) == DMA_PINC_ENABLE) || \
                                            ((STATE) == DMA_PINC_DISABLE))

#define IS_DMA_MEMORY_INC_STATE(STATE) (((STATE) == DMA_MINC_ENABLE)  || \
                                        ((STATE) == DMA_MINC_DISABLE))

#define IS_DMA_PERIPHERAL_DATA_SIZE(SIZE) (((SIZE) == DMA_PDATAALIGN_BYTE)     || \
                                           ((SIZE) == DMA_PDATAALIGN_HALFWORD) || \
                                           ((SIZE) == DMA_PDATAALIGN_WORD))

#define IS_DMA_MEMORY_DATA_SIZE(SIZE) (((SIZE) == DMA_MDATAALIGN_BYTE)     || \
                                       ((SIZE) == DMA_MDATAALIGN_HALFWORD) || \
                                       ((SIZE) == DMA_MDATAALIGN_WORD ))

#define IS_DMA_MODE(MODE) (((MODE) == DMA_NORMAL )  || \
                           ((MODE) == DMA_CIRCULAR))

#define IS_DMA_PRIORITY(PRIORITY) (((PRIORITY) == DMA_PRIORITY_LOW )   || \
                                   ((PRIORITY) == DMA_PRIORITY_MEDIUM) || \
                                   ((PRIORITY) == DMA_PRIORITY_HIGH)   || \
                                   ((PRIORITY) == DMA_PRIORITY_VERY_HIGH))
 
#define IS_DMA_MAP_VALUE(VALUE) ((VALUE) <  DMA_CHANNEL_MAP_END)  
/**
  * @}
  */ 

/* Private functions ---------------------------------------------------------*/

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PY32F4xx_HAL_DMA_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
