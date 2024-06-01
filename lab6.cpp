#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <cmath>
#include <vector>

#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 20


class Point {
protected:
    double x, y;
public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    virtual ~Point() {}

    virtual void move(double dx, double dy) {
        x += dx;
        y += dy;
    }

    virtual void resize(double factor) {

    }

    virtual void rotate(double angle) {
        
    }

    virtual void display() const {
        std::cout << "Point(" << x << ", " << y << ")\n";
    }
};


class Rectangle : public Point {
protected:
    double width, height;
public:
    Rectangle(double x, double y, double width, double height)
        : Point(x, y), width(width), height(height) {}

    void resize(double factor) override {
        width *= factor;
        height *= factor;
    }

    void rotate(double angle) override {
        
        std::cout << "Rectangle rotated by " << angle << " degrees\n";
    }

    void display() const override {
        std::cout << "Rectangle at (" << x << ", " << y << ") with width " << width << " and height " << height << "\n";
    }

    void draw(char screen[SCREEN_HEIGHT][SCREEN_WIDTH]) const {
        int left = static_cast<int>(x);
        int top = static_cast<int>(y);
        int right = static_cast<int>(x + width);
        int bottom = static_cast<int>(y + height);

        for (int i = top; i <= bottom; ++i) {
            for (int j = left; j <= right; ++j) {
                if (i >= 0 && i < SCREEN_HEIGHT && j >= 0 && j < SCREEN_WIDTH) {
                    if (i == top || i == bottom || j == left || j == right) {
                        screen[i][j] = '*';
                    }
                }
            }
        }
    }
};

#endif 


void clearScreen(char screen[SCREEN_HEIGHT][SCREEN_WIDTH]) {
    for (int i = 0; i < SCREEN_HEIGHT; ++i) {
        for (int j = 0; j < SCREEN_WIDTH; ++j) {
            screen[i][j] = ' ';
        }
    }
}

void printScreen(const char screen[SCREEN_HEIGHT][SCREEN_WIDTH]) {
    for (int i = 0; i < SCREEN_HEIGHT; ++i) {
        for (int j = 0; j < SCREEN_WIDTH; ++j) {
            std::cout << screen[i][j];
        }
        std::cout << '\n';
    }
}

void menu() {
    std::cout << "Menu:\n";
    std::cout << "1. Move the rectangle\n";
    std::cout << "2. Resize the rectangle\n";
    std::cout << "3. Rotate the rectangle\n";
    std::cout << "4. Display the rectangle\n";
    std::cout << "5. Exit\n";
}

int main() {
    char screen[SCREEN_HEIGHT][SCREEN_WIDTH];
    Rectangle rect(10, 5, 15, 8);
    int choice;
    double dx, dy, factor, angle;

    while (true) {
        menu();
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "Enter dx and dy: ";
            std::cin >> dx >> dy;
            rect.move(dx, dy);
            break;
        case 2:
            std::cout << "Enter resize factor: ";
            std::cin >> factor;
            rect.resize(factor);
            break;
        case 3:
            std::cout << "Enter rotation angle: ";
            std::cin >> angle;
            rect.rotate(angle);
            break;
        case 4:
            clearScreen(screen);
            rect.draw(screen);
            printScreen(screen);
            break;
        case 5:
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
