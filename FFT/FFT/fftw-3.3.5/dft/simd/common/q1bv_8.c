/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Sat Jul 30 16:45:30 EDT 2016 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_twidsq_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -n 8 -dif -name q1bv_8 -include q1b.h -sign 1 */

/*
 * This function contains 264 FP additions, 192 FP multiplications,
 * (or, 184 additions, 112 multiplications, 80 fused multiply/add),
 * 121 stack variables, 1 constants, and 128 memory accesses
 */
#include "q1b.h"

static void q1bv_8(R *ri, R *ii, const R *W, stride rs, stride vs, INT mb, INT me, INT ms)
{
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT m;
	  R *x;
	  x = ii;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 14)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 14), MAKE_VOLATILE_STRIDE(16, rs), MAKE_VOLATILE_STRIDE(16, vs)) {
	       V T42, T43, T1U, T1V, T2Y, T2Z, TT, TS, T45, T44;
	       {
		    V T3, Te, T1E, T1P, Tv, Tp, T26, T20, T2b, T2m, T3M, T2x, T2D, T3X, TA;
		    V TL, T48, T4e, T17, T12, TW, T1i, T2I, T1z, T1t, T2T, T3f, T3q, T34, T3a;
		    V T3H, T3B, Ts, Tw, Tf, Ta, T23, T27, T1Q, T1L, T2A, T2E, T2n, T2i, T4b;
		    V T4f, T3Y, T3T, TZ, T13, TM, TH, T35, T2L, T3j, T1w, T1A, T1j, T1e, T36;
		    V T2O, T3C, T3i, T3k;
		    {
			 V T3d, T32, T3e, T3o, T3p, T33;
			 {
			      V T2v, T2w, T3V, T46, T3W;
			      {
				   V T1, T2, Tc, Td, T1C, T1D, T1N, T1O;
				   T1 = LD(&(x[0]), ms, &(x[0]));
				   T2 = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
				   Tc = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
				   Td = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
				   T1C = LD(&(x[WS(vs, 3)]), ms, &(x[WS(vs, 3)]));
				   T1D = LD(&(x[WS(vs, 3) + WS(rs, 4)]), ms, &(x[WS(vs, 3)]));
				   T1N = LD(&(x[WS(vs, 3) + WS(rs, 2)]), ms, &(x[WS(vs, 3)]));
				   T1O = LD(&(x[WS(vs, 3) + WS(rs, 6)]), ms, &(x[WS(vs, 3)]));
				   {
					V T29, T1Y, T1Z, T2a, T2k, T2l, Tn, To, T3K, T3L;
					T29 = LD(&(x[WS(vs, 4)]), ms, &(x[WS(vs, 4)]));
					T3 = VSUB(T1, T2);
					Tn = VADD(T1, T2);
					Te = VSUB(Tc, Td);
					To = VADD(Tc, Td);
					T1E = VSUB(T1C, T1D);
					T1Y = VADD(T1C, T1D);
					T1P = VSUB(T1N, T1O);
					T1Z = VADD(T1N, T1O);
					T2a = LD(&(x[WS(vs, 4) + WS(rs, 4)]), ms, &(x[WS(vs, 4)]));
					T2k = LD(&(x[WS(vs, 4) + WS(rs, 2)]), ms, &(x[WS(vs, 4)]));
					T2l = LD(&(x[WS(vs, 4) + WS(rs, 6)]), ms, &(x[WS(vs, 4)]));
					Tv = VADD(Tn, To);
					Tp = VSUB(Tn, To);
					T3K = LD(&(x[WS(vs, 7)]), ms, &(x[WS(vs, 7)]));
					T3L = LD(&(x[WS(vs, 7) + WS(rs, 4)]), ms, &(x[WS(vs, 7)]));
					T26 = VADD(T1Y, T1Z);
					T20 = VSUB(T1Y, T1Z);
					T2v = VADD(T29, T2a);
					T2b = VSUB(T29, T2a);
					T2w = VADD(T2k, T2l);
					T2m = VSUB(T2k, T2l);
					T3V = LD(&(x[WS(vs, 7) + WS(rs, 2)]), ms, &(x[WS(vs, 7)]));
					T46 = VADD(T3K, T3L);
					T3M = VSUB(T3K, T3L);
					T3W = LD(&(x[WS(vs, 7) + WS(rs, 6)]), ms, &(x[WS(vs, 7)]));
				   }
			      }
			      {
				   V T15, TU, T16, T1g, TV, T1h;
				   {
					V Ty, Tz, TJ, TK, T47;
					Ty = LD(&(x[WS(vs, 1)]), ms, &(x[WS(vs, 1)]));
					Tz = LD(&(x[WS(vs, 1) + WS(rs, 4)]), ms, &(x[WS(vs, 1)]));
					TJ = LD(&(x[WS(vs, 1) + WS(rs, 2)]), ms, &(x[WS(vs, 1)]));
					T2x = VSUB(T2v, T2w);
					T2D = VADD(T2v, T2w);
					TK = LD(&(x[WS(vs, 1) + WS(rs, 6)]), ms, &(x[WS(vs, 1)]));
					T47 = VADD(T3V, T3W);
					T3X = VSUB(T3V, T3W);
					T15 = LD(&(x[WS(vs, 2)]), ms, &(x[WS(vs, 2)]));
					TA = VSUB(Ty, Tz);
					TU = VADD(Ty, Tz);
					T16 = LD(&(x[WS(vs, 2) + WS(rs, 4)]), ms, &(x[WS(vs, 2)]));
					T1g = LD(&(x[WS(vs, 2) + WS(rs, 2)]), ms, &(x[WS(vs, 2)]));
					TL = VSUB(TJ, TK);
					TV = VADD(TJ, TK);
					T48 = VSUB(T46, T47);
					T4e = VADD(T46, T47);
					T1h = LD(&(x[WS(vs, 2) + WS(rs, 6)]), ms, &(x[WS(vs, 2)]));
				   }
				   {
					V T2G, T1r, T2H, T2R, T1s, T2S;
					T2G = LD(&(x[WS(vs, 5)]), ms, &(x[WS(vs, 5)]));
					T17 = VSUB(T15, T16);
					T1r = VADD(T15, T16);
					T2H = LD(&(x[WS(vs, 5) + WS(rs, 4)]), ms, &(x[WS(vs, 5)]));
					T12 = VADD(TU, TV);
					TW = VSUB(TU, TV);
					T2R = LD(&(x[WS(vs, 5) + WS(rs, 2)]), ms, &(x[WS(vs, 5)]));
					T1i = VSUB(T1g, T1h);
					T1s = VADD(T1g, T1h);
					T2S = LD(&(x[WS(vs, 5) + WS(rs, 6)]), ms, &(x[WS(vs, 5)]));
					T3d = LD(&(x[WS(vs, 6)]), ms, &(x[WS(vs, 6)]));
					T2I = VSUB(T2G, T2H);
					T32 = VADD(T2G, T2H);
					T3e = LD(&(x[WS(vs, 6) + WS(rs, 4)]), ms, &(x[WS(vs, 6)]));
					T3o = LD(&(x[WS(vs, 6) + WS(rs, 2)]), ms, &(x[WS(vs, 6)]));
					T3p = LD(&(x[WS(vs, 6) + WS(rs, 6)]), ms, &(x[WS(vs, 6)]));
					T1z = VADD(T1r, T1s);
					T1t = VSUB(T1r, T1s);
					T33 = VADD(T2R, T2S);
					T2T = VSUB(T2R, T2S);
				   }
			      }
			 }
			 {
			      V T2y, T2e, T3Q, T2z, T2h, T49, T3P, T3R;
			      {
				   V T6, Tq, T1I, Tr, T9, T21, T1H, T1J;
				   {
					V T4, T3z, T3A, T5, T7, T8, T1F, T1G;
					T4 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
					T3f = VSUB(T3d, T3e);
					T3z = VADD(T3d, T3e);
					T3q = VSUB(T3o, T3p);
					T3A = VADD(T3o, T3p);
					T5 = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
					T7 = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
					T34 = VSUB(T32, T33);
					T3a = VADD(T32, T33);
					T8 = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
					T1F = LD(&(x[WS(vs, 3) + WS(rs, 1)]), ms, &(x[WS(vs, 3) + WS(rs, 1)]));
					T1G = LD(&(x[WS(vs, 3) + WS(rs, 5)]), ms, &(x[WS(vs, 3) + WS(rs, 1)]));
					T3H = VADD(T3z, T3A);
					T3B = VSUB(T3z, T3A);
					T6 = VSUB(T4, T5);
					Tq = VADD(T4, T5);
					T1I = LD(&(x[WS(vs, 3) + WS(rs, 7)]), ms, &(x[WS(vs, 3) + WS(rs, 1)]));
					Tr = VADD(T7, T8);
					T9 = VSUB(T7, T8);
					T21 = VADD(T1F, T1G);
					T1H = VSUB(T1F, T1G);
					T1J = LD(&(x[WS(vs, 3) + WS(rs, 3)]), ms, &(x[WS(vs, 3) + WS(rs, 1)]));
				   }
				   {
					V T2f, T22, T1K, T2g, T2c, T2d, T3N, T3O;
					T2c = LD(&(x[WS(vs, 4) + WS(rs, 1)]), ms, &(x[WS(vs, 4) + WS(rs, 1)]));
					T2d = LD(&(x[WS(vs, 4) + WS(rs, 5)]), ms, &(x[WS(vs, 4) + WS(rs, 1)]));
					T2f = LD(&(x[WS(vs, 4) + WS(rs, 7)]), ms, &(x[WS(vs, 4) + WS(rs, 1)]));
					Ts = VSUB(Tq, Tr);
					Tw = VADD(Tq, Tr);
					Tf = VSUB(T6, T9);
					Ta = VADD(T6, T9);
					T22 = VADD(T1I, T1J);
					T1K = VSUB(T1I, T1J);
					T2y = VADD(T2c, T2d);
					T2e = VSUB(T2c, T2d);
					T2g = LD(&(x[WS(vs, 4) + WS(rs, 3)]), ms, &(x[WS(vs, 4) + WS(rs, 1)]));
					T3N = LD(&(x[WS(vs, 7) + WS(rs, 1)]), ms, &(x[WS(vs, 7) + WS(rs, 1)]));
					T3O = LD(&(x[WS(vs, 7) + WS(rs, 5)]), ms, &(x[WS(vs, 7) + WS(rs, 1)]));
					T3Q = LD(&(x[WS(vs, 7) + WS(rs, 7)]), ms, &(x[WS(vs, 7) + WS(rs, 1)]));
					T23 = VSUB(T21, T22);
					T27 = VADD(T21, T22);
					T1Q = VSUB(T1H, T1K);
					T1L = VADD(T1H, T1K);
					T2z = VADD(T2f, T2g);
					T2h = VSUB(T2f, T2g);
					T49 = VADD(T3N, T3O);
					T3P = VSUB(T3N, T3O);
					T3R = LD(&(x[WS(vs, 7) + WS(rs, 3)]), ms, &(x[WS(vs, 7) + WS(rs, 1)]));
				   }
			      }
			      {
				   V TX, TD, T1b, TY, TG, T1u, T1a, T1c;
				   {
					V TE, T4a, T3S, TF, TB, TC, T18, T19;
					TB = LD(&(x[WS(vs, 1) + WS(rs, 1)]), ms, &(x[WS(vs, 1) + WS(rs, 1)]));
					TC = LD(&(x[WS(vs, 1) + WS(rs, 5)]), ms, &(x[WS(vs, 1) + WS(rs, 1)]));
					TE = LD(&(x[WS(vs, 1) + WS(rs, 7)]), ms, &(x[WS(vs, 1) + WS(rs, 1)]));
					T2A = VSUB(T2y, T2z);
					T2E = VADD(T2y, T2z);
					T2n = VSUB(T2e, T2h);
					T2i = VADD(T2e, T2h);
					T4a = VADD(T3Q, T3R);
					T3S = VSUB(T3Q, T3R);
					TX = VADD(TB, TC);
					TD = VSUB(TB, TC);
					TF = LD(&(x[WS(vs, 1) + WS(rs, 3)]), ms, &(x[WS(vs, 1) + WS(rs, 1)]));
					T18 = LD(&(x[WS(vs, 2) + WS(rs, 1)]), ms, &(x[WS(vs, 2) + WS(rs, 1)]));
					T19 = LD(&(x[WS(vs, 2) + WS(rs, 5)]), ms, &(x[WS(vs, 2) + WS(rs, 1)]));
					T1b = LD(&(x[WS(vs, 2) + WS(rs, 7)]), ms, &(x[WS(vs, 2) + WS(rs, 1)]));
					T4b = VSUB(T49, T4a);
					T4f = VADD(T49, T4a);
					T3Y = VSUB(T3P, T3S);
					T3T = VADD(T3P, T3S);
					TY = VADD(TE, TF);
					TG = VSUB(TE, TF);
					T1u = VADD(T18, T19);
					T1a = VSUB(T18, T19);
					T1c = LD(&(x[WS(vs, 2) + WS(rs, 3)]), ms, &(x[WS(vs, 2) + WS(rs, 1)]));
				   }
				   {
					V T2M, T1v, T1d, T2N, T2J, T2K, T3g, T3h;
					T2J = LD(&(x[WS(vs, 5) + WS(rs, 1)]), ms, &(x[WS(vs, 5) + WS(rs, 1)]));
					T2K = LD(&(x[WS(vs, 5) + WS(rs, 5)]), ms, &(x[WS(vs, 5) + WS(rs, 1)]));
					T2M = LD(&(x[WS(vs, 5) + WS(rs, 7)]), ms, &(x[WS(vs, 5) + WS(rs, 1)]));
					TZ = VSUB(TX, TY);
					T13 = VADD(TX, TY);
					TM = VSUB(TD, TG);
					TH = VADD(TD, TG);
					T1v = VADD(T1b, T1c);
					T1d = VSUB(T1b, T1c);
					T35 = VADD(T2J, T2K);
					T2L = VSUB(T2J, T2K);
					T2N = LD(&(x[WS(vs, 5) + WS(rs, 3)]), ms, &(x[WS(vs, 5) + WS(rs, 1)]));
					T3g = LD(&(x[WS(vs, 6) + WS(rs, 1)]), ms, &(x[WS(vs, 6) + WS(rs, 1)]));
					T3h = LD(&(x[WS(vs, 6) + WS(rs, 5)]), ms, &(x[WS(vs, 6) + WS(rs, 1)]));
					T3j = LD(&(x[WS(vs, 6) + WS(rs, 7)]), ms, &(x[WS(vs, 6) + WS(rs, 1)]));
					T1w = VSUB(T1u, T1v);
					T1A = VADD(T1u, T1v);
					T1j = VSUB(T1a, T1d);
					T1e = VADD(T1a, T1d);
					T36 = VADD(T2M, T2N);
					T2O = VSUB(T2M, T2N);
					T3C = VADD(T3g, T3h);
					T3i = VSUB(T3g, T3h);
					T3k = LD(&(x[WS(vs, 6) + WS(rs, 3)]), ms, &(x[WS(vs, 6) + WS(rs, 1)]));
				   }
			      }
			 }
		    }
		    {
			 V T3b, T2U, T2P, T3I, T3r, T3m, T11, T25, T39, T4d;
			 {
			      V T37, T3E, T2B, T24;
			      {
				   V T3D, T3l, Tt, T4c;
				   ST(&(x[0]), VADD(Tv, Tw), ms, &(x[0]));
				   ST(&(x[WS(rs, 2)]), VADD(T1z, T1A), ms, &(x[0]));
				   ST(&(x[WS(rs, 7)]), VADD(T4e, T4f), ms, &(x[WS(rs, 1)]));
				   T37 = VSUB(T35, T36);
				   T3b = VADD(T35, T36);
				   T2U = VSUB(T2L, T2O);
				   T2P = VADD(T2L, T2O);
				   T3D = VADD(T3j, T3k);
				   T3l = VSUB(T3j, T3k);
				   ST(&(x[WS(rs, 4)]), VADD(T2D, T2E), ms, &(x[0]));
				   ST(&(x[WS(rs, 3)]), VADD(T26, T27), ms, &(x[WS(rs, 1)]));
				   ST(&(x[WS(rs, 1)]), VADD(T12, T13), ms, &(x[WS(rs, 1)]));
				   ST(&(x[WS(rs, 5)]), VADD(T3a, T3b), ms, &(x[WS(rs, 1)]));
				   Tt = BYTW(&(W[TWVL * 10]), VFNMSI(Ts, Tp));
				   T4c = BYTW(&(W[TWVL * 10]), VFNMSI(T4b, T48));
				   T3E = VSUB(T3C, T3D);
				   T3I = VADD(T3C, T3D);
				   T3r = VSUB(T3i, T3l);
				   T3m = VADD(T3i, T3l);
				   T2B = BYTW(&(W[TWVL * 10]), VFNMSI(T2A, T2x));
				   T24 = BYTW(&(W[TWVL * 10]), VFNMSI(T23, T20));
				   ST(&(x[WS(vs, 6)]), Tt, ms, &(x[WS(vs, 6)]));
				   ST(&(x[WS(vs, 6) + WS(rs, 7)]), T4c, ms, &(x[WS(vs, 6) + WS(rs, 1)]));
			      }
			      {
				   V T38, T1y, Tu, T10, T1x, T3F, T2C, T3G;
				   T10 = BYTW(&(W[TWVL * 10]), VFNMSI(TZ, TW));
				   ST(&(x[WS(rs, 6)]), VADD(T3H, T3I), ms, &(x[0]));
				   T1x = BYTW(&(W[TWVL * 10]), VFNMSI(T1w, T1t));
				   T3F = BYTW(&(W[TWVL * 10]), VFNMSI(T3E, T3B));
				   ST(&(x[WS(vs, 6) + WS(rs, 4)]), T2B, ms, &(x[WS(vs, 6)]));
				   ST(&(x[WS(vs, 6) + WS(rs, 3)]), T24, ms, &(x[WS(vs, 6) + WS(rs, 1)]));
				   T38 = BYTW(&(W[TWVL * 10]), VFNMSI(T37, T34));
				   T1y = BYTW(&(W[TWVL * 2]), VFMAI(T1w, T1t));
				   ST(&(x[WS(vs, 6) + WS(rs, 1)]), T10, ms, &(x[WS(vs, 6) + WS(rs, 1)]));
				   Tu = BYTW(&(W[TWVL * 2]), VFMAI(Ts, Tp));
				   ST(&(x[WS(vs, 6) + WS(rs, 2)]), T1x, ms, &(x[WS(vs, 6)]));
				   ST(&(x[WS(vs, 6) + WS(rs, 6)]), T3F, ms, &(x[WS(vs, 6)]));
				   T2C = BYTW(&(W[TWVL * 2]), VFMAI(T2A, T2x));
				   T3G = BYTW(&(W[TWVL * 2]), VFMAI(T3E, T3B));
				   ST(&(x[WS(vs, 6) + WS(rs, 5)]), T38, ms, &(x[WS(vs, 6) + WS(rs, 1)]));
				   ST(&(x[WS(vs, 2) + WS(rs, 2)]), T1y, ms, &(x[WS(vs, 2)]));
				   T11 = BYTW(&(W[TWVL * 2]), VFMAI(TZ, TW));
				   ST(&(x[WS(vs, 2)]), Tu, ms, &(x[WS(vs, 2)]));
				   T25 = BYTW(&(W[TWVL * 2]), VFMAI(T23, T20));
				   T39 = BYTW(&(W[TWVL * 2]), VFMAI(T37, T34));
				   ST(&(x[WS(vs, 2) + WS(rs, 4)]), T2C, ms, &(x[WS(vs, 2)]));
				   ST(&(x[WS(vs, 2) + WS(rs, 6)]), T3G, ms, &(x[WS(vs, 2)]));
				   T4d = BYTW(&(W[TWVL * 2]), VFMAI(T4b, T48));
			      }
			 }
			 {
			      V Tj, Tk, T2r, T2j, T2o, T2s, Ti, Th, T1M, T1R, T41, T40;
			      {
				   V T3c, T4g, T3J, T2F, Tx, T1B;
				   Tx = BYTW(&(W[TWVL * 6]), VSUB(Tv, Tw));
				   ST(&(x[WS(vs, 2) + WS(rs, 1)]), T11, ms, &(x[WS(vs, 2) + WS(rs, 1)]));
				   T1B = BYTW(&(W[TWVL * 6]), VSUB(T1z, T1A));
				   ST(&(x[WS(vs, 2) + WS(rs, 3)]), T25, ms, &(x[WS(vs, 2) + WS(rs, 1)]));
				   ST(&(x[WS(vs, 2) + WS(rs, 5)]), T39, ms, &(x[WS(vs, 2) + WS(rs, 1)]));
				   T3c = BYTW(&(W[TWVL * 6]), VSUB(T3a, T3b));
				   T4g = BYTW(&(W[TWVL * 6]), VSUB(T4e, T4f));
				   ST(&(x[WS(vs, 2) + WS(rs, 7)]), T4d, ms, &(x[WS(vs, 2) + WS(rs, 1)]));
				   ST(&(x[WS(vs, 4)]), Tx, ms, &(x[WS(vs, 4)]));
				   T3J = BYTW(&(W[TWVL * 6]), VSUB(T3H, T3I));
				   ST(&(x[WS(vs, 4) + WS(rs, 2)]), T1B, ms, &(x[WS(vs, 4)]));
				   T2F = BYTW(&(W[TWVL * 6]), VSUB(T2D, T2E));
				   {
					V T14, Tb, Tg, T28, T3U, T3Z;
					T28 = BYTW(&(W[TWVL * 6]), VSUB(T26, T27));
					ST(&(x[WS(vs, 4) + WS(rs, 5)]), T3c, ms, &(x[WS(vs, 4) + WS(rs, 1)]));
					ST(&(x[WS(vs, 4) + WS(rs, 7)]), T4g, ms, &(x[WS(vs, 4) + WS(rs, 1)]));
					T14 = BYTW(&(W[TWVL * 6]), VSUB(T12, T13));
					Tj = VFMA(LDK(KP707106781), Ta, T3);
					Tb = VFNMS(LDK(KP707106781), Ta, T3);
					ST(&(x[WS(vs, 4) + WS(rs, 6)]), T3J, ms, &(x[WS(vs, 4)]));
					Tk = VFMA(LDK(KP707106781), Tf, Te);
					Tg = VFNMS(LDK(KP707106781), Tf, Te);
					ST(&(x[WS(vs, 4) + WS(rs, 4)]), T2F, ms, &(x[WS(vs, 4)]));
					ST(&(x[WS(vs, 4) + WS(rs, 3)]), T28, ms, &(x[WS(vs, 4) + WS(rs, 1)]));
					T3U = VFNMS(LDK(KP707106781), T3T, T3M);
					T42 = VFMA(LDK(KP707106781), T3T, T3M);
					T43 = VFMA(LDK(KP707106781), T3Y, T3X);
					T3Z = VFNMS(LDK(KP707106781), T3Y, T3X);
					ST(&(x[WS(vs, 4) + WS(rs, 1)]), T14, ms, &(x[WS(vs, 4) + WS(rs, 1)]));
					T2r = VFMA(LDK(KP707106781), T2i, T2b);
					T2j = VFNMS(LDK(KP707106781), T2i, T2b);
					T2o = VFNMS(LDK(KP707106781), T2n, T2m);
					T2s = VFMA(LDK(KP707106781), T2n, T2m);
					Ti = BYTW(&(W[TWVL * 8]), VFMAI(Tg, Tb));
					Th = BYTW(&(W[TWVL * 4]), VFNMSI(Tg, Tb));
					T1U = VFMA(LDK(KP707106781), T1L, T1E);
					T1M = VFNMS(LDK(KP707106781), T1L, T1E);
					T1R = VFNMS(LDK(KP707106781), T1Q, T1P);
					T1V = VFMA(LDK(KP707106781), T1Q, T1P);
					T41 = BYTW(&(W[TWVL * 8]), VFMAI(T3Z, T3U));
					T40 = BYTW(&(W[TWVL * 4]), VFNMSI(T3Z, T3U));
				   }
			      }
			      {
				   V TQ, TR, T1n, T1o, T3v, T3w;
				   {
					V TI, TN, T1f, T1k, T3n, T3s;
					{
					     V T1T, T1S, T2q, T2p;
					     TQ = VFMA(LDK(KP707106781), TH, TA);
					     TI = VFNMS(LDK(KP707106781), TH, TA);
					     T2q = BYTW(&(W[TWVL * 8]), VFMAI(T2o, T2j));
					     T2p = BYTW(&(W[TWVL * 4]), VFNMSI(T2o, T2j));
					     ST(&(x[WS(vs, 5)]), Ti, ms, &(x[WS(vs, 5)]));
					     ST(&(x[WS(vs, 3)]), Th, ms, &(x[WS(vs, 3)]));
					     T1T = BYTW(&(W[TWVL * 8]), VFMAI(T1R, T1M));
					     T1S = BYTW(&(W[TWVL * 4]), VFNMSI(T1R, T1M));
					     ST(&(x[WS(vs, 5) + WS(rs, 7)]), T41, ms, &(x[WS(vs, 5) + WS(rs, 1)]));
					     ST(&(x[WS(vs, 3) + WS(rs, 7)]), T40, ms, &(x[WS(vs, 3) + WS(rs, 1)]));
					     ST(&(x[WS(vs, 5) + WS(rs, 4)]), T2q, ms, &(x[WS(vs, 5)]));
					     ST(&(x[WS(vs, 3) + WS(rs, 4)]), T2p, ms, &(x[WS(vs, 3)]));
					     TN = VFNMS(LDK(KP707106781), TM, TL);
					     TR = VFMA(LDK(KP707106781), TM, TL);
					     T1n = VFMA(LDK(KP707106781), T1e, T17);
					     T1f = VFNMS(LDK(KP707106781), T1e, T17);
					     ST(&(x[WS(vs, 5) + WS(rs, 3)]), T1T, ms, &(x[WS(vs, 5) + WS(rs, 1)]));
					     ST(&(x[WS(vs, 3) + WS(rs, 3)]), T1S, ms, &(x[WS(vs, 3) + WS(rs, 1)]));
					     T1k = VFNMS(LDK(KP707106781), T1j, T1i);
					     T1o = VFMA(LDK(KP707106781), T1j, T1i);
					     T3v = VFMA(LDK(KP707106781), T3m, T3f);
					     T3n = VFNMS(LDK(KP707106781), T3m, T3f);
					     T3s = VFNMS(LDK(KP707106781), T3r, T3q);
					     T3w = VFMA(LDK(KP707106781), T3r, T3q);
					}
					{
					     V T2Q, TP, TO, T2V, T2X, T2W;
					     T2Y = VFMA(LDK(KP707106781), T2P, T2I);
					     T2Q = VFNMS(LDK(KP707106781), T2P, T2I);
					     TP = BYTW(&(W[TWVL * 8]), VFMAI(TN, TI));
					     TO = BYTW(&(W[TWVL * 4]), VFNMSI(TN, TI));
					     T2V = VFNMS(LDK(KP707106781), T2U, T2T);
					     T2Z = VFMA(LDK(KP707106781), T2U, T2T);
					     {
						  V T1m, T1l, T3u, T3t;
						  T1m = BYTW(&(W[TWVL * 8]), VFMAI(T1k, T1f));
						  T1l = BYTW(&(W[TWVL * 4]), VFNMSI(T1k, T1f));
						  T3u = BYTW(&(W[TWVL * 8]), VFMAI(T3s, T3n));
						  T3t = BYTW(&(W[TWVL * 4]), VFNMSI(T3s, T3n));
						  ST(&(x[WS(vs, 5) + WS(rs, 1)]), TP, ms, &(x[WS(vs, 5) + WS(rs, 1)]));
						  ST(&(x[WS(vs, 3) + WS(rs, 1)]), TO, ms, &(x[WS(vs, 3) + WS(rs, 1)]));
						  T2X = BYTW(&(W[TWVL * 8]), VFMAI(T2V, T2Q));
						  T2W = BYTW(&(W[TWVL * 4]), VFNMSI(T2V, T2Q));
						  ST(&(x[WS(vs, 5) + WS(rs, 2)]), T1m, ms, &(x[WS(vs, 5)]));
						  ST(&(x[WS(vs, 3) + WS(rs, 2)]), T1l, ms, &(x[WS(vs, 3)]));
						  ST(&(x[WS(vs, 5) + WS(rs, 6)]), T3u, ms, &(x[WS(vs, 5)]));
						  ST(&(x[WS(vs, 3) + WS(rs, 6)]), T3t, ms, &(x[WS(vs, 3)]));
					     }
					     ST(&(x[WS(vs, 5) + WS(rs, 5)]), T2X, ms, &(x[WS(vs, 5) + WS(rs, 1)]));
					     ST(&(x[WS(vs, 3) + WS(rs, 5)]), T2W, ms, &(x[WS(vs, 3) + WS(rs, 1)]));
					}
				   }
				   {
					V T3y, T3x, T1q, T1p;
					T1q = BYTW(&(W[TWVL * 12]), VFNMSI(T1o, T1n));
					T1p = BYTW(&(W[0]), VFMAI(T1o, T1n));
					{
					     V Tm, Tl, T2u, T2t;
					     Tm = BYTW(&(W[TWVL * 12]), VFNMSI(Tk, Tj));
					     Tl = BYTW(&(W[0]), VFMAI(Tk, Tj));
					     T2u = BYTW(&(W[TWVL * 12]), VFNMSI(T2s, T2r));
					     T2t = BYTW(&(W[0]), VFMAI(T2s, T2r));
					     ST(&(x[WS(vs, 7) + WS(rs, 2)]), T1q, ms, &(x[WS(vs, 7)]));
					     ST(&(x[WS(vs, 1) + WS(rs, 2)]), T1p, ms, &(x[WS(vs, 1)]));
					     T3y = BYTW(&(W[TWVL * 12]), VFNMSI(T3w, T3v));
					     T3x = BYTW(&(W[0]), VFMAI(T3w, T3v));
					     ST(&(x[WS(vs, 7)]), Tm, ms, &(x[WS(vs, 7)]));
					     ST(&(x[WS(vs, 1)]), Tl, ms, &(x[WS(vs, 1)]));
					     ST(&(x[WS(vs, 7) + WS(rs, 4)]), T2u, ms, &(x[WS(vs, 7)]));
					     ST(&(x[WS(vs, 1) + WS(rs, 4)]), T2t, ms, &(x[WS(vs, 1)]));
					}
					ST(&(x[WS(vs, 7) + WS(rs, 6)]), T3y, ms, &(x[WS(vs, 7)]));
					ST(&(x[WS(vs, 1) + WS(rs, 6)]), T3x, ms, &(x[WS(vs, 1)]));
					TT = BYTW(&(W[TWVL * 12]), VFNMSI(TR, TQ));
					TS = BYTW(&(W[0]), VFMAI(TR, TQ));
				   }
			      }
			 }
		    }
	       }
	       {
		    V T1X, T1W, T31, T30;
		    T1X = BYTW(&(W[TWVL * 12]), VFNMSI(T1V, T1U));
		    T1W = BYTW(&(W[0]), VFMAI(T1V, T1U));
		    T31 = BYTW(&(W[TWVL * 12]), VFNMSI(T2Z, T2Y));
		    T30 = BYTW(&(W[0]), VFMAI(T2Z, T2Y));
		    ST(&(x[WS(vs, 7) + WS(rs, 1)]), TT, ms, &(x[WS(vs, 7) + WS(rs, 1)]));
		    ST(&(x[WS(vs, 1) + WS(rs, 1)]), TS, ms, &(x[WS(vs, 1) + WS(rs, 1)]));
		    T45 = BYTW(&(W[TWVL * 12]), VFNMSI(T43, T42));
		    T44 = BYTW(&(W[0]), VFMAI(T43, T42));
		    ST(&(x[WS(vs, 7) + WS(rs, 3)]), T1X, ms, &(x[WS(vs, 7) + WS(rs, 1)]));
		    ST(&(x[WS(vs, 1) + WS(rs, 3)]), T1W, ms, &(x[WS(vs, 1) + WS(rs, 1)]));
		    ST(&(x[WS(vs, 7) + WS(rs, 5)]), T31, ms, &(x[WS(vs, 7) + WS(rs, 1)]));
		    ST(&(x[WS(vs, 1) + WS(rs, 5)]), T30, ms, &(x[WS(vs, 1) + WS(rs, 1)]));
	       }
	       ST(&(x[WS(vs, 7) + WS(rs, 7)]), T45, ms, &(x[WS(vs, 7) + WS(rs, 1)]));
	       ST(&(x[WS(vs, 1) + WS(rs, 7)]), T44, ms, &(x[WS(vs, 1) + WS(rs, 1)]));
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     VTW(0, 4),
     VTW(0, 5),
     VTW(0, 6),
     VTW(0, 7),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 8, XSIMD_STRING("q1bv_8"), twinstr, &GENUS, {184, 112, 80, 0}, 0, 0, 0 };

void XSIMD(codelet_q1bv_8) (planner *p) {
     X(kdft_difsq_register) (p, q1bv_8, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_twidsq_c.native -simd -compact -variables 4 -pipeline-latency 8 -n 8 -dif -name q1bv_8 -include q1b.h -sign 1 */

/*
 * This function contains 264 FP additions, 128 FP multiplications,
 * (or, 264 additions, 128 multiplications, 0 fused multiply/add),
 * 77 stack variables, 1 constants, and 128 memory accesses
 */
#include "q1b.h"

static void q1bv_8(R *ri, R *ii, const R *W, stride rs, stride vs, INT mb, INT me, INT ms)
{
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT m;
	  R *x;
	  x = ii;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 14)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 14), MAKE_VOLATILE_STRIDE(16, rs), MAKE_VOLATILE_STRIDE(16, vs)) {
	       V Ta, Tv, Te, Tp, T1L, T26, T1P, T20, T2i, T2D, T2m, T2x, T3T, T4e, T3X;
	       V T48, TH, T12, TL, TW, T1e, T1z, T1i, T1t, T2P, T3a, T2T, T34, T3m, T3H;
	       V T3q, T3B, T7, Tw, Tf, Ts, T1I, T27, T1Q, T23, T2f, T2E, T2n, T2A, T3Q;
	       V T4f, T3Y, T4b, TE, T13, TM, TZ, T1b, T1A, T1j, T1w, T2M, T3b, T2U, T37;
	       V T3j, T3I, T3r, T3E, T28, T14;
	       {
		    V T8, T9, To, Tc, Td, Tn;
		    T8 = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
		    T9 = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
		    To = VADD(T8, T9);
		    Tc = LD(&(x[0]), ms, &(x[0]));
		    Td = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
		    Tn = VADD(Tc, Td);
		    Ta = VSUB(T8, T9);
		    Tv = VADD(Tn, To);
		    Te = VSUB(Tc, Td);
		    Tp = VSUB(Tn, To);
	       }
	       {
		    V T1J, T1K, T1Z, T1N, T1O, T1Y;
		    T1J = LD(&(x[WS(vs, 3) + WS(rs, 2)]), ms, &(x[WS(vs, 3)]));
		    T1K = LD(&(x[WS(vs, 3) + WS(rs, 6)]), ms, &(x[WS(vs, 3)]));
		    T1Z = VADD(T1J, T1K);
		    T1N = LD(&(x[WS(vs, 3)]), ms, &(x[WS(vs, 3)]));
		    T1O = LD(&(x[WS(vs, 3) + WS(rs, 4)]), ms, &(x[WS(vs, 3)]));
		    T1Y = VADD(T1N, T1O);
		    T1L = VSUB(T1J, T1K);
		    T26 = VADD(T1Y, T1Z);
		    T1P = VSUB(T1N, T1O);
		    T20 = VSUB(T1Y, T1Z);
	       }
	       {
		    V T2g, T2h, T2w, T2k, T2l, T2v;
		    T2g = LD(&(x[WS(vs, 4) + WS(rs, 2)]), ms, &(x[WS(vs, 4)]));
		    T2h = LD(&(x[WS(vs, 4) + WS(rs, 6)]), ms, &(x[WS(vs, 4)]));
		    T2w = VADD(T2g, T2h);
		    T2k = LD(&(x[WS(vs, 4)]), ms, &(x[WS(vs, 4)]));
		    T2l = LD(&(x[WS(vs, 4) + WS(rs, 4)]), ms, &(x[WS(vs, 4)]));
		    T2v = VADD(T2k, T2l);
		    T2i = VSUB(T2g, T2h);
		    T2D = VADD(T2v, T2w);
		    T2m = VSUB(T2k, T2l);
		    T2x = VSUB(T2v, T2w);
	       }
	       {
		    V T3R, T3S, T47, T3V, T3W, T46;
		    T3R = LD(&(x[WS(vs, 7) + WS(rs, 2)]), ms, &(x[WS(vs, 7)]));
		    T3S = LD(&(x[WS(vs, 7) + WS(rs, 6)]), ms, &(x[WS(vs, 7)]));
		    T47 = VADD(T3R, T3S);
		    T3V = LD(&(x[WS(vs, 7)]), ms, &(x[WS(vs, 7)]));
		    T3W = LD(&(x[WS(vs, 7) + WS(rs, 4)]), ms, &(x[WS(vs, 7)]));
		    T46 = VADD(T3V, T3W);
		    T3T = VSUB(T3R, T3S);
		    T4e = VADD(T46, T47);
		    T3X = VSUB(T3V, T3W);
		    T48 = VSUB(T46, T47);
	       }
	       {
		    V TF, TG, TV, TJ, TK, TU;
		    TF = LD(&(x[WS(vs, 1) + WS(rs, 2)]), ms, &(x[WS(vs, 1)]));
		    TG = LD(&(x[WS(vs, 1) + WS(rs, 6)]), ms, &(x[WS(vs, 1)]));
		    TV = VADD(TF, TG);
		    TJ = LD(&(x[WS(vs, 1)]), ms, &(x[WS(vs, 1)]));
		    TK = LD(&(x[WS(vs, 1) + WS(rs, 4)]), ms, &(x[WS(vs, 1)]));
		    TU = VADD(TJ, TK);
		    TH = VSUB(TF, TG);
		    T12 = VADD(TU, TV);
		    TL = VSUB(TJ, TK);
		    TW = VSUB(TU, TV);
	       }
	       {
		    V T1c, T1d, T1s, T1g, T1h, T1r;
		    T1c = LD(&(x[WS(vs, 2) + WS(rs, 2)]), ms, &(x[WS(vs, 2)]));
		    T1d = LD(&(x[WS(vs, 2) + WS(rs, 6)]), ms, &(x[WS(vs, 2)]));
		    T1s = VADD(T1c, T1d);
		    T1g = LD(&(x[WS(vs, 2)]), ms, &(x[WS(vs, 2)]));
		    T1h = LD(&(x[WS(vs, 2) + WS(rs, 4)]), ms, &(x[WS(vs, 2)]));
		    T1r = VADD(T1g, T1h);
		    T1e = VSUB(T1c, T1d);
		    T1z = VADD(T1r, T1s);
		    T1i = VSUB(T1g, T1h);
		    T1t = VSUB(T1r, T1s);
	       }
	       {
		    V T2N, T2O, T33, T2R, T2S, T32;
		    T2N = LD(&(x[WS(vs, 5) + WS(rs, 2)]), ms, &(x[WS(vs, 5)]));
		    T2O = LD(&(x[WS(vs, 5) + WS(rs, 6)]), ms, &(x[WS(vs, 5)]));
		    T33 = VADD(T2N, T2O);
		    T2R = LD(&(x[WS(vs, 5)]), ms, &(x[WS(vs, 5)]));
		    T2S = LD(&(x[WS(vs, 5) + WS(rs, 4)]), ms, &(x[WS(vs, 5)]));
		    T32 = VADD(T2R, T2S);
		    T2P = VSUB(T2N, T2O);
		    T3a = VADD(T32, T33);
		    T2T = VSUB(T2R, T2S);
		    T34 = VSUB(T32, T33);
	       }
	       {
		    V T3k, T3l, T3A, T3o, T3p, T3z;
		    T3k = LD(&(x[WS(vs, 6) + WS(rs, 2)]), ms, &(x[WS(vs, 6)]));
		    T3l = LD(&(x[WS(vs, 6) + WS(rs, 6)]), ms, &(x[WS(vs, 6)]));
		    T3A = VADD(T3k, T3l);
		    T3o = LD(&(x[WS(vs, 6)]), ms, &(x[WS(vs, 6)]));
		    T3p = LD(&(x[WS(vs, 6) + WS(rs, 4)]), ms, &(x[WS(vs, 6)]));
		    T3z = VADD(T3o, T3p);
		    T3m = VSUB(T3k, T3l);
		    T3H = VADD(T3z, T3A);
		    T3q = VSUB(T3o, T3p);
		    T3B = VSUB(T3z, T3A);
	       }
	       {
		    V T3, Tq, T6, Tr;
		    {
			 V T1, T2, T4, T5;
			 T1 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
			 T2 = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
			 T3 = VSUB(T1, T2);
			 Tq = VADD(T1, T2);
			 T4 = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			 T5 = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
			 T6 = VSUB(T4, T5);
			 Tr = VADD(T4, T5);
		    }
		    T7 = VMUL(LDK(KP707106781), VSUB(T3, T6));
		    Tw = VADD(Tq, Tr);
		    Tf = VMUL(LDK(KP707106781), VADD(T3, T6));
		    Ts = VBYI(VSUB(Tq, Tr));
	       }
	       {
		    V T1E, T21, T1H, T22;
		    {
			 V T1C, T1D, T1F, T1G;
			 T1C = LD(&(x[WS(vs, 3) + WS(rs, 1)]), ms, &(x[WS(vs, 3) + WS(rs, 1)]));
			 T1D = LD(&(x[WS(vs, 3) + WS(rs, 5)]), ms, &(x[WS(vs, 3) + WS(rs, 1)]));
			 T1E = VSUB(T1C, T1D);
			 T21 = VADD(T1C, T1D);
			 T1F = LD(&(x[WS(vs, 3) + WS(rs, 7)]), ms, &(x[WS(vs, 3) + WS(rs, 1)]));
			 T1G = LD(&(x[WS(vs, 3) + WS(rs, 3)]), ms, &(x[WS(vs, 3) + WS(rs, 1)]));
			 T1H = VSUB(T1F, T1G);
			 T22 = VADD(T1F, T1G);
		    }
		    T1I = VMUL(LDK(KP707106781), VSUB(T1E, T1H));
		    T27 = VADD(T21, T22);
		    T1Q = VMUL(LDK(KP707106781), VADD(T1E, T1H));
		    T23 = VBYI(VSUB(T21, T22));
	       }
	       {
		    V T2b, T2y, T2e, T2z;
		    {
			 V T29, T2a, T2c, T2d;
			 T29 = LD(&(x[WS(vs, 4) + WS(rs, 1)]), ms, &(x[WS(vs, 4) + WS(rs, 1)]));
			 T2a = LD(&(x[WS(vs, 4) + WS(rs, 5)]), ms, &(x[WS(vs, 4) + WS(rs, 1)]));
			 T2b = VSUB(T29, T2a);
			 T2y = VADD(T29, T2a);
			 T2c = LD(&(x[WS(vs, 4) + WS(rs, 7)]), ms, &(x[WS(vs, 4) + WS(rs, 1)]));
			 T2d = LD(&(x[WS(vs, 4) + WS(rs, 3)]), ms, &(x[WS(vs, 4) + WS(rs, 1)]));
			 T2e = VSUB(T2c, T2d);
			 T2z = VADD(T2c, T2d);
		    }
		    T2f = VMUL(LDK(KP707106781), VSUB(T2b, T2e));
		    T2E = VADD(T2y, T2z);
		    T2n = VMUL(LDK(KP707106781), VADD(T2b, T2e));
		    T2A = VBYI(VSUB(T2y, T2z));
	       }
	       {
		    V T3M, T49, T3P, T4a;
		    {
			 V T3K, T3L, T3N, T3O;
			 T3K = LD(&(x[WS(vs, 7) + WS(rs, 1)]), ms, &(x[WS(vs, 7) + WS(rs, 1)]));
			 T3L = LD(&(x[WS(vs, 7) + WS(rs, 5)]), ms, &(x[WS(vs, 7) + WS(rs, 1)]));
			 T3M = VSUB(T3K, T3L);
			 T49 = VADD(T3K, T3L);
			 T3N = LD(&(x[WS(vs, 7) + WS(rs, 7)]), ms, &(x[WS(vs, 7) + WS(rs, 1)]));
			 T3O = LD(&(x[WS(vs, 7) + WS(rs, 3)]), ms, &(x[WS(vs, 7) + WS(rs, 1)]));
			 T3P = VSUB(T3N, T3O);
			 T4a = VADD(T3N, T3O);
		    }
		    T3Q = VMUL(LDK(KP707106781), VSUB(T3M, T3P));
		    T4f = VADD(T49, T4a);
		    T3Y = VMUL(LDK(KP707106781), VADD(T3M, T3P));
		    T4b = VBYI(VSUB(T49, T4a));
	       }
	       {
		    V TA, TX, TD, TY;
		    {
			 V Ty, Tz, TB, TC;
			 Ty = LD(&(x[WS(vs, 1) + WS(rs, 1)]), ms, &(x[WS(vs, 1) + WS(rs, 1)]));
			 Tz = LD(&(x[WS(vs, 1) + WS(rs, 5)]), ms, &(x[WS(vs, 1) + WS(rs, 1)]));
			 TA = VSUB(Ty, Tz);
			 TX = VADD(Ty, Tz);
			 TB = LD(&(x[WS(vs, 1) + WS(rs, 7)]), ms, &(x[WS(vs, 1) + WS(rs, 1)]));
			 TC = LD(&(x[WS(vs, 1) + WS(rs, 3)]), ms, &(x[WS(vs, 1) + WS(rs, 1)]));
			 TD = VSUB(TB, TC);
			 TY = VADD(TB, TC);
		    }
		    TE = VMUL(LDK(KP707106781), VSUB(TA, TD));
		    T13 = VADD(TX, TY);
		    TM = VMUL(LDK(KP707106781), VADD(TA, TD));
		    TZ = VBYI(VSUB(TX, TY));
	       }
	       {
		    V T17, T1u, T1a, T1v;
		    {
			 V T15, T16, T18, T19;
			 T15 = LD(&(x[WS(vs, 2) + WS(rs, 1)]), ms, &(x[WS(vs, 2) + WS(rs, 1)]));
			 T16 = LD(&(x[WS(vs, 2) + WS(rs, 5)]), ms, &(x[WS(vs, 2) + WS(rs, 1)]));
			 T17 = VSUB(T15, T16);
			 T1u = VADD(T15, T16);
			 T18 = LD(&(x[WS(vs, 2) + WS(rs, 7)]), ms, &(x[WS(vs, 2) + WS(rs, 1)]));
			 T19 = LD(&(x[WS(vs, 2) + WS(rs, 3)]), ms, &(x[WS(vs, 2) + WS(rs, 1)]));
			 T1a = VSUB(T18, T19);
			 T1v = VADD(T18, T19);
		    }
		    T1b = VMUL(LDK(KP707106781), VSUB(T17, T1a));
		    T1A = VADD(T1u, T1v);
		    T1j = VMUL(LDK(KP707106781), VADD(T17, T1a));
		    T1w = VBYI(VSUB(T1u, T1v));
	       }
	       {
		    V T2I, T35, T2L, T36;
		    {
			 V T2G, T2H, T2J, T2K;
			 T2G = LD(&(x[WS(vs, 5) + WS(rs, 1)]), ms, &(x[WS(vs, 5) + WS(rs, 1)]));
			 T2H = LD(&(x[WS(vs, 5) + WS(rs, 5)]), ms, &(x[WS(vs, 5) + WS(rs, 1)]));
			 T2I = VSUB(T2G, T2H);
			 T35 = VADD(T2G, T2H);
			 T2J = LD(&(x[WS(vs, 5) + WS(rs, 7)]), ms, &(x[WS(vs, 5) + WS(rs, 1)]));
			 T2K = LD(&(x[WS(vs, 5) + WS(rs, 3)]), ms, &(x[WS(vs, 5) + WS(rs, 1)]));
			 T2L = VSUB(T2J, T2K);
			 T36 = VADD(T2J, T2K);
		    }
		    T2M = VMUL(LDK(KP707106781), VSUB(T2I, T2L));
		    T3b = VADD(T35, T36);
		    T2U = VMUL(LDK(KP707106781), VADD(T2I, T2L));
		    T37 = VBYI(VSUB(T35, T36));
	       }
	       {
		    V T3f, T3C, T3i, T3D;
		    {
			 V T3d, T3e, T3g, T3h;
			 T3d = LD(&(x[WS(vs, 6) + WS(rs, 1)]), ms, &(x[WS(vs, 6) + WS(rs, 1)]));
			 T3e = LD(&(x[WS(vs, 6) + WS(rs, 5)]), ms, &(x[WS(vs, 6) + WS(rs, 1)]));
			 T3f = VSUB(T3d, T3e);
			 T3C = VADD(T3d, T3e);
			 T3g = LD(&(x[WS(vs, 6) + WS(rs, 7)]), ms, &(x[WS(vs, 6) + WS(rs, 1)]));
			 T3h = LD(&(x[WS(vs, 6) + WS(rs, 3)]), ms, &(x[WS(vs, 6) + WS(rs, 1)]));
			 T3i = VSUB(T3g, T3h);
			 T3D = VADD(T3g, T3h);
		    }
		    T3j = VMUL(LDK(KP707106781), VSUB(T3f, T3i));
		    T3I = VADD(T3C, T3D);
		    T3r = VMUL(LDK(KP707106781), VADD(T3f, T3i));
		    T3E = VBYI(VSUB(T3C, T3D));
	       }
	       ST(&(x[0]), VADD(Tv, Tw), ms, &(x[0]));
	       ST(&(x[WS(rs, 2)]), VADD(T1z, T1A), ms, &(x[0]));
	       ST(&(x[WS(rs, 5)]), VADD(T3a, T3b), ms, &(x[WS(rs, 1)]));
	       ST(&(x[WS(rs, 7)]), VADD(T4e, T4f), ms, &(x[WS(rs, 1)]));
	       ST(&(x[WS(rs, 6)]), VADD(T3H, T3I), ms, &(x[0]));
	       ST(&(x[WS(rs, 4)]), VADD(T2D, T2E), ms, &(x[0]));
	       {
		    V Tt, T4c, T2B, T24;
		    ST(&(x[WS(rs, 3)]), VADD(T26, T27), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 1)]), VADD(T12, T13), ms, &(x[WS(rs, 1)]));
		    Tt = BYTW(&(W[TWVL * 10]), VSUB(Tp, Ts));
		    ST(&(x[WS(vs, 6)]), Tt, ms, &(x[WS(vs, 6)]));
		    T4c = BYTW(&(W[TWVL * 10]), VSUB(T48, T4b));
		    ST(&(x[WS(vs, 6) + WS(rs, 7)]), T4c, ms, &(x[WS(vs, 6) + WS(rs, 1)]));
		    T2B = BYTW(&(W[TWVL * 10]), VSUB(T2x, T2A));
		    ST(&(x[WS(vs, 6) + WS(rs, 4)]), T2B, ms, &(x[WS(vs, 6)]));
		    T24 = BYTW(&(W[TWVL * 10]), VSUB(T20, T23));
		    ST(&(x[WS(vs, 6) + WS(rs, 3)]), T24, ms, &(x[WS(vs, 6) + WS(rs, 1)]));
	       }
	       {
		    V T10, T1x, T3F, T38, T1y, Tu;
		    T10 = BYTW(&(W[TWVL * 10]), VSUB(TW, TZ));
		    ST(&(x[WS(vs, 6) + WS(rs, 1)]), T10, ms, &(x[WS(vs, 6) + WS(rs, 1)]));
		    T1x = BYTW(&(W[TWVL * 10]), VSUB(T1t, T1w));
		    ST(&(x[WS(vs, 6) + WS(rs, 2)]), T1x, ms, &(x[WS(vs, 6)]));
		    T3F = BYTW(&(W[TWVL * 10]), VSUB(T3B, T3E));
		    ST(&(x[WS(vs, 6) + WS(rs, 6)]), T3F, ms, &(x[WS(vs, 6)]));
		    T38 = BYTW(&(W[TWVL * 10]), VSUB(T34, T37));
		    ST(&(x[WS(vs, 6) + WS(rs, 5)]), T38, ms, &(x[WS(vs, 6) + WS(rs, 1)]));
		    T1y = BYTW(&(W[TWVL * 2]), VADD(T1t, T1w));
		    ST(&(x[WS(vs, 2) + WS(rs, 2)]), T1y, ms, &(x[WS(vs, 2)]));
		    Tu = BYTW(&(W[TWVL * 2]), VADD(Tp, Ts));
		    ST(&(x[WS(vs, 2)]), Tu, ms, &(x[WS(vs, 2)]));
	       }
	       {
		    V T2C, T3G, T11, T25, T39, T4d;
		    T2C = BYTW(&(W[TWVL * 2]), VADD(T2x, T2A));
		    ST(&(x[WS(vs, 2) + WS(rs, 4)]), T2C, ms, &(x[WS(vs, 2)]));
		    T3G = BYTW(&(W[TWVL * 2]), VADD(T3B, T3E));
		    ST(&(x[WS(vs, 2) + WS(rs, 6)]), T3G, ms, &(x[WS(vs, 2)]));
		    T11 = BYTW(&(W[TWVL * 2]), VADD(TW, TZ));
		    ST(&(x[WS(vs, 2) + WS(rs, 1)]), T11, ms, &(x[WS(vs, 2) + WS(rs, 1)]));
		    T25 = BYTW(&(W[TWVL * 2]), VADD(T20, T23));
		    ST(&(x[WS(vs, 2) + WS(rs, 3)]), T25, ms, &(x[WS(vs, 2) + WS(rs, 1)]));
		    T39 = BYTW(&(W[TWVL * 2]), VADD(T34, T37));
		    ST(&(x[WS(vs, 2) + WS(rs, 5)]), T39, ms, &(x[WS(vs, 2) + WS(rs, 1)]));
		    T4d = BYTW(&(W[TWVL * 2]), VADD(T48, T4b));
		    ST(&(x[WS(vs, 2) + WS(rs, 7)]), T4d, ms, &(x[WS(vs, 2) + WS(rs, 1)]));
	       }
	       {
		    V Tx, T1B, T3c, T4g, T3J, T2F;
		    Tx = BYTW(&(W[TWVL * 6]), VSUB(Tv, Tw));
		    ST(&(x[WS(vs, 4)]), Tx, ms, &(x[WS(vs, 4)]));
		    T1B = BYTW(&(W[TWVL * 6]), VSUB(T1z, T1A));
		    ST(&(x[WS(vs, 4) + WS(rs, 2)]), T1B, ms, &(x[WS(vs, 4)]));
		    T3c = BYTW(&(W[TWVL * 6]), VSUB(T3a, T3b));
		    ST(&(x[WS(vs, 4) + WS(rs, 5)]), T3c, ms, &(x[WS(vs, 4) + WS(rs, 1)]));
		    T4g = BYTW(&(W[TWVL * 6]), VSUB(T4e, T4f));
		    ST(&(x[WS(vs, 4) + WS(rs, 7)]), T4g, ms, &(x[WS(vs, 4) + WS(rs, 1)]));
		    T3J = BYTW(&(W[TWVL * 6]), VSUB(T3H, T3I));
		    ST(&(x[WS(vs, 4) + WS(rs, 6)]), T3J, ms, &(x[WS(vs, 4)]));
		    T2F = BYTW(&(W[TWVL * 6]), VSUB(T2D, T2E));
		    ST(&(x[WS(vs, 4) + WS(rs, 4)]), T2F, ms, &(x[WS(vs, 4)]));
	       }
	       T28 = BYTW(&(W[TWVL * 6]), VSUB(T26, T27));
	       ST(&(x[WS(vs, 4) + WS(rs, 3)]), T28, ms, &(x[WS(vs, 4) + WS(rs, 1)]));
	       T14 = BYTW(&(W[TWVL * 6]), VSUB(T12, T13));
	       ST(&(x[WS(vs, 4) + WS(rs, 1)]), T14, ms, &(x[WS(vs, 4) + WS(rs, 1)]));
	       {
		    V Th, Ti, Tb, Tg;
		    Tb = VBYI(VSUB(T7, Ta));
		    Tg = VSUB(Te, Tf);
		    Th = BYTW(&(W[TWVL * 4]), VADD(Tb, Tg));
		    Ti = BYTW(&(W[TWVL * 8]), VSUB(Tg, Tb));
		    ST(&(x[WS(vs, 3)]), Th, ms, &(x[WS(vs, 3)]));
		    ST(&(x[WS(vs, 5)]), Ti, ms, &(x[WS(vs, 5)]));
	       }
	       {
		    V T40, T41, T3U, T3Z;
		    T3U = VBYI(VSUB(T3Q, T3T));
		    T3Z = VSUB(T3X, T3Y);
		    T40 = BYTW(&(W[TWVL * 4]), VADD(T3U, T3Z));
		    T41 = BYTW(&(W[TWVL * 8]), VSUB(T3Z, T3U));
		    ST(&(x[WS(vs, 3) + WS(rs, 7)]), T40, ms, &(x[WS(vs, 3) + WS(rs, 1)]));
		    ST(&(x[WS(vs, 5) + WS(rs, 7)]), T41, ms, &(x[WS(vs, 5) + WS(rs, 1)]));
	       }
	       {
		    V T2p, T2q, T2j, T2o;
		    T2j = VBYI(VSUB(T2f, T2i));
		    T2o = VSUB(T2m, T2n);
		    T2p = BYTW(&(W[TWVL * 4]), VADD(T2j, T2o));
		    T2q = BYTW(&(W[TWVL * 8]), VSUB(T2o, T2j));
		    ST(&(x[WS(vs, 3) + WS(rs, 4)]), T2p, ms, &(x[WS(vs, 3)]));
		    ST(&(x[WS(vs, 5) + WS(rs, 4)]), T2q, ms, &(x[WS(vs, 5)]));
	       }
	       {
		    V T1S, T1T, T1M, T1R;
		    T1M = VBYI(VSUB(T1I, T1L));
		    T1R = VSUB(T1P, T1Q);
		    T1S = BYTW(&(W[TWVL * 4]), VADD(T1M, T1R));
		    T1T = BYTW(&(W[TWVL * 8]), VSUB(T1R, T1M));
		    ST(&(x[WS(vs, 3) + WS(rs, 3)]), T1S, ms, &(x[WS(vs, 3) + WS(rs, 1)]));
		    ST(&(x[WS(vs, 5) + WS(rs, 3)]), T1T, ms, &(x[WS(vs, 5) + WS(rs, 1)]));
	       }
	       {
		    V TO, TP, TI, TN;
		    TI = VBYI(VSUB(TE, TH));
		    TN = VSUB(TL, TM);
		    TO = BYTW(&(W[TWVL * 4]), VADD(TI, TN));
		    TP = BYTW(&(W[TWVL * 8]), VSUB(TN, TI));
		    ST(&(x[WS(vs, 3) + WS(rs, 1)]), TO, ms, &(x[WS(vs, 3) + WS(rs, 1)]));
		    ST(&(x[WS(vs, 5) + WS(rs, 1)]), TP, ms, &(x[WS(vs, 5) + WS(rs, 1)]));
	       }
	       {
		    V T1l, T1m, T1f, T1k;
		    T1f = VBYI(VSUB(T1b, T1e));
		    T1k = VSUB(T1i, T1j);
		    T1l = BYTW(&(W[TWVL * 4]), VADD(T1f, T1k));
		    T1m = BYTW(&(W[TWVL * 8]), VSUB(T1k, T1f));
		    ST(&(x[WS(vs, 3) + WS(rs, 2)]), T1l, ms, &(x[WS(vs, 3)]));
		    ST(&(x[WS(vs, 5) + WS(rs, 2)]), T1m, ms, &(x[WS(vs, 5)]));
	       }
	       {
		    V T3t, T3u, T3n, T3s;
		    T3n = VBYI(VSUB(T3j, T3m));
		    T3s = VSUB(T3q, T3r);
		    T3t = BYTW(&(W[TWVL * 4]), VADD(T3n, T3s));
		    T3u = BYTW(&(W[TWVL * 8]), VSUB(T3s, T3n));
		    ST(&(x[WS(vs, 3) + WS(rs, 6)]), T3t, ms, &(x[WS(vs, 3)]));
		    ST(&(x[WS(vs, 5) + WS(rs, 6)]), T3u, ms, &(x[WS(vs, 5)]));
	       }
	       {
		    V T2W, T2X, T2Q, T2V;
		    T2Q = VBYI(VSUB(T2M, T2P));
		    T2V = VSUB(T2T, T2U);
		    T2W = BYTW(&(W[TWVL * 4]), VADD(T2Q, T2V));
		    T2X = BYTW(&(W[TWVL * 8]), VSUB(T2V, T2Q));
		    ST(&(x[WS(vs, 3) + WS(rs, 5)]), T2W, ms, &(x[WS(vs, 3) + WS(rs, 1)]));
		    ST(&(x[WS(vs, 5) + WS(rs, 5)]), T2X, ms, &(x[WS(vs, 5) + WS(rs, 1)]));
	       }
	       {
		    V T1p, T1q, T1n, T1o;
		    T1n = VBYI(VADD(T1e, T1b));
		    T1o = VADD(T1i, T1j);
		    T1p = BYTW(&(W[0]), VADD(T1n, T1o));
		    T1q = BYTW(&(W[TWVL * 12]), VSUB(T1o, T1n));
		    ST(&(x[WS(vs, 1) + WS(rs, 2)]), T1p, ms, &(x[WS(vs, 1)]));
		    ST(&(x[WS(vs, 7) + WS(rs, 2)]), T1q, ms, &(x[WS(vs, 7)]));
	       }
	       {
		    V Tl, Tm, Tj, Tk;
		    Tj = VBYI(VADD(Ta, T7));
		    Tk = VADD(Te, Tf);
		    Tl = BYTW(&(W[0]), VADD(Tj, Tk));
		    Tm = BYTW(&(W[TWVL * 12]), VSUB(Tk, Tj));
		    ST(&(x[WS(vs, 1)]), Tl, ms, &(x[WS(vs, 1)]));
		    ST(&(x[WS(vs, 7)]), Tm, ms, &(x[WS(vs, 7)]));
	       }
	       {
		    V T2t, T2u, T2r, T2s;
		    T2r = VBYI(VADD(T2i, T2f));
		    T2s = VADD(T2m, T2n);
		    T2t = BYTW(&(W[0]), VADD(T2r, T2s));
		    T2u = BYTW(&(W[TWVL * 12]), VSUB(T2s, T2r));
		    ST(&(x[WS(vs, 1) + WS(rs, 4)]), T2t, ms, &(x[WS(vs, 1)]));
		    ST(&(x[WS(vs, 7) + WS(rs, 4)]), T2u, ms, &(x[WS(vs, 7)]));
	       }
	       {
		    V T3x, T3y, T3v, T3w;
		    T3v = VBYI(VADD(T3m, T3j));
		    T3w = VADD(T3q, T3r);
		    T3x = BYTW(&(W[0]), VADD(T3v, T3w));
		    T3y = BYTW(&(W[TWVL * 12]), VSUB(T3w, T3v));
		    ST(&(x[WS(vs, 1) + WS(rs, 6)]), T3x, ms, &(x[WS(vs, 1)]));
		    ST(&(x[WS(vs, 7) + WS(rs, 6)]), T3y, ms, &(x[WS(vs, 7)]));
	       }
	       {
		    V TS, TT, TQ, TR;
		    TQ = VBYI(VADD(TH, TE));
		    TR = VADD(TL, TM);
		    TS = BYTW(&(W[0]), VADD(TQ, TR));
		    TT = BYTW(&(W[TWVL * 12]), VSUB(TR, TQ));
		    ST(&(x[WS(vs, 1) + WS(rs, 1)]), TS, ms, &(x[WS(vs, 1) + WS(rs, 1)]));
		    ST(&(x[WS(vs, 7) + WS(rs, 1)]), TT, ms, &(x[WS(vs, 7) + WS(rs, 1)]));
	       }
	       {
		    V T1W, T1X, T1U, T1V;
		    T1U = VBYI(VADD(T1L, T1I));
		    T1V = VADD(T1P, T1Q);
		    T1W = BYTW(&(W[0]), VADD(T1U, T1V));
		    T1X = BYTW(&(W[TWVL * 12]), VSUB(T1V, T1U));
		    ST(&(x[WS(vs, 1) + WS(rs, 3)]), T1W, ms, &(x[WS(vs, 1) + WS(rs, 1)]));
		    ST(&(x[WS(vs, 7) + WS(rs, 3)]), T1X, ms, &(x[WS(vs, 7) + WS(rs, 1)]));
	       }
	       {
		    V T30, T31, T2Y, T2Z;
		    T2Y = VBYI(VADD(T2P, T2M));
		    T2Z = VADD(T2T, T2U);
		    T30 = BYTW(&(W[0]), VADD(T2Y, T2Z));
		    T31 = BYTW(&(W[TWVL * 12]), VSUB(T2Z, T2Y));
		    ST(&(x[WS(vs, 1) + WS(rs, 5)]), T30, ms, &(x[WS(vs, 1) + WS(rs, 1)]));
		    ST(&(x[WS(vs, 7) + WS(rs, 5)]), T31, ms, &(x[WS(vs, 7) + WS(rs, 1)]));
	       }
	       {
		    V T44, T45, T42, T43;
		    T42 = VBYI(VADD(T3T, T3Q));
		    T43 = VADD(T3X, T3Y);
		    T44 = BYTW(&(W[0]), VADD(T42, T43));
		    T45 = BYTW(&(W[TWVL * 12]), VSUB(T43, T42));
		    ST(&(x[WS(vs, 1) + WS(rs, 7)]), T44, ms, &(x[WS(vs, 1) + WS(rs, 1)]));
		    ST(&(x[WS(vs, 7) + WS(rs, 7)]), T45, ms, &(x[WS(vs, 7) + WS(rs, 1)]));
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     VTW(0, 4),
     VTW(0, 5),
     VTW(0, 6),
     VTW(0, 7),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 8, XSIMD_STRING("q1bv_8"), twinstr, &GENUS, {264, 128, 0, 0}, 0, 0, 0 };

void XSIMD(codelet_q1bv_8) (planner *p) {
     X(kdft_difsq_register) (p, q1bv_8, &desc);
}
#endif				/* HAVE_FMA */
