#ifndef OBJ_BASE_CLASS
#define OBJ_BASE_CLASS


class Object {
    private:
    int xLocation;
    int yLocation;
    int height;
    int width;
    double speed;
    char visual;
    
    public:
    Object() : xLocation(0), yLocation(0), height(0), width(0), speed(0), visual('0') { }
    Object(int x, int y, int h, int w, double s, char v) : xLocation(x), yLocation(y), height(h), width(w), speed(s), visual(v) { }
    
    //DRAW OBJECT
    virtual const void drawObject() const = 0;
    
    //MUTATORS
    const void newXpos(int x) { xLocation = x; } 
    const void newYpos(int y) { yLocation = y; } 
    const void newHeight(int h) { height = h; } 
    const void newWidth(int w) { width = w; }
    const void newSpeed(double s) { speed = s; }
    
};

#endif