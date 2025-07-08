#include <stdio.h>

int main (void)

{
  //print out directions
  printf("This program calculates current and power for a given voltage, \n");
  printf("resistance, and resistance tolerance.\n\n");

  //prompt user for voltage (in volts)
  double voltage;
  printf("Please Enter the voltage source (in volts): \n");
  scanf("%lf", &voltage);

  double resistance;
  printf("Please Enter the resistance (in ohms): \n");
  scanf("%lf", &resistance);

  double tolerance;
  printf("Please Enter the resistance tolerance (in percent): \n");
  scanf("%lf", &tolerance);

  tolerance = tolerance/100.0;
  printf("tolerance: %.4f\n", tolerance);

  //calculating maximum and minimum resistance values
  double rlow = resistance - resistance*tolerance;
  double rhigh = resistance + resistance*tolerance;

  //calculate current based on three resistances
  double normalcurrent = voltage/resistance;
  double mincurrent = voltage/rlow;
  double maxcurrent = voltage/rhigh;

  //calculate total power
  double normalpower = voltage * normalcurrent;
  double minpower = voltage * mincurrent;
  double maxpower = voltage * maxcurrent;

  printf("\nResistance (ohms)  Current (amps)  Power (watts)\n");
  printf("%lf     %lf      %lf\n", resistance, normalcurrent, normalpower);
  printf("%lf     %lf      %lf\n", rhigh, mincurrent, minpower);
  printf("%lf     %lf      %lf\n", rlow, maxcurrent, maxpower);
}