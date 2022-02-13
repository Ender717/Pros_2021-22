// Included libraries
#include "Menu.h"

namespace Menu
{
    bool autonSelected = false;

    void DrawAutonSelect()
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
    }
    
    void AutonSelect()
    {
        pros::screen::set_pen(COLOR_WHITE);

        // Select an autonomous
        int auton = 1;
        pros::screen_touch_status_s status;
        bool touched = false;

        while (!autonSelected)
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
                        auton = Autons::NUM_AUTONS;
                }
                else if(status.x >= 320 && status.x <= 400 && status.y >= 100 && status.y <= 180)
                {
                    auton = (auton % Autons::NUM_AUTONS) + 1;
                }
                else if (((status.x - 250) * (status.x - 250)) + ((status.y - 140) * (status.y - 140)) <= (40 * 40))
                {
                    autonSelected = true;
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
                    pros::screen::print(text_format_e_t::E_TEXT_LARGE, 80, 50, "Middle Auton");
                    break;
                case 4:
                    pros::screen::print(text_format_e_t::E_TEXT_LARGE, 80, 50, "Right Auton");
                    break;
                default:
                    pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 50, "No Auton Selected");
                    break;
            }
        }

        Autons::selectedAuton = auton;
    }
}