// RUN: scalehls-opt -scalehls-affine-loop-dataflow %s | FileCheck %s

#map = affine_map<(d0, d1) -> (d0 + d1 * 4)>
#set0 = affine_set<(d0, d1, d2) : (d0 == 0, d1 == 0, d2 == 0)>
#set1 = affine_set<(d0, d1, d2) : (-d0 + 2 == 0, -d1 + 2 == 0, -d2 + 63 == 0)>
module {
  // CHECK: func @forward_dataflow6(%arg0: memref<1x32x32x64xi8, 3>, %arg1: !hls.stream<i1, 1>, %arg2: memref<3x3x64x64xi8, 3>, %arg3: memref<1x32x32x64xi8, 3>, %arg4: !hls.stream<i1, 1>, %arg5: !hls.stream<i1, 1>) attributes {func_directive = #hls.fd<pipeline=false, targetInterval=1, dataflow=true>} {
  func @forward_dataflow6(%arg0: memref<1x32x32x64xi8, 3>, %arg1: !hls.stream<i1, 1>, %arg2: memref<3x3x64x64xi8, 3>, %arg3: memref<1x32x32x64xi8, 3>, %arg4: !hls.stream<i1, 1>, %arg5: !hls.stream<i1, 1>) attributes {func_directive = #hls.fd<pipeline=false, targetInterval=1, dataflow=true>} {
    %c127_i8 = arith.constant 127 : i8
    %cst = arith.constant dense<5> : tensor<64xi8>
    %c0_i8 = arith.constant 0 : i8
    %false = arith.constant false
    %0 = memref.alloc() : memref<1x1x1x1xi8>
    %1 = bufferization.to_memref %cst : memref<64xi8>
    "hls.stream.read"(%arg1) : (!hls.stream<i1, 1>) -> ()
    %2 = memref.alloc() : memref<1x4x4x4xi8>
    %3 = memref.alloc() : memref<1x1x4x4xi8>
    %4 = memref.alloc() : memref<1x4x4x4xi8>
    affine.for %arg6 = 0 to 8 {
      affine.for %arg7 = 0 to 8 {
        affine.for %arg8 = 0 to 16 {
          affine.for %arg9 = 0 to 3 {
            affine.for %arg10 = 0 to 3 {
              affine.for %arg11 = 0 to 16 {

                // CHECK: hls.dataflow.node() {
                // CHECK:   affine.for %arg12 = 0 to 4 {
                // CHECK:     affine.for %arg13 = 0 to 4 {
                // CHECK:       %5 = affine.load %arg2[%arg9, %arg10, %arg12 + %arg11 * 4, %arg13 + %arg8 * 4] : memref<3x3x64x64xi8, 3>
                // CHECK:       affine.store %5, %3[0, 0, %arg12, %arg13] : memref<1x1x4x4xi8>
                // CHECK:     }
                // CHECK:   }
                // CHECK:   affine.for %arg12 = 0 to 4 {
                // CHECK:     affine.for %arg13 = 0 to 4 {
                // CHECK:       affine.for %arg14 = 0 to 4 {
                // CHECK:         %5 = affine.load %arg0[0, %arg12 + %arg9 + %arg6 * 4 - 1, %arg13 + %arg10 + %arg7 * 4 - 1, %arg14 + %arg11 * 4] : memref<1x32x32x64xi8, 3>
                // CHECK:         affine.store %5, %2[0, %arg12, %arg13, %arg14] : memref<1x4x4x4xi8>
                // CHECK:       }
                // CHECK:     }
                // CHECK:   }
                // CHECK: }
                affine.for %arg12 = 0 to 4 {
                  affine.for %arg13 = 0 to 4 {
                    affine.for %arg14 = 0 to 4 {
                      %5 = affine.load %arg0[0, %arg12 + %arg9 + %arg6 * 4 - 1, %arg13 + %arg10 + %arg7 * 4 - 1, %arg14 + %arg11 * 4] : memref<1x32x32x64xi8, 3>
                      affine.store %5, %2[0, %arg12, %arg13, %arg14] : memref<1x4x4x4xi8>
                    }
                  }
                }
                affine.for %arg12 = 0 to 4 {
                  affine.for %arg13 = 0 to 4 {
                    %5 = affine.load %arg2[%arg9, %arg10, %arg12 + %arg11 * 4, %arg13 + %arg8 * 4] : memref<3x3x64x64xi8, 3>
                    affine.store %5, %3[0, 0, %arg12, %arg13] : memref<1x1x4x4xi8>
                  }
                }

                // CHECK: hls.dataflow.node() {
                // CHECK:   affine.for %arg12 = 0 to 4 {
                // CHECK:     affine.for %arg13 = 0 to 4 {
                // CHECK:       affine.for %arg14 = 0 to 4 {
                // CHECK:         affine.for %arg15 = 0 to 4 {
                // CHECK:         } {point}
                // CHECK:       } {point}
                // CHECK:     } {point}
                // CHECK:   } {point}
                // CHECK: }
                affine.for %arg12 = 0 to 4 {
                  affine.for %arg13 = 0 to 4 {
                    affine.for %arg14 = 0 to 4 {
                      affine.for %arg15 = 0 to 4 {
                        %5 = affine.apply #map(%arg15, %arg11)
                        affine.if #set0(%arg9, %arg10, %5) {
                          affine.store %c0_i8, %0[0, 0, 0, 0] : memref<1x1x1x1xi8>
                        }
                        %6 = affine.load %2[0, %arg12, %arg13, %arg15] : memref<1x4x4x4xi8>
                        %7 = affine.load %3[0, 0, %arg15, %arg14] : memref<1x1x4x4xi8>
                        %8 = affine.load %0[0, 0, 0, 0] : memref<1x1x1x1xi8>
                        %9 = arith.muli %6, %7 : i8
                        %10 = arith.addi %8, %9 : i8
                        affine.store %10, %0[0, 0, 0, 0] : memref<1x1x1x1xi8>
                        %11 = affine.load %1[%arg14 + %arg8 * 4] : memref<64xi8>
                        %12 = arith.addi %11, %10 : i8
                        %13 = arith.cmpi slt, %12, %c0_i8 : i8
                        %14 = arith.select %13, %c0_i8, %12 : i8
                        %15 = arith.cmpi slt, %c127_i8, %12 : i8
                        %16 = arith.select %15, %c127_i8, %14 : i8
                        affine.if #set1(%arg9, %arg10, %5) {
                          affine.store %16, %4[0, %arg12, %arg13, %arg14] : memref<1x4x4x4xi8>
                        }
                      } {point}
                    } {point}
                  } {point}
                } {point}

                // CHECK: hls.dataflow.node() {
                // CHECK:   affine.for %arg12 = 0 to 4 {
                // CHECK:     affine.for %arg13 = 0 to 4 {
                // CHECK:       affine.for %arg14 = 0 to 4 {
                // CHECK:         %5 = affine.load %4[0, %arg12, %arg13, %arg14] : memref<1x4x4x4xi8>
                // CHECK:         affine.store %5, %arg3[0, %arg12 + %arg6 * 4, %arg13 + %arg7 * 4, %arg14 + %arg8 * 4] : memref<1x32x32x64xi8, 3>
                // CHECK:       }
                // CHECK:     }
                // CHECK:   }
                // CHECK: }
                affine.for %arg12 = 0 to 4 {
                  affine.for %arg13 = 0 to 4 {
                    affine.for %arg14 = 0 to 4 {
                      %5 = affine.load %4[0, %arg12, %arg13, %arg14] : memref<1x4x4x4xi8>
                      affine.store %5, %arg3[0, %arg12 + %arg6 * 4, %arg13 + %arg7 * 4, %arg14 + %arg8 * 4] : memref<1x32x32x64xi8, 3>
                    }
                  }
                }

              // CHECK: } {loop_directive = #hls.ld<pipeline=false, targetII=1, dataflow=true, flatten=false>}
              }
            }
          }
        }
      }
    }
    "hls.stream.write"(%arg4, %false) : (!hls.stream<i1, 1>, i1) -> ()
    "hls.stream.write"(%arg5, %false) : (!hls.stream<i1, 1>, i1) -> ()
    return
  }
}

