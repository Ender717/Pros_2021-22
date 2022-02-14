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
                    pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 50, "Programming Skills 1");
                    break;
                case 2;
                    pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 50, "Programming Skills 2");
                    break;
                case 3:
                    pros::screen::print(text_format_e_t::E_TEXT_LARGE, 80, 50, "Left Auton");
                    break;
                case 4:
                    pros::screen::print(text_format_e_t::E_TEXT_LARGE, 80, 50, "Middle Auton");
                    break;
                case 5:
                    pros::screen::print(text_format_e_t::E_TEXT_LARGE, 80, 50, "Right Auton");
                    break;
                default:
                    pros::screen::print(text_format_e_t::E_TEXT_LARGE, 50, 50, "No Auton Selected");
                    break;
            }
        }

        Autons::selectedAuton = auton;
    }

    void DrawPosition(float x, float y, float theta)
    {
        // Write the coordinates
        pros::screen::set_pen(COLOR_WHITE);
        pros::screen::print(text_format_e_t::E_TEXT_LARGE, 32, 32, "X: %.2f", x);
        pros::screen::print(text_format_e_t::E_TEXT_LARGE, 32, 72, "Y: %.2f", y);
        pros::screen::print(text_format_e_t::E_TEXT_LARGE, 32, 112, "Theta: %.2f", (theta / DriveConfig::DEGREES_TO_RADIANS));

        // Draw the field
        pros::screen::set_pen(COLOR_LIGHT_GRAY);
        pros::screen::fill_rect(224, 16, 464, 256);

        // Draw the tape lines
        pros::screen::set_pen(COLOR_WHITE);
        pros::screen::draw_line(304, 16, 304, 256);
        pros::screen::draw_line(343, 16, 343, 256);
        pros::screen::draw_line(345, 16, 345, 256);
        pros::screen::draw_line(384, 16, 384, 256);
        pros::screen::draw_line(264, 256, 304, 216);
        pros::screen::draw_line(384, 56, 424, 16);

        // Draw the red platform
        pros::screen::set_pen(COLOR_RED);
        for(int i = 0; i < 5; i++)
            pros::screen::draw_rect(227 + i, 91 + i, 262 - i, 181 - i);

        // Draw the blue platform
        pros::screen::set_pen(COLOR_BLUE);
        for(int i = 0; i < 5; i++)
            pros::screen::draw_rect(426 + i, 91 + i, 461 - i, 181 - i);

        // Draw the field perimeter
        pros::screen::set_pen(COLOR_BLACK);
        for(int i = 0; i < 2; i++)
            pros::screen::draw_rect(223 + i, 15 + i, 465 - i, 257 - i);

        // Draw the robot
        pros::screen::set_pen(COLOR_ORANGE);
        float robotX = 344 + (x * 5.0 / 3.0);
        float robotY = 136 + (y * 5.0 / 3.0);
        pros::screen::draw_circle(robotX, robotY, 15);

        // Draw an arrow to show the direction of the robot
        pros::screen::set_pen(COLOR_BLACK);
        float angle = theta;

        float x1 = robotX - (12 * cos(angle));
        float y1 = robotY - (12 * sin(angle));
        float x2 = robotX + (12 * cos(angle));
        float y2 = robotY + (12 * sin(angle));

        float px1 = x2 + (12 * cos(angle + (3.1415 / 6.0)));
        float py1 = y2 + (12 * sin(angle + (3.1415 / 6.0)));
        float px2 = x2 + (12 * cos(angle - (3.1415 / 6.0)));
        float py2 = y2 + (12 * sin(angle - (3.1415 / 6.0)));

        pros::screen::draw_line(x1, y1, x2, y2);
        pros::screen::draw_line(x2, y2, px1, py1);
        pros::screen::draw_line(x2, y2, px2, py2);
    }
}