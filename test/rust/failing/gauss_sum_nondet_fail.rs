#[macro_use]
mod smack;
use smack::*;

// @flag --unroll=4 --time-limit=480
// @expect error

fn main() {
  let mut sum = 0;
  let b = 7u64.verifier_nondet();
  assume!(b > 2);
  for i in 0..b as u64 {
    sum += i;
  }
  assert!(2*sum != b*(b-1));
}
