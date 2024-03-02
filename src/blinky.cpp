
#include <stm32f103xb.h>
#include <stm32f1xx_hal.h>
#include <stm32f1xx_hal_gpio.h>
#include <stm32f1xx_hal_rcc.h>
#include <stm32f1xx_hal_rcc_ex.h>

// NUCLEO-F103 green led - PA5
#define LED_PORT GPIOA
#define LED_PIN GPIO_PIN_5
#define LED_PORT_CLK_ENABLE __HAL_RCC_GPIOA_CLK_ENABLE

// This prevent name mangling for functions used in C/assembly files.
void SysTick_Handler(void)
{
    HAL_IncTick();

    // 1 Hz blinking
    if ((HAL_GetTick() % 500) == 0)
    {
        HAL_GPIO_TogglePin(LED_PORT, LED_PIN);
    }
}

void initGPIO()
{
    GPIO_InitTypeDef GPIO_Config;

    GPIO_Config.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_Config.Pull = GPIO_NOPULL;
    GPIO_Config.Speed = GPIO_SPEED_FREQ_HIGH;

    GPIO_Config.Pin = LED_PIN;

    LED_PORT_CLK_ENABLE();
    HAL_GPIO_Init(LED_PORT, &GPIO_Config);
}

int main(void)
{
    HAL_Init();
    initGPIO();
    // 1kHz ticks
    HAL_SYSTICK_Config(SystemCoreClock / 1000);

    //HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);

    while (1)
        ;
    return 0;
}