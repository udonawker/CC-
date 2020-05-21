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

    struct struct_z {
        const struct_x* px;
    };

private:
    static const struct_x XXX;
    static const struct_x YYY;
    static const struct_z ZZZ;

public:
    void printXXX();
    void printYYY();
    void printZZZ();
};

#endif
