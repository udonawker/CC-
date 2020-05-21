#ifndef _STRUCT_INITIALIZE_PERIOD_H_
#define _STRUCT_INITIALIZE_PERIOD_H_

class StructInitializePeriod {
private:
    struct struct_a {
      int a;
      int b;
    };

    struct struct_x {
      int x;
      struct_a buff[2];
    };

private:
    static const struct_x XXX;
    static const struct_x YYY;

public:
    void printXXX();
    void printYYY();
};

#endif
