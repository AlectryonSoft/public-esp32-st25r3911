#ifndef PLATFORM_INTERRUPT_H
#define PLATFORM_INTERRUPT_H

#ifdef __cplusplus
extern "C" {
#endif

/*! 
 *****************************************************************************
 * \brief  This function setups the Interrupt for the RFAL
 *  
 * 
 *****************************************************************************
 */
void interrupt_init(void);

/*! 
 *****************************************************************************
 * \brief  To protect interrupt status variable  of RFAL 
 *  
 * This method acquire a mutex before assigning new value to interrupt status
 * variable.
 * 
 *****************************************************************************
 */
void pltf_protect_interrupt_status(void);

/*! 
 *****************************************************************************
 * \brief  To protect interrupt status variable  of RFAL 
 *  
 * This method release the mutex after assigning new value to interrupt status
 * variable.
 * 
 *****************************************************************************
 */
void pltf_unprotect_interrupt_status(void); 

#ifdef __cplusplus
}
#endif

#endif /* PLATFORM_INTERRUPT_H */