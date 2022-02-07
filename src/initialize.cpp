#include "initialize.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() 
{
	
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() 
{
	// Create the controller
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	// Select an autonomous
	int auton = 1;
	bool selected = false;
	while (!selected)
	{
		// Move the menu selection
		if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT))
			auton = (auton + 1) % Autons::NUM_AUTONS;
		if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_LEFT))
		{
			auton--;
			if(auton = 0)
				auton = Autons::NUM_AUTONS;
		}

		// Display the auton selection
		switch(auton)
		{
			case 1:
				pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 70, "Programming Skills");
				break;
			default:
				pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 70, "No Auton Selected");
				break;
		}

		// Select the desired auton
		if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_A))
			selected = true;
	}

	Autons::selectedAuton = auton;
}