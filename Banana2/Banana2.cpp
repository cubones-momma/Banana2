#include <iostream>
#include <string>

using namespace std;

#define PI 3.141592653
#define CIRCLE "Circle"
#define SQUARE "Square"

#define ARRAY_SIZE 3000

int get_digital_root(int value);
void print_array(int user_arr[], int length);

namespace banana
{
    bool is_prime(int value);
    void circle_response();
    void square_response();
    float get_square_area(float length);
    float get_circle_area(float radius);
}

int main()
{
    int digital_root[ARRAY_SIZE];
    int current = 0;
    for (int i = 0; i < ARRAY_SIZE; i++, current++)
    {
        digital_root[i] = get_digital_root(current);
    }
    print_array(digital_root, ARRAY_SIZE);
    return 0;
}

int get_digital_root(int value)
{
    int ans;
    int current = value;

    do
    {
        ans = 0;
        while (current > 0)
        {
            ans += current % 10;
            current /= 10;
        }
    } while ((current = ans) >= 10);

    return ans;
}

void print_array(int user_arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << i << ": " << user_arr[i] << endl;
    }
}

namespace banana
{
    void circle_response()
    {
        float radius;
        float area;
        cout << "Please input the radius: " << endl;
        cin >> radius;
        area = get_circle_area(radius);
        cout << "The area is: " << area;
    }

    void square_response()
    {
        float length;
        float area;
        cout << "Please enter the length of the Square: " << endl;
        cin >> length;
        area = get_square_area(length);
        cout << "The area is: " << area;
    }

    float get_square_area(float length)
    {
        return length * length;
    }

    float get_circle_area(float radius)
    {
        return (float)PI * (radius * radius);
    }

    bool is_prime(int value)
    {
        if (value < 2)
        {
            return false;
        }

        if (value <= 3)
        {
            return true;
        }

        int max = sqrt(value) + 1;
        for (int divisor = 2; divisor <= max; divisor++)
        {
            if ((value % divisor) == 0)
            {
                return false;
            }
        }

        return true;
    }
}
