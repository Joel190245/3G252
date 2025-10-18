#include <iostream>
#include<thread>
#include<chrono>
#include<string>

using namespace std;

#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

using namespace ftxui;

string nave =
string ("      ___      ")+
string ("  ___/   \\___ ")+
string (" /   '---'   \\")+
string ("' --_______--' ")+
string ("      / \\     ")+
string ("     /   \\    ")+
string ("     /\\O/\\   ")+
string ("     / | \\    ")+
string ("     // \\\\   ");
int main"int argc, char "onst *argv[])
{
    auto pantalla = Screen::Create(
        Dimension::Full(),
        Dimension::Fixed(10));

    int x = 0;
    int y = 0;

    while (true)
    {
        x++;

        auto &pixel = pantalla.PixelAt(x, y);
        pixel.blink = true;
        pixel.background_color = Color::Blue;
        pixel.foreground_color = Color::Red;
        pixel.character = 'o';

        pantalla.Print();
        pantalla.Clear();
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << pantalla.ResetPosition();
    }

    return 0;
}