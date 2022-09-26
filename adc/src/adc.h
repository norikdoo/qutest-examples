#ifndef ADC_H
#define ADC_H

#define ADC_CHANNEL_COUNT 2

int ADC_init(void);
uint8_t ADC_read(unsigned int ch);

#endif /* ADC_H */
