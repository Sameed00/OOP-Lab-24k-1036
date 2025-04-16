#include <iostream>
using namespace std;

class Activity {
public:
    virtual double calculateCaloriesBurned() const = 0;
    virtual void display() const = 0;
    virtual ~Activity() {}
};

class Running : public Activity {
private:
    double distance;
    double time;
public:
    Running(double d, double t) : distance(d), time(t) {}

    double calculateCaloriesBurned() const override {
        return distance * 60.0;
    }

    void display() const override {
        cout << "Running:\n";
        cout << "Distance: " << distance << " km\n";
        cout << "Time: " << time << " minutes\n";
        cout << "Calories Burned: " << calculateCaloriesBurned() << " kcal\n\n";
    }
};

class Cycling : public Activity {
private:
    double speed;
    double time;
public:
    Cycling(double s, double t) : speed(s), time(t) {}

    double calculateCaloriesBurned() const override {
        return 8.0 * 70.0 * time;
    }

    void display() const override {
        cout << "Cycling:\n";
        cout << "Speed: " << speed << " km/h\n";
        cout << "Time: " << time << " hours\n";
        cout << "Calories Burned: " << calculateCaloriesBurned() << " kcal\n\n";
    }
};

int main() {
    Running runActivity(5.0, 30.0);
    Cycling cycleActivity(20.0, 1.0);

    runActivity.display();
    cycleActivity.display();

    return 0;
}
