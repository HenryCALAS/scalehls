
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

void forward_node1(
  float v0[8],
  float v1[1000],
  int v2
) {	// L46
  #pragma HLS inline
  #pragma HLS resource variable=v0 core=ram_t2p_bram

  for (int v3 = 0; v3 < 8; v3 += 1) {	// L47
    #pragma HLS pipeline II=1
    float v4 = v0[v3];	// L48
    v1[(v3 + (v2 * 8))] = v4;	// L49
  }
}

void forward_node2(
  float v5[512],
  float v6[8][8],
  float v7[1000],
  float v8[1000],
  float v9[8],
  int v10,
  int v11
) {	// L53
  #pragma HLS inline
  #pragma HLS resource variable=v5 core=ram_t2p_bram

  #pragma HLS resource variable=v6 core=ram_t2p_bram

  #pragma HLS resource variable=v7 core=ram_t2p_bram

  #pragma HLS resource variable=v8 core=ram_t2p_bram

  #pragma HLS resource variable=v9 core=ram_t2p_bram

  for (int v12 = 0; v12 < 8; v12 += 1) {	// L54
    for (int v13 = 0; v13 < 8; v13 += 1) {	// L55
      #pragma HLS pipeline II=1
      float v14 = v5[(v12 + (v10 * 8))];	// L56
      float v15 = v6[v12][v13];	// L57
      float v16 = v8[(v13 + (v11 * 8))];	// L58
      float v17 = v14 * v15;	// L59
      float v18 = v16 + v17;	// L60
      v8[(v13 + (v11 * 8))] = v18;	// L61
      float v19 = v7[(v13 + (v11 * 8))];	// L62
      float v20 = v18 + v19;	// L63
      if ((((-v12) + (v10 * -8)) + 511) == 0) {	// L64
        v9[v13] = v20;	// L65
      }
    }
  }
}

void forward_node3(
  float v21[512][1000],
  float v22[8][8],
  int v23,
  int v24
) {	// L71
  #pragma HLS inline
  #pragma HLS resource variable=v22 core=ram_t2p_bram

  for (int v25 = 0; v25 < 8; v25 += 1) {	// L72
    for (int v26 = 0; v26 < 8; v26 += 1) {	// L73
      #pragma HLS pipeline II=1
      float v27 = v21[(v25 + (v23 * 8))][(v26 + (v24 * 8))];	// L74
      v22[v25][v26] = v27;	// L75
    }
  }
}

void forward_node0(
  float v28[1000],
  float v29[512][1000],
  float v30[512],
  float v31[1000]
) {	// L80
  #pragma HLS resource variable=v28 core=ram_t2p_bram

  #pragma HLS resource variable=v30 core=ram_t2p_bram

  float v32[1000];	// L81
  #pragma HLS resource variable=v32 core=ram_t2p_bram

  for (int v33 = 0; v33 < 8000; v33 += 1) {	// L82
    #pragma HLS dataflow
    int v34 = (v33 % 125);	// L83
    int v35 = (v33 / 125);	// L84
    float v36[8];	// L85
    #pragma HLS resource variable=v36 core=ram_t2p_bram

    float v37[8][8];	// L86
    #pragma HLS resource variable=v37 core=ram_t2p_bram

    forward_node3(v29, v37, v35, v34);	// L87
    forward_node2(v30, v37, v28, v32, v36, v35, v34);	// L88
    forward_node1(v36, v31, v34);	// L89
  }
}

void forward_node4(
  float v38,
  float v39[512],
  float v40[512]
) {	// L93
  #pragma HLS resource variable=v39 core=ram_t2p_bram

  #pragma HLS resource variable=v40 core=ram_t2p_bram

  for (int v41 = 0; v41 < 512; v41 += 1) {	// L94
    #pragma HLS pipeline II=1
    float v42 = v39[v41];	// L95
    v40[v41] = v42;	// L96
  }
  for (int v43 = 0; v43 < 64; v43 += 1) {	// L98
    for (int v44 = 0; v44 < 8; v44 += 1) {	// L99
      #pragma HLS pipeline II=1
      float v45 = v38;	// L100
      float v46 = v40[(v44 + (v43 * 8))];	// L101
      float v47 = v46 / v45;	// L102
      v40[(v44 + (v43 * 8))] = v47;	// L103
    }
  }
}

void forward_node6(
  float v48[8][2][2],
  float v49[512],
  float v50,
  int v51,
  int v52,
  int v53
) {	// L108
  #pragma HLS inline
  #pragma HLS resource variable=v48 core=ram_t2p_bram

  #pragma HLS resource variable=v49 core=ram_t2p_bram

  for (int v54 = 0; v54 < 8; v54 += 1) {	// L112
    for (int v55 = 0; v55 < 2; v55 += 1) {	// L113
      for (int v56 = 0; v56 < 2; v56 += 1) {	// L114
        #pragma HLS pipeline II=1
        float v57 = v49[(v54 + (v52 * 8))];	// L115
        int v58 = ((v55 + (v51 * 2)) + 4);	// L116
        int v59 = ((v56 + (v53 * 2)) + 4);	// L117
        float v60 = v48[v54][v55][v56];	// L118
        bool v61 = v58 < (int)5;	// L119
        float v62 = v61 ? v60 : (float)0.000000;	// L120
        bool v63 = v59 < (int)5;	// L121
        float v64 = v63 ? v62 : (float)0.000000;	// L122
        float v65 = v64 + v57;	// L123
        v49[(v54 + (v52 * 8))] = v65;	// L124
        v50 = (float)1.000000;	// L125
      }
    }
  }
}

void forward_node7(
  float v66[512][5][5],
  float v67[8][2][2],
  int v68,
  int v69,
  int v70
) {	// L131
  #pragma HLS inline
  #pragma HLS resource variable=v67 core=ram_t2p_bram

  for (int v71 = 0; v71 < 8; v71 += 1) {	// L132
    for (int v72 = 0; v72 < 2; v72 += 1) {	// L133
      for (int v73 = 0; v73 < 2; v73 += 1) {	// L134
        #pragma HLS pipeline II=1
        float v74 = v66[(v71 + (v68 * 8))][((v72 + (v69 * 2)) + 4)][((v73 + (v70 * 2)) + 4)];	// L135
        v67[v71][v72][v73] = v74;	// L136
      }
    }
  }
}

void forward_node5(
  float v75[512][5][5],
  float v76,
  float v77[512]
) {	// L142
  #pragma HLS resource variable=v77 core=ram_t2p_bram

  for (int v78 = 0; v78 < 256; v78 += 1) {	// L143
    #pragma HLS dataflow
    int v79 = (v78 % 2);	// L144
    int v80 = ((v78 / 2) % 2);	// L145
    int v81 = ((v78 / 2) / 2);	// L146
    float v82[8][2][2];	// L147
    #pragma HLS resource variable=v82 core=ram_t2p_bram

    forward_node7(v75, v82, v81, v80, v79);	// L148
    forward_node6(v82, v77, v76, v80, v81, v79);	// L149
  }
}

void forward_node9(
  float v83[8][2][2],
  float v84[512][4][4],
  int v85,
  int v86,
  int v87
) {	// L153
  #pragma HLS inline
  #pragma HLS resource variable=v83 core=ram_t2p_bram

  for (int v88 = 0; v88 < 8; v88 += 1) {	// L154
    for (int v89 = 0; v89 < 2; v89 += 1) {	// L155
      for (int v90 = 0; v90 < 2; v90 += 1) {	// L156
        #pragma HLS pipeline II=1
        float v91 = v83[v88][v89][v90];	// L157
        v84[(v88 + (v85 * 8))][(v89 + (v86 * 2))][(v90 + (v87 * 2))] = v91;	// L158
      }
    }
  }
}

void forward_node10(
  float v92[8][2][2],
  float v93[8][2][2],
  float v94[512],
  float v95[512],
  float v96[512],
  float v97[512],
  float v98[8][2][2],
  int v99
) {	// L164
  #pragma HLS inline
  #pragma HLS resource variable=v92 core=ram_t2p_bram

  #pragma HLS resource variable=v93 core=ram_t2p_bram

  #pragma HLS resource variable=v94 core=ram_t2p_bram

  #pragma HLS resource variable=v95 core=ram_t2p_bram

  #pragma HLS resource variable=v96 core=ram_t2p_bram

  #pragma HLS resource variable=v97 core=ram_t2p_bram

  #pragma HLS resource variable=v98 core=ram_t2p_bram

  for (int v100 = 0; v100 < 8; v100 += 1) {	// L167
    for (int v101 = 0; v101 < 2; v101 += 1) {	// L168
      for (int v102 = 0; v102 < 2; v102 += 1) {	// L169
        #pragma HLS pipeline II=1
        float v103 = v92[v100][v101][v102];	// L170
        float v104 = v97[(v100 + (v99 * 8))];	// L171
        float v105 = v96[(v100 + (v99 * 8))];	// L172
        float v106 = v95[(v100 + (v99 * 8))];	// L173
        float v107 = v94[(v100 + (v99 * 8))];	// L174
        float v108 = v93[v100][v101][v102];	// L175
        float v109 = (double)0.000010;	// L176
        float v110 = v107 + v109;	// L177
        float v111 = 1.0 / sqrt(v110);	// L178
        float v112 = v103 - v106;	// L179
        float v113 = v112 * v111;	// L180
        float v114 = v113 * v104;	// L181
        float v115 = v114 + v105;	// L182
        float v116 = v115 + v108;	// L183
        bool v117 = v116 > (float)0.000000;	// L184
        float v118 = v117 ? v116 : (float)0.000000;	// L185
        v98[v100][v101][v102] = v118;	// L186
      }
    }
  }
}

void forward_node11(
  float v119[512][4][4],
  float v120[8][2][2],
  int v121,
  int v122,
  int v123
) {	// L192
  #pragma HLS inline
  #pragma HLS resource variable=v120 core=ram_t2p_bram

  for (int v124 = 0; v124 < 8; v124 += 1) {	// L193
    for (int v125 = 0; v125 < 2; v125 += 1) {	// L194
      for (int v126 = 0; v126 < 2; v126 += 1) {	// L195
        #pragma HLS pipeline II=1
        float v127 = v119[(v124 + (v121 * 8))][(v125 + (v122 * 2))][(v126 + (v123 * 2))];	// L196
        v120[v124][v125][v126] = v127;	// L197
      }
    }
  }
}

void forward_node12(
  float v128[512][4][4],
  float v129[8][2][2],
  int v130,
  int v131,
  int v132
) {	// L203
  #pragma HLS inline
  #pragma HLS resource variable=v129 core=ram_t2p_bram

  for (int v133 = 0; v133 < 8; v133 += 1) {	// L204
    for (int v134 = 0; v134 < 2; v134 += 1) {	// L205
      for (int v135 = 0; v135 < 2; v135 += 1) {	// L206
        #pragma HLS pipeline II=1
        float v136 = v128[(v133 + (v130 * 8))][(v134 + (v131 * 2))][(v135 + (v132 * 2))];	// L207
        v129[v133][v134][v135] = v136;	// L208
      }
    }
  }
}

void forward_node8(
  float v137[512],
  float v138[512][4][4],
  float v139[512],
  float v140[512],
  float v141[512][4][4],
  float v142[512],
  float v143[512][4][4]
) {	// L214
  #pragma HLS resource variable=v137 core=ram_t2p_bram

  #pragma HLS resource variable=v139 core=ram_t2p_bram

  #pragma HLS resource variable=v140 core=ram_t2p_bram

  #pragma HLS resource variable=v142 core=ram_t2p_bram

  for (int v144 = 0; v144 < 256; v144 += 1) {	// L215
    #pragma HLS dataflow
    int v145 = (v144 % 2);	// L216
    int v146 = ((v144 / 2) % 2);	// L217
    int v147 = ((v144 / 2) / 2);	// L218
    float v148[8][2][2];	// L219
    #pragma HLS resource variable=v148 core=ram_t2p_bram

    float v149[8][2][2];	// L220
    #pragma HLS resource variable=v149 core=ram_t2p_bram

    float v150[8][2][2];	// L221
    #pragma HLS resource variable=v150 core=ram_t2p_bram

    forward_node12(v141, v150, v147, v146, v145);	// L222
    forward_node11(v138, v149, v147, v146, v145);	// L223
    forward_node10(v150, v149, v137, v142, v140, v139, v148, v147);	// L224
    forward_node9(v148, v143, v147, v146, v145);	// L225
  }
}

void forward_node14(
  float v151[8][2][2],
  float v152[512][4][4],
  int v153,
  int v154,
  int v155
) {	// L229
  #pragma HLS inline
  #pragma HLS array_partition variable=v151 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v151 cyclic factor=2 dim=3
  #pragma HLS resource variable=v151 core=ram_t2p_bram

  #pragma HLS array_partition variable=v152 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v152 cyclic factor=2 dim=3

  for (int v156 = 0; v156 < 8; v156 += 1) {	// L230
    #pragma HLS pipeline II=1
    float v157 = v151[v156][0][0];	// L231
    v152[(v156 + (v153 * 8))][(v154 * 2)][(v155 * 2)] = v157;	// L232
    float v158 = v151[v156][0][1];	// L233
    v152[(v156 + (v153 * 8))][(v154 * 2)][((v155 * 2) + 1)] = v158;	// L234
    float v159 = v151[v156][1][0];	// L235
    v152[(v156 + (v153 * 8))][((v154 * 2) + 1)][(v155 * 2)] = v159;	// L236
    float v160 = v151[v156][1][1];	// L237
    v152[(v156 + (v153 * 8))][((v154 * 2) + 1)][((v155 * 2) + 1)] = v160;	// L238
  }
}

void forward_node15(
  float v161[8][2][2],
  float v162[8][8],
  float v163[8][2][2],
  float v164[8][2][2]
) {	// L242
  #pragma HLS inline
  #pragma HLS array_partition variable=v161 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v161 cyclic factor=2 dim=3
  #pragma HLS resource variable=v161 core=ram_t2p_bram

  #pragma HLS resource variable=v162 core=ram_t2p_bram

  #pragma HLS array_partition variable=v163 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v163 cyclic factor=2 dim=3
  #pragma HLS resource variable=v163 core=ram_t2p_bram

  #pragma HLS array_partition variable=v164 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v164 cyclic factor=2 dim=3
  #pragma HLS resource variable=v164 core=ram_t2p_bram

  for (int v165 = 0; v165 < 8; v165 += 1) {	// L243
    for (int v166 = 0; v166 < 8; v166 += 1) {	// L244
      #pragma HLS pipeline II=1
      float v167 = v161[v165][0][0];	// L245
      float v168 = v162[v166][v165];	// L246
      float v169 = v163[v166][0][0];	// L247
      float v170 = v164[v166][0][0];	// L248
      float v171 = (v165 == 0) ? v169 : v170;	// L249
      float v172 = v167 * v168;	// L250
      float v173 = v171 + v172;	// L251
      v164[v166][0][0] = v173;	// L252
      float v174 = v161[v165][0][1];	// L253
      float v175 = v163[v166][0][1];	// L254
      float v176 = v164[v166][0][1];	// L255
      float v177 = (v165 == 0) ? v175 : v176;	// L256
      float v178 = v174 * v168;	// L257
      float v179 = v177 + v178;	// L258
      v164[v166][0][1] = v179;	// L259
      float v180 = v161[v165][1][0];	// L260
      float v181 = v163[v166][1][0];	// L261
      float v182 = v164[v166][1][0];	// L262
      float v183 = (v165 == 0) ? v181 : v182;	// L263
      float v184 = v180 * v168;	// L264
      float v185 = v183 + v184;	// L265
      v164[v166][1][0] = v185;	// L266
      float v186 = v161[v165][1][1];	// L267
      float v187 = v163[v166][1][1];	// L268
      float v188 = v164[v166][1][1];	// L269
      float v189 = (v165 == 0) ? v187 : v188;	// L270
      float v190 = v186 * v168;	// L271
      float v191 = v189 + v190;	// L272
      v164[v166][1][1] = v191;	// L273
    }
  }
}

void forward_node16(
  float v192[512][4][4],
  float v193[8][2][2],
  int v194,
  int v195,
  int v196
) {	// L278
  #pragma HLS inline
  #pragma HLS array_partition variable=v192 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v192 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v193 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v193 cyclic factor=2 dim=3
  #pragma HLS resource variable=v193 core=ram_t2p_bram

  for (int v197 = 0; v197 < 8; v197 += 1) {	// L279
    #pragma HLS pipeline II=1
    float v198 = v192[(v197 + (v194 * 8))][(v195 * 2)][(v196 * 2)];	// L280
    v193[v197][0][0] = v198;	// L281
    float v199 = v192[(v197 + (v194 * 8))][(v195 * 2)][((v196 * 2) + 1)];	// L282
    v193[v197][0][1] = v199;	// L283
    float v200 = v192[(v197 + (v194 * 8))][((v195 * 2) + 1)][(v196 * 2)];	// L284
    v193[v197][1][0] = v200;	// L285
    float v201 = v192[(v197 + (v194 * 8))][((v195 * 2) + 1)][((v196 * 2) + 1)];	// L286
    v193[v197][1][1] = v201;	// L287
  }
}

void forward_node17(
  float v202[512][512][3][3],
  float v203[8][8],
  int v204,
  int v205,
  int v206,
  int v207
) {	// L291
  #pragma HLS inline
  #pragma HLS resource variable=v203 core=ram_t2p_bram

  for (int v208 = 0; v208 < 8; v208 += 1) {	// L292
    for (int v209 = 0; v209 < 8; v209 += 1) {	// L293
      #pragma HLS pipeline II=1
      float v210 = v202[(v208 + (v206 * 8))][(v209 + (v207 * 8))][v204][v205];	// L294
      v203[v208][v209] = v210;	// L295
    }
  }
}

void forward_node18(
  float v211[512][4][4],
  float v212[8][2][2],
  int v213,
  int v214,
  int v215,
  int v216,
  int v217
) {	// L300
  #pragma HLS inline
  #pragma HLS array_partition variable=v211 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v211 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v212 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v212 cyclic factor=2 dim=3
  #pragma HLS resource variable=v212 core=ram_t2p_bram

  for (int v218 = 0; v218 < 8; v218 += 1) {	// L301
    #pragma HLS pipeline II=1
    float v219 = v211[(v218 + (v213 * 8))][((v214 + (v215 * 2)) - 1)][((v216 + (v217 * 2)) - 1)];	// L302
    v212[v218][0][0] = v219;	// L303
    float v220 = v211[(v218 + (v213 * 8))][((v214 + (v215 * 2)) - 1)][(v216 + (v217 * 2))];	// L304
    v212[v218][0][1] = v220;	// L305
    float v221 = v211[(v218 + (v213 * 8))][(v214 + (v215 * 2))][((v216 + (v217 * 2)) - 1)];	// L306
    v212[v218][1][0] = v221;	// L307
    float v222 = v211[(v218 + (v213 * 8))][(v214 + (v215 * 2))][(v216 + (v217 * 2))];	// L308
    v212[v218][1][1] = v222;	// L309
  }
}

void forward_node13(
  float v223[512][4][4],
  float v224[512][512][3][3],
  float v225[512][4][4],
  float v226[512][4][4]
) {	// L313
  #pragma HLS array_partition variable=v223 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v223 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v225 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v225 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v226 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v226 cyclic factor=2 dim=3

  for (int v227 = 0; v227 < 147456; v227 += 1) {	// L314
    #pragma HLS dataflow
    int v228 = (v227 % 2);	// L315
    int v229 = ((v227 / 2) % 2);	// L316
    int v230 = (((v227 / 2) / 2) % 64);	// L317
    int v231 = ((((v227 / 2) / 2) / 64) % 3);	// L318
    int v232 = (((((v227 / 2) / 2) / 64) / 3) % 3);	// L319
    int v233 = (((((v227 / 2) / 2) / 64) / 3) / 3);	// L320
    float v234[8][2][2];	// L321
    #pragma HLS array_partition variable=v234 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v234 cyclic factor=2 dim=3
    #pragma HLS resource variable=v234 core=ram_t2p_bram

    float v235[8][8];	// L322
    #pragma HLS resource variable=v235 core=ram_t2p_bram

    float v236[8][2][2];	// L323
    #pragma HLS array_partition variable=v236 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v236 cyclic factor=2 dim=3
    #pragma HLS resource variable=v236 core=ram_t2p_bram

    forward_node18(v223, v236, v233, v232, v229, v231, v228);	// L324
    forward_node17(v224, v235, v232, v231, v230, v233);	// L325
    forward_node16(v225, v234, v230, v229, v228);	// L326
    float v237[8][2][2];	// L327
    #pragma HLS array_partition variable=v237 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v237 cyclic factor=2 dim=3
    #pragma HLS resource variable=v237 core=ram_t2p_bram

    forward_node15(v236, v235, v234, v237);	// L328
    forward_node14(v237, v226, v230, v229, v228);	// L329
  }
}

void forward_node20(
  float v238[8][2][2],
  float v239[512][4][4],
  int v240,
  int v241,
  int v242
) {	// L333
  #pragma HLS inline
  #pragma HLS resource variable=v238 core=ram_t2p_bram

  for (int v243 = 0; v243 < 8; v243 += 1) {	// L334
    for (int v244 = 0; v244 < 2; v244 += 1) {	// L335
      for (int v245 = 0; v245 < 2; v245 += 1) {	// L336
        #pragma HLS pipeline II=1
        float v246 = v238[v243][v244][v245];	// L337
        v239[(v243 + (v240 * 8))][(v244 + (v241 * 2))][(v245 + (v242 * 2))] = v246;	// L338
      }
    }
  }
}

void forward_node21(
  float v247[512],
  float v248[512],
  float v249[512],
  float v250[512],
  float v251[8][2][2],
  float v252[8][2][2],
  int v253
) {	// L344
  #pragma HLS inline
  #pragma HLS resource variable=v247 core=ram_t2p_bram

  #pragma HLS resource variable=v248 core=ram_t2p_bram

  #pragma HLS resource variable=v249 core=ram_t2p_bram

  #pragma HLS resource variable=v250 core=ram_t2p_bram

  #pragma HLS resource variable=v251 core=ram_t2p_bram

  #pragma HLS resource variable=v252 core=ram_t2p_bram

  for (int v254 = 0; v254 < 8; v254 += 1) {	// L347
    for (int v255 = 0; v255 < 2; v255 += 1) {	// L348
      for (int v256 = 0; v256 < 2; v256 += 1) {	// L349
        #pragma HLS pipeline II=1
        float v257 = v251[v254][v255][v256];	// L350
        float v258 = v247[(v254 + (v253 * 8))];	// L351
        float v259 = v249[(v254 + (v253 * 8))];	// L352
        float v260 = v248[(v254 + (v253 * 8))];	// L353
        float v261 = v250[(v254 + (v253 * 8))];	// L354
        float v262 = (double)0.000010;	// L355
        float v263 = v261 + v262;	// L356
        float v264 = 1.0 / sqrt(v263);	// L357
        float v265 = v257 - v260;	// L358
        float v266 = v265 * v264;	// L359
        float v267 = v266 * v258;	// L360
        float v268 = v267 + v259;	// L361
        bool v269 = v268 > (float)0.000000;	// L362
        float v270 = v269 ? v268 : (float)0.000000;	// L363
        v252[v254][v255][v256] = v270;	// L364
      }
    }
  }
}

void forward_node22(
  float v271[512][4][4],
  float v272[8][2][2],
  int v273,
  int v274,
  int v275
) {	// L370
  #pragma HLS inline
  #pragma HLS resource variable=v272 core=ram_t2p_bram

  for (int v276 = 0; v276 < 8; v276 += 1) {	// L371
    for (int v277 = 0; v277 < 2; v277 += 1) {	// L372
      for (int v278 = 0; v278 < 2; v278 += 1) {	// L373
        #pragma HLS pipeline II=1
        float v279 = v271[(v276 + (v273 * 8))][(v277 + (v274 * 2))][(v278 + (v275 * 2))];	// L374
        v272[v276][v277][v278] = v279;	// L375
      }
    }
  }
}

void forward_node19(
  float v280[512],
  float v281[512],
  float v282[512][4][4],
  float v283[512],
  float v284[512],
  float v285[512][4][4]
) {	// L381
  #pragma HLS resource variable=v280 core=ram_t2p_bram

  #pragma HLS resource variable=v281 core=ram_t2p_bram

  #pragma HLS resource variable=v283 core=ram_t2p_bram

  #pragma HLS resource variable=v284 core=ram_t2p_bram

  for (int v286 = 0; v286 < 256; v286 += 1) {	// L382
    #pragma HLS dataflow
    int v287 = (v286 % 2);	// L383
    int v288 = ((v286 / 2) % 2);	// L384
    int v289 = ((v286 / 2) / 2);	// L385
    float v290[8][2][2];	// L386
    #pragma HLS resource variable=v290 core=ram_t2p_bram

    float v291[8][2][2];	// L387
    #pragma HLS resource variable=v291 core=ram_t2p_bram

    forward_node22(v282, v291, v289, v288, v287);	// L388
    forward_node21(v283, v284, v280, v281, v291, v290, v289);	// L389
    forward_node20(v290, v285, v289, v288, v287);	// L390
  }
}

void forward_node24(
  float v292[8][2][2],
  float v293[512][4][4],
  int v294,
  int v295,
  int v296
) {	// L394
  #pragma HLS inline
  #pragma HLS array_partition variable=v292 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v292 cyclic factor=2 dim=3
  #pragma HLS resource variable=v292 core=ram_t2p_bram

  #pragma HLS array_partition variable=v293 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v293 cyclic factor=2 dim=3

  for (int v297 = 0; v297 < 8; v297 += 1) {	// L395
    #pragma HLS pipeline II=1
    float v298 = v292[v297][0][0];	// L396
    v293[(v297 + (v294 * 8))][(v295 * 2)][(v296 * 2)] = v298;	// L397
    float v299 = v292[v297][0][1];	// L398
    v293[(v297 + (v294 * 8))][(v295 * 2)][((v296 * 2) + 1)] = v299;	// L399
    float v300 = v292[v297][1][0];	// L400
    v293[(v297 + (v294 * 8))][((v295 * 2) + 1)][(v296 * 2)] = v300;	// L401
    float v301 = v292[v297][1][1];	// L402
    v293[(v297 + (v294 * 8))][((v295 * 2) + 1)][((v296 * 2) + 1)] = v301;	// L403
  }
}

void forward_node25(
  float v302[8][8],
  float v303[8][2][2],
  float v304[8][2][2],
  float v305[8][2][2],
  float v306[8][2][2],
  int v307,
  int v308,
  int v309
) {	// L407
  #pragma HLS inline
  #pragma HLS resource variable=v302 core=ram_t2p_bram

  #pragma HLS array_partition variable=v303 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v303 cyclic factor=2 dim=3
  #pragma HLS resource variable=v303 core=ram_t2p_bram

  #pragma HLS array_partition variable=v304 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v304 cyclic factor=2 dim=3
  #pragma HLS resource variable=v304 core=ram_t2p_bram

  #pragma HLS array_partition variable=v305 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v305 cyclic factor=2 dim=3
  #pragma HLS resource variable=v305 core=ram_t2p_bram

  #pragma HLS array_partition variable=v306 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v306 cyclic factor=2 dim=3
  #pragma HLS resource variable=v306 core=ram_t2p_bram

  for (int v310 = 0; v310 < 8; v310 += 1) {	// L408
    for (int v311 = 0; v311 < 8; v311 += 1) {	// L409
      #pragma HLS pipeline II=1
      float v312 = v304[v311][0][0];	// L410
      float v313 = v305[v311][0][0];	// L411
      float v314 = v306[v311][0][0];	// L412
      float v315 = (v310 == 0) ? v313 : v314;	// L413
      float v316 = ((v310 + (v307 * 8)) == 0 && v309 == 0 && v308 == 0) ? v312 : v315;	// L414
      float v317 = v303[v310][0][0];	// L415
      float v318 = v302[v311][v310];	// L416
      float v319 = v317 * v318;	// L417
      float v320 = v316 + v319;	// L418
      v306[v311][0][0] = v320;	// L419
      float v321 = v304[v311][0][1];	// L420
      float v322 = v305[v311][0][1];	// L421
      float v323 = v306[v311][0][1];	// L422
      float v324 = (v310 == 0) ? v322 : v323;	// L423
      float v325 = ((v310 + (v307 * 8)) == 0 && v309 == 0 && v308 == 0) ? v321 : v324;	// L424
      float v326 = v303[v310][0][1];	// L425
      float v327 = v326 * v318;	// L426
      float v328 = v325 + v327;	// L427
      v306[v311][0][1] = v328;	// L428
      float v329 = v304[v311][1][0];	// L429
      float v330 = v305[v311][1][0];	// L430
      float v331 = v306[v311][1][0];	// L431
      float v332 = (v310 == 0) ? v330 : v331;	// L432
      float v333 = ((v310 + (v307 * 8)) == 0 && v309 == 0 && v308 == 0) ? v329 : v332;	// L433
      float v334 = v303[v310][1][0];	// L434
      float v335 = v334 * v318;	// L435
      float v336 = v333 + v335;	// L436
      v306[v311][1][0] = v336;	// L437
      float v337 = v304[v311][1][1];	// L438
      float v338 = v305[v311][1][1];	// L439
      float v339 = v306[v311][1][1];	// L440
      float v340 = (v310 == 0) ? v338 : v339;	// L441
      float v341 = ((v310 + (v307 * 8)) == 0 && v309 == 0 && v308 == 0) ? v337 : v340;	// L442
      float v342 = v303[v310][1][1];	// L443
      float v343 = v342 * v318;	// L444
      float v344 = v341 + v343;	// L445
      v306[v311][1][1] = v344;	// L446
    }
  }
}

void forward_node26(
  float v345[512][512][3][3],
  float v346[8][8],
  int v347,
  int v348,
  int v349,
  int v350
) {	// L451
  #pragma HLS inline
  #pragma HLS resource variable=v346 core=ram_t2p_bram

  for (int v351 = 0; v351 < 8; v351 += 1) {	// L452
    for (int v352 = 0; v352 < 8; v352 += 1) {	// L453
      #pragma HLS pipeline II=1
      float v353 = v345[(v351 + (v349 * 8))][(v352 + (v350 * 8))][v347][v348];	// L454
      v346[v351][v352] = v353;	// L455
    }
  }
}

void forward_node27(
  float v354[512][4][4],
  float v355[8][2][2],
  int v356,
  int v357,
  int v358,
  int v359,
  int v360
) {	// L460
  #pragma HLS inline
  #pragma HLS array_partition variable=v354 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v354 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v355 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v355 cyclic factor=2 dim=3
  #pragma HLS resource variable=v355 core=ram_t2p_bram

  for (int v361 = 0; v361 < 8; v361 += 1) {	// L461
    #pragma HLS pipeline II=1
    float v362 = v354[(v361 + (v356 * 8))][((v357 + (v358 * 2)) - 1)][((v359 + (v360 * 2)) - 1)];	// L462
    v355[v361][0][0] = v362;	// L463
    float v363 = v354[(v361 + (v356 * 8))][((v357 + (v358 * 2)) - 1)][(v359 + (v360 * 2))];	// L464
    v355[v361][0][1] = v363;	// L465
    float v364 = v354[(v361 + (v356 * 8))][(v357 + (v358 * 2))][((v359 + (v360 * 2)) - 1)];	// L466
    v355[v361][1][0] = v364;	// L467
    float v365 = v354[(v361 + (v356 * 8))][(v357 + (v358 * 2))][(v359 + (v360 * 2))];	// L468
    v355[v361][1][1] = v365;	// L469
  }
}

void forward_node28(
  float v366[512][4][4],
  float v367[8][2][2],
  int v368,
  int v369,
  int v370
) {	// L473
  #pragma HLS inline
  #pragma HLS array_partition variable=v366 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v366 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v367 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v367 cyclic factor=2 dim=3
  #pragma HLS resource variable=v367 core=ram_t2p_bram

  for (int v371 = 0; v371 < 8; v371 += 1) {	// L474
    #pragma HLS pipeline II=1
    float v372 = v366[(v371 + (v368 * 8))][(v369 * 2)][(v370 * 2)];	// L475
    v367[v371][0][0] = v372;	// L476
    float v373 = v366[(v371 + (v368 * 8))][(v369 * 2)][((v370 * 2) + 1)];	// L477
    v367[v371][0][1] = v373;	// L478
    float v374 = v366[(v371 + (v368 * 8))][((v369 * 2) + 1)][(v370 * 2)];	// L479
    v367[v371][1][0] = v374;	// L480
    float v375 = v366[(v371 + (v368 * 8))][((v369 * 2) + 1)][((v370 * 2) + 1)];	// L481
    v367[v371][1][1] = v375;	// L482
  }
}

void forward_node29(
  float v376[512][4][4],
  float v377[8][2][2],
  int v378,
  int v379,
  int v380
) {	// L486
  #pragma HLS inline
  #pragma HLS array_partition variable=v376 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v376 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v377 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v377 cyclic factor=2 dim=3
  #pragma HLS resource variable=v377 core=ram_t2p_bram

  for (int v381 = 0; v381 < 8; v381 += 1) {	// L487
    #pragma HLS pipeline II=1
    float v382 = v376[(v381 + (v378 * 8))][(v379 * 2)][(v380 * 2)];	// L488
    v377[v381][0][0] = v382;	// L489
    float v383 = v376[(v381 + (v378 * 8))][(v379 * 2)][((v380 * 2) + 1)];	// L490
    v377[v381][0][1] = v383;	// L491
    float v384 = v376[(v381 + (v378 * 8))][((v379 * 2) + 1)][(v380 * 2)];	// L492
    v377[v381][1][0] = v384;	// L493
    float v385 = v376[(v381 + (v378 * 8))][((v379 * 2) + 1)][((v380 * 2) + 1)];	// L494
    v377[v381][1][1] = v385;	// L495
  }
}

void forward_node23(
  float v386[512][512][3][3],
  float v387[512][4][4],
  float v388[512][4][4],
  float v389[512][4][4],
  float v390[512][4][4]
) {	// L499
  #pragma HLS array_partition variable=v387 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v387 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v388 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v388 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v389 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v389 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v390 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v390 cyclic factor=2 dim=3

  for (int v391 = 0; v391 < 147456; v391 += 1) {	// L500
    #pragma HLS dataflow
    int v392 = (v391 % 2);	// L501
    int v393 = ((v391 / 2) % 2);	// L502
    int v394 = (((v391 / 2) / 2) % 64);	// L503
    int v395 = ((((v391 / 2) / 2) / 64) % 3);	// L504
    int v396 = (((((v391 / 2) / 2) / 64) / 3) % 3);	// L505
    int v397 = (((((v391 / 2) / 2) / 64) / 3) / 3);	// L506
    float v398[8][8];	// L507
    #pragma HLS resource variable=v398 core=ram_t2p_bram

    float v399[8][2][2];	// L508
    #pragma HLS array_partition variable=v399 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v399 cyclic factor=2 dim=3
    #pragma HLS resource variable=v399 core=ram_t2p_bram

    float v400[8][2][2];	// L509
    #pragma HLS array_partition variable=v400 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v400 cyclic factor=2 dim=3
    #pragma HLS resource variable=v400 core=ram_t2p_bram

    float v401[8][2][2];	// L510
    #pragma HLS array_partition variable=v401 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v401 cyclic factor=2 dim=3
    #pragma HLS resource variable=v401 core=ram_t2p_bram

    forward_node29(v388, v401, v394, v393, v392);	// L511
    forward_node28(v389, v400, v394, v393, v392);	// L512
    forward_node27(v387, v399, v397, v396, v393, v395, v392);	// L513
    forward_node26(v386, v398, v396, v395, v394, v397);	// L514
    float v402[8][2][2];	// L515
    #pragma HLS array_partition variable=v402 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v402 cyclic factor=2 dim=3
    #pragma HLS resource variable=v402 core=ram_t2p_bram

    forward_node25(v398, v399, v401, v400, v402, v397, v395, v396);	// L516
    forward_node24(v402, v390, v394, v393, v392);	// L517
  }
}

void forward_node31(
  float v403[8][2][2],
  float v404[512][4][4],
  int v405,
  int v406,
  int v407
) {	// L521
  #pragma HLS inline
  #pragma HLS resource variable=v403 core=ram_t2p_bram

  for (int v408 = 0; v408 < 8; v408 += 1) {	// L522
    for (int v409 = 0; v409 < 2; v409 += 1) {	// L523
      for (int v410 = 0; v410 < 2; v410 += 1) {	// L524
        #pragma HLS pipeline II=1
        float v411 = v403[v408][v409][v410];	// L525
        v404[(v408 + (v405 * 8))][(v409 + (v406 * 2))][(v410 + (v407 * 2))] = v411;	// L526
      }
    }
  }
}

void forward_node32(
  float v412[512],
  float v413[512],
  float v414[512],
  float v415[512],
  float v416[512],
  float v417[512],
  float v418[512],
  float v419[8][2][2],
  float v420[8][2][2],
  float v421[8][2][2],
  int v422
) {	// L532
  #pragma HLS inline
  #pragma HLS resource variable=v412 core=ram_t2p_bram

  #pragma HLS resource variable=v413 core=ram_t2p_bram

  #pragma HLS resource variable=v414 core=ram_t2p_bram

  #pragma HLS resource variable=v415 core=ram_t2p_bram

  #pragma HLS resource variable=v416 core=ram_t2p_bram

  #pragma HLS resource variable=v417 core=ram_t2p_bram

  #pragma HLS resource variable=v418 core=ram_t2p_bram

  #pragma HLS resource variable=v419 core=ram_t2p_bram

  #pragma HLS resource variable=v420 core=ram_t2p_bram

  #pragma HLS resource variable=v421 core=ram_t2p_bram

  for (int v423 = 0; v423 < 8; v423 += 1) {	// L535
    for (int v424 = 0; v424 < 2; v424 += 1) {	// L536
      for (int v425 = 0; v425 < 2; v425 += 1) {	// L537
        #pragma HLS pipeline II=1
        float v426 = v420[v423][v424][v425];	// L538
        float v427 = v416[(v423 + (v422 * 8))];	// L539
        float v428 = v415[(v423 + (v422 * 8))];	// L540
        float v429 = v412[(v423 + (v422 * 8))];	// L541
        float v430 = v418[(v423 + (v422 * 8))];	// L542
        float v431 = v419[v423][v424][v425];	// L543
        float v432 = v414[(v423 + (v422 * 8))];	// L544
        float v433 = v413[(v423 + (v422 * 8))];	// L545
        float v434 = v417[(v423 + (v422 * 8))];	// L546
        float v435 = (double)0.000010;	// L547
        float v436 = v434 + v435;	// L548
        float v437 = 1.0 / sqrt(v436);	// L549
        float v438 = v431 - v433;	// L550
        float v439 = v438 * v437;	// L551
        float v440 = v439 * v432;	// L552
        float v441 = v440 + v428;	// L553
        float v442 = v430 + v435;	// L554
        float v443 = 1.0 / sqrt(v442);	// L555
        float v444 = v426 - v429;	// L556
        float v445 = v444 * v443;	// L557
        float v446 = v445 * v427;	// L558
        float v447 = v446 + v428;	// L559
        float v448 = v447 + v441;	// L560
        bool v449 = v448 > (float)0.000000;	// L561
        float v450 = v449 ? v448 : (float)0.000000;	// L562
        v421[v423][v424][v425] = v450;	// L563
      }
    }
  }
}

void forward_node33(
  float v451[512][4][4],
  float v452[8][2][2],
  int v453,
  int v454,
  int v455
) {	// L569
  #pragma HLS inline
  #pragma HLS resource variable=v452 core=ram_t2p_bram

  for (int v456 = 0; v456 < 8; v456 += 1) {	// L570
    for (int v457 = 0; v457 < 2; v457 += 1) {	// L571
      for (int v458 = 0; v458 < 2; v458 += 1) {	// L572
        #pragma HLS pipeline II=1
        float v459 = v451[(v456 + (v453 * 8))][(v457 + (v454 * 2))][(v458 + (v455 * 2))];	// L573
        v452[v456][v457][v458] = v459;	// L574
      }
    }
  }
}

void forward_node34(
  float v460[512][4][4],
  float v461[8][2][2],
  int v462,
  int v463,
  int v464
) {	// L580
  #pragma HLS inline
  #pragma HLS resource variable=v461 core=ram_t2p_bram

  for (int v465 = 0; v465 < 8; v465 += 1) {	// L581
    for (int v466 = 0; v466 < 2; v466 += 1) {	// L582
      for (int v467 = 0; v467 < 2; v467 += 1) {	// L583
        #pragma HLS pipeline II=1
        float v468 = v460[(v465 + (v462 * 8))][(v466 + (v463 * 2))][(v467 + (v464 * 2))];	// L584
        v461[v465][v466][v467] = v468;	// L585
      }
    }
  }
}

void forward_node30(
  float v469[512],
  float v470[512][4][4],
  float v471[512],
  float v472[512],
  float v473[512][4][4],
  float v474[512],
  float v475[512],
  float v476[512],
  float v477[512],
  float v478[512][4][4]
) {	// L591
  #pragma HLS resource variable=v469 core=ram_t2p_bram

  #pragma HLS resource variable=v471 core=ram_t2p_bram

  #pragma HLS resource variable=v472 core=ram_t2p_bram

  #pragma HLS resource variable=v474 core=ram_t2p_bram

  #pragma HLS resource variable=v475 core=ram_t2p_bram

  #pragma HLS resource variable=v476 core=ram_t2p_bram

  #pragma HLS resource variable=v477 core=ram_t2p_bram

  for (int v479 = 0; v479 < 256; v479 += 1) {	// L592
    #pragma HLS dataflow
    int v480 = (v479 % 2);	// L593
    int v481 = ((v479 / 2) % 2);	// L594
    int v482 = ((v479 / 2) / 2);	// L595
    float v483[8][2][2];	// L596
    #pragma HLS resource variable=v483 core=ram_t2p_bram

    float v484[8][2][2];	// L597
    #pragma HLS resource variable=v484 core=ram_t2p_bram

    float v485[8][2][2];	// L598
    #pragma HLS resource variable=v485 core=ram_t2p_bram

    forward_node34(v473, v485, v482, v481, v480);	// L599
    forward_node33(v470, v484, v482, v481, v480);	// L600
    forward_node32(v476, v475, v474, v471, v472, v469, v477, v484, v485, v483, v482);	// L601
    forward_node31(v483, v478, v482, v481, v480);	// L602
  }
}

void forward_node36(
  float v486[8][2][2],
  float v487[512][4][4],
  int v488,
  int v489,
  int v490
) {	// L606
  #pragma HLS inline
  #pragma HLS resource variable=v486 core=ram_t2p_bram

  for (int v491 = 0; v491 < 8; v491 += 1) {	// L607
    for (int v492 = 0; v492 < 2; v492 += 1) {	// L608
      for (int v493 = 0; v493 < 2; v493 += 1) {	// L609
        #pragma HLS pipeline II=1
        float v494 = v486[v491][v492][v493];	// L610
        v487[(v491 + (v488 * 8))][(v492 + (v489 * 2))][(v493 + (v490 * 2))] = v494;	// L611
      }
    }
  }
}

void forward_node37(
  float v495[8][2][2],
  float v496[8][2][2],
  float v497[8][8],
  float v498[8][2][2],
  float v499[8][2][2],
  int v500
) {	// L617
  #pragma HLS inline
  #pragma HLS resource variable=v495 core=ram_t2p_bram

  #pragma HLS resource variable=v496 core=ram_t2p_bram

  #pragma HLS resource variable=v497 core=ram_t2p_bram

  #pragma HLS resource variable=v498 core=ram_t2p_bram

  #pragma HLS resource variable=v499 core=ram_t2p_bram

  for (int v501 = 0; v501 < 8; v501 += 1) {	// L618
    for (int v502 = 0; v502 < 8; v502 += 1) {	// L619
      for (int v503 = 0; v503 < 2; v503 += 1) {	// L620
        for (int v504 = 0; v504 < 2; v504 += 1) {	// L621
          #pragma HLS pipeline II=1
          float v505 = v495[v502][v503][v504];	// L622
          float v506 = v498[v502][v503][v504];	// L623
          float v507 = v499[v502][v503][v504];	// L624
          float v508 = (v501 == 0) ? v506 : v507;	// L625
          float v509 = ((v501 + (v500 * 8)) == 0) ? v505 : v508;	// L626
          float v510 = v496[v501][v503][v504];	// L627
          float v511 = v497[v502][v501];	// L628
          float v512 = v510 * v511;	// L629
          float v513 = v509 + v512;	// L630
          v499[v502][v503][v504] = v513;	// L631
        }
      }
    }
  }
}

void forward_node38(
  float v514[512][256],
  float v515[8][8],
  int v516,
  int v517
) {	// L638
  #pragma HLS inline
  #pragma HLS resource variable=v515 core=ram_t2p_bram

  for (int v518 = 0; v518 < 8; v518 += 1) {	// L639
    for (int v519 = 0; v519 < 8; v519 += 1) {	// L640
      #pragma HLS pipeline II=1
      float v520 = v514[(v518 + (v516 * 8))][(v519 + (v517 * 8))];	// L641
      v515[v518][v519] = v520;	// L642
    }
  }
}

void forward_node39(
  float v521[256][8][8],
  float v522[8][2][2],
  int v523,
  int v524,
  int v525
) {	// L647
  #pragma HLS inline
  #pragma HLS resource variable=v522 core=ram_t2p_bram

  for (int v526 = 0; v526 < 8; v526 += 1) {	// L648
    for (int v527 = 0; v527 < 2; v527 += 1) {	// L649
      for (int v528 = 0; v528 < 2; v528 += 1) {	// L650
        #pragma HLS pipeline II=1
        float v529 = v521[(v526 + (v523 * 8))][((v527 * 2) + (v524 * 4))][((v528 * 2) + (v525 * 4))];	// L651
        v522[v526][v527][v528] = v529;	// L652
      }
    }
  }
}

void forward_node40(
  float v530[512][4][4],
  float v531[8][2][2],
  int v532,
  int v533,
  int v534
) {	// L658
  #pragma HLS inline
  #pragma HLS resource variable=v531 core=ram_t2p_bram

  for (int v535 = 0; v535 < 8; v535 += 1) {	// L659
    for (int v536 = 0; v536 < 2; v536 += 1) {	// L660
      for (int v537 = 0; v537 < 2; v537 += 1) {	// L661
        #pragma HLS pipeline II=1
        float v538 = v530[(v535 + (v532 * 8))][(v536 + (v533 * 2))][(v537 + (v534 * 2))];	// L662
        v531[v535][v536][v537] = v538;	// L663
      }
    }
  }
}

void forward_node41(
  float v539[512][4][4],
  float v540[8][2][2],
  int v541,
  int v542,
  int v543
) {	// L669
  #pragma HLS inline
  #pragma HLS resource variable=v540 core=ram_t2p_bram

  for (int v544 = 0; v544 < 8; v544 += 1) {	// L670
    for (int v545 = 0; v545 < 2; v545 += 1) {	// L671
      for (int v546 = 0; v546 < 2; v546 += 1) {	// L672
        #pragma HLS pipeline II=1
        float v547 = v539[(v544 + (v541 * 8))][(v545 + (v542 * 2))][(v546 + (v543 * 2))];	// L673
        v540[v544][v545][v546] = v547;	// L674
      }
    }
  }
}

void forward_node35(
  float v548[256][8][8],
  float v549[512][256],
  float v550[512][4][4],
  float v551[512][4][4],
  float v552[512][4][4]
) {	// L680
  for (int v553 = 0; v553 < 8192; v553 += 1) {	// L681
    #pragma HLS dataflow
    int v554 = (v553 % 2);	// L682
    int v555 = ((v553 / 2) % 2);	// L683
    int v556 = (((v553 / 2) / 2) % 64);	// L684
    int v557 = (((v553 / 2) / 2) / 64);	// L685
    float v558[8][8];	// L686
    #pragma HLS resource variable=v558 core=ram_t2p_bram

    float v559[8][2][2];	// L687
    #pragma HLS resource variable=v559 core=ram_t2p_bram

    float v560[8][2][2];	// L688
    #pragma HLS resource variable=v560 core=ram_t2p_bram

    float v561[8][2][2];	// L689
    #pragma HLS resource variable=v561 core=ram_t2p_bram

    forward_node41(v550, v561, v556, v555, v554);	// L690
    forward_node40(v551, v560, v556, v555, v554);	// L691
    forward_node39(v548, v559, v557, v555, v554);	// L692
    forward_node38(v549, v558, v556, v557);	// L693
    float v562[8][2][2];	// L694
    #pragma HLS resource variable=v562 core=ram_t2p_bram

    forward_node37(v561, v559, v558, v560, v562, v557);	// L695
    forward_node36(v562, v552, v556, v555, v554);	// L696
  }
}

void forward_node43(
  float v563[8][2][2],
  float v564[512][4][4],
  int v565,
  int v566,
  int v567
) {	// L700
  #pragma HLS inline
  #pragma HLS array_partition variable=v563 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v563 cyclic factor=2 dim=3
  #pragma HLS resource variable=v563 core=ram_t2p_bram

  #pragma HLS array_partition variable=v564 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v564 cyclic factor=2 dim=3

  for (int v568 = 0; v568 < 8; v568 += 1) {	// L701
    #pragma HLS pipeline II=1
    float v569 = v563[v568][0][0];	// L702
    v564[(v568 + (v565 * 8))][(v566 * 2)][(v567 * 2)] = v569;	// L703
    float v570 = v563[v568][0][1];	// L704
    v564[(v568 + (v565 * 8))][(v566 * 2)][((v567 * 2) + 1)] = v570;	// L705
    float v571 = v563[v568][1][0];	// L706
    v564[(v568 + (v565 * 8))][((v566 * 2) + 1)][(v567 * 2)] = v571;	// L707
    float v572 = v563[v568][1][1];	// L708
    v564[(v568 + (v565 * 8))][((v566 * 2) + 1)][((v567 * 2) + 1)] = v572;	// L709
  }
}

void forward_node44(
  float v573[8][2][2],
  float v574[8][8],
  float v575[8][2][2],
  float v576[8][2][2],
  float v577[8][2][2],
  int v578,
  int v579,
  int v580
) {	// L713
  #pragma HLS inline
  #pragma HLS array_partition variable=v573 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v573 cyclic factor=2 dim=3
  #pragma HLS resource variable=v573 core=ram_t2p_bram

  #pragma HLS resource variable=v574 core=ram_t2p_bram

  #pragma HLS array_partition variable=v575 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v575 cyclic factor=2 dim=3
  #pragma HLS resource variable=v575 core=ram_t2p_bram

  #pragma HLS array_partition variable=v576 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v576 cyclic factor=2 dim=3
  #pragma HLS resource variable=v576 core=ram_t2p_bram

  #pragma HLS array_partition variable=v577 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v577 cyclic factor=2 dim=3
  #pragma HLS resource variable=v577 core=ram_t2p_bram

  for (int v581 = 0; v581 < 8; v581 += 1) {	// L714
    for (int v582 = 0; v582 < 8; v582 += 1) {	// L715
      #pragma HLS pipeline II=1
      float v583 = v573[v582][0][0];	// L716
      float v584 = v576[v582][0][0];	// L717
      float v585 = v577[v582][0][0];	// L718
      float v586 = (v581 == 0) ? v584 : v585;	// L719
      float v587 = ((v581 + (v578 * 8)) == 0 && v579 == 0 && v580 == 0) ? v583 : v586;	// L720
      float v588 = v575[v581][0][0];	// L721
      float v589 = v574[v582][v581];	// L722
      float v590 = v588 * v589;	// L723
      float v591 = v587 + v590;	// L724
      v577[v582][0][0] = v591;	// L725
      float v592 = v573[v582][0][1];	// L726
      float v593 = v576[v582][0][1];	// L727
      float v594 = v577[v582][0][1];	// L728
      float v595 = (v581 == 0) ? v593 : v594;	// L729
      float v596 = ((v581 + (v578 * 8)) == 0 && v579 == 0 && v580 == 0) ? v592 : v595;	// L730
      float v597 = v575[v581][0][1];	// L731
      float v598 = v597 * v589;	// L732
      float v599 = v596 + v598;	// L733
      v577[v582][0][1] = v599;	// L734
      float v600 = v573[v582][1][0];	// L735
      float v601 = v576[v582][1][0];	// L736
      float v602 = v577[v582][1][0];	// L737
      float v603 = (v581 == 0) ? v601 : v602;	// L738
      float v604 = ((v581 + (v578 * 8)) == 0 && v579 == 0 && v580 == 0) ? v600 : v603;	// L739
      float v605 = v575[v581][1][0];	// L740
      float v606 = v605 * v589;	// L741
      float v607 = v604 + v606;	// L742
      v577[v582][1][0] = v607;	// L743
      float v608 = v573[v582][1][1];	// L744
      float v609 = v576[v582][1][1];	// L745
      float v610 = v577[v582][1][1];	// L746
      float v611 = (v581 == 0) ? v609 : v610;	// L747
      float v612 = ((v581 + (v578 * 8)) == 0 && v579 == 0 && v580 == 0) ? v608 : v611;	// L748
      float v613 = v575[v581][1][1];	// L749
      float v614 = v613 * v589;	// L750
      float v615 = v612 + v614;	// L751
      v577[v582][1][1] = v615;	// L752
    }
  }
}

void forward_node45(
  float v616[512][512][3][3],
  float v617[8][8],
  int v618,
  int v619,
  int v620,
  int v621
) {	// L757
  #pragma HLS inline
  #pragma HLS resource variable=v617 core=ram_t2p_bram

  for (int v622 = 0; v622 < 8; v622 += 1) {	// L758
    for (int v623 = 0; v623 < 8; v623 += 1) {	// L759
      #pragma HLS pipeline II=1
      float v624 = v616[(v622 + (v620 * 8))][(v623 + (v621 * 8))][v618][v619];	// L760
      v617[v622][v623] = v624;	// L761
    }
  }
}

void forward_node46(
  float v625[512][4][4],
  float v626[8][2][2],
  int v627,
  int v628,
  int v629,
  int v630,
  int v631
) {	// L766
  #pragma HLS inline
  #pragma HLS array_partition variable=v625 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v625 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v626 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v626 cyclic factor=2 dim=3
  #pragma HLS resource variable=v626 core=ram_t2p_bram

  for (int v632 = 0; v632 < 8; v632 += 1) {	// L767
    #pragma HLS pipeline II=1
    float v633 = v625[(v632 + (v627 * 8))][((v628 + (v629 * 2)) - 1)][((v630 + (v631 * 2)) - 1)];	// L768
    v626[v632][0][0] = v633;	// L769
    float v634 = v625[(v632 + (v627 * 8))][((v628 + (v629 * 2)) - 1)][(v630 + (v631 * 2))];	// L770
    v626[v632][0][1] = v634;	// L771
    float v635 = v625[(v632 + (v627 * 8))][(v628 + (v629 * 2))][((v630 + (v631 * 2)) - 1)];	// L772
    v626[v632][1][0] = v635;	// L773
    float v636 = v625[(v632 + (v627 * 8))][(v628 + (v629 * 2))][(v630 + (v631 * 2))];	// L774
    v626[v632][1][1] = v636;	// L775
  }
}

void forward_node47(
  float v637[512][4][4],
  float v638[8][2][2],
  int v639,
  int v640,
  int v641
) {	// L779
  #pragma HLS inline
  #pragma HLS array_partition variable=v637 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v637 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v638 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v638 cyclic factor=2 dim=3
  #pragma HLS resource variable=v638 core=ram_t2p_bram

  for (int v642 = 0; v642 < 8; v642 += 1) {	// L780
    #pragma HLS pipeline II=1
    float v643 = v637[(v642 + (v639 * 8))][(v640 * 2)][(v641 * 2)];	// L781
    v638[v642][0][0] = v643;	// L782
    float v644 = v637[(v642 + (v639 * 8))][(v640 * 2)][((v641 * 2) + 1)];	// L783
    v638[v642][0][1] = v644;	// L784
    float v645 = v637[(v642 + (v639 * 8))][((v640 * 2) + 1)][(v641 * 2)];	// L785
    v638[v642][1][0] = v645;	// L786
    float v646 = v637[(v642 + (v639 * 8))][((v640 * 2) + 1)][((v641 * 2) + 1)];	// L787
    v638[v642][1][1] = v646;	// L788
  }
}

void forward_node48(
  float v647[512][4][4],
  float v648[8][2][2],
  int v649,
  int v650,
  int v651
) {	// L792
  #pragma HLS inline
  #pragma HLS array_partition variable=v647 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v647 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v648 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v648 cyclic factor=2 dim=3
  #pragma HLS resource variable=v648 core=ram_t2p_bram

  for (int v652 = 0; v652 < 8; v652 += 1) {	// L793
    #pragma HLS pipeline II=1
    float v653 = v647[(v652 + (v649 * 8))][(v650 * 2)][(v651 * 2)];	// L794
    v648[v652][0][0] = v653;	// L795
    float v654 = v647[(v652 + (v649 * 8))][(v650 * 2)][((v651 * 2) + 1)];	// L796
    v648[v652][0][1] = v654;	// L797
    float v655 = v647[(v652 + (v649 * 8))][((v650 * 2) + 1)][(v651 * 2)];	// L798
    v648[v652][1][0] = v655;	// L799
    float v656 = v647[(v652 + (v649 * 8))][((v650 * 2) + 1)][((v651 * 2) + 1)];	// L800
    v648[v652][1][1] = v656;	// L801
  }
}

void forward_node42(
  float v657[512][4][4],
  float v658[512][512][3][3],
  float v659[512][4][4],
  float v660[512][4][4],
  float v661[512][4][4]
) {	// L805
  #pragma HLS array_partition variable=v657 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v657 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v659 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v659 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v660 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v660 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v661 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v661 cyclic factor=2 dim=3

  for (int v662 = 0; v662 < 147456; v662 += 1) {	// L806
    #pragma HLS dataflow
    int v663 = (v662 % 2);	// L807
    int v664 = ((v662 / 2) % 2);	// L808
    int v665 = (((v662 / 2) / 2) % 64);	// L809
    int v666 = ((((v662 / 2) / 2) / 64) % 3);	// L810
    int v667 = (((((v662 / 2) / 2) / 64) / 3) % 3);	// L811
    int v668 = (((((v662 / 2) / 2) / 64) / 3) / 3);	// L812
    float v669[8][8];	// L813
    #pragma HLS resource variable=v669 core=ram_t2p_bram

    float v670[8][2][2];	// L814
    #pragma HLS array_partition variable=v670 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v670 cyclic factor=2 dim=3
    #pragma HLS resource variable=v670 core=ram_t2p_bram

    float v671[8][2][2];	// L815
    #pragma HLS array_partition variable=v671 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v671 cyclic factor=2 dim=3
    #pragma HLS resource variable=v671 core=ram_t2p_bram

    float v672[8][2][2];	// L816
    #pragma HLS array_partition variable=v672 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v672 cyclic factor=2 dim=3
    #pragma HLS resource variable=v672 core=ram_t2p_bram

    forward_node48(v659, v672, v665, v664, v663);	// L817
    forward_node47(v660, v671, v665, v664, v663);	// L818
    forward_node46(v657, v670, v668, v667, v664, v666, v663);	// L819
    forward_node45(v658, v669, v667, v666, v665, v668);	// L820
    float v673[8][2][2];	// L821
    #pragma HLS array_partition variable=v673 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v673 cyclic factor=2 dim=3
    #pragma HLS resource variable=v673 core=ram_t2p_bram

    forward_node44(v672, v669, v670, v671, v673, v668, v667, v666);	// L822
    forward_node43(v673, v661, v665, v664, v663);	// L823
  }
}

void forward_node50(
  float v674[8][2][2],
  float v675[512][4][4],
  int v676,
  int v677,
  int v678
) {	// L827
  #pragma HLS inline
  #pragma HLS resource variable=v674 core=ram_t2p_bram

  for (int v679 = 0; v679 < 8; v679 += 1) {	// L828
    for (int v680 = 0; v680 < 2; v680 += 1) {	// L829
      for (int v681 = 0; v681 < 2; v681 += 1) {	// L830
        #pragma HLS pipeline II=1
        float v682 = v674[v679][v680][v681];	// L831
        v675[(v679 + (v676 * 8))][(v680 + (v677 * 2))][(v681 + (v678 * 2))] = v682;	// L832
      }
    }
  }
}

void forward_node51(
  float v683[512],
  float v684[512],
  float v685[512],
  float v686[8][2][2],
  float v687[512],
  float v688[8][2][2],
  int v689
) {	// L838
  #pragma HLS inline
  #pragma HLS resource variable=v683 core=ram_t2p_bram

  #pragma HLS resource variable=v684 core=ram_t2p_bram

  #pragma HLS resource variable=v685 core=ram_t2p_bram

  #pragma HLS resource variable=v686 core=ram_t2p_bram

  #pragma HLS resource variable=v687 core=ram_t2p_bram

  #pragma HLS resource variable=v688 core=ram_t2p_bram

  for (int v690 = 0; v690 < 8; v690 += 1) {	// L841
    for (int v691 = 0; v691 < 2; v691 += 1) {	// L842
      for (int v692 = 0; v692 < 2; v692 += 1) {	// L843
        #pragma HLS pipeline II=1
        float v693 = v686[v690][v691][v692];	// L844
        float v694 = v687[(v690 + (v689 * 8))];	// L845
        float v695 = v684[(v690 + (v689 * 8))];	// L846
        float v696 = v683[(v690 + (v689 * 8))];	// L847
        float v697 = v685[(v690 + (v689 * 8))];	// L848
        float v698 = (double)0.000010;	// L849
        float v699 = v697 + v698;	// L850
        float v700 = 1.0 / sqrt(v699);	// L851
        float v701 = v693 - v696;	// L852
        float v702 = v701 * v700;	// L853
        float v703 = v702 * v694;	// L854
        float v704 = v703 + v695;	// L855
        bool v705 = v704 > (float)0.000000;	// L856
        float v706 = v705 ? v704 : (float)0.000000;	// L857
        v688[v690][v691][v692] = v706;	// L858
      }
    }
  }
}

void forward_node52(
  float v707[512][4][4],
  float v708[8][2][2],
  int v709,
  int v710,
  int v711
) {	// L864
  #pragma HLS inline
  #pragma HLS resource variable=v708 core=ram_t2p_bram

  for (int v712 = 0; v712 < 8; v712 += 1) {	// L865
    for (int v713 = 0; v713 < 2; v713 += 1) {	// L866
      for (int v714 = 0; v714 < 2; v714 += 1) {	// L867
        #pragma HLS pipeline II=1
        float v715 = v707[(v712 + (v709 * 8))][(v713 + (v710 * 2))][(v714 + (v711 * 2))];	// L868
        v708[v712][v713][v714] = v715;	// L869
      }
    }
  }
}

void forward_node49(
  float v716[512],
  float v717[512],
  float v718[512][4][4],
  float v719[512],
  float v720[512],
  float v721[512][4][4]
) {	// L875
  #pragma HLS resource variable=v716 core=ram_t2p_bram

  #pragma HLS resource variable=v717 core=ram_t2p_bram

  #pragma HLS resource variable=v719 core=ram_t2p_bram

  #pragma HLS resource variable=v720 core=ram_t2p_bram

  for (int v722 = 0; v722 < 256; v722 += 1) {	// L876
    #pragma HLS dataflow
    int v723 = (v722 % 2);	// L877
    int v724 = ((v722 / 2) % 2);	// L878
    int v725 = ((v722 / 2) / 2);	// L879
    float v726[8][2][2];	// L880
    #pragma HLS resource variable=v726 core=ram_t2p_bram

    float v727[8][2][2];	// L881
    #pragma HLS resource variable=v727 core=ram_t2p_bram

    forward_node52(v718, v727, v725, v724, v723);	// L882
    forward_node51(v717, v719, v716, v727, v720, v726, v725);	// L883
    forward_node50(v726, v721, v725, v724, v723);	// L884
  }
}

void forward_node54(
  float v728[8][2][2],
  float v729[512][4][4],
  int v730,
  int v731,
  int v732
) {	// L888
  #pragma HLS inline
  #pragma HLS resource variable=v728 core=ram_t2p_bram

  for (int v733 = 0; v733 < 8; v733 += 1) {	// L889
    for (int v734 = 0; v734 < 2; v734 += 1) {	// L890
      for (int v735 = 0; v735 < 2; v735 += 1) {	// L891
        #pragma HLS pipeline II=1
        float v736 = v728[v733][v734][v735];	// L892
        v729[(v733 + (v730 * 8))][(v734 + (v731 * 2))][(v735 + (v732 * 2))] = v736;	// L893
      }
    }
  }
}

void forward_node55(
  float v737[8][2][2],
  float v738[8][2][2],
  float v739[8][8],
  float v740[8][2][2],
  float v741[8][2][2],
  int v742,
  int v743,
  int v744
) {	// L899
  #pragma HLS inline
  #pragma HLS resource variable=v737 core=ram_t2p_bram

  #pragma HLS resource variable=v738 core=ram_t2p_bram

  #pragma HLS resource variable=v739 core=ram_t2p_bram

  #pragma HLS resource variable=v740 core=ram_t2p_bram

  #pragma HLS resource variable=v741 core=ram_t2p_bram

  for (int v745 = 0; v745 < 8; v745 += 1) {	// L900
    for (int v746 = 0; v746 < 8; v746 += 1) {	// L901
      for (int v747 = 0; v747 < 2; v747 += 1) {	// L902
        for (int v748 = 0; v748 < 2; v748 += 1) {	// L903
          #pragma HLS pipeline II=1
          float v749 = v737[v746][v747][v748];	// L904
          float v750 = v740[v746][v747][v748];	// L905
          float v751 = v741[v746][v747][v748];	// L906
          float v752 = (v745 == 0) ? v750 : v751;	// L907
          float v753 = ((v745 + (v744 * 8)) == 0 && v742 == 0 && v743 == 0) ? v749 : v752;	// L908
          float v754 = v738[v745][v747][v748];	// L909
          float v755 = v739[v746][v745];	// L910
          float v756 = v754 * v755;	// L911
          float v757 = v753 + v756;	// L912
          v741[v746][v747][v748] = v757;	// L913
        }
      }
    }
  }
}

void forward_node56(
  float v758[512][256][3][3],
  float v759[8][8],
  int v760,
  int v761,
  int v762,
  int v763
) {	// L920
  #pragma HLS inline
  #pragma HLS resource variable=v759 core=ram_t2p_bram

  for (int v764 = 0; v764 < 8; v764 += 1) {	// L921
    for (int v765 = 0; v765 < 8; v765 += 1) {	// L922
      #pragma HLS pipeline II=1
      float v766 = v758[(v764 + (v762 * 8))][(v765 + (v763 * 8))][v760][v761];	// L923
      v759[v764][v765] = v766;	// L924
    }
  }
}

void forward_node57(
  float v767[256][8][8],
  float v768[8][2][2],
  int v769,
  int v770,
  int v771,
  int v772,
  int v773
) {	// L929
  #pragma HLS inline
  #pragma HLS resource variable=v768 core=ram_t2p_bram

  for (int v774 = 0; v774 < 8; v774 += 1) {	// L930
    for (int v775 = 0; v775 < 2; v775 += 1) {	// L931
      for (int v776 = 0; v776 < 2; v776 += 1) {	// L932
        #pragma HLS pipeline II=1
        float v777 = v767[(v774 + (v769 * 8))][((((v775 * 2) + v770) + (v771 * 4)) - 1)][((((v776 * 2) + v772) + (v773 * 4)) - 1)];	// L933
        v768[v774][v775][v776] = v777;	// L934
      }
    }
  }
}

void forward_node58(
  float v778[512][4][4],
  float v779[8][2][2],
  int v780,
  int v781,
  int v782
) {	// L940
  #pragma HLS inline
  #pragma HLS resource variable=v779 core=ram_t2p_bram

  for (int v783 = 0; v783 < 8; v783 += 1) {	// L941
    for (int v784 = 0; v784 < 2; v784 += 1) {	// L942
      for (int v785 = 0; v785 < 2; v785 += 1) {	// L943
        #pragma HLS pipeline II=1
        float v786 = v778[(v783 + (v780 * 8))][(v784 + (v781 * 2))][(v785 + (v782 * 2))];	// L944
        v779[v783][v784][v785] = v786;	// L945
      }
    }
  }
}

void forward_node59(
  float v787[512][4][4],
  float v788[8][2][2],
  int v789,
  int v790,
  int v791
) {	// L951
  #pragma HLS inline
  #pragma HLS resource variable=v788 core=ram_t2p_bram

  for (int v792 = 0; v792 < 8; v792 += 1) {	// L952
    for (int v793 = 0; v793 < 2; v793 += 1) {	// L953
      for (int v794 = 0; v794 < 2; v794 += 1) {	// L954
        #pragma HLS pipeline II=1
        float v795 = v787[(v792 + (v789 * 8))][(v793 + (v790 * 2))][(v794 + (v791 * 2))];	// L955
        v788[v792][v793][v794] = v795;	// L956
      }
    }
  }
}

void forward_node53(
  float v796[256][8][8],
  float v797[512][4][4],
  float v798[512][256][3][3],
  float v799[512][4][4],
  float v800[512][4][4]
) {	// L962
  for (int v801 = 0; v801 < 73728; v801 += 1) {	// L963
    #pragma HLS dataflow
    int v802 = (v801 % 2);	// L964
    int v803 = ((v801 / 2) % 2);	// L965
    int v804 = (((v801 / 2) / 2) % 64);	// L966
    int v805 = ((((v801 / 2) / 2) / 64) % 3);	// L967
    int v806 = (((((v801 / 2) / 2) / 64) / 3) % 3);	// L968
    int v807 = (((((v801 / 2) / 2) / 64) / 3) / 3);	// L969
    float v808[8][8];	// L970
    #pragma HLS resource variable=v808 core=ram_t2p_bram

    float v809[8][2][2];	// L971
    #pragma HLS resource variable=v809 core=ram_t2p_bram

    float v810[8][2][2];	// L972
    #pragma HLS resource variable=v810 core=ram_t2p_bram

    float v811[8][2][2];	// L973
    #pragma HLS resource variable=v811 core=ram_t2p_bram

    forward_node59(v797, v811, v804, v803, v802);	// L974
    forward_node58(v799, v810, v804, v803, v802);	// L975
    forward_node57(v796, v809, v807, v806, v803, v805, v802);	// L976
    forward_node56(v798, v808, v806, v805, v804, v807);	// L977
    float v812[8][2][2];	// L978
    #pragma HLS resource variable=v812 core=ram_t2p_bram

    forward_node55(v811, v809, v808, v810, v812, v806, v805, v807);	// L979
    forward_node54(v812, v800, v804, v803, v802);	// L980
  }
}

void forward_node61(
  float v813[8][4][4],
  float v814[256][8][8],
  int v815,
  int v816,
  int v817
) {	// L984
  #pragma HLS inline
  #pragma HLS resource variable=v813 core=ram_t2p_bram

  for (int v818 = 0; v818 < 8; v818 += 1) {	// L985
    for (int v819 = 0; v819 < 4; v819 += 1) {	// L986
      for (int v820 = 0; v820 < 4; v820 += 1) {	// L987
        #pragma HLS pipeline II=1
        float v821 = v813[v818][v819][v820];	// L988
        v814[(v818 + (v815 * 8))][(v819 + (v816 * 4))][(v820 + (v817 * 4))] = v821;	// L989
      }
    }
  }
}

void forward_node62(
  float v822[8][4][4],
  float v823[256],
  float v824[256],
  float v825[256],
  float v826[256],
  float v827[8][4][4],
  float v828[8][4][4],
  int v829
) {	// L995
  #pragma HLS inline
  #pragma HLS resource variable=v822 core=ram_t2p_bram

  #pragma HLS resource variable=v823 core=ram_t2p_bram

  #pragma HLS resource variable=v824 core=ram_t2p_bram

  #pragma HLS resource variable=v825 core=ram_t2p_bram

  #pragma HLS resource variable=v826 core=ram_t2p_bram

  #pragma HLS resource variable=v827 core=ram_t2p_bram

  #pragma HLS resource variable=v828 core=ram_t2p_bram

  for (int v830 = 0; v830 < 8; v830 += 1) {	// L998
    for (int v831 = 0; v831 < 4; v831 += 1) {	// L999
      for (int v832 = 0; v832 < 4; v832 += 1) {	// L1000
        #pragma HLS pipeline II=1
        float v833 = v827[v830][v831][v832];	// L1001
        float v834 = v825[(v830 + (v829 * 8))];	// L1002
        float v835 = v826[(v830 + (v829 * 8))];	// L1003
        float v836 = v824[(v830 + (v829 * 8))];	// L1004
        float v837 = v823[(v830 + (v829 * 8))];	// L1005
        float v838 = v822[v830][v831][v832];	// L1006
        float v839 = (double)0.000010;	// L1007
        float v840 = v837 + v839;	// L1008
        float v841 = 1.0 / sqrt(v840);	// L1009
        float v842 = v833 - v836;	// L1010
        float v843 = v842 * v841;	// L1011
        float v844 = v843 * v834;	// L1012
        float v845 = v844 + v835;	// L1013
        float v846 = v845 + v838;	// L1014
        bool v847 = v846 > (float)0.000000;	// L1015
        float v848 = v847 ? v846 : (float)0.000000;	// L1016
        v828[v830][v831][v832] = v848;	// L1017
      }
    }
  }
}

void forward_node63(
  float v849[256][8][8],
  float v850[8][4][4],
  int v851,
  int v852,
  int v853
) {	// L1023
  #pragma HLS inline
  #pragma HLS resource variable=v850 core=ram_t2p_bram

  for (int v854 = 0; v854 < 8; v854 += 1) {	// L1024
    for (int v855 = 0; v855 < 4; v855 += 1) {	// L1025
      for (int v856 = 0; v856 < 4; v856 += 1) {	// L1026
        #pragma HLS pipeline II=1
        float v857 = v849[(v854 + (v851 * 8))][(v855 + (v852 * 4))][(v856 + (v853 * 4))];	// L1027
        v850[v854][v855][v856] = v857;	// L1028
      }
    }
  }
}

void forward_node64(
  float v858[256][8][8],
  float v859[8][4][4],
  int v860,
  int v861,
  int v862
) {	// L1034
  #pragma HLS inline
  #pragma HLS resource variable=v859 core=ram_t2p_bram

  for (int v863 = 0; v863 < 8; v863 += 1) {	// L1035
    for (int v864 = 0; v864 < 4; v864 += 1) {	// L1036
      for (int v865 = 0; v865 < 4; v865 += 1) {	// L1037
        #pragma HLS pipeline II=1
        float v866 = v858[(v863 + (v860 * 8))][(v864 + (v861 * 4))][(v865 + (v862 * 4))];	// L1038
        v859[v863][v864][v865] = v866;	// L1039
      }
    }
  }
}

void forward_node60(
  float v867[256],
  float v868[256][8][8],
  float v869[256],
  float v870[256][8][8],
  float v871[256],
  float v872[256],
  float v873[256][8][8]
) {	// L1045
  #pragma HLS resource variable=v867 core=ram_t2p_bram

  #pragma HLS resource variable=v869 core=ram_t2p_bram

  #pragma HLS resource variable=v871 core=ram_t2p_bram

  #pragma HLS resource variable=v872 core=ram_t2p_bram

  for (int v874 = 0; v874 < 128; v874 += 1) {	// L1046
    #pragma HLS dataflow
    int v875 = (v874 % 2);	// L1047
    int v876 = ((v874 / 2) % 2);	// L1048
    int v877 = ((v874 / 2) / 2);	// L1049
    float v878[8][4][4];	// L1050
    #pragma HLS resource variable=v878 core=ram_t2p_bram

    float v879[8][4][4];	// L1051
    #pragma HLS resource variable=v879 core=ram_t2p_bram

    float v880[8][4][4];	// L1052
    #pragma HLS resource variable=v880 core=ram_t2p_bram

    forward_node64(v868, v880, v877, v876, v875);	// L1053
    forward_node63(v870, v879, v877, v876, v875);	// L1054
    forward_node62(v879, v872, v867, v871, v869, v880, v878, v877);	// L1055
    forward_node61(v878, v873, v877, v876, v875);	// L1056
  }
}

void forward_node66(
  float v881[8][4][4],
  float v882[256][8][8],
  int v883,
  int v884,
  int v885
) {	// L1060
  #pragma HLS inline
  #pragma HLS array_partition variable=v881 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v881 cyclic factor=2 dim=3
  #pragma HLS resource variable=v881 core=ram_t2p_bram

  #pragma HLS array_partition variable=v882 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v882 cyclic factor=2 dim=3

  for (int v886 = 0; v886 < 8; v886 += 1) {	// L1061
    for (int v887 = 0; v887 < 4; v887 += 2) {	// L1062
      for (int v888 = 0; v888 < 4; v888 += 2) {	// L1063
        #pragma HLS pipeline II=1
        float v889 = v881[v886][v887][v888];	// L1064
        v882[(v886 + (v883 * 8))][(v887 + (v884 * 4))][(v888 + (v885 * 4))] = v889;	// L1065
        float v890 = v881[v886][v887][(v888 + 1)];	// L1066
        v882[(v886 + (v883 * 8))][(v887 + (v884 * 4))][((v888 + (v885 * 4)) + 1)] = v890;	// L1067
        float v891 = v881[v886][(v887 + 1)][v888];	// L1068
        v882[(v886 + (v883 * 8))][((v887 + (v884 * 4)) + 1)][(v888 + (v885 * 4))] = v891;	// L1069
        float v892 = v881[v886][(v887 + 1)][(v888 + 1)];	// L1070
        v882[(v886 + (v883 * 8))][((v887 + (v884 * 4)) + 1)][((v888 + (v885 * 4)) + 1)] = v892;	// L1071
      }
    }
  }
}

void forward_node67(
  float v893[8][4][4],
  float v894[8][8],
  float v895[8][4][4],
  float v896[8][4][4]
) {	// L1077
  #pragma HLS inline
  #pragma HLS array_partition variable=v893 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v893 cyclic factor=2 dim=3
  #pragma HLS resource variable=v893 core=ram_t2p_bram

  #pragma HLS resource variable=v894 core=ram_t2p_bram

  #pragma HLS array_partition variable=v895 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v895 cyclic factor=2 dim=3
  #pragma HLS resource variable=v895 core=ram_t2p_bram

  #pragma HLS array_partition variable=v896 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v896 cyclic factor=2 dim=3
  #pragma HLS resource variable=v896 core=ram_t2p_bram

  for (int v897 = 0; v897 < 8; v897 += 1) {	// L1078
    for (int v898 = 0; v898 < 8; v898 += 1) {	// L1079
      for (int v899 = 0; v899 < 4; v899 += 2) {	// L1080
        for (int v900 = 0; v900 < 4; v900 += 2) {	// L1081
          #pragma HLS pipeline II=1
          float v901 = v893[v897][v899][v900];	// L1082
          float v902 = v894[v898][v897];	// L1083
          float v903 = v895[v898][v899][v900];	// L1084
          float v904 = v896[v898][v899][v900];	// L1085
          float v905 = (v897 == 0) ? v903 : v904;	// L1086
          float v906 = v901 * v902;	// L1087
          float v907 = v905 + v906;	// L1088
          v896[v898][v899][v900] = v907;	// L1089
          float v908 = v893[v897][v899][(v900 + 1)];	// L1090
          float v909 = v895[v898][v899][(v900 + 1)];	// L1091
          float v910 = v896[v898][v899][(v900 + 1)];	// L1092
          float v911 = (v897 == 0) ? v909 : v910;	// L1093
          float v912 = v908 * v902;	// L1094
          float v913 = v911 + v912;	// L1095
          v896[v898][v899][(v900 + 1)] = v913;	// L1096
          float v914 = v893[v897][(v899 + 1)][v900];	// L1097
          float v915 = v895[v898][(v899 + 1)][v900];	// L1098
          float v916 = v896[v898][(v899 + 1)][v900];	// L1099
          float v917 = (v897 == 0) ? v915 : v916;	// L1100
          float v918 = v914 * v902;	// L1101
          float v919 = v917 + v918;	// L1102
          v896[v898][(v899 + 1)][v900] = v919;	// L1103
          float v920 = v893[v897][(v899 + 1)][(v900 + 1)];	// L1104
          float v921 = v895[v898][(v899 + 1)][(v900 + 1)];	// L1105
          float v922 = v896[v898][(v899 + 1)][(v900 + 1)];	// L1106
          float v923 = (v897 == 0) ? v921 : v922;	// L1107
          float v924 = v920 * v902;	// L1108
          float v925 = v923 + v924;	// L1109
          v896[v898][(v899 + 1)][(v900 + 1)] = v925;	// L1110
        }
      }
    }
  }
}

void forward_node68(
  float v926[256][8][8],
  float v927[8][4][4],
  int v928,
  int v929,
  int v930
) {	// L1117
  #pragma HLS inline
  #pragma HLS array_partition variable=v926 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v926 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v927 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v927 cyclic factor=2 dim=3
  #pragma HLS resource variable=v927 core=ram_t2p_bram

  for (int v931 = 0; v931 < 8; v931 += 1) {	// L1118
    for (int v932 = 0; v932 < 4; v932 += 2) {	// L1119
      for (int v933 = 0; v933 < 4; v933 += 2) {	// L1120
        #pragma HLS pipeline II=1
        float v934 = v926[(v931 + (v928 * 8))][(v932 + (v929 * 4))][(v933 + (v930 * 4))];	// L1121
        v927[v931][v932][v933] = v934;	// L1122
        float v935 = v926[(v931 + (v928 * 8))][(v932 + (v929 * 4))][((v933 + (v930 * 4)) + 1)];	// L1123
        v927[v931][v932][(v933 + 1)] = v935;	// L1124
        float v936 = v926[(v931 + (v928 * 8))][((v932 + (v929 * 4)) + 1)][(v933 + (v930 * 4))];	// L1125
        v927[v931][(v932 + 1)][v933] = v936;	// L1126
        float v937 = v926[(v931 + (v928 * 8))][((v932 + (v929 * 4)) + 1)][((v933 + (v930 * 4)) + 1)];	// L1127
        v927[v931][(v932 + 1)][(v933 + 1)] = v937;	// L1128
      }
    }
  }
}

void forward_node69(
  float v938[256][256][3][3],
  float v939[8][8],
  int v940,
  int v941,
  int v942,
  int v943
) {	// L1134
  #pragma HLS inline
  #pragma HLS resource variable=v939 core=ram_t2p_bram

  for (int v944 = 0; v944 < 8; v944 += 1) {	// L1135
    for (int v945 = 0; v945 < 8; v945 += 1) {	// L1136
      #pragma HLS pipeline II=1
      float v946 = v938[(v944 + (v942 * 8))][(v945 + (v943 * 8))][v940][v941];	// L1137
      v939[v944][v945] = v946;	// L1138
    }
  }
}

void forward_node70(
  float v947[256][8][8],
  float v948[8][4][4],
  int v949,
  int v950,
  int v951,
  int v952,
  int v953
) {	// L1143
  #pragma HLS inline
  #pragma HLS array_partition variable=v947 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v947 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v948 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v948 cyclic factor=2 dim=3
  #pragma HLS resource variable=v948 core=ram_t2p_bram

  for (int v954 = 0; v954 < 8; v954 += 1) {	// L1144
    for (int v955 = 0; v955 < 4; v955 += 2) {	// L1145
      for (int v956 = 0; v956 < 4; v956 += 2) {	// L1146
        #pragma HLS pipeline II=1
        float v957 = v947[(v954 + (v949 * 8))][(((v955 + v950) + (v951 * 4)) - 1)][(((v956 + v952) + (v953 * 4)) - 1)];	// L1147
        v948[v954][v955][v956] = v957;	// L1148
        float v958 = v947[(v954 + (v949 * 8))][(((v955 + v950) + (v951 * 4)) - 1)][((v956 + v952) + (v953 * 4))];	// L1149
        v948[v954][v955][(v956 + 1)] = v958;	// L1150
        float v959 = v947[(v954 + (v949 * 8))][((v955 + v950) + (v951 * 4))][(((v956 + v952) + (v953 * 4)) - 1)];	// L1151
        v948[v954][(v955 + 1)][v956] = v959;	// L1152
        float v960 = v947[(v954 + (v949 * 8))][((v955 + v950) + (v951 * 4))][((v956 + v952) + (v953 * 4))];	// L1153
        v948[v954][(v955 + 1)][(v956 + 1)] = v960;	// L1154
      }
    }
  }
}

void forward_node65(
  float v961[256][256][3][3],
  float v962[256][8][8],
  float v963[256][8][8],
  float v964[256][8][8]
) {	// L1160
  #pragma HLS array_partition variable=v962 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v962 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v963 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v963 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v964 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v964 cyclic factor=2 dim=3

  for (int v965 = 0; v965 < 36864; v965 += 1) {	// L1161
    #pragma HLS dataflow
    int v966 = (v965 % 2);	// L1162
    int v967 = ((v965 / 2) % 2);	// L1163
    int v968 = (((v965 / 2) / 2) % 32);	// L1164
    int v969 = ((((v965 / 2) / 2) / 32) % 3);	// L1165
    int v970 = (((((v965 / 2) / 2) / 32) / 3) % 3);	// L1166
    int v971 = (((((v965 / 2) / 2) / 32) / 3) / 3);	// L1167
    float v972[8][4][4];	// L1168
    #pragma HLS array_partition variable=v972 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v972 cyclic factor=2 dim=3
    #pragma HLS resource variable=v972 core=ram_t2p_bram

    float v973[8][8];	// L1169
    #pragma HLS resource variable=v973 core=ram_t2p_bram

    float v974[8][4][4];	// L1170
    #pragma HLS array_partition variable=v974 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v974 cyclic factor=2 dim=3
    #pragma HLS resource variable=v974 core=ram_t2p_bram

    forward_node70(v962, v974, v971, v970, v967, v969, v966);	// L1171
    forward_node69(v961, v973, v970, v969, v968, v971);	// L1172
    forward_node68(v963, v972, v968, v967, v966);	// L1173
    float v975[8][4][4];	// L1174
    #pragma HLS array_partition variable=v975 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v975 cyclic factor=2 dim=3
    #pragma HLS resource variable=v975 core=ram_t2p_bram

    forward_node67(v974, v973, v972, v975);	// L1175
    forward_node66(v975, v964, v968, v967, v966);	// L1176
  }
}

void forward_node72(
  float v976[8][4][4],
  float v977[256][8][8],
  int v978,
  int v979,
  int v980
) {	// L1180
  #pragma HLS inline
  #pragma HLS resource variable=v976 core=ram_t2p_bram

  for (int v981 = 0; v981 < 8; v981 += 1) {	// L1181
    for (int v982 = 0; v982 < 4; v982 += 1) {	// L1182
      for (int v983 = 0; v983 < 4; v983 += 1) {	// L1183
        #pragma HLS pipeline II=1
        float v984 = v976[v981][v982][v983];	// L1184
        v977[(v981 + (v978 * 8))][(v982 + (v979 * 4))][(v983 + (v980 * 4))] = v984;	// L1185
      }
    }
  }
}

void forward_node73(
  float v985[256],
  float v986[256],
  float v987[256],
  float v988[256],
  float v989[8][4][4],
  float v990[8][4][4],
  int v991
) {	// L1191
  #pragma HLS inline
  #pragma HLS resource variable=v985 core=ram_t2p_bram

  #pragma HLS resource variable=v986 core=ram_t2p_bram

  #pragma HLS resource variable=v987 core=ram_t2p_bram

  #pragma HLS resource variable=v988 core=ram_t2p_bram

  #pragma HLS resource variable=v989 core=ram_t2p_bram

  #pragma HLS resource variable=v990 core=ram_t2p_bram

  for (int v992 = 0; v992 < 8; v992 += 1) {	// L1194
    for (int v993 = 0; v993 < 4; v993 += 1) {	// L1195
      for (int v994 = 0; v994 < 4; v994 += 1) {	// L1196
        #pragma HLS pipeline II=1
        float v995 = v989[v992][v993][v994];	// L1197
        float v996 = v988[(v992 + (v991 * 8))];	// L1198
        float v997 = v987[(v992 + (v991 * 8))];	// L1199
        float v998 = v985[(v992 + (v991 * 8))];	// L1200
        float v999 = v986[(v992 + (v991 * 8))];	// L1201
        float v1000 = (double)0.000010;	// L1202
        float v1001 = v999 + v1000;	// L1203
        float v1002 = 1.0 / sqrt(v1001);	// L1204
        float v1003 = v995 - v998;	// L1205
        float v1004 = v1003 * v1002;	// L1206
        float v1005 = v1004 * v996;	// L1207
        float v1006 = v1005 + v997;	// L1208
        bool v1007 = v1006 > (float)0.000000;	// L1209
        float v1008 = v1007 ? v1006 : (float)0.000000;	// L1210
        v990[v992][v993][v994] = v1008;	// L1211
      }
    }
  }
}

void forward_node74(
  float v1009[256][8][8],
  float v1010[8][4][4],
  int v1011,
  int v1012,
  int v1013
) {	// L1217
  #pragma HLS inline
  #pragma HLS resource variable=v1010 core=ram_t2p_bram

  for (int v1014 = 0; v1014 < 8; v1014 += 1) {	// L1218
    for (int v1015 = 0; v1015 < 4; v1015 += 1) {	// L1219
      for (int v1016 = 0; v1016 < 4; v1016 += 1) {	// L1220
        #pragma HLS pipeline II=1
        float v1017 = v1009[(v1014 + (v1011 * 8))][(v1015 + (v1012 * 4))][(v1016 + (v1013 * 4))];	// L1221
        v1010[v1014][v1015][v1016] = v1017;	// L1222
      }
    }
  }
}

void forward_node71(
  float v1018[256],
  float v1019[256],
  float v1020[256],
  float v1021[256],
  float v1022[256][8][8],
  float v1023[256][8][8]
) {	// L1228
  #pragma HLS resource variable=v1018 core=ram_t2p_bram

  #pragma HLS resource variable=v1019 core=ram_t2p_bram

  #pragma HLS resource variable=v1020 core=ram_t2p_bram

  #pragma HLS resource variable=v1021 core=ram_t2p_bram

  for (int v1024 = 0; v1024 < 128; v1024 += 1) {	// L1229
    #pragma HLS dataflow
    int v1025 = (v1024 % 2);	// L1230
    int v1026 = ((v1024 / 2) % 2);	// L1231
    int v1027 = ((v1024 / 2) / 2);	// L1232
    float v1028[8][4][4];	// L1233
    #pragma HLS resource variable=v1028 core=ram_t2p_bram

    float v1029[8][4][4];	// L1234
    #pragma HLS resource variable=v1029 core=ram_t2p_bram

    forward_node74(v1022, v1029, v1027, v1026, v1025);	// L1235
    forward_node73(v1020, v1021, v1018, v1019, v1029, v1028, v1027);	// L1236
    forward_node72(v1028, v1023, v1027, v1026, v1025);	// L1237
  }
}

void forward_node76(
  float v1030[8][4][4],
  float v1031[256][8][8],
  int v1032,
  int v1033,
  int v1034
) {	// L1241
  #pragma HLS inline
  #pragma HLS array_partition variable=v1030 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1030 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1030 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1031 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1031 cyclic factor=2 dim=3

  for (int v1035 = 0; v1035 < 8; v1035 += 1) {	// L1242
    for (int v1036 = 0; v1036 < 4; v1036 += 2) {	// L1243
      for (int v1037 = 0; v1037 < 4; v1037 += 2) {	// L1244
        #pragma HLS pipeline II=1
        float v1038 = v1030[v1035][v1036][v1037];	// L1245
        v1031[(v1035 + (v1032 * 8))][(v1036 + (v1033 * 4))][(v1037 + (v1034 * 4))] = v1038;	// L1246
        float v1039 = v1030[v1035][v1036][(v1037 + 1)];	// L1247
        v1031[(v1035 + (v1032 * 8))][(v1036 + (v1033 * 4))][((v1037 + (v1034 * 4)) + 1)] = v1039;	// L1248
        float v1040 = v1030[v1035][(v1036 + 1)][v1037];	// L1249
        v1031[(v1035 + (v1032 * 8))][((v1036 + (v1033 * 4)) + 1)][(v1037 + (v1034 * 4))] = v1040;	// L1250
        float v1041 = v1030[v1035][(v1036 + 1)][(v1037 + 1)];	// L1251
        v1031[(v1035 + (v1032 * 8))][((v1036 + (v1033 * 4)) + 1)][((v1037 + (v1034 * 4)) + 1)] = v1041;	// L1252
      }
    }
  }
}

void forward_node77(
  float v1042[8][8],
  float v1043[8][4][4],
  float v1044[8][4][4],
  float v1045[8][4][4],
  float v1046[8][4][4],
  int v1047,
  int v1048,
  int v1049
) {	// L1258
  #pragma HLS inline
  #pragma HLS resource variable=v1042 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1043 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1043 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1043 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1044 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1044 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1044 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1045 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1045 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1045 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1046 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1046 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1046 core=ram_t2p_bram

  for (int v1050 = 0; v1050 < 8; v1050 += 1) {	// L1259
    for (int v1051 = 0; v1051 < 8; v1051 += 1) {	// L1260
      for (int v1052 = 0; v1052 < 4; v1052 += 2) {	// L1261
        for (int v1053 = 0; v1053 < 4; v1053 += 2) {	// L1262
          #pragma HLS pipeline II=1
          float v1054 = v1044[v1051][v1052][v1053];	// L1263
          float v1055 = v1045[v1051][v1052][v1053];	// L1264
          float v1056 = v1046[v1051][v1052][v1053];	// L1265
          float v1057 = (v1050 == 0) ? v1055 : v1056;	// L1266
          float v1058 = ((v1050 + (v1049 * 8)) == 0 && v1048 == 0 && v1047 == 0) ? v1054 : v1057;	// L1267
          float v1059 = v1043[v1050][v1052][v1053];	// L1268
          float v1060 = v1042[v1051][v1050];	// L1269
          float v1061 = v1059 * v1060;	// L1270
          float v1062 = v1058 + v1061;	// L1271
          v1046[v1051][v1052][v1053] = v1062;	// L1272
          float v1063 = v1044[v1051][v1052][(v1053 + 1)];	// L1273
          float v1064 = v1045[v1051][v1052][(v1053 + 1)];	// L1274
          float v1065 = v1046[v1051][v1052][(v1053 + 1)];	// L1275
          float v1066 = (v1050 == 0) ? v1064 : v1065;	// L1276
          float v1067 = ((v1050 + (v1049 * 8)) == 0 && v1048 == 0 && v1047 == 0) ? v1063 : v1066;	// L1277
          float v1068 = v1043[v1050][v1052][(v1053 + 1)];	// L1278
          float v1069 = v1068 * v1060;	// L1279
          float v1070 = v1067 + v1069;	// L1280
          v1046[v1051][v1052][(v1053 + 1)] = v1070;	// L1281
          float v1071 = v1044[v1051][(v1052 + 1)][v1053];	// L1282
          float v1072 = v1045[v1051][(v1052 + 1)][v1053];	// L1283
          float v1073 = v1046[v1051][(v1052 + 1)][v1053];	// L1284
          float v1074 = (v1050 == 0) ? v1072 : v1073;	// L1285
          float v1075 = ((v1050 + (v1049 * 8)) == 0 && v1048 == 0 && v1047 == 0) ? v1071 : v1074;	// L1286
          float v1076 = v1043[v1050][(v1052 + 1)][v1053];	// L1287
          float v1077 = v1076 * v1060;	// L1288
          float v1078 = v1075 + v1077;	// L1289
          v1046[v1051][(v1052 + 1)][v1053] = v1078;	// L1290
          float v1079 = v1044[v1051][(v1052 + 1)][(v1053 + 1)];	// L1291
          float v1080 = v1045[v1051][(v1052 + 1)][(v1053 + 1)];	// L1292
          float v1081 = v1046[v1051][(v1052 + 1)][(v1053 + 1)];	// L1293
          float v1082 = (v1050 == 0) ? v1080 : v1081;	// L1294
          float v1083 = ((v1050 + (v1049 * 8)) == 0 && v1048 == 0 && v1047 == 0) ? v1079 : v1082;	// L1295
          float v1084 = v1043[v1050][(v1052 + 1)][(v1053 + 1)];	// L1296
          float v1085 = v1084 * v1060;	// L1297
          float v1086 = v1083 + v1085;	// L1298
          v1046[v1051][(v1052 + 1)][(v1053 + 1)] = v1086;	// L1299
        }
      }
    }
  }
}

void forward_node78(
  float v1087[256][256][3][3],
  float v1088[8][8],
  int v1089,
  int v1090,
  int v1091,
  int v1092
) {	// L1306
  #pragma HLS inline
  #pragma HLS resource variable=v1088 core=ram_t2p_bram

  for (int v1093 = 0; v1093 < 8; v1093 += 1) {	// L1307
    for (int v1094 = 0; v1094 < 8; v1094 += 1) {	// L1308
      #pragma HLS pipeline II=1
      float v1095 = v1087[(v1093 + (v1091 * 8))][(v1094 + (v1092 * 8))][v1089][v1090];	// L1309
      v1088[v1093][v1094] = v1095;	// L1310
    }
  }
}

void forward_node79(
  float v1096[256][8][8],
  float v1097[8][4][4],
  int v1098,
  int v1099,
  int v1100,
  int v1101,
  int v1102
) {	// L1315
  #pragma HLS inline
  #pragma HLS array_partition variable=v1096 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1096 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v1097 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1097 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1097 core=ram_t2p_bram

  for (int v1103 = 0; v1103 < 8; v1103 += 1) {	// L1316
    for (int v1104 = 0; v1104 < 4; v1104 += 2) {	// L1317
      for (int v1105 = 0; v1105 < 4; v1105 += 2) {	// L1318
        #pragma HLS pipeline II=1
        float v1106 = v1096[(v1103 + (v1098 * 8))][(((v1104 + v1099) + (v1100 * 4)) - 1)][(((v1105 + v1101) + (v1102 * 4)) - 1)];	// L1319
        v1097[v1103][v1104][v1105] = v1106;	// L1320
        float v1107 = v1096[(v1103 + (v1098 * 8))][(((v1104 + v1099) + (v1100 * 4)) - 1)][((v1105 + v1101) + (v1102 * 4))];	// L1321
        v1097[v1103][v1104][(v1105 + 1)] = v1107;	// L1322
        float v1108 = v1096[(v1103 + (v1098 * 8))][((v1104 + v1099) + (v1100 * 4))][(((v1105 + v1101) + (v1102 * 4)) - 1)];	// L1323
        v1097[v1103][(v1104 + 1)][v1105] = v1108;	// L1324
        float v1109 = v1096[(v1103 + (v1098 * 8))][((v1104 + v1099) + (v1100 * 4))][((v1105 + v1101) + (v1102 * 4))];	// L1325
        v1097[v1103][(v1104 + 1)][(v1105 + 1)] = v1109;	// L1326
      }
    }
  }
}

void forward_node80(
  float v1110[256][8][8],
  float v1111[8][4][4],
  int v1112,
  int v1113,
  int v1114
) {	// L1332
  #pragma HLS inline
  #pragma HLS array_partition variable=v1110 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1110 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v1111 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1111 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1111 core=ram_t2p_bram

  for (int v1115 = 0; v1115 < 8; v1115 += 1) {	// L1333
    for (int v1116 = 0; v1116 < 4; v1116 += 2) {	// L1334
      for (int v1117 = 0; v1117 < 4; v1117 += 2) {	// L1335
        #pragma HLS pipeline II=1
        float v1118 = v1110[(v1115 + (v1112 * 8))][(v1116 + (v1113 * 4))][(v1117 + (v1114 * 4))];	// L1336
        v1111[v1115][v1116][v1117] = v1118;	// L1337
        float v1119 = v1110[(v1115 + (v1112 * 8))][(v1116 + (v1113 * 4))][((v1117 + (v1114 * 4)) + 1)];	// L1338
        v1111[v1115][v1116][(v1117 + 1)] = v1119;	// L1339
        float v1120 = v1110[(v1115 + (v1112 * 8))][((v1116 + (v1113 * 4)) + 1)][(v1117 + (v1114 * 4))];	// L1340
        v1111[v1115][(v1116 + 1)][v1117] = v1120;	// L1341
        float v1121 = v1110[(v1115 + (v1112 * 8))][((v1116 + (v1113 * 4)) + 1)][((v1117 + (v1114 * 4)) + 1)];	// L1342
        v1111[v1115][(v1116 + 1)][(v1117 + 1)] = v1121;	// L1343
      }
    }
  }
}

void forward_node81(
  float v1122[256][8][8],
  float v1123[8][4][4],
  int v1124,
  int v1125,
  int v1126
) {	// L1349
  #pragma HLS inline
  #pragma HLS array_partition variable=v1122 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1122 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v1123 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1123 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1123 core=ram_t2p_bram

  for (int v1127 = 0; v1127 < 8; v1127 += 1) {	// L1350
    for (int v1128 = 0; v1128 < 4; v1128 += 2) {	// L1351
      for (int v1129 = 0; v1129 < 4; v1129 += 2) {	// L1352
        #pragma HLS pipeline II=1
        float v1130 = v1122[(v1127 + (v1124 * 8))][(v1128 + (v1125 * 4))][(v1129 + (v1126 * 4))];	// L1353
        v1123[v1127][v1128][v1129] = v1130;	// L1354
        float v1131 = v1122[(v1127 + (v1124 * 8))][(v1128 + (v1125 * 4))][((v1129 + (v1126 * 4)) + 1)];	// L1355
        v1123[v1127][v1128][(v1129 + 1)] = v1131;	// L1356
        float v1132 = v1122[(v1127 + (v1124 * 8))][((v1128 + (v1125 * 4)) + 1)][(v1129 + (v1126 * 4))];	// L1357
        v1123[v1127][(v1128 + 1)][v1129] = v1132;	// L1358
        float v1133 = v1122[(v1127 + (v1124 * 8))][((v1128 + (v1125 * 4)) + 1)][((v1129 + (v1126 * 4)) + 1)];	// L1359
        v1123[v1127][(v1128 + 1)][(v1129 + 1)] = v1133;	// L1360
      }
    }
  }
}

void forward_node75(
  float v1134[256][8][8],
  float v1135[256][8][8],
  float v1136[256][256][3][3],
  float v1137[256][8][8],
  float v1138[256][8][8]
) {	// L1366
  #pragma HLS array_partition variable=v1134 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1134 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v1135 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1135 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v1137 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1137 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v1138 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1138 cyclic factor=2 dim=3

  for (int v1139 = 0; v1139 < 36864; v1139 += 1) {	// L1367
    #pragma HLS dataflow
    int v1140 = (v1139 % 2);	// L1368
    int v1141 = ((v1139 / 2) % 2);	// L1369
    int v1142 = (((v1139 / 2) / 2) % 32);	// L1370
    int v1143 = ((((v1139 / 2) / 2) / 32) % 3);	// L1371
    int v1144 = (((((v1139 / 2) / 2) / 32) / 3) % 3);	// L1372
    int v1145 = (((((v1139 / 2) / 2) / 32) / 3) / 3);	// L1373
    float v1146[8][8];	// L1374
    #pragma HLS resource variable=v1146 core=ram_t2p_bram

    float v1147[8][4][4];	// L1375
    #pragma HLS array_partition variable=v1147 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v1147 cyclic factor=2 dim=3
    #pragma HLS resource variable=v1147 core=ram_t2p_bram

    float v1148[8][4][4];	// L1376
    #pragma HLS array_partition variable=v1148 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v1148 cyclic factor=2 dim=3
    #pragma HLS resource variable=v1148 core=ram_t2p_bram

    float v1149[8][4][4];	// L1377
    #pragma HLS array_partition variable=v1149 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v1149 cyclic factor=2 dim=3
    #pragma HLS resource variable=v1149 core=ram_t2p_bram

    forward_node81(v1134, v1149, v1142, v1141, v1140);	// L1378
    forward_node80(v1137, v1148, v1142, v1141, v1140);	// L1379
    forward_node79(v1135, v1147, v1145, v1144, v1141, v1143, v1140);	// L1380
    forward_node78(v1136, v1146, v1144, v1143, v1142, v1145);	// L1381
    float v1150[8][4][4];	// L1382
    #pragma HLS array_partition variable=v1150 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v1150 cyclic factor=2 dim=3
    #pragma HLS resource variable=v1150 core=ram_t2p_bram

    forward_node77(v1146, v1147, v1149, v1148, v1150, v1143, v1144, v1145);	// L1383
    forward_node76(v1150, v1138, v1142, v1141, v1140);	// L1384
  }
}

void forward_node83(
  float v1151[8][4][4],
  float v1152[256][8][8],
  int v1153,
  int v1154,
  int v1155
) {	// L1388
  #pragma HLS inline
  #pragma HLS resource variable=v1151 core=ram_t2p_bram

  for (int v1156 = 0; v1156 < 8; v1156 += 1) {	// L1389
    for (int v1157 = 0; v1157 < 4; v1157 += 1) {	// L1390
      for (int v1158 = 0; v1158 < 4; v1158 += 1) {	// L1391
        #pragma HLS pipeline II=1
        float v1159 = v1151[v1156][v1157][v1158];	// L1392
        v1152[(v1156 + (v1153 * 8))][(v1157 + (v1154 * 4))][(v1158 + (v1155 * 4))] = v1159;	// L1393
      }
    }
  }
}

void forward_node84(
  float v1160[256],
  float v1161[256],
  float v1162[256],
  float v1163[256],
  float v1164[256],
  float v1165[256],
  float v1166[8][4][4],
  float v1167[256],
  float v1168[8][4][4],
  float v1169[8][4][4],
  int v1170
) {	// L1399
  #pragma HLS inline
  #pragma HLS resource variable=v1160 core=ram_t2p_bram

  #pragma HLS resource variable=v1161 core=ram_t2p_bram

  #pragma HLS resource variable=v1162 core=ram_t2p_bram

  #pragma HLS resource variable=v1163 core=ram_t2p_bram

  #pragma HLS resource variable=v1164 core=ram_t2p_bram

  #pragma HLS resource variable=v1165 core=ram_t2p_bram

  #pragma HLS resource variable=v1166 core=ram_t2p_bram

  #pragma HLS resource variable=v1167 core=ram_t2p_bram

  #pragma HLS resource variable=v1168 core=ram_t2p_bram

  #pragma HLS resource variable=v1169 core=ram_t2p_bram

  for (int v1171 = 0; v1171 < 8; v1171 += 1) {	// L1402
    for (int v1172 = 0; v1172 < 4; v1172 += 1) {	// L1403
      for (int v1173 = 0; v1173 < 4; v1173 += 1) {	// L1404
        #pragma HLS pipeline II=1
        float v1174 = v1166[v1171][v1172][v1173];	// L1405
        float v1175 = v1162[(v1171 + (v1170 * 8))];	// L1406
        float v1176 = v1165[(v1171 + (v1170 * 8))];	// L1407
        float v1177 = v1160[(v1171 + (v1170 * 8))];	// L1408
        float v1178 = v1164[(v1171 + (v1170 * 8))];	// L1409
        float v1179 = v1168[v1171][v1172][v1173];	// L1410
        float v1180 = v1163[(v1171 + (v1170 * 8))];	// L1411
        float v1181 = v1161[(v1171 + (v1170 * 8))];	// L1412
        float v1182 = v1167[(v1171 + (v1170 * 8))];	// L1413
        float v1183 = (double)0.000010;	// L1414
        float v1184 = v1182 + v1183;	// L1415
        float v1185 = 1.0 / sqrt(v1184);	// L1416
        float v1186 = v1179 - v1181;	// L1417
        float v1187 = v1186 * v1185;	// L1418
        float v1188 = v1187 * v1180;	// L1419
        float v1189 = v1188 + v1176;	// L1420
        float v1190 = v1178 + v1183;	// L1421
        float v1191 = 1.0 / sqrt(v1190);	// L1422
        float v1192 = v1174 - v1177;	// L1423
        float v1193 = v1192 * v1191;	// L1424
        float v1194 = v1193 * v1175;	// L1425
        float v1195 = v1194 + v1176;	// L1426
        float v1196 = v1195 + v1189;	// L1427
        bool v1197 = v1196 > (float)0.000000;	// L1428
        float v1198 = v1197 ? v1196 : (float)0.000000;	// L1429
        v1169[v1171][v1172][v1173] = v1198;	// L1430
      }
    }
  }
}

void forward_node85(
  float v1199[256][8][8],
  float v1200[8][4][4],
  int v1201,
  int v1202,
  int v1203
) {	// L1436
  #pragma HLS inline
  #pragma HLS resource variable=v1200 core=ram_t2p_bram

  for (int v1204 = 0; v1204 < 8; v1204 += 1) {	// L1437
    for (int v1205 = 0; v1205 < 4; v1205 += 1) {	// L1438
      for (int v1206 = 0; v1206 < 4; v1206 += 1) {	// L1439
        #pragma HLS pipeline II=1
        float v1207 = v1199[(v1204 + (v1201 * 8))][(v1205 + (v1202 * 4))][(v1206 + (v1203 * 4))];	// L1440
        v1200[v1204][v1205][v1206] = v1207;	// L1441
      }
    }
  }
}

void forward_node86(
  float v1208[256][8][8],
  float v1209[8][4][4],
  int v1210,
  int v1211,
  int v1212
) {	// L1447
  #pragma HLS inline
  #pragma HLS resource variable=v1209 core=ram_t2p_bram

  for (int v1213 = 0; v1213 < 8; v1213 += 1) {	// L1448
    for (int v1214 = 0; v1214 < 4; v1214 += 1) {	// L1449
      for (int v1215 = 0; v1215 < 4; v1215 += 1) {	// L1450
        #pragma HLS pipeline II=1
        float v1216 = v1208[(v1213 + (v1210 * 8))][(v1214 + (v1211 * 4))][(v1215 + (v1212 * 4))];	// L1451
        v1209[v1213][v1214][v1215] = v1216;	// L1452
      }
    }
  }
}

void forward_node82(
  float v1217[256][8][8],
  float v1218[256],
  float v1219[256],
  float v1220[256],
  float v1221[256],
  float v1222[256][8][8],
  float v1223[256],
  float v1224[256],
  float v1225[256],
  float v1226[256][8][8]
) {	// L1458
  #pragma HLS resource variable=v1218 core=ram_t2p_bram

  #pragma HLS resource variable=v1219 core=ram_t2p_bram

  #pragma HLS resource variable=v1220 core=ram_t2p_bram

  #pragma HLS resource variable=v1221 core=ram_t2p_bram

  #pragma HLS resource variable=v1223 core=ram_t2p_bram

  #pragma HLS resource variable=v1224 core=ram_t2p_bram

  #pragma HLS resource variable=v1225 core=ram_t2p_bram

  for (int v1227 = 0; v1227 < 128; v1227 += 1) {	// L1459
    #pragma HLS dataflow
    int v1228 = (v1227 % 2);	// L1460
    int v1229 = ((v1227 / 2) % 2);	// L1461
    int v1230 = ((v1227 / 2) / 2);	// L1462
    float v1231[8][4][4];	// L1463
    #pragma HLS resource variable=v1231 core=ram_t2p_bram

    float v1232[8][4][4];	// L1464
    #pragma HLS resource variable=v1232 core=ram_t2p_bram

    float v1233[8][4][4];	// L1465
    #pragma HLS resource variable=v1233 core=ram_t2p_bram

    forward_node86(v1222, v1233, v1230, v1229, v1228);	// L1466
    forward_node85(v1217, v1232, v1230, v1229, v1228);	// L1467
    forward_node84(v1219, v1218, v1224, v1223, v1220, v1225, v1233, v1221, v1232, v1231, v1230);	// L1468
    forward_node83(v1231, v1226, v1230, v1229, v1228);	// L1469
  }
}

void forward_node88(
  float v1234[8][4][4],
  float v1235[256][8][8],
  int v1236,
  int v1237,
  int v1238
) {	// L1473
  #pragma HLS inline
  #pragma HLS resource variable=v1234 core=ram_t2p_bram

  for (int v1239 = 0; v1239 < 8; v1239 += 1) {	// L1474
    for (int v1240 = 0; v1240 < 4; v1240 += 1) {	// L1475
      for (int v1241 = 0; v1241 < 4; v1241 += 1) {	// L1476
        #pragma HLS pipeline II=1
        float v1242 = v1234[v1239][v1240][v1241];	// L1477
        v1235[(v1239 + (v1236 * 8))][(v1240 + (v1237 * 4))][(v1241 + (v1238 * 4))] = v1242;	// L1478
      }
    }
  }
}

void forward_node89(
  float v1243[8][4][4],
  float v1244[8][4][4],
  float v1245[8][8],
  float v1246[8][4][4],
  float v1247[8][4][4],
  int v1248
) {	// L1484
  #pragma HLS inline
  #pragma HLS resource variable=v1243 core=ram_t2p_bram

  #pragma HLS resource variable=v1244 core=ram_t2p_bram

  #pragma HLS resource variable=v1245 core=ram_t2p_bram

  #pragma HLS resource variable=v1246 core=ram_t2p_bram

  #pragma HLS resource variable=v1247 core=ram_t2p_bram

  for (int v1249 = 0; v1249 < 8; v1249 += 1) {	// L1485
    for (int v1250 = 0; v1250 < 8; v1250 += 1) {	// L1486
      for (int v1251 = 0; v1251 < 4; v1251 += 1) {	// L1487
        for (int v1252 = 0; v1252 < 4; v1252 += 1) {	// L1488
          #pragma HLS pipeline II=1
          float v1253 = v1243[v1250][v1251][v1252];	// L1489
          float v1254 = v1246[v1250][v1251][v1252];	// L1490
          float v1255 = v1247[v1250][v1251][v1252];	// L1491
          float v1256 = (v1249 == 0) ? v1254 : v1255;	// L1492
          float v1257 = ((v1249 + (v1248 * 8)) == 0) ? v1253 : v1256;	// L1493
          float v1258 = v1244[v1249][v1251][v1252];	// L1494
          float v1259 = v1245[v1250][v1249];	// L1495
          float v1260 = v1258 * v1259;	// L1496
          float v1261 = v1257 + v1260;	// L1497
          v1247[v1250][v1251][v1252] = v1261;	// L1498
        }
      }
    }
  }
}

void forward_node90(
  float v1262[256][128],
  float v1263[8][8],
  int v1264,
  int v1265
) {	// L1505
  #pragma HLS inline
  #pragma HLS resource variable=v1263 core=ram_t2p_bram

  for (int v1266 = 0; v1266 < 8; v1266 += 1) {	// L1506
    for (int v1267 = 0; v1267 < 8; v1267 += 1) {	// L1507
      #pragma HLS pipeline II=1
      float v1268 = v1262[(v1266 + (v1264 * 8))][(v1267 + (v1265 * 8))];	// L1508
      v1263[v1266][v1267] = v1268;	// L1509
    }
  }
}

void forward_node91(
  float v1269[128][16][16],
  float v1270[8][4][4],
  int v1271,
  int v1272,
  int v1273
) {	// L1514
  #pragma HLS inline
  #pragma HLS resource variable=v1270 core=ram_t2p_bram

  for (int v1274 = 0; v1274 < 8; v1274 += 1) {	// L1515
    for (int v1275 = 0; v1275 < 4; v1275 += 1) {	// L1516
      for (int v1276 = 0; v1276 < 4; v1276 += 1) {	// L1517
        #pragma HLS pipeline II=1
        float v1277 = v1269[(v1274 + (v1271 * 8))][((v1275 * 2) + (v1272 * 8))][((v1276 * 2) + (v1273 * 8))];	// L1518
        v1270[v1274][v1275][v1276] = v1277;	// L1519
      }
    }
  }
}

void forward_node92(
  float v1278[256][8][8],
  float v1279[8][4][4],
  int v1280,
  int v1281,
  int v1282
) {	// L1525
  #pragma HLS inline
  #pragma HLS resource variable=v1279 core=ram_t2p_bram

  for (int v1283 = 0; v1283 < 8; v1283 += 1) {	// L1526
    for (int v1284 = 0; v1284 < 4; v1284 += 1) {	// L1527
      for (int v1285 = 0; v1285 < 4; v1285 += 1) {	// L1528
        #pragma HLS pipeline II=1
        float v1286 = v1278[(v1283 + (v1280 * 8))][(v1284 + (v1281 * 4))][(v1285 + (v1282 * 4))];	// L1529
        v1279[v1283][v1284][v1285] = v1286;	// L1530
      }
    }
  }
}

void forward_node93(
  float v1287[256][8][8],
  float v1288[8][4][4],
  int v1289,
  int v1290,
  int v1291
) {	// L1536
  #pragma HLS inline
  #pragma HLS resource variable=v1288 core=ram_t2p_bram

  for (int v1292 = 0; v1292 < 8; v1292 += 1) {	// L1537
    for (int v1293 = 0; v1293 < 4; v1293 += 1) {	// L1538
      for (int v1294 = 0; v1294 < 4; v1294 += 1) {	// L1539
        #pragma HLS pipeline II=1
        float v1295 = v1287[(v1292 + (v1289 * 8))][(v1293 + (v1290 * 4))][(v1294 + (v1291 * 4))];	// L1540
        v1288[v1292][v1293][v1294] = v1295;	// L1541
      }
    }
  }
}

void forward_node87(
  float v1296[256][8][8],
  float v1297[128][16][16],
  float v1298[256][128],
  float v1299[256][8][8],
  float v1300[256][8][8]
) {	// L1547
  for (int v1301 = 0; v1301 < 2048; v1301 += 1) {	// L1548
    #pragma HLS dataflow
    int v1302 = (v1301 % 2);	// L1549
    int v1303 = ((v1301 / 2) % 2);	// L1550
    int v1304 = (((v1301 / 2) / 2) % 32);	// L1551
    int v1305 = (((v1301 / 2) / 2) / 32);	// L1552
    float v1306[8][8];	// L1553
    #pragma HLS resource variable=v1306 core=ram_t2p_bram

    float v1307[8][4][4];	// L1554
    #pragma HLS resource variable=v1307 core=ram_t2p_bram

    float v1308[8][4][4];	// L1555
    #pragma HLS resource variable=v1308 core=ram_t2p_bram

    float v1309[8][4][4];	// L1556
    #pragma HLS resource variable=v1309 core=ram_t2p_bram

    forward_node93(v1296, v1309, v1304, v1303, v1302);	// L1557
    forward_node92(v1299, v1308, v1304, v1303, v1302);	// L1558
    forward_node91(v1297, v1307, v1305, v1303, v1302);	// L1559
    forward_node90(v1298, v1306, v1304, v1305);	// L1560
    float v1310[8][4][4];	// L1561
    #pragma HLS resource variable=v1310 core=ram_t2p_bram

    forward_node89(v1309, v1307, v1306, v1308, v1310, v1305);	// L1562
    forward_node88(v1310, v1300, v1304, v1303, v1302);	// L1563
  }
}

void forward_node95(
  float v1311[8][4][4],
  float v1312[256][8][8],
  int v1313,
  int v1314,
  int v1315
) {	// L1567
  #pragma HLS inline
  #pragma HLS array_partition variable=v1311 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1311 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1311 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1312 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1312 cyclic factor=2 dim=3

  for (int v1316 = 0; v1316 < 8; v1316 += 1) {	// L1568
    for (int v1317 = 0; v1317 < 4; v1317 += 2) {	// L1569
      for (int v1318 = 0; v1318 < 4; v1318 += 2) {	// L1570
        #pragma HLS pipeline II=1
        float v1319 = v1311[v1316][v1317][v1318];	// L1571
        v1312[(v1316 + (v1313 * 8))][(v1317 + (v1314 * 4))][(v1318 + (v1315 * 4))] = v1319;	// L1572
        float v1320 = v1311[v1316][v1317][(v1318 + 1)];	// L1573
        v1312[(v1316 + (v1313 * 8))][(v1317 + (v1314 * 4))][((v1318 + (v1315 * 4)) + 1)] = v1320;	// L1574
        float v1321 = v1311[v1316][(v1317 + 1)][v1318];	// L1575
        v1312[(v1316 + (v1313 * 8))][((v1317 + (v1314 * 4)) + 1)][(v1318 + (v1315 * 4))] = v1321;	// L1576
        float v1322 = v1311[v1316][(v1317 + 1)][(v1318 + 1)];	// L1577
        v1312[(v1316 + (v1313 * 8))][((v1317 + (v1314 * 4)) + 1)][((v1318 + (v1315 * 4)) + 1)] = v1322;	// L1578
      }
    }
  }
}

void forward_node96(
  float v1323[8][4][4],
  float v1324[8][4][4],
  float v1325[8][8],
  float v1326[8][4][4],
  float v1327[8][4][4],
  int v1328,
  int v1329,
  int v1330
) {	// L1584
  #pragma HLS inline
  #pragma HLS array_partition variable=v1323 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1323 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1323 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1324 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1324 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1324 core=ram_t2p_bram

  #pragma HLS resource variable=v1325 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1326 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1326 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1326 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1327 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1327 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1327 core=ram_t2p_bram

  for (int v1331 = 0; v1331 < 8; v1331 += 1) {	// L1585
    for (int v1332 = 0; v1332 < 8; v1332 += 1) {	// L1586
      for (int v1333 = 0; v1333 < 4; v1333 += 2) {	// L1587
        for (int v1334 = 0; v1334 < 4; v1334 += 2) {	// L1588
          #pragma HLS pipeline II=1
          float v1335 = v1323[v1332][v1333][v1334];	// L1589
          float v1336 = v1326[v1332][v1333][v1334];	// L1590
          float v1337 = v1327[v1332][v1333][v1334];	// L1591
          float v1338 = (v1331 == 0) ? v1336 : v1337;	// L1592
          float v1339 = ((v1331 + (v1328 * 8)) == 0 && v1330 == 0 && v1329 == 0) ? v1335 : v1338;	// L1593
          float v1340 = v1324[v1331][v1333][v1334];	// L1594
          float v1341 = v1325[v1332][v1331];	// L1595
          float v1342 = v1340 * v1341;	// L1596
          float v1343 = v1339 + v1342;	// L1597
          v1327[v1332][v1333][v1334] = v1343;	// L1598
          float v1344 = v1323[v1332][v1333][(v1334 + 1)];	// L1599
          float v1345 = v1326[v1332][v1333][(v1334 + 1)];	// L1600
          float v1346 = v1327[v1332][v1333][(v1334 + 1)];	// L1601
          float v1347 = (v1331 == 0) ? v1345 : v1346;	// L1602
          float v1348 = ((v1331 + (v1328 * 8)) == 0 && v1330 == 0 && v1329 == 0) ? v1344 : v1347;	// L1603
          float v1349 = v1324[v1331][v1333][(v1334 + 1)];	// L1604
          float v1350 = v1349 * v1341;	// L1605
          float v1351 = v1348 + v1350;	// L1606
          v1327[v1332][v1333][(v1334 + 1)] = v1351;	// L1607
          float v1352 = v1323[v1332][(v1333 + 1)][v1334];	// L1608
          float v1353 = v1326[v1332][(v1333 + 1)][v1334];	// L1609
          float v1354 = v1327[v1332][(v1333 + 1)][v1334];	// L1610
          float v1355 = (v1331 == 0) ? v1353 : v1354;	// L1611
          float v1356 = ((v1331 + (v1328 * 8)) == 0 && v1330 == 0 && v1329 == 0) ? v1352 : v1355;	// L1612
          float v1357 = v1324[v1331][(v1333 + 1)][v1334];	// L1613
          float v1358 = v1357 * v1341;	// L1614
          float v1359 = v1356 + v1358;	// L1615
          v1327[v1332][(v1333 + 1)][v1334] = v1359;	// L1616
          float v1360 = v1323[v1332][(v1333 + 1)][(v1334 + 1)];	// L1617
          float v1361 = v1326[v1332][(v1333 + 1)][(v1334 + 1)];	// L1618
          float v1362 = v1327[v1332][(v1333 + 1)][(v1334 + 1)];	// L1619
          float v1363 = (v1331 == 0) ? v1361 : v1362;	// L1620
          float v1364 = ((v1331 + (v1328 * 8)) == 0 && v1330 == 0 && v1329 == 0) ? v1360 : v1363;	// L1621
          float v1365 = v1324[v1331][(v1333 + 1)][(v1334 + 1)];	// L1622
          float v1366 = v1365 * v1341;	// L1623
          float v1367 = v1364 + v1366;	// L1624
          v1327[v1332][(v1333 + 1)][(v1334 + 1)] = v1367;	// L1625
        }
      }
    }
  }
}

void forward_node97(
  float v1368[256][256][3][3],
  float v1369[8][8],
  int v1370,
  int v1371,
  int v1372,
  int v1373
) {	// L1632
  #pragma HLS inline
  #pragma HLS resource variable=v1369 core=ram_t2p_bram

  for (int v1374 = 0; v1374 < 8; v1374 += 1) {	// L1633
    for (int v1375 = 0; v1375 < 8; v1375 += 1) {	// L1634
      #pragma HLS pipeline II=1
      float v1376 = v1368[(v1374 + (v1372 * 8))][(v1375 + (v1373 * 8))][v1370][v1371];	// L1635
      v1369[v1374][v1375] = v1376;	// L1636
    }
  }
}

void forward_node98(
  float v1377[256][8][8],
  float v1378[8][4][4],
  int v1379,
  int v1380,
  int v1381,
  int v1382,
  int v1383
) {	// L1641
  #pragma HLS inline
  #pragma HLS array_partition variable=v1377 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1377 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v1378 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1378 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1378 core=ram_t2p_bram

  for (int v1384 = 0; v1384 < 8; v1384 += 1) {	// L1642
    for (int v1385 = 0; v1385 < 4; v1385 += 2) {	// L1643
      for (int v1386 = 0; v1386 < 4; v1386 += 2) {	// L1644
        #pragma HLS pipeline II=1
        float v1387 = v1377[(v1384 + (v1379 * 8))][(((v1385 + v1380) + (v1381 * 4)) - 1)][(((v1386 + v1382) + (v1383 * 4)) - 1)];	// L1645
        v1378[v1384][v1385][v1386] = v1387;	// L1646
        float v1388 = v1377[(v1384 + (v1379 * 8))][(((v1385 + v1380) + (v1381 * 4)) - 1)][((v1386 + v1382) + (v1383 * 4))];	// L1647
        v1378[v1384][v1385][(v1386 + 1)] = v1388;	// L1648
        float v1389 = v1377[(v1384 + (v1379 * 8))][((v1385 + v1380) + (v1381 * 4))][(((v1386 + v1382) + (v1383 * 4)) - 1)];	// L1649
        v1378[v1384][(v1385 + 1)][v1386] = v1389;	// L1650
        float v1390 = v1377[(v1384 + (v1379 * 8))][((v1385 + v1380) + (v1381 * 4))][((v1386 + v1382) + (v1383 * 4))];	// L1651
        v1378[v1384][(v1385 + 1)][(v1386 + 1)] = v1390;	// L1652
      }
    }
  }
}

void forward_node99(
  float v1391[256][8][8],
  float v1392[8][4][4],
  int v1393,
  int v1394,
  int v1395
) {	// L1658
  #pragma HLS inline
  #pragma HLS array_partition variable=v1391 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1391 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v1392 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1392 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1392 core=ram_t2p_bram

  for (int v1396 = 0; v1396 < 8; v1396 += 1) {	// L1659
    for (int v1397 = 0; v1397 < 4; v1397 += 2) {	// L1660
      for (int v1398 = 0; v1398 < 4; v1398 += 2) {	// L1661
        #pragma HLS pipeline II=1
        float v1399 = v1391[(v1396 + (v1393 * 8))][(v1397 + (v1394 * 4))][(v1398 + (v1395 * 4))];	// L1662
        v1392[v1396][v1397][v1398] = v1399;	// L1663
        float v1400 = v1391[(v1396 + (v1393 * 8))][(v1397 + (v1394 * 4))][((v1398 + (v1395 * 4)) + 1)];	// L1664
        v1392[v1396][v1397][(v1398 + 1)] = v1400;	// L1665
        float v1401 = v1391[(v1396 + (v1393 * 8))][((v1397 + (v1394 * 4)) + 1)][(v1398 + (v1395 * 4))];	// L1666
        v1392[v1396][(v1397 + 1)][v1398] = v1401;	// L1667
        float v1402 = v1391[(v1396 + (v1393 * 8))][((v1397 + (v1394 * 4)) + 1)][((v1398 + (v1395 * 4)) + 1)];	// L1668
        v1392[v1396][(v1397 + 1)][(v1398 + 1)] = v1402;	// L1669
      }
    }
  }
}

void forward_node100(
  float v1403[256][8][8],
  float v1404[8][4][4],
  int v1405,
  int v1406,
  int v1407
) {	// L1675
  #pragma HLS inline
  #pragma HLS array_partition variable=v1403 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1403 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v1404 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1404 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1404 core=ram_t2p_bram

  for (int v1408 = 0; v1408 < 8; v1408 += 1) {	// L1676
    for (int v1409 = 0; v1409 < 4; v1409 += 2) {	// L1677
      for (int v1410 = 0; v1410 < 4; v1410 += 2) {	// L1678
        #pragma HLS pipeline II=1
        float v1411 = v1403[(v1408 + (v1405 * 8))][(v1409 + (v1406 * 4))][(v1410 + (v1407 * 4))];	// L1679
        v1404[v1408][v1409][v1410] = v1411;	// L1680
        float v1412 = v1403[(v1408 + (v1405 * 8))][(v1409 + (v1406 * 4))][((v1410 + (v1407 * 4)) + 1)];	// L1681
        v1404[v1408][v1409][(v1410 + 1)] = v1412;	// L1682
        float v1413 = v1403[(v1408 + (v1405 * 8))][((v1409 + (v1406 * 4)) + 1)][(v1410 + (v1407 * 4))];	// L1683
        v1404[v1408][(v1409 + 1)][v1410] = v1413;	// L1684
        float v1414 = v1403[(v1408 + (v1405 * 8))][((v1409 + (v1406 * 4)) + 1)][((v1410 + (v1407 * 4)) + 1)];	// L1685
        v1404[v1408][(v1409 + 1)][(v1410 + 1)] = v1414;	// L1686
      }
    }
  }
}

void forward_node94(
  float v1415[256][8][8],
  float v1416[256][256][3][3],
  float v1417[256][8][8],
  float v1418[256][8][8],
  float v1419[256][8][8]
) {	// L1692
  #pragma HLS array_partition variable=v1415 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1415 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v1417 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1417 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v1418 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1418 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v1419 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1419 cyclic factor=2 dim=3

  for (int v1420 = 0; v1420 < 36864; v1420 += 1) {	// L1693
    #pragma HLS dataflow
    int v1421 = (v1420 % 2);	// L1694
    int v1422 = ((v1420 / 2) % 2);	// L1695
    int v1423 = (((v1420 / 2) / 2) % 32);	// L1696
    int v1424 = ((((v1420 / 2) / 2) / 32) % 3);	// L1697
    int v1425 = (((((v1420 / 2) / 2) / 32) / 3) % 3);	// L1698
    int v1426 = (((((v1420 / 2) / 2) / 32) / 3) / 3);	// L1699
    float v1427[8][8];	// L1700
    #pragma HLS resource variable=v1427 core=ram_t2p_bram

    float v1428[8][4][4];	// L1701
    #pragma HLS array_partition variable=v1428 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v1428 cyclic factor=2 dim=3
    #pragma HLS resource variable=v1428 core=ram_t2p_bram

    float v1429[8][4][4];	// L1702
    #pragma HLS array_partition variable=v1429 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v1429 cyclic factor=2 dim=3
    #pragma HLS resource variable=v1429 core=ram_t2p_bram

    float v1430[8][4][4];	// L1703
    #pragma HLS array_partition variable=v1430 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v1430 cyclic factor=2 dim=3
    #pragma HLS resource variable=v1430 core=ram_t2p_bram

    forward_node100(v1415, v1430, v1423, v1422, v1421);	// L1704
    forward_node99(v1418, v1429, v1423, v1422, v1421);	// L1705
    forward_node98(v1417, v1428, v1426, v1425, v1422, v1424, v1421);	// L1706
    forward_node97(v1416, v1427, v1425, v1424, v1423, v1426);	// L1707
    float v1431[8][4][4];	// L1708
    #pragma HLS array_partition variable=v1431 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v1431 cyclic factor=2 dim=3
    #pragma HLS resource variable=v1431 core=ram_t2p_bram

    forward_node96(v1430, v1428, v1427, v1429, v1431, v1426, v1424, v1425);	// L1709
    forward_node95(v1431, v1419, v1423, v1422, v1421);	// L1710
  }
}

void forward_node102(
  float v1432[8][4][4],
  float v1433[256][8][8],
  int v1434,
  int v1435,
  int v1436
) {	// L1714
  #pragma HLS inline
  #pragma HLS resource variable=v1432 core=ram_t2p_bram

  for (int v1437 = 0; v1437 < 8; v1437 += 1) {	// L1715
    for (int v1438 = 0; v1438 < 4; v1438 += 1) {	// L1716
      for (int v1439 = 0; v1439 < 4; v1439 += 1) {	// L1717
        #pragma HLS pipeline II=1
        float v1440 = v1432[v1437][v1438][v1439];	// L1718
        v1433[(v1437 + (v1434 * 8))][(v1438 + (v1435 * 4))][(v1439 + (v1436 * 4))] = v1440;	// L1719
      }
    }
  }
}

void forward_node103(
  float v1441[256],
  float v1442[8][4][4],
  float v1443[256],
  float v1444[256],
  float v1445[256],
  float v1446[8][4][4],
  int v1447
) {	// L1725
  #pragma HLS inline
  #pragma HLS resource variable=v1441 core=ram_t2p_bram

  #pragma HLS resource variable=v1442 core=ram_t2p_bram

  #pragma HLS resource variable=v1443 core=ram_t2p_bram

  #pragma HLS resource variable=v1444 core=ram_t2p_bram

  #pragma HLS resource variable=v1445 core=ram_t2p_bram

  #pragma HLS resource variable=v1446 core=ram_t2p_bram

  for (int v1448 = 0; v1448 < 8; v1448 += 1) {	// L1728
    for (int v1449 = 0; v1449 < 4; v1449 += 1) {	// L1729
      for (int v1450 = 0; v1450 < 4; v1450 += 1) {	// L1730
        #pragma HLS pipeline II=1
        float v1451 = v1442[v1448][v1449][v1450];	// L1731
        float v1452 = v1445[(v1448 + (v1447 * 8))];	// L1732
        float v1453 = v1441[(v1448 + (v1447 * 8))];	// L1733
        float v1454 = v1444[(v1448 + (v1447 * 8))];	// L1734
        float v1455 = v1443[(v1448 + (v1447 * 8))];	// L1735
        float v1456 = (double)0.000010;	// L1736
        float v1457 = v1455 + v1456;	// L1737
        float v1458 = 1.0 / sqrt(v1457);	// L1738
        float v1459 = v1451 - v1454;	// L1739
        float v1460 = v1459 * v1458;	// L1740
        float v1461 = v1460 * v1452;	// L1741
        float v1462 = v1461 + v1453;	// L1742
        bool v1463 = v1462 > (float)0.000000;	// L1743
        float v1464 = v1463 ? v1462 : (float)0.000000;	// L1744
        v1446[v1448][v1449][v1450] = v1464;	// L1745
      }
    }
  }
}

void forward_node104(
  float v1465[256][8][8],
  float v1466[8][4][4],
  int v1467,
  int v1468,
  int v1469
) {	// L1751
  #pragma HLS inline
  #pragma HLS resource variable=v1466 core=ram_t2p_bram

  for (int v1470 = 0; v1470 < 8; v1470 += 1) {	// L1752
    for (int v1471 = 0; v1471 < 4; v1471 += 1) {	// L1753
      for (int v1472 = 0; v1472 < 4; v1472 += 1) {	// L1754
        #pragma HLS pipeline II=1
        float v1473 = v1465[(v1470 + (v1467 * 8))][(v1471 + (v1468 * 4))][(v1472 + (v1469 * 4))];	// L1755
        v1466[v1470][v1471][v1472] = v1473;	// L1756
      }
    }
  }
}

void forward_node101(
  float v1474[256],
  float v1475[256],
  float v1476[256],
  float v1477[256],
  float v1478[256][8][8],
  float v1479[256][8][8]
) {	// L1762
  #pragma HLS resource variable=v1474 core=ram_t2p_bram

  #pragma HLS resource variable=v1475 core=ram_t2p_bram

  #pragma HLS resource variable=v1476 core=ram_t2p_bram

  #pragma HLS resource variable=v1477 core=ram_t2p_bram

  for (int v1480 = 0; v1480 < 128; v1480 += 1) {	// L1763
    #pragma HLS dataflow
    int v1481 = (v1480 % 2);	// L1764
    int v1482 = ((v1480 / 2) % 2);	// L1765
    int v1483 = ((v1480 / 2) / 2);	// L1766
    float v1484[8][4][4];	// L1767
    #pragma HLS resource variable=v1484 core=ram_t2p_bram

    float v1485[8][4][4];	// L1768
    #pragma HLS resource variable=v1485 core=ram_t2p_bram

    forward_node104(v1478, v1485, v1483, v1482, v1481);	// L1769
    forward_node103(v1476, v1485, v1477, v1474, v1475, v1484, v1483);	// L1770
    forward_node102(v1484, v1479, v1483, v1482, v1481);	// L1771
  }
}

void forward_node106(
  float v1486[8][4][4],
  float v1487[256][8][8],
  int v1488,
  int v1489,
  int v1490
) {	// L1775
  #pragma HLS inline
  #pragma HLS resource variable=v1486 core=ram_t2p_bram

  for (int v1491 = 0; v1491 < 8; v1491 += 1) {	// L1776
    for (int v1492 = 0; v1492 < 4; v1492 += 1) {	// L1777
      for (int v1493 = 0; v1493 < 4; v1493 += 1) {	// L1778
        #pragma HLS pipeline II=1
        float v1494 = v1486[v1491][v1492][v1493];	// L1779
        v1487[(v1491 + (v1488 * 8))][(v1492 + (v1489 * 4))][(v1493 + (v1490 * 4))] = v1494;	// L1780
      }
    }
  }
}

void forward_node107(
  float v1495[8][4][4],
  float v1496[8][8],
  float v1497[8][4][4],
  float v1498[8][4][4],
  float v1499[8][4][4],
  int v1500,
  int v1501,
  int v1502
) {	// L1786
  #pragma HLS inline
  #pragma HLS resource variable=v1495 core=ram_t2p_bram

  #pragma HLS resource variable=v1496 core=ram_t2p_bram

  #pragma HLS resource variable=v1497 core=ram_t2p_bram

  #pragma HLS resource variable=v1498 core=ram_t2p_bram

  #pragma HLS resource variable=v1499 core=ram_t2p_bram

  for (int v1503 = 0; v1503 < 8; v1503 += 1) {	// L1787
    for (int v1504 = 0; v1504 < 8; v1504 += 1) {	// L1788
      for (int v1505 = 0; v1505 < 4; v1505 += 1) {	// L1789
        for (int v1506 = 0; v1506 < 4; v1506 += 1) {	// L1790
          #pragma HLS pipeline II=1
          float v1507 = v1497[v1504][v1505][v1506];	// L1791
          float v1508 = v1498[v1504][v1505][v1506];	// L1792
          float v1509 = v1499[v1504][v1505][v1506];	// L1793
          float v1510 = (v1503 == 0) ? v1508 : v1509;	// L1794
          float v1511 = ((v1503 + (v1502 * 8)) == 0 && v1501 == 0 && v1500 == 0) ? v1507 : v1510;	// L1795
          float v1512 = v1495[v1503][v1505][v1506];	// L1796
          float v1513 = v1496[v1504][v1503];	// L1797
          float v1514 = v1512 * v1513;	// L1798
          float v1515 = v1511 + v1514;	// L1799
          v1499[v1504][v1505][v1506] = v1515;	// L1800
        }
      }
    }
  }
}

void forward_node108(
  float v1516[256][128][3][3],
  float v1517[8][8],
  int v1518,
  int v1519,
  int v1520,
  int v1521
) {	// L1807
  #pragma HLS inline
  #pragma HLS resource variable=v1517 core=ram_t2p_bram

  for (int v1522 = 0; v1522 < 8; v1522 += 1) {	// L1808
    for (int v1523 = 0; v1523 < 8; v1523 += 1) {	// L1809
      #pragma HLS pipeline II=1
      float v1524 = v1516[(v1522 + (v1520 * 8))][(v1523 + (v1521 * 8))][v1518][v1519];	// L1810
      v1517[v1522][v1523] = v1524;	// L1811
    }
  }
}

void forward_node109(
  float v1525[128][16][16],
  float v1526[8][4][4],
  int v1527,
  int v1528,
  int v1529,
  int v1530,
  int v1531
) {	// L1816
  #pragma HLS inline
  #pragma HLS resource variable=v1526 core=ram_t2p_bram

  for (int v1532 = 0; v1532 < 8; v1532 += 1) {	// L1817
    for (int v1533 = 0; v1533 < 4; v1533 += 1) {	// L1818
      for (int v1534 = 0; v1534 < 4; v1534 += 1) {	// L1819
        #pragma HLS pipeline II=1
        float v1535 = v1525[(v1532 + (v1527 * 8))][((((v1533 * 2) + v1528) + (v1529 * 8)) - 1)][((((v1534 * 2) + v1530) + (v1531 * 8)) - 1)];	// L1820
        v1526[v1532][v1533][v1534] = v1535;	// L1821
      }
    }
  }
}

void forward_node110(
  float v1536[256][8][8],
  float v1537[8][4][4],
  int v1538,
  int v1539,
  int v1540
) {	// L1827
  #pragma HLS inline
  #pragma HLS resource variable=v1537 core=ram_t2p_bram

  for (int v1541 = 0; v1541 < 8; v1541 += 1) {	// L1828
    for (int v1542 = 0; v1542 < 4; v1542 += 1) {	// L1829
      for (int v1543 = 0; v1543 < 4; v1543 += 1) {	// L1830
        #pragma HLS pipeline II=1
        float v1544 = v1536[(v1541 + (v1538 * 8))][(v1542 + (v1539 * 4))][(v1543 + (v1540 * 4))];	// L1831
        v1537[v1541][v1542][v1543] = v1544;	// L1832
      }
    }
  }
}

void forward_node111(
  float v1545[256][8][8],
  float v1546[8][4][4],
  int v1547,
  int v1548,
  int v1549
) {	// L1838
  #pragma HLS inline
  #pragma HLS resource variable=v1546 core=ram_t2p_bram

  for (int v1550 = 0; v1550 < 8; v1550 += 1) {	// L1839
    for (int v1551 = 0; v1551 < 4; v1551 += 1) {	// L1840
      for (int v1552 = 0; v1552 < 4; v1552 += 1) {	// L1841
        #pragma HLS pipeline II=1
        float v1553 = v1545[(v1550 + (v1547 * 8))][(v1551 + (v1548 * 4))][(v1552 + (v1549 * 4))];	// L1842
        v1546[v1550][v1551][v1552] = v1553;	// L1843
      }
    }
  }
}

void forward_node105(
  float v1554[256][8][8],
  float v1555[256][128][3][3],
  float v1556[128][16][16],
  float v1557[256][8][8],
  float v1558[256][8][8]
) {	// L1849
  for (int v1559 = 0; v1559 < 18432; v1559 += 1) {	// L1850
    #pragma HLS dataflow
    int v1560 = (v1559 % 2);	// L1851
    int v1561 = ((v1559 / 2) % 2);	// L1852
    int v1562 = (((v1559 / 2) / 2) % 32);	// L1853
    int v1563 = ((((v1559 / 2) / 2) / 32) % 3);	// L1854
    int v1564 = (((((v1559 / 2) / 2) / 32) / 3) % 3);	// L1855
    int v1565 = (((((v1559 / 2) / 2) / 32) / 3) / 3);	// L1856
    float v1566[8][8];	// L1857
    #pragma HLS resource variable=v1566 core=ram_t2p_bram

    float v1567[8][4][4];	// L1858
    #pragma HLS resource variable=v1567 core=ram_t2p_bram

    float v1568[8][4][4];	// L1859
    #pragma HLS resource variable=v1568 core=ram_t2p_bram

    float v1569[8][4][4];	// L1860
    #pragma HLS resource variable=v1569 core=ram_t2p_bram

    forward_node111(v1554, v1569, v1562, v1561, v1560);	// L1861
    forward_node110(v1557, v1568, v1562, v1561, v1560);	// L1862
    forward_node109(v1556, v1567, v1565, v1564, v1561, v1563, v1560);	// L1863
    forward_node108(v1555, v1566, v1564, v1563, v1562, v1565);	// L1864
    float v1570[8][4][4];	// L1865
    #pragma HLS resource variable=v1570 core=ram_t2p_bram

    forward_node107(v1567, v1566, v1569, v1568, v1570, v1563, v1564, v1565);	// L1866
    forward_node106(v1570, v1558, v1562, v1561, v1560);	// L1867
  }
}

void forward_node113(
  float v1571[8][8][8],
  float v1572[128][16][16],
  int v1573,
  int v1574,
  int v1575
) {	// L1871
  #pragma HLS inline
  #pragma HLS resource variable=v1571 core=ram_t2p_bram

  for (int v1576 = 0; v1576 < 8; v1576 += 1) {	// L1872
    for (int v1577 = 0; v1577 < 8; v1577 += 1) {	// L1873
      for (int v1578 = 0; v1578 < 8; v1578 += 1) {	// L1874
        #pragma HLS pipeline II=1
        float v1579 = v1571[v1576][v1577][v1578];	// L1875
        v1572[(v1576 + (v1573 * 8))][(v1577 + (v1574 * 8))][(v1578 + (v1575 * 8))] = v1579;	// L1876
      }
    }
  }
}

void forward_node114(
  float v1580[8][8][8],
  float v1581[8][8][8],
  float v1582[128],
  float v1583[128],
  float v1584[128],
  float v1585[128],
  float v1586[8][8][8],
  int v1587
) {	// L1882
  #pragma HLS inline
  #pragma HLS resource variable=v1580 core=ram_t2p_bram

  #pragma HLS resource variable=v1581 core=ram_t2p_bram

  #pragma HLS resource variable=v1582 core=ram_t2p_bram

  #pragma HLS resource variable=v1583 core=ram_t2p_bram

  #pragma HLS resource variable=v1584 core=ram_t2p_bram

  #pragma HLS resource variable=v1585 core=ram_t2p_bram

  #pragma HLS resource variable=v1586 core=ram_t2p_bram

  for (int v1588 = 0; v1588 < 8; v1588 += 1) {	// L1885
    for (int v1589 = 0; v1589 < 8; v1589 += 1) {	// L1886
      for (int v1590 = 0; v1590 < 8; v1590 += 1) {	// L1887
        #pragma HLS pipeline II=1
        float v1591 = v1581[v1588][v1589][v1590];	// L1888
        float v1592 = v1585[(v1588 + (v1587 * 8))];	// L1889
        float v1593 = v1583[(v1588 + (v1587 * 8))];	// L1890
        float v1594 = v1584[(v1588 + (v1587 * 8))];	// L1891
        float v1595 = v1582[(v1588 + (v1587 * 8))];	// L1892
        float v1596 = v1580[v1588][v1589][v1590];	// L1893
        float v1597 = (double)0.000010;	// L1894
        float v1598 = v1595 + v1597;	// L1895
        float v1599 = 1.0 / sqrt(v1598);	// L1896
        float v1600 = v1591 - v1594;	// L1897
        float v1601 = v1600 * v1599;	// L1898
        float v1602 = v1601 * v1592;	// L1899
        float v1603 = v1602 + v1593;	// L1900
        float v1604 = v1603 + v1596;	// L1901
        bool v1605 = v1604 > (float)0.000000;	// L1902
        float v1606 = v1605 ? v1604 : (float)0.000000;	// L1903
        v1586[v1588][v1589][v1590] = v1606;	// L1904
      }
    }
  }
}

void forward_node115(
  float v1607[128][16][16],
  float v1608[8][8][8],
  int v1609,
  int v1610,
  int v1611
) {	// L1910
  #pragma HLS inline
  #pragma HLS resource variable=v1608 core=ram_t2p_bram

  for (int v1612 = 0; v1612 < 8; v1612 += 1) {	// L1911
    for (int v1613 = 0; v1613 < 8; v1613 += 1) {	// L1912
      for (int v1614 = 0; v1614 < 8; v1614 += 1) {	// L1913
        #pragma HLS pipeline II=1
        float v1615 = v1607[(v1612 + (v1609 * 8))][(v1613 + (v1610 * 8))][(v1614 + (v1611 * 8))];	// L1914
        v1608[v1612][v1613][v1614] = v1615;	// L1915
      }
    }
  }
}

void forward_node116(
  float v1616[128][16][16],
  float v1617[8][8][8],
  int v1618,
  int v1619,
  int v1620
) {	// L1921
  #pragma HLS inline
  #pragma HLS resource variable=v1617 core=ram_t2p_bram

  for (int v1621 = 0; v1621 < 8; v1621 += 1) {	// L1922
    for (int v1622 = 0; v1622 < 8; v1622 += 1) {	// L1923
      for (int v1623 = 0; v1623 < 8; v1623 += 1) {	// L1924
        #pragma HLS pipeline II=1
        float v1624 = v1616[(v1621 + (v1618 * 8))][(v1622 + (v1619 * 8))][(v1623 + (v1620 * 8))];	// L1925
        v1617[v1621][v1622][v1623] = v1624;	// L1926
      }
    }
  }
}

void forward_node112(
  float v1625[128],
  float v1626[128][16][16],
  float v1627[128],
  float v1628[128],
  float v1629[128][16][16],
  float v1630[128],
  float v1631[128][16][16]
) {	// L1932
  #pragma HLS resource variable=v1625 core=ram_t2p_bram

  #pragma HLS resource variable=v1627 core=ram_t2p_bram

  #pragma HLS resource variable=v1628 core=ram_t2p_bram

  #pragma HLS resource variable=v1630 core=ram_t2p_bram

  for (int v1632 = 0; v1632 < 64; v1632 += 1) {	// L1933
    #pragma HLS dataflow
    int v1633 = (v1632 % 2);	// L1934
    int v1634 = ((v1632 / 2) % 2);	// L1935
    int v1635 = ((v1632 / 2) / 2);	// L1936
    float v1636[8][8][8];	// L1937
    #pragma HLS resource variable=v1636 core=ram_t2p_bram

    float v1637[8][8][8];	// L1938
    #pragma HLS resource variable=v1637 core=ram_t2p_bram

    float v1638[8][8][8];	// L1939
    #pragma HLS resource variable=v1638 core=ram_t2p_bram

    forward_node116(v1626, v1638, v1635, v1634, v1633);	// L1940
    forward_node115(v1629, v1637, v1635, v1634, v1633);	// L1941
    forward_node114(v1637, v1638, v1630, v1625, v1627, v1628, v1636, v1635);	// L1942
    forward_node113(v1636, v1631, v1635, v1634, v1633);	// L1943
  }
}

void forward_node118(
  float v1639[8][8][8],
  float v1640[128][16][16],
  int v1641,
  int v1642,
  int v1643
) {	// L1947
  #pragma HLS inline
  #pragma HLS array_partition variable=v1639 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1639 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1639 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1640 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1640 cyclic factor=2 dim=3

  for (int v1644 = 0; v1644 < 8; v1644 += 1) {	// L1948
    for (int v1645 = 0; v1645 < 8; v1645 += 2) {	// L1949
      for (int v1646 = 0; v1646 < 8; v1646 += 2) {	// L1950
        #pragma HLS pipeline II=1
        float v1647 = v1639[v1644][v1645][v1646];	// L1951
        v1640[(v1644 + (v1641 * 8))][(v1645 + (v1642 * 8))][(v1646 + (v1643 * 8))] = v1647;	// L1952
        float v1648 = v1639[v1644][v1645][(v1646 + 1)];	// L1953
        v1640[(v1644 + (v1641 * 8))][(v1645 + (v1642 * 8))][((v1646 + (v1643 * 8)) + 1)] = v1648;	// L1954
        float v1649 = v1639[v1644][(v1645 + 1)][v1646];	// L1955
        v1640[(v1644 + (v1641 * 8))][((v1645 + (v1642 * 8)) + 1)][(v1646 + (v1643 * 8))] = v1649;	// L1956
        float v1650 = v1639[v1644][(v1645 + 1)][(v1646 + 1)];	// L1957
        v1640[(v1644 + (v1641 * 8))][((v1645 + (v1642 * 8)) + 1)][((v1646 + (v1643 * 8)) + 1)] = v1650;	// L1958
      }
    }
  }
}

void forward_node119(
  float v1651[8][8][8],
  float v1652[8][8],
  float v1653[8][8][8],
  float v1654[8][8][8]
) {	// L1964
  #pragma HLS inline
  #pragma HLS array_partition variable=v1651 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1651 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1651 core=ram_t2p_bram

  #pragma HLS resource variable=v1652 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1653 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1653 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1653 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1654 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1654 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1654 core=ram_t2p_bram

  for (int v1655 = 0; v1655 < 8; v1655 += 1) {	// L1965
    for (int v1656 = 0; v1656 < 8; v1656 += 1) {	// L1966
      for (int v1657 = 0; v1657 < 8; v1657 += 2) {	// L1967
        for (int v1658 = 0; v1658 < 8; v1658 += 2) {	// L1968
          #pragma HLS pipeline II=1
          float v1659 = v1651[v1655][v1657][v1658];	// L1969
          float v1660 = v1652[v1656][v1655];	// L1970
          float v1661 = v1653[v1656][v1657][v1658];	// L1971
          float v1662 = v1654[v1656][v1657][v1658];	// L1972
          float v1663 = (v1655 == 0) ? v1661 : v1662;	// L1973
          float v1664 = v1659 * v1660;	// L1974
          float v1665 = v1663 + v1664;	// L1975
          v1654[v1656][v1657][v1658] = v1665;	// L1976
          float v1666 = v1651[v1655][v1657][(v1658 + 1)];	// L1977
          float v1667 = v1653[v1656][v1657][(v1658 + 1)];	// L1978
          float v1668 = v1654[v1656][v1657][(v1658 + 1)];	// L1979
          float v1669 = (v1655 == 0) ? v1667 : v1668;	// L1980
          float v1670 = v1666 * v1660;	// L1981
          float v1671 = v1669 + v1670;	// L1982
          v1654[v1656][v1657][(v1658 + 1)] = v1671;	// L1983
          float v1672 = v1651[v1655][(v1657 + 1)][v1658];	// L1984
          float v1673 = v1653[v1656][(v1657 + 1)][v1658];	// L1985
          float v1674 = v1654[v1656][(v1657 + 1)][v1658];	// L1986
          float v1675 = (v1655 == 0) ? v1673 : v1674;	// L1987
          float v1676 = v1672 * v1660;	// L1988
          float v1677 = v1675 + v1676;	// L1989
          v1654[v1656][(v1657 + 1)][v1658] = v1677;	// L1990
          float v1678 = v1651[v1655][(v1657 + 1)][(v1658 + 1)];	// L1991
          float v1679 = v1653[v1656][(v1657 + 1)][(v1658 + 1)];	// L1992
          float v1680 = v1654[v1656][(v1657 + 1)][(v1658 + 1)];	// L1993
          float v1681 = (v1655 == 0) ? v1679 : v1680;	// L1994
          float v1682 = v1678 * v1660;	// L1995
          float v1683 = v1681 + v1682;	// L1996
          v1654[v1656][(v1657 + 1)][(v1658 + 1)] = v1683;	// L1997
        }
      }
    }
  }
}

void forward_node120(
  float v1684[128][16][16],
  float v1685[8][8][8],
  int v1686,
  int v1687,
  int v1688
) {	// L2004
  #pragma HLS inline
  #pragma HLS array_partition variable=v1684 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1684 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v1685 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1685 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1685 core=ram_t2p_bram

  for (int v1689 = 0; v1689 < 8; v1689 += 1) {	// L2005
    for (int v1690 = 0; v1690 < 8; v1690 += 2) {	// L2006
      for (int v1691 = 0; v1691 < 8; v1691 += 2) {	// L2007
        #pragma HLS pipeline II=1
        float v1692 = v1684[(v1689 + (v1686 * 8))][(v1690 + (v1687 * 8))][(v1691 + (v1688 * 8))];	// L2008
        v1685[v1689][v1690][v1691] = v1692;	// L2009
        float v1693 = v1684[(v1689 + (v1686 * 8))][(v1690 + (v1687 * 8))][((v1691 + (v1688 * 8)) + 1)];	// L2010
        v1685[v1689][v1690][(v1691 + 1)] = v1693;	// L2011
        float v1694 = v1684[(v1689 + (v1686 * 8))][((v1690 + (v1687 * 8)) + 1)][(v1691 + (v1688 * 8))];	// L2012
        v1685[v1689][(v1690 + 1)][v1691] = v1694;	// L2013
        float v1695 = v1684[(v1689 + (v1686 * 8))][((v1690 + (v1687 * 8)) + 1)][((v1691 + (v1688 * 8)) + 1)];	// L2014
        v1685[v1689][(v1690 + 1)][(v1691 + 1)] = v1695;	// L2015
      }
    }
  }
}

void forward_node121(
  float v1696[128][128][3][3],
  float v1697[8][8],
  int v1698,
  int v1699,
  int v1700,
  int v1701
) {	// L2021
  #pragma HLS inline
  #pragma HLS resource variable=v1697 core=ram_t2p_bram

  for (int v1702 = 0; v1702 < 8; v1702 += 1) {	// L2022
    for (int v1703 = 0; v1703 < 8; v1703 += 1) {	// L2023
      #pragma HLS pipeline II=1
      float v1704 = v1696[(v1702 + (v1700 * 8))][(v1703 + (v1701 * 8))][v1698][v1699];	// L2024
      v1697[v1702][v1703] = v1704;	// L2025
    }
  }
}

void forward_node122(
  float v1705[128][16][16],
  float v1706[8][8][8],
  int v1707,
  int v1708,
  int v1709,
  int v1710,
  int v1711
) {	// L2030
  #pragma HLS inline
  #pragma HLS array_partition variable=v1705 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1705 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v1706 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1706 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1706 core=ram_t2p_bram

  for (int v1712 = 0; v1712 < 8; v1712 += 1) {	// L2031
    for (int v1713 = 0; v1713 < 8; v1713 += 2) {	// L2032
      for (int v1714 = 0; v1714 < 8; v1714 += 2) {	// L2033
        #pragma HLS pipeline II=1
        float v1715 = v1705[(v1712 + (v1707 * 8))][(((v1713 + v1708) + (v1709 * 8)) - 1)][(((v1714 + v1710) + (v1711 * 8)) - 1)];	// L2034
        v1706[v1712][v1713][v1714] = v1715;	// L2035
        float v1716 = v1705[(v1712 + (v1707 * 8))][(((v1713 + v1708) + (v1709 * 8)) - 1)][((v1714 + v1710) + (v1711 * 8))];	// L2036
        v1706[v1712][v1713][(v1714 + 1)] = v1716;	// L2037
        float v1717 = v1705[(v1712 + (v1707 * 8))][((v1713 + v1708) + (v1709 * 8))][(((v1714 + v1710) + (v1711 * 8)) - 1)];	// L2038
        v1706[v1712][(v1713 + 1)][v1714] = v1717;	// L2039
        float v1718 = v1705[(v1712 + (v1707 * 8))][((v1713 + v1708) + (v1709 * 8))][((v1714 + v1710) + (v1711 * 8))];	// L2040
        v1706[v1712][(v1713 + 1)][(v1714 + 1)] = v1718;	// L2041
      }
    }
  }
}

void forward_node117(
  float v1719[128][16][16],
  float v1720[128][128][3][3],
  float v1721[128][16][16],
  float v1722[128][16][16]
) {	// L2047
  #pragma HLS array_partition variable=v1719 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1719 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v1721 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1721 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v1722 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1722 cyclic factor=2 dim=3

  for (int v1723 = 0; v1723 < 9216; v1723 += 1) {	// L2048
    #pragma HLS dataflow
    int v1724 = (v1723 % 2);	// L2049
    int v1725 = ((v1723 / 2) % 2);	// L2050
    int v1726 = (((v1723 / 2) / 2) % 16);	// L2051
    int v1727 = ((((v1723 / 2) / 2) / 16) % 3);	// L2052
    int v1728 = (((((v1723 / 2) / 2) / 16) / 3) % 3);	// L2053
    int v1729 = (((((v1723 / 2) / 2) / 16) / 3) / 3);	// L2054
    float v1730[8][8][8];	// L2055
    #pragma HLS array_partition variable=v1730 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v1730 cyclic factor=2 dim=3
    #pragma HLS resource variable=v1730 core=ram_t2p_bram

    float v1731[8][8];	// L2056
    #pragma HLS resource variable=v1731 core=ram_t2p_bram

    float v1732[8][8][8];	// L2057
    #pragma HLS array_partition variable=v1732 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v1732 cyclic factor=2 dim=3
    #pragma HLS resource variable=v1732 core=ram_t2p_bram

    forward_node122(v1719, v1732, v1729, v1728, v1725, v1727, v1724);	// L2058
    forward_node121(v1720, v1731, v1728, v1727, v1726, v1729);	// L2059
    forward_node120(v1721, v1730, v1726, v1725, v1724);	// L2060
    float v1733[8][8][8];	// L2061
    #pragma HLS array_partition variable=v1733 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v1733 cyclic factor=2 dim=3
    #pragma HLS resource variable=v1733 core=ram_t2p_bram

    forward_node119(v1732, v1731, v1730, v1733);	// L2062
    forward_node118(v1733, v1722, v1726, v1725, v1724);	// L2063
  }
}

void forward_node124(
  float v1734[8][8][8],
  float v1735[128][16][16],
  int v1736,
  int v1737,
  int v1738
) {	// L2067
  #pragma HLS inline
  #pragma HLS resource variable=v1734 core=ram_t2p_bram

  for (int v1739 = 0; v1739 < 8; v1739 += 1) {	// L2068
    for (int v1740 = 0; v1740 < 8; v1740 += 1) {	// L2069
      for (int v1741 = 0; v1741 < 8; v1741 += 1) {	// L2070
        #pragma HLS pipeline II=1
        float v1742 = v1734[v1739][v1740][v1741];	// L2071
        v1735[(v1739 + (v1736 * 8))][(v1740 + (v1737 * 8))][(v1741 + (v1738 * 8))] = v1742;	// L2072
      }
    }
  }
}

void forward_node125(
  float v1743[128],
  float v1744[128],
  float v1745[128],
  float v1746[128],
  float v1747[8][8][8],
  float v1748[8][8][8],
  int v1749
) {	// L2078
  #pragma HLS inline
  #pragma HLS resource variable=v1743 core=ram_t2p_bram

  #pragma HLS resource variable=v1744 core=ram_t2p_bram

  #pragma HLS resource variable=v1745 core=ram_t2p_bram

  #pragma HLS resource variable=v1746 core=ram_t2p_bram

  #pragma HLS resource variable=v1747 core=ram_t2p_bram

  #pragma HLS resource variable=v1748 core=ram_t2p_bram

  for (int v1750 = 0; v1750 < 8; v1750 += 1) {	// L2081
    for (int v1751 = 0; v1751 < 8; v1751 += 1) {	// L2082
      for (int v1752 = 0; v1752 < 8; v1752 += 1) {	// L2083
        #pragma HLS pipeline II=1
        float v1753 = v1747[v1750][v1751][v1752];	// L2084
        float v1754 = v1743[(v1750 + (v1749 * 8))];	// L2085
        float v1755 = v1744[(v1750 + (v1749 * 8))];	// L2086
        float v1756 = v1746[(v1750 + (v1749 * 8))];	// L2087
        float v1757 = v1745[(v1750 + (v1749 * 8))];	// L2088
        float v1758 = (double)0.000010;	// L2089
        float v1759 = v1757 + v1758;	// L2090
        float v1760 = 1.0 / sqrt(v1759);	// L2091
        float v1761 = v1753 - v1756;	// L2092
        float v1762 = v1761 * v1760;	// L2093
        float v1763 = v1762 * v1754;	// L2094
        float v1764 = v1763 + v1755;	// L2095
        bool v1765 = v1764 > (float)0.000000;	// L2096
        float v1766 = v1765 ? v1764 : (float)0.000000;	// L2097
        v1748[v1750][v1751][v1752] = v1766;	// L2098
      }
    }
  }
}

void forward_node126(
  float v1767[128][16][16],
  float v1768[8][8][8],
  int v1769,
  int v1770,
  int v1771
) {	// L2104
  #pragma HLS inline
  #pragma HLS resource variable=v1768 core=ram_t2p_bram

  for (int v1772 = 0; v1772 < 8; v1772 += 1) {	// L2105
    for (int v1773 = 0; v1773 < 8; v1773 += 1) {	// L2106
      for (int v1774 = 0; v1774 < 8; v1774 += 1) {	// L2107
        #pragma HLS pipeline II=1
        float v1775 = v1767[(v1772 + (v1769 * 8))][(v1773 + (v1770 * 8))][(v1774 + (v1771 * 8))];	// L2108
        v1768[v1772][v1773][v1774] = v1775;	// L2109
      }
    }
  }
}

void forward_node123(
  float v1776[128],
  float v1777[128][16][16],
  float v1778[128],
  float v1779[128],
  float v1780[128],
  float v1781[128][16][16]
) {	// L2115
  #pragma HLS resource variable=v1776 core=ram_t2p_bram

  #pragma HLS resource variable=v1778 core=ram_t2p_bram

  #pragma HLS resource variable=v1779 core=ram_t2p_bram

  #pragma HLS resource variable=v1780 core=ram_t2p_bram

  for (int v1782 = 0; v1782 < 64; v1782 += 1) {	// L2116
    #pragma HLS dataflow
    int v1783 = (v1782 % 2);	// L2117
    int v1784 = ((v1782 / 2) % 2);	// L2118
    int v1785 = ((v1782 / 2) / 2);	// L2119
    float v1786[8][8][8];	// L2120
    #pragma HLS resource variable=v1786 core=ram_t2p_bram

    float v1787[8][8][8];	// L2121
    #pragma HLS resource variable=v1787 core=ram_t2p_bram

    forward_node126(v1777, v1787, v1785, v1784, v1783);	// L2122
    forward_node125(v1779, v1778, v1780, v1776, v1787, v1786, v1785);	// L2123
    forward_node124(v1786, v1781, v1785, v1784, v1783);	// L2124
  }
}

void forward_node128(
  float v1788[8][8][8],
  float v1789[128][16][16],
  int v1790,
  int v1791,
  int v1792
) {	// L2128
  #pragma HLS inline
  #pragma HLS array_partition variable=v1788 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1788 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1788 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1789 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1789 cyclic factor=2 dim=3

  for (int v1793 = 0; v1793 < 8; v1793 += 1) {	// L2129
    for (int v1794 = 0; v1794 < 8; v1794 += 2) {	// L2130
      for (int v1795 = 0; v1795 < 8; v1795 += 2) {	// L2131
        #pragma HLS pipeline II=1
        float v1796 = v1788[v1793][v1794][v1795];	// L2132
        v1789[(v1793 + (v1790 * 8))][(v1794 + (v1791 * 8))][(v1795 + (v1792 * 8))] = v1796;	// L2133
        float v1797 = v1788[v1793][v1794][(v1795 + 1)];	// L2134
        v1789[(v1793 + (v1790 * 8))][(v1794 + (v1791 * 8))][((v1795 + (v1792 * 8)) + 1)] = v1797;	// L2135
        float v1798 = v1788[v1793][(v1794 + 1)][v1795];	// L2136
        v1789[(v1793 + (v1790 * 8))][((v1794 + (v1791 * 8)) + 1)][(v1795 + (v1792 * 8))] = v1798;	// L2137
        float v1799 = v1788[v1793][(v1794 + 1)][(v1795 + 1)];	// L2138
        v1789[(v1793 + (v1790 * 8))][((v1794 + (v1791 * 8)) + 1)][((v1795 + (v1792 * 8)) + 1)] = v1799;	// L2139
      }
    }
  }
}

void forward_node129(
  float v1800[8][8][8],
  float v1801[8][8],
  float v1802[8][8][8],
  float v1803[8][8][8],
  float v1804[8][8][8],
  int v1805,
  int v1806,
  int v1807
) {	// L2145
  #pragma HLS inline
  #pragma HLS array_partition variable=v1800 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1800 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1800 core=ram_t2p_bram

  #pragma HLS resource variable=v1801 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1802 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1802 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1802 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1803 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1803 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1803 core=ram_t2p_bram

  #pragma HLS array_partition variable=v1804 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1804 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1804 core=ram_t2p_bram

  for (int v1808 = 0; v1808 < 8; v1808 += 1) {	// L2146
    for (int v1809 = 0; v1809 < 8; v1809 += 1) {	// L2147
      for (int v1810 = 0; v1810 < 8; v1810 += 2) {	// L2148
        for (int v1811 = 0; v1811 < 8; v1811 += 2) {	// L2149
          #pragma HLS pipeline II=1
          float v1812 = v1800[v1809][v1810][v1811];	// L2150
          float v1813 = v1803[v1809][v1810][v1811];	// L2151
          float v1814 = v1804[v1809][v1810][v1811];	// L2152
          float v1815 = (v1808 == 0) ? v1813 : v1814;	// L2153
          float v1816 = ((v1808 + (v1807 * 8)) == 0 && v1805 == 0 && v1806 == 0) ? v1812 : v1815;	// L2154
          float v1817 = v1802[v1808][v1810][v1811];	// L2155
          float v1818 = v1801[v1809][v1808];	// L2156
          float v1819 = v1817 * v1818;	// L2157
          float v1820 = v1816 + v1819;	// L2158
          v1804[v1809][v1810][v1811] = v1820;	// L2159
          float v1821 = v1800[v1809][v1810][(v1811 + 1)];	// L2160
          float v1822 = v1803[v1809][v1810][(v1811 + 1)];	// L2161
          float v1823 = v1804[v1809][v1810][(v1811 + 1)];	// L2162
          float v1824 = (v1808 == 0) ? v1822 : v1823;	// L2163
          float v1825 = ((v1808 + (v1807 * 8)) == 0 && v1805 == 0 && v1806 == 0) ? v1821 : v1824;	// L2164
          float v1826 = v1802[v1808][v1810][(v1811 + 1)];	// L2165
          float v1827 = v1826 * v1818;	// L2166
          float v1828 = v1825 + v1827;	// L2167
          v1804[v1809][v1810][(v1811 + 1)] = v1828;	// L2168
          float v1829 = v1800[v1809][(v1810 + 1)][v1811];	// L2169
          float v1830 = v1803[v1809][(v1810 + 1)][v1811];	// L2170
          float v1831 = v1804[v1809][(v1810 + 1)][v1811];	// L2171
          float v1832 = (v1808 == 0) ? v1830 : v1831;	// L2172
          float v1833 = ((v1808 + (v1807 * 8)) == 0 && v1805 == 0 && v1806 == 0) ? v1829 : v1832;	// L2173
          float v1834 = v1802[v1808][(v1810 + 1)][v1811];	// L2174
          float v1835 = v1834 * v1818;	// L2175
          float v1836 = v1833 + v1835;	// L2176
          v1804[v1809][(v1810 + 1)][v1811] = v1836;	// L2177
          float v1837 = v1800[v1809][(v1810 + 1)][(v1811 + 1)];	// L2178
          float v1838 = v1803[v1809][(v1810 + 1)][(v1811 + 1)];	// L2179
          float v1839 = v1804[v1809][(v1810 + 1)][(v1811 + 1)];	// L2180
          float v1840 = (v1808 == 0) ? v1838 : v1839;	// L2181
          float v1841 = ((v1808 + (v1807 * 8)) == 0 && v1805 == 0 && v1806 == 0) ? v1837 : v1840;	// L2182
          float v1842 = v1802[v1808][(v1810 + 1)][(v1811 + 1)];	// L2183
          float v1843 = v1842 * v1818;	// L2184
          float v1844 = v1841 + v1843;	// L2185
          v1804[v1809][(v1810 + 1)][(v1811 + 1)] = v1844;	// L2186
        }
      }
    }
  }
}

void forward_node130(
  float v1845[128][128][3][3],
  float v1846[8][8],
  int v1847,
  int v1848,
  int v1849,
  int v1850
) {	// L2193
  #pragma HLS inline
  #pragma HLS resource variable=v1846 core=ram_t2p_bram

  for (int v1851 = 0; v1851 < 8; v1851 += 1) {	// L2194
    for (int v1852 = 0; v1852 < 8; v1852 += 1) {	// L2195
      #pragma HLS pipeline II=1
      float v1853 = v1845[(v1851 + (v1849 * 8))][(v1852 + (v1850 * 8))][v1847][v1848];	// L2196
      v1846[v1851][v1852] = v1853;	// L2197
    }
  }
}

void forward_node131(
  float v1854[128][16][16],
  float v1855[8][8][8],
  int v1856,
  int v1857,
  int v1858,
  int v1859,
  int v1860
) {	// L2202
  #pragma HLS inline
  #pragma HLS array_partition variable=v1854 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1854 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v1855 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1855 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1855 core=ram_t2p_bram

  for (int v1861 = 0; v1861 < 8; v1861 += 1) {	// L2203
    for (int v1862 = 0; v1862 < 8; v1862 += 2) {	// L2204
      for (int v1863 = 0; v1863 < 8; v1863 += 2) {	// L2205
        #pragma HLS pipeline II=1
        float v1864 = v1854[(v1861 + (v1856 * 8))][(((v1862 + v1857) + (v1858 * 8)) - 1)][(((v1863 + v1859) + (v1860 * 8)) - 1)];	// L2206
        v1855[v1861][v1862][v1863] = v1864;	// L2207
        float v1865 = v1854[(v1861 + (v1856 * 8))][(((v1862 + v1857) + (v1858 * 8)) - 1)][((v1863 + v1859) + (v1860 * 8))];	// L2208
        v1855[v1861][v1862][(v1863 + 1)] = v1865;	// L2209
        float v1866 = v1854[(v1861 + (v1856 * 8))][((v1862 + v1857) + (v1858 * 8))][(((v1863 + v1859) + (v1860 * 8)) - 1)];	// L2210
        v1855[v1861][(v1862 + 1)][v1863] = v1866;	// L2211
        float v1867 = v1854[(v1861 + (v1856 * 8))][((v1862 + v1857) + (v1858 * 8))][((v1863 + v1859) + (v1860 * 8))];	// L2212
        v1855[v1861][(v1862 + 1)][(v1863 + 1)] = v1867;	// L2213
      }
    }
  }
}

void forward_node132(
  float v1868[128][16][16],
  float v1869[8][8][8],
  int v1870,
  int v1871,
  int v1872
) {	// L2219
  #pragma HLS inline
  #pragma HLS array_partition variable=v1868 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1868 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v1869 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1869 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1869 core=ram_t2p_bram

  for (int v1873 = 0; v1873 < 8; v1873 += 1) {	// L2220
    for (int v1874 = 0; v1874 < 8; v1874 += 2) {	// L2221
      for (int v1875 = 0; v1875 < 8; v1875 += 2) {	// L2222
        #pragma HLS pipeline II=1
        float v1876 = v1868[(v1873 + (v1870 * 8))][(v1874 + (v1871 * 8))][(v1875 + (v1872 * 8))];	// L2223
        v1869[v1873][v1874][v1875] = v1876;	// L2224
        float v1877 = v1868[(v1873 + (v1870 * 8))][(v1874 + (v1871 * 8))][((v1875 + (v1872 * 8)) + 1)];	// L2225
        v1869[v1873][v1874][(v1875 + 1)] = v1877;	// L2226
        float v1878 = v1868[(v1873 + (v1870 * 8))][((v1874 + (v1871 * 8)) + 1)][(v1875 + (v1872 * 8))];	// L2227
        v1869[v1873][(v1874 + 1)][v1875] = v1878;	// L2228
        float v1879 = v1868[(v1873 + (v1870 * 8))][((v1874 + (v1871 * 8)) + 1)][((v1875 + (v1872 * 8)) + 1)];	// L2229
        v1869[v1873][(v1874 + 1)][(v1875 + 1)] = v1879;	// L2230
      }
    }
  }
}

void forward_node133(
  float v1880[128][16][16],
  float v1881[8][8][8],
  int v1882,
  int v1883,
  int v1884
) {	// L2236
  #pragma HLS inline
  #pragma HLS array_partition variable=v1880 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1880 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v1881 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1881 cyclic factor=2 dim=3
  #pragma HLS resource variable=v1881 core=ram_t2p_bram

  for (int v1885 = 0; v1885 < 8; v1885 += 1) {	// L2237
    for (int v1886 = 0; v1886 < 8; v1886 += 2) {	// L2238
      for (int v1887 = 0; v1887 < 8; v1887 += 2) {	// L2239
        #pragma HLS pipeline II=1
        float v1888 = v1880[(v1885 + (v1882 * 8))][(v1886 + (v1883 * 8))][(v1887 + (v1884 * 8))];	// L2240
        v1881[v1885][v1886][v1887] = v1888;	// L2241
        float v1889 = v1880[(v1885 + (v1882 * 8))][(v1886 + (v1883 * 8))][((v1887 + (v1884 * 8)) + 1)];	// L2242
        v1881[v1885][v1886][(v1887 + 1)] = v1889;	// L2243
        float v1890 = v1880[(v1885 + (v1882 * 8))][((v1886 + (v1883 * 8)) + 1)][(v1887 + (v1884 * 8))];	// L2244
        v1881[v1885][(v1886 + 1)][v1887] = v1890;	// L2245
        float v1891 = v1880[(v1885 + (v1882 * 8))][((v1886 + (v1883 * 8)) + 1)][((v1887 + (v1884 * 8)) + 1)];	// L2246
        v1881[v1885][(v1886 + 1)][(v1887 + 1)] = v1891;	// L2247
      }
    }
  }
}

void forward_node127(
  float v1892[128][128][3][3],
  float v1893[128][16][16],
  float v1894[128][16][16],
  float v1895[128][16][16],
  float v1896[128][16][16]
) {	// L2253
  #pragma HLS array_partition variable=v1893 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1893 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v1894 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1894 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v1895 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1895 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v1896 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v1896 cyclic factor=2 dim=3

  for (int v1897 = 0; v1897 < 9216; v1897 += 1) {	// L2254
    #pragma HLS dataflow
    int v1898 = (v1897 % 2);	// L2255
    int v1899 = ((v1897 / 2) % 2);	// L2256
    int v1900 = (((v1897 / 2) / 2) % 16);	// L2257
    int v1901 = ((((v1897 / 2) / 2) / 16) % 3);	// L2258
    int v1902 = (((((v1897 / 2) / 2) / 16) / 3) % 3);	// L2259
    int v1903 = (((((v1897 / 2) / 2) / 16) / 3) / 3);	// L2260
    float v1904[8][8];	// L2261
    #pragma HLS resource variable=v1904 core=ram_t2p_bram

    float v1905[8][8][8];	// L2262
    #pragma HLS array_partition variable=v1905 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v1905 cyclic factor=2 dim=3
    #pragma HLS resource variable=v1905 core=ram_t2p_bram

    float v1906[8][8][8];	// L2263
    #pragma HLS array_partition variable=v1906 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v1906 cyclic factor=2 dim=3
    #pragma HLS resource variable=v1906 core=ram_t2p_bram

    float v1907[8][8][8];	// L2264
    #pragma HLS array_partition variable=v1907 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v1907 cyclic factor=2 dim=3
    #pragma HLS resource variable=v1907 core=ram_t2p_bram

    forward_node133(v1893, v1907, v1900, v1899, v1898);	// L2265
    forward_node132(v1895, v1906, v1900, v1899, v1898);	// L2266
    forward_node131(v1894, v1905, v1903, v1902, v1899, v1901, v1898);	// L2267
    forward_node130(v1892, v1904, v1902, v1901, v1900, v1903);	// L2268
    float v1908[8][8][8];	// L2269
    #pragma HLS array_partition variable=v1908 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v1908 cyclic factor=2 dim=3
    #pragma HLS resource variable=v1908 core=ram_t2p_bram

    forward_node129(v1907, v1904, v1905, v1906, v1908, v1902, v1901, v1903);	// L2270
    forward_node128(v1908, v1896, v1900, v1899, v1898);	// L2271
  }
}

void forward_node135(
  float v1909[8][8][8],
  float v1910[128][16][16],
  int v1911,
  int v1912,
  int v1913
) {	// L2275
  #pragma HLS inline
  #pragma HLS resource variable=v1909 core=ram_t2p_bram

  for (int v1914 = 0; v1914 < 8; v1914 += 1) {	// L2276
    for (int v1915 = 0; v1915 < 8; v1915 += 1) {	// L2277
      for (int v1916 = 0; v1916 < 8; v1916 += 1) {	// L2278
        #pragma HLS pipeline II=1
        float v1917 = v1909[v1914][v1915][v1916];	// L2279
        v1910[(v1914 + (v1911 * 8))][(v1915 + (v1912 * 8))][(v1916 + (v1913 * 8))] = v1917;	// L2280
      }
    }
  }
}

void forward_node136(
  float v1918[8][8][8],
  float v1919[128],
  float v1920[128],
  float v1921[128],
  float v1922[8][8][8],
  float v1923[128],
  float v1924[128],
  float v1925[128],
  float v1926[128],
  float v1927[8][8][8],
  int v1928
) {	// L2286
  #pragma HLS inline
  #pragma HLS resource variable=v1918 core=ram_t2p_bram

  #pragma HLS resource variable=v1919 core=ram_t2p_bram

  #pragma HLS resource variable=v1920 core=ram_t2p_bram

  #pragma HLS resource variable=v1921 core=ram_t2p_bram

  #pragma HLS resource variable=v1922 core=ram_t2p_bram

  #pragma HLS resource variable=v1923 core=ram_t2p_bram

  #pragma HLS resource variable=v1924 core=ram_t2p_bram

  #pragma HLS resource variable=v1925 core=ram_t2p_bram

  #pragma HLS resource variable=v1926 core=ram_t2p_bram

  #pragma HLS resource variable=v1927 core=ram_t2p_bram

  for (int v1929 = 0; v1929 < 8; v1929 += 1) {	// L2289
    for (int v1930 = 0; v1930 < 8; v1930 += 1) {	// L2290
      for (int v1931 = 0; v1931 < 8; v1931 += 1) {	// L2291
        #pragma HLS pipeline II=1
        float v1932 = v1918[v1929][v1930][v1931];	// L2292
        float v1933 = v1920[(v1929 + (v1928 * 8))];	// L2293
        float v1934 = v1924[(v1929 + (v1928 * 8))];	// L2294
        float v1935 = v1926[(v1929 + (v1928 * 8))];	// L2295
        float v1936 = v1923[(v1929 + (v1928 * 8))];	// L2296
        float v1937 = v1922[v1929][v1930][v1931];	// L2297
        float v1938 = v1925[(v1929 + (v1928 * 8))];	// L2298
        float v1939 = v1919[(v1929 + (v1928 * 8))];	// L2299
        float v1940 = v1921[(v1929 + (v1928 * 8))];	// L2300
        float v1941 = (double)0.000010;	// L2301
        float v1942 = v1940 + v1941;	// L2302
        float v1943 = 1.0 / sqrt(v1942);	// L2303
        float v1944 = v1937 - v1939;	// L2304
        float v1945 = v1944 * v1943;	// L2305
        float v1946 = v1945 * v1938;	// L2306
        float v1947 = v1946 + v1934;	// L2307
        float v1948 = v1936 + v1941;	// L2308
        float v1949 = 1.0 / sqrt(v1948);	// L2309
        float v1950 = v1932 - v1935;	// L2310
        float v1951 = v1950 * v1949;	// L2311
        float v1952 = v1951 * v1933;	// L2312
        float v1953 = v1952 + v1934;	// L2313
        float v1954 = v1953 + v1947;	// L2314
        bool v1955 = v1954 > (float)0.000000;	// L2315
        float v1956 = v1955 ? v1954 : (float)0.000000;	// L2316
        v1927[v1929][v1930][v1931] = v1956;	// L2317
      }
    }
  }
}

void forward_node137(
  float v1957[128][16][16],
  float v1958[8][8][8],
  int v1959,
  int v1960,
  int v1961
) {	// L2323
  #pragma HLS inline
  #pragma HLS resource variable=v1958 core=ram_t2p_bram

  for (int v1962 = 0; v1962 < 8; v1962 += 1) {	// L2324
    for (int v1963 = 0; v1963 < 8; v1963 += 1) {	// L2325
      for (int v1964 = 0; v1964 < 8; v1964 += 1) {	// L2326
        #pragma HLS pipeline II=1
        float v1965 = v1957[(v1962 + (v1959 * 8))][(v1963 + (v1960 * 8))][(v1964 + (v1961 * 8))];	// L2327
        v1958[v1962][v1963][v1964] = v1965;	// L2328
      }
    }
  }
}

void forward_node138(
  float v1966[128][16][16],
  float v1967[8][8][8],
  int v1968,
  int v1969,
  int v1970
) {	// L2334
  #pragma HLS inline
  #pragma HLS resource variable=v1967 core=ram_t2p_bram

  for (int v1971 = 0; v1971 < 8; v1971 += 1) {	// L2335
    for (int v1972 = 0; v1972 < 8; v1972 += 1) {	// L2336
      for (int v1973 = 0; v1973 < 8; v1973 += 1) {	// L2337
        #pragma HLS pipeline II=1
        float v1974 = v1966[(v1971 + (v1968 * 8))][(v1972 + (v1969 * 8))][(v1973 + (v1970 * 8))];	// L2338
        v1967[v1971][v1972][v1973] = v1974;	// L2339
      }
    }
  }
}

void forward_node134(
  float v1975[128][16][16],
  float v1976[128],
  float v1977[128],
  float v1978[128][16][16],
  float v1979[128],
  float v1980[128],
  float v1981[128],
  float v1982[128],
  float v1983[128],
  float v1984[128][16][16]
) {	// L2345
  #pragma HLS resource variable=v1976 core=ram_t2p_bram

  #pragma HLS resource variable=v1977 core=ram_t2p_bram

  #pragma HLS resource variable=v1979 core=ram_t2p_bram

  #pragma HLS resource variable=v1980 core=ram_t2p_bram

  #pragma HLS resource variable=v1981 core=ram_t2p_bram

  #pragma HLS resource variable=v1982 core=ram_t2p_bram

  #pragma HLS resource variable=v1983 core=ram_t2p_bram

  for (int v1985 = 0; v1985 < 64; v1985 += 1) {	// L2346
    #pragma HLS dataflow
    int v1986 = (v1985 % 2);	// L2347
    int v1987 = ((v1985 / 2) % 2);	// L2348
    int v1988 = ((v1985 / 2) / 2);	// L2349
    float v1989[8][8][8];	// L2350
    #pragma HLS resource variable=v1989 core=ram_t2p_bram

    float v1990[8][8][8];	// L2351
    #pragma HLS resource variable=v1990 core=ram_t2p_bram

    float v1991[8][8][8];	// L2352
    #pragma HLS resource variable=v1991 core=ram_t2p_bram

    forward_node138(v1978, v1991, v1988, v1987, v1986);	// L2353
    forward_node137(v1975, v1990, v1988, v1987, v1986);	// L2354
    forward_node136(v1991, v1979, v1980, v1983, v1990, v1976, v1977, v1982, v1981, v1989, v1988);	// L2355
    forward_node135(v1989, v1984, v1988, v1987, v1986);	// L2356
  }
}

void forward_node140(
  float v1992[8][8][8],
  float v1993[128][16][16],
  int v1994,
  int v1995,
  int v1996
) {	// L2360
  #pragma HLS inline
  #pragma HLS resource variable=v1992 core=ram_t2p_bram

  for (int v1997 = 0; v1997 < 8; v1997 += 1) {	// L2361
    for (int v1998 = 0; v1998 < 8; v1998 += 1) {	// L2362
      for (int v1999 = 0; v1999 < 8; v1999 += 1) {	// L2363
        #pragma HLS pipeline II=1
        float v2000 = v1992[v1997][v1998][v1999];	// L2364
        v1993[(v1997 + (v1994 * 8))][(v1998 + (v1995 * 8))][(v1999 + (v1996 * 8))] = v2000;	// L2365
      }
    }
  }
}

void forward_node141(
  float v2001[8][8][8],
  float v2002[8][8][8],
  float v2003[8][8],
  float v2004[8][8][8],
  float v2005[8][8][8],
  int v2006
) {	// L2371
  #pragma HLS inline
  #pragma HLS resource variable=v2001 core=ram_t2p_bram

  #pragma HLS resource variable=v2002 core=ram_t2p_bram

  #pragma HLS resource variable=v2003 core=ram_t2p_bram

  #pragma HLS resource variable=v2004 core=ram_t2p_bram

  #pragma HLS resource variable=v2005 core=ram_t2p_bram

  for (int v2007 = 0; v2007 < 8; v2007 += 1) {	// L2372
    for (int v2008 = 0; v2008 < 8; v2008 += 1) {	// L2373
      for (int v2009 = 0; v2009 < 8; v2009 += 1) {	// L2374
        for (int v2010 = 0; v2010 < 8; v2010 += 1) {	// L2375
          #pragma HLS pipeline II=1
          float v2011 = v2001[v2008][v2009][v2010];	// L2376
          float v2012 = v2004[v2008][v2009][v2010];	// L2377
          float v2013 = v2005[v2008][v2009][v2010];	// L2378
          float v2014 = (v2007 == 0) ? v2012 : v2013;	// L2379
          float v2015 = ((v2007 + (v2006 * 8)) == 0) ? v2011 : v2014;	// L2380
          float v2016 = v2002[v2007][v2009][v2010];	// L2381
          float v2017 = v2003[v2008][v2007];	// L2382
          float v2018 = v2016 * v2017;	// L2383
          float v2019 = v2015 + v2018;	// L2384
          v2005[v2008][v2009][v2010] = v2019;	// L2385
        }
      }
    }
  }
}

void forward_node142(
  float v2020[128][64],
  float v2021[8][8],
  int v2022,
  int v2023
) {	// L2392
  #pragma HLS inline
  #pragma HLS resource variable=v2021 core=ram_t2p_bram

  for (int v2024 = 0; v2024 < 8; v2024 += 1) {	// L2393
    for (int v2025 = 0; v2025 < 8; v2025 += 1) {	// L2394
      #pragma HLS pipeline II=1
      float v2026 = v2020[(v2024 + (v2022 * 8))][(v2025 + (v2023 * 8))];	// L2395
      v2021[v2024][v2025] = v2026;	// L2396
    }
  }
}

void forward_node143(
  float v2027[64][32][32],
  float v2028[8][8][8],
  int v2029,
  int v2030,
  int v2031
) {	// L2401
  #pragma HLS inline
  #pragma HLS resource variable=v2028 core=ram_t2p_bram

  for (int v2032 = 0; v2032 < 8; v2032 += 1) {	// L2402
    for (int v2033 = 0; v2033 < 8; v2033 += 1) {	// L2403
      for (int v2034 = 0; v2034 < 8; v2034 += 1) {	// L2404
        #pragma HLS pipeline II=1
        float v2035 = v2027[(v2032 + (v2029 * 8))][((v2033 * 2) + (v2030 * 16))][((v2034 * 2) + (v2031 * 16))];	// L2405
        v2028[v2032][v2033][v2034] = v2035;	// L2406
      }
    }
  }
}

void forward_node144(
  float v2036[128][16][16],
  float v2037[8][8][8],
  int v2038,
  int v2039,
  int v2040
) {	// L2412
  #pragma HLS inline
  #pragma HLS resource variable=v2037 core=ram_t2p_bram

  for (int v2041 = 0; v2041 < 8; v2041 += 1) {	// L2413
    for (int v2042 = 0; v2042 < 8; v2042 += 1) {	// L2414
      for (int v2043 = 0; v2043 < 8; v2043 += 1) {	// L2415
        #pragma HLS pipeline II=1
        float v2044 = v2036[(v2041 + (v2038 * 8))][(v2042 + (v2039 * 8))][(v2043 + (v2040 * 8))];	// L2416
        v2037[v2041][v2042][v2043] = v2044;	// L2417
      }
    }
  }
}

void forward_node145(
  float v2045[128][16][16],
  float v2046[8][8][8],
  int v2047,
  int v2048,
  int v2049
) {	// L2423
  #pragma HLS inline
  #pragma HLS resource variable=v2046 core=ram_t2p_bram

  for (int v2050 = 0; v2050 < 8; v2050 += 1) {	// L2424
    for (int v2051 = 0; v2051 < 8; v2051 += 1) {	// L2425
      for (int v2052 = 0; v2052 < 8; v2052 += 1) {	// L2426
        #pragma HLS pipeline II=1
        float v2053 = v2045[(v2050 + (v2047 * 8))][(v2051 + (v2048 * 8))][(v2052 + (v2049 * 8))];	// L2427
        v2046[v2050][v2051][v2052] = v2053;	// L2428
      }
    }
  }
}

void forward_node139(
  float v2054[64][32][32],
  float v2055[128][64],
  float v2056[128][16][16],
  float v2057[128][16][16],
  float v2058[128][16][16]
) {	// L2434
  for (int v2059 = 0; v2059 < 512; v2059 += 1) {	// L2435
    #pragma HLS dataflow
    int v2060 = (v2059 % 2);	// L2436
    int v2061 = ((v2059 / 2) % 2);	// L2437
    int v2062 = (((v2059 / 2) / 2) % 16);	// L2438
    int v2063 = (((v2059 / 2) / 2) / 16);	// L2439
    float v2064[8][8];	// L2440
    #pragma HLS resource variable=v2064 core=ram_t2p_bram

    float v2065[8][8][8];	// L2441
    #pragma HLS resource variable=v2065 core=ram_t2p_bram

    float v2066[8][8][8];	// L2442
    #pragma HLS resource variable=v2066 core=ram_t2p_bram

    float v2067[8][8][8];	// L2443
    #pragma HLS resource variable=v2067 core=ram_t2p_bram

    forward_node145(v2056, v2067, v2062, v2061, v2060);	// L2444
    forward_node144(v2057, v2066, v2062, v2061, v2060);	// L2445
    forward_node143(v2054, v2065, v2063, v2061, v2060);	// L2446
    forward_node142(v2055, v2064, v2062, v2063);	// L2447
    float v2068[8][8][8];	// L2448
    #pragma HLS resource variable=v2068 core=ram_t2p_bram

    forward_node141(v2067, v2065, v2064, v2066, v2068, v2063);	// L2449
    forward_node140(v2068, v2058, v2062, v2061, v2060);	// L2450
  }
}

void forward_node147(
  float v2069[8][8][8],
  float v2070[128][16][16],
  int v2071,
  int v2072,
  int v2073
) {	// L2454
  #pragma HLS inline
  #pragma HLS array_partition variable=v2069 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2069 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2069 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2070 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2070 cyclic factor=2 dim=3

  for (int v2074 = 0; v2074 < 8; v2074 += 1) {	// L2455
    for (int v2075 = 0; v2075 < 8; v2075 += 2) {	// L2456
      for (int v2076 = 0; v2076 < 8; v2076 += 2) {	// L2457
        #pragma HLS pipeline II=1
        float v2077 = v2069[v2074][v2075][v2076];	// L2458
        v2070[(v2074 + (v2071 * 8))][(v2075 + (v2072 * 8))][(v2076 + (v2073 * 8))] = v2077;	// L2459
        float v2078 = v2069[v2074][v2075][(v2076 + 1)];	// L2460
        v2070[(v2074 + (v2071 * 8))][(v2075 + (v2072 * 8))][((v2076 + (v2073 * 8)) + 1)] = v2078;	// L2461
        float v2079 = v2069[v2074][(v2075 + 1)][v2076];	// L2462
        v2070[(v2074 + (v2071 * 8))][((v2075 + (v2072 * 8)) + 1)][(v2076 + (v2073 * 8))] = v2079;	// L2463
        float v2080 = v2069[v2074][(v2075 + 1)][(v2076 + 1)];	// L2464
        v2070[(v2074 + (v2071 * 8))][((v2075 + (v2072 * 8)) + 1)][((v2076 + (v2073 * 8)) + 1)] = v2080;	// L2465
      }
    }
  }
}

void forward_node148(
  float v2081[8][8][8],
  float v2082[8][8],
  float v2083[8][8][8],
  float v2084[8][8][8],
  float v2085[8][8][8],
  int v2086,
  int v2087,
  int v2088
) {	// L2471
  #pragma HLS inline
  #pragma HLS array_partition variable=v2081 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2081 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2081 core=ram_t2p_bram

  #pragma HLS resource variable=v2082 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2083 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2083 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2083 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2084 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2084 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2084 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2085 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2085 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2085 core=ram_t2p_bram

  for (int v2089 = 0; v2089 < 8; v2089 += 1) {	// L2472
    for (int v2090 = 0; v2090 < 8; v2090 += 1) {	// L2473
      for (int v2091 = 0; v2091 < 8; v2091 += 2) {	// L2474
        for (int v2092 = 0; v2092 < 8; v2092 += 2) {	// L2475
          #pragma HLS pipeline II=1
          float v2093 = v2083[v2090][v2091][v2092];	// L2476
          float v2094 = v2084[v2090][v2091][v2092];	// L2477
          float v2095 = v2085[v2090][v2091][v2092];	// L2478
          float v2096 = (v2089 == 0) ? v2094 : v2095;	// L2479
          float v2097 = ((v2089 + (v2087 * 8)) == 0 && v2086 == 0 && v2088 == 0) ? v2093 : v2096;	// L2480
          float v2098 = v2081[v2089][v2091][v2092];	// L2481
          float v2099 = v2082[v2090][v2089];	// L2482
          float v2100 = v2098 * v2099;	// L2483
          float v2101 = v2097 + v2100;	// L2484
          v2085[v2090][v2091][v2092] = v2101;	// L2485
          float v2102 = v2083[v2090][v2091][(v2092 + 1)];	// L2486
          float v2103 = v2084[v2090][v2091][(v2092 + 1)];	// L2487
          float v2104 = v2085[v2090][v2091][(v2092 + 1)];	// L2488
          float v2105 = (v2089 == 0) ? v2103 : v2104;	// L2489
          float v2106 = ((v2089 + (v2087 * 8)) == 0 && v2086 == 0 && v2088 == 0) ? v2102 : v2105;	// L2490
          float v2107 = v2081[v2089][v2091][(v2092 + 1)];	// L2491
          float v2108 = v2107 * v2099;	// L2492
          float v2109 = v2106 + v2108;	// L2493
          v2085[v2090][v2091][(v2092 + 1)] = v2109;	// L2494
          float v2110 = v2083[v2090][(v2091 + 1)][v2092];	// L2495
          float v2111 = v2084[v2090][(v2091 + 1)][v2092];	// L2496
          float v2112 = v2085[v2090][(v2091 + 1)][v2092];	// L2497
          float v2113 = (v2089 == 0) ? v2111 : v2112;	// L2498
          float v2114 = ((v2089 + (v2087 * 8)) == 0 && v2086 == 0 && v2088 == 0) ? v2110 : v2113;	// L2499
          float v2115 = v2081[v2089][(v2091 + 1)][v2092];	// L2500
          float v2116 = v2115 * v2099;	// L2501
          float v2117 = v2114 + v2116;	// L2502
          v2085[v2090][(v2091 + 1)][v2092] = v2117;	// L2503
          float v2118 = v2083[v2090][(v2091 + 1)][(v2092 + 1)];	// L2504
          float v2119 = v2084[v2090][(v2091 + 1)][(v2092 + 1)];	// L2505
          float v2120 = v2085[v2090][(v2091 + 1)][(v2092 + 1)];	// L2506
          float v2121 = (v2089 == 0) ? v2119 : v2120;	// L2507
          float v2122 = ((v2089 + (v2087 * 8)) == 0 && v2086 == 0 && v2088 == 0) ? v2118 : v2121;	// L2508
          float v2123 = v2081[v2089][(v2091 + 1)][(v2092 + 1)];	// L2509
          float v2124 = v2123 * v2099;	// L2510
          float v2125 = v2122 + v2124;	// L2511
          v2085[v2090][(v2091 + 1)][(v2092 + 1)] = v2125;	// L2512
        }
      }
    }
  }
}

void forward_node149(
  float v2126[128][128][3][3],
  float v2127[8][8],
  int v2128,
  int v2129,
  int v2130,
  int v2131
) {	// L2519
  #pragma HLS inline
  #pragma HLS resource variable=v2127 core=ram_t2p_bram

  for (int v2132 = 0; v2132 < 8; v2132 += 1) {	// L2520
    for (int v2133 = 0; v2133 < 8; v2133 += 1) {	// L2521
      #pragma HLS pipeline II=1
      float v2134 = v2126[(v2132 + (v2130 * 8))][(v2133 + (v2131 * 8))][v2128][v2129];	// L2522
      v2127[v2132][v2133] = v2134;	// L2523
    }
  }
}

void forward_node150(
  float v2135[128][16][16],
  float v2136[8][8][8],
  int v2137,
  int v2138,
  int v2139,
  int v2140,
  int v2141
) {	// L2528
  #pragma HLS inline
  #pragma HLS array_partition variable=v2135 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2135 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2136 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2136 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2136 core=ram_t2p_bram

  for (int v2142 = 0; v2142 < 8; v2142 += 1) {	// L2529
    for (int v2143 = 0; v2143 < 8; v2143 += 2) {	// L2530
      for (int v2144 = 0; v2144 < 8; v2144 += 2) {	// L2531
        #pragma HLS pipeline II=1
        float v2145 = v2135[(v2142 + (v2137 * 8))][(((v2143 + v2138) + (v2139 * 8)) - 1)][(((v2144 + v2140) + (v2141 * 8)) - 1)];	// L2532
        v2136[v2142][v2143][v2144] = v2145;	// L2533
        float v2146 = v2135[(v2142 + (v2137 * 8))][(((v2143 + v2138) + (v2139 * 8)) - 1)][((v2144 + v2140) + (v2141 * 8))];	// L2534
        v2136[v2142][v2143][(v2144 + 1)] = v2146;	// L2535
        float v2147 = v2135[(v2142 + (v2137 * 8))][((v2143 + v2138) + (v2139 * 8))][(((v2144 + v2140) + (v2141 * 8)) - 1)];	// L2536
        v2136[v2142][(v2143 + 1)][v2144] = v2147;	// L2537
        float v2148 = v2135[(v2142 + (v2137 * 8))][((v2143 + v2138) + (v2139 * 8))][((v2144 + v2140) + (v2141 * 8))];	// L2538
        v2136[v2142][(v2143 + 1)][(v2144 + 1)] = v2148;	// L2539
      }
    }
  }
}

void forward_node151(
  float v2149[128][16][16],
  float v2150[8][8][8],
  int v2151,
  int v2152,
  int v2153
) {	// L2545
  #pragma HLS inline
  #pragma HLS array_partition variable=v2149 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2149 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2150 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2150 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2150 core=ram_t2p_bram

  for (int v2154 = 0; v2154 < 8; v2154 += 1) {	// L2546
    for (int v2155 = 0; v2155 < 8; v2155 += 2) {	// L2547
      for (int v2156 = 0; v2156 < 8; v2156 += 2) {	// L2548
        #pragma HLS pipeline II=1
        float v2157 = v2149[(v2154 + (v2151 * 8))][(v2155 + (v2152 * 8))][(v2156 + (v2153 * 8))];	// L2549
        v2150[v2154][v2155][v2156] = v2157;	// L2550
        float v2158 = v2149[(v2154 + (v2151 * 8))][(v2155 + (v2152 * 8))][((v2156 + (v2153 * 8)) + 1)];	// L2551
        v2150[v2154][v2155][(v2156 + 1)] = v2158;	// L2552
        float v2159 = v2149[(v2154 + (v2151 * 8))][((v2155 + (v2152 * 8)) + 1)][(v2156 + (v2153 * 8))];	// L2553
        v2150[v2154][(v2155 + 1)][v2156] = v2159;	// L2554
        float v2160 = v2149[(v2154 + (v2151 * 8))][((v2155 + (v2152 * 8)) + 1)][((v2156 + (v2153 * 8)) + 1)];	// L2555
        v2150[v2154][(v2155 + 1)][(v2156 + 1)] = v2160;	// L2556
      }
    }
  }
}

void forward_node152(
  float v2161[128][16][16],
  float v2162[8][8][8],
  int v2163,
  int v2164,
  int v2165
) {	// L2562
  #pragma HLS inline
  #pragma HLS array_partition variable=v2161 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2161 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2162 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2162 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2162 core=ram_t2p_bram

  for (int v2166 = 0; v2166 < 8; v2166 += 1) {	// L2563
    for (int v2167 = 0; v2167 < 8; v2167 += 2) {	// L2564
      for (int v2168 = 0; v2168 < 8; v2168 += 2) {	// L2565
        #pragma HLS pipeline II=1
        float v2169 = v2161[(v2166 + (v2163 * 8))][(v2167 + (v2164 * 8))][(v2168 + (v2165 * 8))];	// L2566
        v2162[v2166][v2167][v2168] = v2169;	// L2567
        float v2170 = v2161[(v2166 + (v2163 * 8))][(v2167 + (v2164 * 8))][((v2168 + (v2165 * 8)) + 1)];	// L2568
        v2162[v2166][v2167][(v2168 + 1)] = v2170;	// L2569
        float v2171 = v2161[(v2166 + (v2163 * 8))][((v2167 + (v2164 * 8)) + 1)][(v2168 + (v2165 * 8))];	// L2570
        v2162[v2166][(v2167 + 1)][v2168] = v2171;	// L2571
        float v2172 = v2161[(v2166 + (v2163 * 8))][((v2167 + (v2164 * 8)) + 1)][((v2168 + (v2165 * 8)) + 1)];	// L2572
        v2162[v2166][(v2167 + 1)][(v2168 + 1)] = v2172;	// L2573
      }
    }
  }
}

void forward_node146(
  float v2173[128][16][16],
  float v2174[128][16][16],
  float v2175[128][128][3][3],
  float v2176[128][16][16],
  float v2177[128][16][16]
) {	// L2579
  #pragma HLS array_partition variable=v2173 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2173 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2174 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2174 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2176 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2176 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2177 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2177 cyclic factor=2 dim=3

  for (int v2178 = 0; v2178 < 9216; v2178 += 1) {	// L2580
    #pragma HLS dataflow
    int v2179 = (v2178 % 2);	// L2581
    int v2180 = ((v2178 / 2) % 2);	// L2582
    int v2181 = (((v2178 / 2) / 2) % 16);	// L2583
    int v2182 = ((((v2178 / 2) / 2) / 16) % 3);	// L2584
    int v2183 = (((((v2178 / 2) / 2) / 16) / 3) % 3);	// L2585
    int v2184 = (((((v2178 / 2) / 2) / 16) / 3) / 3);	// L2586
    float v2185[8][8];	// L2587
    #pragma HLS resource variable=v2185 core=ram_t2p_bram

    float v2186[8][8][8];	// L2588
    #pragma HLS array_partition variable=v2186 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2186 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2186 core=ram_t2p_bram

    float v2187[8][8][8];	// L2589
    #pragma HLS array_partition variable=v2187 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2187 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2187 core=ram_t2p_bram

    float v2188[8][8][8];	// L2590
    #pragma HLS array_partition variable=v2188 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2188 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2188 core=ram_t2p_bram

    forward_node152(v2174, v2188, v2181, v2180, v2179);	// L2591
    forward_node151(v2176, v2187, v2181, v2180, v2179);	// L2592
    forward_node150(v2173, v2186, v2184, v2183, v2180, v2182, v2179);	// L2593
    forward_node149(v2175, v2185, v2183, v2182, v2181, v2184);	// L2594
    float v2189[8][8][8];	// L2595
    #pragma HLS array_partition variable=v2189 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2189 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2189 core=ram_t2p_bram

    forward_node148(v2186, v2185, v2188, v2187, v2189, v2183, v2184, v2182);	// L2596
    forward_node147(v2189, v2177, v2181, v2180, v2179);	// L2597
  }
}

void forward_node154(
  float v2190[8][8][8],
  float v2191[128][16][16],
  int v2192,
  int v2193,
  int v2194
) {	// L2601
  #pragma HLS inline
  #pragma HLS resource variable=v2190 core=ram_t2p_bram

  for (int v2195 = 0; v2195 < 8; v2195 += 1) {	// L2602
    for (int v2196 = 0; v2196 < 8; v2196 += 1) {	// L2603
      for (int v2197 = 0; v2197 < 8; v2197 += 1) {	// L2604
        #pragma HLS pipeline II=1
        float v2198 = v2190[v2195][v2196][v2197];	// L2605
        v2191[(v2195 + (v2192 * 8))][(v2196 + (v2193 * 8))][(v2197 + (v2194 * 8))] = v2198;	// L2606
      }
    }
  }
}

void forward_node155(
  float v2199[8][8][8],
  float v2200[128],
  float v2201[128],
  float v2202[128],
  float v2203[128],
  float v2204[8][8][8],
  int v2205
) {	// L2612
  #pragma HLS inline
  #pragma HLS resource variable=v2199 core=ram_t2p_bram

  #pragma HLS resource variable=v2200 core=ram_t2p_bram

  #pragma HLS resource variable=v2201 core=ram_t2p_bram

  #pragma HLS resource variable=v2202 core=ram_t2p_bram

  #pragma HLS resource variable=v2203 core=ram_t2p_bram

  #pragma HLS resource variable=v2204 core=ram_t2p_bram

  for (int v2206 = 0; v2206 < 8; v2206 += 1) {	// L2615
    for (int v2207 = 0; v2207 < 8; v2207 += 1) {	// L2616
      for (int v2208 = 0; v2208 < 8; v2208 += 1) {	// L2617
        #pragma HLS pipeline II=1
        float v2209 = v2199[v2206][v2207][v2208];	// L2618
        float v2210 = v2201[(v2206 + (v2205 * 8))];	// L2619
        float v2211 = v2202[(v2206 + (v2205 * 8))];	// L2620
        float v2212 = v2200[(v2206 + (v2205 * 8))];	// L2621
        float v2213 = v2203[(v2206 + (v2205 * 8))];	// L2622
        float v2214 = (double)0.000010;	// L2623
        float v2215 = v2213 + v2214;	// L2624
        float v2216 = 1.0 / sqrt(v2215);	// L2625
        float v2217 = v2209 - v2212;	// L2626
        float v2218 = v2217 * v2216;	// L2627
        float v2219 = v2218 * v2210;	// L2628
        float v2220 = v2219 + v2211;	// L2629
        bool v2221 = v2220 > (float)0.000000;	// L2630
        float v2222 = v2221 ? v2220 : (float)0.000000;	// L2631
        v2204[v2206][v2207][v2208] = v2222;	// L2632
      }
    }
  }
}

void forward_node156(
  float v2223[128][16][16],
  float v2224[8][8][8],
  int v2225,
  int v2226,
  int v2227
) {	// L2638
  #pragma HLS inline
  #pragma HLS resource variable=v2224 core=ram_t2p_bram

  for (int v2228 = 0; v2228 < 8; v2228 += 1) {	// L2639
    for (int v2229 = 0; v2229 < 8; v2229 += 1) {	// L2640
      for (int v2230 = 0; v2230 < 8; v2230 += 1) {	// L2641
        #pragma HLS pipeline II=1
        float v2231 = v2223[(v2228 + (v2225 * 8))][(v2229 + (v2226 * 8))][(v2230 + (v2227 * 8))];	// L2642
        v2224[v2228][v2229][v2230] = v2231;	// L2643
      }
    }
  }
}

void forward_node153(
  float v2232[128],
  float v2233[128],
  float v2234[128],
  float v2235[128][16][16],
  float v2236[128],
  float v2237[128][16][16]
) {	// L2649
  #pragma HLS resource variable=v2232 core=ram_t2p_bram

  #pragma HLS resource variable=v2233 core=ram_t2p_bram

  #pragma HLS resource variable=v2234 core=ram_t2p_bram

  #pragma HLS resource variable=v2236 core=ram_t2p_bram

  for (int v2238 = 0; v2238 < 64; v2238 += 1) {	// L2650
    #pragma HLS dataflow
    int v2239 = (v2238 % 2);	// L2651
    int v2240 = ((v2238 / 2) % 2);	// L2652
    int v2241 = ((v2238 / 2) / 2);	// L2653
    float v2242[8][8][8];	// L2654
    #pragma HLS resource variable=v2242 core=ram_t2p_bram

    float v2243[8][8][8];	// L2655
    #pragma HLS resource variable=v2243 core=ram_t2p_bram

    forward_node156(v2235, v2243, v2241, v2240, v2239);	// L2656
    forward_node155(v2243, v2232, v2236, v2233, v2234, v2242, v2241);	// L2657
    forward_node154(v2242, v2237, v2241, v2240, v2239);	// L2658
  }
}

void forward_node158(
  float v2244[8][8][8],
  float v2245[128][16][16],
  int v2246,
  int v2247,
  int v2248
) {	// L2662
  #pragma HLS inline
  #pragma HLS resource variable=v2244 core=ram_t2p_bram

  for (int v2249 = 0; v2249 < 8; v2249 += 1) {	// L2663
    for (int v2250 = 0; v2250 < 8; v2250 += 1) {	// L2664
      for (int v2251 = 0; v2251 < 8; v2251 += 1) {	// L2665
        #pragma HLS pipeline II=1
        float v2252 = v2244[v2249][v2250][v2251];	// L2666
        v2245[(v2249 + (v2246 * 8))][(v2250 + (v2247 * 8))][(v2251 + (v2248 * 8))] = v2252;	// L2667
      }
    }
  }
}

void forward_node159(
  float v2253[8][8][8],
  float v2254[8][8][8],
  float v2255[8][8],
  float v2256[8][8][8],
  float v2257[8][8][8],
  int v2258,
  int v2259,
  int v2260
) {	// L2673
  #pragma HLS inline
  #pragma HLS resource variable=v2253 core=ram_t2p_bram

  #pragma HLS resource variable=v2254 core=ram_t2p_bram

  #pragma HLS resource variable=v2255 core=ram_t2p_bram

  #pragma HLS resource variable=v2256 core=ram_t2p_bram

  #pragma HLS resource variable=v2257 core=ram_t2p_bram

  for (int v2261 = 0; v2261 < 8; v2261 += 1) {	// L2674
    for (int v2262 = 0; v2262 < 8; v2262 += 1) {	// L2675
      for (int v2263 = 0; v2263 < 8; v2263 += 1) {	// L2676
        for (int v2264 = 0; v2264 < 8; v2264 += 1) {	// L2677
          #pragma HLS pipeline II=1
          float v2265 = v2254[v2262][v2263][v2264];	// L2678
          float v2266 = v2256[v2262][v2263][v2264];	// L2679
          float v2267 = v2257[v2262][v2263][v2264];	// L2680
          float v2268 = (v2261 == 0) ? v2266 : v2267;	// L2681
          float v2269 = ((v2261 + (v2258 * 8)) == 0 && v2259 == 0 && v2260 == 0) ? v2265 : v2268;	// L2682
          float v2270 = v2253[v2261][v2263][v2264];	// L2683
          float v2271 = v2255[v2262][v2261];	// L2684
          float v2272 = v2270 * v2271;	// L2685
          float v2273 = v2269 + v2272;	// L2686
          v2257[v2262][v2263][v2264] = v2273;	// L2687
        }
      }
    }
  }
}

void forward_node160(
  float v2274[128][64][3][3],
  float v2275[8][8],
  int v2276,
  int v2277,
  int v2278,
  int v2279
) {	// L2694
  #pragma HLS inline
  #pragma HLS resource variable=v2275 core=ram_t2p_bram

  for (int v2280 = 0; v2280 < 8; v2280 += 1) {	// L2695
    for (int v2281 = 0; v2281 < 8; v2281 += 1) {	// L2696
      #pragma HLS pipeline II=1
      float v2282 = v2274[(v2280 + (v2278 * 8))][(v2281 + (v2279 * 8))][v2276][v2277];	// L2697
      v2275[v2280][v2281] = v2282;	// L2698
    }
  }
}

void forward_node161(
  float v2283[64][32][32],
  float v2284[8][8][8],
  int v2285,
  int v2286,
  int v2287,
  int v2288,
  int v2289
) {	// L2703
  #pragma HLS inline
  #pragma HLS resource variable=v2284 core=ram_t2p_bram

  for (int v2290 = 0; v2290 < 8; v2290 += 1) {	// L2704
    for (int v2291 = 0; v2291 < 8; v2291 += 1) {	// L2705
      for (int v2292 = 0; v2292 < 8; v2292 += 1) {	// L2706
        #pragma HLS pipeline II=1
        float v2293 = v2283[(v2290 + (v2285 * 8))][((((v2291 * 2) + v2286) + (v2287 * 16)) - 1)][((((v2292 * 2) + v2288) + (v2289 * 16)) - 1)];	// L2707
        v2284[v2290][v2291][v2292] = v2293;	// L2708
      }
    }
  }
}

void forward_node162(
  float v2294[128][16][16],
  float v2295[8][8][8],
  int v2296,
  int v2297,
  int v2298
) {	// L2714
  #pragma HLS inline
  #pragma HLS resource variable=v2295 core=ram_t2p_bram

  for (int v2299 = 0; v2299 < 8; v2299 += 1) {	// L2715
    for (int v2300 = 0; v2300 < 8; v2300 += 1) {	// L2716
      for (int v2301 = 0; v2301 < 8; v2301 += 1) {	// L2717
        #pragma HLS pipeline II=1
        float v2302 = v2294[(v2299 + (v2296 * 8))][(v2300 + (v2297 * 8))][(v2301 + (v2298 * 8))];	// L2718
        v2295[v2299][v2300][v2301] = v2302;	// L2719
      }
    }
  }
}

void forward_node163(
  float v2303[128][16][16],
  float v2304[8][8][8],
  int v2305,
  int v2306,
  int v2307
) {	// L2725
  #pragma HLS inline
  #pragma HLS resource variable=v2304 core=ram_t2p_bram

  for (int v2308 = 0; v2308 < 8; v2308 += 1) {	// L2726
    for (int v2309 = 0; v2309 < 8; v2309 += 1) {	// L2727
      for (int v2310 = 0; v2310 < 8; v2310 += 1) {	// L2728
        #pragma HLS pipeline II=1
        float v2311 = v2303[(v2308 + (v2305 * 8))][(v2309 + (v2306 * 8))][(v2310 + (v2307 * 8))];	// L2729
        v2304[v2308][v2309][v2310] = v2311;	// L2730
      }
    }
  }
}

void forward_node157(
  float v2312[64][32][32],
  float v2313[128][16][16],
  float v2314[128][64][3][3],
  float v2315[128][16][16],
  float v2316[128][16][16]
) {	// L2736
  for (int v2317 = 0; v2317 < 4608; v2317 += 1) {	// L2737
    #pragma HLS dataflow
    int v2318 = (v2317 % 2);	// L2738
    int v2319 = ((v2317 / 2) % 2);	// L2739
    int v2320 = (((v2317 / 2) / 2) % 16);	// L2740
    int v2321 = ((((v2317 / 2) / 2) / 16) % 3);	// L2741
    int v2322 = (((((v2317 / 2) / 2) / 16) / 3) % 3);	// L2742
    int v2323 = (((((v2317 / 2) / 2) / 16) / 3) / 3);	// L2743
    float v2324[8][8];	// L2744
    #pragma HLS resource variable=v2324 core=ram_t2p_bram

    float v2325[8][8][8];	// L2745
    #pragma HLS resource variable=v2325 core=ram_t2p_bram

    float v2326[8][8][8];	// L2746
    #pragma HLS resource variable=v2326 core=ram_t2p_bram

    float v2327[8][8][8];	// L2747
    #pragma HLS resource variable=v2327 core=ram_t2p_bram

    forward_node163(v2313, v2327, v2320, v2319, v2318);	// L2748
    forward_node162(v2315, v2326, v2320, v2319, v2318);	// L2749
    forward_node161(v2312, v2325, v2323, v2322, v2319, v2321, v2318);	// L2750
    forward_node160(v2314, v2324, v2322, v2321, v2320, v2323);	// L2751
    float v2328[8][8][8];	// L2752
    #pragma HLS resource variable=v2328 core=ram_t2p_bram

    forward_node159(v2325, v2327, v2324, v2326, v2328, v2323, v2322, v2321);	// L2753
    forward_node158(v2328, v2316, v2320, v2319, v2318);	// L2754
  }
}

void forward_node165(
  float v2329[8][8][8],
  float v2330[64][32][32],
  int v2331,
  int v2332,
  int v2333
) {	// L2758
  #pragma HLS inline
  #pragma HLS resource variable=v2329 core=ram_t2p_bram

  for (int v2334 = 0; v2334 < 8; v2334 += 1) {	// L2759
    for (int v2335 = 0; v2335 < 8; v2335 += 1) {	// L2760
      for (int v2336 = 0; v2336 < 8; v2336 += 1) {	// L2761
        #pragma HLS pipeline II=1
        float v2337 = v2329[v2334][v2335][v2336];	// L2762
        v2330[(v2334 + (v2331 * 8))][(v2335 + (v2332 * 8))][(v2336 + (v2333 * 8))] = v2337;	// L2763
      }
    }
  }
}

void forward_node166(
  float v2338[8][8][8],
  float v2339[64],
  float v2340[64],
  float v2341[64],
  float v2342[64],
  float v2343[8][8][8],
  float v2344[8][8][8],
  int v2345
) {	// L2769
  #pragma HLS inline
  #pragma HLS resource variable=v2338 core=ram_t2p_bram

  #pragma HLS resource variable=v2339 core=ram_t2p_bram

  #pragma HLS resource variable=v2340 core=ram_t2p_bram

  #pragma HLS resource variable=v2341 core=ram_t2p_bram

  #pragma HLS resource variable=v2342 core=ram_t2p_bram

  #pragma HLS resource variable=v2343 core=ram_t2p_bram

  #pragma HLS resource variable=v2344 core=ram_t2p_bram

  for (int v2346 = 0; v2346 < 8; v2346 += 1) {	// L2772
    for (int v2347 = 0; v2347 < 8; v2347 += 1) {	// L2773
      for (int v2348 = 0; v2348 < 8; v2348 += 1) {	// L2774
        #pragma HLS pipeline II=1
        float v2349 = v2343[v2346][v2347][v2348];	// L2775
        float v2350 = v2340[(v2346 + (v2345 * 8))];	// L2776
        float v2351 = v2341[(v2346 + (v2345 * 8))];	// L2777
        float v2352 = v2339[(v2346 + (v2345 * 8))];	// L2778
        float v2353 = v2342[(v2346 + (v2345 * 8))];	// L2779
        float v2354 = v2338[v2346][v2347][v2348];	// L2780
        float v2355 = (double)0.000010;	// L2781
        float v2356 = v2353 + v2355;	// L2782
        float v2357 = 1.0 / sqrt(v2356);	// L2783
        float v2358 = v2349 - v2352;	// L2784
        float v2359 = v2358 * v2357;	// L2785
        float v2360 = v2359 * v2350;	// L2786
        float v2361 = v2360 + v2351;	// L2787
        float v2362 = v2361 + v2354;	// L2788
        bool v2363 = v2362 > (float)0.000000;	// L2789
        float v2364 = v2363 ? v2362 : (float)0.000000;	// L2790
        v2344[v2346][v2347][v2348] = v2364;	// L2791
      }
    }
  }
}

void forward_node167(
  float v2365[64][32][32],
  float v2366[8][8][8],
  int v2367,
  int v2368,
  int v2369
) {	// L2797
  #pragma HLS inline
  #pragma HLS resource variable=v2366 core=ram_t2p_bram

  for (int v2370 = 0; v2370 < 8; v2370 += 1) {	// L2798
    for (int v2371 = 0; v2371 < 8; v2371 += 1) {	// L2799
      for (int v2372 = 0; v2372 < 8; v2372 += 1) {	// L2800
        #pragma HLS pipeline II=1
        float v2373 = v2365[(v2370 + (v2367 * 8))][(v2371 + (v2368 * 8))][(v2372 + (v2369 * 8))];	// L2801
        v2366[v2370][v2371][v2372] = v2373;	// L2802
      }
    }
  }
}

void forward_node168(
  float v2374[64][32][32],
  float v2375[8][8][8],
  int v2376,
  int v2377,
  int v2378
) {	// L2808
  #pragma HLS inline
  #pragma HLS resource variable=v2375 core=ram_t2p_bram

  for (int v2379 = 0; v2379 < 8; v2379 += 1) {	// L2809
    for (int v2380 = 0; v2380 < 8; v2380 += 1) {	// L2810
      for (int v2381 = 0; v2381 < 8; v2381 += 1) {	// L2811
        #pragma HLS pipeline II=1
        float v2382 = v2374[(v2379 + (v2376 * 8))][(v2380 + (v2377 * 8))][(v2381 + (v2378 * 8))];	// L2812
        v2375[v2379][v2380][v2381] = v2382;	// L2813
      }
    }
  }
}

void forward_node164(
  float v2383[64][32][32],
  float v2384[64],
  float v2385[64],
  float v2386[64],
  float v2387[64],
  float v2388[64][32][32],
  float v2389[64][32][32]
) {	// L2819
  #pragma HLS resource variable=v2384 core=ram_t2p_bram

  #pragma HLS resource variable=v2385 core=ram_t2p_bram

  #pragma HLS resource variable=v2386 core=ram_t2p_bram

  #pragma HLS resource variable=v2387 core=ram_t2p_bram

  for (int v2390 = 0; v2390 < 128; v2390 += 1) {	// L2820
    #pragma HLS dataflow
    int v2391 = (v2390 % 4);	// L2821
    int v2392 = ((v2390 / 4) % 4);	// L2822
    int v2393 = ((v2390 / 4) / 4);	// L2823
    float v2394[8][8][8];	// L2824
    #pragma HLS resource variable=v2394 core=ram_t2p_bram

    float v2395[8][8][8];	// L2825
    #pragma HLS resource variable=v2395 core=ram_t2p_bram

    float v2396[8][8][8];	// L2826
    #pragma HLS resource variable=v2396 core=ram_t2p_bram

    forward_node168(v2388, v2396, v2393, v2392, v2391);	// L2827
    forward_node167(v2383, v2395, v2393, v2392, v2391);	// L2828
    forward_node166(v2395, v2384, v2385, v2386, v2387, v2396, v2394, v2393);	// L2829
    forward_node165(v2394, v2389, v2393, v2392, v2391);	// L2830
  }
}

void forward_node170(
  float v2397[8][8][8],
  float v2398[64][32][32],
  int v2399,
  int v2400,
  int v2401
) {	// L2834
  #pragma HLS inline
  #pragma HLS array_partition variable=v2397 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2397 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2397 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2398 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2398 cyclic factor=2 dim=3

  for (int v2402 = 0; v2402 < 8; v2402 += 1) {	// L2835
    for (int v2403 = 0; v2403 < 8; v2403 += 2) {	// L2836
      for (int v2404 = 0; v2404 < 8; v2404 += 2) {	// L2837
        #pragma HLS pipeline II=1
        float v2405 = v2397[v2402][v2403][v2404];	// L2838
        v2398[(v2402 + (v2399 * 8))][(v2403 + (v2400 * 8))][(v2404 + (v2401 * 8))] = v2405;	// L2839
        float v2406 = v2397[v2402][v2403][(v2404 + 1)];	// L2840
        v2398[(v2402 + (v2399 * 8))][(v2403 + (v2400 * 8))][((v2404 + (v2401 * 8)) + 1)] = v2406;	// L2841
        float v2407 = v2397[v2402][(v2403 + 1)][v2404];	// L2842
        v2398[(v2402 + (v2399 * 8))][((v2403 + (v2400 * 8)) + 1)][(v2404 + (v2401 * 8))] = v2407;	// L2843
        float v2408 = v2397[v2402][(v2403 + 1)][(v2404 + 1)];	// L2844
        v2398[(v2402 + (v2399 * 8))][((v2403 + (v2400 * 8)) + 1)][((v2404 + (v2401 * 8)) + 1)] = v2408;	// L2845
      }
    }
  }
}

void forward_node171(
  float v2409[8][8][8],
  float v2410[8][8],
  float v2411[8][8][8],
  float v2412[8][8][8]
) {	// L2851
  #pragma HLS inline
  #pragma HLS array_partition variable=v2409 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2409 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2409 core=ram_t2p_bram

  #pragma HLS resource variable=v2410 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2411 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2411 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2411 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2412 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2412 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2412 core=ram_t2p_bram

  for (int v2413 = 0; v2413 < 8; v2413 += 1) {	// L2852
    for (int v2414 = 0; v2414 < 8; v2414 += 1) {	// L2853
      for (int v2415 = 0; v2415 < 8; v2415 += 2) {	// L2854
        for (int v2416 = 0; v2416 < 8; v2416 += 2) {	// L2855
          #pragma HLS pipeline II=1
          float v2417 = v2409[v2413][v2415][v2416];	// L2856
          float v2418 = v2410[v2414][v2413];	// L2857
          float v2419 = v2411[v2414][v2415][v2416];	// L2858
          float v2420 = v2412[v2414][v2415][v2416];	// L2859
          float v2421 = (v2413 == 0) ? v2419 : v2420;	// L2860
          float v2422 = v2417 * v2418;	// L2861
          float v2423 = v2421 + v2422;	// L2862
          v2412[v2414][v2415][v2416] = v2423;	// L2863
          float v2424 = v2409[v2413][v2415][(v2416 + 1)];	// L2864
          float v2425 = v2411[v2414][v2415][(v2416 + 1)];	// L2865
          float v2426 = v2412[v2414][v2415][(v2416 + 1)];	// L2866
          float v2427 = (v2413 == 0) ? v2425 : v2426;	// L2867
          float v2428 = v2424 * v2418;	// L2868
          float v2429 = v2427 + v2428;	// L2869
          v2412[v2414][v2415][(v2416 + 1)] = v2429;	// L2870
          float v2430 = v2409[v2413][(v2415 + 1)][v2416];	// L2871
          float v2431 = v2411[v2414][(v2415 + 1)][v2416];	// L2872
          float v2432 = v2412[v2414][(v2415 + 1)][v2416];	// L2873
          float v2433 = (v2413 == 0) ? v2431 : v2432;	// L2874
          float v2434 = v2430 * v2418;	// L2875
          float v2435 = v2433 + v2434;	// L2876
          v2412[v2414][(v2415 + 1)][v2416] = v2435;	// L2877
          float v2436 = v2409[v2413][(v2415 + 1)][(v2416 + 1)];	// L2878
          float v2437 = v2411[v2414][(v2415 + 1)][(v2416 + 1)];	// L2879
          float v2438 = v2412[v2414][(v2415 + 1)][(v2416 + 1)];	// L2880
          float v2439 = (v2413 == 0) ? v2437 : v2438;	// L2881
          float v2440 = v2436 * v2418;	// L2882
          float v2441 = v2439 + v2440;	// L2883
          v2412[v2414][(v2415 + 1)][(v2416 + 1)] = v2441;	// L2884
        }
      }
    }
  }
}

void forward_node172(
  float v2442[64][32][32],
  float v2443[8][8][8],
  int v2444,
  int v2445,
  int v2446
) {	// L2891
  #pragma HLS inline
  #pragma HLS array_partition variable=v2442 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2442 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2443 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2443 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2443 core=ram_t2p_bram

  for (int v2447 = 0; v2447 < 8; v2447 += 1) {	// L2892
    for (int v2448 = 0; v2448 < 8; v2448 += 2) {	// L2893
      for (int v2449 = 0; v2449 < 8; v2449 += 2) {	// L2894
        #pragma HLS pipeline II=1
        float v2450 = v2442[(v2447 + (v2444 * 8))][(v2448 + (v2445 * 8))][(v2449 + (v2446 * 8))];	// L2895
        v2443[v2447][v2448][v2449] = v2450;	// L2896
        float v2451 = v2442[(v2447 + (v2444 * 8))][(v2448 + (v2445 * 8))][((v2449 + (v2446 * 8)) + 1)];	// L2897
        v2443[v2447][v2448][(v2449 + 1)] = v2451;	// L2898
        float v2452 = v2442[(v2447 + (v2444 * 8))][((v2448 + (v2445 * 8)) + 1)][(v2449 + (v2446 * 8))];	// L2899
        v2443[v2447][(v2448 + 1)][v2449] = v2452;	// L2900
        float v2453 = v2442[(v2447 + (v2444 * 8))][((v2448 + (v2445 * 8)) + 1)][((v2449 + (v2446 * 8)) + 1)];	// L2901
        v2443[v2447][(v2448 + 1)][(v2449 + 1)] = v2453;	// L2902
      }
    }
  }
}

void forward_node173(
  float v2454[64][64][3][3],
  float v2455[8][8],
  int v2456,
  int v2457,
  int v2458,
  int v2459
) {	// L2908
  #pragma HLS inline
  #pragma HLS resource variable=v2455 core=ram_t2p_bram

  for (int v2460 = 0; v2460 < 8; v2460 += 1) {	// L2909
    for (int v2461 = 0; v2461 < 8; v2461 += 1) {	// L2910
      #pragma HLS pipeline II=1
      float v2462 = v2454[(v2460 + (v2458 * 8))][(v2461 + (v2459 * 8))][v2456][v2457];	// L2911
      v2455[v2460][v2461] = v2462;	// L2912
    }
  }
}

void forward_node174(
  float v2463[64][32][32],
  float v2464[8][8][8],
  int v2465,
  int v2466,
  int v2467,
  int v2468,
  int v2469
) {	// L2917
  #pragma HLS inline
  #pragma HLS array_partition variable=v2463 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2463 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2464 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2464 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2464 core=ram_t2p_bram

  for (int v2470 = 0; v2470 < 8; v2470 += 1) {	// L2918
    for (int v2471 = 0; v2471 < 8; v2471 += 2) {	// L2919
      for (int v2472 = 0; v2472 < 8; v2472 += 2) {	// L2920
        #pragma HLS pipeline II=1
        float v2473 = v2463[(v2470 + (v2465 * 8))][(((v2471 + v2466) + (v2467 * 8)) - 1)][(((v2472 + v2468) + (v2469 * 8)) - 1)];	// L2921
        v2464[v2470][v2471][v2472] = v2473;	// L2922
        float v2474 = v2463[(v2470 + (v2465 * 8))][(((v2471 + v2466) + (v2467 * 8)) - 1)][((v2472 + v2468) + (v2469 * 8))];	// L2923
        v2464[v2470][v2471][(v2472 + 1)] = v2474;	// L2924
        float v2475 = v2463[(v2470 + (v2465 * 8))][((v2471 + v2466) + (v2467 * 8))][(((v2472 + v2468) + (v2469 * 8)) - 1)];	// L2925
        v2464[v2470][(v2471 + 1)][v2472] = v2475;	// L2926
        float v2476 = v2463[(v2470 + (v2465 * 8))][((v2471 + v2466) + (v2467 * 8))][((v2472 + v2468) + (v2469 * 8))];	// L2927
        v2464[v2470][(v2471 + 1)][(v2472 + 1)] = v2476;	// L2928
      }
    }
  }
}

void forward_node169(
  float v2477[64][32][32],
  float v2478[64][64][3][3],
  float v2479[64][32][32],
  float v2480[64][32][32]
) {	// L2934
  #pragma HLS array_partition variable=v2477 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2477 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2479 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2479 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2480 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2480 cyclic factor=2 dim=3

  for (int v2481 = 0; v2481 < 9216; v2481 += 1) {	// L2935
    #pragma HLS dataflow
    int v2482 = (v2481 % 4);	// L2936
    int v2483 = ((v2481 / 4) % 4);	// L2937
    int v2484 = (((v2481 / 4) / 4) % 8);	// L2938
    int v2485 = ((((v2481 / 4) / 4) / 8) % 3);	// L2939
    int v2486 = (((((v2481 / 4) / 4) / 8) / 3) % 3);	// L2940
    int v2487 = (((((v2481 / 4) / 4) / 8) / 3) / 3);	// L2941
    float v2488[8][8][8];	// L2942
    #pragma HLS array_partition variable=v2488 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2488 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2488 core=ram_t2p_bram

    float v2489[8][8];	// L2943
    #pragma HLS resource variable=v2489 core=ram_t2p_bram

    float v2490[8][8][8];	// L2944
    #pragma HLS array_partition variable=v2490 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2490 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2490 core=ram_t2p_bram

    forward_node174(v2477, v2490, v2487, v2486, v2483, v2485, v2482);	// L2945
    forward_node173(v2478, v2489, v2486, v2485, v2484, v2487);	// L2946
    forward_node172(v2479, v2488, v2484, v2483, v2482);	// L2947
    float v2491[8][8][8];	// L2948
    #pragma HLS array_partition variable=v2491 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2491 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2491 core=ram_t2p_bram

    forward_node171(v2490, v2489, v2488, v2491);	// L2949
    forward_node170(v2491, v2480, v2484, v2483, v2482);	// L2950
  }
}

void forward_node176(
  float v2492[8][8][8],
  float v2493[64][32][32],
  int v2494,
  int v2495,
  int v2496
) {	// L2954
  #pragma HLS inline
  #pragma HLS resource variable=v2492 core=ram_t2p_bram

  for (int v2497 = 0; v2497 < 8; v2497 += 1) {	// L2955
    for (int v2498 = 0; v2498 < 8; v2498 += 1) {	// L2956
      for (int v2499 = 0; v2499 < 8; v2499 += 1) {	// L2957
        #pragma HLS pipeline II=1
        float v2500 = v2492[v2497][v2498][v2499];	// L2958
        v2493[(v2497 + (v2494 * 8))][(v2498 + (v2495 * 8))][(v2499 + (v2496 * 8))] = v2500;	// L2959
      }
    }
  }
}

void forward_node177(
  float v2501[8][8][8],
  float v2502[64],
  float v2503[64],
  float v2504[64],
  float v2505[64],
  float v2506[8][8][8],
  int v2507
) {	// L2965
  #pragma HLS inline
  #pragma HLS resource variable=v2501 core=ram_t2p_bram

  #pragma HLS resource variable=v2502 core=ram_t2p_bram

  #pragma HLS resource variable=v2503 core=ram_t2p_bram

  #pragma HLS resource variable=v2504 core=ram_t2p_bram

  #pragma HLS resource variable=v2505 core=ram_t2p_bram

  #pragma HLS resource variable=v2506 core=ram_t2p_bram

  for (int v2508 = 0; v2508 < 8; v2508 += 1) {	// L2968
    for (int v2509 = 0; v2509 < 8; v2509 += 1) {	// L2969
      for (int v2510 = 0; v2510 < 8; v2510 += 1) {	// L2970
        #pragma HLS pipeline II=1
        float v2511 = v2501[v2508][v2509][v2510];	// L2971
        float v2512 = v2502[(v2508 + (v2507 * 8))];	// L2972
        float v2513 = v2503[(v2508 + (v2507 * 8))];	// L2973
        float v2514 = v2505[(v2508 + (v2507 * 8))];	// L2974
        float v2515 = v2504[(v2508 + (v2507 * 8))];	// L2975
        float v2516 = (double)0.000010;	// L2976
        float v2517 = v2515 + v2516;	// L2977
        float v2518 = 1.0 / sqrt(v2517);	// L2978
        float v2519 = v2511 - v2514;	// L2979
        float v2520 = v2519 * v2518;	// L2980
        float v2521 = v2520 * v2512;	// L2981
        float v2522 = v2521 + v2513;	// L2982
        bool v2523 = v2522 > (float)0.000000;	// L2983
        float v2524 = v2523 ? v2522 : (float)0.000000;	// L2984
        v2506[v2508][v2509][v2510] = v2524;	// L2985
      }
    }
  }
}

void forward_node178(
  float v2525[64][32][32],
  float v2526[8][8][8],
  int v2527,
  int v2528,
  int v2529
) {	// L2991
  #pragma HLS inline
  #pragma HLS resource variable=v2526 core=ram_t2p_bram

  for (int v2530 = 0; v2530 < 8; v2530 += 1) {	// L2992
    for (int v2531 = 0; v2531 < 8; v2531 += 1) {	// L2993
      for (int v2532 = 0; v2532 < 8; v2532 += 1) {	// L2994
        #pragma HLS pipeline II=1
        float v2533 = v2525[(v2530 + (v2527 * 8))][(v2531 + (v2528 * 8))][(v2532 + (v2529 * 8))];	// L2995
        v2526[v2530][v2531][v2532] = v2533;	// L2996
      }
    }
  }
}

void forward_node175(
  float v2534[64],
  float v2535[64],
  float v2536[64][32][32],
  float v2537[64],
  float v2538[64],
  float v2539[64][32][32]
) {	// L3002
  #pragma HLS resource variable=v2534 core=ram_t2p_bram

  #pragma HLS resource variable=v2535 core=ram_t2p_bram

  #pragma HLS resource variable=v2537 core=ram_t2p_bram

  #pragma HLS resource variable=v2538 core=ram_t2p_bram

  for (int v2540 = 0; v2540 < 128; v2540 += 1) {	// L3003
    #pragma HLS dataflow
    int v2541 = (v2540 % 4);	// L3004
    int v2542 = ((v2540 / 4) % 4);	// L3005
    int v2543 = ((v2540 / 4) / 4);	// L3006
    float v2544[8][8][8];	// L3007
    #pragma HLS resource variable=v2544 core=ram_t2p_bram

    float v2545[8][8][8];	// L3008
    #pragma HLS resource variable=v2545 core=ram_t2p_bram

    forward_node178(v2536, v2545, v2543, v2542, v2541);	// L3009
    forward_node177(v2545, v2535, v2534, v2538, v2537, v2544, v2543);	// L3010
    forward_node176(v2544, v2539, v2543, v2542, v2541);	// L3011
  }
}

void forward_node180(
  float v2546[8][8][8],
  float v2547[64][32][32],
  int v2548,
  int v2549,
  int v2550
) {	// L3015
  #pragma HLS inline
  #pragma HLS array_partition variable=v2546 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2546 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2546 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2547 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2547 cyclic factor=2 dim=3

  for (int v2551 = 0; v2551 < 8; v2551 += 1) {	// L3016
    for (int v2552 = 0; v2552 < 8; v2552 += 2) {	// L3017
      for (int v2553 = 0; v2553 < 8; v2553 += 2) {	// L3018
        #pragma HLS pipeline II=1
        float v2554 = v2546[v2551][v2552][v2553];	// L3019
        v2547[(v2551 + (v2548 * 8))][(v2552 + (v2549 * 8))][(v2553 + (v2550 * 8))] = v2554;	// L3020
        float v2555 = v2546[v2551][v2552][(v2553 + 1)];	// L3021
        v2547[(v2551 + (v2548 * 8))][(v2552 + (v2549 * 8))][((v2553 + (v2550 * 8)) + 1)] = v2555;	// L3022
        float v2556 = v2546[v2551][(v2552 + 1)][v2553];	// L3023
        v2547[(v2551 + (v2548 * 8))][((v2552 + (v2549 * 8)) + 1)][(v2553 + (v2550 * 8))] = v2556;	// L3024
        float v2557 = v2546[v2551][(v2552 + 1)][(v2553 + 1)];	// L3025
        v2547[(v2551 + (v2548 * 8))][((v2552 + (v2549 * 8)) + 1)][((v2553 + (v2550 * 8)) + 1)] = v2557;	// L3026
      }
    }
  }
}

void forward_node181(
  float v2558[8][8],
  float v2559[8][8][8],
  float v2560[8][8][8],
  float v2561[8][8][8],
  float v2562[8][8][8],
  int v2563,
  int v2564,
  int v2565
) {	// L3032
  #pragma HLS inline
  #pragma HLS resource variable=v2558 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2559 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2559 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2559 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2560 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2560 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2560 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2561 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2561 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2561 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2562 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2562 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2562 core=ram_t2p_bram

  for (int v2566 = 0; v2566 < 8; v2566 += 1) {	// L3033
    for (int v2567 = 0; v2567 < 8; v2567 += 1) {	// L3034
      for (int v2568 = 0; v2568 < 8; v2568 += 2) {	// L3035
        for (int v2569 = 0; v2569 < 8; v2569 += 2) {	// L3036
          #pragma HLS pipeline II=1
          float v2570 = v2560[v2567][v2568][v2569];	// L3037
          float v2571 = v2561[v2567][v2568][v2569];	// L3038
          float v2572 = v2562[v2567][v2568][v2569];	// L3039
          float v2573 = (v2566 == 0) ? v2571 : v2572;	// L3040
          float v2574 = ((v2566 + (v2564 * 8)) == 0 && v2563 == 0 && v2565 == 0) ? v2570 : v2573;	// L3041
          float v2575 = v2559[v2566][v2568][v2569];	// L3042
          float v2576 = v2558[v2567][v2566];	// L3043
          float v2577 = v2575 * v2576;	// L3044
          float v2578 = v2574 + v2577;	// L3045
          v2562[v2567][v2568][v2569] = v2578;	// L3046
          float v2579 = v2560[v2567][v2568][(v2569 + 1)];	// L3047
          float v2580 = v2561[v2567][v2568][(v2569 + 1)];	// L3048
          float v2581 = v2562[v2567][v2568][(v2569 + 1)];	// L3049
          float v2582 = (v2566 == 0) ? v2580 : v2581;	// L3050
          float v2583 = ((v2566 + (v2564 * 8)) == 0 && v2563 == 0 && v2565 == 0) ? v2579 : v2582;	// L3051
          float v2584 = v2559[v2566][v2568][(v2569 + 1)];	// L3052
          float v2585 = v2584 * v2576;	// L3053
          float v2586 = v2583 + v2585;	// L3054
          v2562[v2567][v2568][(v2569 + 1)] = v2586;	// L3055
          float v2587 = v2560[v2567][(v2568 + 1)][v2569];	// L3056
          float v2588 = v2561[v2567][(v2568 + 1)][v2569];	// L3057
          float v2589 = v2562[v2567][(v2568 + 1)][v2569];	// L3058
          float v2590 = (v2566 == 0) ? v2588 : v2589;	// L3059
          float v2591 = ((v2566 + (v2564 * 8)) == 0 && v2563 == 0 && v2565 == 0) ? v2587 : v2590;	// L3060
          float v2592 = v2559[v2566][(v2568 + 1)][v2569];	// L3061
          float v2593 = v2592 * v2576;	// L3062
          float v2594 = v2591 + v2593;	// L3063
          v2562[v2567][(v2568 + 1)][v2569] = v2594;	// L3064
          float v2595 = v2560[v2567][(v2568 + 1)][(v2569 + 1)];	// L3065
          float v2596 = v2561[v2567][(v2568 + 1)][(v2569 + 1)];	// L3066
          float v2597 = v2562[v2567][(v2568 + 1)][(v2569 + 1)];	// L3067
          float v2598 = (v2566 == 0) ? v2596 : v2597;	// L3068
          float v2599 = ((v2566 + (v2564 * 8)) == 0 && v2563 == 0 && v2565 == 0) ? v2595 : v2598;	// L3069
          float v2600 = v2559[v2566][(v2568 + 1)][(v2569 + 1)];	// L3070
          float v2601 = v2600 * v2576;	// L3071
          float v2602 = v2599 + v2601;	// L3072
          v2562[v2567][(v2568 + 1)][(v2569 + 1)] = v2602;	// L3073
        }
      }
    }
  }
}

void forward_node182(
  float v2603[64][64][3][3],
  float v2604[8][8],
  int v2605,
  int v2606,
  int v2607,
  int v2608
) {	// L3080
  #pragma HLS inline
  #pragma HLS resource variable=v2604 core=ram_t2p_bram

  for (int v2609 = 0; v2609 < 8; v2609 += 1) {	// L3081
    for (int v2610 = 0; v2610 < 8; v2610 += 1) {	// L3082
      #pragma HLS pipeline II=1
      float v2611 = v2603[(v2609 + (v2607 * 8))][(v2610 + (v2608 * 8))][v2605][v2606];	// L3083
      v2604[v2609][v2610] = v2611;	// L3084
    }
  }
}

void forward_node183(
  float v2612[64][32][32],
  float v2613[8][8][8],
  int v2614,
  int v2615,
  int v2616,
  int v2617,
  int v2618
) {	// L3089
  #pragma HLS inline
  #pragma HLS array_partition variable=v2612 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2612 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2613 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2613 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2613 core=ram_t2p_bram

  for (int v2619 = 0; v2619 < 8; v2619 += 1) {	// L3090
    for (int v2620 = 0; v2620 < 8; v2620 += 2) {	// L3091
      for (int v2621 = 0; v2621 < 8; v2621 += 2) {	// L3092
        #pragma HLS pipeline II=1
        float v2622 = v2612[(v2619 + (v2614 * 8))][(((v2620 + v2615) + (v2616 * 8)) - 1)][(((v2621 + v2617) + (v2618 * 8)) - 1)];	// L3093
        v2613[v2619][v2620][v2621] = v2622;	// L3094
        float v2623 = v2612[(v2619 + (v2614 * 8))][(((v2620 + v2615) + (v2616 * 8)) - 1)][((v2621 + v2617) + (v2618 * 8))];	// L3095
        v2613[v2619][v2620][(v2621 + 1)] = v2623;	// L3096
        float v2624 = v2612[(v2619 + (v2614 * 8))][((v2620 + v2615) + (v2616 * 8))][(((v2621 + v2617) + (v2618 * 8)) - 1)];	// L3097
        v2613[v2619][(v2620 + 1)][v2621] = v2624;	// L3098
        float v2625 = v2612[(v2619 + (v2614 * 8))][((v2620 + v2615) + (v2616 * 8))][((v2621 + v2617) + (v2618 * 8))];	// L3099
        v2613[v2619][(v2620 + 1)][(v2621 + 1)] = v2625;	// L3100
      }
    }
  }
}

void forward_node184(
  float v2626[64][32][32],
  float v2627[8][8][8],
  int v2628,
  int v2629,
  int v2630
) {	// L3106
  #pragma HLS inline
  #pragma HLS array_partition variable=v2626 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2626 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2627 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2627 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2627 core=ram_t2p_bram

  for (int v2631 = 0; v2631 < 8; v2631 += 1) {	// L3107
    for (int v2632 = 0; v2632 < 8; v2632 += 2) {	// L3108
      for (int v2633 = 0; v2633 < 8; v2633 += 2) {	// L3109
        #pragma HLS pipeline II=1
        float v2634 = v2626[(v2631 + (v2628 * 8))][(v2632 + (v2629 * 8))][(v2633 + (v2630 * 8))];	// L3110
        v2627[v2631][v2632][v2633] = v2634;	// L3111
        float v2635 = v2626[(v2631 + (v2628 * 8))][(v2632 + (v2629 * 8))][((v2633 + (v2630 * 8)) + 1)];	// L3112
        v2627[v2631][v2632][(v2633 + 1)] = v2635;	// L3113
        float v2636 = v2626[(v2631 + (v2628 * 8))][((v2632 + (v2629 * 8)) + 1)][(v2633 + (v2630 * 8))];	// L3114
        v2627[v2631][(v2632 + 1)][v2633] = v2636;	// L3115
        float v2637 = v2626[(v2631 + (v2628 * 8))][((v2632 + (v2629 * 8)) + 1)][((v2633 + (v2630 * 8)) + 1)];	// L3116
        v2627[v2631][(v2632 + 1)][(v2633 + 1)] = v2637;	// L3117
      }
    }
  }
}

void forward_node185(
  float v2638[64][32][32],
  float v2639[8][8][8],
  int v2640,
  int v2641,
  int v2642
) {	// L3123
  #pragma HLS inline
  #pragma HLS array_partition variable=v2638 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2638 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2639 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2639 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2639 core=ram_t2p_bram

  for (int v2643 = 0; v2643 < 8; v2643 += 1) {	// L3124
    for (int v2644 = 0; v2644 < 8; v2644 += 2) {	// L3125
      for (int v2645 = 0; v2645 < 8; v2645 += 2) {	// L3126
        #pragma HLS pipeline II=1
        float v2646 = v2638[(v2643 + (v2640 * 8))][(v2644 + (v2641 * 8))][(v2645 + (v2642 * 8))];	// L3127
        v2639[v2643][v2644][v2645] = v2646;	// L3128
        float v2647 = v2638[(v2643 + (v2640 * 8))][(v2644 + (v2641 * 8))][((v2645 + (v2642 * 8)) + 1)];	// L3129
        v2639[v2643][v2644][(v2645 + 1)] = v2647;	// L3130
        float v2648 = v2638[(v2643 + (v2640 * 8))][((v2644 + (v2641 * 8)) + 1)][(v2645 + (v2642 * 8))];	// L3131
        v2639[v2643][(v2644 + 1)][v2645] = v2648;	// L3132
        float v2649 = v2638[(v2643 + (v2640 * 8))][((v2644 + (v2641 * 8)) + 1)][((v2645 + (v2642 * 8)) + 1)];	// L3133
        v2639[v2643][(v2644 + 1)][(v2645 + 1)] = v2649;	// L3134
      }
    }
  }
}

void forward_node179(
  float v2650[64][32][32],
  float v2651[64][64][3][3],
  float v2652[64][32][32],
  float v2653[64][32][32],
  float v2654[64][32][32]
) {	// L3140
  #pragma HLS array_partition variable=v2650 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2650 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2652 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2652 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2653 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2653 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2654 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2654 cyclic factor=2 dim=3

  for (int v2655 = 0; v2655 < 9216; v2655 += 1) {	// L3141
    #pragma HLS dataflow
    int v2656 = (v2655 % 4);	// L3142
    int v2657 = ((v2655 / 4) % 4);	// L3143
    int v2658 = (((v2655 / 4) / 4) % 8);	// L3144
    int v2659 = ((((v2655 / 4) / 4) / 8) % 3);	// L3145
    int v2660 = (((((v2655 / 4) / 4) / 8) / 3) % 3);	// L3146
    int v2661 = (((((v2655 / 4) / 4) / 8) / 3) / 3);	// L3147
    float v2662[8][8];	// L3148
    #pragma HLS resource variable=v2662 core=ram_t2p_bram

    float v2663[8][8][8];	// L3149
    #pragma HLS array_partition variable=v2663 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2663 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2663 core=ram_t2p_bram

    float v2664[8][8][8];	// L3150
    #pragma HLS array_partition variable=v2664 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2664 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2664 core=ram_t2p_bram

    float v2665[8][8][8];	// L3151
    #pragma HLS array_partition variable=v2665 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2665 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2665 core=ram_t2p_bram

    forward_node185(v2652, v2665, v2658, v2657, v2656);	// L3152
    forward_node184(v2653, v2664, v2658, v2657, v2656);	// L3153
    forward_node183(v2650, v2663, v2661, v2660, v2657, v2659, v2656);	// L3154
    forward_node182(v2651, v2662, v2660, v2659, v2658, v2661);	// L3155
    float v2666[8][8][8];	// L3156
    #pragma HLS array_partition variable=v2666 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2666 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2666 core=ram_t2p_bram

    forward_node181(v2662, v2663, v2665, v2664, v2666, v2660, v2661, v2659);	// L3157
    forward_node180(v2666, v2654, v2658, v2657, v2656);	// L3158
  }
}

void forward_node187(
  float v2667[8][8][8],
  float v2668[64][32][32],
  int v2669,
  int v2670,
  int v2671
) {	// L3162
  #pragma HLS inline
  #pragma HLS resource variable=v2667 core=ram_t2p_bram

  for (int v2672 = 0; v2672 < 8; v2672 += 1) {	// L3163
    for (int v2673 = 0; v2673 < 8; v2673 += 1) {	// L3164
      for (int v2674 = 0; v2674 < 8; v2674 += 1) {	// L3165
        #pragma HLS pipeline II=1
        float v2675 = v2667[v2672][v2673][v2674];	// L3166
        v2668[(v2672 + (v2669 * 8))][(v2673 + (v2670 * 8))][(v2674 + (v2671 * 8))] = v2675;	// L3167
      }
    }
  }
}

void forward_node188(
  float v2676[64],
  float v2677[8][8][8],
  float v2678[64],
  float v2679[8][8][8],
  float v2680[64],
  float v2681[64],
  float v2682[8][8][8],
  int v2683
) {	// L3173
  #pragma HLS inline
  #pragma HLS resource variable=v2676 core=ram_t2p_bram

  #pragma HLS resource variable=v2677 core=ram_t2p_bram

  #pragma HLS resource variable=v2678 core=ram_t2p_bram

  #pragma HLS resource variable=v2679 core=ram_t2p_bram

  #pragma HLS resource variable=v2680 core=ram_t2p_bram

  #pragma HLS resource variable=v2681 core=ram_t2p_bram

  #pragma HLS resource variable=v2682 core=ram_t2p_bram

  for (int v2684 = 0; v2684 < 8; v2684 += 1) {	// L3176
    for (int v2685 = 0; v2685 < 8; v2685 += 1) {	// L3177
      for (int v2686 = 0; v2686 < 8; v2686 += 1) {	// L3178
        #pragma HLS pipeline II=1
        float v2687 = v2677[v2684][v2685][v2686];	// L3179
        float v2688 = v2678[(v2684 + (v2683 * 8))];	// L3180
        float v2689 = v2680[(v2684 + (v2683 * 8))];	// L3181
        float v2690 = v2681[(v2684 + (v2683 * 8))];	// L3182
        float v2691 = v2676[(v2684 + (v2683 * 8))];	// L3183
        float v2692 = v2679[v2684][v2685][v2686];	// L3184
        float v2693 = (double)0.000010;	// L3185
        float v2694 = v2691 + v2693;	// L3186
        float v2695 = 1.0 / sqrt(v2694);	// L3187
        float v2696 = v2687 - v2690;	// L3188
        float v2697 = v2696 * v2695;	// L3189
        float v2698 = v2697 * v2688;	// L3190
        float v2699 = v2698 + v2689;	// L3191
        float v2700 = v2699 + v2692;	// L3192
        bool v2701 = v2700 > (float)0.000000;	// L3193
        float v2702 = v2701 ? v2700 : (float)0.000000;	// L3194
        v2682[v2684][v2685][v2686] = v2702;	// L3195
      }
    }
  }
}

void forward_node189(
  float v2703[64][32][32],
  float v2704[8][8][8],
  int v2705,
  int v2706,
  int v2707
) {	// L3201
  #pragma HLS inline
  #pragma HLS resource variable=v2704 core=ram_t2p_bram

  for (int v2708 = 0; v2708 < 8; v2708 += 1) {	// L3202
    for (int v2709 = 0; v2709 < 8; v2709 += 1) {	// L3203
      for (int v2710 = 0; v2710 < 8; v2710 += 1) {	// L3204
        #pragma HLS pipeline II=1
        float v2711 = v2703[(v2708 + (v2705 * 8))][(v2709 + (v2706 * 8))][(v2710 + (v2707 * 8))];	// L3205
        v2704[v2708][v2709][v2710] = v2711;	// L3206
      }
    }
  }
}

void forward_node190(
  float v2712[64][32][32],
  float v2713[8][8][8],
  int v2714,
  int v2715,
  int v2716
) {	// L3212
  #pragma HLS inline
  #pragma HLS resource variable=v2713 core=ram_t2p_bram

  for (int v2717 = 0; v2717 < 8; v2717 += 1) {	// L3213
    for (int v2718 = 0; v2718 < 8; v2718 += 1) {	// L3214
      for (int v2719 = 0; v2719 < 8; v2719 += 1) {	// L3215
        #pragma HLS pipeline II=1
        float v2720 = v2712[(v2717 + (v2714 * 8))][(v2718 + (v2715 * 8))][(v2719 + (v2716 * 8))];	// L3216
        v2713[v2717][v2718][v2719] = v2720;	// L3217
      }
    }
  }
}

void forward_node186(
  float v2721[64],
  float v2722[64],
  float v2723[64],
  float v2724[64],
  float v2725[64][32][32],
  float v2726[64][32][32],
  float v2727[64][32][32]
) {	// L3223
  #pragma HLS resource variable=v2721 core=ram_t2p_bram

  #pragma HLS resource variable=v2722 core=ram_t2p_bram

  #pragma HLS resource variable=v2723 core=ram_t2p_bram

  #pragma HLS resource variable=v2724 core=ram_t2p_bram

  for (int v2728 = 0; v2728 < 128; v2728 += 1) {	// L3224
    #pragma HLS dataflow
    int v2729 = (v2728 % 4);	// L3225
    int v2730 = ((v2728 / 4) % 4);	// L3226
    int v2731 = ((v2728 / 4) / 4);	// L3227
    float v2732[8][8][8];	// L3228
    #pragma HLS resource variable=v2732 core=ram_t2p_bram

    float v2733[8][8][8];	// L3229
    #pragma HLS resource variable=v2733 core=ram_t2p_bram

    float v2734[8][8][8];	// L3230
    #pragma HLS resource variable=v2734 core=ram_t2p_bram

    forward_node190(v2726, v2734, v2731, v2730, v2729);	// L3231
    forward_node189(v2725, v2733, v2731, v2730, v2729);	// L3232
    forward_node188(v2721, v2734, v2724, v2733, v2723, v2722, v2732, v2731);	// L3233
    forward_node187(v2732, v2727, v2731, v2730, v2729);	// L3234
  }
}

void forward_node192(
  float v2735[8][8][8],
  float v2736[64][32][32],
  int v2737,
  int v2738,
  int v2739
) {	// L3238
  #pragma HLS inline
  #pragma HLS array_partition variable=v2735 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2735 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2735 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2736 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2736 cyclic factor=2 dim=3

  for (int v2740 = 0; v2740 < 8; v2740 += 1) {	// L3239
    for (int v2741 = 0; v2741 < 8; v2741 += 2) {	// L3240
      for (int v2742 = 0; v2742 < 8; v2742 += 2) {	// L3241
        #pragma HLS pipeline II=1
        float v2743 = v2735[v2740][v2741][v2742];	// L3242
        v2736[(v2740 + (v2737 * 8))][(v2741 + (v2738 * 8))][(v2742 + (v2739 * 8))] = v2743;	// L3243
        float v2744 = v2735[v2740][v2741][(v2742 + 1)];	// L3244
        v2736[(v2740 + (v2737 * 8))][(v2741 + (v2738 * 8))][((v2742 + (v2739 * 8)) + 1)] = v2744;	// L3245
        float v2745 = v2735[v2740][(v2741 + 1)][v2742];	// L3246
        v2736[(v2740 + (v2737 * 8))][((v2741 + (v2738 * 8)) + 1)][(v2742 + (v2739 * 8))] = v2745;	// L3247
        float v2746 = v2735[v2740][(v2741 + 1)][(v2742 + 1)];	// L3248
        v2736[(v2740 + (v2737 * 8))][((v2741 + (v2738 * 8)) + 1)][((v2742 + (v2739 * 8)) + 1)] = v2746;	// L3249
      }
    }
  }
}

void forward_node193(
  float v2747[8][8][8],
  float v2748[8][8],
  float v2749[8][8][8],
  float v2750[8][8][8],
  float v2751[8][8][8],
  int v2752,
  int v2753,
  int v2754
) {	// L3255
  #pragma HLS inline
  #pragma HLS array_partition variable=v2747 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2747 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2747 core=ram_t2p_bram

  #pragma HLS resource variable=v2748 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2749 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2749 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2749 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2750 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2750 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2750 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2751 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2751 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2751 core=ram_t2p_bram

  for (int v2755 = 0; v2755 < 8; v2755 += 1) {	// L3256
    for (int v2756 = 0; v2756 < 8; v2756 += 1) {	// L3257
      for (int v2757 = 0; v2757 < 8; v2757 += 2) {	// L3258
        for (int v2758 = 0; v2758 < 8; v2758 += 2) {	// L3259
          #pragma HLS pipeline II=1
          float v2759 = v2747[v2756][v2757][v2758];	// L3260
          float v2760 = v2750[v2756][v2757][v2758];	// L3261
          float v2761 = v2751[v2756][v2757][v2758];	// L3262
          float v2762 = (v2755 == 0) ? v2760 : v2761;	// L3263
          float v2763 = ((v2755 + (v2754 * 8)) == 0 && v2753 == 0 && v2752 == 0) ? v2759 : v2762;	// L3264
          float v2764 = v2749[v2755][v2757][v2758];	// L3265
          float v2765 = v2748[v2756][v2755];	// L3266
          float v2766 = v2764 * v2765;	// L3267
          float v2767 = v2763 + v2766;	// L3268
          v2751[v2756][v2757][v2758] = v2767;	// L3269
          float v2768 = v2747[v2756][v2757][(v2758 + 1)];	// L3270
          float v2769 = v2750[v2756][v2757][(v2758 + 1)];	// L3271
          float v2770 = v2751[v2756][v2757][(v2758 + 1)];	// L3272
          float v2771 = (v2755 == 0) ? v2769 : v2770;	// L3273
          float v2772 = ((v2755 + (v2754 * 8)) == 0 && v2753 == 0 && v2752 == 0) ? v2768 : v2771;	// L3274
          float v2773 = v2749[v2755][v2757][(v2758 + 1)];	// L3275
          float v2774 = v2773 * v2765;	// L3276
          float v2775 = v2772 + v2774;	// L3277
          v2751[v2756][v2757][(v2758 + 1)] = v2775;	// L3278
          float v2776 = v2747[v2756][(v2757 + 1)][v2758];	// L3279
          float v2777 = v2750[v2756][(v2757 + 1)][v2758];	// L3280
          float v2778 = v2751[v2756][(v2757 + 1)][v2758];	// L3281
          float v2779 = (v2755 == 0) ? v2777 : v2778;	// L3282
          float v2780 = ((v2755 + (v2754 * 8)) == 0 && v2753 == 0 && v2752 == 0) ? v2776 : v2779;	// L3283
          float v2781 = v2749[v2755][(v2757 + 1)][v2758];	// L3284
          float v2782 = v2781 * v2765;	// L3285
          float v2783 = v2780 + v2782;	// L3286
          v2751[v2756][(v2757 + 1)][v2758] = v2783;	// L3287
          float v2784 = v2747[v2756][(v2757 + 1)][(v2758 + 1)];	// L3288
          float v2785 = v2750[v2756][(v2757 + 1)][(v2758 + 1)];	// L3289
          float v2786 = v2751[v2756][(v2757 + 1)][(v2758 + 1)];	// L3290
          float v2787 = (v2755 == 0) ? v2785 : v2786;	// L3291
          float v2788 = ((v2755 + (v2754 * 8)) == 0 && v2753 == 0 && v2752 == 0) ? v2784 : v2787;	// L3292
          float v2789 = v2749[v2755][(v2757 + 1)][(v2758 + 1)];	// L3293
          float v2790 = v2789 * v2765;	// L3294
          float v2791 = v2788 + v2790;	// L3295
          v2751[v2756][(v2757 + 1)][(v2758 + 1)] = v2791;	// L3296
        }
      }
    }
  }
}

void forward_node194(
  float v2792[64][64][3][3],
  float v2793[8][8],
  int v2794,
  int v2795,
  int v2796,
  int v2797
) {	// L3303
  #pragma HLS inline
  #pragma HLS resource variable=v2793 core=ram_t2p_bram

  for (int v2798 = 0; v2798 < 8; v2798 += 1) {	// L3304
    for (int v2799 = 0; v2799 < 8; v2799 += 1) {	// L3305
      #pragma HLS pipeline II=1
      float v2800 = v2792[(v2798 + (v2796 * 8))][(v2799 + (v2797 * 8))][v2794][v2795];	// L3306
      v2793[v2798][v2799] = v2800;	// L3307
    }
  }
}

void forward_node195(
  float v2801[64][32][32],
  float v2802[8][8][8],
  int v2803,
  int v2804,
  int v2805,
  int v2806,
  int v2807
) {	// L3312
  #pragma HLS inline
  #pragma HLS array_partition variable=v2801 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2801 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2802 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2802 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2802 core=ram_t2p_bram

  for (int v2808 = 0; v2808 < 8; v2808 += 1) {	// L3313
    for (int v2809 = 0; v2809 < 8; v2809 += 2) {	// L3314
      for (int v2810 = 0; v2810 < 8; v2810 += 2) {	// L3315
        #pragma HLS pipeline II=1
        float v2811 = v2801[(v2808 + (v2803 * 8))][(((v2809 + v2804) + (v2805 * 8)) - 1)][(((v2810 + v2806) + (v2807 * 8)) - 1)];	// L3316
        v2802[v2808][v2809][v2810] = v2811;	// L3317
        float v2812 = v2801[(v2808 + (v2803 * 8))][(((v2809 + v2804) + (v2805 * 8)) - 1)][((v2810 + v2806) + (v2807 * 8))];	// L3318
        v2802[v2808][v2809][(v2810 + 1)] = v2812;	// L3319
        float v2813 = v2801[(v2808 + (v2803 * 8))][((v2809 + v2804) + (v2805 * 8))][(((v2810 + v2806) + (v2807 * 8)) - 1)];	// L3320
        v2802[v2808][(v2809 + 1)][v2810] = v2813;	// L3321
        float v2814 = v2801[(v2808 + (v2803 * 8))][((v2809 + v2804) + (v2805 * 8))][((v2810 + v2806) + (v2807 * 8))];	// L3322
        v2802[v2808][(v2809 + 1)][(v2810 + 1)] = v2814;	// L3323
      }
    }
  }
}

void forward_node196(
  float v2815[64][32][32],
  float v2816[8][8][8],
  int v2817,
  int v2818,
  int v2819
) {	// L3329
  #pragma HLS inline
  #pragma HLS array_partition variable=v2815 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2815 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2816 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2816 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2816 core=ram_t2p_bram

  for (int v2820 = 0; v2820 < 8; v2820 += 1) {	// L3330
    for (int v2821 = 0; v2821 < 8; v2821 += 2) {	// L3331
      for (int v2822 = 0; v2822 < 8; v2822 += 2) {	// L3332
        #pragma HLS pipeline II=1
        float v2823 = v2815[(v2820 + (v2817 * 8))][(v2821 + (v2818 * 8))][(v2822 + (v2819 * 8))];	// L3333
        v2816[v2820][v2821][v2822] = v2823;	// L3334
        float v2824 = v2815[(v2820 + (v2817 * 8))][(v2821 + (v2818 * 8))][((v2822 + (v2819 * 8)) + 1)];	// L3335
        v2816[v2820][v2821][(v2822 + 1)] = v2824;	// L3336
        float v2825 = v2815[(v2820 + (v2817 * 8))][((v2821 + (v2818 * 8)) + 1)][(v2822 + (v2819 * 8))];	// L3337
        v2816[v2820][(v2821 + 1)][v2822] = v2825;	// L3338
        float v2826 = v2815[(v2820 + (v2817 * 8))][((v2821 + (v2818 * 8)) + 1)][((v2822 + (v2819 * 8)) + 1)];	// L3339
        v2816[v2820][(v2821 + 1)][(v2822 + 1)] = v2826;	// L3340
      }
    }
  }
}

void forward_node197(
  float v2827[64][32][32],
  float v2828[8][8][8],
  int v2829,
  int v2830,
  int v2831
) {	// L3346
  #pragma HLS inline
  #pragma HLS array_partition variable=v2827 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2827 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2828 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2828 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2828 core=ram_t2p_bram

  for (int v2832 = 0; v2832 < 8; v2832 += 1) {	// L3347
    for (int v2833 = 0; v2833 < 8; v2833 += 2) {	// L3348
      for (int v2834 = 0; v2834 < 8; v2834 += 2) {	// L3349
        #pragma HLS pipeline II=1
        float v2835 = v2827[(v2832 + (v2829 * 8))][(v2833 + (v2830 * 8))][(v2834 + (v2831 * 8))];	// L3350
        v2828[v2832][v2833][v2834] = v2835;	// L3351
        float v2836 = v2827[(v2832 + (v2829 * 8))][(v2833 + (v2830 * 8))][((v2834 + (v2831 * 8)) + 1)];	// L3352
        v2828[v2832][v2833][(v2834 + 1)] = v2836;	// L3353
        float v2837 = v2827[(v2832 + (v2829 * 8))][((v2833 + (v2830 * 8)) + 1)][(v2834 + (v2831 * 8))];	// L3354
        v2828[v2832][(v2833 + 1)][v2834] = v2837;	// L3355
        float v2838 = v2827[(v2832 + (v2829 * 8))][((v2833 + (v2830 * 8)) + 1)][((v2834 + (v2831 * 8)) + 1)];	// L3356
        v2828[v2832][(v2833 + 1)][(v2834 + 1)] = v2838;	// L3357
      }
    }
  }
}

void forward_node191(
  float v2839[64][32][32],
  float v2840[64][32][32],
  float v2841[64][64][3][3],
  float v2842[64][32][32],
  float v2843[64][32][32]
) {	// L3363
  #pragma HLS array_partition variable=v2839 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2839 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2840 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2840 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2842 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2842 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2843 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2843 cyclic factor=2 dim=3

  for (int v2844 = 0; v2844 < 9216; v2844 += 1) {	// L3364
    #pragma HLS dataflow
    int v2845 = (v2844 % 4);	// L3365
    int v2846 = ((v2844 / 4) % 4);	// L3366
    int v2847 = (((v2844 / 4) / 4) % 8);	// L3367
    int v2848 = ((((v2844 / 4) / 4) / 8) % 3);	// L3368
    int v2849 = (((((v2844 / 4) / 4) / 8) / 3) % 3);	// L3369
    int v2850 = (((((v2844 / 4) / 4) / 8) / 3) / 3);	// L3370
    float v2851[8][8];	// L3371
    #pragma HLS resource variable=v2851 core=ram_t2p_bram

    float v2852[8][8][8];	// L3372
    #pragma HLS array_partition variable=v2852 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2852 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2852 core=ram_t2p_bram

    float v2853[8][8][8];	// L3373
    #pragma HLS array_partition variable=v2853 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2853 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2853 core=ram_t2p_bram

    float v2854[8][8][8];	// L3374
    #pragma HLS array_partition variable=v2854 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2854 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2854 core=ram_t2p_bram

    forward_node197(v2840, v2854, v2847, v2846, v2845);	// L3375
    forward_node196(v2842, v2853, v2847, v2846, v2845);	// L3376
    forward_node195(v2839, v2852, v2850, v2849, v2846, v2848, v2845);	// L3377
    forward_node194(v2841, v2851, v2849, v2848, v2847, v2850);	// L3378
    float v2855[8][8][8];	// L3379
    #pragma HLS array_partition variable=v2855 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v2855 cyclic factor=2 dim=3
    #pragma HLS resource variable=v2855 core=ram_t2p_bram

    forward_node193(v2854, v2851, v2852, v2853, v2855, v2848, v2849, v2850);	// L3380
    forward_node192(v2855, v2843, v2847, v2846, v2845);	// L3381
  }
}

void forward_node199(
  float v2856[8][8][8],
  float v2857[64][32][32],
  int v2858,
  int v2859,
  int v2860
) {	// L3385
  #pragma HLS inline
  #pragma HLS resource variable=v2856 core=ram_t2p_bram

  for (int v2861 = 0; v2861 < 8; v2861 += 1) {	// L3386
    for (int v2862 = 0; v2862 < 8; v2862 += 1) {	// L3387
      for (int v2863 = 0; v2863 < 8; v2863 += 1) {	// L3388
        #pragma HLS pipeline II=1
        float v2864 = v2856[v2861][v2862][v2863];	// L3389
        v2857[(v2861 + (v2858 * 8))][(v2862 + (v2859 * 8))][(v2863 + (v2860 * 8))] = v2864;	// L3390
      }
    }
  }
}

void forward_node200(
  float v2865[8][8][8],
  float v2866[64],
  float v2867[64],
  float v2868[64],
  float v2869[64],
  float v2870[8][8][8],
  int v2871
) {	// L3396
  #pragma HLS inline
  #pragma HLS resource variable=v2865 core=ram_t2p_bram

  #pragma HLS resource variable=v2866 core=ram_t2p_bram

  #pragma HLS resource variable=v2867 core=ram_t2p_bram

  #pragma HLS resource variable=v2868 core=ram_t2p_bram

  #pragma HLS resource variable=v2869 core=ram_t2p_bram

  #pragma HLS resource variable=v2870 core=ram_t2p_bram

  for (int v2872 = 0; v2872 < 8; v2872 += 1) {	// L3399
    for (int v2873 = 0; v2873 < 8; v2873 += 1) {	// L3400
      for (int v2874 = 0; v2874 < 8; v2874 += 1) {	// L3401
        #pragma HLS pipeline II=1
        float v2875 = v2865[v2872][v2873][v2874];	// L3402
        float v2876 = v2869[(v2872 + (v2871 * 8))];	// L3403
        float v2877 = v2867[(v2872 + (v2871 * 8))];	// L3404
        float v2878 = v2868[(v2872 + (v2871 * 8))];	// L3405
        float v2879 = v2866[(v2872 + (v2871 * 8))];	// L3406
        float v2880 = (double)0.000010;	// L3407
        float v2881 = v2879 + v2880;	// L3408
        float v2882 = 1.0 / sqrt(v2881);	// L3409
        float v2883 = v2875 - v2878;	// L3410
        float v2884 = v2883 * v2882;	// L3411
        float v2885 = v2884 * v2876;	// L3412
        float v2886 = v2885 + v2877;	// L3413
        bool v2887 = v2886 > (float)0.000000;	// L3414
        float v2888 = v2887 ? v2886 : (float)0.000000;	// L3415
        v2870[v2872][v2873][v2874] = v2888;	// L3416
      }
    }
  }
}

void forward_node201(
  float v2889[64][32][32],
  float v2890[8][8][8],
  int v2891,
  int v2892,
  int v2893
) {	// L3422
  #pragma HLS inline
  #pragma HLS resource variable=v2890 core=ram_t2p_bram

  for (int v2894 = 0; v2894 < 8; v2894 += 1) {	// L3423
    for (int v2895 = 0; v2895 < 8; v2895 += 1) {	// L3424
      for (int v2896 = 0; v2896 < 8; v2896 += 1) {	// L3425
        #pragma HLS pipeline II=1
        float v2897 = v2889[(v2894 + (v2891 * 8))][(v2895 + (v2892 * 8))][(v2896 + (v2893 * 8))];	// L3426
        v2890[v2894][v2895][v2896] = v2897;	// L3427
      }
    }
  }
}

void forward_node198(
  float v2898[64],
  float v2899[64],
  float v2900[64][32][32],
  float v2901[64],
  float v2902[64],
  float v2903[64][32][32]
) {	// L3433
  #pragma HLS resource variable=v2898 core=ram_t2p_bram

  #pragma HLS resource variable=v2899 core=ram_t2p_bram

  #pragma HLS resource variable=v2901 core=ram_t2p_bram

  #pragma HLS resource variable=v2902 core=ram_t2p_bram

  for (int v2904 = 0; v2904 < 128; v2904 += 1) {	// L3434
    #pragma HLS dataflow
    int v2905 = (v2904 % 4);	// L3435
    int v2906 = ((v2904 / 4) % 4);	// L3436
    int v2907 = ((v2904 / 4) / 4);	// L3437
    float v2908[8][8][8];	// L3438
    #pragma HLS resource variable=v2908 core=ram_t2p_bram

    float v2909[8][8][8];	// L3439
    #pragma HLS resource variable=v2909 core=ram_t2p_bram

    forward_node201(v2900, v2909, v2907, v2906, v2905);	// L3440
    forward_node200(v2909, v2898, v2901, v2899, v2902, v2908, v2907);	// L3441
    forward_node199(v2908, v2903, v2907, v2906, v2905);	// L3442
  }
}

void forward_node203(
  float v2910[8][8][8],
  float v2911[64][32][32],
  int v2912,
  int v2913,
  int v2914
) {	// L3446
  #pragma HLS inline
  #pragma HLS array_partition variable=v2910 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2910 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2910 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2911 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2911 cyclic factor=2 dim=3

  for (int v2915 = 0; v2915 < 8; v2915 += 1) {	// L3447
    for (int v2916 = 0; v2916 < 8; v2916 += 2) {	// L3448
      for (int v2917 = 0; v2917 < 8; v2917 += 2) {	// L3449
        #pragma HLS pipeline II=1
        float v2918 = v2910[v2915][v2916][v2917];	// L3450
        v2911[(v2915 + (v2912 * 8))][(v2916 + (v2913 * 8))][(v2917 + (v2914 * 8))] = v2918;	// L3451
        float v2919 = v2910[v2915][v2916][(v2917 + 1)];	// L3452
        v2911[(v2915 + (v2912 * 8))][(v2916 + (v2913 * 8))][((v2917 + (v2914 * 8)) + 1)] = v2919;	// L3453
        float v2920 = v2910[v2915][(v2916 + 1)][v2917];	// L3454
        v2911[(v2915 + (v2912 * 8))][((v2916 + (v2913 * 8)) + 1)][(v2917 + (v2914 * 8))] = v2920;	// L3455
        float v2921 = v2910[v2915][(v2916 + 1)][(v2917 + 1)];	// L3456
        v2911[(v2915 + (v2912 * 8))][((v2916 + (v2913 * 8)) + 1)][((v2917 + (v2914 * 8)) + 1)] = v2921;	// L3457
      }
    }
  }
}

void forward_node204(
  float v2922[8][8][8],
  float v2923[8][8],
  float v2924[8][8][8],
  float v2925[8][8][8],
  float v2926[8][8][8],
  int v2927,
  int v2928,
  int v2929
) {	// L3463
  #pragma HLS inline
  #pragma HLS array_partition variable=v2922 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2922 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2922 core=ram_t2p_bram

  #pragma HLS resource variable=v2923 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2924 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2924 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2924 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2925 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2925 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2925 core=ram_t2p_bram

  #pragma HLS array_partition variable=v2926 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2926 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2926 core=ram_t2p_bram

  for (int v2930 = 0; v2930 < 8; v2930 += 1) {	// L3464
    for (int v2931 = 0; v2931 < 8; v2931 += 1) {	// L3465
      for (int v2932 = 0; v2932 < 8; v2932 += 2) {	// L3466
        for (int v2933 = 0; v2933 < 8; v2933 += 2) {	// L3467
          #pragma HLS pipeline II=1
          float v2934 = v2922[v2931][v2932][v2933];	// L3468
          float v2935 = v2925[v2931][v2932][v2933];	// L3469
          float v2936 = v2926[v2931][v2932][v2933];	// L3470
          float v2937 = (v2930 == 0) ? v2935 : v2936;	// L3471
          float v2938 = ((v2930 + (v2928 * 8)) == 0 && v2927 == 0 && v2929 == 0) ? v2934 : v2937;	// L3472
          float v2939 = v2924[v2930][v2932][v2933];	// L3473
          float v2940 = v2923[v2931][v2930];	// L3474
          float v2941 = v2939 * v2940;	// L3475
          float v2942 = v2938 + v2941;	// L3476
          v2926[v2931][v2932][v2933] = v2942;	// L3477
          float v2943 = v2922[v2931][v2932][(v2933 + 1)];	// L3478
          float v2944 = v2925[v2931][v2932][(v2933 + 1)];	// L3479
          float v2945 = v2926[v2931][v2932][(v2933 + 1)];	// L3480
          float v2946 = (v2930 == 0) ? v2944 : v2945;	// L3481
          float v2947 = ((v2930 + (v2928 * 8)) == 0 && v2927 == 0 && v2929 == 0) ? v2943 : v2946;	// L3482
          float v2948 = v2924[v2930][v2932][(v2933 + 1)];	// L3483
          float v2949 = v2948 * v2940;	// L3484
          float v2950 = v2947 + v2949;	// L3485
          v2926[v2931][v2932][(v2933 + 1)] = v2950;	// L3486
          float v2951 = v2922[v2931][(v2932 + 1)][v2933];	// L3487
          float v2952 = v2925[v2931][(v2932 + 1)][v2933];	// L3488
          float v2953 = v2926[v2931][(v2932 + 1)][v2933];	// L3489
          float v2954 = (v2930 == 0) ? v2952 : v2953;	// L3490
          float v2955 = ((v2930 + (v2928 * 8)) == 0 && v2927 == 0 && v2929 == 0) ? v2951 : v2954;	// L3491
          float v2956 = v2924[v2930][(v2932 + 1)][v2933];	// L3492
          float v2957 = v2956 * v2940;	// L3493
          float v2958 = v2955 + v2957;	// L3494
          v2926[v2931][(v2932 + 1)][v2933] = v2958;	// L3495
          float v2959 = v2922[v2931][(v2932 + 1)][(v2933 + 1)];	// L3496
          float v2960 = v2925[v2931][(v2932 + 1)][(v2933 + 1)];	// L3497
          float v2961 = v2926[v2931][(v2932 + 1)][(v2933 + 1)];	// L3498
          float v2962 = (v2930 == 0) ? v2960 : v2961;	// L3499
          float v2963 = ((v2930 + (v2928 * 8)) == 0 && v2927 == 0 && v2929 == 0) ? v2959 : v2962;	// L3500
          float v2964 = v2924[v2930][(v2932 + 1)][(v2933 + 1)];	// L3501
          float v2965 = v2964 * v2940;	// L3502
          float v2966 = v2963 + v2965;	// L3503
          v2926[v2931][(v2932 + 1)][(v2933 + 1)] = v2966;	// L3504
        }
      }
    }
  }
}

void forward_node205(
  float v2967[64][64][3][3],
  float v2968[8][8],
  int v2969,
  int v2970,
  int v2971,
  int v2972
) {	// L3511
  #pragma HLS inline
  #pragma HLS resource variable=v2968 core=ram_t2p_bram

  for (int v2973 = 0; v2973 < 8; v2973 += 1) {	// L3512
    for (int v2974 = 0; v2974 < 8; v2974 += 1) {	// L3513
      #pragma HLS pipeline II=1
      float v2975 = v2967[(v2973 + (v2971 * 8))][(v2974 + (v2972 * 8))][v2969][v2970];	// L3514
      v2968[v2973][v2974] = v2975;	// L3515
    }
  }
}

void forward_node206(
  float v2976[64][32][32],
  float v2977[8][8][8],
  int v2978,
  int v2979,
  int v2980,
  int v2981,
  int v2982
) {	// L3520
  #pragma HLS inline
  #pragma HLS array_partition variable=v2976 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2976 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2977 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2977 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2977 core=ram_t2p_bram

  for (int v2983 = 0; v2983 < 8; v2983 += 1) {	// L3521
    for (int v2984 = 0; v2984 < 8; v2984 += 2) {	// L3522
      for (int v2985 = 0; v2985 < 8; v2985 += 2) {	// L3523
        #pragma HLS pipeline II=1
        float v2986 = v2976[(v2983 + (v2978 * 8))][(((v2984 + v2979) + (v2980 * 8)) - 1)][(((v2985 + v2981) + (v2982 * 8)) - 1)];	// L3524
        v2977[v2983][v2984][v2985] = v2986;	// L3525
        float v2987 = v2976[(v2983 + (v2978 * 8))][(((v2984 + v2979) + (v2980 * 8)) - 1)][((v2985 + v2981) + (v2982 * 8))];	// L3526
        v2977[v2983][v2984][(v2985 + 1)] = v2987;	// L3527
        float v2988 = v2976[(v2983 + (v2978 * 8))][((v2984 + v2979) + (v2980 * 8))][(((v2985 + v2981) + (v2982 * 8)) - 1)];	// L3528
        v2977[v2983][(v2984 + 1)][v2985] = v2988;	// L3529
        float v2989 = v2976[(v2983 + (v2978 * 8))][((v2984 + v2979) + (v2980 * 8))][((v2985 + v2981) + (v2982 * 8))];	// L3530
        v2977[v2983][(v2984 + 1)][(v2985 + 1)] = v2989;	// L3531
      }
    }
  }
}

void forward_node207(
  float v2990[64][32][32],
  float v2991[8][8][8],
  int v2992,
  int v2993,
  int v2994
) {	// L3537
  #pragma HLS inline
  #pragma HLS array_partition variable=v2990 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2990 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v2991 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v2991 cyclic factor=2 dim=3
  #pragma HLS resource variable=v2991 core=ram_t2p_bram

  for (int v2995 = 0; v2995 < 8; v2995 += 1) {	// L3538
    for (int v2996 = 0; v2996 < 8; v2996 += 2) {	// L3539
      for (int v2997 = 0; v2997 < 8; v2997 += 2) {	// L3540
        #pragma HLS pipeline II=1
        float v2998 = v2990[(v2995 + (v2992 * 8))][(v2996 + (v2993 * 8))][(v2997 + (v2994 * 8))];	// L3541
        v2991[v2995][v2996][v2997] = v2998;	// L3542
        float v2999 = v2990[(v2995 + (v2992 * 8))][(v2996 + (v2993 * 8))][((v2997 + (v2994 * 8)) + 1)];	// L3543
        v2991[v2995][v2996][(v2997 + 1)] = v2999;	// L3544
        float v3000 = v2990[(v2995 + (v2992 * 8))][((v2996 + (v2993 * 8)) + 1)][(v2997 + (v2994 * 8))];	// L3545
        v2991[v2995][(v2996 + 1)][v2997] = v3000;	// L3546
        float v3001 = v2990[(v2995 + (v2992 * 8))][((v2996 + (v2993 * 8)) + 1)][((v2997 + (v2994 * 8)) + 1)];	// L3547
        v2991[v2995][(v2996 + 1)][(v2997 + 1)] = v3001;	// L3548
      }
    }
  }
}

void forward_node208(
  float v3002[64][32][32],
  float v3003[8][8][8],
  int v3004,
  int v3005,
  int v3006
) {	// L3554
  #pragma HLS inline
  #pragma HLS array_partition variable=v3002 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3002 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v3003 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3003 cyclic factor=2 dim=3
  #pragma HLS resource variable=v3003 core=ram_t2p_bram

  for (int v3007 = 0; v3007 < 8; v3007 += 1) {	// L3555
    for (int v3008 = 0; v3008 < 8; v3008 += 2) {	// L3556
      for (int v3009 = 0; v3009 < 8; v3009 += 2) {	// L3557
        #pragma HLS pipeline II=1
        float v3010 = v3002[(v3007 + (v3004 * 8))][(v3008 + (v3005 * 8))][(v3009 + (v3006 * 8))];	// L3558
        v3003[v3007][v3008][v3009] = v3010;	// L3559
        float v3011 = v3002[(v3007 + (v3004 * 8))][(v3008 + (v3005 * 8))][((v3009 + (v3006 * 8)) + 1)];	// L3560
        v3003[v3007][v3008][(v3009 + 1)] = v3011;	// L3561
        float v3012 = v3002[(v3007 + (v3004 * 8))][((v3008 + (v3005 * 8)) + 1)][(v3009 + (v3006 * 8))];	// L3562
        v3003[v3007][(v3008 + 1)][v3009] = v3012;	// L3563
        float v3013 = v3002[(v3007 + (v3004 * 8))][((v3008 + (v3005 * 8)) + 1)][((v3009 + (v3006 * 8)) + 1)];	// L3564
        v3003[v3007][(v3008 + 1)][(v3009 + 1)] = v3013;	// L3565
      }
    }
  }
}

void forward_node202(
  float v3014[64][64][3][3],
  float v3015[64][32][32],
  float v3016[64][32][32],
  float v3017[64][32][32],
  float v3018[64][32][32]
) {	// L3571
  #pragma HLS array_partition variable=v3015 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3015 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v3016 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3016 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v3017 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3017 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v3018 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3018 cyclic factor=2 dim=3

  for (int v3019 = 0; v3019 < 9216; v3019 += 1) {	// L3572
    #pragma HLS dataflow
    int v3020 = (v3019 % 4);	// L3573
    int v3021 = ((v3019 / 4) % 4);	// L3574
    int v3022 = (((v3019 / 4) / 4) % 8);	// L3575
    int v3023 = ((((v3019 / 4) / 4) / 8) % 3);	// L3576
    int v3024 = (((((v3019 / 4) / 4) / 8) / 3) % 3);	// L3577
    int v3025 = (((((v3019 / 4) / 4) / 8) / 3) / 3);	// L3578
    float v3026[8][8];	// L3579
    #pragma HLS resource variable=v3026 core=ram_t2p_bram

    float v3027[8][8][8];	// L3580
    #pragma HLS array_partition variable=v3027 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v3027 cyclic factor=2 dim=3
    #pragma HLS resource variable=v3027 core=ram_t2p_bram

    float v3028[8][8][8];	// L3581
    #pragma HLS array_partition variable=v3028 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v3028 cyclic factor=2 dim=3
    #pragma HLS resource variable=v3028 core=ram_t2p_bram

    float v3029[8][8][8];	// L3582
    #pragma HLS array_partition variable=v3029 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v3029 cyclic factor=2 dim=3
    #pragma HLS resource variable=v3029 core=ram_t2p_bram

    forward_node208(v3016, v3029, v3022, v3021, v3020);	// L3583
    forward_node207(v3017, v3028, v3022, v3021, v3020);	// L3584
    forward_node206(v3015, v3027, v3025, v3024, v3021, v3023, v3020);	// L3585
    forward_node205(v3014, v3026, v3024, v3023, v3022, v3025);	// L3586
    float v3030[8][8][8];	// L3587
    #pragma HLS array_partition variable=v3030 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v3030 cyclic factor=2 dim=3
    #pragma HLS resource variable=v3030 core=ram_t2p_bram

    forward_node204(v3029, v3026, v3027, v3028, v3030, v3024, v3025, v3023);	// L3588
    forward_node203(v3030, v3018, v3022, v3021, v3020);	// L3589
  }
}

void forward_node210(
  float v3031[8][8][8],
  float v3032[64][32][32],
  int v3033,
  int v3034,
  int v3035
) {	// L3593
  #pragma HLS inline
  #pragma HLS resource variable=v3031 core=ram_t2p_bram

  for (int v3036 = 0; v3036 < 8; v3036 += 1) {	// L3594
    for (int v3037 = 0; v3037 < 8; v3037 += 1) {	// L3595
      for (int v3038 = 0; v3038 < 8; v3038 += 1) {	// L3596
        #pragma HLS pipeline II=1
        float v3039 = v3031[v3036][v3037][v3038];	// L3597
        v3032[(v3036 + (v3033 * 8))][(v3037 + (v3034 * 8))][(v3038 + (v3035 * 8))] = v3039;	// L3598
      }
    }
  }
}

void forward_node211(
  float v3040[8][8][8],
  float v3041[8][8][8],
  float v3042[8][8][8]
) {	// L3604
  #pragma HLS inline
  #pragma HLS resource variable=v3040 core=ram_t2p_bram

  #pragma HLS resource variable=v3041 core=ram_t2p_bram

  #pragma HLS resource variable=v3042 core=ram_t2p_bram

  for (int v3043 = 0; v3043 < 8; v3043 += 1) {	// L3605
    for (int v3044 = 0; v3044 < 8; v3044 += 1) {	// L3606
      for (int v3045 = 0; v3045 < 8; v3045 += 1) {	// L3607
        #pragma HLS pipeline II=1
        float v3046 = v3040[v3043][v3044][v3045];	// L3608
        float v3047 = v3041[v3043][v3044][v3045];	// L3609
        float v3048 = max(v3047, v3046);	// L3610
        v3042[v3043][v3044][v3045] = v3048;	// L3611
      }
    }
  }
}

void forward_node212(
  float v3049[64][32][32],
  float v3050[8][8][8],
  int v3051,
  int v3052,
  int v3053
) {	// L3617
  #pragma HLS inline
  #pragma HLS resource variable=v3050 core=ram_t2p_bram

  for (int v3054 = 0; v3054 < 8; v3054 += 1) {	// L3618
    for (int v3055 = 0; v3055 < 8; v3055 += 1) {	// L3619
      for (int v3056 = 0; v3056 < 8; v3056 += 1) {	// L3620
        #pragma HLS pipeline II=1
        float v3057 = v3049[(v3054 + (v3051 * 8))][(v3055 + (v3052 * 8))][(v3056 + (v3053 * 8))];	// L3621
        v3050[v3054][v3055][v3056] = v3057;	// L3622
      }
    }
  }
}

void forward_node213(
  float v3058[64][64][64],
  float v3059[8][8][8],
  int v3060,
  int v3061,
  int v3062,
  int v3063,
  int v3064
) {	// L3628
  #pragma HLS inline
  #pragma HLS resource variable=v3059 core=ram_t2p_bram

  for (int v3065 = 0; v3065 < 8; v3065 += 1) {	// L3629
    for (int v3066 = 0; v3066 < 8; v3066 += 1) {	// L3630
      for (int v3067 = 0; v3067 < 8; v3067 += 1) {	// L3631
        #pragma HLS pipeline II=1
        float v3068 = v3058[(v3065 + (v3060 * 8))][((((v3066 * 2) + v3061) + (v3062 * 16)) - 1)][((((v3067 * 2) + v3063) + (v3064 * 16)) - 1)];	// L3632
        v3059[v3065][v3066][v3067] = v3068;	// L3633
      }
    }
  }
}

void forward_node209(
  float v3069[64][64][64],
  float v3070[64][32][32],
  float v3071[64][32][32]
) {	// L3639
  for (int v3072 = 0; v3072 < 1152; v3072 += 1) {	// L3640
    #pragma HLS dataflow
    int v3073 = (v3072 % 4);	// L3641
    int v3074 = ((v3072 / 4) % 4);	// L3642
    int v3075 = (((v3072 / 4) / 4) % 8);	// L3643
    int v3076 = ((((v3072 / 4) / 4) / 8) % 3);	// L3644
    int v3077 = ((((v3072 / 4) / 4) / 8) / 3);	// L3645
    float v3078[8][8][8];	// L3646
    #pragma HLS resource variable=v3078 core=ram_t2p_bram

    float v3079[8][8][8];	// L3647
    #pragma HLS resource variable=v3079 core=ram_t2p_bram

    forward_node213(v3069, v3079, v3075, v3077, v3074, v3076, v3073);	// L3648
    forward_node212(v3070, v3078, v3075, v3074, v3073);	// L3649
    float v3080[8][8][8];	// L3650
    #pragma HLS resource variable=v3080 core=ram_t2p_bram

    forward_node211(v3079, v3078, v3080);	// L3651
    forward_node210(v3080, v3071, v3075, v3074, v3073);	// L3652
  }
}

void forward_node215(
  float v3081[8][8][8],
  float v3082[64][64][64],
  int v3083,
  int v3084,
  int v3085
) {	// L3656
  #pragma HLS inline
  #pragma HLS resource variable=v3081 core=ram_t2p_bram

  for (int v3086 = 0; v3086 < 8; v3086 += 1) {	// L3657
    for (int v3087 = 0; v3087 < 8; v3087 += 1) {	// L3658
      for (int v3088 = 0; v3088 < 8; v3088 += 1) {	// L3659
        #pragma HLS pipeline II=1
        float v3089 = v3081[v3086][v3087][v3088];	// L3660
        v3082[(v3086 + (v3083 * 8))][(v3087 + (v3084 * 8))][(v3088 + (v3085 * 8))] = v3089;	// L3661
      }
    }
  }
}

void forward_node216(
  float v3090[8][8][8],
  float v3091[64],
  float v3092[64],
  float v3093[64],
  float v3094[64],
  float v3095[8][8][8],
  int v3096
) {	// L3667
  #pragma HLS inline
  #pragma HLS resource variable=v3090 core=ram_t2p_bram

  #pragma HLS resource variable=v3091 core=ram_t2p_bram

  #pragma HLS resource variable=v3092 core=ram_t2p_bram

  #pragma HLS resource variable=v3093 core=ram_t2p_bram

  #pragma HLS resource variable=v3094 core=ram_t2p_bram

  #pragma HLS resource variable=v3095 core=ram_t2p_bram

  for (int v3097 = 0; v3097 < 8; v3097 += 1) {	// L3670
    for (int v3098 = 0; v3098 < 8; v3098 += 1) {	// L3671
      for (int v3099 = 0; v3099 < 8; v3099 += 1) {	// L3672
        #pragma HLS pipeline II=1
        float v3100 = v3090[v3097][v3098][v3099];	// L3673
        float v3101 = v3091[(v3097 + (v3096 * 8))];	// L3674
        float v3102 = v3094[(v3097 + (v3096 * 8))];	// L3675
        float v3103 = v3092[(v3097 + (v3096 * 8))];	// L3676
        float v3104 = v3093[(v3097 + (v3096 * 8))];	// L3677
        float v3105 = (double)0.000010;	// L3678
        float v3106 = v3104 + v3105;	// L3679
        float v3107 = 1.0 / sqrt(v3106);	// L3680
        float v3108 = v3100 - v3103;	// L3681
        float v3109 = v3108 * v3107;	// L3682
        float v3110 = v3109 * v3101;	// L3683
        float v3111 = v3110 + v3102;	// L3684
        bool v3112 = v3111 > (float)0.000000;	// L3685
        float v3113 = v3112 ? v3111 : (float)0.000000;	// L3686
        v3095[v3097][v3098][v3099] = v3113;	// L3687
      }
    }
  }
}

void forward_node217(
  float v3114[64][64][64],
  float v3115[8][8][8],
  int v3116,
  int v3117,
  int v3118
) {	// L3693
  #pragma HLS inline
  #pragma HLS resource variable=v3115 core=ram_t2p_bram

  for (int v3119 = 0; v3119 < 8; v3119 += 1) {	// L3694
    for (int v3120 = 0; v3120 < 8; v3120 += 1) {	// L3695
      for (int v3121 = 0; v3121 < 8; v3121 += 1) {	// L3696
        #pragma HLS pipeline II=1
        float v3122 = v3114[(v3119 + (v3116 * 8))][(v3120 + (v3117 * 8))][(v3121 + (v3118 * 8))];	// L3697
        v3115[v3119][v3120][v3121] = v3122;	// L3698
      }
    }
  }
}

void forward_node214(
  float v3123[64][64][64],
  float v3124[64],
  float v3125[64],
  float v3126[64],
  float v3127[64],
  float v3128[64][64][64]
) {	// L3704
  #pragma HLS resource variable=v3124 core=ram_t2p_bram

  #pragma HLS resource variable=v3125 core=ram_t2p_bram

  #pragma HLS resource variable=v3126 core=ram_t2p_bram

  #pragma HLS resource variable=v3127 core=ram_t2p_bram

  for (int v3129 = 0; v3129 < 512; v3129 += 1) {	// L3705
    #pragma HLS dataflow
    int v3130 = (v3129 % 8);	// L3706
    int v3131 = ((v3129 / 8) % 8);	// L3707
    int v3132 = ((v3129 / 8) / 8);	// L3708
    float v3133[8][8][8];	// L3709
    #pragma HLS resource variable=v3133 core=ram_t2p_bram

    float v3134[8][8][8];	// L3710
    #pragma HLS resource variable=v3134 core=ram_t2p_bram

    forward_node217(v3123, v3134, v3132, v3131, v3130);	// L3711
    forward_node216(v3134, v3126, v3124, v3127, v3125, v3133, v3132);	// L3712
    forward_node215(v3133, v3128, v3132, v3131, v3130);	// L3713
  }
}

void forward_node219(
  float v3135[8][8][8],
  float v3136[64][64][64],
  int v3137,
  int v3138,
  int v3139
) {	// L3717
  #pragma HLS inline
  #pragma HLS array_partition variable=v3135 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3135 cyclic factor=2 dim=3
  #pragma HLS resource variable=v3135 core=ram_t2p_bram

  #pragma HLS array_partition variable=v3136 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3136 cyclic factor=2 dim=3

  for (int v3140 = 0; v3140 < 8; v3140 += 1) {	// L3718
    for (int v3141 = 0; v3141 < 8; v3141 += 2) {	// L3719
      for (int v3142 = 0; v3142 < 8; v3142 += 2) {	// L3720
        #pragma HLS pipeline II=1
        float v3143 = v3135[v3140][v3141][v3142];	// L3721
        v3136[(v3140 + (v3137 * 8))][(v3141 + (v3138 * 8))][(v3142 + (v3139 * 8))] = v3143;	// L3722
        float v3144 = v3135[v3140][v3141][(v3142 + 1)];	// L3723
        v3136[(v3140 + (v3137 * 8))][(v3141 + (v3138 * 8))][((v3142 + (v3139 * 8)) + 1)] = v3144;	// L3724
        float v3145 = v3135[v3140][(v3141 + 1)][v3142];	// L3725
        v3136[(v3140 + (v3137 * 8))][((v3141 + (v3138 * 8)) + 1)][(v3142 + (v3139 * 8))] = v3145;	// L3726
        float v3146 = v3135[v3140][(v3141 + 1)][(v3142 + 1)];	// L3727
        v3136[(v3140 + (v3137 * 8))][((v3141 + (v3138 * 8)) + 1)][((v3142 + (v3139 * 8)) + 1)] = v3146;	// L3728
      }
    }
  }
}

void forward_node220(
  float v3147[8][8],
  float v3148[8],
  float v3149[8][8][8],
  float v3150[8][8][8]
) {	// L3734
  #pragma HLS inline
  #pragma HLS array_partition variable=v3147 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v3147 cyclic factor=2 dim=2
  #pragma HLS resource variable=v3147 core=ram_t2p_bram

  #pragma HLS resource variable=v3148 core=ram_t2p_bram

  #pragma HLS array_partition variable=v3149 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3149 cyclic factor=2 dim=3
  #pragma HLS resource variable=v3149 core=ram_t2p_bram

  #pragma HLS array_partition variable=v3150 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3150 cyclic factor=2 dim=3
  #pragma HLS resource variable=v3150 core=ram_t2p_bram

  for (int v3151 = 0; v3151 < 8; v3151 += 1) {	// L3735
    for (int v3152 = 0; v3152 < 8; v3152 += 2) {	// L3736
      for (int v3153 = 0; v3153 < 8; v3153 += 2) {	// L3737
        #pragma HLS pipeline II=1
        float v3154 = v3147[v3152][v3153];	// L3738
        float v3155 = v3148[v3151];	// L3739
        float v3156 = v3149[v3151][v3152][v3153];	// L3740
        float v3157 = v3154 * v3155;	// L3741
        float v3158 = v3156 + v3157;	// L3742
        v3150[v3151][v3152][v3153] = v3158;	// L3743
        float v3159 = v3147[v3152][(v3153 + 1)];	// L3744
        float v3160 = v3149[v3151][v3152][(v3153 + 1)];	// L3745
        float v3161 = v3159 * v3155;	// L3746
        float v3162 = v3160 + v3161;	// L3747
        v3150[v3151][v3152][(v3153 + 1)] = v3162;	// L3748
        float v3163 = v3147[(v3152 + 1)][v3153];	// L3749
        float v3164 = v3149[v3151][(v3152 + 1)][v3153];	// L3750
        float v3165 = v3163 * v3155;	// L3751
        float v3166 = v3164 + v3165;	// L3752
        v3150[v3151][(v3152 + 1)][v3153] = v3166;	// L3753
        float v3167 = v3147[(v3152 + 1)][(v3153 + 1)];	// L3754
        float v3168 = v3149[v3151][(v3152 + 1)][(v3153 + 1)];	// L3755
        float v3169 = v3167 * v3155;	// L3756
        float v3170 = v3168 + v3169;	// L3757
        v3150[v3151][(v3152 + 1)][(v3153 + 1)] = v3170;	// L3758
      }
    }
  }
}

void forward_node221(
  float v3171[64][64][64],
  float v3172[8][8][8],
  int v3173,
  int v3174,
  int v3175
) {	// L3764
  #pragma HLS inline
  #pragma HLS array_partition variable=v3171 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3171 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v3172 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3172 cyclic factor=2 dim=3
  #pragma HLS resource variable=v3172 core=ram_t2p_bram

  for (int v3176 = 0; v3176 < 8; v3176 += 1) {	// L3765
    for (int v3177 = 0; v3177 < 8; v3177 += 2) {	// L3766
      for (int v3178 = 0; v3178 < 8; v3178 += 2) {	// L3767
        #pragma HLS pipeline II=1
        float v3179 = v3171[(v3176 + (v3173 * 8))][(v3177 + (v3174 * 8))][(v3178 + (v3175 * 8))];	// L3768
        v3172[v3176][v3177][v3178] = v3179;	// L3769
        float v3180 = v3171[(v3176 + (v3173 * 8))][(v3177 + (v3174 * 8))][((v3178 + (v3175 * 8)) + 1)];	// L3770
        v3172[v3176][v3177][(v3178 + 1)] = v3180;	// L3771
        float v3181 = v3171[(v3176 + (v3173 * 8))][((v3177 + (v3174 * 8)) + 1)][(v3178 + (v3175 * 8))];	// L3772
        v3172[v3176][(v3177 + 1)][v3178] = v3181;	// L3773
        float v3182 = v3171[(v3176 + (v3173 * 8))][((v3177 + (v3174 * 8)) + 1)][((v3178 + (v3175 * 8)) + 1)];	// L3774
        v3172[v3176][(v3177 + 1)][(v3178 + 1)] = v3182;	// L3775
      }
    }
  }
}

void forward_node222(
  float v3183[64][3][7][7],
  float v3184[8],
  int v3185,
  int v3186,
  int v3187,
  int v3188
) {	// L3781
  #pragma HLS inline
  #pragma HLS resource variable=v3184 core=ram_t2p_bram

  for (int v3189 = 0; v3189 < 8; v3189 += 1) {	// L3782
    #pragma HLS pipeline II=1
    float v3190 = v3183[(v3189 + (v3188 * 8))][v3185][v3186][v3187];	// L3783
    v3184[v3189] = v3190;	// L3784
  }
}

void forward_node223(
  float v3191[3][128][128],
  float v3192[8][8],
  int v3193,
  int v3194,
  int v3195,
  int v3196,
  int v3197
) {	// L3788
  #pragma HLS inline
  #pragma HLS array_partition variable=v3191 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v3191 cyclic factor=4 dim=3

  #pragma HLS array_partition variable=v3192 cyclic factor=2 dim=1
  #pragma HLS array_partition variable=v3192 cyclic factor=2 dim=2
  #pragma HLS resource variable=v3192 core=ram_t2p_bram

  for (int v3198 = 0; v3198 < 8; v3198 += 2) {	// L3789
    for (int v3199 = 0; v3199 < 8; v3199 += 2) {	// L3790
      #pragma HLS pipeline II=1
      float v3200 = v3191[v3193][((((v3198 * 2) + v3194) + (v3195 * 16)) - 3)][((((v3199 * 2) + v3196) + (v3197 * 16)) - 3)];	// L3791
      v3192[v3198][v3199] = v3200;	// L3792
      float v3201 = v3191[v3193][((((v3198 * 2) + v3194) + (v3195 * 16)) - 3)][((((v3199 * 2) + v3196) + (v3197 * 16)) - 1)];	// L3793
      v3192[v3198][(v3199 + 1)] = v3201;	// L3794
      float v3202 = v3191[v3193][((((v3198 * 2) + v3194) + (v3195 * 16)) - 1)][((((v3199 * 2) + v3196) + (v3197 * 16)) - 3)];	// L3795
      v3192[(v3198 + 1)][v3199] = v3202;	// L3796
      float v3203 = v3191[v3193][((((v3198 * 2) + v3194) + (v3195 * 16)) - 1)][((((v3199 * 2) + v3196) + (v3197 * 16)) - 1)];	// L3797
      v3192[(v3198 + 1)][(v3199 + 1)] = v3203;	// L3798
    }
  }
}

void forward_node218(
  float v3204[64][3][7][7],
  float v3205[3][128][128],
  float v3206[64][64][64],
  float v3207[64][64][64]
) {	// L3803
  #pragma HLS array_partition variable=v3205 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v3205 cyclic factor=4 dim=3

  #pragma HLS array_partition variable=v3206 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3206 cyclic factor=2 dim=3

  #pragma HLS array_partition variable=v3207 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3207 cyclic factor=2 dim=3

  for (int v3208 = 0; v3208 < 75264; v3208 += 1) {	// L3804
    #pragma HLS dataflow
    int v3209 = (v3208 % 8);	// L3805
    int v3210 = ((v3208 / 8) % 8);	// L3806
    int v3211 = (((v3208 / 8) / 8) % 8);	// L3807
    int v3212 = ((((v3208 / 8) / 8) / 8) % 7);	// L3808
    int v3213 = (((((v3208 / 8) / 8) / 8) / 7) % 7);	// L3809
    int v3214 = (((((v3208 / 8) / 8) / 8) / 7) / 7);	// L3810
    float v3215[8][8][8];	// L3811
    #pragma HLS array_partition variable=v3215 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v3215 cyclic factor=2 dim=3
    #pragma HLS resource variable=v3215 core=ram_t2p_bram

    float v3216[8];	// L3812
    #pragma HLS resource variable=v3216 core=ram_t2p_bram

    float v3217[8][8];	// L3813
    #pragma HLS array_partition variable=v3217 cyclic factor=2 dim=1
    #pragma HLS array_partition variable=v3217 cyclic factor=2 dim=2
    #pragma HLS resource variable=v3217 core=ram_t2p_bram

    forward_node223(v3205, v3217, v3214, v3213, v3210, v3212, v3209);	// L3814
    forward_node222(v3204, v3216, v3214, v3213, v3212, v3211);	// L3815
    forward_node221(v3206, v3215, v3211, v3210, v3209);	// L3816
    float v3218[8][8][8];	// L3817
    #pragma HLS array_partition variable=v3218 cyclic factor=2 dim=2
    #pragma HLS array_partition variable=v3218 cyclic factor=2 dim=3
    #pragma HLS resource variable=v3218 core=ram_t2p_bram

    forward_node220(v3217, v3216, v3215, v3218);	// L3818
    forward_node219(v3218, v3207, v3211, v3210, v3209);	// L3819
  }
}

/// This is top function.
void forward(
  float v3219[3][128][128],
  float v3220[1000],
  float v3221[512][512][3][3],
  float v3222[512][512][3][3],
  float v3223[512][256],
  float v3224[512][512][3][3],
  float v3225[512][256][3][3],
  float v3226[256][256][3][3],
  float v3227[256][256][3][3],
  float v3228[256][128],
  float v3229[256][256][3][3],
  float v3230[256][128][3][3],
  float v3231[128][128][3][3],
  float v3232[128][128][3][3],
  float v3233[128][64],
  float v3234[128][128][3][3],
  float v3235[128][64][3][3],
  float v3236[64][64][3][3],
  float v3237[64][64][3][3],
  float v3238[64][64][3][3],
  float v3239[64][64][3][3],
  float v3240[64][3][7][7],
  float v3241[512][1000],
  float v3242[64][64][64],
  float v3243[64][64][64],
  float v3244[64][64][64],
  float v3245[64][64][64],
  float v3246[64][64][64],
  float v3247[64][32][32],
  float v3248[64][32][32],
  float v3249[64][32][32],
  float v3250[64][32][32],
  float v3251[64][32][32],
  float v3252[64][32][32],
  float v3253[64][32][32],
  float v3254[64][32][32],
  float v3255[64][32][32],
  float v3256[64][32][32],
  float v3257[64][32][32],
  float v3258[64][32][32],
  float v3259[64][32][32],
  float v3260[64][32][32],
  float v3261[64][32][32],
  float v3262[64][32][32],
  float v3263[64][32][32],
  float v3264[64][32][32],
  float v3265[64][32][32],
  float v3266[64][32][32],
  float v3267[64][32][32],
  float v3268[64][32][32],
  float v3269[64][32][32],
  float v3270[64][32][32],
  float v3271[64][32][32],
  float v3272[64][32][32],
  float v3273[64][32][32],
  float v3274[64][32][32],
  float v3275[64][32][32],
  float v3276[128][16][16],
  float v3277[128][16][16],
  float v3278[128][16][16],
  float v3279[128][16][16],
  float v3280[128][16][16],
  float v3281[128][16][16],
  float v3282[128][16][16],
  float v3283[128][16][16],
  float v3284[128][16][16],
  float v3285[128][16][16],
  float v3286[128][16][16],
  float v3287[128][16][16],
  float v3288[128][16][16],
  float v3289[128][16][16],
  float v3290[128][16][16],
  float v3291[128][16][16],
  float v3292[128][16][16],
  float v3293[128][16][16],
  float v3294[128][16][16],
  float v3295[128][16][16],
  float v3296[128][16][16],
  float v3297[128][16][16],
  float v3298[128][16][16],
  float v3299[128][16][16],
  float v3300[128][16][16],
  float v3301[128][16][16],
  float v3302[128][16][16],
  float v3303[128][16][16],
  float v3304[128][16][16],
  float v3305[256][8][8],
  float v3306[256][8][8],
  float v3307[256][8][8],
  float v3308[256][8][8],
  float v3309[256][8][8],
  float v3310[256][8][8],
  float v3311[256][8][8],
  float v3312[256][8][8],
  float v3313[256][8][8],
  float v3314[256][8][8],
  float v3315[256][8][8],
  float v3316[256][8][8],
  float v3317[256][8][8],
  float v3318[256][8][8],
  float v3319[256][8][8],
  float v3320[256][8][8],
  float v3321[256][8][8],
  float v3322[256][8][8],
  float v3323[256][8][8],
  float v3324[256][8][8],
  float v3325[256][8][8],
  float v3326[256][8][8],
  float v3327[256][8][8],
  float v3328[256][8][8],
  float v3329[256][8][8],
  float v3330[256][8][8],
  float v3331[256][8][8],
  float v3332[256][8][8],
  float v3333[256][8][8],
  float v3334[512][4][4],
  float v3335[512][4][4],
  float v3336[512][4][4],
  float v3337[512][4][4],
  float v3338[512][4][4],
  float v3339[512][4][4],
  float v3340[512][4][4],
  float v3341[512][4][4],
  float v3342[512][4][4],
  float v3343[512][4][4],
  float v3344[512][4][4],
  float v3345[512][4][4],
  float v3346[512][4][4],
  float v3347[512][4][4],
  float v3348[512][4][4],
  float v3349[512][4][4],
  float v3350[512][4][4],
  float v3351[512][4][4],
  float v3352[512][4][4],
  float v3353[512][4][4],
  float v3354[512][4][4],
  float v3355[512][4][4],
  float v3356[512][4][4],
  float v3357[512][4][4],
  float v3358[512][4][4],
  float v3359[512][4][4],
  float v3360[512][4][4],
  float v3361[512][4][4],
  float v3362[512][5][5],
  float v3363[512][5][5]
) {	// L3823
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface ap_memory port=v3363
  #pragma HLS stable variable=v3363

  #pragma HLS interface ap_memory port=v3362
  #pragma HLS stable variable=v3362

  #pragma HLS interface ap_memory port=v3361
  #pragma HLS stable variable=v3361

  #pragma HLS interface ap_memory port=v3360
  #pragma HLS stable variable=v3360

  #pragma HLS interface ap_memory port=v3359
  #pragma HLS stable variable=v3359
  #pragma HLS array_partition variable=v3359 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3359 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3358
  #pragma HLS stable variable=v3358

  #pragma HLS interface ap_memory port=v3357
  #pragma HLS stable variable=v3357

  #pragma HLS interface ap_memory port=v3356
  #pragma HLS stable variable=v3356
  #pragma HLS array_partition variable=v3356 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3356 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3355
  #pragma HLS stable variable=v3355
  #pragma HLS array_partition variable=v3355 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3355 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3354
  #pragma HLS stable variable=v3354

  #pragma HLS interface ap_memory port=v3353
  #pragma HLS stable variable=v3353
  #pragma HLS array_partition variable=v3353 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3353 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3352
  #pragma HLS stable variable=v3352

  #pragma HLS interface ap_memory port=v3351
  #pragma HLS stable variable=v3351

  #pragma HLS interface ap_memory port=v3350
  #pragma HLS stable variable=v3350

  #pragma HLS interface ap_memory port=v3349
  #pragma HLS stable variable=v3349

  #pragma HLS interface ap_memory port=v3348
  #pragma HLS stable variable=v3348

  #pragma HLS interface ap_memory port=v3347
  #pragma HLS stable variable=v3347
  #pragma HLS array_partition variable=v3347 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3347 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3346
  #pragma HLS stable variable=v3346
  #pragma HLS array_partition variable=v3346 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3346 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3345
  #pragma HLS stable variable=v3345
  #pragma HLS array_partition variable=v3345 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3345 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3344
  #pragma HLS stable variable=v3344

  #pragma HLS interface ap_memory port=v3343
  #pragma HLS stable variable=v3343

  #pragma HLS interface ap_memory port=v3342
  #pragma HLS stable variable=v3342

  #pragma HLS interface ap_memory port=v3341
  #pragma HLS stable variable=v3341

  #pragma HLS interface ap_memory port=v3340
  #pragma HLS stable variable=v3340

  #pragma HLS interface ap_memory port=v3339
  #pragma HLS stable variable=v3339
  #pragma HLS array_partition variable=v3339 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3339 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3338
  #pragma HLS stable variable=v3338
  #pragma HLS array_partition variable=v3338 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3338 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3337
  #pragma HLS stable variable=v3337
  #pragma HLS array_partition variable=v3337 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3337 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3336
  #pragma HLS stable variable=v3336

  #pragma HLS interface ap_memory port=v3335
  #pragma HLS stable variable=v3335
  #pragma HLS array_partition variable=v3335 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3335 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3334
  #pragma HLS stable variable=v3334

  #pragma HLS interface ap_memory port=v3333
  #pragma HLS stable variable=v3333

  #pragma HLS interface ap_memory port=v3332
  #pragma HLS stable variable=v3332

  #pragma HLS interface ap_memory port=v3331
  #pragma HLS stable variable=v3331

  #pragma HLS interface ap_memory port=v3330
  #pragma HLS stable variable=v3330
  #pragma HLS array_partition variable=v3330 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3330 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3329
  #pragma HLS stable variable=v3329

  #pragma HLS interface ap_memory port=v3328
  #pragma HLS stable variable=v3328

  #pragma HLS interface ap_memory port=v3327
  #pragma HLS stable variable=v3327
  #pragma HLS array_partition variable=v3327 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3327 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3326
  #pragma HLS stable variable=v3326
  #pragma HLS array_partition variable=v3326 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3326 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3325
  #pragma HLS stable variable=v3325

  #pragma HLS interface ap_memory port=v3324
  #pragma HLS stable variable=v3324
  #pragma HLS array_partition variable=v3324 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3324 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3323
  #pragma HLS stable variable=v3323

  #pragma HLS interface ap_memory port=v3322
  #pragma HLS stable variable=v3322

  #pragma HLS interface ap_memory port=v3321
  #pragma HLS stable variable=v3321

  #pragma HLS interface ap_memory port=v3320
  #pragma HLS stable variable=v3320

  #pragma HLS interface ap_memory port=v3319
  #pragma HLS stable variable=v3319

  #pragma HLS interface ap_memory port=v3318
  #pragma HLS stable variable=v3318
  #pragma HLS array_partition variable=v3318 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3318 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3317
  #pragma HLS stable variable=v3317
  #pragma HLS array_partition variable=v3317 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3317 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3316
  #pragma HLS stable variable=v3316
  #pragma HLS array_partition variable=v3316 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3316 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3315
  #pragma HLS stable variable=v3315

  #pragma HLS interface ap_memory port=v3314
  #pragma HLS stable variable=v3314

  #pragma HLS interface ap_memory port=v3313
  #pragma HLS stable variable=v3313

  #pragma HLS interface ap_memory port=v3312
  #pragma HLS stable variable=v3312

  #pragma HLS interface ap_memory port=v3311
  #pragma HLS stable variable=v3311

  #pragma HLS interface ap_memory port=v3310
  #pragma HLS stable variable=v3310
  #pragma HLS array_partition variable=v3310 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3310 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3309
  #pragma HLS stable variable=v3309
  #pragma HLS array_partition variable=v3309 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3309 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3308
  #pragma HLS stable variable=v3308
  #pragma HLS array_partition variable=v3308 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3308 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3307
  #pragma HLS stable variable=v3307

  #pragma HLS interface ap_memory port=v3306
  #pragma HLS stable variable=v3306
  #pragma HLS array_partition variable=v3306 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3306 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3305
  #pragma HLS stable variable=v3305

  #pragma HLS interface ap_memory port=v3304
  #pragma HLS stable variable=v3304

  #pragma HLS interface ap_memory port=v3303
  #pragma HLS stable variable=v3303

  #pragma HLS interface ap_memory port=v3302
  #pragma HLS stable variable=v3302

  #pragma HLS interface ap_memory port=v3301
  #pragma HLS stable variable=v3301
  #pragma HLS array_partition variable=v3301 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3301 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3300
  #pragma HLS stable variable=v3300

  #pragma HLS interface ap_memory port=v3299
  #pragma HLS stable variable=v3299

  #pragma HLS interface ap_memory port=v3298
  #pragma HLS stable variable=v3298
  #pragma HLS array_partition variable=v3298 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3298 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3297
  #pragma HLS stable variable=v3297
  #pragma HLS array_partition variable=v3297 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3297 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3296
  #pragma HLS stable variable=v3296

  #pragma HLS interface ap_memory port=v3295
  #pragma HLS stable variable=v3295
  #pragma HLS array_partition variable=v3295 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3295 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3294
  #pragma HLS stable variable=v3294

  #pragma HLS interface ap_memory port=v3293
  #pragma HLS stable variable=v3293

  #pragma HLS interface ap_memory port=v3292
  #pragma HLS stable variable=v3292

  #pragma HLS interface ap_memory port=v3291
  #pragma HLS stable variable=v3291

  #pragma HLS interface ap_memory port=v3290
  #pragma HLS stable variable=v3290

  #pragma HLS interface ap_memory port=v3289
  #pragma HLS stable variable=v3289
  #pragma HLS array_partition variable=v3289 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3289 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3288
  #pragma HLS stable variable=v3288
  #pragma HLS array_partition variable=v3288 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3288 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3287
  #pragma HLS stable variable=v3287
  #pragma HLS array_partition variable=v3287 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3287 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3286
  #pragma HLS stable variable=v3286

  #pragma HLS interface ap_memory port=v3285
  #pragma HLS stable variable=v3285

  #pragma HLS interface ap_memory port=v3284
  #pragma HLS stable variable=v3284

  #pragma HLS interface ap_memory port=v3283
  #pragma HLS stable variable=v3283

  #pragma HLS interface ap_memory port=v3282
  #pragma HLS stable variable=v3282

  #pragma HLS interface ap_memory port=v3281
  #pragma HLS stable variable=v3281
  #pragma HLS array_partition variable=v3281 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3281 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3280
  #pragma HLS stable variable=v3280
  #pragma HLS array_partition variable=v3280 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3280 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3279
  #pragma HLS stable variable=v3279
  #pragma HLS array_partition variable=v3279 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3279 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3278
  #pragma HLS stable variable=v3278

  #pragma HLS interface ap_memory port=v3277
  #pragma HLS stable variable=v3277
  #pragma HLS array_partition variable=v3277 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3277 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3276
  #pragma HLS stable variable=v3276

  #pragma HLS interface ap_memory port=v3275
  #pragma HLS stable variable=v3275

  #pragma HLS interface ap_memory port=v3274
  #pragma HLS stable variable=v3274

  #pragma HLS interface ap_memory port=v3273
  #pragma HLS stable variable=v3273

  #pragma HLS interface ap_memory port=v3272
  #pragma HLS stable variable=v3272
  #pragma HLS array_partition variable=v3272 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3272 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3271
  #pragma HLS stable variable=v3271

  #pragma HLS interface ap_memory port=v3270
  #pragma HLS stable variable=v3270

  #pragma HLS interface ap_memory port=v3269
  #pragma HLS stable variable=v3269
  #pragma HLS array_partition variable=v3269 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3269 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3268
  #pragma HLS stable variable=v3268
  #pragma HLS array_partition variable=v3268 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3268 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3267
  #pragma HLS stable variable=v3267

  #pragma HLS interface ap_memory port=v3266
  #pragma HLS stable variable=v3266
  #pragma HLS array_partition variable=v3266 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3266 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3265
  #pragma HLS stable variable=v3265

  #pragma HLS interface ap_memory port=v3264
  #pragma HLS stable variable=v3264

  #pragma HLS interface ap_memory port=v3263
  #pragma HLS stable variable=v3263
  #pragma HLS array_partition variable=v3263 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3263 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3262
  #pragma HLS stable variable=v3262
  #pragma HLS array_partition variable=v3262 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3262 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3261
  #pragma HLS stable variable=v3261
  #pragma HLS array_partition variable=v3261 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3261 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3260
  #pragma HLS stable variable=v3260

  #pragma HLS interface ap_memory port=v3259
  #pragma HLS stable variable=v3259

  #pragma HLS interface ap_memory port=v3258
  #pragma HLS stable variable=v3258
  #pragma HLS array_partition variable=v3258 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3258 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3257
  #pragma HLS stable variable=v3257
  #pragma HLS array_partition variable=v3257 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3257 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3256
  #pragma HLS stable variable=v3256

  #pragma HLS interface ap_memory port=v3255
  #pragma HLS stable variable=v3255
  #pragma HLS array_partition variable=v3255 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3255 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3254
  #pragma HLS stable variable=v3254
  #pragma HLS array_partition variable=v3254 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3254 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3253
  #pragma HLS stable variable=v3253
  #pragma HLS array_partition variable=v3253 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3253 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3252
  #pragma HLS stable variable=v3252
  #pragma HLS array_partition variable=v3252 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3252 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3251
  #pragma HLS stable variable=v3251
  #pragma HLS array_partition variable=v3251 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3251 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3250
  #pragma HLS stable variable=v3250

  #pragma HLS interface ap_memory port=v3249
  #pragma HLS stable variable=v3249
  #pragma HLS array_partition variable=v3249 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3249 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3248
  #pragma HLS stable variable=v3248

  #pragma HLS interface ap_memory port=v3247
  #pragma HLS stable variable=v3247

  #pragma HLS interface ap_memory port=v3246
  #pragma HLS stable variable=v3246

  #pragma HLS interface ap_memory port=v3245
  #pragma HLS stable variable=v3245

  #pragma HLS interface ap_memory port=v3244
  #pragma HLS stable variable=v3244

  #pragma HLS interface ap_memory port=v3243
  #pragma HLS stable variable=v3243
  #pragma HLS array_partition variable=v3243 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3243 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3242
  #pragma HLS stable variable=v3242
  #pragma HLS array_partition variable=v3242 cyclic factor=2 dim=2
  #pragma HLS array_partition variable=v3242 cyclic factor=2 dim=3


  #pragma HLS interface ap_memory port=v3241
  #pragma HLS stable variable=v3241

  #pragma HLS interface ap_memory port=v3240
  #pragma HLS stable variable=v3240

  #pragma HLS interface ap_memory port=v3239
  #pragma HLS stable variable=v3239

  #pragma HLS interface ap_memory port=v3238
  #pragma HLS stable variable=v3238

  #pragma HLS interface ap_memory port=v3237
  #pragma HLS stable variable=v3237

  #pragma HLS interface ap_memory port=v3236
  #pragma HLS stable variable=v3236

  #pragma HLS interface ap_memory port=v3235
  #pragma HLS stable variable=v3235

  #pragma HLS interface ap_memory port=v3234
  #pragma HLS stable variable=v3234

  #pragma HLS interface ap_memory port=v3233
  #pragma HLS stable variable=v3233

  #pragma HLS interface ap_memory port=v3232
  #pragma HLS stable variable=v3232

  #pragma HLS interface ap_memory port=v3231
  #pragma HLS stable variable=v3231

  #pragma HLS interface ap_memory port=v3230
  #pragma HLS stable variable=v3230

  #pragma HLS interface ap_memory port=v3229
  #pragma HLS stable variable=v3229

  #pragma HLS interface ap_memory port=v3228
  #pragma HLS stable variable=v3228

  #pragma HLS interface ap_memory port=v3227
  #pragma HLS stable variable=v3227

  #pragma HLS interface ap_memory port=v3226
  #pragma HLS stable variable=v3226

  #pragma HLS interface ap_memory port=v3225
  #pragma HLS stable variable=v3225

  #pragma HLS interface ap_memory port=v3224
  #pragma HLS stable variable=v3224

  #pragma HLS interface ap_memory port=v3223
  #pragma HLS stable variable=v3223

  #pragma HLS interface ap_memory port=v3222
  #pragma HLS stable variable=v3222

  #pragma HLS interface ap_memory port=v3221
  #pragma HLS stable variable=v3221

  #pragma HLS interface ap_memory port=v3220
  #pragma HLS stable variable=v3220

  #pragma HLS interface ap_memory port=v3219
  #pragma HLS stable variable=v3219
  #pragma HLS array_partition variable=v3219 cyclic factor=4 dim=2
  #pragma HLS array_partition variable=v3219 cyclic factor=4 dim=3


  float v3509[1000] = {(float)-0.002634, (float)0.003000, (float)0.000656, (float)-0.026909, (float)0.006364, (float)0.013260, (float)-0.011178, (float)0.020639, (float)-0.003637, (float)-0.012325, (float)-0.012629, (float)-0.007206, (float)-0.019321, (float)-0.024960, (float)-0.011885, (float)-0.008326, (float)-0.009575, (float)-0.016658, (float)0.009180, (float)-0.015354, (float)0.007136, (float)0.030737, (float)0.013239, (float)-0.007753, (float)0.004745, (float)0.011175, (float)0.015949, (float)-0.016712, (float)-0.001013, (float)-0.003717, (float)0.006527, (float)-0.012041, (float)0.009043, (float)-0.000833, (float)0.008865, (float)-0.026307, (float)-0.014588, (float)0.002943, (float)0.002972, (float)-0.019125, (float)-0.004792, (float)0.013828, (float)0.009880, (float)-0.018417, (float)0.019734, (float)0.001694, (float)0.012420, (float)-0.005584, (float)-0.010612, (float)0.000398, (float)0.004273, (float)-0.013298, (float)0.020661, (float)0.016963, (float)0.002795, (float)0.000742, (float)0.013168, (float)0.003221, (float)0.010458, (float)0.016511, (float)0.000917, (float)0.003939, (float)-0.005653, (float)0.019372, (float)0.007524, (float)0.013437, (float)-0.013185, (float)-0.010026, (float)0.007192, (float)-0.002317, (float)-0.018895, (float)0.012519, (float)0.001958, (float)0.007384, (float)-0.009666, (float)0.020189, (float)0.007665, (float)0.018529, (float)0.015710, (float)0.018582, (float)-0.006931, (float)0.017090, (float)0.009127, (float)-0.038876, (float)-0.024116, (float)-0.006872, (float)-0.011648, (float)0.007882, (float)0.001805, (float)0.028480, (float)-0.019379, (float)-0.016295, (float)0.010468, (float)-0.013027, (float)-0.008421, (float)-0.029210, (float)-0.002486, (float)-0.008714, (float)-0.016397, (float)-0.009305, (float)-0.015931, (float)-0.026346, (float)-0.001109, (float)0.022589, (float)0.002139, (float)-0.023212, (float)-0.014085, (float)-0.005622, (float)-0.020090, (float)-0.030284, (float)-0.049574, (float)0.023283, (float)0.014954, (float)-0.007750, (float)-0.003948, (float)-0.037629, (float)-0.024220, (float)-0.010194, (float)-0.007704, (float)-0.004131, (float)-0.002955, (float)-0.006217, (float)-0.012076, (float)-0.007017, (float)-0.003895, (float)-0.016953, (float)-0.024585, (float)0.005535, (float)-0.008337, (float)-0.007076, (float)-0.024023, (float)-0.006369, (float)0.000734, (float)0.005288, (float)-0.022181, (float)-0.026972, (float)-0.017990, (float)-0.016393, (float)0.002148, (float)-0.016122, (float)-0.016112, (float)0.006593, (float)-0.020045, (float)0.006415, (float)-0.012601, (float)-0.007624, (float)0.011411, (float)-0.045084, (float)-0.009202, (float)-0.015563, (float)-0.013590, (float)-0.001437, (float)-0.019466, (float)0.020737, (float)-0.010476, (float)0.006323, (float)0.008323, (float)-0.010791, (float)-0.018903, (float)0.005862, (float)-0.002019, (float)0.032436, (float)0.040581, (float)-0.000041, (float)0.010886, (float)-0.016544, (float)-0.000534, (float)-0.022903, (float)0.004629, (float)-0.004840, (float)0.010187, (float)0.017954, (float)0.004821, (float)0.006183, (float)0.014419, (float)-0.012094, (float)-0.008746, (float)0.001949, (float)0.014685, (float)0.012464, (float)0.007052, (float)-0.004178, (float)0.012048, (float)-0.020199, (float)0.009914, (float)0.013978, (float)-0.001032, (float)0.005739, (float)0.001402, (float)0.000601, (float)-0.000558, (float)0.024424, (float)0.023076, (float)-0.014610, (float)0.011185, (float)0.034608, (float)0.016944, (float)0.004330, (float)-0.025606, (float)0.012279, (float)-0.025810, (float)0.008536, (float)0.020437, (float)0.022557, (float)0.022966, (float)0.008842, (float)-0.013894, (float)0.003872, (float)-0.009305, (float)0.023220, (float)-0.014949, (float)0.006926, (float)0.005007, (float)-0.017302, (float)0.001036, (float)-0.010223, (float)-0.009695, (float)0.034534, (float)0.006134, (float)0.011582, (float)-0.020529, (float)-0.021956, (float)0.005311, (float)0.034101, (float)-0.005808, (float)0.029406, (float)-0.008795, (float)-0.005250, (float)-0.019088, (float)0.030350, (float)0.018445, (float)-0.021225, (float)0.018432, (float)0.013832, (float)0.017848, (float)-0.004476, (float)0.035858, (float)0.021762, (float)0.010880, (float)0.040255, (float)-0.002005, (float)-0.003035, (float)0.009329, (float)-0.016304, (float)0.000963, (float)0.018673, (float)-0.016567, (float)0.014964, (float)-0.003721, (float)-0.007673, (float)-0.000008, (float)0.003973, (float)-0.009598, (float)-0.016833, (float)0.000059, (float)-0.006413, (float)0.008298, (float)0.004821, (float)-0.001147, (float)0.004887, (float)0.017349, (float)0.003922, (float)-0.007808, (float)0.016051, (float)0.009880, (float)-0.010144, (float)0.020912, (float)-0.006320, (float)-0.023139, (float)0.001165, (float)0.022468, (float)-0.006695, (float)0.018311, (float)0.014623, (float)-0.011654, (float)-0.014306, (float)0.012974, (float)-0.009687, (float)-0.006235, (float)0.013180, (float)0.006754, (float)0.046418, (float)-0.027962, (float)-0.015111, (float)0.028716, (float)0.009199, (float)-0.005371, (float)-0.006036, (float)-0.007214, (float)-0.009242, (float)0.001854, (float)-0.003108, (float)-0.008400, (float)-0.016766, (float)0.004094, (float)0.006243, (float)-0.001247, (float)-0.012919, (float)0.003582, (float)0.011006, (float)-0.013282, (float)0.002640, (float)0.008995, (float)0.006542, (float)-0.012031, (float)0.017149, (float)0.017949, (float)-0.010581, (float)-0.026962, (float)-0.013564, (float)-0.009717, (float)-0.002118, (float)0.035370, (float)0.018392, (float)0.026676, (float)-0.001059, (float)-0.003395, (float)-0.004884, (float)0.013427, (float)-0.013948, (float)-0.019559, (float)-0.023295, (float)-0.037834, (float)-0.014637, (float)-0.021323, (float)-0.030952, (float)-0.030822, (float)0.001944, (float)0.002864, (float)-0.021198, (float)0.010448, (float)-0.011316, (float)-0.004261, (float)0.022647, (float)-0.012867, (float)-0.011018, (float)0.012336, (float)-0.020057, (float)-0.021837, (float)-0.006807, (float)-0.010488, (float)-0.026298, (float)-0.009958, (float)-0.012966, (float)-0.002483, (float)-0.007094, (float)0.017997, (float)-0.006426, (float)0.007907, (float)-0.012287, (float)0.009818, (float)0.002667, (float)-0.021524, (float)0.002751, (float)-0.009207, (float)-0.017541, (float)-0.001710, (float)-0.014588, (float)0.004425, (float)0.034405, (float)0.012725, (float)0.030885, (float)0.001309, (float)-0.000070, (float)-0.002317, (float)-0.003799, (float)-0.011148, (float)0.017210, (float)-0.006757, (float)-0.000137, (float)-0.008917, (float)-0.016281, (float)-0.004492, (float)0.011332, (float)-0.001591, (float)-0.008819, (float)-0.004940, (float)0.004573, (float)-0.010949, (float)0.012890, (float)-0.006659, (float)-0.002561, (float)0.002796, (float)0.011225, (float)-0.022055, (float)-0.003927, (float)-0.006647, (float)-0.018840, (float)-0.021687, (float)-0.000741, (float)-0.027281, (float)0.005045, (float)-0.020709, (float)-0.034103, (float)-0.022374, (float)-0.016656, (float)-0.027916, (float)-0.009898, (float)0.005525, (float)0.016013, (float)-0.014895, (float)0.003509, (float)0.009000, (float)-0.008398, (float)-0.037479, (float)0.020727, (float)-0.005880, (float)0.009177, (float)-0.020297, (float)-0.007315, (float)-0.001697, (float)-0.001403, (float)0.003223, (float)0.029212, (float)0.012487, (float)-0.020100, (float)0.021170, (float)-0.025300, (float)0.031815, (float)-0.001064, (float)-0.010449, (float)-0.023419, (float)0.014564, (float)0.021245, (float)0.016530, (float)-0.003244, (float)-0.020437, (float)-0.036982, (float)-0.008721, (float)0.005457, (float)0.001105, (float)0.002201, (float)0.002951, (float)-0.000060, (float)0.000558, (float)-0.003691, (float)0.005376, (float)-0.024765, (float)0.009273, (float)0.009608, (float)0.009165, (float)0.009088, (float)0.007484, (float)-0.011946, (float)0.021395, (float)0.027922, (float)0.014692, (float)-0.002496, (float)0.028887, (float)0.013422, (float)0.001717, (float)0.002502, (float)-0.021253, (float)-0.000824, (float)0.004218, (float)0.008598, (float)0.018735, (float)0.008562, (float)-0.008826, (float)0.017462, (float)-0.013693, (float)0.002196, (float)0.010772, (float)0.002869, (float)0.031032, (float)0.008546, (float)-0.014198, (float)-0.002247, (float)0.018740, (float)-0.012905, (float)0.040370, (float)-0.000775, (float)0.001867, (float)0.007279, (float)-0.026508, (float)-0.017609, (float)-0.024142, (float)0.002958, (float)-0.015917, (float)0.001627, (float)0.011132, (float)0.014574, (float)-0.008192, (float)-0.007658, (float)-0.018452, (float)-0.009042, (float)0.004088, (float)0.044482, (float)-0.023664, (float)-0.005255, (float)-0.019529, (float)0.003286, (float)0.005467, (float)-0.004956, (float)0.007680, (float)-0.003303, (float)-0.002625, (float)-0.011094, (float)0.023922, (float)0.018079, (float)-0.018135, (float)0.005220, (float)-0.013559, (float)0.019448, (float)0.010981, (float)0.026869, (float)-0.006680, (float)-0.000894, (float)-0.003492, (float)-0.019667, (float)-0.018511, (float)-0.000763, (float)-0.016382, (float)-0.015862, (float)-0.013717, (float)0.017528, (float)-0.001142, (float)-0.006335, (float)-0.011118, (float)0.013159, (float)-0.023464, (float)0.000280, (float)-0.000363, (float)0.023797, (float)-0.002735, (float)-0.022223, (float)0.013415, (float)0.010443, (float)-0.023512, (float)0.016832, (float)0.004370, (float)-0.013243, (float)-0.002861, (float)0.005421, (float)0.001992, (float)-0.000687, (float)-0.000391, (float)0.017806, (float)0.018391, (float)0.028473, (float)-0.033835, (float)-0.010778, (float)-0.012371, (float)-0.001911, (float)-0.001638, (float)0.017288, (float)-0.003981, (float)-0.015167, (float)-0.010781, (float)0.005381, (float)-0.000339, (float)0.000339, (float)-0.010162, (float)-0.004027, (float)-0.003475, (float)0.004236, (float)-0.001468, (float)0.013207, (float)0.007558, (float)0.000194, (float)0.003005, (float)0.008628, (float)-0.011193, (float)0.038466, (float)-0.026220, (float)-0.020251, (float)-0.006387, (float)0.021906, (float)-0.007340, (float)0.005275, (float)-0.011709, (float)0.008401, (float)0.002853, (float)-0.004722, (float)0.023118, (float)-0.007604, (float)0.002814, (float)-0.011701, (float)-0.004412, (float)0.011846, (float)-0.001763, (float)-0.012260, (float)-0.002121, (float)0.012072, (float)0.006752, (float)-0.000191, (float)-0.025105, (float)0.012693, (float)0.016062, (float)0.008126, (float)0.001386, (float)0.003009, (float)-0.014111, (float)0.019784, (float)-0.000923, (float)-0.018428, (float)0.007806, (float)0.015319, (float)-0.012768, (float)-0.009017, (float)0.018031, (float)0.024853, (float)0.017788, (float)0.008864, (float)-0.009442, (float)-0.001365, (float)0.012932, (float)0.009013, (float)0.016655, (float)-0.005432, (float)0.027480, (float)-0.031781, (float)-0.013331, (float)0.005579, (float)-0.013278, (float)-0.019219, (float)-0.013307, (float)0.004239, (float)0.030246, (float)-0.008199, (float)0.008301, (float)0.018993, (float)0.010643, (float)0.031324, (float)0.019283, (float)0.003364, (float)0.019669, (float)0.002267, (float)-0.019630, (float)0.020147, (float)-0.011433, (float)-0.007607, (float)0.015071, (float)-0.003040, (float)-0.009343, (float)-0.004166, (float)0.002297, (float)-0.005099, (float)-0.014499, (float)-0.027673, (float)-0.038721, (float)0.005425, (float)0.013504, (float)-0.001281, (float)0.037465, (float)0.001515, (float)0.024035, (float)-0.020557, (float)0.009841, (float)0.010352, (float)0.038597, (float)-0.011905, (float)-0.021718, (float)0.008378, (float)0.014691, (float)0.022631, (float)-0.003763, (float)0.015570, (float)-0.009399, (float)0.005354, (float)0.019584, (float)-0.011156, (float)0.015190, (float)0.005462, (float)0.022995, (float)0.029260, (float)-0.001524, (float)0.006601, (float)-0.031939, (float)-0.010486, (float)-0.004462, (float)0.031853, (float)0.013736, (float)0.013561, (float)0.007091, (float)-0.016753, (float)-0.025470, (float)0.019752, (float)0.026715, (float)-0.004686, (float)0.017682, (float)0.032496, (float)0.014553, (float)0.026101, (float)0.011341, (float)-0.002227, (float)0.035237, (float)-0.011892, (float)-0.018683, (float)-0.005525, (float)-0.007073, (float)-0.005267, (float)0.007595, (float)-0.018465, (float)-0.016897, (float)0.010127, (float)0.013006, (float)-0.001825, (float)0.000667, (float)-0.011207, (float)0.013563, (float)-0.018153, (float)-0.026487, (float)0.006065, (float)0.039711, (float)-0.014285, (float)0.018001, (float)-0.014039, (float)-0.018762, (float)-0.011778, (float)-0.016449, (float)0.009042, (float)-0.007273, (float)0.017517, (float)-0.000730, (float)0.010212, (float)0.023785, (float)0.008129, (float)0.008026, (float)0.011922, (float)0.006242, (float)-0.024625, (float)0.029461, (float)-0.014183, (float)-0.018672, (float)-0.014057, (float)0.007987, (float)-0.021081, (float)-0.027560, (float)-0.003569, (float)0.001599, (float)0.009472, (float)0.018272, (float)-0.002374, (float)0.001184, (float)-0.000577, (float)0.008782, (float)0.002780, (float)0.000680, (float)0.015877, (float)-0.007036, (float)0.002549, (float)-0.017925, (float)0.008491, (float)0.004338, (float)0.024508, (float)0.003669, (float)0.010252, (float)-0.013396, (float)0.000457, (float)0.010313, (float)0.015229, (float)0.039907, (float)-0.008081, (float)0.013760, (float)-0.006586, (float)0.006607, (float)-0.031480, (float)0.024665, (float)0.003437, (float)0.020973, (float)0.019384, (float)-0.020880, (float)0.007147, (float)0.010406, (float)0.000022, (float)-0.019182, (float)0.006314, (float)-0.000169, (float)0.008866, (float)-0.004767, (float)-0.014493, (float)0.003218, (float)0.007335, (float)0.020694, (float)-0.000500, (float)0.018820, (float)0.039147, (float)-0.027095, (float)-0.018293, (float)-0.019868, (float)-0.009405, (float)0.004155, (float)0.005384, (float)-0.004666, (float)-0.013019, (float)-0.024452, (float)-0.008923, (float)-0.014603, (float)0.002553, (float)-0.030766, (float)0.011169, (float)-0.006811, (float)-0.007597, (float)-0.009319, (float)0.001492, (float)-0.002343, (float)0.000444, (float)-0.010810, (float)0.008850, (float)-0.021022, (float)-0.008038, (float)-0.010818, (float)-0.006482, (float)-0.002068, (float)0.022326, (float)-0.019234, (float)0.004084, (float)0.000772, (float)0.001723, (float)-0.017454, (float)-0.013190, (float)-0.007411, (float)-0.001755, (float)0.001293, (float)-0.006703, (float)-0.007059, (float)0.006275, (float)-0.018068, (float)-0.009486, (float)-0.020856, (float)0.008960, (float)0.021294, (float)0.017025, (float)0.021015, (float)0.008823, (float)-0.009828, (float)-0.022293, (float)0.024295, (float)-0.011174, (float)-0.007575, (float)0.006118, (float)-0.020653, (float)-0.016264, (float)0.026457, (float)-0.014782, (float)0.018654, (float)0.025488, (float)0.024106, (float)0.004789, (float)0.023329, (float)0.000358, (float)0.025154, (float)0.017094, (float)0.017803, (float)0.024687, (float)0.009008, (float)0.002361, (float)0.026088, (float)-0.014110, (float)-0.000542, (float)0.000895, (float)0.021150, (float)0.004848, (float)-0.030503, (float)-0.007503, (float)-0.033718, (float)-0.028913, (float)0.015691, (float)0.006205, (float)-0.010853, (float)0.019524, (float)-0.016188, (float)0.008989, (float)0.009189, (float)-0.002859, (float)-0.010911, (float)0.010848, (float)0.048784, (float)-0.001969, (float)0.026843, (float)-0.004872, (float)0.013489, (float)-0.014523, (float)-0.027585, (float)0.006123, (float)0.004817, (float)0.002157, (float)-0.037561, (float)0.030775, (float)0.019977, (float)0.018480, (float)0.003037, (float)0.009382, (float)0.000452, (float)0.061650, (float)-0.008642, (float)-0.026913, (float)0.006353, (float)0.007799, (float)0.013180, (float)-0.001667, (float)0.020865, (float)0.009948, (float)0.008814, (float)0.014841, (float)0.003321, (float)0.003634, (float)0.028740, (float)-0.022120, (float)-0.007157, (float)0.010352, (float)0.016433, (float)0.011683, (float)-0.005806, (float)-0.000693, (float)0.026578, (float)0.008797, (float)-0.031689, (float)0.018949, (float)-0.008586, (float)0.034228, (float)-0.015237, (float)-0.005971, (float)0.001107, (float)-0.018394, (float)-0.019246, (float)-0.036361, (float)0.003984, (float)0.041237, (float)0.013816, (float)-0.007330, (float)0.003883, (float)0.002437, (float)-0.021625, (float)-0.014523, (float)-0.000163, (float)0.000626, (float)-0.016798, (float)0.023083, (float)0.009711, (float)-0.008221, (float)0.001160, (float)-0.020983, (float)-0.006654, (float)-0.014097, (float)0.003407, (float)-0.007758, (float)-0.014738, (float)-0.021343, (float)0.005412, (float)0.003975, (float)-0.004619, (float)-0.015462, (float)-0.007623, (float)0.012211, (float)-0.004845, (float)-0.008876, (float)-0.010275, (float)0.007348, (float)-0.006035, (float)0.002366, (float)0.021053, (float)-0.008569, (float)-0.011630, (float)-0.027332, (float)-0.020648, (float)0.004495, (float)-0.018649, (float)-0.011564, (float)0.000459, (float)-0.006183, (float)-0.024435, (float)-0.007119, (float)-0.014394, (float)-0.002354, (float)0.021556, (float)0.022924, (float)-0.013725, (float)0.007779, (float)-0.008551, (float)0.024221, (float)0.003819, (float)0.000709, (float)0.016114, (float)0.025932, (float)0.018108, (float)0.029306, (float)0.001677, (float)-0.003017, (float)0.032015, (float)-0.014034, (float)0.027365, (float)-0.018858, (float)0.002583, (float)0.013498, (float)-0.013502, (float)-0.014940, (float)-0.010904, (float)0.018642, (float)0.004259, (float)-0.016742, (float)-0.012638, (float)-0.045468, (float)-0.005082, (float)-0.025093, (float)0.006785, (float)-0.017868, (float)-0.000782, (float)-0.006345};	// L4114
  #pragma HLS resource variable=v3509 core=ram_t2p_bram

  float v3510[512] = {(float)0.237053, (float)0.343314, (float)0.327930, (float)0.464220, (float)0.223302, (float)0.236983, (float)0.217579, (float)0.379259, (float)0.313998, (float)0.280349, (float)0.243354, (float)0.211605, (float)0.247772, (float)0.243528, (float)0.229751, (float)0.317221, (float)0.272502, (float)0.651092, (float)0.292538, (float)0.228129, (float)0.227865, (float)0.425408, (float)0.234154, (float)0.332787, (float)0.263182, (float)0.217551, (float)0.317980, (float)0.389284, (float)0.138651, (float)0.227351, (float)0.337893, (float)0.076736, (float)0.225347, (float)0.250441, (float)0.198979, (float)0.195098, (float)0.256563, (float)0.325269, (float)0.279655, (float)0.314925, (float)0.237289, (float)0.253293, (float)0.195599, (float)0.323569, (float)0.209272, (float)0.233284, (float)0.230018, (float)0.501893, (float)0.282992, (float)0.188529, (float)0.326359, (float)0.272219, (float)0.236874, (float)0.242986, (float)0.362477, (float)0.216480, (float)0.470004, (float)0.304696, (float)0.367542, (float)0.264145, (float)0.197909, (float)0.266441, (float)0.344828, (float)0.200494, (float)0.245039, (float)0.435114, (float)0.268898, (float)0.163205, (float)0.308723, (float)0.120929, (float)0.215303, (float)0.159195, (float)0.296048, (float)0.142256, (float)0.295127, (float)0.270614, (float)0.200694, (float)0.293873, (float)0.220994, (float)0.224312, (float)0.246470, (float)0.391002, (float)0.459865, (float)0.541699, (float)0.214747, (float)0.346871, (float)0.270255, (float)0.222941, (float)0.364451, (float)0.264704, (float)0.242119, (float)0.249187, (float)0.166577, (float)0.276258, (float)0.256001, (float)0.215109, (float)0.336350, (float)0.276745, (float)0.251579, (float)0.298841, (float)0.262212, (float)0.349904, (float)0.300138, (float)0.390748, (float)0.318424, (float)0.223267, (float)0.264882, (float)0.210972, (float)0.203422, (float)0.275224, (float)0.231400, (float)0.347985, (float)0.223767, (float)0.289213, (float)0.199100, (float)0.292305, (float)0.325925, (float)0.072217, (float)0.303866, (float)0.304128, (float)0.380301, (float)0.256797, (float)0.238229, (float)0.305689, (float)0.265156, (float)0.153213, (float)0.210964, (float)0.256739, (float)0.314824, (float)0.274623, (float)0.183315, (float)0.195023, (float)0.111641, (float)0.227948, (float)0.370550, (float)0.247727, (float)0.199956, (float)0.306049, (float)0.254773, (float)0.246758, (float)0.302787, (float)0.192077, (float)0.295212, (float)0.198045, (float)0.213546, (float)0.158295, (float)0.158563, (float)0.394441, (float)0.235171, (float)0.394657, (float)0.273975, (float)0.286094, (float)0.185610, (float)0.270156, (float)0.298583, (float)0.172837, (float)0.265767, (float)0.269627, (float)0.202776, (float)0.183818, (float)0.317562, (float)0.624552, (float)0.263150, (float)0.385471, (float)0.207381, (float)0.231713, (float)0.417059, (float)0.204437, (float)0.292574, (float)0.350612, (float)0.230526, (float)0.240012, (float)0.141978, (float)0.109323, (float)0.275665, (float)0.325277, (float)0.233393, (float)0.164955, (float)0.402629, (float)0.206574, (float)0.178993, (float)0.303239, (float)0.565806, (float)0.324606, (float)0.383396, (float)0.325397, (float)0.177192, (float)0.290861, (float)0.235024, (float)0.251875, (float)0.196810, (float)0.200341, (float)0.321280, (float)0.480220, (float)0.254314, (float)0.257771, (float)0.328014, (float)0.226978, (float)0.304444, (float)0.227312, (float)0.244713, (float)0.252721, (float)0.413645, (float)0.258828, (float)0.358865, (float)0.268754, (float)0.211535, (float)0.202235, (float)0.318619, (float)0.374031, (float)0.178458, (float)0.207424, (float)0.234567, (float)0.356628, (float)0.262261, (float)0.262033, (float)0.287963, (float)0.146182, (float)0.189597, (float)0.277728, (float)0.185201, (float)0.323953, (float)0.274835, (float)0.216381, (float)0.306597, (float)0.184479, (float)0.399247, (float)0.169518, (float)0.441088, (float)0.281237, (float)0.273039, (float)0.278381, (float)0.186113, (float)0.358933, (float)0.193435, (float)0.332022, (float)0.334961, (float)0.265495, (float)0.273984, (float)0.318533, (float)0.263286, (float)0.245843, (float)0.200339, (float)0.280912, (float)0.304941, (float)0.205005, (float)0.290431, (float)0.238096, (float)0.327801, (float)0.348381, (float)0.429329, (float)0.242223, (float)0.285886, (float)0.186399, (float)0.295433, (float)0.563375, (float)0.208059, (float)0.374326, (float)0.290192, (float)0.382046, (float)0.306874, (float)0.210070, (float)0.275039, (float)0.287817, (float)0.187039, (float)0.301513, (float)0.166114, (float)0.299785, (float)0.310108, (float)0.252193, (float)0.241927, (float)0.175803, (float)0.268132, (float)0.281191, (float)0.149509, (float)0.286774, (float)0.315678, (float)0.258718, (float)0.243671, (float)0.146721, (float)0.541647, (float)0.248959, (float)0.283121, (float)0.278269, (float)0.161389, (float)0.196283, (float)0.203411, (float)0.236409, (float)0.252743, (float)0.157319, (float)0.318354, (float)0.284144, (float)0.161263, (float)0.148857, (float)0.285006, (float)0.162499, (float)0.327670, (float)0.493568, (float)0.277950, (float)0.317778, (float)0.174265, (float)0.215775, (float)0.222169, (float)0.282063, (float)0.426734, (float)0.271349, (float)0.177836, (float)0.306651, (float)0.227027, (float)0.177218, (float)0.389682, (float)0.292299, (float)0.484342, (float)0.234477, (float)0.232725, (float)0.274010, (float)0.269951, (float)0.280366, (float)0.403522, (float)0.150091, (float)0.332921, (float)0.328650, (float)0.280335, (float)0.230856, (float)0.173835, (float)0.326979, (float)0.309747, (float)0.180763, (float)0.238421, (float)0.210695, (float)0.324003, (float)0.334594, (float)0.223584, (float)0.206111, (float)0.268665, (float)0.235953, (float)0.333787, (float)0.269394, (float)0.320256, (float)0.289484, (float)0.188421, (float)0.149104, (float)0.395704, (float)0.516672, (float)0.340672, (float)0.185363, (float)0.181559, (float)0.262563, (float)0.185529, (float)0.221933, (float)0.148225, (float)0.258442, (float)0.245774, (float)0.261618, (float)0.239616, (float)0.240172, (float)0.242331, (float)0.346345, (float)0.273092, (float)0.152377, (float)0.251441, (float)0.276048, (float)0.173379, (float)0.271490, (float)0.405222, (float)0.225249, (float)0.367610, (float)0.307018, (float)0.312668, (float)0.183613, (float)0.432988, (float)0.220315, (float)0.207333, (float)0.280325, (float)0.298398, (float)0.219112, (float)0.327168, (float)0.226721, (float)0.274924, (float)0.305604, (float)0.456600, (float)0.296181, (float)0.352823, (float)0.323551, (float)0.422030, (float)0.271530, (float)0.225554, (float)0.290283, (float)0.182879, (float)0.399409, (float)0.282009, (float)0.247102, (float)0.164738, (float)0.365430, (float)0.450432, (float)0.268513, (float)0.299158, (float)0.282500, (float)0.243481, (float)0.221242, (float)0.430044, (float)0.434159, (float)0.198785, (float)0.286281, (float)0.339768, (float)0.244437, (float)0.290467, (float)0.255927, (float)0.258624, (float)0.170158, (float)0.190607, (float)0.253623, (float)0.297827, (float)0.249819, (float)0.377678, (float)0.225250, (float)0.247197, (float)0.224260, (float)0.173196, (float)0.219388, (float)0.209061, (float)0.282015, (float)0.289757, (float)0.288662, (float)0.329191, (float)0.164362, (float)0.296229, (float)0.327889, (float)0.253544, (float)0.279541, (float)0.223803, (float)0.260670, (float)0.193694, (float)0.267951, (float)0.241841, (float)0.519329, (float)0.250175, (float)0.314686, (float)0.216584, (float)0.231314, (float)0.202680, (float)0.187981, (float)0.218013, (float)0.382618, (float)0.387100, (float)0.235753, (float)0.355567, (float)0.227164, (float)0.327212, (float)0.344226, (float)0.315383, (float)0.199268, (float)0.313538, (float)0.225408, (float)0.304828, (float)0.265832, (float)0.333724, (float)0.267948, (float)0.267009, (float)0.236316, (float)0.434741, (float)0.193061, (float)0.199529, (float)0.207250, (float)0.320201, (float)0.266679, (float)0.230467, (float)0.238302, (float)0.224635, (float)0.256233, (float)0.283666, (float)0.404571, (float)0.278617, (float)0.224333, (float)0.159102, (float)0.192333, (float)0.189382, (float)0.249551, (float)0.114005, (float)0.312817, (float)0.319656, (float)0.353033, (float)0.299884, (float)0.211529, (float)0.471820, (float)0.297907, (float)0.347207, (float)0.288995, (float)0.473978, (float)0.223012, (float)0.362989, (float)0.401476, (float)0.244623, (float)0.189659, (float)0.146001, (float)0.187443, (float)0.273355, (float)0.236632, (float)0.300086, (float)0.235897, (float)0.268770, (float)0.325564, (float)0.274938, (float)0.284832, (float)0.229917, (float)0.300114, (float)0.481755, (float)0.307368, (float)0.316406, (float)0.311434, (float)0.354851, (float)0.285893};	// L4115
  #pragma HLS resource variable=v3510 core=ram_t2p_bram

  float v3511[512] = {(float)1.841924, (float)1.830665, (float)1.765044, (float)1.828764, (float)1.950485, (float)1.802649, (float)1.953560, (float)2.278975, (float)1.766216, (float)1.890236, (float)1.776848, (float)1.774939, (float)1.905522, (float)1.732813, (float)1.876214, (float)1.821127, (float)1.796656, (float)2.342822, (float)1.798536, (float)1.727121, (float)1.791495, (float)1.951208, (float)1.892834, (float)1.901748, (float)1.878427, (float)1.980947, (float)1.856939, (float)1.783045, (float)1.891100, (float)1.885943, (float)1.776434, (float)1.983203, (float)1.838904, (float)1.761562, (float)1.872803, (float)1.875332, (float)1.900778, (float)1.820872, (float)1.703864, (float)1.737742, (float)1.778557, (float)1.694390, (float)1.782871, (float)1.781527, (float)1.759392, (float)1.842761, (float)1.923818, (float)2.087056, (float)1.898015, (float)1.841299, (float)1.847065, (float)1.858356, (float)1.764045, (float)1.845287, (float)1.760567, (float)1.950370, (float)1.961970, (float)1.875451, (float)1.942396, (float)1.873090, (float)1.867402, (float)1.942193, (float)1.874984, (float)1.920790, (float)1.746413, (float)1.855831, (float)1.653877, (float)2.066049, (float)2.029759, (float)1.917397, (float)1.897197, (float)1.758860, (float)1.755070, (float)1.955983, (float)1.790851, (float)1.797098, (float)1.785074, (float)1.773338, (float)1.806138, (float)1.794901, (float)1.816864, (float)1.808875, (float)1.864094, (float)2.154163, (float)1.773894, (float)1.791333, (float)1.802216, (float)1.715502, (float)1.767918, (float)1.770429, (float)1.626641, (float)1.864492, (float)1.907619, (float)1.857551, (float)1.692416, (float)1.802023, (float)1.709990, (float)1.771347, (float)1.857234, (float)1.710326, (float)2.066400, (float)1.905368, (float)1.942188, (float)1.807759, (float)1.741196, (float)1.606143, (float)1.910464, (float)1.894665, (float)1.795414, (float)1.898920, (float)1.823906, (float)1.761872, (float)1.795084, (float)1.814886, (float)1.853915, (float)1.850158, (float)1.709521, (float)2.183057, (float)1.859896, (float)1.825197, (float)1.819331, (float)1.846032, (float)1.796820, (float)1.622874, (float)1.844986, (float)1.829045, (float)1.870638, (float)1.929316, (float)1.688099, (float)1.972520, (float)1.898131, (float)1.892510, (float)1.885120, (float)1.844526, (float)1.976428, (float)2.067389, (float)1.838374, (float)1.841449, (float)1.876244, (float)1.793084, (float)1.713145, (float)1.964417, (float)1.785416, (float)1.936923, (float)1.897213, (float)1.893970, (float)1.870030, (float)1.796662, (float)1.877477, (float)1.940897, (float)1.739148, (float)1.794372, (float)1.967792, (float)1.767767, (float)1.685112, (float)1.941390, (float)1.966295, (float)1.988168, (float)1.791470, (float)1.814119, (float)1.832476, (float)2.120046, (float)1.925580, (float)2.359169, (float)2.030399, (float)1.959444, (float)1.733415, (float)1.904849, (float)1.822145, (float)1.781100, (float)1.908426, (float)1.805347, (float)1.917101, (float)1.964422, (float)1.825584, (float)1.643215, (float)1.917314, (float)1.909381, (float)1.992280, (float)1.796252, (float)1.907689, (float)1.761856, (float)2.172372, (float)1.793135, (float)1.756431, (float)1.888935, (float)1.983240, (float)1.913613, (float)1.803543, (float)1.841859, (float)1.827797, (float)1.805722, (float)1.906258, (float)1.864566, (float)1.784804, (float)1.823047, (float)1.798623, (float)1.709148, (float)1.772385, (float)1.793932, (float)1.761125, (float)1.932543, (float)2.016203, (float)1.729540, (float)2.019571, (float)1.887599, (float)1.832458, (float)1.822480, (float)1.786975, (float)1.916026, (float)1.719693, (float)1.716987, (float)1.913316, (float)1.776954, (float)1.994338, (float)1.838863, (float)1.806998, (float)1.851589, (float)1.785702, (float)1.964764, (float)1.955314, (float)1.923161, (float)1.808591, (float)1.811360, (float)1.714114, (float)1.805774, (float)1.853172, (float)1.925512, (float)1.768152, (float)1.831435, (float)1.849486, (float)1.829582, (float)1.827823, (float)1.881891, (float)1.769794, (float)1.783835, (float)1.780722, (float)1.997370, (float)1.699350, (float)1.948276, (float)1.779277, (float)1.802874, (float)2.221012, (float)1.645528, (float)1.835702, (float)2.170646, (float)1.920386, (float)1.741420, (float)1.780923, (float)1.864751, (float)1.914509, (float)1.884929, (float)1.834563, (float)1.936827, (float)1.816905, (float)2.230180, (float)1.826201, (float)2.065090, (float)1.988802, (float)1.816873, (float)1.846174, (float)1.968134, (float)1.808323, (float)1.859548, (float)1.853903, (float)1.769876, (float)1.900066, (float)1.728547, (float)1.755268, (float)1.892441, (float)1.782869, (float)1.942767, (float)1.872420, (float)1.722780, (float)2.054824, (float)1.773247, (float)1.856061, (float)1.769877, (float)1.926942, (float)1.817067, (float)2.407539, (float)1.725657, (float)1.781858, (float)1.724360, (float)1.852108, (float)1.830183, (float)1.879742, (float)1.761717, (float)1.965020, (float)1.980732, (float)1.710236, (float)1.748623, (float)1.835038, (float)1.991866, (float)1.850481, (float)1.899953, (float)1.826905, (float)1.978724, (float)1.763464, (float)1.607073, (float)1.799797, (float)1.954521, (float)1.734773, (float)1.713990, (float)1.885145, (float)1.798079, (float)1.910030, (float)1.831536, (float)1.786438, (float)1.916499, (float)1.883893, (float)1.901720, (float)1.933395, (float)1.740484, (float)1.766093, (float)1.801504, (float)1.998720, (float)1.762174, (float)1.910710, (float)1.844371, (float)1.712762, (float)1.872555, (float)1.852910, (float)1.926968, (float)1.876938, (float)1.726095, (float)1.839320, (float)1.907536, (float)1.795327, (float)1.824615, (float)1.760533, (float)2.047018, (float)1.922079, (float)1.920474, (float)1.890972, (float)1.766609, (float)1.680096, (float)1.830830, (float)1.884494, (float)1.833918, (float)1.823766, (float)1.761641, (float)1.611358, (float)1.841055, (float)1.743720, (float)1.842344, (float)1.953971, (float)1.746498, (float)1.774127, (float)1.874641, (float)1.885600, (float)1.773955, (float)1.760335, (float)1.768241, (float)1.839620, (float)1.686926, (float)1.808025, (float)1.883639, (float)1.828299, (float)1.834092, (float)1.852179, (float)1.974879, (float)1.870677, (float)1.771900, (float)1.899318, (float)1.810824, (float)1.847982, (float)1.826671, (float)1.873141, (float)1.957556, (float)1.834722, (float)1.950949, (float)1.964092, (float)1.799669, (float)1.765217, (float)1.925279, (float)1.712602, (float)1.755079, (float)1.942656, (float)1.855907, (float)1.916284, (float)1.768074, (float)1.780292, (float)1.850017, (float)1.853547, (float)1.886460, (float)1.759878, (float)2.069206, (float)1.802135, (float)1.707732, (float)1.889028, (float)1.945721, (float)1.851559, (float)1.788223, (float)1.835623, (float)1.847209, (float)1.670773, (float)1.743474, (float)1.908001, (float)1.965260, (float)2.040064, (float)1.893518, (float)1.844987, (float)1.753582, (float)1.773277, (float)1.813463, (float)1.853431, (float)1.936762, (float)1.734786, (float)1.873797, (float)1.963245, (float)1.903311, (float)1.742212, (float)1.784246, (float)1.851613, (float)2.021755, (float)1.704387, (float)1.879297, (float)1.865480, (float)1.851599, (float)1.800211, (float)1.868684, (float)1.846039, (float)1.758945, (float)1.817399, (float)1.982992, (float)1.903378, (float)2.122153, (float)1.846037, (float)1.920870, (float)1.889303, (float)1.942176, (float)1.848934, (float)1.839560, (float)1.995323, (float)2.086452, (float)1.825274, (float)1.769959, (float)1.803460, (float)1.753474, (float)1.892261, (float)1.862024, (float)1.862720, (float)1.726408, (float)1.814006, (float)1.961330, (float)1.881199, (float)1.872904, (float)2.005015, (float)1.709180, (float)1.772615, (float)1.940960, (float)1.838086, (float)1.836619, (float)1.727632, (float)1.879583, (float)1.754793, (float)1.953583, (float)1.806152, (float)1.888337, (float)2.027816, (float)1.877468, (float)1.944567, (float)1.867612, (float)1.842294, (float)1.779833, (float)1.940318, (float)1.837511, (float)2.047343, (float)1.950710, (float)1.833741, (float)1.818419, (float)1.779133, (float)1.899275, (float)1.878100, (float)1.869083, (float)1.849270, (float)1.762251, (float)1.945750, (float)1.756408, (float)1.744830, (float)1.863340, (float)1.686286, (float)1.806160, (float)1.870201, (float)2.004785, (float)1.850444, (float)1.896378, (float)1.948875, (float)1.826359, (float)1.901902, (float)1.819593, (float)1.971231, (float)1.896917, (float)1.865206, (float)1.870860, (float)1.698377, (float)1.867712, (float)1.884631, (float)1.925568, (float)1.861968, (float)1.636646, (float)1.843373, (float)1.750554, (float)1.843847, (float)1.578803, (float)1.931623, (float)1.953484, (float)1.787848, (float)1.735447, (float)2.091964, (float)1.945583};	// L4116
  #pragma HLS resource variable=v3511 core=ram_t2p_bram

  float v3512[512] = {(float)0.012607, (float)0.012795, (float)0.012836, (float)0.013783, (float)0.012441, (float)0.013147, (float)0.014444, (float)0.016157, (float)0.012308, (float)0.011641, (float)0.011995, (float)0.011215, (float)0.012360, (float)0.010052, (float)0.012017, (float)0.013942, (float)0.013127, (float)0.018412, (float)0.012599, (float)0.010842, (float)0.012449, (float)0.013412, (float)0.013765, (float)0.013621, (float)0.012877, (float)0.012920, (float)0.012716, (float)0.012023, (float)0.014954, (float)0.012628, (float)0.012342, (float)0.012743, (float)0.012353, (float)0.011137, (float)0.012544, (float)0.012324, (float)0.014762, (float)0.012765, (float)0.011890, (float)0.010633, (float)0.012721, (float)0.010859, (float)0.012173, (float)0.012396, (float)0.013669, (float)0.012910, (float)0.012683, (float)0.020786, (float)0.012164, (float)0.011582, (float)0.012351, (float)0.013041, (float)0.010677, (float)0.015028, (float)0.011270, (float)0.012414, (float)0.015545, (float)0.014291, (float)0.013015, (float)0.011886, (float)0.011764, (float)0.017043, (float)0.011810, (float)0.014155, (float)0.011373, (float)0.012751, (float)0.010263, (float)0.013853, (float)0.015373, (float)0.012052, (float)0.013857, (float)0.011107, (float)0.011257, (float)0.013424, (float)0.011654, (float)0.013275, (float)0.012267, (float)0.011632, (float)0.011624, (float)0.011821, (float)0.011366, (float)0.014051, (float)0.011627, (float)0.015670, (float)0.010272, (float)0.012229, (float)0.013182, (float)0.011980, (float)0.011770, (float)0.011470, (float)0.009519, (float)0.013395, (float)0.012046, (float)0.013805, (float)0.011765, (float)0.012712, (float)0.011828, (float)0.011465, (float)0.012209, (float)0.011313, (float)0.012856, (float)0.012779, (float)0.012912, (float)0.012170, (float)0.011401, (float)0.011912, (float)0.014428, (float)0.014182, (float)0.013258, (float)0.015467, (float)0.011182, (float)0.011008, (float)0.011993, (float)0.013008, (float)0.013681, (float)0.013370, (float)0.011496, (float)0.016639, (float)0.011855, (float)0.012463, (float)0.012111, (float)0.013034, (float)0.012276, (float)0.009981, (float)0.012321, (float)0.011815, (float)0.012773, (float)0.011727, (float)0.011281, (float)0.013318, (float)0.014112, (float)0.012649, (float)0.010986, (float)0.012151, (float)0.015177, (float)0.013746, (float)0.012133, (float)0.013573, (float)0.012481, (float)0.013561, (float)0.010291, (float)0.012488, (float)0.011282, (float)0.012459, (float)0.013162, (float)0.013991, (float)0.012794, (float)0.015236, (float)0.011475, (float)0.014152, (float)0.011746, (float)0.011560, (float)0.014177, (float)0.011815, (float)0.010985, (float)0.014292, (float)0.013252, (float)0.013664, (float)0.012592, (float)0.011000, (float)0.012848, (float)0.020357, (float)0.012684, (float)0.030875, (float)0.016966, (float)0.013806, (float)0.010805, (float)0.011598, (float)0.012627, (float)0.012273, (float)0.012620, (float)0.011659, (float)0.012492, (float)0.012681, (float)0.012751, (float)0.010844, (float)0.014885, (float)0.013681, (float)0.012171, (float)0.011670, (float)0.013635, (float)0.011769, (float)0.018156, (float)0.011138, (float)0.012628, (float)0.015029, (float)0.015616, (float)0.013909, (float)0.011480, (float)0.011303, (float)0.012139, (float)0.011750, (float)0.015876, (float)0.013656, (float)0.010394, (float)0.012946, (float)0.012624, (float)0.011957, (float)0.013235, (float)0.011265, (float)0.011500, (float)0.012635, (float)0.015489, (float)0.009593, (float)0.014590, (float)0.014663, (float)0.013447, (float)0.012776, (float)0.012686, (float)0.012837, (float)0.010899, (float)0.010744, (float)0.011642, (float)0.011800, (float)0.014411, (float)0.012817, (float)0.011857, (float)0.011787, (float)0.010723, (float)0.014497, (float)0.013106, (float)0.013415, (float)0.013301, (float)0.012676, (float)0.011392, (float)0.012345, (float)0.012399, (float)0.012312, (float)0.013118, (float)0.011824, (float)0.012197, (float)0.012423, (float)0.012812, (float)0.013887, (float)0.011381, (float)0.011887, (float)0.010703, (float)0.015483, (float)0.012125, (float)0.012822, (float)0.011870, (float)0.012034, (float)0.017866, (float)0.010217, (float)0.012893, (float)0.014659, (float)0.012393, (float)0.011389, (float)0.011972, (float)0.012732, (float)0.013072, (float)0.012994, (float)0.012904, (float)0.012871, (float)0.011562, (float)0.014855, (float)0.012064, (float)0.014229, (float)0.012749, (float)0.015885, (float)0.013019, (float)0.012125, (float)0.012583, (float)0.011958, (float)0.013250, (float)0.010867, (float)0.013941, (float)0.010751, (float)0.012574, (float)0.012344, (float)0.010800, (float)0.011533, (float)0.013274, (float)0.011349, (float)0.014498, (float)0.012250, (float)0.012234, (float)0.009903, (float)0.011828, (float)0.012083, (float)0.015951, (float)0.010767, (float)0.011830, (float)0.013225, (float)0.011655, (float)0.011856, (float)0.012551, (float)0.011889, (float)0.012027, (float)0.013007, (float)0.011249, (float)0.012834, (float)0.013066, (float)0.014390, (float)0.013390, (float)0.011616, (float)0.013649, (float)0.013628, (float)0.012689, (float)0.009673, (float)0.013976, (float)0.012583, (float)0.011835, (float)0.012000, (float)0.014709, (float)0.013959, (float)0.012518, (float)0.013496, (float)0.012184, (float)0.014348, (float)0.012852, (float)0.012958, (float)0.013992, (float)0.011663, (float)0.010442, (float)0.011392, (float)0.013530, (float)0.012199, (float)0.013925, (float)0.012103, (float)0.010940, (float)0.012331, (float)0.014481, (float)0.012432, (float)0.011955, (float)0.011361, (float)0.013141, (float)0.013357, (float)0.010638, (float)0.011367, (float)0.011926, (float)0.015863, (float)0.013304, (float)0.012212, (float)0.013405, (float)0.011748, (float)0.010780, (float)0.011570, (float)0.013548, (float)0.013191, (float)0.011238, (float)0.011355, (float)0.011769, (float)0.014076, (float)0.010655, (float)0.011557, (float)0.012413, (float)0.011456, (float)0.011505, (float)0.012523, (float)0.011101, (float)0.011558, (float)0.011428, (float)0.010822, (float)0.011301, (float)0.011807, (float)0.012160, (float)0.012464, (float)0.011496, (float)0.012547, (float)0.014902, (float)0.014602, (float)0.012770, (float)0.012263, (float)0.014406, (float)0.012328, (float)0.011850, (float)0.012651, (float)0.013965, (float)0.014678, (float)0.012244, (float)0.012105, (float)0.012584, (float)0.011940, (float)0.010827, (float)0.013151, (float)0.011509, (float)0.011410, (float)0.013750, (float)0.012897, (float)0.014835, (float)0.012276, (float)0.011962, (float)0.012476, (float)0.013449, (float)0.013318, (float)0.012557, (float)0.016294, (float)0.012615, (float)0.011391, (float)0.010025, (float)0.013623, (float)0.012699, (float)0.011068, (float)0.013502, (float)0.012616, (float)0.011090, (float)0.012450, (float)0.013262, (float)0.012724, (float)0.016779, (float)0.013447, (float)0.011733, (float)0.012772, (float)0.013858, (float)0.012996, (float)0.013405, (float)0.012329, (float)0.012411, (float)0.012495, (float)0.013410, (float)0.011526, (float)0.011101, (float)0.011719, (float)0.012455, (float)0.013591, (float)0.010963, (float)0.012343, (float)0.011039, (float)0.012518, (float)0.011693, (float)0.011699, (float)0.013526, (float)0.012257, (float)0.012567, (float)0.014976, (float)0.012528, (float)0.013554, (float)0.011318, (float)0.012526, (float)0.012288, (float)0.013581, (float)0.011964, (float)0.012445, (float)0.014404, (float)0.016388, (float)0.012757, (float)0.012317, (float)0.011435, (float)0.011726, (float)0.013039, (float)0.012119, (float)0.013858, (float)0.011201, (float)0.012956, (float)0.012951, (float)0.012869, (float)0.012629, (float)0.016022, (float)0.011351, (float)0.011411, (float)0.014286, (float)0.012237, (float)0.012991, (float)0.012031, (float)0.011916, (float)0.010642, (float)0.013661, (float)0.013933, (float)0.012715, (float)0.014832, (float)0.011984, (float)0.012630, (float)0.011473, (float)0.013745, (float)0.011393, (float)0.011939, (float)0.013160, (float)0.013901, (float)0.012581, (float)0.011313, (float)0.010755, (float)0.011584, (float)0.012514, (float)0.012153, (float)0.013047, (float)0.011249, (float)0.011903, (float)0.012367, (float)0.011338, (float)0.012559, (float)0.011869, (float)0.012105, (float)0.010223, (float)0.015068, (float)0.013862, (float)0.010991, (float)0.012486, (float)0.012651, (float)0.010860, (float)0.013252, (float)0.015014, (float)0.012576, (float)0.012565, (float)0.012202, (float)0.014279, (float)0.010337, (float)0.013899, (float)0.013158, (float)0.012282, (float)0.014694, (float)0.010891, (float)0.014762, (float)0.010859, (float)0.010720, (float)0.011243, (float)0.015002, (float)0.012772, (float)0.011317, (float)0.012571, (float)0.016188, (float)0.013516};	// L4117
  #pragma HLS resource variable=v3512 core=ram_t2p_bram

  float v3513[512] = {(float)-0.013953, (float)-0.050031, (float)-0.043323, (float)-0.015914, (float)-0.046112, (float)-0.023473, (float)-0.025429, (float)-0.033783, (float)0.051665, (float)-0.035325, (float)-0.037555, (float)-0.013353, (float)-0.034012, (float)-0.002871, (float)-0.043814, (float)-0.026424, (float)-0.030987, (float)-0.091183, (float)0.015193, (float)-0.039889, (float)0.003516, (float)-0.063124, (float)-0.028069, (float)-0.038168, (float)-0.005747, (float)-0.019639, (float)-0.020180, (float)-0.041006, (float)-0.037068, (float)-0.049702, (float)-0.020847, (float)-0.035155, (float)-0.022799, (float)-0.035089, (float)-0.025835, (float)-0.026871, (float)-0.033089, (float)-0.053280, (float)-0.029554, (float)-0.027207, (float)-0.079410, (float)-0.038662, (float)-0.070901, (float)-0.004792, (float)-0.040081, (float)-0.044518, (float)-0.009688, (float)0.039220, (float)-0.041579, (float)-0.035060, (float)-0.027755, (float)-0.007651, (float)-0.044367, (float)-0.026813, (float)-0.012360, (float)-0.035112, (float)-0.031672, (float)-0.024467, (float)-0.060395, (float)-0.046648, (float)-0.053290, (float)-0.028216, (float)-0.054557, (float)-0.054704, (float)-0.028591, (float)-0.050634, (float)0.000627, (float)-0.051950, (float)-0.051578, (float)-0.036758, (float)-0.030772, (float)-0.039569, (float)-0.019722, (float)-0.043900, (float)-0.044507, (float)-0.053416, (float)-0.043945, (float)-0.023374, (float)-0.051497, (float)-0.044268, (float)-0.039613, (float)0.007135, (float)-0.031644, (float)0.034458, (float)-0.038945, (float)-0.038628, (float)-0.029412, (float)-0.036697, (float)-0.033454, (float)-0.003520, (float)-0.023919, (float)-0.015737, (float)-0.018832, (float)-0.036160, (float)-0.030676, (float)-0.035423, (float)-0.036338, (float)-0.060085, (float)-0.024744, (float)-0.010668, (float)-0.064177, (float)-0.049577, (float)-0.052484, (float)-0.054054, (float)-0.005603, (float)-0.011281, (float)-0.052175, (float)-0.042486, (float)-0.028311, (float)-0.036422, (float)-0.005653, (float)-0.028168, (float)-0.029531, (float)-0.037204, (float)-0.067556, (float)-0.031953, (float)-0.045689, (float)0.045595, (float)-0.030731, (float)-0.023350, (float)-0.032033, (float)-0.015946, (float)-0.043791, (float)0.004781, (float)0.000364, (float)-0.031503, (float)-0.023126, (float)-0.037362, (float)-0.046890, (float)-0.027394, (float)-0.056134, (float)-0.049824, (float)-0.043524, (float)-0.027824, (float)-0.070928, (float)-0.060755, (float)-0.050579, (float)-0.028704, (float)-0.026274, (float)-0.033160, (float)-0.008618, (float)-0.039907, (float)-0.035256, (float)-0.086042, (float)-0.026312, (float)-0.032020, (float)-0.014972, (float)-0.011586, (float)-0.038802, (float)-0.067321, (float)-0.045730, (float)-0.013368, (float)-0.029202, (float)-0.015672, (float)-0.055057, (float)-0.047705, (float)-0.026542, (float)-0.013914, (float)-0.019433, (float)-0.036511, (float)-0.051134, (float)-0.043920, (float)-0.033364, (float)0.041027, (float)-0.032706, (float)-0.000820, (float)-0.019290, (float)-0.047500, (float)-0.044132, (float)-0.038169, (float)-0.024048, (float)-0.041317, (float)-0.020381, (float)-0.039825, (float)-0.043505, (float)-0.013664, (float)-0.030153, (float)-0.032162, (float)-0.051351, (float)-0.043963, (float)-0.001310, (float)-0.020620, (float)-0.041151, (float)-0.074645, (float)-0.013569, (float)-0.042029, (float)-0.036559, (float)-0.055496, (float)-0.024927, (float)-0.043322, (float)-0.025386, (float)-0.005925, (float)0.009121, (float)-0.046321, (float)-0.049662, (float)-0.013392, (float)-0.049198, (float)-0.022978, (float)-0.013565, (float)-0.044778, (float)-0.041518, (float)-0.053186, (float)-0.062418, (float)-0.033953, (float)-0.018224, (float)-0.047834, (float)-0.025541, (float)-0.016724, (float)-0.066561, (float)-0.055189, (float)-0.029102, (float)0.001744, (float)-0.028708, (float)-0.047356, (float)-0.039403, (float)-0.052492, (float)-0.048850, (float)-0.033341, (float)-0.027483, (float)-0.061212, (float)-0.045193, (float)-0.035821, (float)0.008330, (float)-0.017342, (float)0.001103, (float)-0.062373, (float)-0.024603, (float)-0.072638, (float)0.021412, (float)-0.075782, (float)-0.032325, (float)-0.024850, (float)-0.022635, (float)-0.008499, (float)-0.024250, (float)0.006696, (float)-0.016815, (float)-0.057800, (float)-0.040070, (float)-0.025381, (float)-0.026095, (float)-0.036127, (float)-0.041404, (float)-0.047404, (float)-0.001727, (float)-0.058207, (float)-0.062922, (float)-0.041185, (float)-0.027714, (float)-0.026942, (float)-0.019350, (float)-0.002645, (float)-0.046726, (float)-0.044284, (float)-0.021652, (float)-0.048506, (float)-0.040399, (float)-0.035572, (float)-0.046054, (float)-0.031532, (float)-0.032670, (float)-0.043606, (float)-0.053407, (float)-0.029613, (float)-0.065983, (float)-0.036677, (float)-0.015673, (float)-0.041916, (float)0.007200, (float)-0.026574, (float)-0.029427, (float)-0.046752, (float)-0.016942, (float)-0.017730, (float)-0.031830, (float)-0.020861, (float)-0.042271, (float)-0.037406, (float)-0.038363, (float)-0.043299, (float)0.007099, (float)-0.016024, (float)-0.011558, (float)-0.013649, (float)-0.019286, (float)-0.005381, (float)-0.038080, (float)-0.040525, (float)-0.037919, (float)-0.038805, (float)-0.075134, (float)-0.013963, (float)0.002917, (float)-0.018857, (float)-0.018787, (float)-0.018889, (float)-0.039999, (float)-0.047723, (float)-0.015847, (float)-0.038556, (float)-0.003824, (float)-0.041886, (float)-0.022822, (float)-0.027051, (float)-0.012578, (float)-0.012243, (float)-0.010389, (float)-0.030908, (float)-0.049441, (float)-0.057127, (float)-0.043721, (float)-0.029496, (float)-0.028846, (float)-0.034347, (float)-0.033969, (float)-0.018485, (float)-0.020259, (float)-0.006510, (float)-0.032701, (float)-0.012320, (float)-0.042393, (float)-0.044799, (float)-0.025397, (float)-0.037255, (float)-0.030126, (float)-0.033043, (float)0.011193, (float)-0.034983, (float)-0.031577, (float)-0.036480, (float)-0.010290, (float)0.028495, (float)-0.036363, (float)-0.004754, (float)-0.057458, (float)-0.017357, (float)-0.009672, (float)-0.026240, (float)-0.032853, (float)-0.001027, (float)-0.056348, (float)-0.019716, (float)-0.063584, (float)0.011124, (float)-0.029937, (float)-0.025287, (float)-0.039320, (float)0.002933, (float)-0.048010, (float)-0.031270, (float)-0.035449, (float)-0.029562, (float)-0.017369, (float)-0.050306, (float)-0.045947, (float)-0.017834, (float)-0.006932, (float)-0.003274, (float)-0.048955, (float)-0.035086, (float)-0.024075, (float)-0.021984, (float)-0.007037, (float)-0.037546, (float)-0.031797, (float)-0.024134, (float)-0.033352, (float)-0.032565, (float)-0.016909, (float)-0.022290, (float)-0.039201, (float)-0.010906, (float)-0.056042, (float)-0.048766, (float)-0.030840, (float)-0.034916, (float)-0.038825, (float)-0.043324, (float)-0.056847, (float)0.010243, (float)-0.046514, (float)-0.010452, (float)-0.002154, (float)-0.044856, (float)-0.036066, (float)-0.017105, (float)-0.005236, (float)-0.028570, (float)-0.050284, (float)-0.065926, (float)-0.016846, (float)-0.031785, (float)-0.062677, (float)-0.055734, (float)-0.035885, (float)-0.014798, (float)-0.043455, (float)-0.013114, (float)-0.035012, (float)-0.021125, (float)-0.073286, (float)-0.041934, (float)-0.017432, (float)-0.035229, (float)0.035735, (float)-0.030858, (float)-0.041892, (float)-0.035874, (float)0.001710, (float)-0.018882, (float)-0.032570, (float)-0.068433, (float)-0.002356, (float)-0.045632, (float)0.001103, (float)-0.079181, (float)-0.015563, (float)-0.022546, (float)-0.019013, (float)-0.047557, (float)-0.015476, (float)-0.045174, (float)-0.025230, (float)-0.031111, (float)-0.017632, (float)-0.011193, (float)-0.016986, (float)-0.063783, (float)-0.025520, (float)0.009365, (float)-0.024927, (float)-0.052760, (float)-0.062665, (float)-0.024147, (float)-0.054109, (float)-0.064714, (float)-0.019359, (float)-0.014110, (float)-0.045960, (float)-0.042290, (float)-0.029651, (float)-0.011331, (float)-0.049568, (float)-0.045198, (float)-0.046655, (float)-0.039152, (float)-0.072373, (float)-0.028233, (float)-0.033341, (float)0.000050, (float)-0.024896, (float)-0.004391, (float)-0.057027, (float)-0.016781, (float)-0.041684, (float)-0.043151, (float)-0.011696, (float)-0.032351, (float)-0.009796, (float)-0.010248, (float)-0.031722, (float)-0.031369, (float)-0.043368, (float)-0.041376, (float)-0.017700, (float)-0.065839, (float)-0.044930, (float)-0.030312, (float)-0.049151, (float)-0.034421, (float)-0.029603, (float)-0.027210, (float)-0.021330, (float)-0.036309, (float)-0.023335, (float)-0.040678, (float)-0.012841, (float)-0.030524, (float)-0.061549, (float)-0.046466, (float)-0.062686, (float)-0.036889, (float)-0.039056, (float)-0.034740, (float)-0.006074, (float)-0.019422, (float)-0.042960, (float)-0.037847, (float)-0.077137, (float)-0.029199, (float)-0.054336, (float)-0.025864, (float)-0.032088, (float)-0.050267, (float)-0.026562, (float)-0.019347, (float)-0.012865, (float)-0.037129, (float)-0.033561, (float)-0.056942, (float)-0.023849, (float)-0.007705, (float)-0.058456, (float)0.000136, (float)-0.066229, (float)-0.029168, (float)-0.003950, (float)-0.052685, (float)-0.019541, (float)-0.058807, (float)-0.045790, (float)-0.030423};	// L4118
  #pragma HLS resource variable=v3513 core=ram_t2p_bram

  float v3514[512] = {(float)-0.166778, (float)-0.301884, (float)-0.218710, (float)-0.291665, (float)-0.197052, (float)-0.232542, (float)-0.186879, (float)-0.185719, (float)-0.247446, (float)-0.162930, (float)-0.244761, (float)-0.250772, (float)-0.189473, (float)-0.265120, (float)-0.325032, (float)-0.381098, (float)-0.295301, (float)-0.496279, (float)-0.029429, (float)-0.272426, (float)-0.200655, (float)-0.222042, (float)-0.294523, (float)-0.257905, (float)-0.515237, (float)-0.199378, (float)-0.501575, (float)-0.273609, (float)-0.452842, (float)-0.396767, (float)-0.228079, (float)-0.177167, (float)-0.129269, (float)-0.265454, (float)-0.325217, (float)-0.323211, (float)-0.333732, (float)-0.190141, (float)-0.069213, (float)-0.219598, (float)-0.213196, (float)-0.256509, (float)-0.164644, (float)-0.156687, (float)-0.208673, (float)-0.217784, (float)-0.248026, (float)-0.276723, (float)-0.307089, (float)-0.198761, (float)-0.198528, (float)-0.023470, (float)-0.245765, (float)-0.415635, (float)-0.165957, (float)-0.192324, (float)-0.332811, (float)-0.148053, (float)-0.304728, (float)-0.227722, (float)-0.318194, (float)-0.274427, (float)-0.164250, (float)-0.336509, (float)-0.405015, (float)-0.208197, (float)-0.062082, (float)-0.267069, (float)-0.280936, (float)-0.218496, (float)-0.214800, (float)-0.446515, (float)-0.337594, (float)-0.321295, (float)-0.292084, (float)-0.199835, (float)-0.336912, (float)-0.209215, (float)-0.283081, (float)-0.289337, (float)-0.171927, (float)-0.218890, (float)-0.401572, (float)-0.248410, (float)-0.207006, (float)-0.384924, (float)-0.375318, (float)-0.587427, (float)-0.163706, (float)-0.174781, (float)-0.221691, (float)-0.506717, (float)-0.249581, (float)-0.211673, (float)-0.429063, (float)-0.194439, (float)-0.308921, (float)-0.262051, (float)-0.409624, (float)-0.060217, (float)-0.200947, (float)-0.131576, (float)-0.333645, (float)-0.262714, (float)-0.232000, (float)-0.090958, (float)-0.156032, (float)-0.288905, (float)-0.328569, (float)-0.162802, (float)-0.512772, (float)-0.203649, (float)-0.172572, (float)-0.184377, (float)-0.228476, (float)-0.192538, (float)-0.343170, (float)-0.092912, (float)-0.313844, (float)-0.191236, (float)-0.192553, (float)-0.034224, (float)-0.326845, (float)-0.169908, (float)-0.082844, (float)-0.241710, (float)-0.206921, (float)-0.386983, (float)-0.220995, (float)-0.286666, (float)-0.052590, (float)-0.309189, (float)-0.065540, (float)-0.259427, (float)-0.216036, (float)-0.506234, (float)-0.290463, (float)-0.212464, (float)-0.312382, (float)-0.212780, (float)-0.194570, (float)-0.251969, (float)-0.547520, (float)-0.232130, (float)-0.335038, (float)-0.347271, (float)-0.215781, (float)-0.360343, (float)-0.075889, (float)-0.147226, (float)-0.032748, (float)-0.140364, (float)-0.312821, (float)-0.306322, (float)-0.112002, (float)-0.266357, (float)-0.269969, (float)-0.311171, (float)-0.151908, (float)-0.384272, (float)-0.064518, (float)-0.237345, (float)-0.422661, (float)-0.254578, (float)-0.161118, (float)-0.234975, (float)-0.152435, (float)-0.349375, (float)-0.345312, (float)-0.208057, (float)-0.091781, (float)-0.202487, (float)-0.124616, (float)-0.253308, (float)-0.276754, (float)-0.315624, (float)-0.253035, (float)-0.395692, (float)-0.098060, (float)-0.125728, (float)-0.369679, (float)-0.233297, (float)-0.366438, (float)-0.282851, (float)-0.432020, (float)-0.083630, (float)-0.158317, (float)-0.239466, (float)-0.181846, (float)-0.440792, (float)-0.237558, (float)-0.445011, (float)-0.323199, (float)-0.278685, (float)-0.185759, (float)-0.213734, (float)0.048095, (float)-0.105792, (float)-0.109336, (float)-0.203505, (float)-0.049555, (float)-0.211673, (float)-0.159833, (float)-0.238937, (float)-0.282979, (float)-0.287788, (float)-0.340562, (float)-0.255988, (float)-0.446779, (float)-0.244449, (float)-0.249191, (float)-0.222163, (float)-0.279186, (float)-0.300518, (float)-0.418048, (float)-0.256758, (float)-0.187175, (float)-0.026989, (float)-0.264514, (float)-0.187262, (float)-0.302245, (float)-0.340033, (float)-0.180271, (float)-0.180987, (float)-0.207890, (float)-0.477471, (float)-0.204706, (float)-0.187821, (float)-0.450425, (float)-0.251550, (float)-0.165694, (float)-0.276547, (float)-0.232948, (float)-0.244570, (float)-0.295637, (float)-0.416283, (float)-0.281643, (float)-0.157050, (float)-0.219938, (float)-0.212529, (float)-0.168377, (float)0.035650, (float)-0.091396, (float)-0.448422, (float)-0.353491, (float)-0.221241, (float)-0.254963, (float)-0.250917, (float)-0.270208, (float)-0.059870, (float)-0.350520, (float)-0.292434, (float)-0.236047, (float)-0.233904, (float)-0.125887, (float)-0.259706, (float)-0.226746, (float)-0.197800, (float)-0.137064, (float)-0.012892, (float)-0.117458, (float)-0.252714, (float)-0.309939, (float)-0.323135, (float)-0.346767, (float)-0.355307, (float)-0.353698, (float)-0.331463, (float)-0.371257, (float)-0.109127, (float)-0.095854, (float)-0.025802, (float)-0.275570, (float)-0.280846, (float)-0.201234, (float)-0.281223, (float)-0.199129, (float)-0.394824, (float)-0.225674, (float)-0.246888, (float)-0.421136, (float)-0.210989, (float)-0.466971, (float)-0.306896, (float)-0.354851, (float)-0.233702, (float)-0.061225, (float)-0.132124, (float)-0.296824, (float)-0.187037, (float)-0.231554, (float)-0.068646, (float)-0.311342, (float)-0.289526, (float)-0.314944, (float)-0.268616, (float)-0.208079, (float)-0.209587, (float)-0.301078, (float)-0.181040, (float)-0.022727, (float)-0.387303, (float)-0.266473, (float)-0.022525, (float)-0.297290, (float)-0.097272, (float)-0.297961, (float)-0.321932, (float)-0.292626, (float)-0.319557, (float)-0.433212, (float)-0.198044, (float)-0.211702, (float)-0.230248, (float)-0.098036, (float)-0.234449, (float)-0.215439, (float)-0.292083, (float)-0.035002, (float)-0.336064, (float)-0.261990, (float)-0.218833, (float)-0.156628, (float)-0.179497, (float)-0.272610, (float)-0.410262, (float)0.041331, (float)-0.150667, (float)-0.255214, (float)-0.313730, (float)-0.246626, (float)-0.296126, (float)-0.093810, (float)-0.148112, (float)-0.212855, (float)-0.547962, (float)-0.291468, (float)-0.280187, (float)-0.507714, (float)-0.130599, (float)-0.186227, (float)-0.239996, (float)-0.436204, (float)-0.301735, (float)-0.163260, (float)-0.344721, (float)-0.104740, (float)-0.284646, (float)-0.124401, (float)-0.303603, (float)-0.240359, (float)-0.233264, (float)-0.249393, (float)-0.186588, (float)-0.329376, (float)-0.167748, (float)-0.254014, (float)-0.129459, (float)-0.051167, (float)-0.196646, (float)-0.280118, (float)-0.170163, (float)-0.187942, (float)-0.184979, (float)-0.327354, (float)-0.036948, (float)-0.297911, (float)-0.261205, (float)-0.188904, (float)-0.327026, (float)-0.137659, (float)-0.278723, (float)-0.220099, (float)-0.241671, (float)-0.283364, (float)-0.055538, (float)-0.253775, (float)-0.103968, (float)-0.266035, (float)-0.164432, (float)-0.172312, (float)-0.267215, (float)-0.279710, (float)-0.421407, (float)-0.037770, (float)-0.238588, (float)-0.349763, (float)-0.243517, (float)-0.434770, (float)-0.255393, (float)-0.171896, (float)-0.283597, (float)-0.331604, (float)-0.278738, (float)-0.287927, (float)-0.263989, (float)-0.055961, (float)-0.178914, (float)-0.419529, (float)-0.215160, (float)0.056671, (float)-0.235948, (float)-0.224888, (float)-0.091073, (float)-0.264409, (float)-0.387462, (float)-0.331677, (float)-0.141506, (float)-0.342510, (float)-0.001966, (float)-0.194066, (float)-0.282105, (float)-0.280897, (float)-0.096453, (float)-0.184142, (float)-0.297108, (float)-0.017309, (float)-0.304341, (float)-0.301250, (float)-0.172939, (float)-0.187185, (float)-0.268301, (float)-0.203277, (float)-0.305852, (float)-0.293887, (float)-0.216347, (float)-0.188940, (float)-0.258145, (float)-0.229595, (float)-0.206601, (float)-0.346224, (float)-0.429798, (float)-0.260050, (float)-0.309454, (float)-0.179973, (float)-0.011597, (float)-0.212382, (float)-0.255211, (float)-0.052268, (float)-0.221629, (float)-0.260463, (float)-0.213373, (float)-0.286738, (float)-0.255577, (float)-0.227501, (float)-0.343706, (float)-0.169841, (float)-0.155950, (float)-0.411996, (float)-0.206748, (float)-0.115915, (float)-0.240838, (float)-0.309345, (float)-0.262110, (float)-0.259264, (float)-0.013475, (float)-0.309890, (float)-0.217898, (float)-0.276555, (float)-0.240024, (float)-0.393405, (float)0.007223, (float)-0.298154, (float)-0.092989, (float)-0.216617, (float)-0.163475, (float)-0.182670, (float)-0.230832, (float)-0.252491, (float)-0.099116, (float)-0.232465, (float)-0.293801, (float)-0.247992, (float)-0.093388, (float)-0.191098, (float)-0.377190, (float)-0.336867, (float)-0.160648, (float)-0.275220, (float)-0.300454, (float)-0.137182, (float)-0.299033, (float)-0.215551, (float)-0.262224, (float)-0.316047, (float)-0.134242, (float)-0.290303, (float)-0.386548, (float)-0.291577, (float)-0.324283, (float)-0.205084, (float)-0.265611, (float)-0.235949, (float)-0.150819, (float)-0.106305, (float)-0.359518, (float)-0.231204, (float)-0.304596, (float)-0.417826, (float)-0.027616, (float)-0.220362, (float)-0.242648, (float)-0.161557, (float)-0.478941, (float)-0.171309, (float)-0.280208, (float)-0.230503, (float)-0.432674, (float)-0.241290, (float)-0.186202, (float)-0.148583, (float)-0.150677};	// L4119
  #pragma HLS resource variable=v3514 core=ram_t2p_bram

  float v3515[512] = {(float)0.258653, (float)0.307254, (float)0.259460, (float)0.322322, (float)0.266240, (float)0.265176, (float)0.257515, (float)0.266003, (float)0.276571, (float)0.241378, (float)0.304453, (float)0.285334, (float)0.282124, (float)0.287992, (float)0.309360, (float)0.344413, (float)0.315457, (float)0.412925, (float)0.210974, (float)0.290261, (float)0.249561, (float)0.260129, (float)0.296687, (float)0.303279, (float)0.415180, (float)0.271899, (float)0.366112, (float)0.325054, (float)0.389843, (float)0.334617, (float)0.275327, (float)0.271204, (float)0.241399, (float)0.335072, (float)0.339427, (float)0.316734, (float)0.336015, (float)0.266617, (float)0.210885, (float)0.270491, (float)0.258746, (float)0.307003, (float)0.271974, (float)0.231582, (float)0.288480, (float)0.288359, (float)0.295524, (float)0.305746, (float)0.304270, (float)0.259641, (float)0.267296, (float)0.192930, (float)0.313607, (float)0.359308, (float)0.262186, (float)0.293081, (float)0.329468, (float)0.251390, (float)0.320831, (float)0.279846, (float)0.325917, (float)0.293923, (float)0.238955, (float)0.310520, (float)0.347136, (float)0.281158, (float)0.214759, (float)0.299651, (float)0.306111, (float)0.273967, (float)0.279072, (float)0.379026, (float)0.359156, (float)0.324715, (float)0.299542, (float)0.273507, (float)0.335615, (float)0.270266, (float)0.325483, (float)0.312741, (float)0.278306, (float)0.270219, (float)0.390034, (float)0.294182, (float)0.289862, (float)0.346078, (float)0.343229, (float)0.468488, (float)0.263406, (float)0.255341, (float)0.301866, (float)0.396060, (float)0.274202, (float)0.299477, (float)0.385829, (float)0.278531, (float)0.321156, (float)0.310891, (float)0.364163, (float)0.219310, (float)0.264327, (float)0.233275, (float)0.315063, (float)0.310163, (float)0.293578, (float)0.237394, (float)0.241894, (float)0.297588, (float)0.333537, (float)0.261866, (float)0.398381, (float)0.272133, (float)0.271832, (float)0.267829, (float)0.275722, (float)0.244483, (float)0.350807, (float)0.217371, (float)0.330944, (float)0.265293, (float)0.256439, (float)0.174837, (float)0.317694, (float)0.275073, (float)0.206674, (float)0.290497, (float)0.276154, (float)0.332903, (float)0.273802, (float)0.322444, (float)0.219853, (float)0.299732, (float)0.220557, (float)0.321267, (float)0.276035, (float)0.392709, (float)0.317351, (float)0.269806, (float)0.298773, (float)0.260953, (float)0.255023, (float)0.278819, (float)0.444529, (float)0.286156, (float)0.360626, (float)0.327896, (float)0.286877, (float)0.329384, (float)0.224351, (float)0.233813, (float)0.175445, (float)0.231830, (float)0.318585, (float)0.332225, (float)0.225506, (float)0.304087, (float)0.283712, (float)0.327611, (float)0.239207, (float)0.366756, (float)0.197145, (float)0.294643, (float)0.361256, (float)0.273633, (float)0.255369, (float)0.286021, (float)0.251089, (float)0.348963, (float)0.325344, (float)0.293427, (float)0.202669, (float)0.258012, (float)0.220020, (float)0.308927, (float)0.307405, (float)0.333202, (float)0.294267, (float)0.337549, (float)0.233025, (float)0.261063, (float)0.338264, (float)0.283743, (float)0.354584, (float)0.309302, (float)0.379091, (float)0.219729, (float)0.264785, (float)0.282971, (float)0.258664, (float)0.358847, (float)0.283009, (float)0.397142, (float)0.319417, (float)0.306608, (float)0.275414, (float)0.264732, (float)0.096991, (float)0.218234, (float)0.233432, (float)0.262442, (float)0.182925, (float)0.293257, (float)0.274660, (float)0.300114, (float)0.299629, (float)0.310712, (float)0.325552, (float)0.293957, (float)0.390091, (float)0.279043, (float)0.303045, (float)0.283846, (float)0.301035, (float)0.304372, (float)0.347879, (float)0.308721, (float)0.261120, (float)0.195816, (float)0.294136, (float)0.255841, (float)0.288934, (float)0.314836, (float)0.251640, (float)0.266390, (float)0.286150, (float)0.393963, (float)0.293256, (float)0.278149, (float)0.379642, (float)0.302151, (float)0.258293, (float)0.302115, (float)0.278377, (float)0.296740, (float)0.299419, (float)0.385593, (float)0.327699, (float)0.258716, (float)0.253909, (float)0.282389, (float)0.263356, (float)0.148927, (float)0.220537, (float)0.392898, (float)0.340055, (float)0.271699, (float)0.278920, (float)0.291713, (float)0.317740, (float)0.199225, (float)0.368365, (float)0.311954, (float)0.320131, (float)0.281020, (float)0.230217, (float)0.277928, (float)0.286487, (float)0.285787, (float)0.271287, (float)0.160112, (float)0.249581, (float)0.289524, (float)0.315395, (float)0.344278, (float)0.328518, (float)0.344432, (float)0.325108, (float)0.323501, (float)0.337509, (float)0.228236, (float)0.212838, (float)0.179536, (float)0.307721, (float)0.300513, (float)0.277469, (float)0.305415, (float)0.291415, (float)0.353504, (float)0.287099, (float)0.266912, (float)0.396121, (float)0.267444, (float)0.389827, (float)0.318337, (float)0.324219, (float)0.278895, (float)0.191084, (float)0.256855, (float)0.342734, (float)0.246424, (float)0.277846, (float)0.209767, (float)0.301859, (float)0.314531, (float)0.327072, (float)0.291418, (float)0.261850, (float)0.264285, (float)0.303916, (float)0.252017, (float)0.209921, (float)0.364308, (float)0.291455, (float)0.195748, (float)0.328570, (float)0.235546, (float)0.320984, (float)0.298192, (float)0.338831, (float)0.344965, (float)0.371618, (float)0.289784, (float)0.284586, (float)0.280502, (float)0.221948, (float)0.290975, (float)0.268068, (float)0.316252, (float)0.196427, (float)0.317611, (float)0.309220, (float)0.270613, (float)0.250465, (float)0.250810, (float)0.316617, (float)0.358251, (float)0.156263, (float)0.260824, (float)0.289224, (float)0.340060, (float)0.289098, (float)0.312587, (float)0.217215, (float)0.245887, (float)0.265121, (float)0.405211, (float)0.298572, (float)0.302591, (float)0.377266, (float)0.226189, (float)0.267520, (float)0.289994, (float)0.375936, (float)0.320086, (float)0.256677, (float)0.344324, (float)0.234774, (float)0.305689, (float)0.234677, (float)0.327660, (float)0.293774, (float)0.274554, (float)0.280529, (float)0.242139, (float)0.359016, (float)0.262216, (float)0.277316, (float)0.239642, (float)0.213411, (float)0.272716, (float)0.298438, (float)0.274433, (float)0.259093, (float)0.262776, (float)0.356810, (float)0.200910, (float)0.321951, (float)0.286774, (float)0.256133, (float)0.311339, (float)0.213783, (float)0.313627, (float)0.274466, (float)0.304581, (float)0.304164, (float)0.197231, (float)0.281454, (float)0.254222, (float)0.298339, (float)0.261308, (float)0.266769, (float)0.314248, (float)0.293041, (float)0.379950, (float)0.196589, (float)0.294770, (float)0.336325, (float)0.271314, (float)0.362477, (float)0.290850, (float)0.269547, (float)0.311078, (float)0.324165, (float)0.300873, (float)0.323066, (float)0.305076, (float)0.201172, (float)0.271588, (float)0.369198, (float)0.269375, (float)0.148108, (float)0.285847, (float)0.281887, (float)0.239137, (float)0.286653, (float)0.346642, (float)0.343100, (float)0.236494, (float)0.335651, (float)0.168539, (float)0.292454, (float)0.309248, (float)0.312699, (float)0.188345, (float)0.256073, (float)0.308609, (float)0.173237, (float)0.298885, (float)0.323458, (float)0.269283, (float)0.263033, (float)0.291337, (float)0.278647, (float)0.312437, (float)0.309797, (float)0.269525, (float)0.240332, (float)0.290607, (float)0.278380, (float)0.265381, (float)0.348534, (float)0.393850, (float)0.303310, (float)0.314508, (float)0.262222, (float)0.153991, (float)0.278961, (float)0.296657, (float)0.195435, (float)0.263214, (float)0.295734, (float)0.258132, (float)0.323063, (float)0.279482, (float)0.285947, (float)0.313898, (float)0.248818, (float)0.240414, (float)0.371402, (float)0.264856, (float)0.226700, (float)0.287824, (float)0.346230, (float)0.306279, (float)0.317971, (float)0.172571, (float)0.315303, (float)0.262468, (float)0.301976, (float)0.299645, (float)0.363247, (float)0.154106, (float)0.319185, (float)0.219963, (float)0.289393, (float)0.262160, (float)0.253383, (float)0.293457, (float)0.320769, (float)0.223056, (float)0.274329, (float)0.302337, (float)0.282941, (float)0.239436, (float)0.250616, (float)0.351159, (float)0.336579, (float)0.266591, (float)0.293011, (float)0.304928, (float)0.232099, (float)0.339687, (float)0.272655, (float)0.289975, (float)0.314638, (float)0.268182, (float)0.309351, (float)0.371775, (float)0.338693, (float)0.320203, (float)0.242282, (float)0.274548, (float)0.296551, (float)0.250019, (float)0.232927, (float)0.341928, (float)0.292804, (float)0.353586, (float)0.373931, (float)0.193541, (float)0.267000, (float)0.284598, (float)0.258259, (float)0.378281, (float)0.282597, (float)0.292868, (float)0.272787, (float)0.364453, (float)0.277048, (float)0.275636, (float)0.252264, (float)0.249964};	// L4120
  #pragma HLS resource variable=v3515 core=ram_t2p_bram

  float v3516[512] = {(float)0.157272, (float)0.121494, (float)0.110890, (float)0.138332, (float)0.154231, (float)0.119160, (float)0.137997, (float)0.156451, (float)0.103958, (float)0.122691, (float)0.121031, (float)0.108789, (float)0.150741, (float)0.122900, (float)0.118188, (float)0.103053, (float)0.123558, (float)0.141964, (float)0.272493, (float)0.113742, (float)0.128986, (float)0.119658, (float)0.120304, (float)0.120511, (float)0.133857, (float)0.146808, (float)0.091806, (float)0.142326, (float)0.128061, (float)0.105257, (float)0.140615, (float)0.143751, (float)0.169360, (float)0.159124, (float)0.121500, (float)0.126739, (float)0.149052, (float)0.154392, (float)0.151626, (float)0.120618, (float)0.140859, (float)0.148686, (float)0.133982, (float)0.121194, (float)0.169162, (float)0.135213, (float)0.119971, (float)0.134204, (float)0.113415, (float)0.125448, (float)0.121302, (float)0.179269, (float)0.132751, (float)0.129523, (float)0.158171, (float)0.149059, (float)0.118247, (float)0.142966, (float)0.120525, (float)0.128163, (float)0.137333, (float)0.103394, (float)0.120583, (float)0.087091, (float)0.084795, (float)0.133024, (float)0.200593, (float)0.126079, (float)0.123615, (float)0.103434, (float)0.126255, (float)0.135451, (float)0.141095, (float)0.122359, (float)0.136957, (float)0.159438, (float)0.132475, (float)0.121734, (float)0.141482, (float)0.133773, (float)0.161217, (float)0.126054, (float)0.138424, (float)0.148697, (float)0.136529, (float)0.115158, (float)0.111243, (float)0.210655, (float)0.150067, (float)0.149925, (float)0.146573, (float)0.124652, (float)0.130291, (float)0.179599, (float)0.139915, (float)0.138198, (float)0.126833, (float)0.144613, (float)0.119749, (float)0.181381, (float)0.135587, (float)0.155462, (float)0.119060, (float)0.151802, (float)0.148132, (float)0.167735, (float)0.166350, (float)0.137500, (float)0.130187, (float)0.157453, (float)0.104428, (float)0.148859, (float)0.132261, (float)0.165668, (float)0.136275, (float)0.164993, (float)0.138821, (float)0.157225, (float)0.109712, (float)0.153218, (float)0.111765, (float)0.158229, (float)0.123995, (float)0.137109, (float)0.147888, (float)0.144130, (float)0.120230, (float)0.107165, (float)0.124514, (float)0.144111, (float)0.170445, (float)0.105546, (float)0.172847, (float)0.152914, (float)0.116989, (float)0.107541, (float)0.131471, (float)0.138915, (float)0.105366, (float)0.139452, (float)0.145897, (float)0.113597, (float)0.132929, (float)0.135730, (float)0.153182, (float)0.120458, (float)0.130249, (float)0.106744, (float)0.168344, (float)0.129868, (float)0.185800, (float)0.121044, (float)0.135292, (float)0.128703, (float)0.135367, (float)0.124730, (float)0.132676, (float)0.145161, (float)0.128291, (float)0.138383, (float)0.147979, (float)0.138992, (float)0.125923, (float)0.123036, (float)0.161289, (float)0.156189, (float)0.129665, (float)0.144354, (float)0.121738, (float)0.148620, (float)0.125385, (float)0.137104, (float)0.177627, (float)0.125947, (float)0.126593, (float)0.143159, (float)0.114476, (float)0.112578, (float)0.151409, (float)0.162312, (float)0.112443, (float)0.140079, (float)0.129008, (float)0.109462, (float)0.129889, (float)0.143210, (float)0.153370, (float)0.138683, (float)0.141045, (float)0.099450, (float)0.138254, (float)0.138848, (float)0.109361, (float)0.141240, (float)0.145026, (float)0.134450, (float)0.180661, (float)0.166874, (float)0.179685, (float)0.144648, (float)0.124261, (float)0.150043, (float)0.196581, (float)0.142786, (float)0.117790, (float)0.132922, (float)0.123891, (float)0.148714, (float)0.144703, (float)0.123294, (float)0.122973, (float)0.142068, (float)0.138037, (float)0.126073, (float)0.104146, (float)0.136178, (float)0.125905, (float)0.197598, (float)0.111434, (float)0.117451, (float)0.091696, (float)0.118450, (float)0.130511, (float)0.141301, (float)0.146123, (float)0.131051, (float)0.197174, (float)0.135347, (float)0.106754, (float)0.134551, (float)0.184436, (float)0.134739, (float)0.128100, (float)0.132872, (float)0.115101, (float)0.136478, (float)0.155266, (float)0.157809, (float)0.109249, (float)0.153827, (float)0.143292, (float)0.161629, (float)0.156723, (float)0.119411, (float)0.120206, (float)0.109810, (float)0.120180, (float)0.111734, (float)0.128541, (float)0.174715, (float)0.141909, (float)0.125527, (float)0.180091, (float)0.136425, (float)0.138315, (float)0.141775, (float)0.139527, (float)0.164408, (float)0.185390, (float)0.191718, (float)0.147939, (float)0.127644, (float)0.131170, (float)0.126823, (float)0.106023, (float)0.137908, (float)0.116774, (float)0.126028, (float)0.112418, (float)0.156467, (float)0.120242, (float)0.209883, (float)0.133611, (float)0.131967, (float)0.152136, (float)0.153782, (float)0.159980, (float)0.119557, (float)0.140178, (float)0.116429, (float)0.140495, (float)0.102665, (float)0.124602, (float)0.113414, (float)0.112752, (float)0.123284, (float)0.162008, (float)0.192566, (float)0.176427, (float)0.125148, (float)0.107817, (float)0.188905, (float)0.120710, (float)0.118803, (float)0.113520, (float)0.118226, (float)0.127486, (float)0.130172, (float)0.122628, (float)0.132900, (float)0.251585, (float)0.138885, (float)0.133268, (float)0.192137, (float)0.115032, (float)0.157397, (float)0.136418, (float)0.134507, (float)0.135265, (float)0.143946, (float)0.130495, (float)0.136269, (float)0.255849, (float)0.127721, (float)0.161987, (float)0.140434, (float)0.145994, (float)0.143567, (float)0.217126, (float)0.120137, (float)0.137316, (float)0.130616, (float)0.131082, (float)0.130820, (float)0.128702, (float)0.116088, (float)0.216788, (float)0.148036, (float)0.109485, (float)0.144219, (float)0.102065, (float)0.114707, (float)0.149040, (float)0.164266, (float)0.119442, (float)0.105308, (float)0.120292, (float)0.104201, (float)0.104647, (float)0.157188, (float)0.119718, (float)0.141703, (float)0.129102, (float)0.143758, (float)0.152957, (float)0.142382, (float)0.147007, (float)0.117802, (float)0.134479, (float)0.116054, (float)0.118435, (float)0.113276, (float)0.114869, (float)0.133755, (float)0.157416, (float)0.173171, (float)0.122215, (float)0.131741, (float)0.165122, (float)0.159154, (float)0.125511, (float)0.171438, (float)0.138623, (float)0.127446, (float)0.170997, (float)0.160217, (float)0.142664, (float)0.119088, (float)0.142298, (float)0.124406, (float)0.124245, (float)0.134550, (float)0.122764, (float)0.157830, (float)0.138354, (float)0.187025, (float)0.114211, (float)0.169193, (float)0.132511, (float)0.141570, (float)0.149899, (float)0.125941, (float)0.120167, (float)0.124617, (float)0.174438, (float)0.161133, (float)0.127741, (float)0.122790, (float)0.127565, (float)0.110531, (float)0.170789, (float)0.136660, (float)0.122042, (float)0.117236, (float)0.132416, (float)0.118440, (float)0.249330, (float)0.140252, (float)0.126854, (float)0.125446, (float)0.158869, (float)0.122826, (float)0.154812, (float)0.162049, (float)0.126960, (float)0.121890, (float)0.121928, (float)0.144863, (float)0.113283, (float)0.180020, (float)0.195894, (float)0.132988, (float)0.131381, (float)0.106672, (float)0.120703, (float)0.108573, (float)0.142950, (float)0.111283, (float)0.137490, (float)0.165181, (float)0.129301, (float)0.126071, (float)0.151297, (float)0.126862, (float)0.133357, (float)0.121345, (float)0.111666, (float)0.136574, (float)0.139949, (float)0.130967, (float)0.145197, (float)0.147552, (float)0.133029, (float)0.117296, (float)0.150844, (float)0.138939, (float)0.123110, (float)0.138138, (float)0.165599, (float)0.111851, (float)0.138641, (float)0.112593, (float)0.137264, (float)0.112204, (float)0.123050, (float)0.095599, (float)0.140241, (float)0.156471, (float)0.140808, (float)0.120633, (float)0.139597, (float)0.123611, (float)0.162952, (float)0.135291, (float)0.130257, (float)0.208375, (float)0.124216, (float)0.112209, (float)0.131368, (float)0.132996, (float)0.139019, (float)0.169519, (float)0.134225, (float)0.160857, (float)0.167455, (float)0.144514, (float)0.142181, (float)0.156618, (float)0.162929, (float)0.168533, (float)0.133698, (float)0.129143, (float)0.131512, (float)0.164832, (float)0.118704, (float)0.131188, (float)0.134356, (float)0.158196, (float)0.108468, (float)0.114835, (float)0.134079, (float)0.175744, (float)0.139813, (float)0.116924, (float)0.136767, (float)0.197171, (float)0.113234, (float)0.129328, (float)0.135916, (float)0.115879, (float)0.120353, (float)0.114077, (float)0.151214, (float)0.157829, (float)0.148324, (float)0.109571, (float)0.136292, (float)0.153027, (float)0.141014, (float)0.181838, (float)0.121173, (float)0.130402, (float)0.141520, (float)0.120097, (float)0.156104, (float)0.114908, (float)0.125043, (float)0.112289, (float)0.116106, (float)0.146591, (float)0.141853, (float)0.171405};	// L4121
  #pragma HLS resource variable=v3516 core=ram_t2p_bram

  float v3517[512] = {(float)-0.616304, (float)-0.710955, (float)-0.454402, (float)-0.614255, (float)-0.787494, (float)-0.528893, (float)-0.621433, (float)-0.582421, (float)-0.406652, (float)-0.525627, (float)-0.512498, (float)-0.533722, (float)-0.565790, (float)-0.684483, (float)-0.514649, (float)-0.632307, (float)-0.539150, (float)-0.683786, (float)-0.657745, (float)-0.471635, (float)-0.524932, (float)-0.405884, (float)-0.602798, (float)-0.524639, (float)-0.891306, (float)-0.652838, (float)-0.504806, (float)-0.500840, (float)-0.506658, (float)-0.597285, (float)-0.552446, (float)-0.638255, (float)-0.678162, (float)-0.726262, (float)-0.572461, (float)-0.645593, (float)-0.713844, (float)-0.614577, (float)-0.534616, (float)-0.517699, (float)-0.459262, (float)-0.661813, (float)-0.511263, (float)-0.581029, (float)-0.624362, (float)-0.553085, (float)-0.556308, (float)-0.548126, (float)-0.608908, (float)-0.462584, (float)-0.731059, (float)-0.663177, (float)-0.631639, (float)-0.738078, (float)-0.613689, (float)-0.623704, (float)-0.496449, (float)-0.448909, (float)-0.642752, (float)-0.596825, (float)-0.553037, (float)-0.382175, (float)-0.610950, (float)-0.453029, (float)-0.467932, (float)-0.522124, (float)-0.635563, (float)-0.486059, (float)-0.777206, (float)-0.509635, (float)-0.578227, (float)-0.705387, (float)-0.666734, (float)-0.624430, (float)-0.729190, (float)-0.731116, (float)-0.655683, (float)-0.687150, (float)-0.676692, (float)-0.556686, (float)-0.605893, (float)-0.667994, (float)-0.716171, (float)-0.610517, (float)-0.577846, (float)-0.650139, (float)-0.624793, (float)-1.075139, (float)-0.676370, (float)-0.727725, (float)-0.583836, (float)-0.517192, (float)-0.657830, (float)-0.676537, (float)-0.782756, (float)-0.521314, (float)-0.585204, (float)-0.605134, (float)-0.617385, (float)-0.649530, (float)-0.712327, (float)-0.693985, (float)-0.553193, (float)-0.659540, (float)-0.540599, (float)-0.793111, (float)-0.571818, (float)-0.584746, (float)-0.613227, (float)-0.693451, (float)-0.686847, (float)-0.669434, (float)-0.532752, (float)-0.643606, (float)-0.681984, (float)1.094305, (float)-0.721794, (float)-0.552714, (float)-0.636416, (float)-0.703609, (float)-0.495384, (float)-0.724163, (float)-0.597713, (float)-0.491831, (float)-0.612987, (float)-0.566158, (float)-0.560591, (float)-0.521596, (float)-0.622898, (float)-0.663222, (float)-0.687799, (float)-0.528395, (float)-0.676746, (float)-0.687652, (float)-0.490881, (float)-0.564638, (float)-0.531156, (float)-0.594634, (float)-0.476138, (float)-0.478973, (float)-0.437675, (float)-0.507542, (float)-0.775500, (float)-0.630304, (float)-0.713768, (float)-0.635128, (float)-0.486655, (float)-0.694944, (float)-0.584056, (float)-0.531543, (float)-0.774950, (float)-0.414342, (float)-0.627546, (float)-0.736624, (float)-0.433248, (float)-0.526515, (float)-0.559585, (float)-0.705374, (float)-0.570816, (float)-0.682786, (float)-0.568887, (float)-0.637050, (float)-0.688830, (float)-0.657953, (float)-0.704505, (float)-0.588115, (float)-0.566433, (float)-0.726806, (float)-0.453258, (float)-0.589214, (float)-0.375950, (float)-0.560585, (float)-0.419610, (float)-0.622340, (float)-0.585825, (float)-0.623298, (float)-0.559863, (float)-0.612563, (float)-0.609163, (float)-0.580848, (float)-0.601551, (float)-0.678778, (float)-0.625062, (float)-0.595292, (float)-0.611051, (float)-0.553896, (float)-0.673447, (float)-0.727241, (float)-0.609655, (float)-0.531932, (float)-0.615366, (float)-0.661623, (float)-0.525051, (float)-0.720417, (float)-0.514133, (float)-0.532666, (float)0.423257, (float)-0.552948, (float)-0.524175, (float)-0.659346, (float)-0.451149, (float)-0.634925, (float)-0.345611, (float)-0.663090, (float)-0.591956, (float)-0.597252, (float)-0.621118, (float)-0.711954, (float)-0.631364, (float)-0.503959, (float)-0.651598, (float)-0.654962, (float)-0.714219, (float)-0.580766, (float)-0.678856, (float)-0.620104, (float)-0.406141, (float)-0.592477, (float)-0.555808, (float)-0.557123, (float)-0.488908, (float)-0.536469, (float)-0.581187, (float)-0.434032, (float)-0.651491, (float)-0.765928, (float)-0.725813, (float)-0.600297, (float)-0.548644, (float)-0.573570, (float)-0.673882, (float)-0.791803, (float)-0.703981, (float)-0.729587, (float)-0.540516, (float)-0.765787, (float)-0.797869, (float)-0.434029, (float)-0.495118, (float)-0.607839, (float)-0.594747, (float)-0.499707, (float)-0.627690, (float)-0.779225, (float)-0.564906, (float)-0.536798, (float)-0.548710, (float)-0.448432, (float)-0.582722, (float)-0.659951, (float)-0.621732, (float)-0.481428, (float)-0.535148, (float)-0.716983, (float)-0.616804, (float)-0.511115, (float)-0.524308, (float)-0.533465, (float)-0.580659, (float)-0.554720, (float)-0.650323, (float)-0.458660, (float)-0.520870, (float)-0.606180, (float)-0.617250, (float)-0.551609, (float)-0.600615, (float)-0.623892, (float)-0.547826, (float)-0.416296, (float)-0.400634, (float)-0.652903, (float)-0.629601, (float)-0.628480, (float)-0.695389, (float)-0.696171, (float)-0.619967, (float)-0.610122, (float)-0.740638, (float)-0.554527, (float)-0.611820, (float)-0.456072, (float)-0.701886, (float)-0.492771, (float)-0.674054, (float)-0.535626, (float)-0.508433, (float)-0.576041, (float)-0.781385, (float)-0.606688, (float)-0.564861, (float)-0.706667, (float)-0.524017, (float)-0.546131, (float)-0.611009, (float)-0.493108, (float)-0.583555, (float)-0.562198, (float)-0.645880, (float)-0.630781, (float)-0.902502, (float)-0.785391, (float)-0.565273, (float)-0.729284, (float)-0.592601, (float)-0.559185, (float)-0.744047, (float)-0.748236, (float)-0.666430, (float)-0.704776, (float)-0.743941, (float)-0.587821, (float)-0.802787, (float)-0.619217, (float)-0.461556, (float)-0.585491, (float)-0.674150, (float)-0.788763, (float)-0.665089, (float)-0.368269, (float)-0.613433, (float)-0.484249, (float)-0.368227, (float)-0.653625, (float)-0.763135, (float)-0.609199, (float)-0.483914, (float)-0.650656, (float)-0.390514, (float)-0.686241, (float)-0.440122, (float)-0.652524, (float)-0.565567, (float)-0.671697, (float)-0.742093, (float)-0.722871, (float)-0.467401, (float)-0.575119, (float)-0.551060, (float)-0.558588, (float)-0.555832, (float)-0.495576, (float)-0.740304, (float)-0.685487, (float)-0.348640, (float)-0.653714, (float)-0.484410, (float)-0.634893, (float)-0.559822, (float)-0.594751, (float)-0.481156, (float)-0.533360, (float)-0.597617, (float)-0.626149, (float)-0.677230, (float)-0.751566, (float)-0.549316, (float)-0.351552, (float)-0.500901, (float)-0.687211, (float)-0.596026, (float)-0.701455, (float)-0.701849, (float)-0.616725, (float)-0.646680, (float)-0.662618, (float)-0.628021, (float)-0.568340, (float)-0.437611, (float)-0.575540, (float)-0.433710, (float)-0.723970, (float)-0.643754, (float)-0.746185, (float)-0.583211, (float)-0.434603, (float)-0.483143, (float)-0.708712, (float)-0.629189, (float)-0.574825, (float)-0.645158, (float)-0.625728, (float)-0.539591, (float)-0.618591, (float)-0.635195, (float)-0.804003, (float)-0.686286, (float)-0.509029, (float)-0.578320, (float)-0.463522, (float)-0.662571, (float)-0.605672, (float)-0.545510, (float)-0.690327, (float)-0.425566, (float)-0.628013, (float)-0.600466, (float)-0.625441, (float)-0.656136, (float)-0.631090, (float)0.069986, (float)-0.538626, (float)-0.630297, (float)-0.612624, (float)-0.562514, (float)-0.717746, (float)-0.714968, (float)-0.443519, (float)-0.503402, (float)-0.460118, (float)-0.713433, (float)-0.604455, (float)-0.617452, (float)-0.131146, (float)-0.460610, (float)-0.527855, (float)-0.470304, (float)-0.617029, (float)-0.539948, (float)-0.653345, (float)-0.489337, (float)-0.605371, (float)-0.582756, (float)-0.432120, (float)-0.558990, (float)-0.612080, (float)-0.432217, (float)-0.565227, (float)-0.555233, (float)-0.552695, (float)-0.701409, (float)-0.830658, (float)-0.723646, (float)-0.580912, (float)-0.588886, (float)-0.308734, (float)-0.508060, (float)-0.625120, (float)-0.505165, (float)-0.597686, (float)-0.482370, (float)-0.581055, (float)-0.569211, (float)-0.551578, (float)-0.736489, (float)-0.549753, (float)-0.632732, (float)-0.506880, (float)-0.737591, (float)-0.609342, (float)-0.448911, (float)-0.414976, (float)-0.824387, (float)-0.646708, (float)-0.652089, (float)-0.790253, (float)-0.550589, (float)-0.592843, (float)-0.561587, (float)-0.524387, (float)-0.768650, (float)-0.446418, (float)-0.575646, (float)-0.663503, (float)-0.833324, (float)-0.584874, (float)-0.649196, (float)-0.674701, (float)-0.591840, (float)-0.700442, (float)-0.570885, (float)-0.678234, (float)-0.567685, (float)-0.527412, (float)-0.603221, (float)-0.732851, (float)-0.763933, (float)-0.714234, (float)-0.543401, (float)-0.595375, (float)-0.366722, (float)-0.835745, (float)-0.595797, (float)-0.552825, (float)-0.704469, (float)-0.730476, (float)-0.583419, (float)-0.688803, (float)-0.629495, (float)-0.467073, (float)-0.495003, (float)-0.388563, (float)-0.705246, (float)-0.742846, (float)-0.439654, (float)-0.619706, (float)-0.604399, (float)-0.721261, (float)-0.772576, (float)-0.570528, (float)-0.534292, (float)-0.605621, (float)-0.505945, (float)-0.718137, (float)-0.681156, (float)-0.640036, (float)-0.627977, (float)-0.675497, (float)-0.664535, (float)-0.670920, (float)-0.678671, (float)-0.770007};	// L4122
  #pragma HLS resource variable=v3517 core=ram_t2p_bram

  float v3518[512] = {(float)0.169410, (float)0.336753, (float)0.299325, (float)0.374526, (float)0.151277, (float)0.178057, (float)0.316733, (float)0.394715, (float)0.185845, (float)0.206849, (float)0.109002, (float)0.204206, (float)0.295515, (float)0.076483, (float)0.202319, (float)0.248717, (float)0.329550, (float)0.334914, (float)0.253230, (float)0.273901, (float)0.166143, (float)0.343162, (float)0.342436, (float)0.296871, (float)0.222597, (float)0.099329, (float)0.332798, (float)0.234925, (float)0.289414, (float)0.229609, (float)0.271884, (float)0.394487, (float)0.199041, (float)0.256375, (float)0.255654, (float)0.354066, (float)0.184846, (float)0.251309, (float)0.310109, (float)0.278173, (float)0.210884, (float)0.244075, (float)0.328250, (float)0.324777, (float)0.249868, (float)0.187333, (float)0.264297, (float)0.394897, (float)0.196152, (float)0.258667, (float)0.170828, (float)0.338123, (float)0.223777, (float)0.249751, (float)0.278729, (float)0.378271, (float)0.344459, (float)0.268094, (float)0.295598, (float)0.114583, (float)0.268843, (float)0.347863, (float)0.129532, (float)0.284261, (float)0.155215, (float)0.302551, (float)0.273831, (float)0.189133, (float)0.356764, (float)0.230155, (float)0.219877, (float)0.207006, (float)0.211938, (float)0.097067, (float)0.248231, (float)0.226383, (float)0.355506, (float)0.311291, (float)0.238566, (float)0.265447, (float)0.297534, (float)0.266616, (float)0.218011, (float)0.145094, (float)0.245951, (float)0.173432, (float)0.235794, (float)0.289079, (float)0.209118, (float)0.197142, (float)0.218470, (float)0.200752, (float)0.246056, (float)0.372634, (float)0.202765, (float)0.199320, (float)0.365248, (float)0.225819, (float)0.260566, (float)0.190004, (float)0.276370, (float)0.201080, (float)0.197336, (float)0.295795, (float)0.322198, (float)0.411696, (float)0.147543, (float)0.267399, (float)0.192815, (float)0.361520, (float)0.277430, (float)0.214287, (float)0.268830, (float)0.428604, (float)0.256000, (float)0.277671, (float)0.133946, (float)0.510279, (float)0.323768, (float)0.241690, (float)0.152944, (float)0.184349, (float)0.057901, (float)0.228790, (float)0.179726, (float)0.280332, (float)0.227906, (float)0.157900, (float)0.319630, (float)0.184173, (float)0.337821, (float)0.168833, (float)0.165389, (float)0.304870, (float)0.353342, (float)0.294815, (float)0.114033, (float)0.250263, (float)0.189174, (float)0.264696, (float)0.240506, (float)0.388007, (float)0.193253, (float)0.191754, (float)0.251126, (float)0.290069, (float)0.315123, (float)0.325163, (float)0.129560, (float)0.249134, (float)0.141738, (float)0.129532, (float)0.306188, (float)0.283580, (float)0.348328, (float)0.230613, (float)0.274099, (float)0.269971, (float)0.187296, (float)0.243142, (float)0.352592, (float)0.354630, (float)0.272095, (float)0.270821, (float)0.306536, (float)0.083244, (float)0.296813, (float)0.228561, (float)0.327553, (float)0.269526, (float)0.245220, (float)0.244357, (float)0.285695, (float)0.336548, (float)0.278372, (float)0.293323, (float)0.339739, (float)0.223145, (float)0.233046, (float)0.148591, (float)0.384555, (float)0.310379, (float)0.172444, (float)0.172428, (float)0.346584, (float)0.297812, (float)0.258155, (float)0.187930, (float)0.241948, (float)0.224921, (float)0.272043, (float)0.373508, (float)0.425912, (float)0.375369, (float)0.173145, (float)0.369828, (float)0.234918, (float)0.269450, (float)0.314805, (float)0.165768, (float)0.118073, (float)0.299416, (float)0.401808, (float)0.212650, (float)0.386431, (float)0.295480, (float)0.184785, (float)0.368620, (float)0.197224, (float)0.326541, (float)0.231940, (float)0.167550, (float)0.175588, (float)0.236656, (float)0.213911, (float)0.197388, (float)0.256083, (float)0.261869, (float)0.217013, (float)0.228423, (float)0.348622, (float)0.450006, (float)0.256276, (float)0.255950, (float)0.281415, (float)0.179733, (float)0.173643, (float)0.201252, (float)0.341085, (float)0.224510, (float)0.138465, (float)0.228378, (float)0.222973, (float)0.256646, (float)0.230147, (float)0.363866, (float)0.137964, (float)0.238139, (float)0.259003, (float)0.083023, (float)0.186304, (float)0.126698, (float)0.450099, (float)0.274064, (float)0.259042, (float)0.278164, (float)0.224772, (float)0.271820, (float)0.194872, (float)0.181473, (float)0.296870, (float)0.316810, (float)0.338941, (float)0.279011, (float)0.159396, (float)0.275177, (float)0.294745, (float)0.290891, (float)0.141803, (float)0.333568, (float)0.195306, (float)0.264556, (float)0.087880, (float)0.255316, (float)0.333496, (float)0.194341, (float)0.277656, (float)0.238551, (float)0.367640, (float)0.304152, (float)0.123388, (float)0.261541, (float)0.254774, (float)0.322369, (float)0.346163, (float)0.209001, (float)0.214224, (float)0.205431, (float)0.211544, (float)0.215323, (float)0.216290, (float)0.250868, (float)0.242926, (float)0.332636, (float)-0.052733, (float)0.224385, (float)0.231899, (float)0.267421, (float)0.110341, (float)0.231996, (float)0.282224, (float)0.323417, (float)0.281837, (float)0.209333, (float)0.226130, (float)0.290010, (float)0.312654, (float)0.345589, (float)0.259207, (float)0.167721, (float)0.392362, (float)0.269410, (float)0.199733, (float)0.297266, (float)0.332400, (float)0.226979, (float)0.065588, (float)0.296431, (float)0.194763, (float)0.238322, (float)0.302117, (float)0.251032, (float)0.311681, (float)0.318538, (float)0.172093, (float)0.186731, (float)0.166460, (float)0.285118, (float)0.351171, (float)-0.048625, (float)0.155843, (float)0.221314, (float)0.328078, (float)0.386052, (float)0.237469, (float)0.305702, (float)0.117849, (float)0.268051, (float)0.192117, (float)0.221083, (float)0.167906, (float)0.287741, (float)0.249482, (float)0.245134, (float)0.267811, (float)0.239291, (float)0.098827, (float)0.277783, (float)0.246465, (float)0.174705, (float)0.100487, (float)0.050196, (float)0.280930, (float)0.281007, (float)0.171598, (float)0.211425, (float)0.221346, (float)0.281698, (float)0.150649, (float)0.076939, (float)0.238055, (float)0.241127, (float)0.294181, (float)0.254267, (float)0.255613, (float)0.345135, (float)0.294828, (float)0.303989, (float)0.320355, (float)0.275740, (float)0.165689, (float)0.294141, (float)0.130094, (float)0.185425, (float)0.286594, (float)0.319824, (float)0.212748, (float)0.360818, (float)0.344050, (float)0.095413, (float)0.258644, (float)0.170935, (float)0.200692, (float)0.196744, (float)0.197181, (float)0.194237, (float)0.320139, (float)0.348373, (float)0.343676, (float)0.315266, (float)0.202015, (float)0.325148, (float)0.322675, (float)0.303804, (float)0.263383, (float)0.236389, (float)0.249160, (float)0.307993, (float)0.259140, (float)0.239066, (float)0.271980, (float)0.260091, (float)0.321008, (float)0.181837, (float)0.352627, (float)0.357930, (float)0.286101, (float)0.252634, (float)0.164206, (float)0.289713, (float)0.399584, (float)0.265095, (float)0.203076, (float)0.250223, (float)0.369446, (float)0.208519, (float)0.280384, (float)0.223330, (float)0.230855, (float)0.160899, (float)0.236905, (float)0.211641, (float)0.354886, (float)0.163478, (float)0.164160, (float)0.307243, (float)0.307705, (float)0.215194, (float)0.282122, (float)0.285682, (float)0.170101, (float)0.230474, (float)0.213436, (float)0.318922, (float)0.106063, (float)0.262806, (float)0.260816, (float)0.174854, (float)0.082007, (float)0.181492, (float)0.356583, (float)0.120368, (float)0.315855, (float)0.159469, (float)0.378953, (float)0.327226, (float)0.208611, (float)0.309562, (float)0.225279, (float)0.145632, (float)0.134626, (float)0.230364, (float)0.291274, (float)0.272654, (float)0.202684, (float)0.268785, (float)0.195801, (float)0.227745, (float)0.303641, (float)0.324994, (float)0.300008, (float)0.332829, (float)0.241726, (float)0.266489, (float)0.247341, (float)0.091259, (float)0.250275, (float)0.254326, (float)0.371028, (float)0.332103, (float)0.369274, (float)0.109943, (float)0.170144, (float)0.175816, (float)0.388793, (float)0.220611, (float)0.276613, (float)0.281295, (float)0.175525, (float)0.261646, (float)0.154389, (float)0.251868, (float)0.194534, (float)0.245232, (float)0.340547, (float)0.244606, (float)0.242613, (float)0.182212, (float)0.300236, (float)0.303656, (float)0.311811, (float)0.241362, (float)0.232588, (float)0.130263, (float)0.308066, (float)0.097932, (float)0.277647, (float)0.291823, (float)0.384778, (float)0.178882, (float)0.362211, (float)0.300467, (float)0.192286, (float)0.267236, (float)0.166335, (float)0.299789, (float)0.271044, (float)0.204033, (float)0.256543, (float)0.228943, (float)0.255155, (float)0.212116, (float)0.353151, (float)0.229290, (float)0.250965, (float)0.308534, (float)0.236787, (float)0.299957, (float)0.211089, (float)0.345572, (float)0.342168, (float)0.157556};	// L4123
  #pragma HLS resource variable=v3518 core=ram_t2p_bram

  float v3519[512] = {(float)0.014797, (float)0.037974, (float)0.024287, (float)0.033282, (float)0.009573, (float)0.012175, (float)0.032409, (float)0.023881, (float)0.021434, (float)0.012457, (float)0.007617, (float)0.014534, (float)0.025956, (float)0.008145, (float)0.016107, (float)0.016402, (float)0.032195, (float)0.034207, (float)0.021148, (float)0.021447, (float)0.013177, (float)0.034486, (float)0.035753, (float)0.023377, (float)0.017639, (float)0.004832, (float)0.028323, (float)0.019312, (float)0.027409, (float)0.017613, (float)0.022178, (float)0.042271, (float)0.016393, (float)0.015593, (float)0.018405, (float)0.021813, (float)0.017244, (float)0.022655, (float)0.034637, (float)0.017027, (float)0.018760, (float)0.026324, (float)0.028153, (float)0.027661, (float)0.023234, (float)0.010893, (float)0.019429, (float)0.047713, (float)0.014600, (float)0.020709, (float)0.014191, (float)0.027877, (float)0.011790, (float)0.018164, (float)0.021013, (float)0.033222, (float)0.022192, (float)0.023825, (float)0.023330, (float)0.009719, (float)0.020101, (float)0.035948, (float)0.010746, (float)0.019807, (float)0.014409, (float)0.025751, (float)0.020639, (float)0.008093, (float)0.024897, (float)0.016369, (float)0.024380, (float)0.015503, (float)0.015689, (float)0.004939, (float)0.024048, (float)0.012735, (float)0.023085, (float)0.026694, (float)0.022144, (float)0.019275, (float)0.021960, (float)0.019823, (float)0.015991, (float)0.012718, (float)0.016494, (float)0.011768, (float)0.016908, (float)0.024666, (float)0.022209, (float)0.017352, (float)0.016695, (float)0.020054, (float)0.024338, (float)0.027665, (float)0.017877, (float)0.017486, (float)0.037940, (float)0.015464, (float)0.020674, (float)0.012233, (float)0.033432, (float)0.015017, (float)0.013682, (float)0.028803, (float)0.028052, (float)0.031367, (float)0.013165, (float)0.026028, (float)0.011627, (float)0.047816, (float)0.019174, (float)0.011349, (float)0.018531, (float)0.044545, (float)0.019873, (float)0.028756, (float)0.008903, (float)0.052529, (float)0.030137, (float)0.017425, (float)0.013181, (float)0.013588, (float)0.003196, (float)0.016511, (float)0.010533, (float)0.017726, (float)0.015709, (float)0.008342, (float)0.028195, (float)0.013471, (float)0.027743, (float)0.012433, (float)0.013966, (float)0.020415, (float)0.030947, (float)0.029389, (float)0.006835, (float)0.017954, (float)0.012979, (float)0.022241, (float)0.017859, (float)0.029926, (float)0.018215, (float)0.011935, (float)0.023874, (float)0.024038, (float)0.024009, (float)0.037302, (float)0.009383, (float)0.026433, (float)0.011903, (float)0.008586, (float)0.029513, (float)0.018345, (float)0.012961, (float)0.016569, (float)0.026276, (float)0.025337, (float)0.015654, (float)0.021501, (float)0.022197, (float)0.023241, (float)0.019577, (float)0.067689, (float)0.024607, (float)0.004769, (float)0.024836, (float)0.016700, (float)0.019427, (float)0.023107, (float)0.017138, (float)0.018203, (float)0.018894, (float)0.024965, (float)0.021896, (float)0.025463, (float)0.036071, (float)0.015943, (float)0.018717, (float)0.006850, (float)0.041029, (float)0.023362, (float)0.019808, (float)0.012859, (float)0.032598, (float)0.030832, (float)0.024954, (float)0.012277, (float)0.017085, (float)0.015440, (float)0.023446, (float)0.029087, (float)0.059264, (float)0.024963, (float)0.012804, (float)0.020356, (float)0.022088, (float)0.032317, (float)0.040116, (float)0.009682, (float)0.010246, (float)0.022698, (float)0.031086, (float)0.017329, (float)0.027773, (float)0.022563, (float)0.012499, (float)0.028079, (float)0.021120, (float)0.023154, (float)0.017160, (float)0.011038, (float)0.010535, (float)0.018923, (float)0.013009, (float)0.014156, (float)0.027678, (float)0.024117, (float)0.021302, (float)0.014714, (float)0.036207, (float)0.028543, (float)0.016743, (float)0.018916, (float)0.026885, (float)0.010043, (float)0.012075, (float)0.014134, (float)0.033789, (float)0.020699, (float)0.010101, (float)0.018902, (float)0.015572, (float)0.049192, (float)0.016134, (float)0.028751, (float)0.009142, (float)0.042635, (float)0.026588, (float)0.004665, (float)0.009972, (float)0.005729, (float)0.049139, (float)0.024250, (float)0.016319, (float)0.014276, (float)0.014179, (float)0.024507, (float)0.012122, (float)0.020003, (float)0.024153, (float)0.027940, (float)0.025884, (float)0.020835, (float)0.012927, (float)0.024182, (float)0.034140, (float)0.021667, (float)0.007899, (float)0.029858, (float)0.013404, (float)0.021888, (float)0.005248, (float)0.024414, (float)0.033217, (float)0.017424, (float)0.017588, (float)0.022876, (float)0.025777, (float)0.036217, (float)0.011590, (float)0.015665, (float)0.016886, (float)0.024274, (float)0.033398, (float)0.016618, (float)0.019122, (float)0.017813, (float)0.015589, (float)0.017732, (float)0.017904, (float)0.019168, (float)0.016683, (float)0.033678, (float)0.004529, (float)0.015886, (float)0.018173, (float)0.022744, (float)0.007121, (float)0.012488, (float)0.023408, (float)0.031028, (float)0.027164, (float)0.015513, (float)0.017717, (float)0.016643, (float)0.029922, (float)0.022554, (float)0.017378, (float)0.014135, (float)0.046231, (float)0.023767, (float)0.013142, (float)0.024729, (float)0.023066, (float)0.023765, (float)0.003310, (float)0.020579, (float)0.012455, (float)0.016946, (float)0.029351, (float)0.019246, (float)0.024107, (float)0.027394, (float)0.011762, (float)0.011401, (float)0.017944, (float)0.023090, (float)0.027987, (float)0.004324, (float)0.012802, (float)0.010422, (float)0.027148, (float)0.030546, (float)0.014914, (float)0.022719, (float)0.007397, (float)0.016942, (float)0.010857, (float)0.014844, (float)0.016265, (float)0.028345, (float)0.019868, (float)0.015381, (float)0.016695, (float)0.021697, (float)0.009911, (float)0.018018, (float)0.016002, (float)0.010949, (float)0.005767, (float)0.005036, (float)0.026319, (float)0.030716, (float)0.009113, (float)0.010563, (float)0.016398, (float)0.030490, (float)0.013609, (float)0.006690, (float)0.019067, (float)0.017289, (float)0.025994, (float)0.015580, (float)0.021489, (float)0.026740, (float)0.025944, (float)0.023086, (float)0.030448, (float)0.017901, (float)0.016307, (float)0.018869, (float)0.008179, (float)0.012594, (float)0.028673, (float)0.027379, (float)0.012914, (float)0.042257, (float)0.044290, (float)0.004725, (float)0.017098, (float)0.010509, (float)0.034835, (float)0.010232, (float)0.010880, (float)0.009897, (float)0.024268, (float)0.031363, (float)0.028433, (float)0.023923, (float)0.018523, (float)0.022239, (float)0.027958, (float)0.021271, (float)0.018237, (float)0.016664, (float)0.028019, (float)0.021324, (float)0.028550, (float)0.017067, (float)0.018597, (float)0.015267, (float)0.019043, (float)0.010217, (float)0.027563, (float)0.028792, (float)0.020045, (float)0.018991, (float)0.011335, (float)0.022008, (float)0.021896, (float)0.019881, (float)0.012837, (float)0.022065, (float)0.043280, (float)0.018434, (float)0.019879, (float)0.012119, (float)0.019007, (float)0.009195, (float)0.022533, (float)0.009538, (float)0.029914, (float)0.011779, (float)0.010417, (float)0.025136, (float)0.024045, (float)0.014470, (float)0.020585, (float)0.020260, (float)0.013212, (float)0.017874, (float)0.016841, (float)0.018557, (float)0.007608, (float)0.026879, (float)0.016277, (float)0.013738, (float)0.005450, (float)0.012819, (float)0.036177, (float)0.008542, (float)0.030353, (float)0.011260, (float)0.038203, (float)0.019922, (float)0.016696, (float)0.020955, (float)0.016163, (float)0.009182, (float)0.010645, (float)0.016338, (float)0.021920, (float)0.022267, (float)0.014893, (float)0.023184, (float)0.014378, (float)0.013713, (float)0.018360, (float)0.020984, (float)0.024619, (float)0.023726, (float)0.022280, (float)0.018140, (float)0.020319, (float)0.003983, (float)0.019480, (float)0.027284, (float)0.028425, (float)0.023305, (float)0.028359, (float)0.006877, (float)0.012102, (float)0.011683, (float)0.038713, (float)0.016494, (float)0.020911, (float)0.019379, (float)0.014409, (float)0.015669, (float)0.009922, (float)0.030646, (float)0.014635, (float)0.014432, (float)0.040783, (float)0.017921, (float)0.018565, (float)0.014059, (float)0.020364, (float)0.024347, (float)0.021271, (float)0.016969, (float)0.016637, (float)0.011990, (float)0.031063, (float)0.005982, (float)0.027176, (float)0.025192, (float)0.025004, (float)0.010163, (float)0.023461, (float)0.029223, (float)0.010756, (float)0.017914, (float)0.009306, (float)0.025531, (float)0.016042, (float)0.012558, (float)0.018730, (float)0.013725, (float)0.030774, (float)0.011870, (float)0.037628, (float)0.017584, (float)0.017254, (float)0.026002, (float)0.018345, (float)0.018618, (float)0.013726, (float)0.034435, (float)0.014385, (float)0.011154};	// L4124
  #pragma HLS resource variable=v3519 core=ram_t2p_bram

  float v3520[512] = {(float)-0.102286, (float)-0.130249, (float)0.016886, (float)0.053927, (float)0.053070, (float)-0.065007, (float)-0.168092, (float)-0.096206, (float)0.060128, (float)-0.089756, (float)-0.075971, (float)-0.011981, (float)0.048014, (float)-0.086672, (float)-0.041463, (float)-0.088698, (float)-0.037827, (float)-0.237557, (float)-0.096518, (float)-0.043417, (float)0.030305, (float)-0.238074, (float)-0.006524, (float)-0.070019, (float)0.060617, (float)0.025746, (float)-0.169070, (float)-0.120655, (float)-0.155018, (float)-0.092696, (float)-0.001185, (float)-0.096202, (float)-0.092171, (float)-0.178946, (float)0.014559, (float)-0.049803, (float)0.027617, (float)-0.169230, (float)0.025903, (float)0.037747, (float)-0.029229, (float)0.014037, (float)-0.063783, (float)-0.083131, (float)0.104908, (float)-0.055399, (float)-0.055074, (float)0.133189, (float)0.077474, (float)-0.186081, (float)-0.081155, (float)-0.208298, (float)-0.024397, (float)-0.029691, (float)-0.059322, (float)0.124287, (float)-0.047476, (float)-0.001440, (float)-0.006886, (float)-0.100196, (float)-0.104021, (float)-0.083676, (float)0.000882, (float)0.025870, (float)-0.048999, (float)-0.063094, (float)0.019339, (float)-0.037542, (float)-0.048652, (float)-0.080320, (float)-0.112343, (float)-0.153831, (float)-0.103056, (float)-0.085757, (float)-0.070625, (float)-0.072476, (float)-0.090262, (float)0.007539, (float)-0.085022, (float)-0.028707, (float)0.000811, (float)0.024941, (float)-0.106755, (float)-0.123709, (float)-0.127055, (float)0.093040, (float)-0.029539, (float)-0.084636, (float)-0.056157, (float)-0.121008, (float)0.010295, (float)-0.111767, (float)-0.040748, (float)-0.010973, (float)-0.051184, (float)-0.132640, (float)0.045407, (float)-0.107193, (float)-0.101830, (float)-0.169869, (float)-0.033820, (float)-0.095022, (float)-0.189678, (float)0.062315, (float)-0.021020, (float)0.093181, (float)-0.098590, (float)0.082313, (float)-0.091109, (float)0.071120, (float)-0.110610, (float)0.017561, (float)-0.016362, (float)-0.247180, (float)-0.118508, (float)-0.047748, (float)-0.065117, (float)0.177139, (float)0.014971, (float)-0.044933, (float)-0.153648, (float)0.085648, (float)0.021406, (float)-0.077496, (float)-0.011504, (float)-0.018905, (float)0.053105, (float)-0.085857, (float)-0.038039, (float)0.072169, (float)-0.027858, (float)0.024390, (float)-0.067953, (float)-0.043382, (float)-0.034377, (float)-0.161844, (float)-0.022166, (float)-0.049201, (float)0.043180, (float)-0.154618, (float)-0.109031, (float)-0.135244, (float)-0.127626, (float)0.043546, (float)0.017695, (float)-0.065638, (float)-0.061107, (float)0.202461, (float)-0.013972, (float)-0.124579, (float)0.008559, (float)-0.018228, (float)0.031176, (float)-0.148220, (float)-0.186647, (float)-0.005104, (float)-0.081573, (float)-0.181948, (float)-0.097725, (float)-0.037767, (float)0.000181, (float)-0.038663, (float)-0.063522, (float)0.146074, (float)-0.128204, (float)-0.074300, (float)0.030985, (float)-0.122840, (float)-0.042529, (float)0.025415, (float)-0.092340, (float)0.000491, (float)-0.016613, (float)-0.135662, (float)-0.062528, (float)0.006009, (float)0.037423, (float)-0.000798, (float)-0.133080, (float)-0.041386, (float)-0.202340, (float)-0.016247, (float)-0.196248, (float)-0.072525, (float)0.020790, (float)-0.058455, (float)-0.113474, (float)-0.136087, (float)-0.106708, (float)-0.171915, (float)0.014489, (float)-0.039008, (float)0.042632, (float)-0.119871, (float)0.081119, (float)-0.099114, (float)-0.177936, (float)-0.084463, (float)0.001022, (float)-0.008251, (float)0.007777, (float)-0.098570, (float)-0.094069, (float)0.069623, (float)-0.110015, (float)-0.114589, (float)0.017814, (float)-0.171108, (float)-0.014443, (float)-0.028208, (float)0.048741, (float)-0.051265, (float)-0.096291, (float)0.038626, (float)-0.103671, (float)0.012829, (float)-0.049016, (float)-0.029189, (float)-0.055315, (float)-0.140197, (float)0.002234, (float)-0.079135, (float)-0.017436, (float)0.010842, (float)-0.006639, (float)0.025010, (float)0.002807, (float)-0.014991, (float)-0.117217, (float)0.033509, (float)0.003361, (float)-0.100465, (float)-0.173487, (float)-0.113841, (float)-0.080396, (float)-0.032859, (float)-0.028635, (float)-0.213338, (float)-0.015135, (float)-0.087584, (float)0.014559, (float)-0.027689, (float)-0.142149, (float)0.027245, (float)0.034968, (float)-0.148343, (float)-0.130571, (float)-0.059593, (float)-0.136536, (float)-0.100315, (float)-0.008331, (float)-0.090577, (float)-0.101207, (float)-0.142599, (float)0.043190, (float)-0.078463, (float)-0.046141, (float)0.015669, (float)0.014962, (float)-0.128983, (float)0.068532, (float)-0.147780, (float)-0.125880, (float)-0.057315, (float)0.099854, (float)-0.023377, (float)-0.134027, (float)0.017321, (float)0.167296, (float)0.069254, (float)0.006963, (float)0.020260, (float)-0.050786, (float)-0.139708, (float)-0.129200, (float)-0.033092, (float)0.008835, (float)0.120834, (float)-0.180802, (float)-0.014881, (float)-0.130247, (float)0.032282, (float)-0.098632, (float)-0.062034, (float)0.078147, (float)0.080889, (float)-0.091807, (float)-0.045004, (float)-0.124604, (float)-0.048472, (float)-0.075580, (float)0.069195, (float)-0.038243, (float)-0.006287, (float)-0.047689, (float)-0.060283, (float)-0.048453, (float)-0.035499, (float)-0.102493, (float)-0.063373, (float)0.151472, (float)-0.132043, (float)-0.071426, (float)0.040202, (float)-0.034154, (float)-0.008526, (float)0.001868, (float)-0.029316, (float)-0.152261, (float)-0.033686, (float)-0.048225, (float)-0.097569, (float)-0.040431, (float)-0.091853, (float)-0.000275, (float)0.022159, (float)-0.055239, (float)-0.068588, (float)0.031948, (float)0.150193, (float)-0.117370, (float)-0.129927, (float)0.018276, (float)-0.015077, (float)-0.146365, (float)-0.084167, (float)-0.030010, (float)-0.073432, (float)-0.053854, (float)-0.128083, (float)0.040759, (float)-0.089652, (float)-0.140781, (float)0.057215, (float)0.028043, (float)-0.009149, (float)-0.103762, (float)-0.024293, (float)-0.084685, (float)-0.022411, (float)-0.002665, (float)-0.115365, (float)-0.046597, (float)0.030503, (float)-0.105998, (float)-0.009157, (float)-0.074790, (float)0.000416, (float)-0.088800, (float)-0.142314, (float)-0.039687, (float)-0.164266, (float)-0.045068, (float)0.033121, (float)0.000795, (float)-0.154220, (float)0.099867, (float)-0.004623, (float)-0.057053, (float)-0.084284, (float)0.054957, (float)-0.181353, (float)-0.138678, (float)-0.033480, (float)0.047180, (float)-0.032470, (float)-0.003394, (float)-0.021033, (float)0.039258, (float)0.009295, (float)-0.018768, (float)-0.097337, (float)0.518637, (float)0.018138, (float)-0.040453, (float)-0.057851, (float)-0.014343, (float)-0.026796, (float)-0.042246, (float)0.004108, (float)-0.077753, (float)-0.048641, (float)0.035890, (float)-0.156307, (float)-0.082575, (float)-0.148550, (float)-0.098730, (float)-0.002838, (float)-0.024290, (float)-0.065538, (float)0.007586, (float)-0.139745, (float)-0.104217, (float)-0.082347, (float)-0.055217, (float)0.007889, (float)-0.047024, (float)0.065973, (float)-0.106290, (float)-0.057187, (float)-0.055214, (float)-0.080113, (float)-0.089246, (float)0.028202, (float)0.123264, (float)-0.205945, (float)-0.020338, (float)-0.024089, (float)0.082836, (float)0.004376, (float)-0.031189, (float)-0.171535, (float)0.046388, (float)-0.071442, (float)0.032068, (float)-0.096685, (float)-0.066919, (float)-0.034415, (float)-0.076992, (float)0.056344, (float)-0.146839, (float)-0.069553, (float)-0.007231, (float)-0.024979, (float)-0.043237, (float)-0.062540, (float)-0.002472, (float)0.008895, (float)-0.082210, (float)-0.124440, (float)0.070838, (float)0.016016, (float)-0.134764, (float)-0.062674, (float)-0.105392, (float)0.142106, (float)-0.008648, (float)-0.076716, (float)-0.125101, (float)-0.054731, (float)-0.131304, (float)-0.023042, (float)0.015469, (float)-0.048935, (float)-0.001273, (float)0.045024, (float)0.033201, (float)-0.046740, (float)-0.105459, (float)0.048534, (float)-0.112343, (float)-0.077349, (float)0.006614, (float)-0.037838, (float)-0.017476, (float)-0.031532, (float)0.045498, (float)-0.178286, (float)-0.030906, (float)-0.087056, (float)-0.073235, (float)-0.033448, (float)-0.021015, (float)0.086905, (float)-0.056695, (float)0.047351, (float)-0.197582, (float)-0.091191, (float)-0.123400, (float)-0.057476, (float)-0.064887, (float)-0.092378, (float)-0.011430, (float)-0.075702, (float)-0.111605, (float)-0.029059, (float)-0.049385, (float)-0.032027, (float)-0.191926, (float)-0.064090, (float)-0.022608, (float)-0.168679, (float)0.005069, (float)-0.127235, (float)0.092186, (float)-0.086097, (float)-0.060362, (float)-0.111019, (float)-0.000974, (float)-0.026893, (float)-0.126493, (float)0.080552, (float)-0.088567, (float)0.001659, (float)-0.018472, (float)-0.013239, (float)-0.089863, (float)-0.102586, (float)-0.092393, (float)-0.059868, (float)-0.024012, (float)-0.005873, (float)0.080796, (float)-0.040349, (float)-0.112878, (float)0.087438, (float)-0.008288, (float)-0.194065, (float)-0.147339, (float)-0.034333, (float)-0.019008, (float)-0.006106};	// L4125
  #pragma HLS resource variable=v3520 core=ram_t2p_bram

  float v3521[512] = {(float)-0.175876, (float)-0.215647, (float)-0.204695, (float)-0.169495, (float)-0.162827, (float)-0.147338, (float)-0.215763, (float)-0.290474, (float)-0.111154, (float)-0.219632, (float)-0.102010, (float)-0.154852, (float)-0.198917, (float)-0.044533, (float)-0.150829, (float)-0.191982, (float)-0.211422, (float)-0.165469, (float)-0.185385, (float)-0.173255, (float)-0.128850, (float)-0.237593, (float)-0.196459, (float)-0.196512, (float)-0.177603, (float)-0.177378, (float)-0.175981, (float)-0.154552, (float)-0.164812, (float)-0.259943, (float)-0.175183, (float)-0.249797, (float)-0.174085, (float)-0.240969, (float)-0.249838, (float)-0.293822, (float)-0.149622, (float)-0.157821, (float)-0.180007, (float)-0.185098, (float)-0.151621, (float)-0.134493, (float)-0.274576, (float)-0.124816, (float)-0.224551, (float)-0.253069, (float)-0.239821, (float)-0.185870, (float)-0.173906, (float)-0.239322, (float)-0.121415, (float)-0.180345, (float)-0.272923, (float)-0.261738, (float)-0.185536, (float)-0.231590, (float)-0.233326, (float)-0.186008, (float)-0.209718, (float)-0.069156, (float)-0.191230, (float)-0.207791, (float)-0.108394, (float)-0.280989, (float)-0.130290, (float)-0.165388, (float)-0.211865, (float)-0.364110, (float)-0.295110, (float)-0.238412, (float)-0.163155, (float)-0.189230, (float)-0.179195, (float)-0.203113, (float)-0.176996, (float)-0.273815, (float)-0.332410, (float)-0.172504, (float)-0.179256, (float)-0.263844, (float)-0.220675, (float)-0.160910, (float)-0.153418, (float)-0.141382, (float)-0.299210, (float)-0.144963, (float)-0.183827, (float)-0.177888, (float)-0.142214, (float)-0.219838, (float)-0.190025, (float)-0.158025, (float)-0.166649, (float)-0.248980, (float)-0.156913, (float)-0.171848, (float)-0.166000, (float)-0.197152, (float)-0.228674, (float)-0.236629, (float)-0.222967, (float)-0.154267, (float)-0.203035, (float)-0.143148, (float)-0.136256, (float)-0.201488, (float)-0.180418, (float)-0.209272, (float)-0.296443, (float)-0.198436, (float)-0.268257, (float)-0.221554, (float)-0.214695, (float)-0.340379, (float)-0.266834, (float)-0.189038, (float)-0.173252, (float)-0.222553, (float)-0.177227, (float)-0.169795, (float)-0.109547, (float)-0.218040, (float)-0.115450, (float)-0.165376, (float)-0.190963, (float)-0.353537, (float)-0.311177, (float)-0.216132, (float)-0.149594, (float)-0.166691, (float)-0.284863, (float)-0.220685, (float)-0.152887, (float)-0.180719, (float)-0.211753, (float)-0.186857, (float)-0.137562, (float)-0.177034, (float)-0.186086, (float)-0.196906, (float)-0.174074, (float)-0.301054, (float)-0.078720, (float)-0.201734, (float)-0.194675, (float)-0.224661, (float)-0.245879, (float)-0.105768, (float)-0.140073, (float)-0.121287, (float)-0.119868, (float)-0.175956, (float)-0.215642, (float)-0.330730, (float)-0.351507, (float)-0.236602, (float)-0.118475, (float)-0.215456, (float)-0.175091, (float)-0.189247, (float)-0.336501, (float)-0.159756, (float)-0.255446, (float)0.064416, (float)-0.285613, (float)-0.119795, (float)-0.158325, (float)-0.229696, (float)-0.335175, (float)-0.198683, (float)-0.268627, (float)-0.163159, (float)-0.246141, (float)-0.290042, (float)-0.242833, (float)-0.144908, (float)-0.190023, (float)-0.214939, (float)-0.154125, (float)-0.291725, (float)-0.250379, (float)-0.221277, (float)-0.046265, (float)-0.154741, (float)-0.151054, (float)-0.152670, (float)-0.173487, (float)-0.193143, (float)-0.198664, (float)-0.223877, (float)-0.208557, (float)-0.268808, (float)-0.184503, (float)-0.179723, (float)-0.183276, (float)-0.388039, (float)-0.153910, (float)-0.155262, (float)-0.156722, (float)-0.223757, (float)-0.151111, (float)-0.253952, (float)-0.284909, (float)-0.182560, (float)-0.268691, (float)-0.232789, (float)-0.210797, (float)-0.240983, (float)-0.102194, (float)-0.150658, (float)-0.197840, (float)-0.173376, (float)-0.228219, (float)-0.098492, (float)-0.184693, (float)-0.176974, (float)-0.157557, (float)-0.193729, (float)-0.164283, (float)-0.282202, (float)-0.186557, (float)-0.275359, (float)-0.226644, (float)-0.216856, (float)-0.135228, (float)-0.219364, (float)-0.105988, (float)-0.213885, (float)-0.132169, (float)-0.188947, (float)-0.213028, (float)-0.191251, (float)-0.236402, (float)-0.140232, (float)-0.222844, (float)-0.235422, (float)-0.163198, (float)-0.190452, (float)-0.142823, (float)-0.117746, (float)-0.241885, (float)-0.273342, (float)-0.296315, (float)-0.159994, (float)-0.355825, (float)-0.367269, (float)-0.220057, (float)-0.150526, (float)-0.208420, (float)-0.086982, (float)-0.205152, (float)-0.206952, (float)-0.198606, (float)-0.229943, (float)-0.074515, (float)-0.176496, (float)-0.141153, (float)-0.218021, (float)-0.144980, (float)-0.142644, (float)-0.145244, (float)-0.291583, (float)-0.087099, (float)-0.135855, (float)-0.200296, (float)-0.112490, (float)-0.258800, (float)-0.198756, (float)-0.202807, (float)-0.244341, (float)-0.086370, (float)-0.341515, (float)-0.257930, (float)-0.234285, (float)-0.355215, (float)-0.185889, (float)-0.115276, (float)-0.173172, (float)-0.177991, (float)-0.190923, (float)-0.201802, (float)-0.188640, (float)-0.275075, (float)-0.150079, (float)0.116527, (float)-0.189073, (float)-0.184478, (float)-0.203674, (float)-0.033936, (float)-0.346352, (float)-0.195640, (float)-0.196203, (float)-0.153652, (float)-0.190249, (float)-0.143065, (float)-0.302204, (float)-0.177953, (float)-0.197052, (float)-0.211816, (float)-0.095247, (float)-0.171144, (float)-0.240855, (float)-0.218429, (float)-0.211422, (float)-0.204203, (float)-0.056632, (float)-0.069972, (float)-0.208111, (float)-0.187201, (float)-0.207923, (float)-0.153953, (float)-0.226569, (float)-0.198087, (float)-0.167854, (float)-0.202200, (float)-0.201038, (float)-0.105144, (float)-0.170481, (float)-0.213924, (float)0.039596, (float)-0.107683, (float)-0.274493, (float)-0.269041, (float)-0.260268, (float)-0.281934, (float)-0.191735, (float)-0.194046, (float)-0.294365, (float)-0.182235, (float)-0.290273, (float)-0.106416, (float)-0.207573, (float)-0.264753, (float)-0.303198, (float)-0.287798, (float)-0.157870, (float)-0.007106, (float)-0.214186, (float)-0.202193, (float)-0.151610, (float)-0.112344, (float)0.024550, (float)-0.097783, (float)-0.138225, (float)-0.179958, (float)-0.321398, (float)-0.217892, (float)-0.136859, (float)-0.079968, (float)0.011651, (float)-0.183850, (float)-0.192576, (float)-0.161397, (float)-0.276863, (float)-0.190925, (float)-0.210108, (float)-0.230516, (float)-0.205480, (float)-0.201685, (float)-0.274145, (float)-0.100519, (float)-0.315171, (float)-0.112055, (float)-0.170047, (float)-0.136427, (float)-0.215665, (float)-0.267289, (float)-0.158427, (float)-0.199738, (float)-0.174545, (float)-0.188593, (float)-0.230733, (float)-0.202356, (float)-0.337601, (float)-0.226602, (float)-0.235517, (float)-0.213326, (float)-0.234617, (float)-0.241234, (float)-0.235827, (float)-0.126483, (float)-0.234063, (float)-0.188728, (float)-0.164635, (float)-0.141678, (float)-0.188190, (float)-0.107585, (float)-0.304830, (float)-0.116209, (float)-0.165138, (float)-0.204584, (float)-0.183345, (float)-0.310223, (float)-0.177752, (float)-0.157479, (float)-0.267603, (float)-0.177651, (float)-0.156919, (float)-0.174050, (float)-0.189249, (float)-0.302800, (float)-0.145666, (float)-0.217923, (float)-0.222581, (float)-0.160946, (float)-0.142348, (float)-0.268311, (float)-0.292008, (float)-0.173983, (float)-0.207916, (float)-0.194009, (float)-0.267895, (float)-0.197272, (float)-0.195115, (float)-0.166471, (float)-0.228643, (float)-0.190261, (float)-0.266719, (float)-0.401001, (float)-0.255011, (float)-0.181693, (float)-0.202540, (float)-0.158920, (float)-0.247610, (float)-0.057332, (float)-0.220320, (float)-0.208377, (float)-0.158687, (float)-0.121199, (float)-0.179473, (float)-0.344943, (float)-0.166220, (float)-0.252310, (float)-0.243506, (float)-0.287777, (float)-0.279724, (float)-0.189737, (float)-0.211347, (float)-0.194293, (float)-0.205022, (float)-0.169366, (float)-0.224268, (float)-0.298661, (float)-0.132767, (float)-0.142799, (float)-0.239909, (float)-0.159280, (float)-0.199854, (float)-0.322538, (float)-0.185953, (float)-0.176311, (float)-0.269071, (float)-0.209719, (float)-0.239560, (float)-0.113970, (float)-0.189716, (float)-0.186976, (float)-0.182853, (float)-0.261500, (float)-0.207342, (float)-0.185801, (float)-0.059755, (float)-0.191480, (float)-0.218287, (float)-0.208783, (float)-0.174156, (float)-0.271491, (float)-0.199923, (float)-0.211675, (float)-0.249233, (float)-0.171727, (float)-0.156605, (float)-0.166925, (float)-0.301463, (float)-0.168512, (float)-0.243372, (float)-0.229652, (float)-0.194695, (float)-0.286040, (float)-0.328765, (float)-0.219691, (float)-0.186197, (float)-0.175520, (float)-0.098674, (float)-0.175625, (float)-0.130352, (float)-0.155537, (float)-0.167934, (float)-0.222239, (float)-0.281887, (float)-0.265243, (float)-0.094651, (float)-0.241226, (float)-0.273117, (float)-0.257160, (float)-0.260431, (float)-0.293425, (float)-0.246995, (float)-0.181964, (float)-0.274007, (float)-0.133587, (float)-0.169813, (float)-0.191901, (float)-0.179560, (float)-0.232497, (float)-0.135247, (float)-0.107717, (float)-0.218356, (float)-0.153940, (float)-0.201536, (float)-0.324302, (float)-0.171332};	// L4126
  #pragma HLS resource variable=v3521 core=ram_t2p_bram

  float v3522[512] = {(float)0.447423, (float)0.513753, (float)0.433517, (float)0.342105, (float)0.385544, (float)0.349521, (float)0.374139, (float)0.583643, (float)0.432735, (float)0.504286, (float)0.461772, (float)0.386647, (float)0.349811, (float)0.479783, (float)0.331033, (float)0.391315, (float)0.388016, (float)0.522505, (float)0.397472, (float)0.329229, (float)0.415106, (float)0.445845, (float)0.397002, (float)0.361367, (float)0.391385, (float)0.463290, (float)0.346294, (float)0.364381, (float)0.327155, (float)0.458416, (float)0.428011, (float)0.453801, (float)0.403021, (float)0.467282, (float)0.420868, (float)0.398738, (float)0.423288, (float)0.387562, (float)0.421188, (float)0.345988, (float)0.352240, (float)0.374380, (float)0.455002, (float)0.288776, (float)0.459012, (float)0.481650, (float)0.444968, (float)0.511018, (float)0.405238, (float)0.424651, (float)0.355792, (float)0.307477, (float)0.446194, (float)0.472367, (float)0.425337, (float)0.388401, (float)0.449249, (float)0.372737, (float)0.463020, (float)0.398490, (float)0.351244, (float)0.366537, (float)0.386002, (float)0.508161, (float)0.402154, (float)0.345836, (float)0.480451, (float)0.539029, (float)0.422332, (float)0.427524, (float)0.458986, (float)0.473648, (float)0.367295, (float)0.540533, (float)0.324312, (float)0.517760, (float)0.474331, (float)0.350593, (float)0.375866, (float)0.432766, (float)0.386732, (float)0.459052, (float)0.384294, (float)0.498163, (float)0.528848, (float)0.394591, (float)0.458918, (float)0.319701, (float)0.467630, (float)0.480615, (float)0.430807, (float)0.423547, (float)0.328379, (float)0.387704, (float)0.414036, (float)0.446909, (float)0.404150, (float)0.440666, (float)0.435647, (float)0.512019, (float)0.505891, (float)0.462759, (float)0.458519, (float)0.331097, (float)0.342400, (float)0.414994, (float)0.517032, (float)0.459319, (float)0.522786, (float)0.425166, (float)0.421423, (float)0.499517, (float)0.409826, (float)0.537956, (float)0.487378, (float)0.371902, (float)0.464947, (float)0.431961, (float)0.327671, (float)0.374342, (float)0.436016, (float)0.483832, (float)0.439920, (float)0.376324, (float)0.414979, (float)0.514663, (float)0.501180, (float)0.438183, (float)0.365483, (float)0.403676, (float)0.449763, (float)0.471993, (float)0.391360, (float)0.323746, (float)0.320835, (float)0.322407, (float)0.429084, (float)0.400934, (float)0.394691, (float)0.377877, (float)0.434894, (float)0.412024, (float)0.327408, (float)0.433427, (float)0.373986, (float)0.418887, (float)0.428752, (float)0.307146, (float)0.426034, (float)0.341015, (float)0.437495, (float)0.440691, (float)0.374963, (float)0.585253, (float)0.451794, (float)0.504526, (float)0.300518, (float)0.496813, (float)0.415490, (float)0.375511, (float)0.551371, (float)0.414643, (float)0.467706, (float)0.140422, (float)0.500085, (float)0.419293, (float)0.424561, (float)0.445150, (float)0.510906, (float)0.448834, (float)0.457372, (float)0.389648, (float)0.414464, (float)0.449722, (float)0.424525, (float)0.397052, (float)0.395712, (float)0.407184, (float)0.530484, (float)0.498646, (float)0.373323, (float)0.427978, (float)0.346914, (float)0.417807, (float)0.376607, (float)0.402921, (float)0.381379, (float)0.449335, (float)0.513231, (float)0.407952, (float)0.415510, (float)0.363528, (float)0.439108, (float)0.348868, (float)0.422753, (float)0.483326, (float)0.349387, (float)0.440606, (float)0.379494, (float)0.429752, (float)0.491020, (float)0.387832, (float)0.629899, (float)0.432214, (float)0.543615, (float)0.414014, (float)0.431155, (float)0.316055, (float)0.361197, (float)0.359734, (float)0.428121, (float)0.450592, (float)0.429420, (float)0.364638, (float)0.411044, (float)0.403845, (float)0.409787, (float)0.390064, (float)0.392834, (float)0.542146, (float)0.362942, (float)0.407754, (float)0.458593, (float)0.421713, (float)0.395339, (float)0.399698, (float)0.383811, (float)0.437370, (float)0.357607, (float)0.421712, (float)0.412836, (float)0.390364, (float)0.413677, (float)0.514531, (float)0.403890, (float)0.357687, (float)0.442909, (float)0.563922, (float)0.384760, (float)0.610368, (float)0.448247, (float)0.620309, (float)0.533568, (float)0.347986, (float)0.540067, (float)0.604419, (float)0.407654, (float)0.346940, (float)0.428102, (float)0.463130, (float)0.594779, (float)0.347913, (float)0.368877, (float)0.365834, (float)0.319143, (float)0.549162, (float)0.340987, (float)0.538595, (float)0.404143, (float)0.337258, (float)0.418550, (float)0.518712, (float)0.393328, (float)0.318837, (float)0.350157, (float)0.373564, (float)0.423783, (float)0.475212, (float)0.332150, (float)0.507801, (float)0.431669, (float)0.531826, (float)0.441295, (float)0.550951, (float)0.564777, (float)0.412977, (float)0.401727, (float)0.430363, (float)0.407656, (float)0.428488, (float)0.436032, (float)0.374929, (float)0.426109, (float)0.390548, (float)0.303016, (float)0.341231, (float)0.376848, (float)0.450699, (float)0.312710, (float)0.459211, (float)0.429770, (float)0.393613, (float)0.310594, (float)0.386927, (float)0.359374, (float)0.404642, (float)0.472214, (float)0.437271, (float)0.390158, (float)0.351535, (float)0.444846, (float)0.429893, (float)0.434711, (float)0.469288, (float)0.480729, (float)0.254855, (float)0.417091, (float)0.438670, (float)0.415612, (float)0.397638, (float)0.409194, (float)0.495279, (float)0.482386, (float)0.346782, (float)0.438214, (float)0.417869, (float)0.466848, (float)0.329928, (float)0.598589, (float)0.494855, (float)0.416673, (float)0.499622, (float)0.452813, (float)0.454967, (float)0.494491, (float)0.341493, (float)0.465827, (float)0.435634, (float)0.397566, (float)0.543874, (float)0.464332, (float)0.512203, (float)0.466884, (float)0.446294, (float)0.480985, (float)0.349167, (float)0.396135, (float)0.359268, (float)0.405338, (float)0.387780, (float)0.395922, (float)0.500108, (float)0.280756, (float)0.547004, (float)0.444839, (float)0.489365, (float)0.462131, (float)0.341664, (float)0.348471, (float)0.506004, (float)0.363714, (float)0.377388, (float)0.324810, (float)0.451971, (float)0.393600, (float)0.340334, (float)0.465975, (float)0.411420, (float)0.364251, (float)0.419598, (float)0.390338, (float)0.512833, (float)0.422064, (float)0.411518, (float)0.424044, (float)0.361026, (float)0.499868, (float)0.367244, (float)0.472069, (float)0.425155, (float)0.559005, (float)0.469406, (float)0.732236, (float)0.584926, (float)0.474911, (float)0.442566, (float)0.393422, (float)0.390910, (float)0.457596, (float)0.363646, (float)0.414579, (float)0.412940, (float)0.508076, (float)0.368089, (float)0.365219, (float)0.425403, (float)0.294505, (float)0.414201, (float)0.314530, (float)0.430416, (float)0.425217, (float)0.349332, (float)0.425694, (float)0.513318, (float)0.326145, (float)0.436697, (float)0.363685, (float)0.371230, (float)0.418293, (float)0.377237, (float)0.441756, (float)0.423116, (float)0.413291, (float)0.473100, (float)0.495479, (float)0.404575, (float)0.407886, (float)0.471905, (float)0.387505, (float)0.467329, (float)0.412886, (float)0.456864, (float)0.353010, (float)0.479327, (float)0.384407, (float)0.378485, (float)0.334253, (float)0.435122, (float)0.651192, (float)0.429510, (float)0.412192, (float)0.378755, (float)0.369234, (float)0.434277, (float)0.421420, (float)0.387330, (float)0.456627, (float)0.445587, (float)0.410690, (float)0.459617, (float)0.708211, (float)0.445249, (float)0.351457, (float)0.478452, (float)0.421713, (float)0.575569, (float)0.431215, (float)0.404691, (float)0.404316, (float)0.476442, (float)0.548901, (float)0.442972, (float)0.555885, (float)0.374430, (float)0.395060, (float)0.437607, (float)0.475181, (float)0.434038, (float)0.439896, (float)0.358578, (float)0.416113, (float)0.392985, (float)0.459856, (float)0.435436, (float)0.344785, (float)0.464944, (float)0.444204, (float)0.427477, (float)0.388138, (float)0.324681, (float)0.490854, (float)0.342600, (float)0.398876, (float)0.432001, (float)0.336283, (float)0.399056, (float)0.473241, (float)0.351376, (float)0.473625, (float)0.424391, (float)0.460255, (float)0.329753, (float)0.435716, (float)0.435347, (float)0.374213, (float)0.419065, (float)0.387980, (float)0.421212, (float)0.452733, (float)0.721327, (float)0.396854, (float)0.521703, (float)0.378590, (float)0.351187, (float)0.531838, (float)0.413776, (float)0.324344, (float)0.324375, (float)0.365248, (float)0.477405, (float)0.399674, (float)0.280039, (float)0.456171, (float)0.446301, (float)0.481626, (float)0.428990, (float)0.439948, (float)0.463270, (float)0.357526, (float)0.477375, (float)0.310451, (float)0.435638, (float)0.379660, (float)0.430352, (float)0.426148, (float)0.373965, (float)0.336998, (float)0.391676, (float)0.363721, (float)0.434727, (float)0.523475, (float)0.384540};	// L4127
  #pragma HLS resource variable=v3522 core=ram_t2p_bram

  float v3523[512] = {(float)0.024833, (float)0.033080, (float)0.020296, (float)0.015249, (float)0.020692, (float)0.018305, (float)0.020471, (float)0.028226, (float)0.030079, (float)0.024272, (float)0.027239, (float)0.021119, (float)0.016120, (float)0.048926, (float)0.015775, (float)0.019033, (float)0.020561, (float)0.035445, (float)0.022633, (float)0.014559, (float)0.021948, (float)0.026594, (float)0.025071, (float)0.015912, (float)0.019282, (float)0.021082, (float)0.019509, (float)0.019900, (float)0.016651, (float)0.018938, (float)0.021580, (float)0.025958, (float)0.020472, (float)0.021154, (float)0.016775, (float)0.014313, (float)0.028038, (float)0.020398, (float)0.023671, (float)0.013760, (float)0.019427, (float)0.021632, (float)0.023166, (float)0.013648, (float)0.025834, (float)0.020891, (float)0.019066, (float)0.034593, (float)0.021960, (float)0.022518, (float)0.020690, (float)0.013641, (float)0.016057, (float)0.019966, (float)0.020539, (float)0.017946, (float)0.017566, (float)0.019128, (float)0.022047, (float)0.029701, (float)0.017670, (float)0.019960, (float)0.029041, (float)0.023745, (float)0.023840, (float)0.020386, (float)0.025736, (float)0.017321, (float)0.016626, (float)0.018936, (float)0.036740, (float)0.023555, (float)0.017346, (float)0.029061, (float)0.017480, (float)0.020982, (float)0.016436, (float)0.017391, (float)0.022283, (float)0.019045, (float)0.015922, (float)0.026576, (float)0.018965, (float)0.024633, (float)0.022448, (float)0.023271, (float)0.026828, (float)0.015013, (float)0.034970, (float)0.027197, (float)0.024104, (float)0.024977, (float)0.018593, (float)0.018319, (float)0.023605, (float)0.029364, (float)0.020061, (float)0.021858, (float)0.022766, (float)0.020778, (float)0.037099, (float)0.027477, (float)0.024862, (float)0.017150, (float)0.016191, (float)0.015232, (float)0.030046, (float)0.026621, (float)0.018450, (float)0.029335, (float)0.017999, (float)0.025333, (float)0.018225, (float)0.026072, (float)0.023344, (float)0.019952, (float)0.027224, (float)0.039102, (float)0.017148, (float)0.018970, (float)0.026572, (float)0.023887, (float)0.025440, (float)0.019029, (float)0.018488, (float)0.019150, (float)0.022768, (float)0.021362, (float)0.015905, (float)0.020834, (float)0.020401, (float)0.025575, (float)0.022002, (float)0.012720, (float)0.015156, (float)0.017273, (float)0.024564, (float)0.020573, (float)0.019230, (float)0.017903, (float)0.021950, (float)0.019275, (float)0.019678, (float)0.020337, (float)0.020774, (float)0.023042, (float)0.022799, (float)0.017380, (float)0.025705, (float)0.020541, (float)0.030618, (float)0.020408, (float)0.018540, (float)0.025696, (float)0.014412, (float)0.022202, (float)0.018074, (float)0.032491, (float)0.023889, (float)0.017946, (float)0.019074, (float)0.022918, (float)0.018890, (float)0.029527, (float)0.021006, (float)0.025455, (float)0.023745, (float)0.020723, (float)0.020327, (float)0.020734, (float)0.020228, (float)0.019176, (float)0.017930, (float)0.022085, (float)0.017270, (float)0.023272, (float)0.022734, (float)0.018007, (float)0.037277, (float)0.020109, (float)0.025690, (float)0.023128, (float)0.027003, (float)0.024481, (float)0.020348, (float)0.029298, (float)0.019656, (float)0.020298, (float)0.032104, (float)0.017097, (float)0.020729, (float)0.016681, (float)0.029341, (float)0.013314, (float)0.022363, (float)0.015633, (float)0.018116, (float)0.030468, (float)0.020086, (float)0.021300, (float)0.028081, (float)0.017087, (float)0.034536, (float)0.021716, (float)0.024298, (float)0.016968, (float)0.021991, (float)0.014881, (float)0.019965, (float)0.016619, (float)0.024966, (float)0.023971, (float)0.019127, (float)0.023055, (float)0.020037, (float)0.024586, (float)0.024219, (float)0.019185, (float)0.023733, (float)0.024952, (float)0.021067, (float)0.016952, (float)0.022617, (float)0.016901, (float)0.025003, (float)0.018883, (float)0.019898, (float)0.020216, (float)0.020317, (float)0.024188, (float)0.019648, (float)0.018298, (float)0.018622, (float)0.067734, (float)0.018365, (float)0.014915, (float)0.023664, (float)0.082619, (float)0.025052, (float)0.040331, (float)0.018407, (float)0.032252, (float)0.033313, (float)0.016555, (float)0.020685, (float)0.026944, (float)0.015494, (float)0.018364, (float)0.018372, (float)0.034329, (float)0.038219, (float)0.016332, (float)0.015061, (float)0.015214, (float)0.020056, (float)0.033673, (float)0.021137, (float)0.027841, (float)0.019850, (float)0.021473, (float)0.023712, (float)0.025655, (float)0.022647, (float)0.016206, (float)0.016700, (float)0.024116, (float)0.016932, (float)0.025522, (float)0.016277, (float)0.029663, (float)0.037830, (float)0.018506, (float)0.017631, (float)0.028417, (float)0.029806, (float)0.021214, (float)0.021561, (float)0.021888, (float)0.021089, (float)0.024743, (float)0.023409, (float)0.019061, (float)0.017674, (float)0.027206, (float)0.034606, (float)0.016863, (float)0.018932, (float)0.024011, (float)0.022686, (float)0.017131, (float)0.022803, (float)0.017171, (float)0.019732, (float)0.017178, (float)0.019143, (float)0.014510, (float)0.032377, (float)0.022500, (float)0.018290, (float)0.021394, (float)0.030828, (float)0.021373, (float)0.020031, (float)0.023608, (float)0.028301, (float)0.018092, (float)0.023573, (float)0.019300, (float)0.018900, (float)0.019180, (float)0.022582, (float)0.031516, (float)0.026300, (float)0.016959, (float)0.020105, (float)0.019393, (float)0.041140, (float)0.015049, (float)0.033769, (float)0.052802, (float)0.028814, (float)0.019997, (float)0.020849, (float)0.020606, (float)0.021785, (float)0.013761, (float)0.021078, (float)0.015782, (float)0.018571, (float)0.025762, (float)0.037403, (float)0.032722, (float)0.021694, (float)0.017374, (float)0.018202, (float)0.019531, (float)0.052114, (float)0.015209, (float)0.018567, (float)0.022269, (float)0.020769, (float)0.065523, (float)0.016649, (float)0.036942, (float)0.020398, (float)0.016697, (float)0.022643, (float)0.023169, (float)0.025668, (float)0.046674, (float)0.018211, (float)0.021373, (float)0.020317, (float)0.018884, (float)0.018498, (float)0.016197, (float)0.024375, (float)0.016976, (float)0.018281, (float)0.014417, (float)0.028025, (float)0.020342, (float)0.026802, (float)0.018525, (float)0.023066, (float)0.015621, (float)0.023369, (float)0.020752, (float)0.025609, (float)0.018787, (float)0.030633, (float)0.024343, (float)0.090075, (float)0.022312, (float)0.021592, (float)0.016924, (float)0.020200, (float)0.017122, (float)0.022771, (float)0.015618, (float)0.029398, (float)0.019049, (float)0.027112, (float)0.017003, (float)0.016870, (float)0.021307, (float)0.016659, (float)0.015115, (float)0.022211, (float)0.020252, (float)0.018544, (float)0.014517, (float)0.013800, (float)0.029232, (float)0.016665, (float)0.019171, (float)0.016493, (float)0.019881, (float)0.020807, (float)0.020759, (float)0.012931, (float)0.020713, (float)0.017423, (float)0.030200, (float)0.027102, (float)0.025999, (float)0.015614, (float)0.018196, (float)0.020943, (float)0.021923, (float)0.024057, (float)0.018049, (float)0.015076, (float)0.025803, (float)0.018316, (float)0.018238, (float)0.016072, (float)0.018363, (float)0.028800, (float)0.016225, (float)0.022379, (float)0.019086, (float)0.020058, (float)0.015964, (float)0.030622, (float)0.018056, (float)0.020481, (float)0.026230, (float)0.025718, (float)0.024484, (float)0.048848, (float)0.020584, (float)0.017286, (float)0.023303, (float)0.020452, (float)0.025861, (float)0.021619, (float)0.017750, (float)0.017517, (float)0.022799, (float)0.037831, (float)0.019328, (float)0.030274, (float)0.018237, (float)0.019539, (float)0.019688, (float)0.028542, (float)0.021648, (float)0.017796, (float)0.014165, (float)0.020635, (float)0.015512, (float)0.024537, (float)0.018025, (float)0.017956, (float)0.021426, (float)0.023666, (float)0.025232, (float)0.017208, (float)0.014933, (float)0.029103, (float)0.023218, (float)0.017705, (float)0.020426, (float)0.015930, (float)0.023843, (float)0.024137, (float)0.015038, (float)0.024345, (float)0.019328, (float)0.025741, (float)0.019144, (float)0.024423, (float)0.015700, (float)0.023361, (float)0.018594, (float)0.017644, (float)0.022995, (float)0.018335, (float)0.039936, (float)0.016851, (float)0.031330, (float)0.018009, (float)0.020876, (float)0.028069, (float)0.024640, (float)0.019396, (float)0.015216, (float)0.013678, (float)0.021538, (float)0.015096, (float)0.016284, (float)0.019524, (float)0.018641, (float)0.020955, (float)0.020575, (float)0.014833, (float)0.019324, (float)0.019538, (float)0.018318, (float)0.019908, (float)0.020339, (float)0.021765, (float)0.022689, (float)0.020712, (float)0.023893, (float)0.018392, (float)0.017216, (float)0.017257, (float)0.026570, (float)0.015864, (float)0.017469};	// L4128
  #pragma HLS resource variable=v3523 core=ram_t2p_bram

  float v3524[512] = {(float)-0.232302, (float)-0.200935, (float)-0.122972, (float)-0.110189, (float)-0.094452, (float)-0.107273, (float)-0.135740, (float)-0.195383, (float)-0.182557, (float)-0.189005, (float)-0.143205, (float)-0.166712, (float)-0.108637, (float)-0.121344, (float)-0.161362, (float)-0.110852, (float)-0.179412, (float)-0.185288, (float)-0.142104, (float)-0.154869, (float)-0.132217, (float)-0.187041, (float)-0.172972, (float)-0.104222, (float)-0.154669, (float)-0.167919, (float)-0.184609, (float)-0.156798, (float)-0.134012, (float)-0.078551, (float)-0.166365, (float)-0.148140, (float)-0.153803, (float)-0.147544, (float)-0.147552, (float)-0.140890, (float)-0.240223, (float)-0.070726, (float)-0.051521, (float)-0.105176, (float)-0.153536, (float)-0.251397, (float)-0.196279, (float)-0.131828, (float)-0.138942, (float)-0.172649, (float)-0.206854, (float)-0.179420, (float)-0.070911, (float)-0.185128, (float)-0.133683, (float)-0.098252, (float)-0.146256, (float)-0.168510, (float)-0.135466, (float)-0.160325, (float)-0.100751, (float)-0.178750, (float)-0.217991, (float)-0.145966, (float)-0.194805, (float)-0.134796, (float)-0.201972, (float)-0.197083, (float)-0.187969, (float)-0.091100, (float)-0.177819, (float)-0.194519, (float)-0.079001, (float)-0.213767, (float)-0.108032, (float)-0.186328, (float)-0.148694, (float)-0.181970, (float)-0.108989, (float)-0.155602, (float)-0.183434, (float)-0.132527, (float)-0.190307, (float)-0.128660, (float)-0.141448, (float)-0.097824, (float)-0.096139, (float)-0.106179, (float)-0.162803, (float)-0.154933, (float)-0.193116, (float)-0.107990, (float)-0.167286, (float)0.015974, (float)-0.106103, (float)-0.082035, (float)-0.173040, (float)-0.149805, (float)-0.145115, (float)-0.153323, (float)-0.062149, (float)-0.144531, (float)-0.091818, (float)-0.184441, (float)-0.200063, (float)-0.195992, (float)-0.281586, (float)-0.105019, (float)-0.082714, (float)-0.096708, (float)-0.190664, (float)-0.204479, (float)-0.142458, (float)-0.172193, (float)-0.185631, (float)-0.148087, (float)-0.050002, (float)-0.196371, (float)-0.252936, (float)-0.130516, (float)-0.183256, (float)-0.100996, (float)-0.167824, (float)-0.090414, (float)-0.142094, (float)-0.182888, (float)-0.148279, (float)-0.160357, (float)-0.204362, (float)-0.246992, (float)-0.257437, (float)0.041143, (float)-0.104581, (float)-0.098690, (float)-0.155744, (float)-0.156297, (float)-0.119009, (float)-0.053658, (float)-0.100444, (float)-0.128948, (float)-0.147222, (float)-0.117688, (float)-0.100082, (float)-0.169749, (float)-0.118216, (float)-0.107779, (float)-0.098160, (float)-0.084792, (float)-0.115911, (float)-0.212963, (float)-0.183578, (float)-0.131023, (float)-0.129830, (float)-0.106809, (float)-0.166528, (float)-0.180043, (float)-0.190757, (float)-0.189426, (float)-0.179287, (float)-0.124778, (float)-0.158351, (float)-0.012211, (float)-0.110524, (float)-0.055824, (float)-0.128081, (float)-0.090005, (float)-0.107691, (float)-0.036224, (float)-0.180773, (float)-0.168387, (float)-0.189743, (float)-0.134360, (float)-0.143946, (float)-0.105097, (float)-0.187517, (float)-0.176032, (float)-0.060163, (float)-0.180108, (float)-0.149665, (float)-0.092921, (float)-0.168158, (float)-0.112420, (float)-0.233518, (float)-0.139173, (float)-0.158372, (float)-0.148938, (float)-0.083121, (float)-0.116465, (float)-0.111749, (float)-0.148483, (float)-0.225528, (float)-0.094978, (float)-0.320784, (float)-0.157886, (float)-0.256821, (float)-0.096258, (float)-0.153973, (float)-0.099777, (float)-0.136168, (float)-0.213496, (float)-0.203732, (float)-0.135704, (float)-0.121270, (float)-0.110177, (float)-0.194392, (float)-0.184633, (float)-0.145726, (float)-0.119995, (float)-0.151465, (float)-0.124048, (float)-0.150740, (float)-0.145879, (float)-0.183828, (float)-0.013828, (float)-0.159438, (float)-0.189359, (float)-0.191632, (float)-0.097181, (float)-0.190013, (float)-0.062310, (float)-0.102058, (float)-0.099895, (float)-0.235442, (float)-0.205990, (float)-0.158682, (float)-0.096543, (float)-0.044021, (float)-0.145041, (float)-0.243312, (float)-0.136630, (float)-0.143473, (float)-0.123434, (float)-0.099576, (float)-0.185544, (float)-0.125909, (float)-0.171286, (float)-0.207148, (float)0.367456, (float)-0.183047, (float)-0.082496, (float)-0.159248, (float)0.476678, (float)-0.177632, (float)-0.284210, (float)-0.173548, (float)-0.258689, (float)-0.091807, (float)-0.070211, (float)-0.191668, (float)-0.231592, (float)-0.142491, (float)-0.200931, (float)-0.162459, (float)-0.050567, (float)-0.174687, (float)-0.163821, (float)-0.084131, (float)-0.054895, (float)-0.151551, (float)-0.235959, (float)-0.117191, (float)-0.109222, (float)-0.003786, (float)-0.167928, (float)-0.122046, (float)-0.064560, (float)-0.178259, (float)-0.151505, (float)-0.051187, (float)-0.091795, (float)-0.081585, (float)-0.142072, (float)-0.135937, (float)0.008303, (float)-0.248446, (float)-0.188448, (float)-0.073592, (float)-0.113894, (float)-0.221322, (float)-0.177965, (float)-0.192910, (float)-0.170259, (float)-0.133447, (float)-0.209552, (float)-0.185318, (float)-0.116583, (float)-0.143818, (float)-0.188078, (float)0.143649, (float)-0.068612, (float)-0.142092, (float)-0.133502, (float)-0.152447, (float)-0.232189, (float)-0.240584, (float)-0.087056, (float)-0.139663, (float)-0.148048, (float)-0.151175, (float)-0.126180, (float)-0.124397, (float)-0.117284, (float)-0.129118, (float)-0.132612, (float)-0.111337, (float)-0.207984, (float)-0.132911, (float)-0.149755, (float)-0.146943, (float)-0.171493, (float)-0.108968, (float)-0.138324, (float)-0.047026, (float)-0.145403, (float)-0.173710, (float)-0.244259, (float)-0.130177, (float)-0.082999, (float)-0.107842, (float)-0.133776, (float)-0.145120, (float)-0.127843, (float)-0.194736, (float)-0.087655, (float)-0.128759, (float)-0.115108, (float)-0.180912, (float)-0.106765, (float)-0.179656, (float)-0.159873, (float)-0.141131, (float)-0.210445, (float)-0.118925, (float)-0.154765, (float)-0.176910, (float)-0.215166, (float)-0.254884, (float)-0.197702, (float)-0.138451, (float)-0.233902, (float)-0.248123, (float)-0.097799, (float)-0.097889, (float)-0.069748, (float)-0.125725, (float)-0.092703, (float)-0.122435, (float)-0.198584, (float)-0.157050, (float)-0.184530, (float)-0.194364, (float)-0.140669, (float)-0.131509, (float)-0.165687, (float)-0.182292, (float)-0.197263, (float)-0.130963, (float)-0.154184, (float)-0.128043, (float)-0.057010, (float)-0.153762, (float)-0.115227, (float)-0.149621, (float)-0.047698, (float)-0.151506, (float)-0.112096, (float)-0.166724, (float)-0.165059, (float)-0.041460, (float)-0.129915, (float)-0.168775, (float)-0.114300, (float)-0.056381, (float)-0.079186, (float)-0.214027, (float)-0.153466, (float)-0.308662, (float)-0.192660, (float)-0.116826, (float)-0.170450, (float)-0.136237, (float)-0.153795, (float)-0.080354, (float)-0.152580, (float)-0.112461, (float)-0.143779, (float)-0.056540, (float)-0.091854, (float)-0.142999, (float)-0.117261, (float)-0.221513, (float)-0.162438, (float)-0.227675, (float)-0.116485, (float)-0.181648, (float)-0.089875, (float)-0.053628, (float)-0.144332, (float)-0.153889, (float)-0.122333, (float)-0.139570, (float)-0.189093, (float)-0.150242, (float)-0.152174, (float)-0.107524, (float)-0.081042, (float)-0.127600, (float)-0.221178, (float)-0.074705, (float)-0.131271, (float)-0.148800, (float)-0.183152, (float)-0.100470, (float)-0.168825, (float)-0.208740, (float)-0.205517, (float)-0.056272, (float)-0.181550, (float)-0.079208, (float)-0.138109, (float)-0.092590, (float)-0.113554, (float)-0.219974, (float)-0.102614, (float)-0.194732, (float)-0.089157, (float)-0.171075, (float)-0.066090, (float)-0.198945, (float)-0.124851, (float)-0.179668, (float)-0.207942, (float)-0.175541, (float)-0.091204, (float)-0.312171, (float)-0.127823, (float)-0.137409, (float)-0.212180, (float)-0.103986, (float)-0.110434, (float)-0.202333, (float)-0.135847, (float)-0.143726, (float)-0.137832, (float)-0.153456, (float)-0.170911, (float)-0.245988, (float)-0.119525, (float)-0.122377, (float)-0.148505, (float)-0.205045, (float)-0.166311, (float)-0.121796, (float)-0.108426, (float)-0.084329, (float)-0.154539, (float)-0.162437, (float)-0.040206, (float)-0.094774, (float)-0.123349, (float)-0.124742, (float)-0.094856, (float)-0.189039, (float)-0.140897, (float)-0.195749, (float)-0.152068, (float)-0.179119, (float)-0.177113, (float)-0.079887, (float)-0.151514, (float)-0.239003, (float)-0.097860, (float)-0.137393, (float)-0.172780, (float)-0.089316, (float)-0.217160, (float)-0.152696, (float)-0.172826, (float)-0.113589, (float)-0.132474, (float)-0.220271, (float)-0.128512, (float)-0.180011, (float)-0.235956, (float)-0.147804, (float)-0.085998, (float)-0.136019, (float)-0.136589, (float)-0.195817, (float)-0.115021, (float)-0.182575, (float)-0.231534, (float)-0.128786, (float)-0.219198, (float)-0.094386, (float)-0.164513, (float)-0.198852, (float)-0.167741, (float)-0.195079, (float)-0.183487, (float)-0.051837, (float)-0.091640, (float)-0.156358, (float)-0.152678, (float)-0.183448, (float)-0.142401, (float)-0.048417, (float)-0.079919, (float)-0.092998, (float)-0.093650, (float)-0.110507, (float)-0.159363, (float)-0.145434, (float)-0.245941, (float)-0.075525, (float)-0.210594};	// L4129
  #pragma HLS resource variable=v3524 core=ram_t2p_bram

  float v3525[512] = {(float)-0.198635, (float)-0.159280, (float)-0.205440, (float)-0.159751, (float)-0.126783, (float)-0.322602, (float)-0.159702, (float)-0.347721, (float)-0.249661, (float)-0.273007, (float)-0.231932, (float)-0.028604, (float)-0.189897, (float)-0.281265, (float)-0.173262, (float)-0.241200, (float)-0.371220, (float)-0.274710, (float)-0.205253, (float)-0.258500, (float)-0.153542, (float)-0.274793, (float)-0.324058, (float)-0.252472, (float)-0.190612, (float)-0.225170, (float)-0.343567, (float)-0.220154, (float)-0.166400, (float)-0.271596, (float)-0.191981, (float)-0.339946, (float)-0.202635, (float)-0.297159, (float)-0.261564, (float)-0.223832, (float)-0.248628, (float)-0.260583, (float)-0.089288, (float)-0.357226, (float)-0.128296, (float)-0.258322, (float)-0.244954, (float)-0.152284, (float)-0.316499, (float)-0.144499, (float)-0.252168, (float)-0.196256, (float)-0.179368, (float)-0.107088, (float)-0.166188, (float)-0.205255, (float)-0.252968, (float)-0.144727, (float)-0.251718, (float)-0.206196, (float)-0.281670, (float)-0.337613, (float)-0.138244, (float)-0.238891, (float)-0.255711, (float)-0.015554, (float)-0.216885, (float)-0.176316, (float)-0.148643, (float)-0.212185, (float)-0.200180, (float)-0.071553, (float)-0.208908, (float)-0.357989, (float)-0.258831, (float)-0.359925, (float)-0.152776, (float)-0.210741, (float)-0.292484, (float)-0.185539, (float)-0.397034, (float)-0.125722, (float)-0.257364, (float)-0.241233, (float)-0.086334, (float)-0.306480, (float)-0.270061, (float)-0.337952, (float)-0.248466, (float)-0.193549, (float)-0.298651, (float)-0.227864, (float)-0.359965, (float)-0.276432, (float)-0.248049, (float)-0.120810, (float)-0.337792, (float)-0.266138, (float)-0.167728, (float)-0.247002, (float)-0.215158, (float)-0.259118, (float)-0.193646, (float)-0.154288, (float)-0.411724, (float)-0.156958, (float)-0.237157, (float)-0.299713, (float)-0.212358, (float)-0.203400, (float)-0.184828, (float)-0.306988, (float)-0.343761, (float)-0.183858, (float)-0.193655, (float)-0.091612, (float)-0.233758, (float)-0.355788, (float)-0.196726, (float)-0.330299, (float)-0.139834, (float)-0.217654, (float)-0.166528, (float)-0.185734, (float)-0.311453, (float)-0.104899, (float)-0.422929, (float)-0.240815, (float)-0.132040, (float)-0.163091, (float)-0.337840, (float)-0.330003, (float)-0.318321, (float)-0.226779, (float)-0.278663, (float)-0.194961, (float)-0.194987, (float)-0.146256, (float)-0.243719, (float)-0.229727, (float)-0.128243, (float)-0.216404, (float)-0.117926, (float)-0.243669, (float)-0.261094, (float)-0.265609, (float)-0.194772, (float)-0.120835, (float)-0.166772, (float)-0.135053, (float)-0.271304, (float)-0.056007, (float)-0.224252, (float)-0.131812, (float)-0.235599, (float)-0.272038, (float)-0.205063, (float)-0.173640, (float)-0.289066, (float)-0.262726, (float)-0.335823, (float)-0.177874, (float)-0.230911, (float)-0.147696, (float)-0.268536, (float)-0.188245, (float)-0.262892, (float)-0.198329, (float)-0.352163, (float)-0.190481, (float)-0.277790, (float)-0.339548, (float)-0.289472, (float)-0.224038, (float)-0.114972, (float)-0.246249, (float)-0.242611, (float)-0.258111, (float)-0.313325, (float)-0.231534, (float)-0.227076, (float)-0.207734, (float)-0.210885, (float)-0.137085, (float)-0.132296, (float)-0.252940, (float)-0.171612, (float)-0.253187, (float)-0.227680, (float)-0.208407, (float)-0.180303, (float)-0.186834, (float)-0.240367, (float)-0.216608, (float)-0.219689, (float)-0.287034, (float)-0.306171, (float)-0.150719, (float)-0.105436, (float)-0.219935, (float)-0.241527, (float)-0.331005, (float)-0.269987, (float)-0.156821, (float)-0.144899, (float)-0.261037, (float)-0.182827, (float)-0.264791, (float)-0.313404, (float)-0.293743, (float)-0.268707, (float)-0.211493, (float)-0.216372, (float)-0.452181, (float)-0.299851, (float)-0.303153, (float)-0.229169, (float)-0.309911, (float)-0.264202, (float)-0.269489, (float)-0.144062, (float)-0.167143, (float)-0.156979, (float)-0.141488, (float)-0.222238, (float)-0.173627, (float)-0.148146, (float)-0.257285, (float)-0.206039, (float)-0.170317, (float)-0.235997, (float)-0.176952, (float)-0.213227, (float)-0.201556, (float)-0.300095, (float)-0.151790, (float)-0.208563, (float)-0.280471, (float)-0.269795, (float)-0.229193, (float)-0.129287, (float)-0.251390, (float)-0.260037, (float)-0.245432, (float)-0.174379, (float)-0.102882, (float)-0.167894, (float)-0.235278, (float)-0.200725, (float)-0.336331, (float)-0.164050, (float)-0.242959, (float)-0.169863, (float)-0.169697, (float)-0.183738, (float)-0.162455, (float)-0.241503, (float)-0.268742, (float)-0.230482, (float)-0.202916, (float)-0.220905, (float)-0.224020, (float)-0.267481, (float)-0.323331, (float)0.146213, (float)-0.477669, (float)-0.237640, (float)-0.148853, (float)-0.146244, (float)-0.305496, (float)-0.223361, (float)-0.169727, (float)-0.195171, (float)-0.213050, (float)-0.233987, (float)-0.203905, (float)-0.305400, (float)-0.259589, (float)-0.347015, (float)-0.217554, (float)-0.270612, (float)-0.289733, (float)-0.172889, (float)-0.230001, (float)-0.106558, (float)-0.355581, (float)-0.291246, (float)-0.177713, (float)-0.200747, (float)-0.169918, (float)-0.300875, (float)-0.304572, (float)-0.169294, (float)-0.260249, (float)-0.205322, (float)-0.180969, (float)-0.180788, (float)-0.172978, (float)-0.375723, (float)-0.180822, (float)-0.180544, (float)-0.189487, (float)-0.264252, (float)-0.207542, (float)-0.236463, (float)-0.197528, (float)-0.306371, (float)-0.198389, (float)-0.181054, (float)-0.367628, (float)-0.119818, (float)-0.148455, (float)-0.176971, (float)-0.078079, (float)-0.205227, (float)-0.136028, (float)-0.141746, (float)-0.169058, (float)-0.239485, (float)-0.178486, (float)-0.174669, (float)-0.248379, (float)-0.271685, (float)-0.309555, (float)-0.146468, (float)-0.223885, (float)-0.258417, (float)-0.357162, (float)-0.231054, (float)-0.287848, (float)-0.384136, (float)-0.347452, (float)-0.389585, (float)-0.189110, (float)-0.286117, (float)-0.243095, (float)-0.283685, (float)-0.436487, (float)-0.335263, (float)-0.180239, (float)-0.197564, (float)-0.152912, (float)-0.197830, (float)-0.253538, (float)-0.195395, (float)-0.266740, (float)-0.281316, (float)-0.248707, (float)-0.307038, (float)-0.233905, (float)-0.221150, (float)-0.192464, (float)-0.222371, (float)-0.417830, (float)-0.315056, (float)-0.266301, (float)-0.358100, (float)-0.193531, (float)-0.238467, (float)-0.242361, (float)-0.185004, (float)-0.226484, (float)-0.180310, (float)-0.077689, (float)-0.149226, (float)-0.336118, (float)-0.413346, (float)-0.312267, (float)-0.274504, (float)-0.124697, (float)-0.310247, (float)0.004149, (float)-0.198112, (float)-0.330072, (float)-0.204688, (float)-0.105279, (float)-0.165321, (float)-0.163434, (float)-0.111551, (float)-0.231402, (float)-0.319092, (float)-0.181831, (float)-0.265720, (float)-0.221983, (float)-0.102949, (float)-0.199872, (float)-0.270191, (float)-0.213872, (float)-0.225551, (float)-0.265250, (float)-0.162972, (float)-0.332166, (float)-0.161663, (float)-0.344593, (float)0.028774, (float)-0.245563, (float)-0.317107, (float)-0.357985, (float)-0.285660, (float)-0.251980, (float)-0.203063, (float)-0.152176, (float)-0.220265, (float)-0.348986, (float)-0.168507, (float)-0.142427, (float)-0.160224, (float)-0.155327, (float)-0.305684, (float)-0.241994, (float)-0.353634, (float)-0.055081, (float)-0.098713, (float)-0.227165, (float)-0.261876, (float)-0.203461, (float)-0.090587, (float)-0.197606, (float)-0.303963, (float)-0.273170, (float)-0.316085, (float)-0.210227, (float)-0.338416, (float)-0.173969, (float)-0.147459, (float)-0.184161, (float)-0.182304, (float)-0.115078, (float)-0.218291, (float)-0.200986, (float)-0.265908, (float)-0.220454, (float)-0.256738, (float)-0.163324, (float)-0.221288, (float)-0.265817, (float)-0.293830, (float)-0.106918, (float)-0.252185, (float)-0.110302, (float)-0.221646, (float)-0.224405, (float)-0.290811, (float)-0.217623, (float)-0.360512, (float)-0.237444, (float)-0.239137, (float)-0.225083, (float)-0.225597, (float)-0.133864, (float)-0.197039, (float)-0.296969, (float)-0.220620, (float)-0.205085, (float)-0.222900, (float)-0.360189, (float)-0.292274, (float)-0.249828, (float)-0.146556, (float)-0.097893, (float)-0.168627, (float)-0.215751, (float)-0.288114, (float)-0.300222, (float)-0.276004, (float)-0.249589, (float)-0.353595, (float)-0.286838, (float)-0.325114, (float)-0.184698, (float)-0.306160, (float)-0.386136, (float)-0.264980, (float)-0.133942, (float)-0.184593, (float)-0.163013, (float)-0.062955, (float)-0.171709, (float)-0.141548, (float)-0.190569, (float)-0.461079, (float)-0.139061, (float)-0.191997, (float)-0.136922, (float)-0.164662, (float)-0.005524, (float)-0.259823, (float)-0.265267, (float)-0.231897, (float)-0.178000, (float)-0.191288, (float)-0.205495, (float)-0.189086, (float)-0.262499, (float)-0.163345, (float)-0.249750, (float)-0.169640, (float)-0.190729, (float)-0.243125, (float)-0.182511, (float)-0.260706, (float)-0.194282, (float)-0.236066, (float)-0.058098, (float)-0.275778, (float)-0.259300, (float)-0.146562, (float)-0.358905, (float)-0.043869, (float)-0.344004, (float)-0.108874, (float)-0.421938, (float)-0.150348, (float)-0.279242, (float)-0.303465, (float)-0.115635};	// L4130
  #pragma HLS resource variable=v3525 core=ram_t2p_bram

  float v3526[512] = {(float)0.242738, (float)0.223229, (float)0.251088, (float)0.228825, (float)0.207412, (float)0.290541, (float)0.248232, (float)0.310215, (float)0.274875, (float)0.289230, (float)0.244753, (float)0.175929, (float)0.242616, (float)0.277998, (float)0.231506, (float)0.263106, (float)0.338313, (float)0.278466, (float)0.253569, (float)0.298945, (float)0.233532, (float)0.281249, (float)0.348573, (float)0.277822, (float)0.228034, (float)0.254681, (float)0.303198, (float)0.246762, (float)0.251219, (float)0.297292, (float)0.257664, (float)0.319988, (float)0.238466, (float)0.271371, (float)0.253153, (float)0.262516, (float)0.334373, (float)0.262634, (float)0.183769, (float)0.283901, (float)0.218676, (float)0.266551, (float)0.285818, (float)0.247110, (float)0.291457, (float)0.233155, (float)0.263742, (float)0.269146, (float)0.243248, (float)0.238433, (float)0.235601, (float)0.252514, (float)0.256354, (float)0.245073, (float)0.252895, (float)0.252250, (float)0.279956, (float)0.316502, (float)0.233972, (float)0.263354, (float)0.256883, (float)0.194176, (float)0.262103, (float)0.220502, (float)0.230072, (float)0.232253, (float)0.281094, (float)0.189740, (float)0.227982, (float)0.347183, (float)0.271688, (float)0.319123, (float)0.243989, (float)0.271895, (float)0.278139, (float)0.226162, (float)0.344388, (float)0.264784, (float)0.272536, (float)0.285112, (float)0.203887, (float)0.293511, (float)0.274228, (float)0.277399, (float)0.265362, (float)0.243014, (float)0.272139, (float)0.270834, (float)0.308537, (float)0.289527, (float)0.259586, (float)0.214701, (float)0.311861, (float)0.344944, (float)0.226181, (float)0.281367, (float)0.232603, (float)0.271219, (float)0.263690, (float)0.232319, (float)0.333319, (float)0.271424, (float)0.299137, (float)0.274671, (float)0.251543, (float)0.239413, (float)0.270857, (float)0.283572, (float)0.286577, (float)0.240797, (float)0.256005, (float)0.204830, (float)0.239414, (float)0.281327, (float)0.326718, (float)0.276053, (float)0.212269, (float)0.271543, (float)0.254019, (float)0.277094, (float)0.320890, (float)0.190511, (float)0.398912, (float)0.267578, (float)0.235663, (float)0.216938, (float)0.321555, (float)0.359597, (float)0.283838, (float)0.264836, (float)0.270211, (float)0.246857, (float)0.244201, (float)0.255279, (float)0.259854, (float)0.269251, (float)0.239868, (float)0.269991, (float)0.206276, (float)0.271124, (float)0.283362, (float)0.278073, (float)0.252874, (float)0.201308, (float)0.234309, (float)0.208181, (float)0.306341, (float)0.163521, (float)0.267299, (float)0.219724, (float)0.278701, (float)0.272365, (float)0.274440, (float)0.228724, (float)0.296922, (float)0.266241, (float)0.298229, (float)0.239561, (float)0.303906, (float)0.231925, (float)0.277275, (float)0.266073, (float)0.289807, (float)0.248948, (float)0.305993, (float)0.261240, (float)0.293731, (float)0.304544, (float)0.299858, (float)0.258004, (float)0.209265, (float)0.271366, (float)0.299270, (float)0.267889, (float)0.296296, (float)0.275384, (float)0.257953, (float)0.256569, (float)0.263375, (float)0.232545, (float)0.244152, (float)0.293402, (float)0.239776, (float)0.263149, (float)0.285050, (float)0.286958, (float)0.223889, (float)0.240993, (float)0.267589, (float)0.268111, (float)0.263831, (float)0.273174, (float)0.281168, (float)0.220254, (float)0.266969, (float)0.276436, (float)0.254976, (float)0.316048, (float)0.288816, (float)0.261468, (float)0.217815, (float)0.248495, (float)0.241365, (float)0.279753, (float)0.287232, (float)0.276727, (float)0.255150, (float)0.242932, (float)0.245879, (float)0.328794, (float)0.302417, (float)0.291177, (float)0.262525, (float)0.301930, (float)0.264317, (float)0.272079, (float)0.210763, (float)0.236752, (float)0.226902, (float)0.198820, (float)0.283030, (float)0.256911, (float)0.234938, (float)0.275530, (float)0.244206, (float)0.271696, (float)0.274690, (float)0.278527, (float)0.251553, (float)0.222659, (float)0.278269, (float)0.246469, (float)0.265156, (float)0.264124, (float)0.296017, (float)0.267127, (float)0.267868, (float)0.253713, (float)0.284713, (float)0.250700, (float)0.252451, (float)0.202384, (float)0.231072, (float)0.261772, (float)0.276418, (float)0.303103, (float)0.245168, (float)0.271560, (float)0.227330, (float)0.229452, (float)0.261116, (float)0.232895, (float)0.268972, (float)0.275259, (float)0.273658, (float)0.259012, (float)0.242071, (float)0.268511, (float)0.339180, (float)0.307252, (float)0.137076, (float)0.365011, (float)0.298036, (float)0.245969, (float)0.248711, (float)0.291247, (float)0.270354, (float)0.255993, (float)0.221280, (float)0.256874, (float)0.266119, (float)0.236722, (float)0.274177, (float)0.284701, (float)0.305502, (float)0.267062, (float)0.281862, (float)0.279052, (float)0.240121, (float)0.254914, (float)0.221047, (float)0.350725, (float)0.285211, (float)0.216223, (float)0.282136, (float)0.236936, (float)0.290523, (float)0.282647, (float)0.230002, (float)0.274461, (float)0.243744, (float)0.252203, (float)0.248898, (float)0.239529, (float)0.285060, (float)0.288684, (float)0.262105, (float)0.250022, (float)0.268917, (float)0.242713, (float)0.300962, (float)0.306657, (float)0.286106, (float)0.238744, (float)0.246162, (float)0.285928, (float)0.255025, (float)0.263029, (float)0.244164, (float)0.214544, (float)0.289764, (float)0.228232, (float)0.232676, (float)0.224215, (float)0.273758, (float)0.248482, (float)0.237869, (float)0.305787, (float)0.279779, (float)0.276106, (float)0.225152, (float)0.286625, (float)0.266006, (float)0.325035, (float)0.261215, (float)0.276718, (float)0.320541, (float)0.293245, (float)0.318326, (float)0.293882, (float)0.310258, (float)0.255299, (float)0.298073, (float)0.366746, (float)0.308639, (float)0.225385, (float)0.235182, (float)0.234786, (float)0.255469, (float)0.259705, (float)0.236874, (float)0.301747, (float)0.277597, (float)0.272827, (float)0.317445, (float)0.278549, (float)0.272122, (float)0.263707, (float)0.270200, (float)0.363315, (float)0.286896, (float)0.267537, (float)0.340459, (float)0.258697, (float)0.273187, (float)0.274671, (float)0.282137, (float)0.275032, (float)0.262962, (float)0.201825, (float)0.235759, (float)0.303436, (float)0.315534, (float)0.301280, (float)0.277486, (float)0.251089, (float)0.294482, (float)0.160482, (float)0.282515, (float)0.296418, (float)0.219357, (float)0.206085, (float)0.233200, (float)0.234764, (float)0.266315, (float)0.254269, (float)0.292666, (float)0.221489, (float)0.252101, (float)0.282715, (float)0.199326, (float)0.245316, (float)0.259724, (float)0.265365, (float)0.275675, (float)0.264962, (float)0.244407, (float)0.294905, (float)0.230785, (float)0.307080, (float)0.190391, (float)0.302415, (float)0.278632, (float)0.365939, (float)0.296625, (float)0.274562, (float)0.244938, (float)0.220149, (float)0.256353, (float)0.285268, (float)0.239166, (float)0.245727, (float)0.246669, (float)0.237418, (float)0.266365, (float)0.245967, (float)0.318188, (float)0.179343, (float)0.237876, (float)0.259582, (float)0.284720, (float)0.245217, (float)0.197415, (float)0.238787, (float)0.294851, (float)0.287885, (float)0.278605, (float)0.276464, (float)0.329610, (float)0.253012, (float)0.268977, (float)0.254731, (float)0.233338, (float)0.234827, (float)0.268967, (float)0.271771, (float)0.267890, (float)0.251561, (float)0.271041, (float)0.236629, (float)0.260149, (float)0.276431, (float)0.287993, (float)0.200767, (float)0.263671, (float)0.226324, (float)0.251057, (float)0.260447, (float)0.280525, (float)0.298889, (float)0.296537, (float)0.259692, (float)0.276733, (float)0.255258, (float)0.295895, (float)0.251213, (float)0.292514, (float)0.300836, (float)0.242281, (float)0.239387, (float)0.270826, (float)0.370442, (float)0.287928, (float)0.253228, (float)0.224844, (float)0.202289, (float)0.227922, (float)0.236583, (float)0.308202, (float)0.297956, (float)0.290909, (float)0.277748, (float)0.429307, (float)0.265800, (float)0.294045, (float)0.241794, (float)0.281646, (float)0.324692, (float)0.264662, (float)0.221609, (float)0.275780, (float)0.242125, (float)0.207775, (float)0.233235, (float)0.227066, (float)0.261117, (float)0.365041, (float)0.201653, (float)0.259769, (float)0.215959, (float)0.264116, (float)0.140771, (float)0.266422, (float)0.250156, (float)0.255299, (float)0.222699, (float)0.241697, (float)0.269631, (float)0.238818, (float)0.283297, (float)0.233322, (float)0.266676, (float)0.222427, (float)0.269119, (float)0.270981, (float)0.245862, (float)0.267364, (float)0.242962, (float)0.259345, (float)0.185116, (float)0.295006, (float)0.366398, (float)0.221177, (float)0.302595, (float)0.184028, (float)0.344339, (float)0.213992, (float)0.371655, (float)0.236002, (float)0.308054, (float)0.263847, (float)0.223318};	// L4131
  #pragma HLS resource variable=v3526 core=ram_t2p_bram

  float v3527[512] = {(float)0.102969, (float)0.099928, (float)0.127914, (float)0.099059, (float)0.100430, (float)0.121449, (float)0.162097, (float)0.100043, (float)0.159959, (float)0.122664, (float)0.105262, (float)0.142098, (float)0.102029, (float)0.132221, (float)0.100326, (float)0.106438, (float)0.136585, (float)0.124613, (float)0.130006, (float)0.198400, (float)0.116320, (float)0.149600, (float)0.162998, (float)0.126596, (float)0.106612, (float)0.121217, (float)0.106790, (float)0.112300, (float)0.161500, (float)0.165558, (float)0.130312, (float)0.143827, (float)0.114844, (float)0.123655, (float)0.116569, (float)0.115679, (float)0.192961, (float)0.104196, (float)0.090405, (float)0.095586, (float)0.106340, (float)0.084078, (float)0.116300, (float)0.134858, (float)0.117626, (float)0.164849, (float)0.111461, (float)0.122224, (float)0.126947, (float)0.188003, (float)0.109027, (float)0.127952, (float)0.121110, (float)0.144697, (float)0.085655, (float)0.120671, (float)0.112938, (float)0.120395, (float)0.130486, (float)0.117947, (float)0.116683, (float)0.245552, (float)0.202163, (float)0.097515, (float)0.126310, (float)0.104477, (float)0.208212, (float)0.083050, (float)0.103759, (float)0.123070, (float)0.112443, (float)0.110532, (float)0.146693, (float)0.133561, (float)0.128758, (float)0.110741, (float)0.136630, (float)0.181454, (float)0.128223, (float)0.130604, (float)0.119954, (float)0.105619, (float)0.118920, (float)0.120361, (float)0.111300, (float)0.098627, (float)0.103261, (float)0.122012, (float)0.117761, (float)0.149702, (float)0.111549, (float)0.113045, (float)0.120670, (float)0.137210, (float)0.098998, (float)0.146081, (float)0.098501, (float)0.118389, (float)0.150684, (float)0.128408, (float)0.108534, (float)0.140632, (float)0.175394, (float)0.109470, (float)0.097672, (float)0.094074, (float)0.179887, (float)0.107252, (float)0.079623, (float)0.115265, (float)0.118862, (float)0.145173, (float)0.109861, (float)0.136122, (float)0.259220, (float)0.080983, (float)0.109804, (float)0.157304, (float)0.127159, (float)0.183668, (float)0.136026, (float)0.095853, (float)0.140319, (float)0.130310, (float)0.134171, (float)0.096452, (float)0.128541, (float)0.221489, (float)0.124658, (float)0.118763, (float)0.120368, (float)0.116297, (float)0.100566, (float)0.171091, (float)0.103555, (float)0.121105, (float)0.136119, (float)0.119264, (float)0.097030, (float)0.110434, (float)0.133113, (float)0.124958, (float)0.116818, (float)0.088458, (float)0.116332, (float)0.089325, (float)0.168050, (float)0.093430, (float)0.124383, (float)0.118799, (float)0.163994, (float)0.108056, (float)0.131044, (float)0.123868, (float)0.126921, (float)0.097171, (float)0.121111, (float)0.104287, (float)0.229385, (float)0.120757, (float)0.101777, (float)0.114841, (float)0.147212, (float)0.097454, (float)0.130895, (float)0.131667, (float)0.191380, (float)0.108085, (float)0.149058, (float)0.113174, (float)0.099293, (float)0.116667, (float)0.147313, (float)0.120351, (float)0.101188, (float)0.120051, (float)0.106186, (float)0.119047, (float)0.133610, (float)0.120395, (float)0.141070, (float)0.181610, (float)0.113411, (float)0.111433, (float)0.173537, (float)0.177542, (float)0.121546, (float)0.138897, (float)0.098290, (float)0.139586, (float)0.120764, (float)0.106274, (float)0.113612, (float)0.124812, (float)0.263905, (float)0.148459, (float)0.107708, (float)0.106114, (float)0.155084, (float)0.172677, (float)0.125083, (float)0.136005, (float)0.121585, (float)0.152622, (float)0.110289, (float)0.104515, (float)0.085658, (float)0.110004, (float)0.119019, (float)0.125474, (float)0.158541, (float)0.126997, (float)0.132823, (float)0.125616, (float)0.107881, (float)0.128350, (float)0.071472, (float)0.116252, (float)0.137530, (float)0.082056, (float)0.146145, (float)0.121004, (float)0.122692, (float)0.114094, (float)0.107170, (float)0.149235, (float)0.120269, (float)0.208620, (float)0.113120, (float)0.074732, (float)0.138501, (float)0.149575, (float)0.128722, (float)0.099209, (float)0.133543, (float)0.151521, (float)0.186073, (float)0.113070, (float)0.164859, (float)0.093683, (float)0.136206, (float)0.095898, (float)0.087026, (float)0.118172, (float)0.144881, (float)0.157680, (float)0.125008, (float)0.129811, (float)0.125173, (float)0.101626, (float)0.178735, (float)0.113597, (float)0.120398, (float)0.112605, (float)0.129529, (float)0.137083, (float)0.113586, (float)0.146883, (float)0.160778, (float)0.099425, (float)0.234304, (float)0.139662, (float)0.114545, (float)0.133579, (float)0.142977, (float)0.112115, (float)0.138883, (float)0.163318, (float)0.105025, (float)0.153779, (float)0.109543, (float)0.113140, (float)0.100522, (float)0.141127, (float)0.113207, (float)0.102092, (float)0.139891, (float)0.104518, (float)0.122020, (float)0.130258, (float)0.154121, (float)0.142526, (float)0.121724, (float)0.094121, (float)0.230927, (float)0.099665, (float)0.092804, (float)0.126329, (float)0.125531, (float)0.088600, (float)0.124690, (float)0.129280, (float)0.107645, (float)0.141442, (float)0.093475, (float)0.137658, (float)0.166226, (float)0.145095, (float)0.105080, (float)0.111591, (float)0.132086, (float)0.189528, (float)0.136962, (float)0.134989, (float)0.128502, (float)0.095144, (float)0.184310, (float)0.213431, (float)0.153420, (float)0.175178, (float)0.172102, (float)0.098957, (float)0.151034, (float)0.105176, (float)0.136074, (float)0.146286, (float)0.160968, (float)0.159597, (float)0.115675, (float)0.088342, (float)0.112243, (float)0.118787, (float)0.118149, (float)0.135604, (float)0.130526, (float)0.107419, (float)0.109284, (float)0.118020, (float)0.096058, (float)0.221776, (float)0.137604, (float)0.115087, (float)0.137037, (float)0.129592, (float)0.100529, (float)0.091615, (float)0.112613, (float)0.092674, (float)0.143197, (float)0.097747, (float)0.123528, (float)0.142610, (float)0.138156, (float)0.138650, (float)0.117726, (float)0.131527, (float)0.128811, (float)0.119234, (float)0.137690, (float)0.136844, (float)0.146846, (float)0.108803, (float)0.131052, (float)0.121582, (float)0.107816, (float)0.123804, (float)0.137003, (float)0.105249, (float)0.188565, (float)0.169428, (float)0.132624, (float)0.131426, (float)0.108044, (float)0.109634, (float)0.121790, (float)0.172380, (float)0.130916, (float)0.095925, (float)0.140335, (float)0.123459, (float)0.095284, (float)0.156764, (float)0.151655, (float)0.119709, (float)0.245863, (float)0.125804, (float)0.096682, (float)0.093338, (float)0.062390, (float)0.131068, (float)0.090356, (float)0.129776, (float)0.114087, (float)0.110646, (float)0.107882, (float)0.111276, (float)0.123109, (float)0.141226, (float)0.116038, (float)0.156117, (float)0.267777, (float)0.161008, (float)0.117126, (float)0.198059, (float)0.123219, (float)0.120907, (float)0.102412, (float)0.102818, (float)0.136985, (float)0.079203, (float)0.124966, (float)0.140690, (float)0.142933, (float)0.125776, (float)0.113467, (float)0.114388, (float)0.118252, (float)0.111282, (float)0.190332, (float)0.106768, (float)0.136849, (float)0.118526, (float)0.113189, (float)0.118171, (float)0.105632, (float)0.092010, (float)0.104149, (float)0.152369, (float)0.152479, (float)0.135482, (float)0.233237, (float)0.143558, (float)0.149689, (float)0.196908, (float)0.162862, (float)0.168064, (float)0.112899, (float)0.138323, (float)0.148283, (float)0.118987, (float)0.135336, (float)0.118192, (float)0.120108, (float)0.100727, (float)0.114601, (float)0.177554, (float)0.111874, (float)0.109587, (float)0.111309, (float)0.158084, (float)0.098303, (float)0.124443, (float)0.145842, (float)0.113721, (float)0.137052, (float)0.180867, (float)0.213040, (float)0.137236, (float)0.093852, (float)0.104700, (float)0.131116, (float)0.191763, (float)0.123431, (float)0.093901, (float)0.121040, (float)0.138561, (float)0.090314, (float)0.117834, (float)0.160101, (float)0.157086, (float)0.146179, (float)0.153154, (float)0.296101, (float)0.097116, (float)0.138284, (float)0.116281, (float)0.093932, (float)0.117921, (float)0.106596, (float)0.147237, (float)0.130546, (float)0.143004, (float)0.119795, (float)0.130636, (float)0.182460, (float)0.133858, (float)0.104615, (float)0.070947, (float)0.158399, (float)0.100164, (float)0.149495, (float)0.160381, (float)0.142217, (float)0.114640, (float)0.090272, (float)0.089960, (float)0.122854, (float)0.156734, (float)0.126246, (float)0.116253, (float)0.150747, (float)0.102566, (float)0.122289, (float)0.140423, (float)0.136450, (float)0.118191, (float)0.092278, (float)0.118940, (float)0.109218, (float)0.106868, (float)0.123438, (float)0.233763, (float)0.122934, (float)0.111006, (float)0.098920, (float)0.113283, (float)0.093151, (float)0.158288, (float)0.123618, (float)0.139493, (float)0.110941, (float)0.105699};	// L4132
  #pragma HLS resource variable=v3527 core=ram_t2p_bram

  float v3528[512] = {(float)-0.112399, (float)-0.116439, (float)-0.129277, (float)-0.418715, (float)-0.384113, (float)-0.407468, (float)-0.531776, (float)-0.182379, (float)-0.757418, (float)-0.839405, (float)-0.191102, (float)-0.269664, (float)-0.438940, (float)-0.266877, (float)-0.433000, (float)-0.476784, (float)-0.496500, (float)-0.473768, (float)-0.141513, (float)-0.424507, (float)-0.328492, (float)-0.526421, (float)-0.812645, (float)-0.401106, (float)-0.314249, (float)-0.458406, (float)-0.166297, (float)-0.485648, (float)-0.343087, (float)-0.518310, (float)-0.432761, (float)-0.672563, (float)-0.433207, (float)-0.405020, (float)-0.183107, (float)-0.453480, (float)-1.013503, (float)-0.009113, (float)-0.477304, (float)-0.384145, (float)-0.501301, (float)-0.742657, (float)-0.499172, (float)-0.586968, (float)-0.360770, (float)-0.475071, (float)-0.608605, (float)-0.376767, (float)-0.692520, (float)-1.217636, (float)-0.516137, (float)-0.412293, (float)-0.321387, (float)-0.153690, (float)-0.332965, (float)-0.330429, (float)-0.437467, (float)-0.581860, (float)-0.476988, (float)-0.594429, (float)-0.250872, (float)0.262500, (float)0.104237, (float)-0.336077, (float)-0.432966, (float)-0.400236, (float)-0.367752, (float)-0.366686, (float)-0.219613, (float)-0.646535, (float)-0.588735, (float)-0.385367, (float)-0.330557, (float)-0.378576, (float)-0.231806, (float)-0.097445, (float)-1.031814, (float)-0.880079, (float)-0.327233, (float)-0.494126, (float)-0.603831, (float)-0.408300, (float)-0.125906, (float)-0.115601, (float)-0.178602, (float)-0.555274, (float)-0.710459, (float)-0.266660, (float)-0.167976, (float)-0.007352, (float)-0.246322, (float)-0.336113, (float)0.157182, (float)-0.601864, (float)-0.468605, (float)-0.357834, (float)-0.581191, (float)-0.211286, (float)-0.359057, (float)-0.529334, (float)-0.772094, (float)-0.584602, (float)-0.112900, (float)-0.413537, (float)-0.496495, (float)-0.675932, (float)-0.407701, (float)-0.489354, (float)-0.332871, (float)-0.368918, (float)-0.013880, (float)-0.110656, (float)-0.328942, (float)0.049362, (float)-0.104944, (float)0.032464, (float)-0.214452, (float)-0.058529, (float)-0.365958, (float)-0.295750, (float)-0.087778, (float)-0.647347, (float)-0.895826, (float)-0.520704, (float)-0.475582, (float)-0.335130, (float)-0.542062, (float)0.092361, (float)-0.920866, (float)0.061003, (float)0.073713, (float)-0.368023, (float)-0.701119, (float)-0.591840, (float)-0.508094, (float)-0.459119, (float)-0.515429, (float)-0.318958, (float)-0.623240, (float)-0.551153, (float)-0.481386, (float)-0.430723, (float)-0.291835, (float)-0.212256, (float)-0.218935, (float)-0.402839, (float)-0.156959, (float)-0.109874, (float)-0.391399, (float)-0.388566, (float)-0.150173, (float)-0.452671, (float)-0.167128, (float)-0.202127, (float)-0.532084, (float)-0.264351, (float)-0.520682, (float)-0.553412, (float)-0.551886, (float)-0.306945, (float)-0.232572, (float)-0.570877, (float)-0.616357, (float)-0.011549, (float)-0.664122, (float)-0.572931, (float)-0.274999, (float)-0.572013, (float)-0.768450, (float)-0.436126, (float)-0.352616, (float)-0.042565, (float)-0.134978, (float)-0.883548, (float)-0.321707, (float)-0.170556, (float)-0.428356, (float)-0.449698, (float)-0.726382, (float)-0.958914, (float)-0.343854, (float)-0.679991, (float)-0.451969, (float)-0.545850, (float)-0.299316, (float)-0.485377, (float)-0.141496, (float)-0.028968, (float)-0.272937, (float)-0.166597, (float)-0.234621, (float)-0.539686, (float)-0.472434, (float)-0.560607, (float)-0.564710, (float)-0.361384, (float)-0.515817, (float)-0.272838, (float)-0.043191, (float)-0.942049, (float)-0.528378, (float)-0.623554, (float)-0.383542, (float)-0.682523, (float)-0.534687, (float)-0.412121, (float)-0.265564, (float)-0.576051, (float)-0.337885, (float)-0.767888, (float)-0.833459, (float)-0.563115, (float)-0.371247, (float)-0.016989, (float)-0.509873, (float)-0.519588, (float)-0.261680, (float)-0.563200, (float)-0.631046, (float)-0.524374, (float)-0.219218, (float)-0.424097, (float)-0.213002, (float)-0.276040, (float)-0.177244, (float)-0.571938, (float)-0.403344, (float)-0.787354, (float)-0.322614, (float)-0.267134, (float)-0.342526, (float)-0.710991, (float)-0.442178, (float)-0.131834, (float)-0.384127, (float)-0.405017, (float)-0.510206, (float)-0.486478, (float)-0.541453, (float)-0.479047, (float)-0.486675, (float)-0.248170, (float)-0.534675, (float)0.137316, (float)-0.928146, (float)-0.379055, (float)-0.039265, (float)-0.650038, (float)-0.068735, (float)-0.255033, (float)-0.783301, (float)-0.190591, (float)0.069200, (float)-0.520266, (float)0.110204, (float)-0.469053, (float)-0.216485, (float)-0.405797, (float)-0.525246, (float)-0.548900, (float)-0.224316, (float)-0.891227, (float)-0.575327, (float)-0.378748, (float)-0.466015, (float)-0.416706, (float)-0.794753, (float)-0.221377, (float)0.216941, (float)-0.323023, (float)-0.571629, (float)-0.452323, (float)-0.223508, (float)-0.535418, (float)-0.618674, (float)-0.640286, (float)-0.577882, (float)-0.697379, (float)-0.453077, (float)-0.455918, (float)-0.674158, (float)-0.865837, (float)-0.641282, (float)-0.309825, (float)0.412202, (float)-0.481322, (float)-0.526779, (float)0.134130, (float)-0.112282, (float)-0.386807, (float)-0.668274, (float)-0.402017, (float)-0.470466, (float)-0.526314, (float)-0.491210, (float)-0.434492, (float)0.067518, (float)-0.731700, (float)-0.346691, (float)-0.475672, (float)-0.484478, (float)-0.166603, (float)-0.554598, (float)-0.287519, (float)-0.557369, (float)-0.292941, (float)-0.917794, (float)0.093173, (float)-0.347311, (float)-0.265892, (float)-0.870023, (float)-0.414276, (float)-0.669144, (float)-0.389632, (float)-0.399296, (float)-0.358292, (float)-0.964411, (float)-0.541634, (float)-0.311702, (float)0.178528, (float)-0.497123, (float)-0.843553, (float)-0.628203, (float)-0.511303, (float)-0.099860, (float)-0.383422, (float)-0.433000, (float)-0.408400, (float)-0.426940, (float)-0.566965, (float)-0.559916, (float)0.200167, (float)-0.358192, (float)-0.762071, (float)-0.425684, (float)-0.474864, (float)-0.267235, (float)-0.444904, (float)-0.463114, (float)-0.505526, (float)-0.321621, (float)-0.542648, (float)-0.261515, (float)-0.569461, (float)-0.298140, (float)-0.844004, (float)-0.623715, (float)-0.664250, (float)-0.469105, (float)-0.932553, (float)-0.612922, (float)0.098774, (float)-0.838134, (float)-0.273548, (float)-0.229909, (float)-0.588052, (float)-0.210117, (float)-0.051954, (float)-0.821773, (float)-0.846684, (float)-0.161722, (float)-0.224413, (float)-0.436564, (float)-0.120466, (float)-0.575075, (float)-0.679570, (float)-0.405034, (float)-0.067879, (float)-0.840527, (float)-0.454655, (float)-0.170813, (float)-0.048041, (float)-0.158716, (float)-0.373385, (float)-0.889646, (float)0.082504, (float)-0.759268, (float)-0.459439, (float)-0.267621, (float)-0.114515, (float)-0.302276, (float)-0.245612, (float)-0.364465, (float)-0.354500, (float)-0.824092, (float)-0.173027, (float)-0.257509, (float)-0.010339, (float)-0.393497, (float)-0.703393, (float)-0.291880, (float)-0.279310, (float)-0.396569, (float)-0.712801, (float)-0.521117, (float)-0.718786, (float)-0.407343, (float)-0.281441, (float)-0.229254, (float)-0.452871, (float)-0.677881, (float)-0.093355, (float)-0.327243, (float)-0.363757, (float)-0.204797, (float)-0.272021, (float)-0.368346, (float)-0.333415, (float)-0.640944, (float)-0.280670, (float)-0.424596, (float)-0.068290, (float)-0.343726, (float)-0.146595, (float)-0.625573, (float)-0.431924, (float)-0.185842, (float)-0.181652, (float)-0.767884, (float)-0.335338, (float)-0.958843, (float)-0.195242, (float)-0.200604, (float)-0.128025, (float)-0.404694, (float)-0.223926, (float)-0.624653, (float)-0.342209, (float)-0.559487, (float)-0.702609, (float)0.035447, (float)-0.581416, (float)-0.738228, (float)-0.390357, (float)-0.340927, (float)-0.863017, (float)-0.345280, (float)-0.156938, (float)-0.671733, (float)-0.521623, (float)-0.232921, (float)-0.356420, (float)-0.758426, (float)-0.012366, (float)-0.539764, (float)-0.770848, (float)-0.335878, (float)-0.290856, (float)-0.313259, (float)-0.339998, (float)-0.562364, (float)-0.549299, (float)-0.463665, (float)-0.402154, (float)-0.357964, (float)-0.332480, (float)-0.338387, (float)-0.227683, (float)-0.269677, (float)-0.290673, (float)-0.216382, (float)-0.248912, (float)-0.057300, (float)-0.373486, (float)-0.399569, (float)-0.345078, (float)-0.464810, (float)-0.714298, (float)-0.206166, (float)-0.251282, (float)-0.446420, (float)-0.262376, (float)-0.161453, (float)-0.309853, (float)-0.747986, (float)-0.775115, (float)-0.338349, (float)-0.287491, (float)-0.597623, (float)-0.375151, (float)-0.944747, (float)0.977841, (float)-0.525900, (float)-0.011899, (float)-0.312199, (float)-0.380173, (float)-0.769012, (float)-0.353425, (float)-0.326794, (float)-0.388225, (float)-0.487052, (float)-0.440380, (float)-0.677326, (float)-0.491474, (float)-0.489073, (float)-0.331316, (float)-0.649739, (float)-0.530273, (float)-0.619254, (float)-0.806289, (float)-0.435616, (float)-0.046601, (float)-0.677238, (float)-0.735951, (float)-0.638833, (float)-0.419857, (float)-0.457520, (float)-0.577571, (float)-0.564816, (float)-0.250951, (float)-0.275274, (float)-0.486037};	// L4133
  #pragma HLS resource variable=v3528 core=ram_t2p_bram

  float v3529[256] = {(float)-0.016245, (float)-0.203263, (float)0.029385, (float)-0.169664, (float)-0.183951, (float)-0.030897, (float)-0.203861, (float)-0.142588, (float)-0.044317, (float)-0.088597, (float)-0.064677, (float)-0.096849, (float)-0.037978, (float)-0.207329, (float)-0.306056, (float)0.144284, (float)-0.307884, (float)-0.123179, (float)-0.162712, (float)-0.098041, (float)-0.247118, (float)-0.283653, (float)-0.120123, (float)-0.289314, (float)-0.230311, (float)-0.356210, (float)-0.082497, (float)-0.348327, (float)0.070732, (float)-0.132077, (float)-0.107421, (float)-0.145144, (float)0.023506, (float)0.022505, (float)-0.188479, (float)-0.250710, (float)-0.246110, (float)0.063148, (float)-0.002294, (float)-0.120950, (float)-0.258070, (float)-0.164026, (float)-0.017193, (float)-0.114291, (float)-0.209634, (float)-0.015776, (float)0.012847, (float)-0.133163, (float)-0.313940, (float)-0.229356, (float)-0.152731, (float)-0.350311, (float)0.208646, (float)0.078491, (float)-0.159745, (float)-0.198988, (float)0.034600, (float)0.038818, (float)-0.126883, (float)0.101943, (float)0.098149, (float)-0.038957, (float)-0.253741, (float)-0.135554, (float)-0.179615, (float)-0.242240, (float)-0.451653, (float)-0.312450, (float)-0.017678, (float)-0.261494, (float)-0.156722, (float)0.021168, (float)-0.075348, (float)-0.142621, (float)-0.278794, (float)0.006175, (float)-0.189471, (float)-0.232739, (float)-0.129768, (float)-0.120019, (float)-0.191670, (float)-0.098714, (float)-0.191551, (float)-0.166586, (float)-0.272923, (float)0.128678, (float)-0.462026, (float)-0.225932, (float)-0.227040, (float)0.193910, (float)0.023026, (float)-0.330260, (float)-0.320158, (float)-0.129240, (float)-0.071557, (float)0.004831, (float)-0.257935, (float)-0.011567, (float)-0.055650, (float)-0.122925, (float)-0.480394, (float)-0.235115, (float)-0.136698, (float)-0.057786, (float)-0.053713, (float)-0.274276, (float)-0.082687, (float)-0.192167, (float)-0.348090, (float)-0.035842, (float)-0.109360, (float)0.013808, (float)-0.188810, (float)-0.259163, (float)-0.329339, (float)-0.082037, (float)-0.183938, (float)-0.163550, (float)-0.316315, (float)-0.024608, (float)-0.166662, (float)-0.165285, (float)-0.307553, (float)-0.222890, (float)-0.183395, (float)-0.053620, (float)-0.062063, (float)-0.175165, (float)-0.524255, (float)-0.193342, (float)-0.111859, (float)-0.228255, (float)-0.043679, (float)-0.177694, (float)-0.130007, (float)-0.251926, (float)-0.045575, (float)-0.630507, (float)-0.136383, (float)-0.213837, (float)0.040575, (float)-0.528653, (float)-0.201392, (float)-0.144229, (float)-0.192954, (float)-0.303300, (float)0.103006, (float)-0.149919, (float)-0.229681, (float)-0.530064, (float)-0.254274, (float)-0.041712, (float)0.042858, (float)-0.321792, (float)-0.161135, (float)-0.256175, (float)-0.118742, (float)-0.100078, (float)0.022491, (float)0.099644, (float)-0.213848, (float)-0.201887, (float)0.080756, (float)-0.012101, (float)-0.236381, (float)-0.324670, (float)-0.148193, (float)-0.484607, (float)-0.344871, (float)-0.136469, (float)-0.666387, (float)0.041802, (float)-0.280741, (float)-0.096090, (float)-0.237802, (float)-0.183354, (float)-0.189028, (float)-0.037668, (float)-0.305603, (float)-0.184272, (float)-0.135655, (float)-0.303846, (float)-0.267961, (float)-0.414308, (float)-0.263275, (float)-0.174954, (float)-0.185577, (float)-0.240538, (float)-0.108238, (float)-0.225023, (float)-0.126790, (float)-0.109350, (float)0.059438, (float)-0.141892, (float)-0.117792, (float)-0.160157, (float)-0.032850, (float)-0.019429, (float)-0.198540, (float)0.046975, (float)-0.188651, (float)-0.277640, (float)-0.093020, (float)-0.409246, (float)-0.337848, (float)-0.725179, (float)0.026007, (float)-0.182911, (float)0.056122, (float)-0.222686, (float)-0.002551, (float)-0.321779, (float)-0.009302, (float)-0.284284, (float)-0.512142, (float)-0.233748, (float)-0.083571, (float)-0.081786, (float)-0.129600, (float)-0.209036, (float)0.016879, (float)-0.189866, (float)-0.189163, (float)-0.307490, (float)-0.310809, (float)-0.298639, (float)-0.471174, (float)-0.182340, (float)-0.189275, (float)-0.313145, (float)-0.087605, (float)-0.116606, (float)-0.299515, (float)-0.083107, (float)-0.342664, (float)-0.077193, (float)-0.145986, (float)-0.161113, (float)0.020350, (float)-0.062725, (float)-0.060997, (float)-0.257375, (float)-0.138255, (float)0.046971, (float)-0.030197, (float)-0.163756, (float)-0.332289, (float)-0.174150, (float)-0.630677, (float)-0.077151, (float)-0.212325, (float)-0.155853, (float)-0.045911, (float)-0.241584, (float)-0.014343, (float)-0.207857};	// L4134
  #pragma HLS resource variable=v3529 core=ram_t2p_bram

  float v3530[256] = {(float)0.197083, (float)0.177063, (float)0.130256, (float)0.199495, (float)0.183903, (float)0.093385, (float)0.233283, (float)0.223625, (float)0.165396, (float)0.127999, (float)0.084225, (float)0.108512, (float)0.316751, (float)0.203194, (float)0.324606, (float)0.218361, (float)0.320812, (float)0.282439, (float)0.340799, (float)0.333867, (float)0.330713, (float)0.557144, (float)0.282054, (float)0.308072, (float)0.211382, (float)0.297131, (float)0.236138, (float)0.549991, (float)0.122082, (float)0.338117, (float)0.152827, (float)0.154387, (float)0.198245, (float)0.058198, (float)0.181202, (float)0.248904, (float)0.195430, (float)0.070545, (float)0.091757, (float)0.132818, (float)0.261582, (float)0.201262, (float)0.072013, (float)0.157323, (float)0.191896, (float)0.081277, (float)0.116971, (float)0.250426, (float)0.286264, (float)0.303238, (float)0.147590, (float)0.369600, (float)0.186970, (float)0.209749, (float)0.190654, (float)0.236384, (float)0.164152, (float)0.107897, (float)0.253063, (float)0.170326, (float)0.126562, (float)0.081425, (float)0.240692, (float)0.260912, (float)0.270503, (float)0.212843, (float)0.500701, (float)0.237510, (float)0.080245, (float)0.289631, (float)0.177601, (float)0.088677, (float)0.109387, (float)0.183369, (float)0.281203, (float)0.197087, (float)0.202083, (float)0.344269, (float)0.141080, (float)0.136165, (float)0.267635, (float)0.161836, (float)0.272281, (float)0.272662, (float)0.252797, (float)0.098169, (float)0.470705, (float)0.223911, (float)0.364941, (float)0.198725, (float)0.081468, (float)0.254280, (float)0.332248, (float)0.156143, (float)0.233612, (float)0.129416, (float)0.257032, (float)0.169978, (float)0.137449, (float)0.221491, (float)0.501533, (float)0.313217, (float)0.148703, (float)0.117356, (float)0.091607, (float)0.213016, (float)0.139292, (float)0.305655, (float)0.563450, (float)0.101800, (float)0.099411, (float)0.049198, (float)0.442658, (float)0.314225, (float)0.400163, (float)0.133425, (float)0.217355, (float)0.552157, (float)0.280600, (float)0.278423, (float)0.433314, (float)0.260157, (float)0.378775, (float)0.182663, (float)0.266373, (float)0.107714, (float)0.300150, (float)0.242794, (float)0.513047, (float)0.082872, (float)0.125387, (float)0.199579, (float)0.145117, (float)0.225259, (float)0.146747, (float)0.371155, (float)0.079381, (float)0.542518, (float)0.205773, (float)0.210267, (float)0.128751, (float)0.499309, (float)0.181521, (float)0.184518, (float)0.415396, (float)0.381719, (float)0.205408, (float)0.220500, (float)0.147142, (float)0.496439, (float)0.420158, (float)0.080098, (float)0.062257, (float)0.353560, (float)0.276026, (float)0.383971, (float)0.163176, (float)0.140242, (float)0.267423, (float)0.084425, (float)0.230524, (float)0.225906, (float)0.214586, (float)0.418085, (float)0.282106, (float)0.292584, (float)0.341571, (float)0.464038, (float)0.302510, (float)0.373204, (float)0.587109, (float)0.061605, (float)0.279668, (float)0.304214, (float)0.217345, (float)0.354958, (float)0.209598, (float)0.244930, (float)0.342777, (float)0.286756, (float)0.354334, (float)0.466692, (float)0.322005, (float)0.380490, (float)0.263234, (float)0.215985, (float)0.192379, (float)0.407367, (float)0.496558, (float)0.362302, (float)0.166981, (float)0.132087, (float)0.237372, (float)0.211823, (float)0.152241, (float)0.166782, (float)0.383586, (float)0.098273, (float)0.372934, (float)0.394324, (float)0.435339, (float)0.226984, (float)0.150788, (float)0.313302, (float)0.384988, (float)0.577444, (float)0.189226, (float)0.282158, (float)0.090682, (float)0.236430, (float)0.096440, (float)0.235968, (float)0.069868, (float)0.293818, (float)0.510049, (float)0.334802, (float)0.233938, (float)0.114513, (float)0.215459, (float)0.226613, (float)0.282874, (float)0.234118, (float)0.189083, (float)0.290554, (float)0.268075, (float)0.387578, (float)0.391480, (float)0.184427, (float)0.188864, (float)0.440469, (float)0.140498, (float)0.346018, (float)0.272350, (float)0.256695, (float)0.278544, (float)0.114821, (float)0.160654, (float)0.175425, (float)0.088254, (float)0.164943, (float)0.126761, (float)0.235614, (float)0.281092, (float)0.076576, (float)0.142417, (float)0.168344, (float)0.397862, (float)0.268495, (float)0.638344, (float)0.108743, (float)0.318036, (float)0.176041, (float)0.363429, (float)0.261512, (float)0.199873, (float)0.254116};	// L4135
  #pragma HLS resource variable=v3530 core=ram_t2p_bram

  float v3531[256] = {(float)0.018530, (float)0.026394, (float)0.012856, (float)0.012689, (float)0.014751, (float)0.015978, (float)0.012460, (float)0.018145, (float)0.019383, (float)0.011628, (float)0.007526, (float)0.011219, (float)0.034934, (float)0.017682, (float)0.020756, (float)0.025356, (float)0.023623, (float)0.019827, (float)0.022904, (float)0.034381, (float)0.019890, (float)0.053809, (float)0.031563, (float)0.019644, (float)0.012794, (float)0.019174, (float)0.019996, (float)0.028697, (float)0.018158, (float)0.027271, (float)0.011315, (float)0.011837, (float)0.021068, (float)0.008485, (float)0.016900, (float)0.015894, (float)0.012585, (float)0.015643, (float)0.009987, (float)0.008934, (float)0.018547, (float)0.015648, (float)0.008220, (float)0.013122, (float)0.011694, (float)0.010160, (float)0.010536, (float)0.024400, (float)0.013983, (float)0.016112, (float)0.011215, (float)0.016260, (float)0.029490, (float)0.035517, (float)0.014957, (float)0.020074, (float)0.017436, (float)0.011895, (float)0.020108, (float)0.035077, (float)0.018778, (float)0.012123, (float)0.013372, (float)0.023718, (float)0.024176, (float)0.017590, (float)0.028278, (float)0.014679, (float)0.010504, (float)0.016922, (float)0.024693, (float)0.018485, (float)0.010362, (float)0.016711, (float)0.013731, (float)0.022465, (float)0.011501, (float)0.024804, (float)0.012025, (float)0.012570, (float)0.021939, (float)0.016975, (float)0.017424, (float)0.021701, (float)0.017643, (float)0.019817, (float)0.023719, (float)0.012252, (float)0.027208, (float)0.060497, (float)0.011410, (float)0.012758, (float)0.019986, (float)0.019867, (float)0.022465, (float)0.019493, (float)0.016528, (float)0.023030, (float)0.018762, (float)0.020904, (float)0.021493, (float)0.024125, (float)0.012632, (float)0.014381, (float)0.012692, (float)0.009812, (float)0.016465, (float)0.016313, (float)0.040332, (float)0.015335, (float)0.014138, (float)0.005016, (float)0.033883, (float)0.015893, (float)0.022616, (float)0.012452, (float)0.017113, (float)0.045386, (float)0.016545, (float)0.031452, (float)0.041772, (float)0.022630, (float)0.024911, (float)0.016146, (float)0.019939, (float)0.010476, (float)0.027228, (float)0.014376, (float)0.027456, (float)0.011228, (float)0.009946, (float)0.009961, (float)0.020141, (float)0.018478, (float)0.009278, (float)0.020743, (float)0.008191, (float)0.028920, (float)0.015118, (float)0.013835, (float)0.016313, (float)0.021079, (float)0.012747, (float)0.013377, (float)0.040637, (float)0.025386, (float)0.021835, (float)0.015742, (float)0.008617, (float)0.018719, (float)0.034042, (float)0.009114, (float)0.006896, (float)0.021932, (float)0.020435, (float)0.033022, (float)0.020678, (float)0.012721, (float)0.040421, (float)0.014042, (float)0.014963, (float)0.016277, (float)0.047124, (float)0.053335, (float)0.014413, (float)0.016945, (float)0.024771, (float)0.022726, (float)0.016246, (float)0.039784, (float)0.025942, (float)0.006863, (float)0.016802, (float)0.020793, (float)0.018885, (float)0.023745, (float)0.015412, (float)0.022586, (float)0.018481, (float)0.020519, (float)0.029992, (float)0.050411, (float)0.018868, (float)0.017426, (float)0.014016, (float)0.018388, (float)0.023564, (float)0.040373, (float)0.069144, (float)0.027295, (float)0.020721, (float)0.016795, (float)0.023665, (float)0.018622, (float)0.014306, (float)0.011317, (float)0.042427, (float)0.014678, (float)0.021902, (float)0.043384, (float)0.044179, (float)0.011020, (float)0.017952, (float)0.014674, (float)0.015806, (float)0.025305, (float)0.023667, (float)0.021030, (float)0.011405, (float)0.019686, (float)0.011575, (float)0.013539, (float)0.009093, (float)0.020994, (float)0.023689, (float)0.025597, (float)0.033564, (float)0.016578, (float)0.015100, (float)0.013169, (float)0.029548, (float)0.026140, (float)0.016542, (float)0.013860, (float)0.011822, (float)0.020687, (float)0.018049, (float)0.009810, (float)0.016161, (float)0.039758, (float)0.011737, (float)0.032446, (float)0.013650, (float)0.022535, (float)0.017262, (float)0.012099, (float)0.009317, (float)0.011607, (float)0.011387, (float)0.019526, (float)0.014283, (float)0.010255, (float)0.020608, (float)0.011115, (float)0.016965, (float)0.013392, (float)0.022404, (float)0.021118, (float)0.039554, (float)0.007481, (float)0.024169, (float)0.012689, (float)0.036180, (float)0.016522, (float)0.018249, (float)0.016171};	// L4136
  #pragma HLS resource variable=v3531 core=ram_t2p_bram

  float v3532[256] = {(float)-0.082312, (float)-0.033227, (float)-0.026646, (float)-0.013217, (float)-0.063828, (float)-0.104692, (float)-0.067094, (float)-0.053039, (float)0.062327, (float)-0.000111, (float)-0.012984, (float)0.017784, (float)-0.049284, (float)-0.065327, (float)-0.098474, (float)0.211247, (float)-0.092193, (float)-0.113936, (float)-0.187878, (float)-0.082167, (float)-0.058521, (float)-0.559937, (float)-0.051197, (float)-0.198668, (float)-0.071481, (float)-0.066465, (float)-0.168375, (float)-0.103121, (float)0.105447, (float)-0.230613, (float)-0.033933, (float)-0.080676, (float)-0.003466, (float)0.047170, (float)-0.078841, (float)-0.126503, (float)-0.061497, (float)0.064309, (float)0.027830, (float)0.003133, (float)-0.076740, (float)-0.095088, (float)0.000138, (float)-0.047186, (float)-0.030897, (float)-0.046435, (float)-0.063253, (float)-0.081402, (float)-0.070531, (float)-0.067097, (float)-0.079232, (float)-0.177784, (float)0.055108, (float)0.411084, (float)0.001561, (float)-0.079884, (float)-0.069195, (float)-0.049812, (float)0.003836, (float)0.002520, (float)0.035645, (float)-0.025757, (float)-0.122488, (float)-0.046376, (float)-0.121627, (float)-0.064273, (float)-0.138339, (float)-0.023200, (float)-0.018081, (float)-0.147026, (float)0.048809, (float)-0.055714, (float)-0.034797, (float)-0.056561, (float)-0.065104, (float)-0.104747, (float)-0.052624, (float)-0.185086, (float)-0.106039, (float)0.026538, (float)0.071723, (float)-0.019967, (float)-0.112256, (float)-0.200571, (float)-0.103172, (float)0.004091, (float)-0.224197, (float)-0.127268, (float)-0.088721, (float)0.108202, (float)-0.058866, (float)-0.083435, (float)-0.104600, (float)0.023022, (float)-0.088489, (float)0.033548, (float)-0.110725, (float)-0.009239, (float)-0.045979, (float)-0.136995, (float)-0.202196, (float)0.046265, (float)-0.019667, (float)-0.011913, (float)-0.060050, (float)-0.075059, (float)-0.072690, (float)-0.091073, (float)-0.092056, (float)-0.058019, (float)-0.036355, (float)-0.044718, (float)-0.170913, (float)-0.136799, (float)-0.147614, (float)-0.147590, (float)-0.112343, (float)-0.230801, (float)-0.090601, (float)-0.259308, (float)-0.208255, (float)-0.063401, (float)-0.268006, (float)-0.161228, (float)-0.100256, (float)-0.131830, (float)-0.090434, (float)-0.096675, (float)-0.197284, (float)0.053544, (float)-0.027836, (float)-0.074435, (float)-0.056267, (float)-0.059114, (float)-0.024094, (float)-0.151039, (float)0.002181, (float)-0.188863, (float)-0.128863, (float)-0.019607, (float)-0.072803, (float)-0.184000, (float)-0.060926, (float)-0.020046, (float)-0.403146, (float)-0.073355, (float)-0.095973, (float)-0.086466, (float)-0.068302, (float)-0.168954, (float)-0.098700, (float)0.012385, (float)-0.044298, (float)-0.193734, (float)-0.132867, (float)-0.120692, (float)-0.142336, (float)0.104760, (float)-0.085365, (float)0.063847, (float)-0.057782, (float)-0.086523, (float)0.033596, (float)-0.387682, (float)-0.057414, (float)-0.075301, (float)-0.207186, (float)-0.182655, (float)-0.123786, (float)-0.220588, (float)-0.164540, (float)-0.029335, (float)-0.130926, (float)-0.158500, (float)-0.043881, (float)-0.138688, (float)-0.061651, (float)-0.019781, (float)-0.122039, (float)-0.076332, (float)-0.356170, (float)0.341274, (float)-0.065834, (float)-0.126368, (float)-0.175434, (float)0.041658, (float)-0.036161, (float)-0.128932, (float)-0.270402, (float)-0.214051, (float)0.019383, (float)0.013128, (float)-0.009500, (float)-0.060263, (float)-0.034165, (float)-0.079913, (float)-0.317163, (float)-0.034097, (float)-0.169743, (float)-0.122081, (float)-0.309284, (float)-0.122529, (float)-0.028297, (float)-0.151813, (float)-0.093257, (float)-0.283448, (float)-0.003030, (float)-0.035894, (float)0.003011, (float)-0.046019, (float)-0.085464, (float)-0.038165, (float)-0.017352, (float)-0.082586, (float)-0.150925, (float)-0.176884, (float)-0.150072, (float)0.001534, (float)-0.087669, (float)-0.033261, (float)-0.254497, (float)-0.012980, (float)-0.046881, (float)-0.088381, (float)-0.089857, (float)-0.191141, (float)-0.131301, (float)-0.035002, (float)-0.114926, (float)-0.188881, (float)-0.040911, (float)-0.381905, (float)-0.089706, (float)-0.170198, (float)-0.154573, (float)0.030685, (float)-0.040941, (float)-0.036983, (float)-0.069053, (float)-0.042029, (float)0.053512, (float)-0.131176, (float)-0.119942, (float)-0.057783, (float)-0.054637, (float)-0.123350, (float)-0.116191, (float)-0.123229, (float)-0.252074, (float)-0.041003, (float)-0.105637, (float)-0.052183, (float)-0.241468, (float)-0.094696, (float)-0.156377, (float)-0.122982};	// L4137
  #pragma HLS resource variable=v3532 core=ram_t2p_bram

  float v3533[256] = {(float)-0.133214, (float)-0.064444, (float)-0.323875, (float)-0.239039, (float)-0.326220, (float)-0.179559, (float)-0.208659, (float)-0.320836, (float)-0.187442, (float)-0.298805, (float)-0.209937, (float)-0.228288, (float)-0.214078, (float)-0.245966, (float)-0.276796, (float)-0.135078, (float)-0.249833, (float)-0.239290, (float)-0.122324, (float)-0.459029, (float)-0.217210, (float)-0.121966, (float)-0.210134, (float)-0.177912, (float)-0.242619, (float)-0.154622, (float)-0.154925, (float)-0.371626, (float)-0.281672, (float)-0.388609, (float)-0.154490, (float)-0.068677, (float)-0.341201, (float)-0.226082, (float)-0.196129, (float)-0.224238, (float)-0.298387, (float)-0.138098, (float)-0.225115, (float)-0.165752, (float)-0.453374, (float)-0.322573, (float)-0.097736, (float)-0.134867, (float)-0.261947, (float)-0.142808, (float)-0.396050, (float)-0.163345, (float)-0.210092, (float)-0.116093, (float)-0.144819, (float)-0.550154, (float)-0.217875, (float)-0.124579, (float)0.050221, (float)-0.190218, (float)-0.104652, (float)-0.099972, (float)-0.141065, (float)-0.312444, (float)-0.219041, (float)-0.306164, (float)-0.124671, (float)-0.155663, (float)-0.297321, (float)-0.382461, (float)-0.195100, (float)-0.138092, (float)-0.576052, (float)-0.387944, (float)-0.280753, (float)-0.254198, (float)-0.347019, (float)-0.246020, (float)-0.109053, (float)-0.056168, (float)-0.183284, (float)-0.495630, (float)-0.305902, (float)-0.098782, (float)-0.225456, (float)-0.195824, (float)-0.132007, (float)-0.173788, (float)-0.228728, (float)-0.192558, (float)-0.092404, (float)-0.342682, (float)-0.548922, (float)-0.243081, (float)-0.193513, (float)-0.164142, (float)-0.250291, (float)-0.327355, (float)-0.400776, (float)-0.282362, (float)-0.269382, (float)-0.193880, (float)-0.241272, (float)-0.030905, (float)-0.088015, (float)-0.342131, (float)-0.310449, (float)-0.110157, (float)-0.153949, (float)-0.123325, (float)-0.178033, (float)-0.271506, (float)-0.200460, (float)-0.184582, (float)-0.284287, (float)-0.111685, (float)-0.181633, (float)-0.211910, (float)-0.330439, (float)-0.226671, (float)-0.141322, (float)-0.337637, (float)-0.267428, (float)-0.252407, (float)-0.255380, (float)-0.473517, (float)-0.234194, (float)-0.213038, (float)-0.328168, (float)-0.196613, (float)-0.106321, (float)-0.261463, (float)-0.423371, (float)-0.137416, (float)-0.081062, (float)-0.306943, (float)-0.153817, (float)-0.145295, (float)-0.161228, (float)-0.163069, (float)-0.375850, (float)-0.260815, (float)-0.238250, (float)-0.249911, (float)-0.148469, (float)-0.148726, (float)-0.432819, (float)-0.137658, (float)-0.278101, (float)-0.225946, (float)-0.207203, (float)-0.416503, (float)-0.358211, (float)-0.138224, (float)-0.359833, (float)-0.267221, (float)-0.208982, (float)-0.017715, (float)-0.127906, (float)-0.281210, (float)-0.362077, (float)0.047602, (float)-0.223232, (float)-0.127153, (float)-0.323714, (float)-0.300843, (float)-0.111896, (float)-0.083946, (float)-0.242635, (float)-0.200009, (float)-0.187291, (float)-0.468492, (float)-0.199976, (float)-0.346223, (float)-0.070560, (float)-0.197347, (float)-0.354795, (float)-0.197491, (float)-0.353741, (float)-0.354628, (float)-0.143281, (float)-0.205225, (float)-0.272155, (float)-0.152756, (float)-0.279767, (float)-0.194508, (float)-0.247417, (float)-0.491016, (float)0.132207, (float)-0.237834, (float)-0.516559, (float)-0.395906, (float)-0.235377, (float)-0.126617, (float)-0.080985, (float)-0.413208, (float)-0.557567, (float)-0.223787, (float)-0.156350, (float)-0.395036, (float)-0.328337, (float)-0.084629, (float)-0.310310, (float)-0.312971, (float)-0.149776, (float)-0.139644, (float)-0.097234, (float)-0.161957, (float)-0.163142, (float)-0.636406, (float)-0.135030, (float)-0.234509, (float)-0.104853, (float)-0.162499, (float)-0.287795, (float)-0.245024, (float)-0.146850, (float)-0.203473, (float)-0.535771, (float)-0.168296, (float)-0.552396, (float)-0.251135, (float)-0.122984, (float)-0.230478, (float)-0.192514, (float)-0.375949, (float)-0.101441, (float)-0.169663, (float)-0.400249, (float)-0.297984, (float)-0.303460, (float)-0.156281, (float)-0.465962, (float)-0.115537, (float)-0.166486, (float)-0.338201, (float)-0.293534, (float)-0.312157, (float)-0.301493, (float)-0.326061, (float)-0.254199, (float)-0.203715, (float)-0.095477, (float)-0.206962, (float)-0.437046, (float)-0.205060, (float)-0.420465, (float)-0.312456, (float)-0.484535, (float)-0.352765, (float)-0.262413, (float)-0.289421, (float)-0.397609, (float)-0.210660, (float)-0.179051, (float)-0.107529, (float)-0.121296, (float)-0.302165, (float)0.051579, (float)-0.192754};	// L4138
  #pragma HLS resource variable=v3533 core=ram_t2p_bram

  float v3534[256] = {(float)0.248004, (float)0.197221, (float)0.227915, (float)0.270937, (float)0.329617, (float)0.263992, (float)0.271038, (float)0.347507, (float)0.238823, (float)0.290421, (float)0.276932, (float)0.304482, (float)0.226830, (float)0.263404, (float)0.299885, (float)0.239654, (float)0.272437, (float)0.272277, (float)0.213278, (float)0.380557, (float)0.276681, (float)0.240271, (float)0.240643, (float)0.291698, (float)0.267530, (float)0.230546, (float)0.239432, (float)0.312264, (float)0.298412, (float)0.335303, (float)0.223426, (float)0.191874, (float)0.316781, (float)0.262574, (float)0.290077, (float)0.291755, (float)0.345481, (float)0.256062, (float)0.243417, (float)0.229806, (float)0.331795, (float)0.348086, (float)0.203156, (float)0.247785, (float)0.247750, (float)0.248303, (float)0.325223, (float)0.256749, (float)0.268470, (float)0.197736, (float)0.254135, (float)0.407943, (float)0.248038, (float)0.207616, (float)0.227621, (float)0.268264, (float)0.209837, (float)0.205637, (float)0.201043, (float)0.356013, (float)0.238443, (float)0.328386, (float)0.195169, (float)0.244480, (float)0.284825, (float)0.374165, (float)0.274620, (float)0.211680, (float)0.385899, (float)0.478451, (float)0.300522, (float)0.284849, (float)0.376245, (float)0.290297, (float)0.212571, (float)0.177562, (float)0.277798, (float)0.387786, (float)0.312289, (float)0.197362, (float)0.267901, (float)0.229997, (float)0.247368, (float)0.231969, (float)0.263528, (float)0.281929, (float)0.229565, (float)0.319441, (float)0.381395, (float)0.250263, (float)0.226861, (float)0.267645, (float)0.343139, (float)0.379892, (float)0.378657, (float)0.296827, (float)0.302131, (float)0.257482, (float)0.300692, (float)0.193874, (float)0.194984, (float)0.321728, (float)0.362303, (float)0.217116, (float)0.248580, (float)0.226643, (float)0.213327, (float)0.285148, (float)0.271466, (float)0.271985, (float)0.310700, (float)0.217368, (float)0.267532, (float)0.238684, (float)0.343367, (float)0.276101, (float)0.208426, (float)0.297540, (float)0.317776, (float)0.281832, (float)0.285849, (float)0.349836, (float)0.267530, (float)0.263775, (float)0.315932, (float)0.287927, (float)0.187316, (float)0.298574, (float)0.358417, (float)0.256991, (float)0.181488, (float)0.275838, (float)0.263985, (float)0.248594, (float)0.256725, (float)0.225200, (float)0.341978, (float)0.290998, (float)0.289778, (float)0.290217, (float)0.240370, (float)0.238109, (float)0.363321, (float)0.269005, (float)0.380985, (float)0.294719, (float)0.274345, (float)0.464418, (float)0.313274, (float)0.244387, (float)0.347697, (float)0.300125, (float)0.197695, (float)0.230124, (float)0.251274, (float)0.266026, (float)0.327121, (float)0.162206, (float)0.227351, (float)0.222519, (float)0.359638, (float)0.321504, (float)0.199726, (float)0.221497, (float)0.270638, (float)0.283085, (float)0.262063, (float)0.370977, (float)0.272955, (float)0.290309, (float)0.189265, (float)0.213956, (float)0.245996, (float)0.314081, (float)0.242442, (float)0.369932, (float)0.236427, (float)0.242000, (float)0.294799, (float)0.249748, (float)0.275993, (float)0.268643, (float)0.289536, (float)0.385712, (float)0.139844, (float)0.283177, (float)0.336180, (float)0.252237, (float)0.282348, (float)0.238055, (float)0.231099, (float)0.327437, (float)0.407818, (float)0.264824, (float)0.252499, (float)0.338782, (float)0.325136, (float)0.241992, (float)0.285595, (float)0.360523, (float)0.260303, (float)0.229410, (float)0.248266, (float)0.217122, (float)0.235323, (float)0.411717, (float)0.258756, (float)0.288844, (float)0.197249, (float)0.240768, (float)0.275538, (float)0.303093, (float)0.245712, (float)0.274405, (float)0.356421, (float)0.254601, (float)0.367256, (float)0.288264, (float)0.258973, (float)0.302077, (float)0.288963, (float)0.350464, (float)0.209174, (float)0.295303, (float)0.322194, (float)0.292542, (float)0.257395, (float)0.301156, (float)0.389332, (float)0.221066, (float)0.222639, (float)0.325820, (float)0.320490, (float)0.297501, (float)0.232316, (float)0.332266, (float)0.281247, (float)0.270204, (float)0.229953, (float)0.284602, (float)0.331768, (float)0.229250, (float)0.349766, (float)0.262185, (float)0.358054, (float)0.400306, (float)0.292357, (float)0.304933, (float)0.347845, (float)0.284454, (float)0.274175, (float)0.201888, (float)0.246647, (float)0.298755, (float)0.204366, (float)0.269054};	// L4139
  #pragma HLS resource variable=v3534 core=ram_t2p_bram

  float v3535[256] = {(float)0.202093, (float)0.264854, (float)0.081632, (float)0.114109, (float)0.127637, (float)0.123027, (float)0.178034, (float)0.139318, (float)0.123479, (float)0.117826, (float)0.128063, (float)0.150515, (float)0.105954, (float)0.095384, (float)0.114740, (float)0.126009, (float)0.083070, (float)0.221375, (float)0.145195, (float)0.125999, (float)0.120253, (float)0.150707, (float)0.106624, (float)0.303817, (float)0.144419, (float)0.126642, (float)0.196604, (float)0.114546, (float)0.137646, (float)0.099110, (float)0.122224, (float)0.134298, (float)0.106592, (float)0.114780, (float)0.194646, (float)0.158945, (float)0.171481, (float)0.158772, (float)0.157699, (float)0.099467, (float)0.103577, (float)0.130468, (float)0.154715, (float)0.162316, (float)0.143723, (float)0.162410, (float)0.085646, (float)0.218325, (float)0.133880, (float)0.080743, (float)0.152815, (float)0.127717, (float)0.141331, (float)0.119961, (float)0.256691, (float)0.120201, (float)0.152304, (float)0.151313, (float)0.100176, (float)0.145286, (float)0.161952, (float)0.126973, (float)0.117854, (float)0.100444, (float)0.203356, (float)0.157843, (float)0.178462, (float)0.118063, (float)0.067406, (float)0.246021, (float)0.125107, (float)0.114425, (float)0.167035, (float)0.145993, (float)0.162544, (float)0.120343, (float)0.169716, (float)0.106482, (float)0.141526, (float)0.169446, (float)0.090944, (float)0.113330, (float)0.156861, (float)0.087992, (float)0.133309, (float)0.171133, (float)0.242056, (float)0.118814, (float)0.088181, (float)0.108375, (float)0.137294, (float)0.288606, (float)0.173576, (float)0.173963, (float)0.151192, (float)0.108596, (float)0.121099, (float)0.152290, (float)0.145297, (float)0.173510, (float)0.151500, (float)0.134832, (float)0.244512, (float)0.143301, (float)0.142233, (float)0.152000, (float)0.098458, (float)0.129181, (float)0.137196, (float)0.222825, (float)0.126548, (float)0.153776, (float)0.160038, (float)0.112089, (float)0.192169, (float)0.119511, (float)0.110010, (float)0.115071, (float)0.143141, (float)0.125817, (float)0.141578, (float)0.104924, (float)0.183995, (float)0.115784, (float)0.111114, (float)0.218703, (float)0.119288, (float)0.154097, (float)0.107354, (float)0.135008, (float)0.138471, (float)0.099032, (float)0.141793, (float)0.183737, (float)0.166731, (float)0.171192, (float)0.156719, (float)0.154214, (float)0.150069, (float)0.158486, (float)0.142163, (float)0.152685, (float)0.117883, (float)0.188203, (float)0.185572, (float)0.154950, (float)0.179835, (float)0.287934, (float)0.115603, (float)0.174893, (float)0.129729, (float)0.152180, (float)0.130814, (float)0.212340, (float)0.157937, (float)0.093668, (float)0.131023, (float)0.205168, (float)0.151040, (float)0.154166, (float)0.141620, (float)0.120317, (float)0.137218, (float)0.197992, (float)0.135204, (float)0.206488, (float)0.138541, (float)0.135778, (float)0.169633, (float)0.281613, (float)0.105841, (float)0.088596, (float)0.112328, (float)0.226925, (float)0.111682, (float)0.107955, (float)0.202922, (float)0.102599, (float)0.114998, (float)0.145168, (float)0.118048, (float)0.169048, (float)0.207947, (float)0.113291, (float)0.193266, (float)0.145378, (float)0.087229, (float)0.100246, (float)0.110129, (float)0.175703, (float)0.196709, (float)0.090690, (float)0.117549, (float)0.150821, (float)0.134801, (float)0.120340, (float)0.141347, (float)0.218888, (float)0.102995, (float)0.138703, (float)0.166914, (float)0.108992, (float)0.163189, (float)0.087485, (float)0.134905, (float)0.107441, (float)0.283900, (float)0.162788, (float)0.187195, (float)0.153806, (float)0.097348, (float)0.183113, (float)0.211954, (float)0.171563, (float)0.088992, (float)0.186927, (float)0.087747, (float)0.129961, (float)0.279172, (float)0.156529, (float)0.160495, (float)0.142747, (float)0.136645, (float)0.144106, (float)0.107992, (float)0.116587, (float)0.128579, (float)0.249071, (float)0.124998, (float)0.146923, (float)0.138747, (float)0.116422, (float)0.125475, (float)0.099127, (float)0.094169, (float)0.154936, (float)0.284385, (float)0.123462, (float)0.173281, (float)0.182766, (float)0.089063, (float)0.110368, (float)0.128625, (float)0.149508, (float)0.124881, (float)0.462863, (float)0.137999, (float)0.101497, (float)0.106382, (float)0.161172, (float)0.214756, (float)0.144181, (float)0.171417, (float)0.160055, (float)0.257159, (float)0.187855};	// L4140
  #pragma HLS resource variable=v3535 core=ram_t2p_bram

  float v3536[256] = {(float)-0.102453, (float)-0.259171, (float)-0.096546, (float)-0.340652, (float)-0.709656, (float)-0.603112, (float)-0.214115, (float)-0.903070, (float)-0.403511, (float)-0.640743, (float)-0.249654, (float)-0.358281, (float)-0.456530, (float)-0.649031, (float)-0.517009, (float)-0.134873, (float)-0.485002, (float)-0.473931, (float)-0.315326, (float)-0.820895, (float)-0.422487, (float)-0.620579, (float)-0.455907, (float)-0.336757, (float)-0.479224, (float)-0.145781, (float)-0.274776, (float)-0.398024, (float)-0.713027, (float)-0.839437, (float)-0.273773, (float)-0.268421, (float)-0.755879, (float)-0.121173, (float)-0.438951, (float)-0.697070, (float)-0.503360, (float)-0.566661, (float)-0.088093, (float)-0.530825, (float)-1.077885, (float)-0.465694, (float)-0.101642, (float)-0.325129, (float)0.538409, (float)-0.757289, (float)-0.471778, (float)-0.347490, (float)-0.719843, (float)0.047820, (float)-0.138734, (float)-0.877976, (float)-0.405742, (float)-0.115066, (float)0.099245, (float)-0.388754, (float)-1.001531, (float)-0.386642, (float)-0.326697, (float)-0.732440, (float)0.090762, (float)-0.275990, (float)-0.275940, (float)-0.189190, (float)-0.503649, (float)-0.740645, (float)-0.531369, (float)-0.480375, (float)-0.606323, (float)-0.002653, (float)-0.918494, (float)-0.244357, (float)-1.184874, (float)-0.538959, (float)0.082583, (float)-0.517662, (float)-0.281385, (float)-0.946679, (float)-0.394639, (float)-0.220216, (float)-0.932489, (float)-0.220535, (float)-0.563211, (float)-0.316468, (float)-0.347139, (float)-0.569394, (float)-0.510860, (float)-0.589007, (float)-0.783802, (float)-0.002263, (float)-0.239585, (float)-0.167228, (float)-0.841089, (float)-0.730738, (float)-0.726148, (float)-0.934870, (float)-0.371630, (float)-0.356172, (float)-0.513671, (float)0.019965, (float)-0.168304, (float)-0.563289, (float)-0.785985, (float)0.099101, (float)-0.419311, (float)-0.207190, (float)0.357886, (float)-0.410227, (float)-0.366750, (float)-0.404898, (float)-0.900548, (float)-0.277691, (float)-0.272548, (float)0.394123, (float)-0.507511, (float)-0.452994, (float)-0.147831, (float)-0.022060, (float)-0.857384, (float)-0.310359, (float)-0.345442, (float)-0.642811, (float)-0.270896, (float)-0.856503, (float)-0.625989, (float)0.038911, (float)-0.225354, (float)-0.060526, (float)-0.598401, (float)-0.364272, (float)-0.348462, (float)0.025581, (float)-0.649912, (float)-0.305280, (float)-0.239829, (float)-0.398209, (float)-0.721522, (float)-0.653706, (float)0.076822, (float)-0.455411, (float)-0.536163, (float)-0.102057, (float)-0.646412, (float)-0.265759, (float)-0.498525, (float)-0.431918, (float)-0.385519, (float)-0.394294, (float)-0.591754, (float)-0.233525, (float)-0.677230, (float)-0.516218, (float)0.380602, (float)-0.389636, (float)-0.729214, (float)-0.220693, (float)-0.168720, (float)-0.662275, (float)0.284971, (float)0.172585, (float)-0.197409, (float)-0.558643, (float)-0.252358, (float)0.177279, (float)-0.609615, (float)-0.228053, (float)-0.469064, (float)-0.813329, (float)0.009186, (float)-0.491989, (float)-0.176777, (float)0.128825, (float)-0.069292, (float)-0.839732, (float)0.261292, (float)-0.218767, (float)-0.319037, (float)-0.486760, (float)-0.660932, (float)-0.767496, (float)-0.793261, (float)-0.934205, (float)-0.069119, (float)-0.661614, (float)-0.370487, (float)-0.453789, (float)-0.927919, (float)0.332377, (float)-0.495022, (float)0.266945, (float)-0.813905, (float)-0.790910, (float)-0.789206, (float)-0.467173, (float)-0.591689, (float)-0.546259, (float)-0.289580, (float)-0.022648, (float)-0.272203, (float)-0.374683, (float)0.120206, (float)-0.033795, (float)0.189072, (float)-0.243509, (float)-0.022650, (float)-0.764620, (float)-0.401645, (float)-0.311593, (float)1.539555, (float)-0.137344, (float)-0.753158, (float)-0.610004, (float)-0.243898, (float)-0.531916, (float)-0.660311, (float)-0.319874, (float)-0.847142, (float)-0.048371, (float)0.082996, (float)-0.458410, (float)-0.388908, (float)-0.816281, (float)-0.332179, (float)-0.667026, (float)-0.774422, (float)-0.700965, (float)0.212783, (float)-0.562379, (float)-1.035953, (float)-0.309841, (float)0.699997, (float)-0.358035, (float)-0.348437, (float)-0.516148, (float)-0.216690, (float)-0.890328, (float)-0.340157, (float)-0.403715, (float)-0.550114, (float)-0.419702, (float)-0.528954, (float)-0.497380, (float)0.008297, (float)-0.016590, (float)-0.860652, (float)-0.558072, (float)-0.516058, (float)-0.366773, (float)-0.736309, (float)-0.365438, (float)-0.278847, (float)-0.389011, (float)-0.152117, (float)-0.332711, (float)-0.790260, (float)-0.253097};	// L4141
  #pragma HLS resource variable=v3536 core=ram_t2p_bram

  float v3537[256] = {(float)0.067355, (float)0.051428, (float)0.038453, (float)0.169151, (float)0.060444, (float)0.045957, (float)0.120948, (float)0.111015, (float)0.041795, (float)0.038695, (float)0.044169, (float)0.070729, (float)0.078953, (float)0.109442, (float)0.095900, (float)0.054391, (float)0.103244, (float)0.218981, (float)0.045899, (float)0.037226, (float)0.140985, (float)0.058720, (float)0.036016, (float)0.095475, (float)0.165730, (float)0.102427, (float)0.141727, (float)0.058008, (float)0.053617, (float)0.071556, (float)0.086484, (float)0.111046, (float)0.051134, (float)0.051456, (float)0.080900, (float)0.115377, (float)0.077653, (float)0.044903, (float)0.048958, (float)0.105569, (float)0.145745, (float)0.074394, (float)0.053026, (float)0.059951, (float)0.102562, (float)0.048563, (float)0.040838, (float)0.131216, (float)0.063901, (float)0.106154, (float)0.091546, (float)0.147588, (float)0.090042, (float)0.074165, (float)0.106905, (float)0.077630, (float)0.142333, (float)0.049509, (float)0.097357, (float)0.066064, (float)0.129222, (float)0.054811, (float)0.114466, (float)0.094952, (float)0.092081, (float)0.157894, (float)0.049587, (float)0.023633, (float)0.039756, (float)0.093460, (float)0.029148, (float)0.065285, (float)0.088538, (float)0.118976, (float)0.169175, (float)0.069161, (float)0.131626, (float)0.060590, (float)0.048040, (float)0.065360, (float)0.108199, (float)0.062440, (float)0.110316, (float)0.110551, (float)0.107625, (float)0.040008, (float)0.072288, (float)0.094698, (float)0.066159, (float)0.046392, (float)0.044422, (float)0.172738, (float)0.092065, (float)0.034482, (float)0.045051, (float)0.037437, (float)0.094050, (float)0.081760, (float)0.039662, (float)0.045171, (float)0.098512, (float)0.109502, (float)0.107201, (float)0.050593, (float)0.044436, (float)0.075476, (float)0.042001, (float)0.104616, (float)0.117208, (float)0.044654, (float)0.045942, (float)0.040864, (float)0.053858, (float)0.103637, (float)0.074125, (float)0.031065, (float)0.108586, (float)0.174579, (float)0.077694, (float)0.068938, (float)0.109982, (float)0.048908, (float)0.104767, (float)0.109747, (float)0.102549, (float)0.044844, (float)0.067470, (float)0.070740, (float)0.136368, (float)0.043839, (float)0.034581, (float)0.176885, (float)0.066684, (float)0.115469, (float)0.062781, (float)0.087277, (float)0.040644, (float)0.289002, (float)0.070327, (float)0.042766, (float)0.117316, (float)0.104901, (float)0.061137, (float)0.046914, (float)0.040005, (float)0.074382, (float)0.100340, (float)0.101244, (float)0.059949, (float)0.107826, (float)0.151178, (float)0.032168, (float)0.042972, (float)0.097673, (float)0.095145, (float)0.083779, (float)0.095803, (float)0.044831, (float)0.026261, (float)0.042486, (float)0.115426, (float)0.077075, (float)0.178146, (float)0.029957, (float)0.069904, (float)0.072415, (float)0.159989, (float)0.089302, (float)0.113046, (float)0.053426, (float)0.135893, (float)0.037503, (float)0.080887, (float)0.114542, (float)0.123203, (float)0.094226, (float)0.088033, (float)0.034649, (float)0.099603, (float)0.046072, (float)0.069359, (float)0.063005, (float)0.158955, (float)0.050894, (float)0.125435, (float)0.059031, (float)0.074401, (float)0.108354, (float)0.051442, (float)0.093101, (float)0.084757, (float)0.024004, (float)0.027874, (float)0.099328, (float)0.061239, (float)0.059906, (float)0.109542, (float)0.050842, (float)0.065824, (float)0.116200, (float)0.083273, (float)0.165128, (float)0.050494, (float)0.123114, (float)0.122795, (float)0.103773, (float)0.036941, (float)0.075630, (float)0.041531, (float)0.119168, (float)0.029214, (float)0.083852, (float)0.057698, (float)0.095098, (float)0.094377, (float)0.030888, (float)0.039030, (float)0.060384, (float)0.067196, (float)0.050130, (float)0.038252, (float)0.094625, (float)0.095757, (float)0.050099, (float)0.024288, (float)0.107435, (float)0.190828, (float)0.069329, (float)0.137637, (float)0.115080, (float)0.032938, (float)0.064666, (float)0.061636, (float)0.110599, (float)0.035808, (float)0.072129, (float)0.085061, (float)0.037549, (float)0.036827, (float)0.094678, (float)0.046447, (float)0.166622, (float)0.104944, (float)0.075518, (float)0.039807, (float)0.024882, (float)0.152823, (float)0.116652, (float)0.088585, (float)0.054029, (float)0.072570, (float)0.073581, (float)0.079700, (float)0.085395, (float)0.060856, (float)0.126276};	// L4142
  #pragma HLS resource variable=v3537 core=ram_t2p_bram

  float v3538[256] = {(float)0.013212, (float)0.013382, (float)0.006095, (float)0.023173, (float)0.010613, (float)0.013040, (float)0.018071, (float)0.022225, (float)0.005863, (float)0.008064, (float)0.009384, (float)0.020050, (float)0.013193, (float)0.043016, (float)0.016614, (float)0.008651, (float)0.016540, (float)0.025693, (float)0.008004, (float)0.005019, (float)0.027886, (float)0.003852, (float)0.007347, (float)0.015154, (float)0.021317, (float)0.029001, (float)0.021060, (float)0.006044, (float)0.011943, (float)0.013458, (float)0.013165, (float)0.024103, (float)0.010533, (float)0.017815, (float)0.014061, (float)0.021802, (float)0.009886, (float)0.011141, (float)0.012210, (float)0.013257, (float)0.018708, (float)0.016071, (float)0.014969, (float)0.012958, (float)0.011608, (float)0.009993, (float)0.006997, (float)0.025080, (float)0.010482, (float)0.014110, (float)0.018211, (float)0.023854, (float)0.024584, (float)0.020267, (float)0.019324, (float)0.016686, (float)0.023925, (float)0.013504, (float)0.019314, (float)0.024688, (float)0.022756, (float)0.013571, (float)0.014856, (float)0.024605, (float)0.027555, (float)0.028775, (float)0.008696, (float)0.006599, (float)0.010593, (float)0.010700, (float)0.009298, (float)0.019956, (float)0.022161, (float)0.022084, (float)0.016220, (float)0.011626, (float)0.015926, (float)0.007989, (float)0.010761, (float)0.012732, (float)0.020618, (float)0.014437, (float)0.015537, (float)0.018481, (float)0.020876, (float)0.009675, (float)0.004506, (float)0.014136, (float)0.008490, (float)0.012861, (float)0.012262, (float)0.034415, (float)0.014798, (float)0.005757, (float)0.008053, (float)0.008657, (float)0.012911, (float)0.023058, (float)0.014168, (float)0.009986, (float)0.011963, (float)0.015742, (float)0.020729, (float)0.009315, (float)0.011655, (float)0.011168, (float)0.011475, (float)0.016534, (float)0.017462, (float)0.009781, (float)0.017381, (float)0.010939, (float)0.011043, (float)0.013494, (float)0.007770, (float)0.005724, (float)0.018667, (float)0.010200, (float)0.011307, (float)0.008269, (float)0.009879, (float)0.011117, (float)0.014385, (float)0.023246, (float)0.025138, (float)0.009115, (float)0.010578, (float)0.007320, (float)0.016562, (float)0.014827, (float)0.005685, (float)0.034491, (float)0.019896, (float)0.020521, (float)0.009075, (float)0.012675, (float)0.010924, (float)0.026108, (float)0.010890, (float)0.006949, (float)0.022735, (float)0.007547, (float)0.016364, (float)0.010205, (float)0.007436, (float)0.013534, (float)0.015288, (float)0.025751, (float)0.007504, (float)0.009168, (float)0.023543, (float)0.007190, (float)0.008317, (float)0.012518, (float)0.014798, (float)0.011023, (float)0.015361, (float)0.004985, (float)0.006109, (float)0.009817, (float)0.013473, (float)0.016659, (float)0.028802, (float)0.003228, (float)0.015283, (float)0.013065, (float)0.019141, (float)0.010007, (float)0.020190, (float)0.014825, (float)0.011234, (float)0.006844, (float)0.014365, (float)0.009743, (float)0.021293, (float)0.015214, (float)0.013259, (float)0.006814, (float)0.012939, (float)0.006188, (float)0.006421, (float)0.007311, (float)0.022736, (float)0.008418, (float)0.019729, (float)0.010084, (float)0.019774, (float)0.022133, (float)0.007438, (float)0.011675, (float)0.026822, (float)0.006403, (float)0.008460, (float)0.012970, (float)0.011952, (float)0.009338, (float)0.011365, (float)0.016780, (float)0.008185, (float)0.010743, (float)0.016519, (float)0.020700, (float)0.009490, (float)0.019632, (float)0.013310, (float)0.011290, (float)0.005067, (float)0.015383, (float)0.011103, (float)0.028381, (float)0.011821, (float)0.011883, (float)0.015355, (float)0.021017, (float)0.011177, (float)0.010712, (float)0.007522, (float)0.014946, (float)0.012895, (float)0.005904, (float)0.004068, (float)0.020167, (float)0.015424, (float)0.010638, (float)0.003425, (float)0.011384, (float)0.030723, (float)0.007040, (float)0.030110, (float)0.018263, (float)0.006956, (float)0.005911, (float)0.008097, (float)0.018654, (float)0.006678, (float)0.018846, (float)0.013750, (float)0.006798, (float)0.008424, (float)0.015255, (float)0.014950, (float)0.013587, (float)0.020014, (float)0.015513, (float)0.009465, (float)0.005946, (float)0.023052, (float)0.018731, (float)0.009167, (float)0.009334, (float)0.014370, (float)0.011357, (float)0.011465, (float)0.010277, (float)0.010530, (float)0.017208};	// L4143
  #pragma HLS resource variable=v3538 core=ram_t2p_bram

  float v3539[256] = {(float)-0.107749, (float)-0.122918, (float)-0.068057, (float)-0.192978, (float)-0.057083, (float)-0.022351, (float)-0.033751, (float)-0.243701, (float)-0.044682, (float)0.045172, (float)0.000794, (float)0.060614, (float)-0.068606, (float)-0.041073, (float)0.043546, (float)-0.087261, (float)-0.215666, (float)-0.159296, (float)-0.015692, (float)-0.069784, (float)-0.179629, (float)-0.020418, (float)0.044308, (float)-0.157338, (float)-0.040731, (float)-0.183036, (float)0.017990, (float)-0.089484, (float)-0.043369, (float)-0.203314, (float)-0.017081, (float)0.144224, (float)-0.079689, (float)-0.184836, (float)-0.020056, (float)-0.043827, (float)-0.143498, (float)-0.015720, (float)0.062979, (float)-0.022316, (float)-0.146989, (float)-0.083330, (float)-0.156791, (float)0.018029, (float)0.008319, (float)0.112518, (float)-0.093601, (float)0.064658, (float)-0.135173, (float)-0.137200, (float)0.136350, (float)-0.103056, (float)-0.167458, (float)-0.206970, (float)-0.007766, (float)-0.017808, (float)0.112277, (float)-0.087588, (float)-0.187685, (float)0.024718, (float)-0.254787, (float)-0.141303, (float)-0.091591, (float)-0.161294, (float)0.008704, (float)-0.204462, (float)-0.042047, (float)-0.076329, (float)-0.052223, (float)-0.002868, (float)-0.042433, (float)0.154109, (float)0.066410, (float)-0.073272, (float)-0.093508, (float)-0.022622, (float)-0.179698, (float)0.012897, (float)0.046525, (float)-0.100765, (float)-0.065238, (float)0.008820, (float)-0.012005, (float)0.057574, (float)-0.057091, (float)-0.066670, (float)-0.022753, (float)-0.088033, (float)-0.019220, (float)0.091500, (float)0.021224, (float)-0.286575, (float)-0.185104, (float)0.063062, (float)-0.032503, (float)0.010583, (float)-0.016274, (float)-0.137474, (float)-0.020840, (float)0.039972, (float)0.038194, (float)-0.158154, (float)-0.024230, (float)-0.010428, (float)-0.025313, (float)-0.007089, (float)-0.082242, (float)-0.002871, (float)0.016810, (float)-0.132763, (float)-0.063943, (float)0.083179, (float)-0.066588, (float)-0.008000, (float)-0.045917, (float)0.045017, (float)-0.101334, (float)-0.062952, (float)-0.062940, (float)-0.136139, (float)-0.050002, (float)-0.048774, (float)0.109049, (float)-0.069991, (float)-0.080147, (float)-0.103026, (float)-0.027757, (float)-0.124223, (float)-0.058502, (float)-0.026336, (float)-0.037121, (float)-0.067826, (float)-0.168335, (float)0.012244, (float)0.038192, (float)-0.007231, (float)-0.042381, (float)-0.086380, (float)-0.005778, (float)0.096943, (float)-0.223213, (float)0.025069, (float)-0.029840, (float)-0.012575, (float)0.053059, (float)-0.200877, (float)-0.221157, (float)-0.002151, (float)0.039617, (float)-0.002853, (float)-0.137680, (float)0.022641, (float)0.019518, (float)-0.174737, (float)0.061876, (float)-0.153826, (float)-0.089588, (float)0.075784, (float)-0.046126, (float)0.001137, (float)-0.078707, (float)-0.087727, (float)-0.220280, (float)-0.043143, (float)0.074256, (float)-0.128912, (float)-0.096022, (float)-0.084083, (float)0.058107, (float)-0.105853, (float)-0.151327, (float)-0.083388, (float)0.035651, (float)-0.091718, (float)0.064076, (float)0.059519, (float)-0.120998, (float)-0.027586, (float)0.037621, (float)-0.009965, (float)-0.137036, (float)-0.096201, (float)-0.281392, (float)-0.103302, (float)-0.043732, (float)-0.033824, (float)-0.059146, (float)-0.069079, (float)-0.088350, (float)-0.048529, (float)0.074784, (float)-0.037809, (float)-0.047766, (float)0.018923, (float)-0.054648, (float)-0.014481, (float)0.033152, (float)-0.059256, (float)0.022501, (float)-0.137368, (float)-0.118120, (float)0.055905, (float)0.022248, (float)-0.002063, (float)-0.095352, (float)-0.041699, (float)0.079884, (float)-0.144740, (float)-0.029650, (float)-0.095548, (float)0.059774, (float)0.073225, (float)-0.007424, (float)0.040194, (float)-0.022209, (float)0.074660, (float)0.011220, (float)0.126989, (float)-0.027397, (float)-0.005367, (float)0.014878, (float)-0.026290, (float)-0.037304, (float)-0.097051, (float)0.074925, (float)-0.137720, (float)-0.187705, (float)-0.063754, (float)-0.148719, (float)-0.009851, (float)-0.027509, (float)0.001119, (float)-0.040400, (float)0.055569, (float)-0.111979, (float)-0.167270, (float)0.040156, (float)-0.179521, (float)0.067644, (float)0.022024, (float)-0.081266, (float)0.091851, (float)-0.040204, (float)0.019240, (float)0.003338, (float)-0.021979, (float)-0.167338, (float)-0.108656, (float)-0.102467, (float)0.047615, (float)-0.137436, (float)0.005816, (float)-0.077233, (float)-0.044517, (float)0.014401, (float)-0.114851};	// L4144
  #pragma HLS resource variable=v3539 core=ram_t2p_bram

  float v3540[256] = {(float)-0.026385, (float)0.099545, (float)-0.006836, (float)-0.087678, (float)0.007832, (float)0.040653, (float)-0.030738, (float)0.005956, (float)0.001694, (float)0.047769, (float)0.063004, (float)0.035760, (float)-0.050405, (float)0.021372, (float)-0.009033, (float)-0.033702, (float)-0.045529, (float)-0.192383, (float)-0.067608, (float)0.077464, (float)-0.033957, (float)-0.079947, (float)0.131379, (float)-0.127304, (float)-0.062825, (float)-0.005497, (float)-0.091520, (float)-0.175702, (float)-0.008296, (float)-0.094468, (float)0.002491, (float)-0.031894, (float)-0.015755, (float)0.143725, (float)-0.003477, (float)0.010756, (float)-0.051074, (float)0.035848, (float)0.087819, (float)-0.045240, (float)-0.045785, (float)0.014690, (float)0.068685, (float)0.016806, (float)-0.047715, (float)0.056814, (float)0.045985, (float)-0.050668, (float)0.005891, (float)-0.103352, (float)0.010281, (float)-0.105204, (float)-0.016557, (float)-0.019213, (float)-0.034522, (float)0.020138, (float)-0.136205, (float)0.039602, (float)-0.008828, (float)-0.010837, (float)-0.029803, (float)0.072119, (float)-0.066893, (float)-0.009429, (float)-0.030956, (float)-0.026700, (float)-0.141836, (float)0.119003, (float)0.066929, (float)-0.213746, (float)0.042720, (float)0.047782, (float)0.033905, (float)0.000139, (float)-0.148223, (float)-0.023684, (float)-0.074337, (float)-0.068427, (float)-0.020076, (float)0.014697, (float)-0.039620, (float)0.019393, (float)-0.069640, (float)-0.055779, (float)0.007966, (float)0.023639, (float)-0.257815, (float)0.006356, (float)-0.100405, (float)0.028047, (float)0.015223, (float)-0.048413, (float)-0.153553, (float)0.104931, (float)0.049892, (float)0.065689, (float)-0.054139, (float)0.007726, (float)0.094090, (float)-0.019978, (float)-0.235610, (float)-0.062284, (float)0.033363, (float)0.110169, (float)0.076999, (float)-0.032478, (float)0.048089, (float)-0.149947, (float)-0.165030, (float)0.123038, (float)0.071157, (float)0.058895, (float)-0.048155, (float)-0.097220, (float)-0.186036, (float)0.085326, (float)-0.051602, (float)-0.307986, (float)-0.060410, (float)-0.077131, (float)-0.272820, (float)0.028950, (float)-0.132805, (float)0.017264, (float)-0.039184, (float)0.054153, (float)-0.037219, (float)-0.152829, (float)-0.176634, (float)0.083937, (float)0.069329, (float)-0.082645, (float)0.111784, (float)-0.050772, (float)-0.044772, (float)-0.037455, (float)0.030361, (float)-0.378243, (float)0.014857, (float)0.006824, (float)-0.052090, (float)-0.295015, (float)0.089860, (float)0.029646, (float)0.019930, (float)-0.083483, (float)-0.096416, (float)-0.023830, (float)0.034911, (float)-0.266257, (float)-0.161844, (float)0.073552, (float)0.027568, (float)-0.110867, (float)-0.010322, (float)-0.097499, (float)0.013995, (float)0.010802, (float)0.078444, (float)0.013057, (float)-0.039476, (float)0.024805, (float)-0.077445, (float)-0.028419, (float)0.010412, (float)-0.042330, (float)-0.166340, (float)-0.094908, (float)-0.034328, (float)0.045544, (float)-0.300010, (float)-0.006938, (float)0.014103, (float)-0.261548, (float)-0.073598, (float)-0.106273, (float)-0.010544, (float)-0.071160, (float)-0.103388, (float)-0.029787, (float)-0.142769, (float)-0.051710, (float)-0.057126, (float)-0.054392, (float)-0.042260, (float)-0.008512, (float)0.015887, (float)-0.065358, (float)-0.061346, (float)-0.145019, (float)0.039939, (float)0.081640, (float)-0.007760, (float)-0.034062, (float)0.031969, (float)-0.044756, (float)-0.070306, (float)0.102130, (float)-0.179928, (float)-0.211733, (float)-0.059797, (float)-0.115961, (float)0.039271, (float)-0.045443, (float)-0.184456, (float)-0.108476, (float)0.055781, (float)-0.063649, (float)0.016825, (float)0.000166, (float)0.079866, (float)-0.067240, (float)0.079827, (float)-0.003991, (float)-0.190164, (float)0.020026, (float)0.073181, (float)0.103234, (float)-0.026431, (float)0.023963, (float)-0.044247, (float)0.022896, (float)0.023444, (float)-0.023481, (float)0.010516, (float)-0.214937, (float)-0.128099, (float)-0.018338, (float)-0.000602, (float)-0.051624, (float)0.056575, (float)-0.054297, (float)0.014146, (float)-0.049852, (float)0.067255, (float)0.051713, (float)-0.004027, (float)0.035057, (float)0.082781, (float)0.010034, (float)0.059230, (float)-0.204295, (float)-0.076169, (float)0.041432, (float)0.077517, (float)0.076005, (float)-0.159186, (float)-0.083613, (float)-0.166251, (float)0.002297, (float)-0.068489, (float)0.038119, (float)-0.098731, (float)-0.020290, (float)0.015394, (float)-0.105481};	// L4145
  #pragma HLS resource variable=v3540 core=ram_t2p_bram

  float v3541[256] = {(float)0.321214, (float)0.212399, (float)0.266072, (float)0.359449, (float)0.278469, (float)0.258197, (float)0.310780, (float)0.309614, (float)0.334833, (float)0.299212, (float)0.254539, (float)0.245751, (float)0.313275, (float)0.415883, (float)0.299702, (float)0.306994, (float)0.313544, (float)0.441772, (float)0.374276, (float)0.257042, (float)0.294294, (float)0.307829, (float)0.273839, (float)0.394832, (float)0.292831, (float)0.357222, (float)0.343523, (float)0.537935, (float)0.424347, (float)0.390766, (float)0.274456, (float)0.279759, (float)0.321719, (float)0.195593, (float)0.275126, (float)0.318720, (float)0.350660, (float)0.275078, (float)0.191919, (float)0.330734, (float)0.285038, (float)0.303757, (float)0.217935, (float)0.265186, (float)0.294413, (float)0.213770, (float)0.218425, (float)0.294765, (float)0.326244, (float)0.375874, (float)0.255724, (float)0.379644, (float)0.294955, (float)0.338577, (float)0.324264, (float)0.307028, (float)0.333070, (float)0.230194, (float)0.303576, (float)0.337655, (float)0.292232, (float)0.220439, (float)0.326703, (float)0.319780, (float)0.402345, (float)0.298687, (float)0.486047, (float)0.285416, (float)0.271637, (float)0.434131, (float)0.283433, (float)0.229564, (float)0.250730, (float)0.311966, (float)0.367275, (float)0.324437, (float)0.338049, (float)0.327208, (float)0.286757, (float)0.287673, (float)0.320995, (float)0.233216, (float)0.337860, (float)0.276670, (float)0.294190, (float)0.267243, (float)0.440110, (float)0.290800, (float)0.377056, (float)0.278862, (float)0.305619, (float)0.327566, (float)0.387124, (float)0.245329, (float)0.255872, (float)0.278296, (float)0.316762, (float)0.340972, (float)0.231816, (float)0.357684, (float)0.503631, (float)0.355690, (float)0.247532, (float)0.185207, (float)0.227332, (float)0.360157, (float)0.291895, (float)0.392827, (float)0.442318, (float)0.205229, (float)0.252430, (float)0.218886, (float)0.411338, (float)0.361080, (float)0.428416, (float)0.233330, (float)0.350439, (float)0.700149, (float)0.375362, (float)0.287419, (float)0.370221, (float)0.317366, (float)0.363957, (float)0.288891, (float)0.415500, (float)0.247910, (float)0.289849, (float)0.373996, (float)0.492593, (float)0.280807, (float)0.238791, (float)0.347282, (float)0.186811, (float)0.283673, (float)0.308996, (float)0.361434, (float)0.279743, (float)0.687078, (float)0.285402, (float)0.293681, (float)0.312809, (float)0.486253, (float)0.219283, (float)0.287136, (float)0.255449, (float)0.417536, (float)0.304438, (float)0.322992, (float)0.334262, (float)0.494713, (float)0.392355, (float)0.226389, (float)0.265720, (float)0.419290, (float)0.348321, (float)0.355126, (float)0.287663, (float)0.255942, (float)0.245868, (float)0.277469, (float)0.384195, (float)0.294926, (float)0.350955, (float)0.192600, (float)0.310130, (float)0.341671, (float)0.393080, (float)0.391781, (float)0.323868, (float)0.285095, (float)0.458256, (float)0.266863, (float)0.266303, (float)0.443338, (float)0.322125, (float)0.365481, (float)0.333581, (float)0.439321, (float)0.396961, (float)0.372661, (float)0.352343, (float)0.358557, (float)0.328611, (float)0.418138, (float)0.295527, (float)0.304995, (float)0.298793, (float)0.432011, (float)0.230884, (float)0.382633, (float)0.227008, (float)0.222812, (float)0.320580, (float)0.327314, (float)0.262748, (float)0.308742, (float)0.292022, (float)0.232836, (float)0.414381, (float)0.407486, (float)0.326447, (float)0.358304, (float)0.301402, (float)0.315049, (float)0.443821, (float)0.404212, (float)0.202751, (float)0.385498, (float)0.256986, (float)0.236064, (float)0.234269, (float)0.331237, (float)0.230322, (float)0.374439, (float)0.472747, (float)0.360084, (float)0.275426, (float)0.198746, (float)0.302701, (float)0.342689, (float)0.299445, (float)0.253305, (float)0.263879, (float)0.345958, (float)0.384709, (float)0.436817, (float)0.378559, (float)0.312291, (float)0.259140, (float)0.397851, (float)0.257663, (float)0.313072, (float)0.293382, (float)0.302671, (float)0.294207, (float)0.226591, (float)0.280574, (float)0.297662, (float)0.185842, (float)0.278839, (float)0.250415, (float)0.394814, (float)0.349607, (float)0.242925, (float)0.215502, (float)0.268320, (float)0.409995, (float)0.349523, (float)0.424278, (float)0.262704, (float)0.332853, (float)0.284865, (float)0.392416, (float)0.372755, (float)0.265513, (float)0.333785};	// L4146
  #pragma HLS resource variable=v3541 core=ram_t2p_bram

  float v3542[256] = {(float)0.107920, (float)0.113119, (float)0.092402, (float)0.071782, (float)0.097940, (float)0.161556, (float)0.067759, (float)0.095264, (float)0.156841, (float)0.148867, (float)0.148639, (float)0.118751, (float)0.103737, (float)0.327870, (float)0.074858, (float)0.097990, (float)0.084549, (float)0.063650, (float)0.081342, (float)0.100630, (float)0.073185, (float)0.064171, (float)0.193288, (float)0.082385, (float)0.059233, (float)0.148861, (float)0.073801, (float)0.089610, (float)0.255869, (float)0.151682, (float)0.068495, (float)0.104463, (float)0.116415, (float)0.118472, (float)0.089943, (float)0.102400, (float)0.069438, (float)0.161354, (float)0.085833, (float)0.078180, (float)0.062971, (float)0.131437, (float)0.108712, (float)0.101784, (float)0.070927, (float)0.097307, (float)0.063811, (float)0.079515, (float)0.091107, (float)0.077233, (float)0.080560, (float)0.098582, (float)0.130434, (float)0.164583, (float)0.100621, (float)0.123261, (float)0.070296, (float)0.103307, (float)0.129595, (float)0.237423, (float)0.090776, (float)0.129562, (float)0.067803, (float)0.133029, (float)0.206679, (float)0.085977, (float)0.120746, (float)0.157335, (float)0.165559, (float)0.077627, (float)0.166565, (float)0.188749, (float)0.116823, (float)0.114407, (float)0.046436, (float)0.113001, (float)0.056545, (float)0.065159, (float)0.103074, (float)0.109842, (float)0.076094, (float)0.101361, (float)0.062740, (float)0.062418, (float)0.098488, (float)0.131857, (float)0.063869, (float)0.088104, (float)0.064605, (float)0.198904, (float)0.201842, (float)0.068886, (float)0.062178, (float)0.123867, (float)0.100861, (float)0.193545, (float)0.075647, (float)0.175286, (float)0.142215, (float)0.152461, (float)0.073533, (float)0.103727, (float)0.077450, (float)0.073334, (float)0.134000, (float)0.067998, (float)0.186661, (float)0.064853, (float)0.088539, (float)0.127883, (float)0.196692, (float)0.116001, (float)0.161062, (float)0.078586, (float)0.069576, (float)0.104028, (float)0.139981, (float)0.095898, (float)0.099353, (float)0.063146, (float)0.044682, (float)0.159987, (float)0.062740, (float)0.100733, (float)0.231643, (float)0.107364, (float)0.069490, (float)0.052605, (float)0.117870, (float)0.221723, (float)0.078380, (float)0.096814, (float)0.090653, (float)0.067003, (float)0.075803, (float)0.082118, (float)0.157966, (float)0.111124, (float)0.092853, (float)0.087567, (float)0.096227, (float)0.058785, (float)0.075936, (float)0.093882, (float)0.077693, (float)0.119861, (float)0.067781, (float)0.143152, (float)0.087430, (float)0.066882, (float)0.088135, (float)0.101346, (float)0.130327, (float)0.087776, (float)0.113767, (float)0.080938, (float)0.094607, (float)0.094033, (float)0.146219, (float)0.161455, (float)0.084281, (float)0.120982, (float)0.092326, (float)0.044513, (float)0.096573, (float)0.102368, (float)0.063741, (float)0.070668, (float)0.074185, (float)0.139571, (float)0.049915, (float)0.117890, (float)0.068812, (float)0.048670, (float)0.087817, (float)0.086432, (float)0.079138, (float)0.172189, (float)0.099577, (float)0.125177, (float)0.055568, (float)0.076120, (float)0.072859, (float)0.120526, (float)0.054969, (float)0.108001, (float)0.132347, (float)0.227916, (float)0.052727, (float)0.067079, (float)0.095510, (float)0.112687, (float)0.129030, (float)0.087197, (float)0.092644, (float)0.079046, (float)0.058910, (float)0.132045, (float)0.060425, (float)0.070423, (float)0.090503, (float)0.054910, (float)0.162270, (float)0.062874, (float)0.067185, (float)0.064026, (float)0.080040, (float)0.127539, (float)0.131902, (float)0.074259, (float)0.138094, (float)0.065906, (float)0.132874, (float)0.196173, (float)0.073843, (float)0.141605, (float)0.163910, (float)0.096622, (float)0.099170, (float)0.078575, (float)0.076646, (float)0.090674, (float)0.075964, (float)0.100050, (float)0.135052, (float)0.060326, (float)0.060349, (float)0.076702, (float)0.067060, (float)0.133114, (float)0.119993, (float)0.077948, (float)0.083209, (float)0.061850, (float)0.120612, (float)0.098630, (float)0.074216, (float)0.096020, (float)0.067579, (float)0.090194, (float)0.119490, (float)0.041490, (float)0.092642, (float)0.119073, (float)0.105536, (float)0.133169, (float)0.086161, (float)0.086509, (float)0.064966, (float)0.079783, (float)0.066094, (float)0.101048, (float)0.103775, (float)0.100503, (float)0.094500, (float)0.061120};	// L4147
  #pragma HLS resource variable=v3542 core=ram_t2p_bram

  float v3543[256] = {(float)-0.189777, (float)-0.482186, (float)-0.008805, (float)0.006411, (float)-0.340083, (float)-0.104136, (float)-0.162624, (float)-0.225853, (float)-0.111947, (float)-0.325409, (float)-0.025436, (float)-0.235121, (float)-0.079023, (float)-0.330589, (float)-0.095579, (float)-0.041512, (float)-0.320712, (float)-0.003675, (float)-0.182978, (float)-0.129528, (float)-0.206938, (float)-0.263178, (float)-0.135148, (float)-0.129547, (float)-0.252728, (float)-0.010400, (float)-0.087520, (float)-0.337514, (float)-0.500123, (float)-0.119882, (float)-0.198902, (float)-0.296375, (float)-0.192366, (float)-0.290422, (float)-0.009084, (float)-0.010365, (float)0.073766, (float)-0.176034, (float)0.044212, (float)-0.223174, (float)0.037583, (float)-0.123472, (float)-0.006477, (float)-0.252415, (float)-0.012039, (float)0.055478, (float)0.153278, (float)-0.142060, (float)-0.116012, (float)-0.089306, (float)-0.154690, (float)-0.161466, (float)0.020772, (float)-0.349643, (float)-0.147741, (float)-0.615463, (float)-0.136424, (float)-0.040550, (float)-0.324642, (float)-0.169717, (float)0.169392, (float)-0.066222, (float)-0.207621, (float)-0.396942, (float)-0.293588, (float)0.107962, (float)-0.279773, (float)-0.085886, (float)-0.071285, (float)-0.351994, (float)-0.064169, (float)-0.199326, (float)0.020171, (float)-0.380757, (float)-0.083251, (float)-0.132135, (float)-0.300852, (float)-0.179991, (float)0.082419, (float)-0.053208, (float)0.153810, (float)0.177749, (float)0.183670, (float)-0.197191, (float)-0.008271, (float)-0.213453, (float)-0.388144, (float)-0.168575, (float)-0.114889, (float)0.205505, (float)-0.205391, (float)-0.134499, (float)-0.157910, (float)-0.180125, (float)-0.213260, (float)-0.294034, (float)-0.208740, (float)-0.041945, (float)-0.215760, (float)-0.045287, (float)-0.293506, (float)-0.157409, (float)0.031047, (float)0.015392, (float)-0.101318, (float)0.040111, (float)-0.407119, (float)-0.285228, (float)-0.295356, (float)-0.226055, (float)-0.108272, (float)0.135866, (float)-0.618958, (float)-0.195708, (float)-0.201768, (float)-0.018107, (float)-0.315698, (float)-0.097366, (float)-0.218778, (float)0.010469, (float)-0.068638, (float)-0.293657, (float)-0.316823, (float)-0.174534, (float)0.028630, (float)-0.172140, (float)-0.204302, (float)-0.211421, (float)-0.203194, (float)-0.216986, (float)0.045944, (float)0.211036, (float)-0.100892, (float)-0.056037, (float)0.150099, (float)-0.171299, (float)0.017118, (float)-0.202913, (float)-0.217480, (float)0.083633, (float)-0.021473, (float)-0.342348, (float)-0.144981, (float)0.163231, (float)-0.167945, (float)-0.167225, (float)-0.163446, (float)-0.361114, (float)-0.066378, (float)-0.301459, (float)-0.119178, (float)0.019238, (float)-0.141982, (float)-0.285228, (float)-0.303883, (float)-0.089706, (float)-0.065887, (float)-0.024002, (float)-0.221210, (float)0.030599, (float)-0.008324, (float)-0.377250, (float)-0.258354, (float)0.002954, (float)-0.098139, (float)-0.260227, (float)-0.121153, (float)-0.209369, (float)-0.139802, (float)-0.179488, (float)-0.146744, (float)0.010215, (float)-0.139606, (float)-0.273151, (float)-0.142677, (float)-0.113589, (float)-0.166838, (float)-0.334615, (float)-0.310770, (float)-0.046880, (float)-0.073305, (float)-0.382769, (float)-0.108244, (float)-0.085387, (float)-0.156431, (float)-0.170715, (float)-0.139600, (float)0.037278, (float)0.278705, (float)-0.241466, (float)-0.119594, (float)-0.145318, (float)-0.264213, (float)-0.101207, (float)0.047012, (float)-0.113262, (float)0.159313, (float)-0.056641, (float)-0.186790, (float)-0.236183, (float)0.092192, (float)0.165713, (float)0.156039, (float)-0.199838, (float)-0.193852, (float)0.115413, (float)0.053682, (float)-0.219226, (float)-0.099676, (float)-0.233159, (float)-0.149759, (float)0.031655, (float)0.079305, (float)-0.217689, (float)-0.265366, (float)-0.227793, (float)-0.041873, (float)0.014206, (float)-0.211142, (float)-0.022370, (float)0.095297, (float)-0.162817, (float)0.098129, (float)-0.122034, (float)-0.035969, (float)-0.388423, (float)0.114713, (float)0.006867, (float)-0.282127, (float)-0.605982, (float)-0.224330, (float)0.017712, (float)-0.073646, (float)-0.137202, (float)-0.043635, (float)0.161579, (float)-0.190647, (float)-0.277439, (float)0.113585, (float)0.189117, (float)0.061008, (float)0.016080, (float)-0.104557, (float)-0.082977, (float)0.007892, (float)-0.096327, (float)-0.195615, (float)-0.144547, (float)-0.159137, (float)0.061161, (float)-0.255179, (float)0.008187, (float)0.197982, (float)-0.228035, (float)-0.116328, (float)-0.164370};	// L4148
  #pragma HLS resource variable=v3543 core=ram_t2p_bram

  float v3544[256] = {(float)-0.091541, (float)0.018898, (float)-0.123456, (float)-0.061327, (float)-0.100263, (float)-0.130591, (float)-0.147267, (float)-0.107884, (float)-0.243784, (float)-0.111251, (float)0.136086, (float)-0.147696, (float)0.038740, (float)-0.090681, (float)0.035250, (float)-0.185141, (float)-0.131863, (float)-0.174566, (float)-0.081508, (float)-0.100397, (float)-0.339357, (float)-0.171201, (float)-0.080694, (float)-0.122756, (float)-0.226348, (float)-0.150313, (float)-0.231352, (float)-0.232732, (float)-0.085389, (float)-0.080152, (float)-0.071633, (float)-0.083903, (float)-0.059168, (float)0.035758, (float)-0.032176, (float)-0.219693, (float)0.002686, (float)-0.147120, (float)-0.026404, (float)-0.188586, (float)-0.241665, (float)-0.149379, (float)-0.190439, (float)-0.108913, (float)-0.265685, (float)-0.136225, (float)-0.048705, (float)-0.134040, (float)-0.092953, (float)-0.006406, (float)-0.172137, (float)-0.147599, (float)-0.171439, (float)0.033604, (float)-0.101091, (float)-0.176112, (float)-0.118361, (float)-0.048236, (float)-0.325970, (float)-0.155533, (float)-0.016897, (float)-0.237285, (float)-0.101522, (float)-0.105098, (float)-0.273812, (float)-0.191719, (float)-0.050346, (float)-0.109822, (float)0.148440, (float)-0.228247, (float)-0.069973, (float)-0.142682, (float)-0.141699, (float)-0.309599, (float)-0.204279, (float)0.026869, (float)-0.077861, (float)-0.084224, (float)-0.046442, (float)-0.142941, (float)-0.391699, (float)0.025708, (float)-0.177874, (float)-0.099331, (float)-0.050711, (float)-0.222194, (float)-0.095079, (float)-0.086135, (float)-0.074276, (float)-0.166584, (float)-0.205380, (float)-0.178156, (float)-0.115048, (float)-0.252517, (float)-0.069416, (float)-0.053633, (float)-0.049875, (float)-0.031105, (float)0.121213, (float)-0.098814, (float)-0.157045, (float)-0.309300, (float)-0.079659, (float)-0.099416, (float)-0.177447, (float)-0.050523, (float)0.076561, (float)-0.047986, (float)-0.127789, (float)-0.065052, (float)-0.173716, (float)0.030266, (float)-0.133399, (float)-0.243512, (float)-0.074562, (float)-0.036471, (float)-0.184350, (float)-0.088707, (float)-0.192414, (float)-0.111002, (float)-0.145788, (float)-0.089511, (float)-0.095593, (float)-0.204198, (float)-0.133813, (float)-0.063686, (float)-0.069926, (float)-0.165650, (float)-0.152099, (float)-0.131711, (float)-0.082572, (float)-0.247043, (float)-0.117428, (float)-0.147476, (float)-0.084031, (float)-0.068137, (float)-0.178943, (float)0.028840, (float)-0.036173, (float)-0.300523, (float)-0.144107, (float)-0.081247, (float)-0.049173, (float)-0.065680, (float)-0.124873, (float)-0.110424, (float)0.018734, (float)-0.135130, (float)-0.194434, (float)-0.090873, (float)0.206699, (float)-0.108119, (float)-0.249868, (float)-0.099919, (float)0.050711, (float)-0.189901, (float)-0.036945, (float)-0.143244, (float)0.127873, (float)-0.178175, (float)-0.117233, (float)-0.009903, (float)0.078477, (float)-0.068088, (float)-0.036492, (float)-0.159562, (float)-0.160586, (float)-0.092235, (float)-0.177350, (float)-0.178807, (float)0.030627, (float)-0.110060, (float)-0.135469, (float)-0.224402, (float)-0.085992, (float)-0.123241, (float)-0.092661, (float)-0.166617, (float)-0.139341, (float)-0.089812, (float)-0.061381, (float)-0.173992, (float)-0.250278, (float)-0.059253, (float)-0.127184, (float)-0.142201, (float)-0.074251, (float)-0.220762, (float)-0.220682, (float)-0.274205, (float)-0.130161, (float)-0.091641, (float)-0.169643, (float)-0.248070, (float)-0.152374, (float)0.041031, (float)-0.107683, (float)0.040801, (float)-0.191516, (float)-0.069653, (float)-0.104922, (float)-0.011046, (float)-0.325680, (float)-0.133634, (float)-0.102107, (float)0.012819, (float)-0.271689, (float)-0.124546, (float)0.028783, (float)-0.102536, (float)-0.240512, (float)-0.147584, (float)0.100827, (float)-0.021987, (float)-0.098267, (float)-0.441696, (float)-0.077403, (float)-0.320662, (float)-0.027250, (float)-0.072613, (float)-0.060763, (float)-0.043001, (float)-0.087174, (float)-0.128030, (float)-0.160845, (float)-0.152924, (float)-0.174502, (float)-0.170176, (float)-0.048594, (float)-0.145877, (float)-0.055220, (float)-0.080786, (float)-0.026370, (float)-0.095169, (float)-0.112555, (float)-0.045169, (float)-0.083661, (float)-0.033070, (float)0.012683, (float)-0.086466, (float)-0.144631, (float)-0.073167, (float)-0.215994, (float)-0.095242, (float)-0.129684, (float)-0.200768, (float)-0.213469, (float)-0.220437, (float)-0.238096, (float)-0.178692, (float)-0.138572, (float)-0.190089, (float)-0.098096, (float)-0.085015, (float)-0.076103, (float)-0.058645};	// L4149
  #pragma HLS resource variable=v3544 core=ram_t2p_bram

  float v3545[256] = {(float)0.285559, (float)0.242513, (float)0.303185, (float)0.316843, (float)0.301112, (float)0.347454, (float)0.307561, (float)0.310476, (float)0.364599, (float)0.325492, (float)0.219472, (float)0.316731, (float)0.267433, (float)0.310377, (float)0.302567, (float)0.344343, (float)0.291547, (float)0.337878, (float)0.288732, (float)0.299638, (float)0.358818, (float)0.316421, (float)0.288209, (float)0.291741, (float)0.349248, (float)0.374901, (float)0.358705, (float)0.316626, (float)0.275555, (float)0.297773, (float)0.336378, (float)0.289266, (float)0.310645, (float)0.250589, (float)0.346038, (float)0.362116, (float)0.257021, (float)0.369536, (float)0.293526, (float)0.328555, (float)0.324343, (float)0.318817, (float)0.309339, (float)0.331369, (float)0.354980, (float)0.297806, (float)0.273727, (float)0.302276, (float)0.317948, (float)0.283143, (float)0.306462, (float)0.338974, (float)0.305294, (float)0.309905, (float)0.301651, (float)0.347185, (float)0.303356, (float)0.293453, (float)0.335237, (float)0.367627, (float)0.316286, (float)0.340372, (float)0.307773, (float)0.281928, (float)0.379397, (float)0.308284, (float)0.277796, (float)0.336334, (float)0.228444, (float)0.325858, (float)0.279001, (float)0.307226, (float)0.297520, (float)0.384725, (float)0.337204, (float)0.225265, (float)0.282748, (float)0.373716, (float)0.279589, (float)0.348498, (float)0.387878, (float)0.328783, (float)0.334035, (float)0.333461, (float)0.275599, (float)0.350031, (float)0.289668, (float)0.279846, (float)0.290734, (float)0.321974, (float)0.382362, (float)0.352245, (float)0.327819, (float)0.368933, (float)0.314718, (float)0.360019, (float)0.312293, (float)0.251859, (float)0.235510, (float)0.321113, (float)0.320316, (float)0.334461, (float)0.276752, (float)0.334053, (float)0.315254, (float)0.317547, (float)0.222378, (float)0.295571, (float)0.320610, (float)0.265781, (float)0.366241, (float)0.271525, (float)0.365474, (float)0.342714, (float)0.281972, (float)0.275396, (float)0.466927, (float)0.309017, (float)0.346771, (float)0.314426, (float)0.321970, (float)0.276543, (float)0.330110, (float)0.321858, (float)0.315216, (float)0.281280, (float)0.249709, (float)0.351405, (float)0.326416, (float)0.301382, (float)0.273426, (float)0.352193, (float)0.383082, (float)0.302775, (float)0.294032, (float)0.282470, (float)0.309919, (float)0.237338, (float)0.270537, (float)0.418871, (float)0.298495, (float)0.384072, (float)0.275390, (float)0.309113, (float)0.316944, (float)0.282377, (float)0.274919, (float)0.349322, (float)0.401850, (float)0.310825, (float)0.217624, (float)0.282134, (float)0.319884, (float)0.335810, (float)0.246835, (float)0.333235, (float)0.287557, (float)0.296442, (float)0.238542, (float)0.345085, (float)0.308119, (float)0.276033, (float)0.253318, (float)0.257576, (float)0.309189, (float)0.294967, (float)0.308874, (float)0.311262, (float)0.347532, (float)0.317155, (float)0.247428, (float)0.337070, (float)0.345042, (float)0.318918, (float)0.314958, (float)0.300786, (float)0.269426, (float)0.373029, (float)0.323512, (float)0.298830, (float)0.281176, (float)0.324457, (float)0.363002, (float)0.284270, (float)0.353284, (float)0.345131, (float)0.324354, (float)0.352450, (float)0.311796, (float)0.342882, (float)0.321482, (float)0.274752, (float)0.328727, (float)0.365552, (float)0.290056, (float)0.252260, (float)0.328359, (float)0.252313, (float)0.342566, (float)0.285146, (float)0.291776, (float)0.249690, (float)0.515868, (float)0.302605, (float)0.274273, (float)0.237944, (float)0.352385, (float)0.339384, (float)0.226397, (float)0.265234, (float)0.375858, (float)0.377673, (float)0.245921, (float)0.304622, (float)0.306692, (float)0.377470, (float)0.297616, (float)0.355231, (float)0.269597, (float)0.264911, (float)0.287163, (float)0.298522, (float)0.286704, (float)0.367557, (float)0.349431, (float)0.382281, (float)0.324598, (float)0.356710, (float)0.266202, (float)0.335733, (float)0.293518, (float)0.298707, (float)0.266426, (float)0.301895, (float)0.317489, (float)0.243584, (float)0.327437, (float)0.276378, (float)0.246619, (float)0.287555, (float)0.305970, (float)0.315744, (float)0.332885, (float)0.298386, (float)0.296086, (float)0.330902, (float)0.372892, (float)0.323777, (float)0.349068, (float)0.334237, (float)0.303659, (float)0.357816, (float)0.284855, (float)0.282661, (float)0.280880, (float)0.324879};	// L4150
  #pragma HLS resource variable=v3545 core=ram_t2p_bram

  float v3546[256] = {(float)0.250864, (float)0.298932, (float)0.281011, (float)0.261564, (float)0.303803, (float)0.361369, (float)0.174898, (float)0.261464, (float)0.231546, (float)0.259326, (float)0.319929, (float)0.203902, (float)0.393703, (float)0.281866, (float)0.692774, (float)0.166908, (float)0.197141, (float)0.234712, (float)0.179814, (float)0.258408, (float)0.204510, (float)0.224671, (float)0.257510, (float)0.189613, (float)0.224339, (float)0.329013, (float)0.226237, (float)0.162855, (float)0.174987, (float)0.216183, (float)0.268586, (float)0.198980, (float)0.302773, (float)0.247399, (float)0.630018, (float)0.274692, (float)0.234032, (float)0.218395, (float)0.347572, (float)0.196595, (float)0.173869, (float)0.201052, (float)0.188224, (float)0.191662, (float)0.234873, (float)0.179596, (float)0.201768, (float)0.195002, (float)0.218602, (float)0.259526, (float)0.152205, (float)0.208831, (float)0.138049, (float)0.525828, (float)0.165894, (float)0.328321, (float)0.193083, (float)0.234705, (float)0.144876, (float)0.261347, (float)0.272002, (float)0.185486, (float)0.246871, (float)0.233705, (float)0.252473, (float)0.148685, (float)0.174042, (float)0.210088, (float)0.350658, (float)0.166817, (float)0.285117, (float)0.187431, (float)0.172494, (float)0.261913, (float)0.190267, (float)0.277414, (float)0.187483, (float)0.258448, (float)0.163465, (float)0.269258, (float)0.170919, (float)0.709311, (float)0.226438, (float)0.243884, (float)0.271709, (float)0.201970, (float)0.242027, (float)0.197879, (float)0.324886, (float)0.232497, (float)0.217436, (float)0.239979, (float)0.220082, (float)0.191406, (float)0.231140, (float)0.472309, (float)0.274862, (float)0.203280, (float)0.437263, (float)0.212425, (float)0.195578, (float)0.157026, (float)0.249678, (float)0.272318, (float)0.192829, (float)0.272554, (float)0.194160, (float)0.286151, (float)0.273076, (float)0.234804, (float)0.325900, (float)0.307940, (float)0.279887, (float)0.186518, (float)0.241578, (float)0.226162, (float)0.350172, (float)0.216920, (float)0.237095, (float)0.174961, (float)0.282227, (float)0.198301, (float)0.397905, (float)0.237978, (float)0.179769, (float)0.266089, (float)0.163974, (float)0.426010, (float)0.203198, (float)0.176351, (float)0.180248, (float)0.282140, (float)0.478301, (float)0.189528, (float)0.336067, (float)0.200891, (float)0.154111, (float)0.202102, (float)0.236516, (float)0.352982, (float)0.183315, (float)0.613094, (float)0.183968, (float)0.277182, (float)0.273462, (float)0.179923, (float)0.400513, (float)0.214398, (float)0.267736, (float)0.266503, (float)0.421295, (float)0.237306, (float)0.240770, (float)0.257516, (float)0.389262, (float)0.172283, (float)0.317349, (float)0.201366, (float)0.509833, (float)0.225395, (float)0.210268, (float)0.315547, (float)0.306514, (float)0.181416, (float)0.251151, (float)0.166545, (float)0.207832, (float)0.235228, (float)0.216052, (float)0.167390, (float)0.430228, (float)0.304516, (float)0.351816, (float)0.162007, (float)0.223414, (float)0.202807, (float)0.152331, (float)0.331499, (float)0.208631, (float)0.300535, (float)0.276002, (float)0.198756, (float)0.168350, (float)0.211100, (float)0.307697, (float)0.280259, (float)0.304477, (float)0.177278, (float)0.179699, (float)0.147033, (float)0.212199, (float)0.214709, (float)0.168834, (float)0.191250, (float)0.206656, (float)0.244358, (float)0.260919, (float)0.275039, (float)0.259668, (float)0.237292, (float)0.221625, (float)0.398130, (float)0.774624, (float)0.201475, (float)0.173361, (float)0.363690, (float)0.174825, (float)0.249547, (float)0.245724, (float)0.155897, (float)0.274097, (float)0.376527, (float)0.276687, (float)0.284072, (float)0.255299, (float)0.158174, (float)0.332825, (float)0.199572, (float)0.228403, (float)0.272024, (float)0.251950, (float)0.272385, (float)0.193060, (float)0.292428, (float)0.262938, (float)0.375961, (float)0.220595, (float)0.261611, (float)0.190731, (float)0.282084, (float)0.275237, (float)0.230336, (float)0.272964, (float)0.233962, (float)0.223458, (float)0.146601, (float)0.286886, (float)0.276269, (float)0.282303, (float)0.184287, (float)0.180444, (float)0.224428, (float)0.184037, (float)0.144650, (float)0.212632, (float)0.179212, (float)0.254628, (float)0.166118, (float)0.188118, (float)0.166739, (float)0.237100, (float)0.252300, (float)0.226000, (float)0.272757, (float)0.202812, (float)0.480202};	// L4151
  #pragma HLS resource variable=v3546 core=ram_t2p_bram

  float v3547[256] = {(float)-0.125285, (float)-0.226214, (float)-0.486030, (float)-0.145832, (float)-0.631118, (float)0.007284, (float)-0.059700, (float)0.003752, (float)-0.136321, (float)-0.221260, (float)-0.384376, (float)-0.578263, (float)-1.271543, (float)-0.454579, (float)-1.409158, (float)-0.486397, (float)0.288440, (float)-0.782657, (float)0.305954, (float)-0.354159, (float)-0.571101, (float)-0.799809, (float)0.088768, (float)-0.143884, (float)-0.686732, (float)-0.858843, (float)-0.544732, (float)0.298266, (float)-0.191937, (float)0.134417, (float)-0.638721, (float)-0.471627, (float)0.613940, (float)-0.006469, (float)0.009157, (float)-0.754339, (float)-0.366568, (float)-0.147949, (float)-0.726295, (float)-0.306396, (float)-0.300255, (float)-0.488007, (float)-0.368779, (float)-0.329479, (float)-0.146555, (float)-0.668113, (float)-0.121652, (float)-0.566083, (float)-0.754172, (float)-0.497712, (float)-0.198177, (float)-0.748014, (float)0.293547, (float)-0.503929, (float)-0.415239, (float)-0.184573, (float)-0.065346, (float)-0.361654, (float)0.097863, (float)-0.098897, (float)-0.874720, (float)-0.686600, (float)-0.285040, (float)-0.180705, (float)-0.756375, (float)0.489559, (float)-0.471906, (float)-0.325071, (float)0.236078, (float)-0.282303, (float)-0.545358, (float)-0.570296, (float)-0.391414, (float)-0.745949, (float)-0.312741, (float)0.498307, (float)-0.429021, (float)0.050147, (float)-0.146516, (float)-0.606047, (float)0.313227, (float)-0.374327, (float)-0.582572, (float)-0.384315, (float)-0.107641, (float)-0.565698, (float)-0.310177, (float)0.317944, (float)-0.778714, (float)-0.032611, (float)-0.472261, (float)-0.566884, (float)-0.014164, (float)-0.597379, (float)-0.317522, (float)-0.936114, (float)-0.183842, (float)0.132857, (float)-1.032077, (float)-0.059062, (float)-0.459894, (float)-0.509421, (float)0.207018, (float)-0.052015, (float)0.150766, (float)-0.861900, (float)-0.087798, (float)-0.813155, (float)-0.385866, (float)-0.229938, (float)-0.609966, (float)-0.224648, (float)-0.346424, (float)-0.951537, (float)0.085479, (float)0.310099, (float)-0.472149, (float)-0.415532, (float)0.007986, (float)-0.173154, (float)-0.650107, (float)-0.620344, (float)-0.137175, (float)-0.152218, (float)-0.286989, (float)-0.494054, (float)0.096648, (float)0.507254, (float)-0.251031, (float)-0.303242, (float)-0.314956, (float)-0.573268, (float)-0.054476, (float)-0.344083, (float)-0.764426, (float)-0.232119, (float)-0.773845, (float)-0.174531, (float)0.242331, (float)-0.335081, (float)-0.129590, (float)-0.512466, (float)-0.110073, (float)-0.876779, (float)-0.286019, (float)-0.355995, (float)-0.124355, (float)-0.299707, (float)-0.157739, (float)-0.316033, (float)-0.174813, (float)0.589301, (float)0.125172, (float)-0.280216, (float)-0.051413, (float)-0.660500, (float)-0.198867, (float)-0.106192, (float)-0.084415, (float)-0.672405, (float)-0.000834, (float)-0.260551, (float)-0.382815, (float)-0.167397, (float)-1.455198, (float)-0.445208, (float)-0.215850, (float)-0.587816, (float)-0.417873, (float)-0.621527, (float)0.173720, (float)-0.588677, (float)-0.572029, (float)0.074681, (float)-0.600545, (float)-0.346055, (float)-0.325968, (float)-0.357741, (float)-0.093304, (float)-0.358804, (float)-0.393470, (float)-0.955065, (float)-0.914292, (float)-0.276236, (float)-0.365220, (float)-0.170353, (float)-0.267629, (float)-0.229179, (float)-0.380049, (float)-0.492739, (float)-0.217846, (float)-0.361399, (float)-0.127377, (float)-0.520279, (float)-0.543694, (float)0.020979, (float)-0.635725, (float)-0.592680, (float)-0.161099, (float)-0.101500, (float)-0.406663, (float)-0.421175, (float)-0.267119, (float)-0.327238, (float)-0.499771, (float)0.010453, (float)-0.397699, (float)-0.461170, (float)-0.067067, (float)0.152801, (float)-0.192739, (float)-0.401757, (float)-0.581724, (float)-0.338345, (float)-0.507856, (float)-0.606219, (float)-0.209398, (float)0.034390, (float)0.004939, (float)-0.007406, (float)-0.843081, (float)-0.882384, (float)-0.354944, (float)-0.209500, (float)-0.493705, (float)-0.290731, (float)-0.441446, (float)-0.489615, (float)0.083633, (float)-0.977952, (float)-0.472126, (float)-0.147393, (float)-0.318508, (float)-0.243628, (float)-0.179690, (float)-0.042850, (float)-0.297155, (float)-0.429911, (float)-0.312470, (float)-0.369892, (float)-0.489870, (float)-0.097868, (float)-0.780393, (float)-0.392426, (float)0.084980, (float)-0.503046, (float)-0.675454, (float)-0.250641, (float)-0.435426, (float)-0.244056, (float)0.019346, (float)-0.344223, (float)-0.675849, (float)-0.448382, (float)-0.162842, (float)-0.680128};	// L4152
  #pragma HLS resource variable=v3547 core=ram_t2p_bram

  float v3548[128] = {(float)-0.140328, (float)-0.088945, (float)-0.414691, (float)-0.226405, (float)-0.073735, (float)-0.353450, (float)-0.337907, (float)-0.075212, (float)-0.179123, (float)0.044826, (float)-0.284193, (float)-0.176455, (float)-0.159067, (float)-0.067545, (float)-0.154270, (float)-0.106100, (float)-0.233439, (float)-0.098128, (float)-0.090774, (float)-0.056665, (float)-0.190828, (float)-0.205473, (float)-0.270418, (float)-0.188264, (float)-0.356957, (float)-0.112524, (float)-0.163161, (float)-0.021077, (float)-0.168745, (float)-0.212433, (float)-0.171320, (float)-0.087193, (float)-0.219359, (float)-0.188759, (float)-0.295415, (float)-0.457019, (float)-0.022601, (float)-0.052663, (float)0.040554, (float)-0.060934, (float)-0.045578, (float)-0.117637, (float)-0.014481, (float)0.031818, (float)-0.204581, (float)-0.095336, (float)-0.049646, (float)-0.105117, (float)-0.079309, (float)-0.193274, (float)-0.146744, (float)-0.321475, (float)-0.325699, (float)-0.228701, (float)-0.035580, (float)-0.186885, (float)-0.193175, (float)-0.077068, (float)0.276766, (float)-0.065632, (float)-0.089503, (float)-0.254808, (float)-0.236533, (float)0.002141, (float)-0.098652, (float)-0.317785, (float)0.161271, (float)0.000558, (float)-0.234711, (float)-0.414953, (float)-0.131037, (float)-0.314176, (float)-0.258199, (float)-0.539954, (float)0.077238, (float)-0.254571, (float)-0.445436, (float)-0.026179, (float)-0.093667, (float)-0.220115, (float)-0.204358, (float)-0.015544, (float)-0.089319, (float)-0.216655, (float)0.111158, (float)-0.061883, (float)-0.121699, (float)-0.159310, (float)-0.131706, (float)-0.171691, (float)-0.372923, (float)-0.335352, (float)-0.341418, (float)0.035783, (float)-0.206719, (float)-0.108735, (float)0.014148, (float)-0.033818, (float)-0.212884, (float)-0.112212, (float)-0.162665, (float)-0.199955, (float)0.090774, (float)-0.004113, (float)-0.131348, (float)-0.294189, (float)0.016028, (float)-0.106472, (float)-0.128883, (float)-0.169939, (float)-0.172128, (float)-0.180889, (float)-0.229467, (float)-0.361108, (float)-0.174603, (float)-0.353952, (float)-0.155432, (float)-0.270855, (float)-0.260711, (float)0.008433, (float)-0.031063, (float)-0.002231, (float)-0.083139, (float)0.038031, (float)-0.489251, (float)-0.274916, (float)0.124518, (float)-0.127154};	// L4153
  #pragma HLS resource variable=v3548 core=ram_t2p_bram

  float v3549[128] = {(float)0.119389, (float)0.162451, (float)0.308392, (float)0.293060, (float)0.295737, (float)0.526303, (float)0.403845, (float)0.202352, (float)0.340056, (float)0.198215, (float)0.255910, (float)0.231121, (float)0.163044, (float)0.289084, (float)0.224845, (float)0.231051, (float)0.241681, (float)0.218689, (float)0.192158, (float)0.310324, (float)0.201460, (float)0.480243, (float)0.248132, (float)0.389808, (float)0.320391, (float)0.403485, (float)0.261744, (float)0.155120, (float)0.225615, (float)0.211736, (float)0.270751, (float)0.353666, (float)0.250458, (float)0.184278, (float)0.246481, (float)0.650101, (float)0.389760, (float)0.428938, (float)0.179944, (float)0.160353, (float)0.177524, (float)0.359953, (float)0.269352, (float)0.128253, (float)0.166169, (float)0.171629, (float)0.183674, (float)0.171020, (float)0.417839, (float)0.324853, (float)0.175895, (float)0.471709, (float)0.411493, (float)0.199489, (float)0.202503, (float)0.149152, (float)0.286027, (float)0.107250, (float)0.364880, (float)0.190612, (float)0.536862, (float)0.240043, (float)0.441093, (float)0.170234, (float)0.199319, (float)0.204474, (float)0.197212, (float)0.404137, (float)0.303404, (float)0.616775, (float)0.228446, (float)0.322839, (float)0.454725, (float)0.436961, (float)0.157013, (float)0.405716, (float)0.579129, (float)0.233751, (float)0.158552, (float)0.313032, (float)0.220113, (float)0.319544, (float)0.116600, (float)0.251712, (float)0.218374, (float)0.098906, (float)0.311623, (float)0.261283, (float)0.327686, (float)0.177789, (float)0.271778, (float)0.417423, (float)0.513997, (float)0.213603, (float)0.190534, (float)0.289775, (float)0.247165, (float)0.134083, (float)0.621224, (float)0.181041, (float)0.239355, (float)0.141709, (float)0.175946, (float)0.282684, (float)0.198707, (float)0.377475, (float)0.374890, (float)0.127358, (float)0.365601, (float)0.430489, (float)0.421177, (float)0.267256, (float)0.201616, (float)0.509774, (float)0.144946, (float)0.440837, (float)0.358322, (float)0.250295, (float)0.568202, (float)0.251753, (float)0.139241, (float)0.061661, (float)0.340573, (float)0.131263, (float)0.458603, (float)0.291374, (float)0.132604, (float)0.391477};	// L4154
  #pragma HLS resource variable=v3549 core=ram_t2p_bram

  float v3550[128] = {(float)0.018228, (float)0.021225, (float)0.028612, (float)0.020886, (float)0.029474, (float)0.047744, (float)0.035290, (float)0.028429, (float)0.028470, (float)0.045069, (float)0.029840, (float)0.019491, (float)0.017088, (float)0.029840, (float)0.028539, (float)0.028518, (float)0.020139, (float)0.022774, (float)0.032135, (float)0.033348, (float)0.017759, (float)0.047420, (float)0.030149, (float)0.041645, (float)0.037812, (float)0.046252, (float)0.029589, (float)0.016504, (float)0.026924, (float)0.030834, (float)0.036263, (float)0.045937, (float)0.031620, (float)0.026538, (float)0.022904, (float)0.058237, (float)0.056463, (float)0.040456, (float)0.026616, (float)0.032348, (float)0.033927, (float)0.084368, (float)0.024933, (float)0.017348, (float)0.022366, (float)0.021032, (float)0.019272, (float)0.015102, (float)0.056145, (float)0.039999, (float)0.018257, (float)0.040509, (float)0.032031, (float)0.022098, (float)0.033824, (float)0.022704, (float)0.025319, (float)0.018465, (float)0.068178, (float)0.026885, (float)0.072726, (float)0.021805, (float)0.049063, (float)0.026663, (float)0.023015, (float)0.013440, (float)0.047817, (float)0.058346, (float)0.033150, (float)0.047472, (float)0.018629, (float)0.033559, (float)0.045253, (float)0.031564, (float)0.036324, (float)0.034589, (float)0.047584, (float)0.032355, (float)0.017391, (float)0.035121, (float)0.018529, (float)0.053177, (float)0.013671, (float)0.030469, (float)0.037829, (float)0.016996, (float)0.041624, (float)0.031600, (float)0.032903, (float)0.016922, (float)0.032056, (float)0.043576, (float)0.035142, (float)0.024761, (float)0.016919, (float)0.038553, (float)0.036356, (float)0.017814, (float)0.062490, (float)0.040622, (float)0.025852, (float)0.022963, (float)0.027265, (float)0.029650, (float)0.020724, (float)0.044788, (float)0.057808, (float)0.020073, (float)0.039706, (float)0.058224, (float)0.043781, (float)0.036008, (float)0.026018, (float)0.035214, (float)0.019792, (float)0.032273, (float)0.049339, (float)0.016944, (float)0.062593, (float)0.029896, (float)0.025511, (float)0.015677, (float)0.036686, (float)0.015467, (float)0.031936, (float)0.028402, (float)0.028767, (float)0.044939};	// L4155
  #pragma HLS resource variable=v3550 core=ram_t2p_bram

  float v3551[128] = {(float)-0.030282, (float)0.032654, (float)0.024031, (float)-0.076254, (float)-0.158904, (float)-0.080364, (float)-0.179721, (float)-0.070087, (float)-0.157296, (float)0.113432, (float)-0.080524, (float)-0.023368, (float)-0.075576, (float)-0.183264, (float)0.038381, (float)0.079149, (float)-0.059366, (float)-0.021708, (float)0.028777, (float)-0.102287, (float)-0.069791, (float)-0.048403, (float)0.123386, (float)-0.124158, (float)0.058383, (float)-0.104519, (float)-0.008196, (float)-0.053568, (float)0.012729, (float)0.026888, (float)-0.178475, (float)-0.051413, (float)-0.050308, (float)0.017321, (float)0.016230, (float)-0.253243, (float)-0.281744, (float)-0.238800, (float)-0.064062, (float)0.013646, (float)0.139668, (float)-0.282715, (float)0.076684, (float)-0.032818, (float)-0.007989, (float)-0.005788, (float)-0.132186, (float)-0.026603, (float)-0.399491, (float)-0.082451, (float)-0.106088, (float)-0.055577, (float)-0.055737, (float)0.055247, (float)-0.125942, (float)-0.007705, (float)-0.101706, (float)-0.053206, (float)-0.157038, (float)0.067522, (float)-0.557878, (float)0.052287, (float)-0.110857, (float)0.009559, (float)0.010253, (float)-0.096847, (float)-0.009989, (float)-0.263148, (float)-0.101345, (float)-0.015615, (float)-0.054351, (float)-0.143559, (float)-0.074740, (float)-0.060869, (float)-0.071018, (float)-0.117134, (float)0.020510, (float)0.037233, (float)-0.016161, (float)-0.024520, (float)0.168410, (float)-0.286805, (float)0.055828, (float)0.040196, (float)-0.136006, (float)-0.052269, (float)-0.054720, (float)-0.110828, (float)-0.248952, (float)-0.025246, (float)0.078344, (float)-0.192699, (float)-0.142652, (float)-0.112169, (float)-0.059888, (float)-0.088440, (float)-0.019096, (float)0.001496, (float)-0.552184, (float)0.004240, (float)0.030461, (float)0.024223, (float)-0.124602, (float)-0.154293, (float)0.004527, (float)-0.180832, (float)-0.222397, (float)0.090906, (float)0.032938, (float)0.545644, (float)-0.022998, (float)0.062755, (float)0.046356, (float)-0.087351, (float)-0.029993, (float)0.110824, (float)-0.049152, (float)-0.033058, (float)-0.247085, (float)-0.035225, (float)0.051587, (float)0.070940, (float)-0.240892, (float)-0.065018, (float)-0.168374, (float)-0.056477, (float)-0.130560, (float)-0.062673};	// L4156
  #pragma HLS resource variable=v3551 core=ram_t2p_bram

  float v3552[128] = {(float)-0.173491, (float)-0.233710, (float)-0.338329, (float)-0.080570, (float)-0.192011, (float)-0.062054, (float)-0.188519, (float)-0.283036, (float)-0.168034, (float)-0.179567, (float)-0.264540, (float)-0.198254, (float)-0.118316, (float)-0.243189, (float)-0.170644, (float)-0.308978, (float)-0.266079, (float)-0.403989, (float)-0.194935, (float)-0.139227, (float)-0.244917, (float)-0.124167, (float)-0.201219, (float)-0.190123, (float)-0.101361, (float)-0.346804, (float)-0.224452, (float)-0.327163, (float)-0.305659, (float)-0.328909, (float)-0.153208, (float)-0.196746, (float)-0.066690, (float)-0.328066, (float)-0.141847, (float)-0.152700, (float)-0.098708, (float)-0.324310, (float)-0.225153, (float)-0.346165, (float)-0.228392, (float)-0.226256, (float)-0.180956, (float)-0.156392, (float)-0.172998, (float)-0.150661, (float)-0.291292, (float)-0.164308, (float)-0.199820, (float)-0.153210, (float)-0.221071, (float)-0.224671, (float)-0.091338, (float)-0.156250, (float)-0.245263, (float)-0.485364, (float)-0.442787, (float)-0.102146, (float)-0.161508, (float)-0.212533, (float)-0.223903, (float)-0.195173, (float)-0.044655, (float)-0.173257, (float)-0.117751, (float)-0.477455, (float)-0.211025, (float)-0.230468, (float)-0.179492, (float)-0.158220, (float)-0.200780, (float)-0.204053, (float)-0.197439, (float)-0.274988, (float)-0.039521, (float)-0.216061, (float)-0.278604, (float)-0.262572, (float)-0.099668, (float)-0.295324, (float)-0.143103, (float)-0.144757, (float)-0.189352, (float)-0.128346, (float)-0.180698, (float)-0.114418, (float)-0.130784, (float)-0.415391, (float)-0.232355, (float)-0.137638, (float)-0.115441, (float)-0.209871, (float)-0.096623, (float)-0.166871, (float)-0.383489, (float)-0.254503, (float)-0.160312, (float)-0.190372, (float)-0.241955, (float)-0.165757, (float)-0.113350, (float)-0.149788, (float)-0.121281, (float)-0.231825, (float)-0.201705, (float)-0.382692, (float)-0.149086, (float)-0.117410, (float)-0.126119, (float)-0.203114, (float)-0.183187, (float)-0.227419, (float)-0.128094, (float)-0.255662, (float)-0.140035, (float)-0.072347, (float)-0.221194, (float)-0.148563, (float)-0.291366, (float)-0.111600, (float)-0.219389, (float)-0.489799, (float)-0.369349, (float)-0.143669, (float)-0.123228, (float)-0.372334, (float)-0.679388, (float)-0.153556};	// L4157
  #pragma HLS resource variable=v3552 core=ram_t2p_bram

  float v3553[128] = {(float)0.332279, (float)0.290789, (float)0.324604, (float)0.343499, (float)0.301133, (float)0.305367, (float)0.304133, (float)0.353912, (float)0.286192, (float)0.360089, (float)0.297030, (float)0.338131, (float)0.256527, (float)0.327597, (float)0.303041, (float)0.408485, (float)0.351930, (float)0.421810, (float)0.305489, (float)0.255109, (float)0.342549, (float)0.321531, (float)0.336599, (float)0.270019, (float)0.284925, (float)0.395363, (float)0.316580, (float)0.328618, (float)0.351512, (float)0.395284, (float)0.276768, (float)0.362486, (float)0.198786, (float)0.271687, (float)0.335525, (float)0.279714, (float)0.250960, (float)0.383155, (float)0.326616, (float)0.326292, (float)0.368095, (float)0.340069, (float)0.365079, (float)0.339102, (float)0.307109, (float)0.323148, (float)0.369146, (float)0.241042, (float)0.353627, (float)0.318859, (float)0.323815, (float)0.361054, (float)0.308593, (float)0.330886, (float)0.388617, (float)0.436192, (float)0.454995, (float)0.296215, (float)0.307095, (float)0.338550, (float)0.331689, (float)0.322825, (float)0.239334, (float)0.314733, (float)0.273822, (float)0.321808, (float)0.319823, (float)0.341149, (float)0.361058, (float)0.283285, (float)0.303515, (float)0.318290, (float)0.314626, (float)0.389027, (float)0.260684, (float)0.347912, (float)0.323576, (float)0.370897, (float)0.259174, (float)0.374153, (float)0.255528, (float)0.296578, (float)0.350519, (float)0.316516, (float)0.280768, (float)0.266033, (float)0.281745, (float)0.479532, (float)0.337221, (float)0.272313, (float)0.295520, (float)0.322453, (float)0.247034, (float)0.316046, (float)0.351453, (float)0.313138, (float)0.337206, (float)0.283730, (float)0.354032, (float)0.289689, (float)0.249013, (float)0.301909, (float)0.311431, (float)0.351002, (float)0.302211, (float)0.361745, (float)0.285898, (float)0.283114, (float)0.324345, (float)0.276870, (float)0.331425, (float)0.239431, (float)0.293249, (float)0.278819, (float)0.268619, (float)0.319401, (float)0.354174, (float)0.268255, (float)0.295470, (float)0.292432, (float)0.353813, (float)0.425614, (float)0.360298, (float)0.301261, (float)0.276316, (float)0.435417, (float)0.399058, (float)0.269375};	// L4158
  #pragma HLS resource variable=v3553 core=ram_t2p_bram

  float v3554[128] = {(float)0.265984, (float)0.142226, (float)0.240406, (float)0.429715, (float)0.130597, (float)0.333568, (float)0.193908, (float)0.159962, (float)0.216622, (float)0.406987, (float)0.102928, (float)0.344171, (float)0.202139, (float)0.158985, (float)0.222596, (float)0.184193, (float)0.273120, (float)0.226213, (float)0.217797, (float)0.153600, (float)0.172152, (float)0.203482, (float)0.339101, (float)0.157192, (float)0.227613, (float)0.273962, (float)0.154285, (float)0.130658, (float)0.164928, (float)0.257095, (float)0.143062, (float)0.234942, (float)0.176451, (float)0.117135, (float)0.340118, (float)0.165663, (float)0.130661, (float)0.316855, (float)0.197333, (float)0.150357, (float)0.318104, (float)0.252881, (float)0.298031, (float)0.246102, (float)0.285730, (float)0.281353, (float)0.188892, (float)0.112508, (float)0.207923, (float)0.213070, (float)0.215777, (float)0.337231, (float)0.279137, (float)0.285221, (float)0.510197, (float)0.180843, (float)0.253995, (float)0.387584, (float)0.204832, (float)0.171647, (float)0.277470, (float)0.238497, (float)0.199155, (float)0.332500, (float)0.183191, (float)0.124644, (float)0.185207, (float)0.208308, (float)0.317851, (float)0.307654, (float)0.184214, (float)0.184476, (float)0.168399, (float)0.244728, (float)0.299013, (float)0.241209, (float)0.337016, (float)0.197437, (float)0.167910, (float)0.245905, (float)0.166989, (float)0.176372, (float)0.225831, (float)0.374315, (float)0.146398, (float)0.170609, (float)0.292521, (float)0.259431, (float)0.212312, (float)0.219105, (float)0.228057, (float)0.180866, (float)0.127798, (float)0.257516, (float)0.338658, (float)0.175510, (float)0.308295, (float)0.139915, (float)0.219728, (float)0.159400, (float)0.131078, (float)0.224978, (float)0.342173, (float)0.239100, (float)0.123958, (float)0.206810, (float)0.278398, (float)0.179967, (float)0.313302, (float)0.116730, (float)0.306559, (float)0.100834, (float)0.172883, (float)0.304478, (float)0.218748, (float)0.286205, (float)0.236073, (float)0.156040, (float)0.127094, (float)0.246670, (float)0.220105, (float)0.142332, (float)0.153068, (float)0.299454, (float)0.206944, (float)0.212649, (float)0.136926, (float)0.156573};	// L4159
  #pragma HLS resource variable=v3554 core=ram_t2p_bram

  float v3555[128] = {(float)-0.359329, (float)-0.477234, (float)0.232878, (float)-0.713911, (float)-0.671253, (float)-0.555205, (float)-0.455632, (float)-0.650177, (float)-0.208170, (float)-0.401110, (float)-0.394219, (float)-0.296979, (float)-0.162634, (float)-0.437940, (float)-0.333381, (float)-0.616314, (float)-0.298241, (float)-0.519042, (float)0.167560, (float)-0.183182, (float)-0.207992, (float)-0.529586, (float)-0.424530, (float)-0.175528, (float)-0.855614, (float)-0.306702, (float)-0.456019, (float)-0.164220, (float)-0.505888, (float)-0.452942, (float)-0.453194, (float)-0.725371, (float)0.603657, (float)-0.250895, (float)-0.019907, (float)-0.467233, (float)-0.590104, (float)-0.419542, (float)-0.327237, (float)0.565780, (float)-0.343822, (float)-0.599216, (float)-0.268328, (float)-0.459065, (float)-0.346020, (float)-0.166886, (float)-0.327144, (float)0.035087, (float)-0.417475, (float)-0.398392, (float)-0.411848, (float)-0.361882, (float)-0.131267, (float)-0.275814, (float)-0.719622, (float)-0.540127, (float)-1.173857, (float)-0.049651, (float)-0.135809, (float)-0.613852, (float)-0.514309, (float)-0.301727, (float)-0.046470, (float)-0.397720, (float)-0.025143, (float)0.382112, (float)-0.507901, (float)-0.279453, (float)-0.190372, (float)0.399343, (float)-0.441783, (float)-0.181321, (float)-0.612221, (float)-0.313241, (float)-0.065635, (float)-0.445764, (float)0.089382, (float)-0.375939, (float)0.043963, (float)-0.397213, (float)-0.286045, (float)0.087717, (float)-0.082471, (float)-0.762022, (float)-0.026026, (float)-0.386070, (float)-0.112798, (float)-0.412884, (float)-0.288291, (float)1.105405, (float)-0.389190, (float)-0.039337, (float)-0.139370, (float)-0.167832, (float)0.182516, (float)-0.437861, (float)-0.252168, (float)-0.111858, (float)-0.509824, (float)-0.032774, (float)-0.287390, (float)-0.380895, (float)-0.192937, (float)-0.335496, (float)-0.386343, (float)-0.161692, (float)-0.228914, (float)0.166474, (float)-0.687425, (float)-0.170472, (float)-0.521633, (float)-0.331493, (float)-0.667820, (float)0.534173, (float)0.143320, (float)-0.555769, (float)-0.427653, (float)-0.323982, (float)-0.214243, (float)0.021606, (float)-0.437899, (float)-0.848646, (float)-0.767517, (float)-0.451166, (float)0.278764, (float)-0.969427, (float)-1.169143, (float)0.019830};	// L4160
  #pragma HLS resource variable=v3555 core=ram_t2p_bram

  float v3556[128] = {(float)0.333437, (float)0.058141, (float)0.071451, (float)0.344152, (float)0.175646, (float)0.150940, (float)0.156753, (float)0.309979, (float)0.192735, (float)0.151586, (float)0.304443, (float)0.223826, (float)0.370650, (float)0.173883, (float)0.305100, (float)0.261006, (float)0.157454, (float)0.201529, (float)0.293294, (float)0.100969, (float)0.587052, (float)0.067581, (float)0.249943, (float)0.092899, (float)0.244333, (float)0.049473, (float)0.244866, (float)0.275016, (float)0.307121, (float)0.302456, (float)0.181769, (float)0.068811, (float)0.222305, (float)0.376576, (float)0.466122, (float)0.328428, (float)0.103522, (float)0.339995, (float)0.232495, (float)0.151386, (float)0.175311, (float)0.226932, (float)0.260599, (float)0.183070, (float)0.289391, (float)0.258995, (float)0.220830, (float)0.139903, (float)0.064348, (float)0.283322, (float)0.345072, (float)0.201662, (float)0.069578, (float)0.272249, (float)0.112749, (float)0.291654, (float)0.235779, (float)0.270338, (float)0.091056, (float)0.259050, (float)0.130156, (float)0.226135, (float)0.196738, (float)0.053907, (float)0.069651, (float)0.052445, (float)0.105012, (float)0.086111, (float)0.117261, (float)0.095746, (float)0.186192, (float)0.164236, (float)0.133584, (float)0.106451, (float)0.131232, (float)0.088791, (float)0.079264, (float)0.047525, (float)0.304888, (float)0.232467, (float)0.290756, (float)0.129200, (float)0.077844, (float)0.226314, (float)0.237911, (float)0.340521, (float)0.091429, (float)0.193598, (float)0.122301, (float)0.139977, (float)0.295250, (float)0.236044, (float)0.168133, (float)0.133842, (float)0.266574, (float)0.149506, (float)0.076098, (float)0.167363, (float)0.178391, (float)0.171979, (float)0.231797, (float)0.375289, (float)0.210302, (float)0.192155, (float)0.400192, (float)0.171847, (float)0.059252, (float)0.074192, (float)0.068560, (float)0.193075, (float)0.138588, (float)0.111138, (float)0.305451, (float)0.120503, (float)0.344339, (float)0.163305, (float)0.367280, (float)0.153379, (float)0.074206, (float)0.208761, (float)0.039418, (float)0.259399, (float)0.138467, (float)-0.005076, (float)0.190468, (float)0.127526, (float)0.307100, (float)0.168179};	// L4161
  #pragma HLS resource variable=v3556 core=ram_t2p_bram

  float v3557[128] = {(float)0.195075, (float)0.015126, (float)0.024686, (float)0.069140, (float)0.066477, (float)0.038569, (float)0.029205, (float)0.187348, (float)0.047591, (float)0.085917, (float)0.106478, (float)0.091648, (float)0.123286, (float)0.059453, (float)0.122047, (float)0.087753, (float)0.062034, (float)0.083518, (float)0.119766, (float)0.026393, (float)0.141712, (float)0.015137, (float)0.080786, (float)0.022324, (float)0.122655, (float)0.009270, (float)0.109414, (float)0.105676, (float)0.119017, (float)0.148300, (float)0.076409, (float)0.018531, (float)0.064178, (float)0.211846, (float)0.124331, (float)0.055484, (float)0.042722, (float)0.055615, (float)0.112607, (float)0.095887, (float)0.094294, (float)0.113487, (float)0.066087, (float)0.070395, (float)0.122939, (float)0.140619, (float)0.085870, (float)0.067176, (float)0.013766, (float)0.105736, (float)0.111352, (float)0.058925, (float)0.026861, (float)0.096942, (float)0.048945, (float)0.128996, (float)0.076791, (float)0.093506, (float)0.021500, (float)0.129628, (float)0.012155, (float)0.059132, (float)0.058341, (float)0.021649, (float)0.013461, (float)0.010597, (float)0.034173, (float)0.019851, (float)0.056583, (float)0.016790, (float)0.064006, (float)0.053730, (float)0.032178, (float)0.031792, (float)0.058448, (float)0.036133, (float)0.015466, (float)0.015941, (float)0.094866, (float)0.096540, (float)0.092703, (float)0.033148, (float)0.024034, (float)0.112144, (float)0.069260, (float)0.217726, (float)0.025089, (float)0.064994, (float)0.034509, (float)0.035683, (float)0.153443, (float)0.056833, (float)0.036974, (float)0.044199, (float)0.075228, (float)0.041296, (float)0.025106, (float)0.058206, (float)0.037025, (float)0.119014, (float)0.099326, (float)0.264434, (float)0.053664, (float)0.049540, (float)0.112233, (float)0.063765, (float)0.030242, (float)0.037588, (float)0.018721, (float)0.063380, (float)0.030748, (float)0.037784, (float)0.179270, (float)0.023952, (float)0.201506, (float)0.033747, (float)0.144427, (float)0.036813, (float)0.016456, (float)0.070980, (float)0.013318, (float)0.263823, (float)0.028834, (float)0.005705, (float)0.046202, (float)0.029074, (float)0.119795, (float)0.045042};	// L4162
  #pragma HLS resource variable=v3557 core=ram_t2p_bram

  float v3558[128] = {(float)-0.211283, (float)0.135911, (float)0.003872, (float)0.088622, (float)-0.054593, (float)-0.271570, (float)0.252057, (float)-0.203466, (float)0.030309, (float)-0.146448, (float)-0.263998, (float)-0.443631, (float)-0.381481, (float)-0.146328, (float)0.057290, (float)-0.211984, (float)-0.066480, (float)0.243781, (float)0.083157, (float)0.003994, (float)-0.213596, (float)-0.175505, (float)-0.720057, (float)-0.223341, (float)0.104656, (float)0.146672, (float)-0.316539, (float)-0.200965, (float)0.256891, (float)-0.814085, (float)-0.086720, (float)-0.087481, (float)-0.979392, (float)-0.219662, (float)-0.056762, (float)-0.384841, (float)0.257944, (float)0.173454, (float)-0.052807, (float)0.327628, (float)-0.438050, (float)0.189461, (float)-0.131566, (float)-0.310094, (float)-0.286190, (float)-0.016661, (float)-0.221619, (float)-0.193017, (float)0.045372, (float)-0.304901, (float)0.186341, (float)-0.546061, (float)0.046079, (float)0.189910, (float)-0.035324, (float)-0.241548, (float)0.081305, (float)0.478797, (float)0.051930, (float)0.043841, (float)0.137906, (float)-0.403564, (float)-0.123150, (float)0.055124, (float)-0.066305, (float)0.169912, (float)-0.309545, (float)-0.108016, (float)-0.143140, (float)0.233852, (float)-0.289316, (float)0.351272, (float)0.189279, (float)-0.078873, (float)-0.588245, (float)-0.136508, (float)-0.291918, (float)0.286934, (float)0.308479, (float)-0.109600, (float)0.390506, (float)-0.262971, (float)-0.214997, (float)-0.196612, (float)-0.257918, (float)-0.090391, (float)0.050640, (float)-0.027527, (float)0.406672, (float)0.096961, (float)-0.397573, (float)0.217634, (float)0.258483, (float)0.107776, (float)-0.260712, (float)-0.112592, (float)-0.200102, (float)-0.439961, (float)-0.118115, (float)0.216810, (float)-0.129016, (float)-0.143399, (float)0.249810, (float)-0.281125, (float)-0.276826, (float)-0.520892, (float)0.178535, (float)0.116071, (float)-0.180557, (float)-0.144778, (float)-0.070399, (float)-0.359138, (float)-0.458136, (float)-0.111657, (float)-0.191608, (float)0.726131, (float)-0.238154, (float)0.012629, (float)0.074889, (float)-0.009665, (float)0.047987, (float)0.993994, (float)0.063368, (float)0.062898, (float)-0.795395, (float)-0.161197, (float)1.303984, (float)-0.287946};	// L4163
  #pragma HLS resource variable=v3558 core=ram_t2p_bram

  float v3559[128] = {(float)0.024560, (float)0.059340, (float)0.134748, (float)-0.108948, (float)-0.046953, (float)-0.135904, (float)-0.054964, (float)0.050946, (float)-0.061328, (float)0.091555, (float)0.003117, (float)-0.027439, (float)-0.053891, (float)0.017680, (float)0.043196, (float)0.007427, (float)0.054773, (float)-0.032124, (float)-0.022354, (float)0.014151, (float)-0.215038, (float)-0.115954, (float)0.048597, (float)-0.114138, (float)0.106568, (float)0.035475, (float)0.013958, (float)0.017726, (float)0.078118, (float)0.133057, (float)0.013866, (float)0.044721, (float)0.106299, (float)0.052816, (float)-0.053854, (float)-0.115995, (float)0.105490, (float)-0.159093, (float)0.009957, (float)0.119660, (float)0.017048, (float)0.092924, (float)-0.067453, (float)0.098745, (float)0.103357, (float)0.050093, (float)0.029731, (float)0.028066, (float)-0.007469, (float)-0.057654, (float)-0.014447, (float)-0.164012, (float)0.125463, (float)0.081694, (float)0.063531, (float)0.093611, (float)0.021275, (float)0.048635, (float)-0.117394, (float)0.023740, (float)-0.217731, (float)0.009857, (float)-0.188289, (float)0.046725, (float)-0.082868, (float)0.058492, (float)-0.030578, (float)0.050947, (float)0.054060, (float)-0.167106, (float)0.011538, (float)-0.030242, (float)-0.139324, (float)0.011474, (float)0.042843, (float)0.118872, (float)-0.128894, (float)0.047884, (float)0.047402, (float)-0.062519, (float)0.000927, (float)-0.014440, (float)0.090924, (float)0.134192, (float)-0.033815, (float)0.056014, (float)0.084818, (float)-0.046690, (float)0.022831, (float)-0.009708, (float)0.136016, (float)-0.262473, (float)0.008751, (float)-0.055258, (float)0.038344, (float)-0.072012, (float)0.090656, (float)0.161242, (float)-0.107569, (float)0.101078, (float)-0.051920, (float)0.083777, (float)-0.070380, (float)-0.080635, (float)-0.024310, (float)0.053303, (float)0.127705, (float)0.140336, (float)-0.059300, (float)-0.063885, (float)-0.076590, (float)-0.116262, (float)0.066147, (float)-0.164424, (float)0.042161, (float)-0.278612, (float)-0.100634, (float)-0.069588, (float)-0.076140, (float)0.037116, (float)-0.024699, (float)0.091587, (float)-0.019960, (float)-0.017605, (float)0.029791, (float)-0.037279, (float)0.046599, (float)-0.137054};	// L4164
  #pragma HLS resource variable=v3559 core=ram_t2p_bram

  float v3560[128] = {(float)0.145360, (float)0.327034, (float)0.311272, (float)0.253844, (float)0.408611, (float)0.393735, (float)0.440020, (float)0.310809, (float)0.340602, (float)0.216793, (float)0.217005, (float)0.385689, (float)0.197057, (float)0.269211, (float)0.166347, (float)0.245394, (float)0.323222, (float)0.368608, (float)0.389336, (float)0.326424, (float)0.387510, (float)0.470665, (float)0.195832, (float)0.471701, (float)0.167291, (float)0.393835, (float)0.304437, (float)0.192885, (float)0.217518, (float)0.211891, (float)0.422997, (float)0.368287, (float)0.245454, (float)0.222887, (float)0.337012, (float)0.322865, (float)0.268833, (float)0.355672, (float)0.258055, (float)0.403077, (float)0.449247, (float)0.364234, (float)0.259931, (float)0.188145, (float)0.135859, (float)0.295791, (float)0.191273, (float)0.306459, (float)0.398054, (float)0.410152, (float)0.187375, (float)0.451574, (float)0.334031, (float)0.162764, (float)0.359933, (float)0.162416, (float)0.288619, (float)0.135804, (float)0.449146, (float)0.269389, (float)0.482328, (float)0.339347, (float)0.476410, (float)0.315497, (float)0.600514, (float)0.465356, (float)0.526438, (float)0.299068, (float)0.299173, (float)0.462067, (float)0.261355, (float)0.424686, (float)0.466248, (float)0.424928, (float)0.334506, (float)0.265505, (float)0.404762, (float)0.360481, (float)0.178225, (float)0.383255, (float)0.282325, (float)0.384305, (float)0.330699, (float)0.215093, (float)0.331719, (float)0.145785, (float)0.277083, (float)0.491718, (float)0.319917, (float)0.422169, (float)0.155856, (float)0.488359, (float)0.326664, (float)0.343999, (float)0.160794, (float)0.485517, (float)0.267712, (float)0.161554, (float)0.322052, (float)0.424293, (float)0.366113, (float)0.189262, (float)0.339991, (float)0.364810, (float)0.177854, (float)0.354371, (float)0.285221, (float)0.243696, (float)0.447201, (float)0.301112, (float)0.399651, (float)0.617299, (float)0.279388, (float)0.486732, (float)0.150205, (float)0.602134, (float)0.360387, (float)0.469642, (float)0.371103, (float)0.238830, (float)0.534697, (float)0.150882, (float)0.321347, (float)0.439417, (float)0.322947, (float)0.432900, (float)0.148859, (float)0.370201};	// L4165
  #pragma HLS resource variable=v3560 core=ram_t2p_bram

  float v3561[128] = {(float)0.048081, (float)0.057063, (float)0.061899, (float)0.031855, (float)0.089576, (float)0.053762, (float)0.060583, (float)0.102586, (float)0.044504, (float)0.104475, (float)0.047660, (float)0.075112, (float)0.031222, (float)0.050009, (float)0.045284, (float)0.051051, (float)0.084579, (float)0.079215, (float)0.199471, (float)0.059025, (float)0.055521, (float)0.087712, (float)0.054514, (float)0.082450, (float)0.051070, (float)0.104590, (float)0.060172, (float)0.046650, (float)0.057548, (float)0.066726, (float)0.097311, (float)0.092991, (float)0.060063, (float)0.070214, (float)0.069294, (float)0.034683, (float)0.105912, (float)0.040416, (float)0.044948, (float)0.240390, (float)0.199556, (float)0.184995, (float)0.033682, (float)0.049144, (float)0.032698, (float)0.097604, (float)0.039781, (float)0.099897, (float)0.087856, (float)0.075277, (float)0.036786, (float)0.063870, (float)0.115870, (float)0.048717, (float)0.128205, (float)0.061422, (float)0.054136, (float)0.033325, (float)0.090838, (float)0.072602, (float)0.048982, (float)0.075107, (float)0.064598, (float)0.069368, (float)0.144685, (float)0.111054, (float)0.186836, (float)0.064836, (float)0.063890, (float)0.053752, (float)0.063663, (float)0.058872, (float)0.064292, (float)0.106626, (float)0.136297, (float)0.084543, (float)0.067032, (float)0.100692, (float)0.036063, (float)0.074072, (float)0.043717, (float)0.077617, (float)0.072114, (float)0.068459, (float)0.061152, (float)0.060784, (float)0.068841, (float)0.106674, (float)0.060960, (float)0.079729, (float)0.038548, (float)0.057476, (float)0.051169, (float)0.067163, (float)0.022885, (float)0.089759, (float)0.072918, (float)0.044839, (float)0.037924, (float)0.243955, (float)0.076868, (float)0.087841, (float)0.052205, (float)0.054060, (float)0.022537, (float)0.074135, (float)0.130297, (float)0.057613, (float)0.083563, (float)0.049879, (float)0.052438, (float)0.163570, (float)0.087086, (float)0.057702, (float)0.049753, (float)0.111324, (float)0.067851, (float)0.068260, (float)0.046537, (float)0.050457, (float)0.179244, (float)0.084195, (float)0.041398, (float)0.097146, (float)0.046994, (float)0.057527, (float)0.049032, (float)0.045477};	// L4166
  #pragma HLS resource variable=v3561 core=ram_t2p_bram

  float v3562[128] = {(float)-0.453216, (float)-0.152422, (float)-0.377120, (float)-0.071292, (float)-0.287784, (float)-0.153411, (float)-0.544283, (float)-0.187820, (float)-0.295625, (float)-0.036512, (float)-0.033632, (float)-0.147503, (float)0.006782, (float)-0.137726, (float)-0.141708, (float)-0.370328, (float)-0.464431, (float)-0.124823, (float)0.476732, (float)0.038502, (float)-0.325714, (float)-0.153851, (float)-0.318125, (float)-0.103727, (float)0.063922, (float)-0.206649, (float)-0.160771, (float)0.055680, (float)0.125203, (float)-0.381157, (float)-0.230118, (float)-0.125565, (float)-0.284221, (float)-0.094927, (float)-0.362862, (float)-0.101347, (float)0.317283, (float)-0.126387, (float)-0.166025, (float)-0.144379, (float)-0.947483, (float)-1.099162, (float)-0.012528, (float)-0.068993, (float)0.149744, (float)-0.328442, (float)0.088629, (float)-0.346599, (float)-0.263027, (float)-0.158299, (float)-0.309201, (float)-0.036766, (float)-0.016934, (float)-0.343533, (float)-0.374221, (float)-0.248840, (float)-0.107837, (float)-0.306945, (float)-0.101044, (float)0.165530, (float)-0.420061, (float)-0.270237, (float)-0.134241, (float)-0.049494, (float)-0.464282, (float)-0.227078, (float)-0.453005, (float)-0.036464, (float)-0.453056, (float)-0.048457, (float)0.040308, (float)-0.079835, (float)-0.088525, (float)-0.139873, (float)-0.525539, (float)0.025445, (float)-0.121041, (float)-0.268475, (float)-0.144709, (float)-0.111433, (float)-0.578161, (float)-0.344528, (float)-0.009802, (float)-0.850283, (float)-0.038048, (float)-0.244956, (float)-0.070458, (float)-0.116732, (float)-0.194630, (float)-0.376894, (float)-0.509102, (float)0.235545, (float)-0.179103, (float)-0.246469, (float)-0.203475, (float)-0.355957, (float)0.010045, (float)-0.206067, (float)-0.040713, (float)-0.623080, (float)-0.043063, (float)-0.287439, (float)-0.362729, (float)-0.148554, (float)-0.027103, (float)-0.371420, (float)0.131329, (float)-0.182683, (float)-0.229369, (float)-0.066050, (float)-0.043142, (float)-0.959691, (float)0.084918, (float)-0.085548, (float)-0.328571, (float)-0.955873, (float)-0.164016, (float)-0.074490, (float)0.103987, (float)-0.380771, (float)-0.466441, (float)0.082288, (float)-0.214799, (float)-0.336690, (float)-0.077530, (float)-0.167701, (float)-0.066847, (float)-0.101599};	// L4167
  #pragma HLS resource variable=v3562 core=ram_t2p_bram

  float v3563[128] = {(float)-0.058919, (float)-0.168562, (float)-0.020559, (float)0.002724, (float)-0.095516, (float)-0.104846, (float)0.034862, (float)-0.088465, (float)-0.205294, (float)-0.176443, (float)-0.122366, (float)-0.036381, (float)-0.078540, (float)0.208818, (float)-0.040302, (float)-0.182007, (float)-0.107612, (float)0.298905, (float)-0.056967, (float)0.206444, (float)-0.092137, (float)-0.137563, (float)-0.130374, (float)-0.119292, (float)-0.100569, (float)-0.038038, (float)-0.110811, (float)-0.047660, (float)-0.108695, (float)0.158133, (float)-0.112305, (float)-0.158445, (float)0.097579, (float)-0.043000, (float)-0.134921, (float)-0.118917, (float)-0.098579, (float)-0.047895, (float)-0.083688, (float)-0.072037, (float)-0.083597, (float)-0.244234, (float)-0.337563, (float)-0.212384, (float)-0.069257, (float)-0.065093, (float)0.497870, (float)-0.081146, (float)-0.102116, (float)-0.078765, (float)-0.180223, (float)-0.101133, (float)-0.109032, (float)-0.061716, (float)-0.085599, (float)-0.049520, (float)-0.036976, (float)0.002258, (float)-0.050784, (float)-0.242987, (float)0.000918, (float)-0.152533, (float)-0.096342, (float)-0.051610, (float)-0.047299, (float)0.088366, (float)-0.102754, (float)-0.090700, (float)-0.108634, (float)-0.037853, (float)-0.103024, (float)-0.160907, (float)-0.090269, (float)-0.089757, (float)-0.128227, (float)-0.083011, (float)-0.018634, (float)-0.023180, (float)-0.004535, (float)-0.213116, (float)-0.143089, (float)-0.139070, (float)-0.130341, (float)-0.056792, (float)-0.186188, (float)-0.120910, (float)-0.033967, (float)-0.118150, (float)0.229818, (float)-0.208474, (float)-0.133540, (float)0.141824, (float)-0.089086, (float)-0.127267, (float)0.010721, (float)-0.102923, (float)-0.102543, (float)0.156240, (float)-0.093673, (float)-0.065726, (float)-0.124505, (float)-0.045139, (float)-0.070736, (float)-0.044729, (float)0.071477, (float)-0.048389, (float)-0.031163, (float)-0.043704, (float)-0.092708, (float)-0.146466, (float)-0.115128, (float)-0.018331, (float)-0.192681, (float)0.249057, (float)0.029965, (float)-0.130989, (float)-0.046823, (float)-0.085139, (float)-0.042109, (float)-0.041294, (float)-0.045703, (float)-0.143300, (float)-0.098112, (float)-0.104567, (float)-0.131521, (float)-0.124859, (float)-0.098192, (float)-0.096066};	// L4168
  #pragma HLS resource variable=v3563 core=ram_t2p_bram

  float v3564[128] = {(float)0.324834, (float)0.361286, (float)0.296001, (float)0.291272, (float)0.340724, (float)0.343486, (float)0.304928, (float)0.330825, (float)0.344703, (float)0.386029, (float)0.319625, (float)0.262200, (float)0.299442, (float)0.218919, (float)0.239658, (float)0.374363, (float)0.355502, (float)0.194782, (float)0.334943, (float)0.215932, (float)0.334950, (float)0.345426, (float)0.309408, (float)0.376880, (float)0.354555, (float)0.326677, (float)0.317772, (float)0.327223, (float)0.383199, (float)0.258517, (float)0.297278, (float)0.348103, (float)0.282671, (float)0.299546, (float)0.345139, (float)0.347087, (float)0.344019, (float)0.334352, (float)0.321053, (float)0.318047, (float)0.293964, (float)0.335297, (float)0.325333, (float)0.373341, (float)0.319777, (float)0.298675, (float)0.162031, (float)0.326202, (float)0.327120, (float)0.340962, (float)0.369312, (float)0.332041, (float)0.335704, (float)0.295134, (float)0.311533, (float)0.318515, (float)0.313850, (float)0.263277, (float)0.308895, (float)0.360143, (float)0.273400, (float)0.343340, (float)0.333502, (float)0.328786, (float)0.270554, (float)0.287885, (float)0.331762, (float)0.330961, (float)0.317023, (float)0.297651, (float)0.329960, (float)0.321629, (float)0.320513, (float)0.323057, (float)0.348127, (float)0.313005, (float)0.282608, (float)0.285637, (float)0.327924, (float)0.366598, (float)0.328828, (float)0.357500, (float)0.337720, (float)0.290390, (float)0.327274, (float)0.321442, (float)0.333242, (float)0.345229, (float)0.184188, (float)0.391577, (float)0.333745, (float)0.232547, (float)0.328524, (float)0.335796, (float)0.288527, (float)0.314884, (float)0.328837, (float)0.223603, (float)0.315898, (float)0.299266, (float)0.340252, (float)0.321951, (float)0.317072, (float)0.295022, (float)0.284672, (float)0.322377, (float)0.311865, (float)0.261327, (float)0.337353, (float)0.333315, (float)0.333005, (float)0.295903, (float)0.408659, (float)0.219163, (float)0.298173, (float)0.400610, (float)0.308063, (float)0.317075, (float)0.286153, (float)0.295179, (float)0.306962, (float)0.358301, (float)0.323218, (float)0.334503, (float)0.345349, (float)0.304311, (float)0.332711, (float)0.333740};	// L4169
  #pragma HLS resource variable=v3564 core=ram_t2p_bram

  float v3565[128] = {(float)0.593310, (float)0.522483, (float)0.958677, (float)1.298441, (float)0.695402, (float)0.549521, (float)0.712340, (float)0.739628, (float)0.400142, (float)0.592862, (float)0.487997, (float)0.653224, (float)0.590060, (float)0.578593, (float)0.503144, (float)0.698397, (float)0.669882, (float)0.361280, (float)0.625812, (float)0.522611, (float)0.630567, (float)0.690843, (float)0.439007, (float)0.795547, (float)0.850360, (float)0.889134, (float)0.496305, (float)0.766487, (float)0.902729, (float)0.611070, (float)0.463242, (float)0.460936, (float)0.805312, (float)0.462128, (float)0.543827, (float)0.640072, (float)0.620282, (float)0.613264, (float)0.607044, (float)0.655792, (float)0.531518, (float)0.268372, (float)0.144623, (float)0.565144, (float)0.778362, (float)0.697679, (float)0.437897, (float)0.624566, (float)0.774904, (float)0.730056, (float)0.509908, (float)0.629786, (float)0.560832, (float)0.779375, (float)0.685117, (float)0.625684, (float)1.032232, (float)0.742745, (float)0.932032, (float)0.365862, (float)0.749193, (float)0.531596, (float)0.642129, (float)1.224698, (float)0.655463, (float)0.780651, (float)0.712956, (float)0.572756, (float)0.484813, (float)0.618051, (float)0.642812, (float)0.503305, (float)0.604441, (float)0.686455, (float)0.646250, (float)0.618148, (float)0.587760, (float)0.670910, (float)0.821051, (float)0.581310, (float)0.661186, (float)0.600928, (float)0.699439, (float)0.548678, (float)0.352786, (float)0.486316, (float)0.788625, (float)0.611432, (float)0.385830, (float)0.669801, (float)0.450744, (float)0.775131, (float)0.501571, (float)0.592511, (float)1.119311, (float)0.703092, (float)0.584707, (float)0.439465, (float)0.634338, (float)0.548005, (float)0.662297, (float)0.709441, (float)0.590768, (float)0.871853, (float)1.121974, (float)0.703923, (float)0.628972, (float)0.496351, (float)0.713743, (float)0.673382, (float)0.428245, (float)0.712878, (float)0.594225, (float)0.796172, (float)0.630016, (float)0.988299, (float)0.634330, (float)0.772596, (float)0.698150, (float)0.692563, (float)0.669203, (float)0.720668, (float)0.451586, (float)0.680505, (float)0.526193, (float)0.474407, (float)0.713929, (float)0.614371};	// L4170
  #pragma HLS resource variable=v3565 core=ram_t2p_bram

  float v3566[128] = {(float)0.150200, (float)0.300916, (float)-0.147537, (float)-0.120987, (float)-0.570131, (float)-0.752484, (float)0.023193, (float)-0.119149, (float)-0.520287, (float)-0.034415, (float)0.152679, (float)-0.800944, (float)-0.213324, (float)-0.195601, (float)-0.450303, (float)-0.263243, (float)0.083857, (float)-1.361400, (float)0.351981, (float)0.043538, (float)-0.512436, (float)-0.448886, (float)0.367435, (float)-0.786505, (float)-0.006069, (float)-0.550220, (float)-0.262887, (float)-0.069671, (float)-0.389200, (float)0.859612, (float)-0.026084, (float)0.019395, (float)-1.482228, (float)0.207719, (float)0.074051, (float)-0.537047, (float)0.634842, (float)0.006638, (float)-0.615627, (float)-0.637323, (float)-0.264894, (float)0.302085, (float)-0.614048, (float)-0.862524, (float)-1.168787, (float)-0.269116, (float)-0.756879, (float)-0.710371, (float)-0.560104, (float)-0.380309, (float)-0.642373, (float)-0.565310, (float)-0.394290, (float)-0.853161, (float)-0.881654, (float)-0.544433, (float)-0.236447, (float)-0.257178, (float)-0.013056, (float)-1.125633, (float)0.237203, (float)-0.226454, (float)-0.168215, (float)-0.745038, (float)-0.863955, (float)0.211796, (float)0.191799, (float)0.505848, (float)0.075484, (float)-0.697482, (float)-0.751843, (float)0.579945, (float)-0.293336, (float)-0.007108, (float)-0.625584, (float)-0.261605, (float)-0.673278, (float)-1.137500, (float)0.119250, (float)-0.498732, (float)-0.646061, (float)-0.057618, (float)0.036118, (float)0.002640, (float)-1.188415, (float)0.290132, (float)-0.797850, (float)-0.288818, (float)0.710557, (float)-0.671836, (float)-0.391351, (float)0.372045, (float)-0.492660, (float)-0.523825, (float)-0.016232, (float)-0.507445, (float)-0.326729, (float)-1.231871, (float)-0.192739, (float)-0.127261, (float)0.323021, (float)-0.015556, (float)-0.131741, (float)-0.609888, (float)-0.017879, (float)-0.300286, (float)-0.124729, (float)0.145174, (float)-0.493696, (float)-0.485238, (float)-0.335667, (float)-0.326114, (float)-0.377579, (float)-0.369098, (float)-0.645815, (float)-0.332252, (float)-0.042399, (float)-0.255116, (float)-0.655701, (float)-0.291660, (float)0.534487, (float)-0.428588, (float)0.158519, (float)-0.354673, (float)-0.126226, (float)-1.052125, (float)-0.249047, (float)-0.291654};	// L4171
  #pragma HLS resource variable=v3566 core=ram_t2p_bram

  float v3567[64] = {(float)-0.177790, (float)-0.128705, (float)0.034879, (float)-0.145190, (float)0.186434, (float)-0.141275, (float)-0.420148, (float)-0.133402, (float)0.218276, (float)-0.191190, (float)0.031088, (float)-0.023462, (float)-0.172444, (float)-0.027425, (float)-0.029478, (float)-0.103149, (float)0.004718, (float)0.082794, (float)-0.152129, (float)0.018295, (float)-0.241826, (float)-0.083148, (float)-0.049059, (float)-0.068803, (float)-0.255967, (float)0.138053, (float)-0.016455, (float)0.209190, (float)-0.002823, (float)-0.026474, (float)-0.022462, (float)0.028627, (float)-0.106532, (float)-0.369825, (float)0.286155, (float)-0.103624, (float)0.308034, (float)-0.089430, (float)0.277215, (float)0.113614, (float)-0.315686, (float)0.042269, (float)0.056672, (float)0.236950, (float)-0.072728, (float)0.046475, (float)-0.053608, (float)0.130854, (float)0.028206, (float)-0.137072, (float)0.146362, (float)-0.071663, (float)-0.323746, (float)-0.158278, (float)-0.042404, (float)-0.127791, (float)-0.170256, (float)0.041290, (float)0.089118, (float)0.077040, (float)-0.072964, (float)0.068284, (float)-0.039060, (float)0.047603};	// L4172
  #pragma HLS resource variable=v3567 core=ram_t2p_bram

  float v3568[64] = {(float)0.255970, (float)0.568951, (float)0.404206, (float)0.512989, (float)0.217755, (float)0.494048, (float)0.331485, (float)0.551048, (float)0.435429, (float)0.529137, (float)0.208072, (float)0.473497, (float)0.594470, (float)0.564473, (float)0.276135, (float)0.257107, (float)0.485284, (float)0.624026, (float)0.436954, (float)0.230790, (float)0.497025, (float)0.315717, (float)0.570591, (float)0.216200, (float)0.193186, (float)0.144774, (float)0.221751, (float)0.238884, (float)0.587139, (float)0.350060, (float)0.410852, (float)0.319929, (float)0.580758, (float)0.328075, (float)0.272313, (float)0.197146, (float)0.613904, (float)0.407504, (float)0.630373, (float)0.387390, (float)0.760535, (float)0.211071, (float)0.307139, (float)0.460326, (float)0.309855, (float)0.191446, (float)0.443134, (float)0.253684, (float)0.574516, (float)0.645867, (float)0.391356, (float)0.308978, (float)0.678156, (float)0.193749, (float)0.581427, (float)0.256959, (float)0.351401, (float)0.212430, (float)0.579397, (float)0.341530, (float)0.205068, (float)0.071525, (float)0.408986, (float)0.441568};	// L4173
  #pragma HLS resource variable=v3568 core=ram_t2p_bram

  float v3569[64] = {(float)0.048466, (float)0.103448, (float)0.066338, (float)0.045807, (float)0.114688, (float)0.053403, (float)0.065437, (float)0.046703, (float)0.044204, (float)0.081993, (float)0.033204, (float)0.040009, (float)0.037901, (float)0.084874, (float)0.040922, (float)0.028237, (float)0.082061, (float)0.069935, (float)0.032657, (float)0.049693, (float)0.050617, (float)0.105976, (float)0.092145, (float)0.030009, (float)0.016958, (float)0.038313, (float)0.035837, (float)0.038259, (float)0.074534, (float)0.057908, (float)0.038953, (float)0.050435, (float)0.049378, (float)0.061704, (float)0.045755, (float)0.034700, (float)0.052544, (float)0.057536, (float)0.047484, (float)0.035390, (float)0.065802, (float)0.033570, (float)0.043730, (float)0.073445, (float)0.057415, (float)0.059629, (float)0.045175, (float)0.040343, (float)0.078903, (float)0.055075, (float)0.032795, (float)0.077450, (float)0.072167, (float)0.039030, (float)0.050137, (float)0.039366, (float)0.045432, (float)0.045014, (float)0.089896, (float)0.029663, (float)0.052693, (float)0.018401, (float)0.052560, (float)0.033971};	// L4174
  #pragma HLS resource variable=v3569 core=ram_t2p_bram

  float v3570[64] = {(float)-0.055500, (float)-0.203719, (float)0.768174, (float)-0.065923, (float)0.474583, (float)-0.046248, (float)-0.089630, (float)0.040515, (float)-0.244641, (float)-0.307899, (float)0.241824, (float)-0.013522, (float)-0.013889, (float)-0.571560, (float)0.163069, (float)-0.123432, (float)-0.060682, (float)-0.068160, (float)0.032566, (float)0.024542, (float)-0.100840, (float)0.064618, (float)0.002764, (float)-0.010114, (float)-0.014506, (float)0.037742, (float)-0.084166, (float)0.018299, (float)-0.505570, (float)-0.052911, (float)-0.057266, (float)-0.121150, (float)-0.357840, (float)-0.247204, (float)-0.340336, (float)0.057016, (float)-0.251170, (float)-0.265774, (float)-0.121009, (float)-0.036924, (float)-0.099599, (float)0.283819, (float)0.147756, (float)-0.110480, (float)-0.459736, (float)-0.186662, (float)-0.285773, (float)0.123724, (float)-0.129131, (float)-0.238919, (float)0.020293, (float)0.108089, (float)-0.230991, (float)-0.084760, (float)-0.031626, (float)0.254551, (float)0.059674, (float)-0.172892, (float)-0.018973, (float)0.189760, (float)0.082253, (float)0.037962, (float)-0.042936, (float)0.139213};	// L4175
  #pragma HLS resource variable=v3570 core=ram_t2p_bram

  float v3571[64] = {(float)-0.099726, (float)-0.475517, (float)-0.047361, (float)-0.269804, (float)-0.083441, (float)-0.007201, (float)0.047423, (float)0.102155, (float)-0.016982, (float)-0.147148, (float)0.230658, (float)0.144664, (float)-0.177520, (float)0.027268, (float)0.155878, (float)-0.183632, (float)0.123778, (float)-0.152205, (float)0.055447, (float)-0.288112, (float)-0.260619, (float)0.231643, (float)-0.324240, (float)-0.021868, (float)-0.264468, (float)0.057604, (float)-0.246467, (float)0.048148, (float)-0.352958, (float)0.094998, (float)-0.186222, (float)-0.170697, (float)-0.016055, (float)-0.260413, (float)-0.314487, (float)-0.108275, (float)0.065943, (float)-0.142717, (float)-0.056989, (float)-0.007582, (float)-0.300593, (float)-0.074393, (float)-0.068269, (float)-0.110389, (float)0.025262, (float)0.048921, (float)-0.251537, (float)0.115038, (float)-0.378323, (float)0.084590, (float)-0.036842, (float)0.143884, (float)-0.046804, (float)-0.308721, (float)-0.024006, (float)0.139675, (float)-0.090794, (float)-0.179469, (float)-0.112889, (float)-0.079252, (float)-0.149069, (float)0.059446, (float)-0.443326, (float)-0.013775};	// L4176
  #pragma HLS resource variable=v3571 core=ram_t2p_bram

  float v3572[64] = {(float)0.391013, (float)0.437474, (float)0.374570, (float)0.398993, (float)0.340426, (float)0.350275, (float)0.261832, (float)0.270686, (float)0.286510, (float)0.430750, (float)0.189464, (float)0.304125, (float)0.383696, (float)0.294356, (float)0.210527, (float)0.330406, (float)0.294271, (float)0.288749, (float)0.205988, (float)0.462650, (float)0.233496, (float)0.183100, (float)0.448870, (float)0.282973, (float)0.338903, (float)0.299658, (float)0.350253, (float)0.273501, (float)0.390755, (float)0.281686, (float)0.263607, (float)0.446234, (float)0.328157, (float)0.377594, (float)0.447084, (float)0.387753, (float)0.251591, (float)0.317194, (float)0.366085, (float)0.316589, (float)0.381759, (float)0.312835, (float)0.227367, (float)0.362716, (float)0.290218, (float)0.238076, (float)0.298752, (float)0.246872, (float)0.383969, (float)0.288621, (float)0.319681, (float)0.287939, (float)0.321752, (float)0.455860, (float)0.350026, (float)0.241983, (float)0.339564, (float)0.351888, (float)0.383881, (float)0.380568, (float)0.403935, (float)0.282568, (float)0.459434, (float)0.334185};	// L4177
  #pragma HLS resource variable=v3572 core=ram_t2p_bram

  float v3573[64] = {(float)0.711093, (float)0.554310, (float)0.614262, (float)0.514770, (float)0.284033, (float)0.492356, (float)0.353583, (float)0.393900, (float)0.251109, (float)0.485877, (float)0.180289, (float)0.746771, (float)0.422531, (float)0.368559, (float)0.171940, (float)0.277702, (float)0.367602, (float)0.231068, (float)0.351484, (float)0.491670, (float)0.139254, (float)0.173218, (float)0.624763, (float)0.303798, (float)0.159914, (float)0.524640, (float)0.240992, (float)0.509616, (float)0.525103, (float)0.536898, (float)0.179995, (float)1.062263, (float)0.400559, (float)0.205999, (float)0.519441, (float)0.498068, (float)0.425001, (float)0.261632, (float)0.825168, (float)0.499086, (float)0.328967, (float)0.364203, (float)0.271639, (float)0.652044, (float)0.449248, (float)0.275283, (float)0.337728, (float)0.316726, (float)0.382971, (float)0.462435, (float)0.409776, (float)0.556643, (float)0.504820, (float)0.474730, (float)0.682017, (float)0.438720, (float)0.350608, (float)0.299549, (float)0.559473, (float)0.685530, (float)0.526043, (float)0.647788, (float)0.495957, (float)0.544854};	// L4178
  #pragma HLS resource variable=v3573 core=ram_t2p_bram

  float v3574[64] = {(float)-0.653447, (float)0.924024, (float)-1.340310, (float)-0.739529, (float)-0.583001, (float)-1.671664, (float)-0.337623, (float)0.191265, (float)-0.456502, (float)-0.787722, (float)-0.375650, (float)-0.229459, (float)-1.700279, (float)-0.613499, (float)0.542234, (float)-0.107217, (float)-0.231535, (float)-0.377473, (float)-1.802572, (float)-0.720974, (float)-0.028771, (float)-1.258514, (float)-1.814399, (float)0.050433, (float)-0.073926, (float)-1.550640, (float)-1.509207, (float)-1.062313, (float)0.170608, (float)0.152729, (float)0.398340, (float)-2.906515, (float)-0.906957, (float)-0.298274, (float)-1.840399, (float)-2.395594, (float)0.224111, (float)-0.075966, (float)-0.952490, (float)-1.463211, (float)0.765657, (float)-0.383212, (float)0.859049, (float)-1.321067, (float)-1.259886, (float)-0.121953, (float)-0.222972, (float)0.507102, (float)1.026229, (float)-0.596883, (float)-0.010449, (float)-1.401284, (float)-0.426694, (float)-0.997893, (float)-1.945835, (float)0.199095, (float)-0.884107, (float)-0.830212, (float)-0.307628, (float)-2.075870, (float)-1.264517, (float)0.267899, (float)0.434910, (float)-1.256771};	// L4179
  #pragma HLS resource variable=v3574 core=ram_t2p_bram

  float v3575[64] = {(float)0.227523, (float)0.008675, (float)-0.067346, (float)-0.068779, (float)0.359775, (float)-0.201667, (float)-0.000048, (float)0.023735, (float)0.395493, (float)0.037079, (float)0.006879, (float)0.275777, (float)-0.070272, (float)-0.239702, (float)-0.081753, (float)-0.094132, (float)-0.145436, (float)0.037301, (float)-0.361739, (float)-0.395614, (float)-0.407890, (float)0.003556, (float)-0.278780, (float)-0.035299, (float)-0.070281, (float)0.210055, (float)-0.004636, (float)-0.196648, (float)-0.280661, (float)-0.016540, (float)0.264518, (float)-0.089359, (float)-0.210460, (float)-0.130261, (float)0.172147, (float)0.053403, (float)-0.222954, (float)-0.048033, (float)0.245716, (float)0.209495, (float)0.162200, (float)0.113698, (float)0.114566, (float)-0.148701, (float)-0.032150, (float)-0.305488, (float)0.491247, (float)0.108730, (float)0.012779, (float)0.100442, (float)0.415533, (float)-0.014710, (float)0.023922, (float)0.099812, (float)-0.172731, (float)0.100782, (float)-0.145636, (float)-0.227354, (float)0.136365, (float)0.201266, (float)-0.057430, (float)0.235302, (float)-0.112987, (float)0.309331};	// L4180
  #pragma HLS resource variable=v3575 core=ram_t2p_bram

  float v3576[64] = {(float)0.249624, (float)0.219779, (float)0.275616, (float)0.607289, (float)0.265406, (float)0.294219, (float)0.113630, (float)0.442462, (float)0.286828, (float)0.297393, (float)0.250593, (float)0.410340, (float)0.485451, (float)0.338272, (float)0.466963, (float)0.177248, (float)0.217085, (float)0.502508, (float)0.226337, (float)0.366660, (float)0.486735, (float)0.458631, (float)0.465238, (float)0.219968, (float)0.151047, (float)0.276148, (float)0.381326, (float)0.280345, (float)0.238178, (float)0.395336, (float)0.303210, (float)0.316327, (float)0.202471, (float)0.232277, (float)0.200276, (float)0.166101, (float)0.468973, (float)0.347641, (float)0.341383, (float)0.227361, (float)0.248534, (float)0.235556, (float)0.272629, (float)0.465665, (float)0.342945, (float)0.246468, (float)0.467435, (float)0.281193, (float)0.624087, (float)0.415187, (float)0.340282, (float)0.421777, (float)0.115192, (float)0.298459, (float)0.580225, (float)0.279544, (float)0.470572, (float)0.451711, (float)0.430281, (float)0.274865, (float)0.342688, (float)0.113665, (float)0.506885, (float)0.437001};	// L4181
  #pragma HLS resource variable=v3576 core=ram_t2p_bram

  float v3577[64] = {(float)0.112977, (float)0.041237, (float)0.033545, (float)0.128228, (float)0.208378, (float)0.030685, (float)0.060566, (float)0.073705, (float)0.031310, (float)0.040856, (float)0.137575, (float)0.039873, (float)0.043669, (float)0.028224, (float)0.158828, (float)0.028779, (float)0.083656, (float)0.079875, (float)0.017730, (float)0.183914, (float)0.088387, (float)0.305412, (float)0.151206, (float)0.039352, (float)0.037352, (float)0.096941, (float)0.171872, (float)0.061037, (float)0.060672, (float)0.156014, (float)0.044767, (float)0.123553, (float)0.046391, (float)0.100531, (float)0.049753, (float)0.048147, (float)0.045006, (float)0.122899, (float)0.062314, (float)0.038063, (float)0.022906, (float)0.122661, (float)0.165624, (float)0.104651, (float)0.131607, (float)0.183358, (float)0.062244, (float)0.127234, (float)0.192906, (float)0.041888, (float)0.026284, (float)0.262289, (float)0.071197, (float)0.144237, (float)0.093709, (float)0.098259, (float)0.116282, (float)0.151095, (float)0.100875, (float)0.034225, (float)0.185439, (float)0.069805, (float)0.063052, (float)0.034959};	// L4182
  #pragma HLS resource variable=v3577 core=ram_t2p_bram

  float v3578[64] = {(float)0.167667, (float)0.005160, (float)0.786813, (float)0.166958, (float)0.477449, (float)-0.036223, (float)-0.057831, (float)0.002011, (float)-0.342021, (float)0.067421, (float)-0.097042, (float)-0.099979, (float)-0.065909, (float)-0.038458, (float)-0.070890, (float)-0.221758, (float)-0.134342, (float)0.119792, (float)-0.060160, (float)0.000618, (float)0.086362, (float)-0.146616, (float)0.035369, (float)-0.153914, (float)-0.041574, (float)-0.431713, (float)0.032966, (float)-0.079720, (float)-0.586836, (float)-0.246140, (float)-0.150488, (float)-0.401244, (float)-0.218739, (float)-0.635121, (float)0.069792, (float)0.141156, (float)0.275380, (float)-0.564455, (float)-0.111346, (float)-0.241368, (float)-0.131315, (float)-0.021504, (float)0.126393, (float)-0.168429, (float)0.169258, (float)-0.468406, (float)-0.690758, (float)0.204412, (float)0.001475, (float)-0.054254, (float)-0.148674, (float)0.126161, (float)-0.114532, (float)-0.159674, (float)0.122987, (float)-0.160528, (float)-0.225617, (float)-0.099545, (float)-0.162096, (float)0.322956, (float)-0.005539, (float)0.109110, (float)0.078114, (float)0.012128};	// L4183
  #pragma HLS resource variable=v3578 core=ram_t2p_bram

  float v3579[64] = {(float)0.165661, (float)0.241959, (float)0.177965, (float)-0.043138, (float)-0.205331, (float)0.159751, (float)0.292936, (float)0.091178, (float)0.111647, (float)0.088373, (float)0.110414, (float)-0.203524, (float)0.153929, (float)0.085720, (float)-0.109398, (float)0.065450, (float)0.076595, (float)-0.206687, (float)-0.021186, (float)0.139637, (float)0.040125, (float)-0.282750, (float)-0.325706, (float)-0.003466, (float)-0.437301, (float)-0.124845, (float)0.128243, (float)-0.087393, (float)0.119922, (float)-0.082930, (float)-0.531535, (float)-0.078031, (float)-0.387627, (float)-0.054656, (float)-0.181555, (float)-0.188850, (float)0.132012, (float)0.003135, (float)-0.269714, (float)-0.298390, (float)0.139352, (float)0.259657, (float)0.137245, (float)0.005264, (float)0.013150, (float)0.329456, (float)-0.271507, (float)-0.018674, (float)-0.246698, (float)0.157942, (float)0.016460, (float)-0.089049, (float)-0.190278, (float)-0.078674, (float)0.170013, (float)-0.483183, (float)0.061921, (float)-0.067710, (float)0.312465, (float)-0.506396, (float)0.313813, (float)-0.261735, (float)-0.154493, (float)0.006281};	// L4184
  #pragma HLS resource variable=v3579 core=ram_t2p_bram

  float v3580[64] = {(float)0.309043, (float)0.214711, (float)0.236577, (float)0.425931, (float)0.513686, (float)0.218109, (float)0.220441, (float)0.229953, (float)0.264006, (float)0.269451, (float)0.213778, (float)0.460191, (float)0.266088, (float)0.231898, (float)0.390032, (float)0.238855, (float)0.266045, (float)0.363448, (float)0.347413, (float)0.247701, (float)0.328453, (float)0.534935, (float)0.644020, (float)0.227494, (float)0.448181, (float)0.307817, (float)0.260412, (float)0.465068, (float)0.217946, (float)0.285815, (float)0.342562, (float)0.441997, (float)0.444977, (float)0.450019, (float)0.551551, (float)0.509207, (float)0.256445, (float)0.263419, (float)0.566351, (float)0.640956, (float)0.222757, (float)0.198602, (float)0.245954, (float)0.224201, (float)0.214311, (float)0.198216, (float)0.636766, (float)0.310555, (float)0.504928, (float)0.240275, (float)0.306494, (float)0.375986, (float)0.379381, (float)0.428064, (float)0.299082, (float)0.332632, (float)0.259647, (float)0.334533, (float)0.200566, (float)0.435056, (float)0.168260, (float)0.514938, (float)0.262883, (float)0.325370};	// L4185
  #pragma HLS resource variable=v3580 core=ram_t2p_bram

  float v3581[64] = {(float)0.435055, (float)0.204354, (float)0.234371, (float)0.555869, (float)0.962581, (float)0.348372, (float)0.087091, (float)0.685126, (float)0.471447, (float)1.264185, (float)0.151851, (float)0.672974, (float)0.242971, (float)0.557664, (float)0.870111, (float)0.241860, (float)0.205246, (float)0.814858, (float)0.304025, (float)0.261729, (float)0.805968, (float)0.800655, (float)1.558104, (float)0.240397, (float)0.444483, (float)0.676497, (float)0.556174, (float)0.937784, (float)0.258369, (float)0.317293, (float)0.096178, (float)0.411816, (float)0.519685, (float)0.976714, (float)1.270331, (float)0.890841, (float)0.360924, (float)0.222713, (float)1.158769, (float)1.596519, (float)0.406011, (float)0.255919, (float)0.176324, (float)0.279655, (float)0.375710, (float)0.128194, (float)1.827967, (float)0.314452, (float)0.741928, (float)0.212855, (float)0.812225, (float)0.466000, (float)0.406509, (float)0.491435, (float)0.481395, (float)0.169688, (float)0.400027, (float)0.386658, (float)0.149924, (float)0.413703, (float)0.067106, (float)0.830320, (float)0.243440, (float)0.344939};	// L4186
  #pragma HLS resource variable=v3581 core=ram_t2p_bram

  float v3582[64] = {(float)-0.433190, (float)-0.175695, (float)0.030747, (float)-0.705807, (float)-1.636446, (float)-0.798920, (float)-0.067817, (float)-0.195550, (float)-1.126039, (float)-0.957785, (float)0.003038, (float)-1.826511, (float)-0.039339, (float)-0.867986, (float)-1.106184, (float)-0.635920, (float)-0.987194, (float)-0.577787, (float)-1.334917, (float)-0.340781, (float)-1.198194, (float)-1.605752, (float)-2.170181, (float)-0.881360, (float)-0.817468, (float)-0.695106, (float)0.654208, (float)-1.642239, (float)0.281131, (float)0.316297, (float)-0.412330, (float)-1.402285, (float)-1.504384, (float)-2.503079, (float)-2.158050, (float)-1.364501, (float)-0.857909, (float)-0.220596, (float)-2.554775, (float)-2.269485, (float)-0.160925, (float)-0.855172, (float)0.528861, (float)1.349205, (float)-0.938154, (float)-0.335566, (float)-2.916777, (float)-1.596725, (float)-1.887467, (float)-1.616621, (float)-1.944322, (float)-2.019488, (float)-0.967085, (float)-1.388074, (float)-1.883634, (float)0.186852, (float)-1.348731, (float)-0.459333, (float)-0.454171, (float)-0.903211, (float)-0.076797, (float)-1.771877, (float)1.248418, (float)-0.913858};	// L4187
  #pragma HLS resource variable=v3582 core=ram_t2p_bram

  float v3583[64] = {(float)0.230717, (float)0.253822, (float)-0.000001, (float)-0.664389, (float)-0.000000, (float)0.161522, (float)0.454504, (float)-0.000000, (float)0.300514, (float)-0.000008, (float)0.349418, (float)0.311481, (float)-0.249530, (float)-0.000035, (float)0.107726, (float)0.218971, (float)0.381413, (float)-0.529882, (float)-0.628644, (float)0.571398, (float)0.299847, (float)0.584304, (float)0.482022, (float)0.328526, (float)0.196717, (float)0.194962, (float)0.152145, (float)0.085522, (float)0.513143, (float)0.015237, (float)0.166442, (float)0.332394, (float)0.249211, (float)0.443367, (float)-0.280169, (float)-0.020385, (float)-0.000000, (float)0.321341, (float)-0.000000, (float)0.237767, (float)0.232908, (float)0.315275, (float)0.427762, (float)0.293128, (float)0.263794, (float)0.675976, (float)0.429100, (float)0.345663, (float)-0.000000, (float)0.247294, (float)0.303161, (float)0.615773, (float)0.398349, (float)0.332067, (float)-0.412188, (float)0.378069, (float)0.178953, (float)0.257478, (float)-0.449080, (float)0.213059, (float)0.569339, (float)0.572743, (float)-0.402383, (float)0.234064};	// L4188
  #pragma HLS resource variable=v3583 core=ram_t2p_bram

  float v3584[64] = {(float)0.234873, (float)0.266258, (float)-0.000000, (float)0.518700, (float)0.000000, (float)0.222385, (float)0.422887, (float)0.000000, (float)0.250932, (float)0.000002, (float)0.316872, (float)0.250492, (float)0.378926, (float)0.000011, (float)0.275264, (float)0.236741, (float)0.242022, (float)0.395315, (float)0.469346, (float)0.290896, (float)0.272684, (float)0.278028, (float)0.290692, (float)0.206927, (float)0.258990, (float)0.278711, (float)0.291150, (float)0.316014, (float)0.388891, (float)0.304112, (float)0.267757, (float)0.210925, (float)0.287084, (float)0.332426, (float)0.426728, (float)0.373261, (float)0.000000, (float)0.190678, (float)0.000000, (float)0.223030, (float)0.179079, (float)0.248601, (float)0.273995, (float)0.259229, (float)0.294202, (float)0.299236, (float)0.223689, (float)0.262799, (float)0.000000, (float)0.266098, (float)0.220890, (float)0.284286, (float)0.330723, (float)0.226810, (float)0.365381, (float)0.212299, (float)0.239653, (float)0.249496, (float)0.525831, (float)0.248248, (float)0.295653, (float)0.258777, (float)0.483256, (float)0.266704};	// L4189
  #pragma HLS resource variable=v3584 core=ram_t2p_bram

  float v3585[64] = {(float)1.016945, (float)3.716743, (float)0.000000, (float)3.282543, (float)0.000000, (float)0.658227, (float)4.370062, (float)0.000000, (float)0.915523, (float)0.000000, (float)4.125586, (float)2.743992, (float)2.839091, (float)0.000000, (float)11.072271, (float)0.500746, (float)2.231282, (float)4.825707, (float)2.698614, (float)9.369955, (float)3.733917, (float)5.484296, (float)5.712669, (float)0.445445, (float)0.436275, (float)7.156336, (float)13.717909, (float)5.251175, (float)6.817375, (float)1.672358, (float)1.653430, (float)1.232460, (float)4.907629, (float)3.073051, (float)4.238386, (float)4.993635, (float)0.000000, (float)1.521162, (float)0.000000, (float)0.351344, (float)0.170247, (float)1.420545, (float)1.908483, (float)2.151240, (float)2.660849, (float)4.844434, (float)1.929712, (float)1.499944, (float)0.000000, (float)1.530640, (float)0.365027, (float)2.937554, (float)5.466412, (float)0.707925, (float)3.331507, (float)0.771803, (float)2.406784, (float)6.521367, (float)4.126250, (float)1.050635, (float)2.953032, (float)11.365622, (float)4.769047, (float)1.655878};	// L4190
  #pragma HLS resource variable=v3585 core=ram_t2p_bram

  float v3586[64] = {(float)0.002768, (float)-0.025769, (float)0.000000, (float)-0.084605, (float)0.000000, (float)0.000497, (float)-0.022408, (float)-0.000000, (float)-0.004824, (float)0.000000, (float)0.039582, (float)0.031994, (float)-0.037490, (float)-0.000001, (float)0.006600, (float)0.004378, (float)0.064797, (float)0.111760, (float)0.036002, (float)-0.075075, (float)-0.038240, (float)0.084358, (float)-0.052287, (float)-0.011799, (float)0.001302, (float)0.032172, (float)-0.017784, (float)-0.091009, (float)0.113187, (float)-0.041632, (float)0.008730, (float)0.029693, (float)-0.070502, (float)-0.003485, (float)0.109771, (float)-0.001734, (float)-0.000000, (float)0.029330, (float)-0.000000, (float)0.006732, (float)-0.003710, (float)0.016028, (float)-0.027883, (float)0.026593, (float)0.028475, (float)-0.127347, (float)0.044617, (float)0.026329, (float)0.000000, (float)-0.017045, (float)-0.003562, (float)-0.045841, (float)0.063876, (float)0.015220, (float)-0.038511, (float)-0.016428, (float)-0.016569, (float)0.056057, (float)-0.080306, (float)-0.002665, (float)-0.041718, (float)0.126113, (float)-0.049237, (float)-0.013261};	// L4191
  #pragma HLS resource variable=v3586 core=ram_t2p_bram

  forward_node218(v3240, v3219, v3243, v3242);	// L4192
  forward_node214(v3244, v3586, v3583, v3584, v3585, v3245);	// L4193
  forward_node209(v3246, v3248, v3247);	// L4194
  forward_node202(v3239, v3249, v3251, v3258, v3257);	// L4195
  forward_node198(v3581, v3582, v3259, v3579, v3580, v3260);	// L4196
  forward_node191(v3261, v3252, v3238, v3263, v3262);	// L4197
  forward_node186(v3577, v3578, v3575, v3576, v3250, v3264, v3265);	// L4198
  forward_node179(v3266, v3237, v3253, v3269, v3268);	// L4199
  forward_node175(v3571, v3572, v3270, v3574, v3573, v3271);	// L4200
  forward_node169(v3272, v3236, v3255, v3254);	// L4201
  forward_node164(v3267, v3570, v3568, v3567, v3569, v3256, v3273);	// L4202
  forward_node157(v3274, v3276, v3235, v3284, v3283);	// L4203
  forward_node153(v3566, v3563, v3565, v3285, v3564, v3286);	// L4204
  forward_node146(v3287, v3277, v3234, v3289, v3288);	// L4205
  forward_node139(v3275, v3233, v3278, v3292, v3291);	// L4206
  forward_node134(v3293, v3561, v3559, v3290, v3558, v3560, v3562, v3556, v3557, v3294);	// L4207
  forward_node127(v3232, v3279, v3295, v3298, v3297);	// L4208
  forward_node123(v3555, v3299, v3552, v3553, v3554, v3300);	// L4209
  forward_node117(v3301, v3231, v3281, v3280);	// L4210
  forward_node112(v3548, v3282, v3551, v3549, v3296, v3550, v3302);	// L4211
  forward_node105(v3305, v3230, v3303, v3313, v3312);	// L4212
  forward_node101(v3547, v3545, v3544, v3546, v3314, v3315);	// L4213
  forward_node94(v3306, v3229, v3316, v3318, v3317);	// L4214
  forward_node87(v3307, v3304, v3228, v3321, v3320);	// L4215
  forward_node82(v3322, v3539, v3543, v3542, v3538, v3319, v3537, v3541, v3540, v3323);	// L4216
  forward_node75(v3308, v3324, v3227, v3327, v3326);	// L4217
  forward_node71(v3533, v3534, v3536, v3535, v3328, v3329);	// L4218
  forward_node65(v3226, v3330, v3310, v3309);	// L4219
  forward_node60(v3532, v3311, v3529, v3325, v3530, v3531, v3331);	// L4220
  forward_node53(v3332, v3334, v3225, v3342, v3341);	// L4221
  forward_node49(v3527, v3528, v3343, v3525, v3526, v3344);	// L4222
  forward_node42(v3345, v3224, v3335, v3347, v3346);	// L4223
  forward_node35(v3333, v3223, v3336, v3350, v3349);	// L4224
  forward_node30(v3519, v3351, v3521, v3522, v3348, v3518, v3520, v3524, v3523, v3352);	// L4225
  forward_node23(v3222, v3353, v3337, v3356, v3355);	// L4226
  forward_node19(v3514, v3516, v3357, v3515, v3517, v3358);	// L4227
  forward_node13(v3359, v3221, v3339, v3338);	// L4228
  forward_node8(v3512, v3354, v3511, v3510, v3340, v3513, v3360);	// L4229
  float v3587[512][4][4];	// L4230
  #pragma HLS resource variable=v3587 core=ram_t2p_bram

  for (int v3588 = 0; v3588 < 64; v3588 += 1) {	// L4231
    for (int v3589 = 0; v3589 < 2; v3589 += 1) {	// L4232
      for (int v3590 = 0; v3590 < 2; v3590 += 1) {	// L4233
        for (int v3591 = 0; v3591 < 8; v3591 += 1) {	// L4234
          for (int v3592 = 0; v3592 < 2; v3592 += 1) {	// L4235
            for (int v3593 = 0; v3593 < 2; v3593 += 1) {	// L4236
              #pragma HLS pipeline II=1
              float v3594 = v3361[(v3591 + (v3588 * 8))][(v3592 + (v3589 * 2))][(v3593 + (v3590 * 2))];	// L4237
              v3587[(v3591 + (v3588 * 8))][(v3592 + (v3589 * 2))][(v3593 + (v3590 * 2))] = v3594;	// L4238
            }
          }
        }
      }
    }
  }
  float v3595[512];	// L4245
  #pragma HLS resource variable=v3595 core=ram_t2p_bram

  float v3596;	// L4246
  forward_node5(v3362, v3596, v3595);	// L4247
  float v3597[512];	// L4248
  #pragma HLS resource variable=v3597 core=ram_t2p_bram

  forward_node4(v3596, v3595, v3597);	// L4249
  forward_node0(v3509, v3241, v3597, v3220);	// L4250
  for (int v3598 = 0; v3598 < 512; v3598 += 1) {	// L4251
    for (int v3599 = 0; v3599 < 4; v3599 += 1) {	// L4252
      for (int v3600 = 0; v3600 < 4; v3600 += 1) {	// L4253
        #pragma HLS pipeline II=1
        float v3601 = v3587[v3598][v3599][v3600];	// L4254
        v3363[v3598][v3599][v3600] = v3601;	// L4255
      }
    }
  }
}

