package main

// #cgo LDFLAGS: -L. -lfma
// #include "fma.h"
import "C"
import "unsafe"
import "fmt"

func fma_ff(A, B, C float32) float32 {
  return float32(C.fma_ff(C.float(A), C.float(B), C.float(C)))
}

/* These Horner's Method accessor functions use the fused multiply-add versions */

func HornerEvaluate_sp (x float32, coeffs []float32, count uint) float32 {
  return float32(C.horner_fma_sp(C.float(x), (*C.float)(unsafe.Pointer(&coeffs[0])) , C.uint(count)))
}
 
func HornerEvaluate_dp (x float64, coeffs []float64, count uint) float64 {
  return float64(C.horner_fma_dp(C.double(x), (*C.double)(unsafe.Pointer(&coeffs[0])) , C.uint(count)))
}
  

func main() {
  fmt.Println("Result is ")
  fmt.Println(fma_ff(12.1, 2.0, 1.0))
  
  /* now test polynomial evaluation */
  /* 32 bit floating point */
  var coeffs_sp = []float32 {1.0, 2.0, 3.0}  
  fmt.Println(HornerEvaluate_sp(.5, coeffs_sp, 3))

  /* 64 bit floating point */
  var coeffs_dp = []float64 {1.0, 2.0, 3.0}  
  fmt.Println(HornerEvaluate_dp(.5, coeffs_dp, 3))
  
}
