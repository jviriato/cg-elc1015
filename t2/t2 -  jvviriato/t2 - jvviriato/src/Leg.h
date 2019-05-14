#ifndef LEG_H
#define LEG_H

class Leg
{
private:
    double pedal_coords[2];
    double seat_coords[2];
    double knee_coords[2];
    double size;

public:
    Leg(double size);
    void render();
    void update(double pedal_x, double pedal_y);
    void setPedal(double x, double y);
    void setSeat(double x, double y);
    void setKnee();
    ~Leg();
};

#endif
