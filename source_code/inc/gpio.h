#ifndef GPIO_H_
#define GPIO_H_

//#include "system_stm32f4xx.h"
#include "reg_access.h"
#include "memory_map.h"

/* GPIO port base addresses (for convenience) */
/** @defgroup gpio_port_id GPIO Port IDs
@ingroup gpio_defines

@{*/
#define GPIOA				GPIO_PORT_A_BASE
#define GPIOB				GPIO_PORT_B_BASE
#define GPIOC				GPIO_PORT_C_BASE
#define GPIOD				GPIO_PORT_D_BASE
#define GPIOE				GPIO_PORT_E_BASE
#define GPIOF				GPIO_PORT_F_BASE
#define GPIOG				GPIO_PORT_G_BASE
#define GPIOH				GPIO_PORT_H_BASE
#define GPIOI				GPIO_PORT_I_BASE

/**@}*/


/* --- GPIO_LCKR values ---------------------------------------------------- */

#define GPIO_LCKK			(1 << 16)
/* GPIO_LCKR[15:0]: LCKy: Port x lock bit y (y = 0..15) */

/* GPIO number definitions (for convenience) */
/** @defgroup gpio_pin_id GPIO Pin Identifiers
@ingroup gpio_defines

@{*/
#define GPIO0				(1 << 0)
#define GPIO1				(1 << 1)
#define GPIO2				(1 << 2)
#define GPIO3				(1 << 3)
#define GPIO4				(1 << 4)
#define GPIO5				(1 << 5)
#define GPIO6				(1 << 6)
#define GPIO7				(1 << 7)
#define GPIO8				(1 << 8)
#define GPIO9				(1 << 9)
#define GPIO10				(1 << 10)
#define GPIO11				(1 << 11)
#define GPIO12				(1 << 12)
#define GPIO13				(1 << 13)
#define GPIO14				(1 << 14)
#define GPIO15				(1 << 15)
#define GPIO_ALL			0xffff


#define PIN0          0
#define PIN1          1
#define PIN2          2
#define PIN3          3 
#define PIN4          4
#define PIN5          5
#define PIN6          6
#define PIN7          7
#define PIN8          8
#define PIN9          9
#define PIN10          10
#define PIN11          11
#define PIN12          12
#define PIN13          13
#define PIN14          14
#define PIN15          15

/* --- GPIO registers for STM32F2, STM32F3 and STM32F4 --------------------- */

/* Port mode register (GPIOx_MODER) */
#define GPIO_MODER(port)		((port) + 0x00)
#define GPIOA_MODER			GPIO_MODER(GPIOA)
#define GPIOB_MODER			GPIO_MODER(GPIOB)
#define GPIOC_MODER			GPIO_MODER(GPIOC)
#define GPIOD_MODER			GPIO_MODER(GPIOD)
#define GPIOE_MODER			GPIO_MODER(GPIOE)
#define GPIOF_MODER			GPIO_MODER(GPIOF)
#define GPIOG_MODER			GPIO_MODER(GPIOG)
#define GPIOH_MODER			GPIO_MODER(GPIOH)
#define GPIOI_MODER			GPIO_MODER(GPIOI)

/* Port output type register (GPIOx_OTYPER) */
#define GPIO_OTYPER(port)		((port) + 0x04)
#define GPIOA_OTYPER			GPIO_OTYPER(GPIOA)
#define GPIOB_OTYPER			GPIO_OTYPER(GPIOB)
#define GPIOC_OTYPER			GPIO_OTYPER(GPIOC)
#define GPIOD_OTYPER			GPIO_OTYPER(GPIOD)
#define GPIOE_OTYPER			GPIO_OTYPER(GPIOE)
#define GPIOF_OTYPER			GPIO_OTYPER(GPIOF)
#define GPIOG_OTYPER			GPIO_OTYPER(GPIOG)
#define GPIOH_OTYPER			GPIO_OTYPER(GPIOH)
#define GPIOI_OTYPER			GPIO_OTYPER(GPIOI)

/* Port output speed register (GPIOx_OSPEEDR) */
#define GPIO_OSPEEDR(port)		((port) + 0x08)
#define GPIOA_OSPEEDR			GPIO_OSPEEDR(GPIOA)
#define GPIOB_OSPEEDR			GPIO_OSPEEDR(GPIOB)
#define GPIOC_OSPEEDR			GPIO_OSPEEDR(GPIOC)
#define GPIOD_OSPEEDR			GPIO_OSPEEDR(GPIOD)
#define GPIOE_OSPEEDR			GPIO_OSPEEDR(GPIOE)
#define GPIOF_OSPEEDR			GPIO_OSPEEDR(GPIOF)
#define GPIOG_OSPEEDR			GPIO_OSPEEDR(GPIOG)
#define GPIOH_OSPEEDR			GPIO_OSPEEDR(GPIOH)
#define GPIOI_OSPEEDR			GPIO_OSPEEDR(GPIOI)

/* Port pull-up/pull-down register (GPIOx_PUPDR) */
#define GPIO_PUPDR(port)		((port) + 0x0c)
#define GPIOA_PUPDR			GPIO_PUPDR(GPIOA)
#define GPIOB_PUPDR			GPIO_PUPDR(GPIOB)
#define GPIOC_PUPDR			GPIO_PUPDR(GPIOC)
#define GPIOD_PUPDR			GPIO_PUPDR(GPIOD)
#define GPIOE_PUPDR			GPIO_PUPDR(GPIOE)
#define GPIOF_PUPDR			GPIO_PUPDR(GPIOF)
#define GPIOG_PUPDR			GPIO_PUPDR(GPIOG)
#define GPIOH_PUPDR			GPIO_PUPDR(GPIOH)
#define GPIOI_PUPDR			GPIO_PUPDR(GPIOI)


/* Port input data register (GPIOx_IDR) */
#define GPIO_IDR(port)			((port) + 0x10)
#define GPIOA_IDR			GPIO_IDR(GPIOA)
#define GPIOB_IDR			GPIO_IDR(GPIOB)
#define GPIOC_IDR			GPIO_IDR(GPIOC)
#define GPIOD_IDR			GPIO_IDR(GPIOD)
#define GPIOE_IDR			GPIO_IDR(GPIOE)
#define GPIOF_IDR			GPIO_IDR(GPIOF)
#define GPIOG_IDR			GPIO_IDR(GPIOG)
#define GPIOH_IDR			GPIO_IDR(GPIOH)
#define GPIOI_IDR			GPIO_IDR(GPIOI)

/* Port output data register (GPIOx_ODR) */
#define GPIO_ODR(port)			((port) + 0x14)
#define GPIOA_ODR			GPIO_ODR(GPIOA)
#define GPIOB_ODR			GPIO_ODR(GPIOB)
#define GPIOC_ODR			GPIO_ODR(GPIOC)
#define GPIOD_ODR			GPIO_ODR(GPIOD)
#define GPIOE_ODR			GPIO_ODR(GPIOE)
#define GPIOF_ODR			GPIO_ODR(GPIOF)
#define GPIOG_ODR			GPIO_ODR(GPIOG)
#define GPIOH_ODR			GPIO_ODR(GPIOH)
#define GPIOI_ODR			GPIO_ODR(GPIOI)

/* Port bit set/reset register (GPIOx_BSRR) */
#define GPIO_BSRR(port)			((port) + 0x18)
#define GPIOA_BSRR			GPIO_BSRR(GPIOA)
#define GPIOB_BSRR			GPIO_BSRR(GPIOB)
#define GPIOC_BSRR			GPIO_BSRR(GPIOC)
#define GPIOD_BSRR			GPIO_BSRR(GPIOD)
#define GPIOE_BSRR			GPIO_BSRR(GPIOE)
#define GPIOF_BSRR			GPIO_BSRR(GPIOF)
#define GPIOG_BSRR			GPIO_BSRR(GPIOG)
#define GPIOH_BSRR			GPIO_BSRR(GPIOH)
#define GPIOI_BSRR			GPIO_BSRR(GPIOI)

/* Port configuration lock register (GPIOx_LCKR) */
#define GPIO_LCKR(port)			((port) + 0x1c)
#define GPIOA_LCKR			GPIO_LCKR(GPIOA)
#define GPIOB_LCKR			GPIO_LCKR(GPIOB)
#define GPIOC_LCKR			GPIO_LCKR(GPIOC)
#define GPIOD_LCKR			GPIO_LCKR(GPIOD)
#define GPIOE_LCKR			GPIO_LCKR(GPIOE)
#define GPIOF_LCKR			GPIO_LCKR(GPIOF)
#define GPIOG_LCKR			GPIO_LCKR(GPIOG)
#define GPIOH_LCKR			GPIO_LCKR(GPIOH)
#define GPIOI_LCKR			GPIO_LCKR(GPIOI)

/* Alternate function low register (GPIOx_AFRL) */
#define GPIO_AFRL(port)			((port) + 0x20)
#define GPIOA_AFRL			GPIO_AFRL(GPIOA)
#define GPIOB_AFRL			GPIO_AFRL(GPIOB)
#define GPIOC_AFRL			GPIO_AFRL(GPIOC)
#define GPIOD_AFRL			GPIO_AFRL(GPIOD)
#define GPIOE_AFRL			GPIO_AFRL(GPIOE)
#define GPIOF_AFRL			GPIO_AFRL(GPIOF)
#define GPIOG_AFRL			GPIO_AFRL(GPIOG)
#define GPIOH_AFRL			GPIO_AFRL(GPIOH)
#define GPIOI_AFRL			GPIO_AFRL(GPIOI)

/* Alternate function high register (GPIOx_AFRH) */
#define GPIO_AFRH(port)			((port) + 0x24)
#define GPIOA_AFRH			GPIO_AFRH(GPIOA)
#define GPIOB_AFRH			GPIO_AFRH(GPIOB)
#define GPIOC_AFRH			GPIO_AFRH(GPIOC)
#define GPIOD_AFRH			GPIO_AFRH(GPIOD)
#define GPIOE_AFRH			GPIO_AFRH(GPIOE)
#define GPIOF_AFRH			GPIO_AFRH(GPIOF)
#define GPIOG_AFRH			GPIO_AFRH(GPIOG)
#define GPIOH_AFRH			GPIO_AFRH(GPIOH)
#define GPIOI_AFRH			GPIO_AFRH(GPIOI)

/* --- GPIOx_MODER values -------------------------------------------------- */

#define GPIO_MODE(n, mode)		((mode) << (2 * (n)))
#define GPIO_MODE_MASK(n)		(0x3 << (2 * (n)))
/** @defgroup gpio_mode GPIO Pin Direction and Analog/Digital Mode
@ingroup gpio_defines
@{*/
#define GPIO_MODE_INPUT			0x0
#define GPIO_MODE_OUTPUT		0x1
#define GPIO_MODE_AF			0x2
#define GPIO_MODE_ANALOG		0x3
/**@}*/

/* --- GPIOx_OTYPER values ------------------------------------------------- */

/** @defgroup gpio_output_type GPIO Output Pin Driver Type
@ingroup gpio_defines
@list Push Pull
@list Open Drain
@{*/
#define GPIO_OTYPE_PP			0x0
#define GPIO_OTYPE_OD			0x1
/**@}*/

/* --- GPIOx_OSPEEDR values ------------------------------------------------ */

#define GPIO_OSPEED(n, speed)		((speed) << (2 * (n)))
#define GPIO_OSPEED_MASK(n)		(0x3 << (2 * (n)))
/** @defgroup gpio_speed GPIO Output Pin Speed
@ingroup gpio_defines
@{*/
#define GPIO_OSPEED_2MHZ		0x0
#define GPIO_OSPEED_25MHZ		0x1
#define GPIO_OSPEED_50MHZ		0x2
#define GPIO_OSPEED_100MHZ		0x3
/**@}*/

/* --- GPIOx_PUPDR values -------------------------------------------------- */

#define GPIO_PUPD(n, pupd)		((pupd) << (2 * (n)))
#define GPIO_PUPD_MASK(n)		(0x3 << (2 * (n)))
/** @defgroup gpio_pup GPIO Output Pin Pullup
@ingroup gpio_defines
@{*/
#define GPIO_PUPD_NONE			0x0
#define GPIO_PUPD_PULLUP		0x1
#define GPIO_PUPD_PULLDOWN		0x2
/**@}*/

/* --- GPIOx_IDR values ---------------------------------------------------- */

/* GPIOx_IDR[15:0]: IDRy[15:0]: Port input data (y = 0..15) */

/* --- GPIOx_ODR values ---------------------------------------------------- */

/* GPIOx_ODR[15:0]: ODRy[15:0]: Port output data (y = 0..15) */

/* --- GPIOx_BSRR values --------------------------------------------------- */

/* GPIOx_BSRR[31:16]: BRy: Port x reset bit y (y = 0..15) */
/* GPIOx_BSRR[15:0]: BSy: Port x set bit y (y = 0..15) */

/* --- GPIOx_LCKR values --------------------------------------------------- */

#define GPIO_LCKK			(1 << 16)
/* GPIOx_LCKR[15:0]: LCKy: Port x lock bit y (y = 0..15) */

/* --- GPIOx_AFRL/H values ------------------------------------------------- */

/* Note: AFRL is used for bits 0..7, AFRH is used for 8..15 */
/* See datasheet table 6 (pg. 48) for alternate function mappings. */

#define GPIO_AFR(n, af)			((af) << ((n) * 4))
#define GPIO_AFR_MASK(n)		(0xf << ((n) * 4))
/** @defgroup gpio_af_num Alternate Function Pin Selection
@ingroup gpio_defines
@{*/
#define GPIO_AF0			0x0
#define GPIO_AF1			0x1
#define GPIO_AF2			0x2
#define GPIO_AF3			0x3
#define GPIO_AF4			0x4
#define GPIO_AF5			0x5
#define GPIO_AF6			0x6
#define GPIO_AF7			0x7
#define GPIO_AF8			0x8
#define GPIO_AF9			0x9
#define GPIO_AF10			0xa
#define GPIO_AF11			0xb
#define GPIO_AF12			0xc
#define GPIO_AF13			0xd
#define GPIO_AF14			0xe
#define GPIO_AF15			0xf
/**@}*/

/* Note: EXTI source selection is now in the SYSCFG peripheral. */

template <typename addr_type,
          typename reg_type,
          const addr_type port,
          const reg_type bpos>
class port_pin
{
  public:
    static void set_direction_output()
    {
      port_dir_type::bit_set();
    }

    static void set_direction_input()
    {
      port_dir_type::bit_clr();
    }

    static void set_pin_high()
    {
      port_out_type::bit_set();
    }

    static void set_pin_low()
    {
      port_out_type::bit_clr();
    }

    static bool read_input_value()
    {
      return port_inp_type::bit_get();
    }

    static void toggle()
    {
      port_out_type::bit_not();
    }

  private:
    static constexpr addr_type pmode  = GPIO_MODER(port);
    static constexpr addr_type pinp   = GPIO_IDR(port);
    static constexpr addr_type pout   = GPIO_ODR(port);

    // type definition of the port mode register
    typedef reg_access<addr_type,
                       reg_type,
                       pmode,
                       (bpos * 2)> port_dir_type;

    // type definition of the port data register
    typedef reg_access<addr_type,
                       reg_type,
                       pout,
                       bpos> port_out_type;

    // type definition of the port input register
    typedef reg_access<addr_type,
                       reg_type,
                       pinp,
                       bpos> port_inp_type;
};

#endif