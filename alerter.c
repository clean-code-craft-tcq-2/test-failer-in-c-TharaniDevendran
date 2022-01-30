#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) 
{
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if(celcius < 200.0f) 
    {
        return 200;     // Return 200 for ok
    }
    else
        return 500;    // Return 500 for ok
}

float ConvertFarenheitToCelcius(float farenheit)  
{
	return (farenheit - 32) * 5 / 9;
}

void alertInCelcius(float farenheit, int (*ToNetworkAlertStub)(float))
{
    float celcius = ConvertFarenheitToCelcius(farenheit);
    int returnCode = ToNetworkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

int main() 
{
	alertInCelcius(400.5, &networkAlertStub);
    assert(alertFailureCount == 1);
    
    alertInCelcius(303.6, &networkAlertStub);
    assert(alertFailureCount == 1);
    
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well \n");
    return 0;
}
