#ifndef __MIPS__
#define __MIPS__

#include <string>

// These are the registers for Mips. Currently, listed only are the ones
// from QtSpim.
enum Registers
{
    $r0,
    $at,
    $v0,
    $v1,
    $a0,
    $a1,
    $a2,
    $a3,
    $t0,
    $t1,
    $t2,
    $t3,
    $t4,
    $t5,
    $t6,
    $t7,
    $t8,
    $t9,
    $s0,
    $s1,
    $s2,
    $s3,
    $s4,
    $s5,
    $s6,
    $s7,
    $s8,
    $k0,
    $k1,
    $gp,
    $sp,
    $ra
};


class Mips : 
{
public:
    // Stack Based Code Gen would use push & pop frequently.
    static std::string push(std::string val);
    static std::string pop();
}

#endif