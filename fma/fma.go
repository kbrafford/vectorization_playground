package main

// #cgo LDFLAGS: -L. -lfma
// #include "fma.h"
import "C"
import "unsafe"
import "fmt"

func HornerEvaluate_sp (x []float32, coeffs []float32, count uint) (float32, float32, float32, float32) {
  var res [4]float32

  C.horner_fma_sp((*C.float)(unsafe.Pointer(&x[0])), 
                  (*C.float)(unsafe.Pointer(&coeffs[0])),
                   C.uint(count), (*C.float)(unsafe.Pointer(&res[0])))

  return res[3], res[2], res[1], res[0]
}

func HornerEvaluate_dp (x []float64, coeffs []float64, count uint) (float64, float64) {
  var res [2]float64

  C.horner_fma_dp((*C.double)(unsafe.Pointer(&x[0])), 
                  (*C.double)(unsafe.Pointer(&coeffs[0])),
                   C.uint(count), (*C.double)(unsafe.Pointer(&res[0])))

  return res[1], res[0]
}

 
func main() {
  fmt.Println("Single Precision:")

  /* single precision */  
  /* coefficients of the polynomial */
                           /* c    x   x**2 */
  var coeffs_sp = []float32 {1.0, 2.0, 3.0}
  
  /* points at which to evaluate the polynomial */
  var x = []float32 {.2, .4, .6, .8}
  
  a,b,c,d := HornerEvaluate_sp(x, coeffs_sp, 3)

  fmt.Println("3x^2 + 2x + 1 evaluated at")
  fmt.Println(x[0], x[1], x[2], x[3])
  fmt.Println(a, b, c, d)
  
  fmt.Println("")
  fmt.Println("Double Precision:")
  
  /* double precision */  
  /* coefficients of the polynomial */
                           /* c    x   x**2 */
  var coeffs_dp = []float64 {1.0, 2.0, 3.0}
  
  /* points at which to evaluate the polynomial */
  var x_dp = []float64 {1.0/3.0, 2.0/3.0}
  
  e,f := HornerEvaluate_dp(x_dp, coeffs_dp, 3)

  fmt.Println("3x^2 + 2x + 1 evaluated at")
  fmt.Println(x_dp[0], x_dp[1])
  fmt.Println(e, f)  
}
