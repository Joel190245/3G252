#include <ftxui/screen/screen.hpp>
int main() {
    auto screen = ftxui::Screen::Create(ftxui::Dimension::Fixed(10), ftxui::Dimension::Fixed(3));
    screen.Print();
    return 0;
}

