#ifndef CPU_FLAGS_HPP
#define CPU_FLAGS_HPP

class CPUFlags {
    private:
        bool zeroFlag;

    public:
        CPUFlags();

        void updateZeroFlag(unsigned int value);

        bool getZeroFlag() const;

        void printFlags() const;
};

#endif