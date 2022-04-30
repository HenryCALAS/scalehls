
//===------------------------------------------------------------*- C++ -*-===//
//
// Automatically generated file for High-level Synthesis (HLS).
//
//===----------------------------------------------------------------------===//

#include <algorithm>
#include <ap_axi_sdata.h>
#include <ap_fixed.h>
#include <ap_int.h>
#include <hls_math.h>
#include <hls_stream.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

using namespace std;

void get_oracle_activations1(
  double v0[4096],
  double v1[64],
  double v2[64],
  double v3[64]
) {	// L2
  for (int v4 = 0; v4 < 2; v4 += 1) {	// L6
    for (int v5 = 0; v5 < 64; v5 += 1) {	// L6
      for (int v6 = 0; v6 < 32; v6 += 1) {	// L6
        v2[v5] = 0.000000;	// L5
        double v7 = v1[(v6 + (v4 * 32))];	// L7
        double v8 = v0[(((v5 * 64) + v6) + (v4 * 32))];	// L8
        double v9 = v7 * v8;	// L9
        double v10 = v2[v5];	// L10
        double v11 = v10 + v9;	// L11
        v2[v5] = v11;	// L12
        double v12 = v2[v5];	// L14
        double v13 = v3[v5];	// L15
        double v14 = v12 * v13;	// L16
        v2[v5] = v14;	// L17
      }
    }
  }
}

