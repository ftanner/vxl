/* Version 1.0 generated April 7, 1997 by Greg Ward Larson, SGI */
#define UV_SQSIZ   0.003500
#define UV_NDIVS   16289
#define UV_VSTART  0.016940
#define UV_NVS     163
static struct {
        float   ustart;
        short   nus, ncum;
}       uv_row[UV_NVS] = {
        0.247663, 4,   0,
        0.243779, 6,   4,
        0.241684, 7,   10,
        0.237874, 9,   17,
        0.235906, 10,  26,
        0.232153, 12,  36,
        0.228352, 14,  48,
        0.226259, 15,  62,
        0.222371, 17,  77,
        0.220410, 18,  94,
        0.214710, 21,  112,
        0.212714, 22,  133,
        0.210721, 23,  155,
        0.204976, 26,  178,
        0.202986, 27,  204,
        0.199245, 29,  231,
        0.195525, 31,  260,
        0.193560, 32,  291,
        0.189878, 34,  323,
        0.186216, 36,  357,
        0.186216, 36,  393,
        0.182592, 38,  429,
        0.179003, 40,  467,
        0.175466, 42,  507,
        0.172001, 44,  549,
        0.172001, 44,  593,
        0.168612, 46,  637,
        0.168612, 46,  683,
        0.163575, 49,  729,
        0.158642, 52,  778,
        0.158642, 52,  830,
        0.158642, 52,  882,
        0.153815, 55,  934,
        0.153815, 55,  989,
        0.149097, 58,  1044,
        0.149097, 58,  1102,
        0.142746, 62,  1160,
        0.142746, 62,  1222,
        0.142746, 62,  1284,
        0.138270, 65,  1346,
        0.138270, 65,  1411,
        0.138270, 65,  1476,
        0.132166, 69,  1541,
        0.132166, 69,  1610,
        0.126204, 73,  1679,
        0.126204, 73,  1752,
        0.126204, 73,  1825,
        0.120381, 77,  1898,
        0.120381, 77,  1975,
        0.120381, 77,  2052,
        0.120381, 77,  2129,
        0.112962, 82,  2206,
        0.112962, 82,  2288,
        0.112962, 82,  2370,
        0.107450, 86,  2452,
        0.107450, 86,  2538,
        0.107450, 86,  2624,
        0.107450, 86,  2710,
        0.100343, 91,  2796,
        0.100343, 91,  2887,
        0.100343, 91,  2978,
        0.095126, 95,  3069,
        0.095126, 95,  3164,
        0.095126, 95,  3259,
        0.095126, 95,  3354,
        0.088276, 100, 3449,
        0.088276, 100, 3549,
        0.088276, 100, 3649,
        0.088276, 100, 3749,
        0.081523, 105, 3849,
        0.081523, 105, 3954,
        0.081523, 105, 4059,
        0.081523, 105, 4164,
        0.074861, 110, 4269,
        0.074861, 110, 4379,
        0.074861, 110, 4489,
        0.074861, 110, 4599,
        0.068290, 115, 4709,
        0.068290, 115, 4824,
        0.068290, 115, 4939,
        0.068290, 115, 5054,
        0.063573, 119, 5169,
        0.063573, 119, 5288,
        0.063573, 119, 5407,
        0.063573, 119, 5526,
        0.057219, 124, 5645,
        0.057219, 124, 5769,
        0.057219, 124, 5893,
        0.057219, 124, 6017,
        0.050985, 129, 6141,
        0.050985, 129, 6270,
        0.050985, 129, 6399,
        0.050985, 129, 6528,
        0.050985, 129, 6657,
        0.044859, 134, 6786,
        0.044859, 134, 6920,
        0.044859, 134, 7054,
        0.044859, 134, 7188,
        0.040571, 138, 7322,
        0.040571, 138, 7460,
        0.040571, 138, 7598,
        0.040571, 138, 7736,
        0.036339, 142, 7874,
        0.036339, 142, 8016,
        0.036339, 142, 8158,
        0.036339, 142, 8300,
        0.032139, 146, 8442,
        0.032139, 146, 8588,
        0.032139, 146, 8734,
        0.032139, 146, 8880,
        0.027947, 150, 9026,
        0.027947, 150, 9176,
        0.027947, 150, 9326,
        0.023739, 154, 9476,
        0.023739, 154, 9630,
        0.023739, 154, 9784,
        0.023739, 154, 9938,
        0.019504, 158, 10092,
        0.019504, 158, 10250,
        0.019504, 158, 10408,
        0.016976, 161, 10566,
        0.016976, 161, 10727,
        0.016976, 161, 10888,
        0.016976, 161, 11049,
        0.012639, 165, 11210,
        0.012639, 165, 11375,
        0.012639, 165, 11540,
        0.009991, 168, 11705,
        0.009991, 168, 11873,
        0.009991, 168, 12041,
        0.009016, 170, 12209,
        0.009016, 170, 12379,
        0.009016, 170, 12549,
        0.006217, 173, 12719,
        0.006217, 173, 12892,
        0.005097, 175, 13065,
        0.005097, 175, 13240,
        0.005097, 175, 13415,
        0.003909, 177, 13590,
        0.003909, 177, 13767,
        0.002340, 177, 13944,
        0.002389, 170, 14121,
        0.001068, 164, 14291,
        0.001653, 157, 14455,
        0.000717, 150, 14612,
        0.001614, 143, 14762,
        0.000270, 136, 14905,
        0.000484, 129, 15041,
        0.001103, 123, 15170,
        0.001242, 115, 15293,
        0.001188, 109, 15408,
        0.001011, 103, 15517,
        0.000709, 97,  15620,
        0.000301, 89,  15717,
        0.002416, 82,  15806,
        0.003251, 76,  15888,
        0.003246, 69,  15964,
        0.004141, 62,  16033,
        0.005963, 55,  16095,
        0.008839, 47,  16150,
        0.010490, 40,  16197,
        0.016994, 31,  16237,
        0.023659, 21,  16268,
};
