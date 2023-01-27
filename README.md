# Automatic Irrigation System with MSP432 Launchpad

Introducing the Automatic Irrigator, the perfect solution for keeping your plants hydrated and healthy with minimal effort. This innovative embedded system features a humidity sensor, temperature sensor, water pump and water level sensor. With a user-friendly selection menu for plant customization and a switch for the water pump, this system is designed to make the irrigation process easy and efficient. The system provides real-time information about the water level and alerts you when the water level is low. Additionally, proper maintenance of the humidity and water sensors ensures that the irrigation process is effective and efficient. This product will help you save water and time while keeping your plants in optimal condition. Get your hands on the Automatic Irrigator today and experience the convenience of hassle-free irrigation.

## Requirements

 ![alt text](https://github.com/Robertogiordano/Automatic-Irrigation-System-Unitn-2022-2023/blob/main/img/final%20scheme.jpg)
 
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

|-- main.c                             #main code
|-- msp432p401r.cmd                    #linker commmand file
|-- startup_msp432p401r_ccs.c          #initialize MCU and periherals including vector table, reset handler, system initialization and exception handlers
|-- system_msp432p401r.c               #configure the system clock and other system-level settings
|__ TargetConfigs
|   |--MSP432P401R.ccxml               #contains information about the target microcontroller
|-- Lib
|   |-- displaymenu.c
|   |-- displaymenu.h                  #contains functions to use the display and manage the water pump
|   |-- HAL_I2C.c
|   |-- HAL_I2C.h                      #contains functions to initialize Inter-integrated circuit transimssion
|   |-- HAL_OPT3001.c
|   |-- HAL_OPT3001.h                  #contains functions to initialize boosterpack optical light sensor
|   |-- HAL_TMP006.c
|   |-- HAL_TMP006.h                   #contains functions to initialize boosterpack temperature sensor
|-- Debug                              #debugs files created after the first debug (auto-created by CCS)


## Build and Run
When creating the layout for an automatic irrigation system, it is important to pay attention to the placement of the components and the connections between them. The layout should accurately reflect the electronic circuit and the cable links from the motherboard to all the components.

One important consideration is the placement of the reservoir and the plants. The water pump may not have enough power to push water to all areas of the system, so it's important to ensure that the reservoir and the plants are in close proximity to each other to minimize the distance the water needs to travel.

Another important consideration is the design of the container that holds the water. It should be designed in a way that prevents water from flowing out of the container due to the principle of communicating vessels. This can often be achieved by using an inverse U shape, which helps to contain the water and prevent it from flowing out of the container.

In order to build, burn and run the code starts to connect MSP432 with JTAG connection to the computer.
Than, simply open Code Composer Studio and import the whole folder.
Press on debug icon and the whole project will be automatically build and burnt.
In the end, press the play button to run the code.

Many variables are availables in the expresison panel to monitor all the inputs.

## Links to video and powerpoint
Video:
https://drive.google.com/file/d/1M0-fqor-0n5G2SIImS-bF2R9dSsC9bi-/view?usp=share_link

PPTX:
https://1drv.ms/p/s!ApySBi4wQidyh-d5lFBZgq4TDQ0EJg?e=oUUJGA

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## Team Members

The team worked remotely and used a remote computer and a remote camera to implement and develop the project. They collaborated effectively and efficiently to complete the project in a successful manner. The team lead (Roberto Giordano) was responsible for creating all the code and coordinating the project, while the other two team members (Francesco La Rosa and Pietro Bellini) were responsible for testing the system and creating all the electronic circuits. The collaboration between the team members allowed them to develop a high-quality irrigation system that can help improve the health and growth of plants.
