#[macro_use]
extern crate smack;
use smack::*;

// @flag --check=integer-overflow
// @expect error

fn main() {
    let a = 32u8.verifier_nondet();
    let b = 8u8.verifier_nondet();
    let c = a * b;
}
