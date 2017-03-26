package main

// #cgo LDFLAGS: -L. -lfma
// #include "fma.h"
import "C"
import "fmt"

func fma_ff(A, B, C float32) float32 {
  return float32(C.fma_ff(C.float(A), C.float(B), C.float(C)))
}

func main() {
  fmt.Println("Result is ")
  fmt.Println(fma_ff(12.1, 2.0, 1.0))
}
