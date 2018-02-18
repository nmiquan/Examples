#include <stdio.h>
#include <math.h>

#define SPEED_OF_LIGHT 299792458.0

int main(void) {
    double mass, rest_mass;
    double velocity;
    double ratio;

    printf("Enter rest mass: ");
    scanf("%lf", &rest_mass);

    printf("Enter velocity in metres/second: ");
    scanf("%lf", &velocity);
    
    // compute velocity as a fraction of speed of light
    ratio = velocity / SPEED_OF_LIGHT;
    
    if (ratio >= 1.0) {
        printf("Error: velocity exceeds speed of light.\n");
    } else {
        // compute observed mass using Einstein's equation
        mass = rest_mass / sqrt(1.0 - ratio*ratio);
        printf("Observed mass = %1.6f\n", mass);
    }
    return 0;
}
