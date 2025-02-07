#include <iostream>
using namespace std;

struct CoordinateAxis {
    int x;
    int y;

    void print_coordinate_axis_with_rectangle(int rectX, int rectY, int rectWidth, int rectHeight) {
        const int width = 2 * x + 1;
        const int height = 2 * y + 1;
        char** axis = new char* [height];
        for (int i = 0; i < height; ++i) {
            axis[i] = new char[width];
        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                axis[i][j] = ' ';
            }
        }
        for (int i = 0; i < height; i++) {
            axis[i][x] = '*';
        }
        for (int j = 0; j < width; j++) {
            axis[y][j] = '-';
        }
        axis[y][x] = '0';
        for (int i = 0; i < rectHeight; i++) {
            for (int j = 0; j < rectWidth; j++) {
                int drawY = y - rectY - i;
                int drawX = x + rectX + j;
                if (drawY >= 0 && drawY < height && drawX >= 0 && drawX < width) {
                    if (i == 0 || i == rectHeight - 1 || j == 0 || j == rectWidth - 1) {
                        axis[drawY][drawX] = '?';
                    }
                }
            }
        }

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << axis[i][j];
            }
            cout << endl;
        }

        for (int i = 0; i < height; ++i) {
            delete[] axis[i];
        }
        delete[] axis;
    }
};

struct Rectangle {
    int width;
    int height;
    int pose_x;
    int pose_y;

    void change_size(int newWidth, int newHeight, CoordinateAxis& axis) {
        width = newWidth;
        height = newHeight;
        if (pose_x + width > axis.x) {
            axis.x = pose_x + width;
        }
        if (pose_y + height > axis.y) {
            axis.y = pose_y + height;
        }
    }
    void change_position(int newX, int newY) {
        pose_x = newX;
        pose_y = newY;
    }
    void print_rectangle() {
        cout << "Rectangle: width = " << width << ", height = " << height << ", pose_x = " << pose_x << ", pose_y = " << pose_y << endl;
    }
};

int main() {
    CoordinateAxis axis;
    axis.x = 7;
    axis.y = 5;

    Rectangle rect;
    rect.width = 5;
    rect.height = 3;
    rect.pose_x = 1;
    rect.pose_y = 2;

    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Print coordinate axis with rectangle\n";
        cout << "2. Change rectangle size\n";
        cout << "3. Change rectangle position\n";
        cout << "4. Print rectangle details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            axis.print_coordinate_axis_with_rectangle(rect.pose_x, rect.pose_y, rect.width, rect.height);
            break;
        case 2: {
            int newWidth, newHeight;
            cout << "Enter new width: ";
            cin >> newWidth;
            cout << "Enter new height: ";
            cin >> newHeight;
            rect.change_size(newWidth, newHeight, axis);
            break;
        }
        case 3: {
            int newX, newY;
            cout << "Enter new x position: ";
            cin >> newX;
            cout << "Enter new y position: ";
            cin >> newY;
            rect.change_position(newX, newY);
            break;
        }
        case 4:
            rect.print_rectangle();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}