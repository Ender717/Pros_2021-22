#include "initialize.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {

}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() 
{
	Robot::Initialize();
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
	// Select an autonomous
	int auton = 1;
	bool selected = false;
	while (!selected)
	{
		// Draw the buttons
		pros::screen::set_pen(COLOR_BLUE);
		pros::screen::fill_rect(20, 100, 80, 160);
		pros::screen::fill_rect(20, 100, 80, 160);

		pros::screen::set_pen(COLOR_GREEN);
		pros::screen::fill_circle(80, 130, 30);

		pros::screen::set_pen(COLOR_WHITE);
		pros::screen::draw_rect(20, 100, 80, 160);
		pros::screen::draw_rect(20, 100, 80, 160);
		pros::screen::draw_circle(80, 130, 30);

		// Move the menu selection
		if(false)
			auton = (auton + 1) % Autons::NUM_AUTONS;
		if(false)
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
			case 2:
				pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 70, "Left Auton");
				break;
			default:
				pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 70, "No Auton Selected");
				break;
		}

		// Select the desired auton
		if(false)
			selected = true;
	}

	Autons::selectedAuton = auton;
}