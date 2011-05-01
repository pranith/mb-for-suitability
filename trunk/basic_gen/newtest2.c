#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

long *src;
long result;

void recordTime(struct timeval* current)
{
  gettimeofday(current, NULL);

  return;
}

float diffTime(struct timeval before, struct timeval after)
{
  float time_sec = ((after.tv_sec - before.tv_sec) + ((after.tv_usec - before.tv_usec) / 1000000.0));

  return time_sec;
}

int main()
{
  unsigned long size = 256 * 1024 * 1024 / sizeof(long); // 256 MB
  src = (long *)malloc(sizeof(long) * size);
  unsigned long i = 0, j, k = 0, l;
  volatile long dest;
  volatile long \
    dest0,\
    dest1,\
    dest2,\
    dest3,\
    dest4,\
    dest5,\
    dest6,\
    dest7,\
    dest8,\
    dest9,\
    dest10,\
    dest11,\
    dest12,\
    dest13,\
    dest14,\
    dest15,\
    dest16,\
    dest17,\
    dest18,\
    dest19,\
    dest20,\
    dest21,\
    dest22,\
    dest23,\
    dest24,\
    dest25,\
    dest26,\
    dest27,\
    dest28,\
    dest29,\
    dest30,\
    dest31,\
    dest32,\
    dest33,\
    dest34,\
    dest35,\
    dest36,\
    dest37,\
    dest38,\
    dest39,\
    dest40,\
    dest41,\
    dest42,\
    dest43,\
    dest44,\
    dest45,\
    dest46,\
    dest47,\
    dest48,\
    dest49,\
    dest50,\
    dest51,\
    dest52,\
    dest53,\
    dest54,\
    dest55,\
    dest56,\
    dest57,\
    dest58,\
    dest59,\
    dest60,\
    dest61,\
    dest62,\
    dest63,\
    dest64,\
    dest65,\
    dest66,\
    dest67,\
    dest68,\
    dest69,\
    dest70,\
    dest71,\
    dest72,\
    dest73,\
    dest74,\
    dest75,\
    dest76,\
    dest77,\
    dest78,\
    dest79,\
    dest80,\
    dest81,\
    dest82,\
    dest83,\
    dest84,\
    dest85,\
    dest86,\
    dest87,\
    dest88,\
    dest89,\
    dest90,\
    dest91,\
    dest92,\
    dest93,\
    dest94,\
    dest95,\
    dest96,\
    dest97,\
    dest98,\
    dest99,\
    dest100,\
    dest101,\
    dest102,\
    dest103,\
    dest104,\
    dest105,\
    dest106,\
    dest107,\
    dest108,\
    dest109,\
    dest110,\
    dest111,\
    dest112,\
    dest113,\
    dest114,\
    dest115,\
    dest116,\
    dest117,\
    dest118,\
    dest119,\
    dest120,\
    dest121,\
    dest122,\
    dest123,\
    dest124,\
    dest125,\
    dest126,\
    dest127,\
    dest128,\
    dest129,\
    dest130,\
    dest131,\
    dest132,\
    dest133,\
    dest134,\
    dest135,\
    dest136,\
    dest137,\
    dest138,\
    dest139,\
    dest140,\
    dest141,\
    dest142,\
    dest143,\
    dest144,\
    dest145,\
    dest146,\
    dest147,\
    dest148,\
    dest149,\
    dest150,\
    dest151,\
    dest152,\
    dest153,\
    dest154,\
    dest155,\
    dest156,\
    dest157,\
    dest158,\
    dest159,\
    dest160,\
    dest161,\
    dest162,\
    dest163,\
    dest164,\
    dest165,\
    dest166,\
    dest167,\
    dest168,\
    dest169,\
    dest170,\
    dest171,\
    dest172,\
    dest173,\
    dest174,\
    dest175,\
    dest176,\
    dest177,\
    dest178,\
    dest179,\
    dest180,\
    dest181,\
    dest182,\
    dest183,\
    dest184,\
    dest185,\
    dest186,\
    dest187,\
    dest188,\
    dest189,\
    dest190,\
    dest191,\
    dest192,\
    dest193,\
    dest194,\
    dest195,\
    dest196,\
    dest197,\
    dest198,\
    dest199,\
    dest200,\
    dest201,\
    dest202,\
    dest203,\
    dest204,\
    dest205,\
    dest206,\
    dest207,\
    dest208,\
    dest209,\
    dest210,\
    dest211,\
    dest212,\
    dest213,\
    dest214,\
    dest215,\
    dest216,\
    dest217,\
    dest218,\
    dest219,\
    dest220,\
    dest221,\
    dest222,\
    dest223,\
    dest224,\
    dest225,\
    dest226,\
    dest227,\
    dest228,\
    dest229,\
    dest230,\
    dest231,\
    dest232,\
    dest233,\
    dest234,\
    dest235,\
    dest236,\
    dest237,\
    dest238,\
    dest239,\
    dest240,\
    dest241,\
    dest242,\
    dest243,\
    dest244,\
    dest245,\
    dest246,\
    dest247,\
    dest248,\
    dest249,\
    dest250,\
    dest251,\
    dest252,\
    dest253,\
    dest254,\
    dest255,\
    dest256,\
    dest257,\
    dest258,\
    dest259,\
    dest260,\
    dest261,\
    dest262,\
    dest263,\
    dest264,\
    dest265,\
    dest266,\
    dest267,\
    dest268,\
    dest269,\
    dest270,\
    dest271,\
    dest272,\
    dest273,\
    dest274,\
    dest275,\
    dest276,\
    dest277,\
    dest278,\
    dest279,\
    dest280,\
    dest281,\
    dest282,\
    dest283,\
    dest284,\
    dest285,\
    dest286,\
    dest287,\
    dest288,\
    dest289,\
    dest290,\
    dest291,\
    dest292,\
    dest293,\
    dest294,\
    dest295,\
    dest296,\
    dest297,\
    dest298,\
    dest299,\
    dest300,\
    dest301,\
    dest302,\
    dest303,\
    dest304,\
    dest305,\
    dest306,\
    dest307,\
    dest308,\
    dest309,\
    dest310,\
    dest311,\
    dest312,\
    dest313,\
    dest314,\
    dest315,\
    dest316,\
    dest317,\
    dest318,\
    dest319,\
    dest320,\
    dest321,\
    dest322,\
    dest323,\
    dest324,\
    dest325,\
    dest326,\
    dest327,\
    dest328,\
    dest329,\
    dest330,\
    dest331,\
    dest332,\
    dest333,\
    dest334,\
    dest335,\
    dest336,\
    dest337,\
    dest338,\
    dest339,\
    dest340,\
    dest341,\
    dest342,\
    dest343,\
    dest344,\
    dest345,\
    dest346,\
    dest347,\
    dest348,\
    dest349,\
    dest350,\
    dest351,\
    dest352,\
    dest353,\
    dest354,\
    dest355,\
    dest356,\
    dest357,\
    dest358,\
    dest359,\
    dest360,\
    dest361,\
    dest362,\
    dest363,\
    dest364,\
    dest365,\
    dest366,\
    dest367,\
    dest368,\
    dest369,\
    dest370,\
    dest371,\
    dest372,\
    dest373,\
    dest374,\
    dest375,\
    dest376,\
    dest377,\
    dest378,\
    dest379,\
    dest380,\
    dest381,\
    dest382,\
    dest383,\
    dest384,\
    dest385,\
    dest386,\
    dest387,\
    dest388,\
    dest389,\
    dest390,\
    dest391,\
    dest392,\
    dest393,\
    dest394,\
    dest395,\
    dest396,\
    dest397,\
    dest398,\
    dest399; 
  int num_mem_ops = 400;

  unsigned long num_iter = 5000000000 / num_mem_ops;
  struct timeval before, after;

  //initialize array
  for (j = 0; j < size; j++)
    src[j] = 1;

  int inc = 1;
  int max = inc * 400;
  int num_req = 0;
  int final = 0;
  /*
   * to generate 'n' requests we use the formula src[i + (8 * num_req * iteration)/400]
   *
   * this will generate 'n' requests over the entire iteration
   */
  for (num_req = 0; num_req < 400; num_req++)
  {
    fprintf(stderr, "trying for num_req %d\n", num_req);
    recordTime(&before);
    for(j = 0; j < num_iter; j++)
    {
      dest0 += src[i + ((num_req * 0) / 50)];
      dest1 += src[i + ((num_req * 1) / 50)];
      dest2 += src[i + ((num_req * 2) / 50)];
      dest3 += src[i + ((num_req * 3) / 50)];
      dest4 += src[i + ((num_req * 4) / 50)];
      dest5 += src[i + ((num_req * 5) / 50)];
      dest6 += src[i + ((num_req * 6) / 50)];
      dest7 += src[i + ((num_req * 7) / 50)];
      dest8 += src[i + ((num_req * 8) / 50)];
      dest9 += src[i + ((num_req * 9) / 50)];
      dest10 += src[i + ((num_req * 10) / 50)];
      dest11 += src[i + ((num_req * 11) / 50)];
      dest12 += src[i + ((num_req * 12) / 50)];
      dest13 += src[i + ((num_req * 13) / 50)];
      dest14 += src[i + ((num_req * 14) / 50)];
      dest15 += src[i + ((num_req * 15) / 50)];
      dest16 += src[i + ((num_req * 16) / 50)];
      dest17 += src[i + ((num_req * 17) / 50)];
      dest18 += src[i + ((num_req * 18) / 50)];
      dest19 += src[i + ((num_req * 19) / 50)];
      dest20 += src[i + ((num_req * 20) / 50)];
      dest21 += src[i + ((num_req * 21) / 50)];
      dest22 += src[i + ((num_req * 22) / 50)];
      dest23 += src[i + ((num_req * 23) / 50)];
      dest24 += src[i + ((num_req * 24) / 50)];
      dest25 += src[i + ((num_req * 25) / 50)];
      dest26 += src[i + ((num_req * 26) / 50)];
      dest27 += src[i + ((num_req * 27) / 50)];
      dest28 += src[i + ((num_req * 28) / 50)];
      dest29 += src[i + ((num_req * 29) / 50)];
      dest30 += src[i + ((num_req * 30) / 50)];
      dest31 += src[i + ((num_req * 31) / 50)];
      dest32 += src[i + ((num_req * 32) / 50)];
      dest33 += src[i + ((num_req * 33) / 50)];
      dest34 += src[i + ((num_req * 34) / 50)];
      dest35 += src[i + ((num_req * 35) / 50)];
      dest36 += src[i + ((num_req * 36) / 50)];
      dest37 += src[i + ((num_req * 37) / 50)];
      dest38 += src[i + ((num_req * 38) / 50)];
      dest39 += src[i + ((num_req * 39) / 50)];
      dest40 += src[i + ((num_req * 40) / 50)];
      dest41 += src[i + ((num_req * 41) / 50)];
      dest42 += src[i + ((num_req * 42) / 50)];
      dest43 += src[i + ((num_req * 43) / 50)];
      dest44 += src[i + ((num_req * 44) / 50)];
      dest45 += src[i + ((num_req * 45) / 50)];
      dest46 += src[i + ((num_req * 46) / 50)];
      dest47 += src[i + ((num_req * 47) / 50)];
      dest48 += src[i + ((num_req * 48) / 50)];
      dest49 += src[i + ((num_req * 49) / 50)];
      dest50 += src[i + ((num_req * 50) / 50)];
      dest51 += src[i + ((num_req * 51) / 50)];
      dest52 += src[i + ((num_req * 52) / 50)];
      dest53 += src[i + ((num_req * 53) / 50)];
      dest54 += src[i + ((num_req * 54) / 50)];
      dest55 += src[i + ((num_req * 55) / 50)];
      dest56 += src[i + ((num_req * 56) / 50)];
      dest57 += src[i + ((num_req * 57) / 50)];
      dest58 += src[i + ((num_req * 58) / 50)];
      dest59 += src[i + ((num_req * 59) / 50)];
      dest60 += src[i + ((num_req * 60) / 50)];
      dest61 += src[i + ((num_req * 61) / 50)];
      dest62 += src[i + ((num_req * 62) / 50)];
      dest63 += src[i + ((num_req * 63) / 50)];
      dest64 += src[i + ((num_req * 64) / 50)];
      dest65 += src[i + ((num_req * 65) / 50)];
      dest66 += src[i + ((num_req * 66) / 50)];
      dest67 += src[i + ((num_req * 67) / 50)];
      dest68 += src[i + ((num_req * 68) / 50)];
      dest69 += src[i + ((num_req * 69) / 50)];
      dest70 += src[i + ((num_req * 70) / 50)];
      dest71 += src[i + ((num_req * 71) / 50)];
      dest72 += src[i + ((num_req * 72) / 50)];
      dest73 += src[i + ((num_req * 73) / 50)];
      dest74 += src[i + ((num_req * 74) / 50)];
      dest75 += src[i + ((num_req * 75) / 50)];
      dest76 += src[i + ((num_req * 76) / 50)];
      dest77 += src[i + ((num_req * 77) / 50)];
      dest78 += src[i + ((num_req * 78) / 50)];
      dest79 += src[i + ((num_req * 79) / 50)];
      dest80 += src[i + ((num_req * 80) / 50)];
      dest81 += src[i + ((num_req * 81) / 50)];
      dest82 += src[i + ((num_req * 82) / 50)];
      dest83 += src[i + ((num_req * 83) / 50)];
      dest84 += src[i + ((num_req * 84) / 50)];
      dest85 += src[i + ((num_req * 85) / 50)];
      dest86 += src[i + ((num_req * 86) / 50)];
      dest87 += src[i + ((num_req * 87) / 50)];
      dest88 += src[i + ((num_req * 88) / 50)];
      dest89 += src[i + ((num_req * 89) / 50)];
      dest90 += src[i + ((num_req * 90) / 50)];
      dest91 += src[i + ((num_req * 91) / 50)];
      dest92 += src[i + ((num_req * 92) / 50)];
      dest93 += src[i + ((num_req * 93) / 50)];
      dest94 += src[i + ((num_req * 94) / 50)];
      dest95 += src[i + ((num_req * 95) / 50)];
      dest96 += src[i + ((num_req * 96) / 50)];
      dest97 += src[i + ((num_req * 97) / 50)];
      dest98 += src[i + ((num_req * 98) / 50)];
      dest99 += src[i + ((num_req * 99) / 50)];
      dest100 += src[i + ((num_req * 100) / 50)];
      dest101 += src[i + ((num_req * 101) / 50)];
      dest102 += src[i + ((num_req * 102) / 50)];
      dest103 += src[i + ((num_req * 103) / 50)];
      dest104 += src[i + ((num_req * 104) / 50)];
      dest105 += src[i + ((num_req * 105) / 50)];
      dest106 += src[i + ((num_req * 106) / 50)];
      dest107 += src[i + ((num_req * 107) / 50)];
      dest108 += src[i + ((num_req * 108) / 50)];
      dest109 += src[i + ((num_req * 109) / 50)];
      dest110 += src[i + ((num_req * 110) / 50)];
      dest111 += src[i + ((num_req * 111) / 50)];
      dest112 += src[i + ((num_req * 112) / 50)];
      dest113 += src[i + ((num_req * 113) / 50)];
      dest114 += src[i + ((num_req * 114) / 50)];
      dest115 += src[i + ((num_req * 115) / 50)];
      dest116 += src[i + ((num_req * 116) / 50)];
      dest117 += src[i + ((num_req * 117) / 50)];
      dest118 += src[i + ((num_req * 118) / 50)];
      dest119 += src[i + ((num_req * 119) / 50)];
      dest120 += src[i + ((num_req * 120) / 50)];
      dest121 += src[i + ((num_req * 121) / 50)];
      dest122 += src[i + ((num_req * 122) / 50)];
      dest123 += src[i + ((num_req * 123) / 50)];
      dest124 += src[i + ((num_req * 124) / 50)];
      dest125 += src[i + ((num_req * 125) / 50)];
      dest126 += src[i + ((num_req * 126) / 50)];
      dest127 += src[i + ((num_req * 127) / 50)];
      dest128 += src[i + ((num_req * 128) / 50)];
      dest129 += src[i + ((num_req * 129) / 50)];
      dest130 += src[i + ((num_req * 130) / 50)];
      dest131 += src[i + ((num_req * 131) / 50)];
      dest132 += src[i + ((num_req * 132) / 50)];
      dest133 += src[i + ((num_req * 133) / 50)];
      dest134 += src[i + ((num_req * 134) / 50)];
      dest135 += src[i + ((num_req * 135) / 50)];
      dest136 += src[i + ((num_req * 136) / 50)];
      dest137 += src[i + ((num_req * 137) / 50)];
      dest138 += src[i + ((num_req * 138) / 50)];
      dest139 += src[i + ((num_req * 139) / 50)];
      dest140 += src[i + ((num_req * 140) / 50)];
      dest141 += src[i + ((num_req * 141) / 50)];
      dest142 += src[i + ((num_req * 142) / 50)];
      dest143 += src[i + ((num_req * 143) / 50)];
      dest144 += src[i + ((num_req * 144) / 50)];
      dest145 += src[i + ((num_req * 145) / 50)];
      dest146 += src[i + ((num_req * 146) / 50)];
      dest147 += src[i + ((num_req * 147) / 50)];
      dest148 += src[i + ((num_req * 148) / 50)];
      dest149 += src[i + ((num_req * 149) / 50)];
      dest150 += src[i + ((num_req * 150) / 50)];
      dest151 += src[i + ((num_req * 151) / 50)];
      dest152 += src[i + ((num_req * 152) / 50)];
      dest153 += src[i + ((num_req * 153) / 50)];
      dest154 += src[i + ((num_req * 154) / 50)];
      dest155 += src[i + ((num_req * 155) / 50)];
      dest156 += src[i + ((num_req * 156) / 50)];
      dest157 += src[i + ((num_req * 157) / 50)];
      dest158 += src[i + ((num_req * 158) / 50)];
      dest159 += src[i + ((num_req * 159) / 50)];
      dest160 += src[i + ((num_req * 160) / 50)];
      dest161 += src[i + ((num_req * 161) / 50)];
      dest162 += src[i + ((num_req * 162) / 50)];
      dest163 += src[i + ((num_req * 163) / 50)];
      dest164 += src[i + ((num_req * 164) / 50)];
      dest165 += src[i + ((num_req * 165) / 50)];
      dest166 += src[i + ((num_req * 166) / 50)];
      dest167 += src[i + ((num_req * 167) / 50)];
      dest168 += src[i + ((num_req * 168) / 50)];
      dest169 += src[i + ((num_req * 169) / 50)];
      dest170 += src[i + ((num_req * 170) / 50)];
      dest171 += src[i + ((num_req * 171) / 50)];
      dest172 += src[i + ((num_req * 172) / 50)];
      dest173 += src[i + ((num_req * 173) / 50)];
      dest174 += src[i + ((num_req * 174) / 50)];
      dest175 += src[i + ((num_req * 175) / 50)];
      dest176 += src[i + ((num_req * 176) / 50)];
      dest177 += src[i + ((num_req * 177) / 50)];
      dest178 += src[i + ((num_req * 178) / 50)];
      dest179 += src[i + ((num_req * 179) / 50)];
      dest180 += src[i + ((num_req * 180) / 50)];
      dest181 += src[i + ((num_req * 181) / 50)];
      dest182 += src[i + ((num_req * 182) / 50)];
      dest183 += src[i + ((num_req * 183) / 50)];
      dest184 += src[i + ((num_req * 184) / 50)];
      dest185 += src[i + ((num_req * 185) / 50)];
      dest186 += src[i + ((num_req * 186) / 50)];
      dest187 += src[i + ((num_req * 187) / 50)];
      dest188 += src[i + ((num_req * 188) / 50)];
      dest189 += src[i + ((num_req * 189) / 50)];
      dest190 += src[i + ((num_req * 190) / 50)];
      dest191 += src[i + ((num_req * 191) / 50)];
      dest192 += src[i + ((num_req * 192) / 50)];
      dest193 += src[i + ((num_req * 193) / 50)];
      dest194 += src[i + ((num_req * 194) / 50)];
      dest195 += src[i + ((num_req * 195) / 50)];
      dest196 += src[i + ((num_req * 196) / 50)];
      dest197 += src[i + ((num_req * 197) / 50)];
      dest198 += src[i + ((num_req * 198) / 50)];
      dest199 += src[i + ((num_req * 199) / 50)];
      dest200 += src[i + ((num_req * 200) / 50)];
      dest201 += src[i + ((num_req * 201) / 50)];
      dest202 += src[i + ((num_req * 202) / 50)];
      dest203 += src[i + ((num_req * 203) / 50)];
      dest204 += src[i + ((num_req * 204) / 50)];
      dest205 += src[i + ((num_req * 205) / 50)];
      dest206 += src[i + ((num_req * 206) / 50)];
      dest207 += src[i + ((num_req * 207) / 50)];
      dest208 += src[i + ((num_req * 208) / 50)];
      dest209 += src[i + ((num_req * 209) / 50)];
      dest210 += src[i + ((num_req * 210) / 50)];
      dest211 += src[i + ((num_req * 211) / 50)];
      dest212 += src[i + ((num_req * 212) / 50)];
      dest213 += src[i + ((num_req * 213) / 50)];
      dest214 += src[i + ((num_req * 214) / 50)];
      dest215 += src[i + ((num_req * 215) / 50)];
      dest216 += src[i + ((num_req * 216) / 50)];
      dest217 += src[i + ((num_req * 217) / 50)];
      dest218 += src[i + ((num_req * 218) / 50)];
      dest219 += src[i + ((num_req * 219) / 50)];
      dest220 += src[i + ((num_req * 220) / 50)];
      dest221 += src[i + ((num_req * 221) / 50)];
      dest222 += src[i + ((num_req * 222) / 50)];
      dest223 += src[i + ((num_req * 223) / 50)];
      dest224 += src[i + ((num_req * 224) / 50)];
      dest225 += src[i + ((num_req * 225) / 50)];
      dest226 += src[i + ((num_req * 226) / 50)];
      dest227 += src[i + ((num_req * 227) / 50)];
      dest228 += src[i + ((num_req * 228) / 50)];
      dest229 += src[i + ((num_req * 229) / 50)];
      dest230 += src[i + ((num_req * 230) / 50)];
      dest231 += src[i + ((num_req * 231) / 50)];
      dest232 += src[i + ((num_req * 232) / 50)];
      dest233 += src[i + ((num_req * 233) / 50)];
      dest234 += src[i + ((num_req * 234) / 50)];
      dest235 += src[i + ((num_req * 235) / 50)];
      dest236 += src[i + ((num_req * 236) / 50)];
      dest237 += src[i + ((num_req * 237) / 50)];
      dest238 += src[i + ((num_req * 238) / 50)];
      dest239 += src[i + ((num_req * 239) / 50)];
      dest240 += src[i + ((num_req * 240) / 50)];
      dest241 += src[i + ((num_req * 241) / 50)];
      dest242 += src[i + ((num_req * 242) / 50)];
      dest243 += src[i + ((num_req * 243) / 50)];
      dest244 += src[i + ((num_req * 244) / 50)];
      dest245 += src[i + ((num_req * 245) / 50)];
      dest246 += src[i + ((num_req * 246) / 50)];
      dest247 += src[i + ((num_req * 247) / 50)];
      dest248 += src[i + ((num_req * 248) / 50)];
      dest249 += src[i + ((num_req * 249) / 50)];
      dest250 += src[i + ((num_req * 250) / 50)];
      dest251 += src[i + ((num_req * 251) / 50)];
      dest252 += src[i + ((num_req * 252) / 50)];
      dest253 += src[i + ((num_req * 253) / 50)];
      dest254 += src[i + ((num_req * 254) / 50)];
      dest255 += src[i + ((num_req * 255) / 50)];
      dest256 += src[i + ((num_req * 256) / 50)];
      dest257 += src[i + ((num_req * 257) / 50)];
      dest258 += src[i + ((num_req * 258) / 50)];
      dest259 += src[i + ((num_req * 259) / 50)];
      dest260 += src[i + ((num_req * 260) / 50)];
      dest261 += src[i + ((num_req * 261) / 50)];
      dest262 += src[i + ((num_req * 262) / 50)];
      dest263 += src[i + ((num_req * 263) / 50)];
      dest264 += src[i + ((num_req * 264) / 50)];
      dest265 += src[i + ((num_req * 265) / 50)];
      dest266 += src[i + ((num_req * 266) / 50)];
      dest267 += src[i + ((num_req * 267) / 50)];
      dest268 += src[i + ((num_req * 268) / 50)];
      dest269 += src[i + ((num_req * 269) / 50)];
      dest270 += src[i + ((num_req * 270) / 50)];
      dest271 += src[i + ((num_req * 271) / 50)];
      dest272 += src[i + ((num_req * 272) / 50)];
      dest273 += src[i + ((num_req * 273) / 50)];
      dest274 += src[i + ((num_req * 274) / 50)];
      dest275 += src[i + ((num_req * 275) / 50)];
      dest276 += src[i + ((num_req * 276) / 50)];
      dest277 += src[i + ((num_req * 277) / 50)];
      dest278 += src[i + ((num_req * 278) / 50)];
      dest279 += src[i + ((num_req * 279) / 50)];
      dest280 += src[i + ((num_req * 280) / 50)];
      dest281 += src[i + ((num_req * 281) / 50)];
      dest282 += src[i + ((num_req * 282) / 50)];
      dest283 += src[i + ((num_req * 283) / 50)];
      dest284 += src[i + ((num_req * 284) / 50)];
      dest285 += src[i + ((num_req * 285) / 50)];
      dest286 += src[i + ((num_req * 286) / 50)];
      dest287 += src[i + ((num_req * 287) / 50)];
      dest288 += src[i + ((num_req * 288) / 50)];
      dest289 += src[i + ((num_req * 289) / 50)];
      dest290 += src[i + ((num_req * 290) / 50)];
      dest291 += src[i + ((num_req * 291) / 50)];
      dest292 += src[i + ((num_req * 292) / 50)];
      dest293 += src[i + ((num_req * 293) / 50)];
      dest294 += src[i + ((num_req * 294) / 50)];
      dest295 += src[i + ((num_req * 295) / 50)];
      dest296 += src[i + ((num_req * 296) / 50)];
      dest297 += src[i + ((num_req * 297) / 50)];
      dest298 += src[i + ((num_req * 298) / 50)];
      dest299 += src[i + ((num_req * 299) / 50)];
      dest300 += src[i + ((num_req * 300) / 50)];
      dest301 += src[i + ((num_req * 301) / 50)];
      dest302 += src[i + ((num_req * 302) / 50)];
      dest303 += src[i + ((num_req * 303) / 50)];
      dest304 += src[i + ((num_req * 304) / 50)];
      dest305 += src[i + ((num_req * 305) / 50)];
      dest306 += src[i + ((num_req * 306) / 50)];
      dest307 += src[i + ((num_req * 307) / 50)];
      dest308 += src[i + ((num_req * 308) / 50)];
      dest309 += src[i + ((num_req * 309) / 50)];
      dest310 += src[i + ((num_req * 310) / 50)];
      dest311 += src[i + ((num_req * 311) / 50)];
      dest312 += src[i + ((num_req * 312) / 50)];
      dest313 += src[i + ((num_req * 313) / 50)];
      dest314 += src[i + ((num_req * 314) / 50)];
      dest315 += src[i + ((num_req * 315) / 50)];
      dest316 += src[i + ((num_req * 316) / 50)];
      dest317 += src[i + ((num_req * 317) / 50)];
      dest318 += src[i + ((num_req * 318) / 50)];
      dest319 += src[i + ((num_req * 319) / 50)];
      dest320 += src[i + ((num_req * 320) / 50)];
      dest321 += src[i + ((num_req * 321) / 50)];
      dest322 += src[i + ((num_req * 322) / 50)];
      dest323 += src[i + ((num_req * 323) / 50)];
      dest324 += src[i + ((num_req * 324) / 50)];
      dest325 += src[i + ((num_req * 325) / 50)];
      dest326 += src[i + ((num_req * 326) / 50)];
      dest327 += src[i + ((num_req * 327) / 50)];
      dest328 += src[i + ((num_req * 328) / 50)];
      dest329 += src[i + ((num_req * 329) / 50)];
      dest330 += src[i + ((num_req * 330) / 50)];
      dest331 += src[i + ((num_req * 331) / 50)];
      dest332 += src[i + ((num_req * 332) / 50)];
      dest333 += src[i + ((num_req * 333) / 50)];
      dest334 += src[i + ((num_req * 334) / 50)];
      dest335 += src[i + ((num_req * 335) / 50)];
      dest336 += src[i + ((num_req * 336) / 50)];
      dest337 += src[i + ((num_req * 337) / 50)];
      dest338 += src[i + ((num_req * 338) / 50)];
      dest339 += src[i + ((num_req * 339) / 50)];
      dest340 += src[i + ((num_req * 340) / 50)];
      dest341 += src[i + ((num_req * 341) / 50)];
      dest342 += src[i + ((num_req * 342) / 50)];
      dest343 += src[i + ((num_req * 343) / 50)];
      dest344 += src[i + ((num_req * 344) / 50)];
      dest345 += src[i + ((num_req * 345) / 50)];
      dest346 += src[i + ((num_req * 346) / 50)];
      dest347 += src[i + ((num_req * 347) / 50)];
      dest348 += src[i + ((num_req * 348) / 50)];
      dest349 += src[i + ((num_req * 349) / 50)];
      dest350 += src[i + ((num_req * 350) / 50)];
      dest351 += src[i + ((num_req * 351) / 50)];
      dest352 += src[i + ((num_req * 352) / 50)];
      dest353 += src[i + ((num_req * 353) / 50)];
      dest354 += src[i + ((num_req * 354) / 50)];
      dest355 += src[i + ((num_req * 355) / 50)];
      dest356 += src[i + ((num_req * 356) / 50)];
      dest357 += src[i + ((num_req * 357) / 50)];
      dest358 += src[i + ((num_req * 358) / 50)];
      dest359 += src[i + ((num_req * 359) / 50)];
      dest360 += src[i + ((num_req * 360) / 50)];
      dest361 += src[i + ((num_req * 361) / 50)];
      dest362 += src[i + ((num_req * 362) / 50)];
      dest363 += src[i + ((num_req * 363) / 50)];
      dest364 += src[i + ((num_req * 364) / 50)];
      dest365 += src[i + ((num_req * 365) / 50)];
      dest366 += src[i + ((num_req * 366) / 50)];
      dest367 += src[i + ((num_req * 367) / 50)];
      dest368 += src[i + ((num_req * 368) / 50)];
      dest369 += src[i + ((num_req * 369) / 50)];
      dest370 += src[i + ((num_req * 370) / 50)];
      dest371 += src[i + ((num_req * 371) / 50)];
      dest372 += src[i + ((num_req * 372) / 50)];
      dest373 += src[i + ((num_req * 373) / 50)];
      dest374 += src[i + ((num_req * 374) / 50)];
      dest375 += src[i + ((num_req * 375) / 50)];
      dest376 += src[i + ((num_req * 376) / 50)];
      dest377 += src[i + ((num_req * 377) / 50)];
      dest378 += src[i + ((num_req * 378) / 50)];
      dest379 += src[i + ((num_req * 379) / 50)];
      dest380 += src[i + ((num_req * 380) / 50)];
      dest381 += src[i + ((num_req * 381) / 50)];
      dest382 += src[i + ((num_req * 382) / 50)];
      dest383 += src[i + ((num_req * 383) / 50)];
      dest384 += src[i + ((num_req * 384) / 50)];
      dest385 += src[i + ((num_req * 385) / 50)];
      dest386 += src[i + ((num_req * 386) / 50)];
      dest387 += src[i + ((num_req * 387) / 50)];
      dest388 += src[i + ((num_req * 388) / 50)];
      dest389 += src[i + ((num_req * 389) / 50)];
      dest390 += src[i + ((num_req * 390) / 50)];
      dest391 += src[i + ((num_req * 391) / 50)];
      dest392 += src[i + ((num_req * 392) / 50)];
      dest393 += src[i + ((num_req * 393) / 50)];
      dest394 += src[i + ((num_req * 394) / 50)];
      dest395 += src[i + ((num_req * 395) / 50)];
      dest396 += src[i + ((num_req * 396) / 50)];
      dest397 += src[i + ((num_req * 397) / 50)];
      dest398 += src[i + ((num_req * 398) / 50)];
      dest399 += src[i + ((num_req * 399) / 50)];
      i += (8 * num_req);

      if (i + (num_req * 399)/50 >= size)
        i = 0;
      final = 1 \
        + dest0\
        + dest1\
        + dest2\
        + dest3\
        + dest4\
        + dest5\
        + dest6\
        + dest7\
        + dest8\
        + dest9\
        + dest10\
        + dest11\
        + dest12\
        + dest13\
        + dest14\
        + dest15\
        + dest16\
        + dest17\
        + dest18\
        + dest19\
        + dest20\
        + dest21\
        + dest22\
        + dest23\
        + dest24\
        + dest25\
        + dest26\
        + dest27\
        + dest28\
        + dest29\
        + dest30\
        + dest31\
        + dest32\
        + dest33\
        + dest34\
        + dest35\
        + dest36\
        + dest37\
        + dest38\
        + dest39\
        + dest40\
        + dest41\
        + dest42\
        + dest43\
        + dest44\
        + dest45\
        + dest46\
        + dest47\
        + dest48\
        + dest49\
        + dest50\
        + dest51\
        + dest52\
        + dest53\
        + dest54\
        + dest55\
        + dest56\
        + dest57\
        + dest58\
        + dest59\
        + dest60\
        + dest61\
        + dest62\
        + dest63\
        + dest64\
        + dest65\
        + dest66\
        + dest67\
        + dest68\
        + dest69\
        + dest70\
        + dest71\
        + dest72\
        + dest73\
        + dest74\
        + dest75\
        + dest76\
        + dest77\
        + dest78\
        + dest79\
        + dest80\
        + dest81\
        + dest82\
        + dest83\
        + dest84\
        + dest85\
        + dest86\
        + dest87\
        + dest88\
        + dest89\
        + dest90\
        + dest91\
        + dest92\
        + dest93\
        + dest94\
        + dest95\
        + dest96\
        + dest97\
        + dest98\
        + dest99\
        + dest100\
        + dest101\
        + dest102\
        + dest103\
        + dest104\
        + dest105\
        + dest106\
        + dest107\
        + dest108\
        + dest109\
        + dest110\
        + dest111\
        + dest112\
        + dest113\
        + dest114\
        + dest115\
        + dest116\
        + dest117\
        + dest118\
        + dest119\
        + dest120\
        + dest121\
        + dest122\
        + dest123\
        + dest124\
        + dest125\
        + dest126\
        + dest127\
        + dest128\
        + dest129\
        + dest130\
        + dest131\
        + dest132\
        + dest133\
        + dest134\
        + dest135\
        + dest136\
        + dest137\
        + dest138\
        + dest139\
        + dest140\
        + dest141\
        + dest142\
        + dest143\
        + dest144\
        + dest145\
        + dest146\
        + dest147\
        + dest148\
        + dest149\
        + dest150\
        + dest151\
        + dest152\
        + dest153\
        + dest154\
        + dest155\
        + dest156\
        + dest157\
        + dest158\
        + dest159\
        + dest160\
        + dest161\
        + dest162\
        + dest163\
        + dest164\
        + dest165\
        + dest166\
        + dest167\
        + dest168\
        + dest169\
        + dest170\
        + dest171\
        + dest172\
        + dest173\
        + dest174\
        + dest175\
        + dest176\
        + dest177\
        + dest178\
        + dest179\
        + dest180\
        + dest181\
        + dest182\
        + dest183\
        + dest184\
        + dest185\
        + dest186\
        + dest187\
        + dest188\
        + dest189\
        + dest190\
        + dest191\
        + dest192\
        + dest193\
        + dest194\
        + dest195\
        + dest196\
        + dest197\
        + dest198\
        + dest199\
        + dest200\
        + dest201\
        + dest202\
        + dest203\
        + dest204\
        + dest205\
        + dest206\
        + dest207\
        + dest208\
        + dest209\
        + dest210\
        + dest211\
        + dest212\
        + dest213\
        + dest214\
        + dest215\
        + dest216\
        + dest217\
        + dest218\
        + dest219\
        + dest220\
        + dest221\
        + dest222\
        + dest223\
        + dest224\
        + dest225\
        + dest226\
        + dest227\
        + dest228\
        + dest229\
        + dest230\
        + dest231\
        + dest232\
        + dest233\
        + dest234\
        + dest235\
        + dest236\
        + dest237\
        + dest238\
        + dest239\
        + dest240\
        + dest241\
        + dest242\
        + dest243\
        + dest244\
        + dest245\
        + dest246\
        + dest247\
        + dest248\
        + dest249\
        + dest250\
        + dest251\
        + dest252\
        + dest253\
        + dest254\
        + dest255\
        + dest256\
        + dest257\
        + dest258\
        + dest259\
        + dest260\
        + dest261\
        + dest262\
        + dest263\
        + dest264\
        + dest265\
        + dest266\
        + dest267\
        + dest268\
        + dest269\
        + dest270\
        + dest271\
        + dest272\
        + dest273\
        + dest274\
        + dest275\
        + dest276\
        + dest277\
        + dest278\
        + dest279\
        + dest280\
        + dest281\
        + dest282\
        + dest283\
        + dest284\
        + dest285\
        + dest286\
        + dest287\
        + dest288\
        + dest289\
        + dest290\
        + dest291\
        + dest292\
        + dest293\
        + dest294\
        + dest295\
        + dest296\
        + dest297\
        + dest298\
        + dest299\
        + dest300\
        + dest301\
        + dest302\
        + dest303\
        + dest304\
        + dest305\
        + dest306\
        + dest307\
        + dest308\
        + dest309\
        + dest310\
        + dest311\
        + dest312\
        + dest313\
        + dest314\
        + dest315\
        + dest316\
        + dest317\
        + dest318\
        + dest319\
        + dest320\
        + dest321\
        + dest322\
        + dest323\
        + dest324\
        + dest325\
        + dest326\
        + dest327\
        + dest328\
        + dest329\
        + dest330\
        + dest331\
        + dest332\
        + dest333\
        + dest334\
        + dest335\
        + dest336\
        + dest337\
        + dest338\
        + dest339\
        + dest340\
        + dest341\
        + dest342\
        + dest343\
        + dest344\
        + dest345\
        + dest346\
        + dest347\
        + dest348\
        + dest349\
        + dest350\
        + dest351\
        + dest352\
        + dest353\
        + dest354\
        + dest355\
        + dest356\
        + dest357\
        + dest358\
        + dest359\
        + dest360\
        + dest361\
        + dest362\
        + dest363\
        + dest364\
        + dest365\
        + dest366\
        + dest367\
        + dest368\
        + dest369\
        + dest370\
        + dest371\
        + dest372\
        + dest373\
        + dest374\
        + dest375\
        + dest376\
        + dest377\
        + dest378\
        + dest379\
        + dest380\
        + dest381\
        + dest382\
        + dest383\
        + dest384\
        + dest385\
        + dest386\
        + dest387\
        + dest388\
        + dest389\
        + dest390\
        + dest391\
        + dest392\
        + dest393\
        + dest394\
        + dest395\
        + dest396\
        + dest397\
        + dest398\
        + dest399; 
    }
    recordTime(&after);
    printf("%d %f\n", num_req, diffTime(before, after));
    fprintf(stderr, "%d %f\n", num_req, diffTime(before, after));
  }

  result = final;

  return 0;
}
