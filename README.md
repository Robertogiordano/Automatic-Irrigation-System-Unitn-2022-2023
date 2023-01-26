# Automatic Irrigation System with MSP432 Launchpad

## Requirements
### Hardware Requirements

For our project we need to use those materials:
[MSP432 Launchpad](),
[Educational booster pack MKII](),
5V motor pump, 
moisture sensor,
water level sensor,
potentiometer,
battery,
bridge stepper motor controller,
cables(male to male, male to female, female to female)

### Software Requirements
To run the code on the board, you need to install [Code Composer Studio]().
All the libraries are yet included in the project. So, you need only to download the folder and import the project. 

## Project Layout 



With this configuration(or an analogue one) we set all of our structure,using also a "container"(a Yogurt vase) for the water where the water sensor and the pump were sealed making the structure impermeabile and leakproof.With a tube the reservoir is connected to the plant(Using a void glass to let the user see the water flow) and where it is positioned the umidity sensor 

## Build 
Using the Layout you can reproduce the eletronic circuit and the cable links from the motherboard to all the components,in our workspace we needed to extend some circuit to have a better and easiest way to control all the things and test them.
An important Thing you need tyo pay attention is the position of the reservoir and the plant as the pump sometimes hasn't the power to push the water in a specific way.Another important thing is to put the container in a way that the water doesn't flow off caused of communicating vessels Principe(ususally an inverse U can solve mostly all the problems)

## Code description
c++


## Run 
With CCS we let the program start and then we can interact with the system menù on the launchpad booster if we need to modify something,or else we could observe the irrigator work with defoult settings.

## Links to video and powerpoint
[Video]()

[Powerpoint]()

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## Team Members
The team member and their principal apport to the project

Bellini   Pietro (Eletronic Designer)

Giordano  Roberto (Principal Programmer, coordinator)

La Rosa   Francesco (Builder and Host)
