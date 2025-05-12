#include <iostream>
#include <sstream>

enum switches{
    LIGHT_INSIDE = 1,
    LIGHT_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};

void waterPipe_control (double outside_temp, int &switch_state) {
    if (outside_temp < 0 && !(switch_state & WATER_PIPE_HEATING)) {
        switch_state |= WATER_PIPE_HEATING;
        std::cout << "Water pipe heating is now on.\n";
    } else if (outside_temp > 5 && switch_state & WATER_PIPE_HEATING) {
        switch_state &= ~ WATER_PIPE_HEATING;
        std::cout << "Water pipe heating is now off.\n";
    }
}

void outsideLight_control (int hour, std::string moving, int &switch_state) {
    if (((hour >= 17 || hour < 5) && moving == "yes") && !(switch_state & LIGHT_OUTSIDE)) {
        switch_state |= LIGHT_OUTSIDE;
        std::cout << "The light outside house is now on.\n";
    } else if (((hour < 17 && hour >= 5) || moving != "yes") && switch_state & LIGHT_OUTSIDE) {
        switch_state &= ~LIGHT_OUTSIDE;
        std::cout << "The light outside house now is now off.\n";
    }
}

void insideHeating_control (double inside_temp, int &switch_state) {
    if (inside_temp < 22 && !(switch_state & HEATERS)) {
        switch_state |= HEATERS;
        std::cout << "The heating in the house now is now on.\n";
    } else if (inside_temp > 25 && switch_state & HEATERS) {
        switch_state &= ~ HEATERS;
        std::cout << "The heating in the house is now off.\n";
    }
}

void conditioner_control (double inside_temp, int &switch_state) {
     if (inside_temp >= 30 && !(switch_state & CONDITIONER)) {
        switch_state |= CONDITIONER;
        std::cout << "The conditioner is now on.\n";
    } else if (inside_temp <= 25 && switch_state & CONDITIONER) {
        switch_state &= ~ CONDITIONER;
        std::cout << "The conditioner is now off.\n";
    }
}

void insideLight_control (int light_temp, int hour, std::string house_light, int &switch_state) {
    if (house_light == "on" && !(switch_state & LIGHT_INSIDE)) {
        switch_state |= LIGHT_INSIDE;
        std::cout << "The light inside house is now on.\n";
    } else if (house_light == "off" && switch_state & LIGHT_INSIDE) {
        switch_state &= ~LIGHT_INSIDE;
        std::cout << "The light inside house is now off.\n";
    }
    
    if (switch_state & LIGHT_INSIDE) {
        if (hour == 17) {
            light_temp = 4425;
        } else if (hour == 18) {
            light_temp = 3850;
        } else if (hour == 19) {
            light_temp = 3275;
        } else if (hour >= 20 && hour <= 23) {
            light_temp = 2700;
        } else {
            light_temp = 5000;
        }
        std::cout << "Color temperature: " << light_temp << "K\n";
    }
}

int main() {
    std::cout << "Smart house!\n";
    std::string input_data;
    int hour = 0, count = 0;
    int color_temp = 5000;
    int switch_state = 0;
    double inside_temp, outside_temp;
    std::string moving_outside, inside_light;
    
    do {
        std::cout << "Time is " << hour << ":00\n";
        std::cout << "Enter the sensor statuse separated by a spaces\n<Temperature inside (number)> <temperature outside (number)> <movement (yes/no)> <lights (on/off)>:\n";
        std::getline(std::cin, input_data);
        std::stringstream data_stream(input_data);
        data_stream >> inside_temp >> outside_temp >> moving_outside >> inside_light;
        
        waterPipe_control(outside_temp, switch_state);
        outsideLight_control(hour, moving_outside, switch_state);
        insideHeating_control(inside_temp,switch_state);
        conditioner_control(inside_temp,switch_state);
        insideLight_control(color_temp,hour,inside_light,switch_state);
        
        if (hour == 23) {
            hour = 0;
        } else {
            count++;
            hour++;
        }
        std::cout << std::endl;
    } while (count < 48);
}