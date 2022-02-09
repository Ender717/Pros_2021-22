#include "opcontrol.h"

void AutonSelect();
/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() 
{
	// Create the robot
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	AutonSelect();
	pros::screen::erase();
	
	while(true)
	{
		Robot::DriveControl(master);
		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 20, "X: %f", Robot::position.GetX());
		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 60, "Y: %f", Robot::position.GetY());
		pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 100, "Theta: %f", Robot::position.GetTheta());
	}
}

void AutonSelect()
{
	// Draw the buttons
	pros::screen::set_pen(COLOR_BLUE);
	pros::screen::fill_rect(100, 100, 180, 180);
	pros::screen::fill_rect(320, 100, 400, 180);

	pros::screen::set_pen(COLOR_GREEN);
	pros::screen::fill_circle(250, 140, 40);

	pros::screen::set_pen(COLOR_WHITE);
	pros::screen::draw_rect(100, 100, 180, 180);
	pros::screen::draw_rect(320, 100, 400, 180);
	pros::screen::draw_circle(250, 140, 40);

	pros::screen::set_pen(COLOR_BLACK);
	for(int i = 0; i < 5; i++)
	{
		pros::screen::draw_line(125 + i, 140, 155 + i, 170);
		pros::screen::draw_line(125 + i, 140, 155 + i, 110);
		pros::screen::draw_line(375 - i, 140, 345 - i, 170);
		pros::screen::draw_line(375 - i, 140, 345 - i, 110);
	}

	pros::screen::set_pen(COLOR_WHITE);

	// Select an autonomous
	int auton = 1;
	pros::screen_touch_status_s status;
	bool touched = false;
	bool selected = false;

	while (!selected)
	{
        status = pros::screen::touch_status();
		// Move the menu selection
		if(status.touch_status == E_TOUCH_PRESSED)
			touched = true;
		if(touched && status.touch_status == E_TOUCH_RELEASED)
		{
			touched = false;
			pros::screen::erase_rect(50, 50, 450, 90);
			if(status.x >= 100 && status.x <= 180 && status.y >= 100 && status.y <= 180)
			{
				auton--;
				if(auton == 0)
					auton = 3;
			}
			else if(status.x >= 320 && status.x <= 400 && status.y >= 100 && status.y <= 180)
			{
				auton = (auton % 3) + 1;
			}
			else if (((status.x - 250) * (status.x - 250)) + ((status.y - 140) * (status.y - 140)) <= (40 * 40))
			{
				selected = true;
			}
		}
		
		// Display the auton selection
		switch(auton)
		{
			case 1:
				pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 50, "Programming Skills");
				break;
			case 2:
				pros::screen::print(text_format_e_t::E_TEXT_LARGE, 80, 50, "Left Auton");
				break;
			case 3:
				pros::screen::print(text_format_e_t::E_TEXT_LARGE, 80, 50, "Right Auton");
				break;
			default:
				pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 50, "No Auton Selected");
				break;
		}
	}
}
