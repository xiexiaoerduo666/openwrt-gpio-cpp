#include "gpio.h"

int main()
{
    GPIO GPIO42;
    GPIO GPIO43;

    GPIO42.GetPinMux();
    GPIO42.SetPinMux("ephy");

    int status;

    status = GPIO42.SetPin("42",PIN_OUT,PIN_LOW);
    if(status < 0)
        printf("%s Error Code:%d","42",status);
    printf("GPIO42.SetPin() finished\n");

    status = GPIO43.SetPin("43",PIN_OUT,PIN_LOW);
    if(status < 0)
        printf("%s Error Code:%d","43",status);
    printf("GPIO43.SetPin() finished\n");
    printf("00\n");

    for(int i=0;i<10;i++)
    {
        status = GPIO42.SetPinValue(PIN_LOW);
        printf("GPIO42.SetPinValue() status:%d\n",status);
        status = GPIO43.SetPinValue(PIN_HIGH);
        printf("GPIO43.SetPinValue() status:%d\n",status);
        printf("01\n");
        usleep(500000);    // 500 ms
        GPIO42.SetPinValue(PIN_HIGH);
        GPIO43.SetPinValue(PIN_LOW);
        printf("10\n");
        usleep(500000);    // 500 ms
        GPIO42.SetPinValue(PIN_HIGH);
        GPIO43.SetPinValue(PIN_HIGH);
        printf("11\n");
        usleep(500000);    // 500 ms
        GPIO42.SetPinValue(PIN_LOW);
        GPIO43.SetPinValue(PIN_LOW);
        printf("00\n");
        usleep(500000);    // 500 ms
    }

    status = GPIO42.DelPin();
    printf("GPIO42.DelPin() status:%d\n",status);
    status = GPIO43.DelPin();
    printf("GPIO43.DelPin() status:%d\n",status);
    return 0;
}